#include <vector>
#include <cstdlib>
#include "caffe/util/benchmark.hpp"
#include "caffe/common.hpp"

namespace caffe {

    template <class Dtype>
	void convertKernelToCompressed(const Dtype *kernel, const int sizeX, int sizeY, std::vector<Dtype> &values, std::vector<int> &indicesCol, std::vector<int> &indicesRow) {
		int lastIndex = 0;
		indicesRow.push_back(0);
		for (int y = 0; y < sizeY; y++) {
			int countInTheRow = 0;
			for (int x = 0; x < sizeX; x++) {
				if (kernel[y * sizeX + x] != 0.0) {
					values.push_back(kernel[y * sizeX + x]);
					indicesCol.push_back(x);
					countInTheRow++;
				}
			}
			lastIndex += countInTheRow;
			indicesRow.push_back(lastIndex);
		}
	}
	
	template <class Dtype>
	void convertKernelToCompressedChannels(
		const Dtype *kernel, 
		const int sizeX, 
		const int sizeY,
		const int channelSize, 
		std::vector<Dtype> &values, 
		std::vector<int> &indicesCol,
		std::vector<int> &indicesChannel,
		std::vector<int> &indicesRow
	) {
		int lastIndex = 0;
		indicesRow.push_back(0);
		indicesChannel.push_back(0);
		for (int y = 0; y < sizeY; y++) {
			const int nChannels = sizeX / channelSize;
			for (int ch = 0; ch < nChannels; ch++) {
				int countInTheChannel = 0;
				for (int i = 0; i < channelSize; i++) {
					int x = ch * channelSize + i;
					if (kernel[y * sizeX + x] != 0) {
						values.push_back(kernel[y * sizeX + x]);
						indicesCol.push_back(x);
						countInTheChannel++;
					}
				}
				lastIndex += countInTheChannel;
				indicesChannel.push_back(lastIndex);
			}
			indicesRow.push_back(lastIndex);
		}
	}
	
	template<typename DType> 
	void sparse_gemmm(
		const int resSizeY, 
		const int imgSizeX, 
		const int imgSizeY,
		 
		const DType* kernelValues, 
		const int* indicesCol,
		const int* indicesRow,
		const DType* img, 
		DType* res
	);
	
	template<> inline
	void sparse_gemmm<float>(
		const int resSizeY, 
		const int imgSizeX, 
		const int imgSizeY,
		 
		const float* kernelValues, 
		const int* indicesCol,
		const int* indicesRow,
		const float* img, 
		float* res
	) {
		char matdescra[6];
		matdescra[0] = 'G';
		matdescra[2] = 'N';
		matdescra[3] = 'C';
		
		float alpha = 1.0f;
		float beta = 0.0f;	
		mkl_scsrmm (
			"n",
			&resSizeY, 
			&imgSizeX, 
			&imgSizeY,
			&alpha,
			matdescra,
			kernelValues, 
			indicesCol,
			indicesRow,
			indicesRow+1,
			img, 
			&imgSizeX, 
			&beta, 
			res, 
			&imgSizeX
		);
	}
	
	
	template<> inline
	void sparse_gemmm<double>(
		const int resSizeY, 
		const int imgSizeX, 
		const int imgSizeY,
		 
		const double* kernelValues, 
		const int* indicesCol,
		const int* indicesRow,
		const double* img, 
		double* res
	) {
		char matdescra[6];
		matdescra[0] = 'G';
		matdescra[2] = 'N';
		matdescra[3] = 'C';
		
		double alpha = 1.0;
		double beta = 0.0;	
		
		mkl_dcsrmm (
			"n",
			&resSizeY, 
			&imgSizeX, 
			&imgSizeY,
			&alpha,
			matdescra,
			kernelValues, 
			indicesCol,
			indicesRow,
			indicesRow+1,
			img, 
			&imgSizeX, 
			&beta, 
			res, 
			&imgSizeX
		);
	}
	
	template<typename Dtype>
	inline void directConvolution(
		const Dtype *kernel, // sparse matrix of a kernel in CSR format.
		const int *indicesCol, // sizeNonZeroes
		const int *indicesRow, // nOutputChannels + 1
		const int sizeNonZeroes,
		
		const int kernelSizeX, // single kernel sizeX
		const int kernelSizeY, // single kernel sizeY
		
		const Dtype* img, // image in original 3D-format: channels, width, height
		const int nInputChannels,
		const int imgSizeX, // size of a single channel
		const int imgSizeY, // size of a single channel
		
		Dtype *res, // output in original 3D-format: nOutputChannels, width, height
		const int nOutputChannels,
		const int resSizeX,
		const int resSizeY
	) {
		for (int i = 0; i < resSizeX * resSizeY * nOutputChannels; i++) {
			res[i] = 0;
		}
		
		const int kernelSize = kernelSizeX * kernelSizeY;
		for (int row = 0; row < nOutputChannels; row++) {
			const int res_off = resSizeX * resSizeY * row;
			for (int idx = indicesRow[row]; idx < indicesRow[row + 1]; idx++) {
				const Dtype mult = kernel[idx];
				int kernelCol = indicesCol[idx];
				
				std::div_t divRes = std::div(kernelCol, kernelSize);
				const int channelIdx = divRes.quot;
				kernelCol = divRes.rem;
				
				const int realKernelRow = kernelCol / kernelSizeX;
				const int realKernelCol = kernelCol % kernelSizeX;
		
				const int xDist = -realKernelCol;
				const int yDist = -realKernelRow;
				
				const int beginY = -yDist;
				const int endY = resSizeY - yDist;
				const int beginX = -xDist;
				const int endX = resSizeX - xDist;

				const Dtype *input = img + imgSizeX * (imgSizeY * channelIdx + beginY);
				Dtype *currRes = res + res_off + xDist + resSizeX * (beginY + yDist);
				
				for (int y = beginY; y < endY; y++, currRes += resSizeX, input += imgSizeX) {
					for (int x = beginX; x < endX; x++) {
						currRes[x] += mult * input[x];
					}
				}
			}
		}
	}
	
	inline int getStartDiff(const int dimX, const int kernelBigCol, const int kernelSize, const int kernelSizeX) {
		const int kernelCol = kernelBigCol % kernelSize;
		
		const int realKernelRow = kernelCol / kernelSizeX;
		const int realKernelCol = kernelCol % kernelSizeX;
	
		return realKernelRow * dimX + realKernelCol;
	}
	
	template<typename Dtype>
	inline void directConvolution2(
		const Dtype *kernel, // sparse matrix of a kernel in CSR format.
		const int *indicesCol, // sizeNonZeroes
		const int *indicesRow, // nOutputChannels + 1
		const int sizeNonZeroes,
		
		const int kernelSizeX, // single kernel sizeX
		const int kernelSizeY, // single kernel sizeY
		
		const Dtype* img, // image in original 3D-format: channels, width, height
		const int nInputChannels,
		const int imgSizeX, // size of a single channel
		const int imgSizeY, // size of a single channel
		
		Dtype *res, // output in original 3D-format: nOutputChannels, width, height
		const int nOutputChannels,
		const int resSizeX,
		const int resSizeY
	) {
		for (int i = 0; i < resSizeX * resSizeY * nOutputChannels; i++) {
			res[i] = 0;
		}
		
		const int kernelSize = kernelSizeX * kernelSizeY;
		for (int row = 0; row < nOutputChannels; row++) {
			const int res_off = resSizeX * resSizeY * row;
			int begin = indicesRow[row];
			const int end = indicesRow[row + 1];
			
			if (begin == end) {
				continue;
			}
			
			while (end - begin >= 8) {
				#define SIZE_R 8
				Dtype mult[SIZE_R];
				const Dtype* input[SIZE_R];
				int realKernelCol[SIZE_R];
				
				for (int i = 0; i < SIZE_R; i++) {
					mult[i] = kernel[begin + i];
					int kernelCol = indicesCol[begin + i];
					const int channelIdx = kernelCol / kernelSize;
					kernelCol %= kernelSize;
					
					const int realKernelRow = kernelCol / kernelSizeX;
					realKernelCol[i] = kernelCol % kernelSizeX;
		
					input[i] = img + imgSizeX * (imgSizeY * channelIdx + realKernelRow);
				}
				 
				Dtype *currRes = res + res_off;
				
				for (int y = 0; y < resSizeY; y++) {
					for (int x = 0; x < resSizeX; x++) {
						currRes[x] += 
							mult[0] * input[0][x + realKernelCol[0]] +
						    mult[1] * input[1][x + realKernelCol[1]] +
						    mult[2] * input[2][x + realKernelCol[2]] +
						    mult[3] * input[3][x + realKernelCol[3]] +
						    mult[4] * input[4][x + realKernelCol[4]] +
						    mult[5] * input[5][x + realKernelCol[5]] +
						    mult[6] * input[6][x + realKernelCol[6]] +
						    mult[7] * input[7][x + realKernelCol[7]];
					}
					for (int i = 0; i < SIZE_R; i++) {
					 	input[i] += imgSizeX;
					}
					currRes += resSizeX;
				}
				begin += SIZE_R;
				
				#undef SIZE_R
			}
			
			while (end - begin >= 4) {
				#define SIZE_R 4
				Dtype mult[SIZE_R];
				const Dtype* input[SIZE_R];
				int realKernelCol[SIZE_R];
				
				for (int i = 0; i < SIZE_R; i++) {
					mult[i] = kernel[begin + i];
					int kernelCol = indicesCol[begin + i];
					const int channelIdx = kernelCol / kernelSize;
					kernelCol %= kernelSize;
					
					const int realKernelRow = kernelCol / kernelSizeX;
					realKernelCol[i] = kernelCol % kernelSizeX;
		
					input[i] = img + imgSizeX * (imgSizeY * channelIdx + realKernelRow);
				}
				 
				Dtype *currRes = res + res_off;
				
				for (int y = 0; y < resSizeY; y++) {
					for (int x = 0; x < resSizeX; x++) {
						currRes[x] += 
							mult[0] * input[0][x + realKernelCol[0]] +
						    mult[1] * input[1][x + realKernelCol[1]] +
						    mult[2] * input[2][x + realKernelCol[2]] +
						    mult[3] * input[3][x + realKernelCol[3]];
					}
					for (int i = 0; i < SIZE_R; i++) {
						input[i] += imgSizeX;
					}
					currRes += resSizeX;
				}
				begin += SIZE_R;
				
				#undef SIZE_R
			}
			
			while (end - begin >= 2) {
				#define SIZE_R 2
				Dtype mult[SIZE_R];
				const Dtype* input[SIZE_R];
				int realKernelCol[SIZE_R];
				
				for (int i = 0; i < SIZE_R; i++) {
					mult[i] = kernel[begin + i];
					int kernelCol = indicesCol[begin + i];
					const int channelIdx = kernelCol / kernelSize;
					kernelCol %= kernelSize;
					
					const int realKernelRow = kernelCol / kernelSizeX;
					realKernelCol[i] = kernelCol % kernelSizeX;
		
					input[i] = img + imgSizeX * (imgSizeY * channelIdx + realKernelRow);
				}
				
				Dtype *currRes = res + res_off;
				
				for (int y = 0; y < resSizeY; y++) {
					for (int x = 0; x < resSizeX; x++) {
						currRes[x] += 
							mult[0] * input[0][x + realKernelCol[0]] +
						    mult[1] * input[1][x + realKernelCol[1]];
					}
					for (int i = 0; i < SIZE_R; i++) {
						input[i] += imgSizeX;
					}
					currRes += resSizeX;
				}
				begin += SIZE_R;
				
				#undef SIZE_R
			}
			
			for (int idx = begin; idx < end; idx++) {
				const Dtype mult = kernel[idx];
				int kernelCol = indicesCol[idx];
				
				std::div_t divRes = std::div(kernelCol, kernelSize);
				const int channelIdx = divRes.quot;
				kernelCol = divRes.rem;
				
				const int realKernelRow = kernelCol / kernelSizeX;
				const int realKernelCol = kernelCol % kernelSizeX;
		
				const Dtype *input = img + imgSizeX * (imgSizeY * channelIdx + realKernelRow);
				
				Dtype *currRes = res + res_off;
				
				for (int y = 0; y < resSizeY; y++, currRes += resSizeX, input += imgSizeX) {
					for (int x = 0; x < resSizeX; x++) {
						currRes[x] += mult * input[x + realKernelCol];
					}
				}
			}
		}
	}
	
	template<typename Dtype>
	inline void directConvolutionEx(
		const Dtype *kernel, // sparse matrix of a kernel in CSR format.
		const int *indicesCol, // sizeNonZeroes
		const int *indicesChannels, // nOutputChannels * nInputChannels + 1
		const int *indicesRow, // nOutputChannels + 1
		
		const int sizeNonZeroes,
		
		const int kernelSizeX, // single kernel sizeX
		const int kernelSizeY, // single kernel sizeY
		
		const Dtype* img, // image in original 3D-format: channels, width, height
		const int nInputChannels,
		const int imgSizeX, // size of a single channel
		const int imgSizeY, // size of a single channel
		
		Dtype *res, // output in original 3D-format: nOutputChannels, width, height
		const int nOutputChannels,
		const int resSizeX,
		const int resSizeY
	) {
		for (int i = 0; i < resSizeX * resSizeY * nOutputChannels; i++) {
			res[i] = 0;
		}
		
		const int kernelSize = kernelSizeX * kernelSizeY;
		for (int row = 0; row < nOutputChannels; row++) {
			const int res_off = resSizeX * resSizeY * row;
			const int offsetChannel = row * nInputChannels;
			for (int channel = 0; channel < nInputChannels; channel++) {
				const int begin = indicesChannels[offsetChannel + channel];
				const int end = indicesChannels[offsetChannel + channel + 1];
				for (int idx = begin; idx < end; idx++) {
					const Dtype mult = kernel[idx];
					int kernelCol = indicesCol[idx];
					
					std::div_t divRes = std::div(kernelCol, kernelSize);
					const int channelIdx = divRes.quot;
					kernelCol = divRes.rem;
					
					const int realKernelRow = kernelCol / kernelSizeX;
					const int realKernelCol = kernelCol % kernelSizeX;
			
					const int xDist = -realKernelCol;
					const int yDist = -realKernelRow;
					
					const int beginY = -yDist;
					const int endY = resSizeY - yDist;
					const int beginX = -xDist;
					const int endX = resSizeX - xDist;

					const Dtype *input = img + imgSizeX * (imgSizeY * channelIdx + beginY);
					Dtype *currRes = res + res_off + xDist + resSizeX * (beginY + yDist);
					
					for (int y = beginY; y < endY; y++, currRes += resSizeX, input += imgSizeX) {
						for (int x = beginX; x < endX; x++) {
							currRes[x] += mult * input[x];
						}
					}
				}
			}
		}
	}


	template<typename Dtype>
	inline void directConvolutionCentered(
		const Dtype *kernel, // sparse matrix of a kernel in CSR format.
		const int *indicesCol, // sizeNonZeroes
		const int *indicesRow, // nOutputChannels + 1
		const int sizeNonZeroes,
		
		const int kernelSizeX, // single kernel sizeX
		const int kernelSizeY, // single kernel sizeY
		
		const Dtype* img, // image in original 3D-format: channels, width, height
		const int nInputChannels,
		const int imgSizeX, // size of a single channel
		const int imgSizeY, // size of a single channel
		
		Dtype *res, // output in original 3D-format: nOutputChannels, width, height
		const int nOutputChannels,
		const int resSizeX,
		const int resSizeY
	) {
		const int dimX = imgSizeX + 2 * kernelSizeX;
		const int dimY = imgSizeY;
		const int dimData = dimX * dimY;
		
		
		caffe::CPUTimer time;
		time.Start();
		 
	 
		std::vector<Dtype> enlargedOutput(dimData * nOutputChannels, 0);
		std::vector<Dtype> enlargedInput(dimData * nInputChannels, 0);
		
		
		time.Stop();
		int timeMalloc = time.MicroSeconds();
		
		time.Start();
		for (int ch = 0; ch < nInputChannels; ch++) {
			for (int y = 0; y < imgSizeY; y++) {
				const int inputShiftX = ch * dimData + y * dimX + kernelSizeX;
				const int outputShiftX = ch * imgSizeX * imgSizeY + y * imgSizeX;
				for (int x = 0; x < imgSizeX; x++) {
					enlargedInput[inputShiftX + x] = 
						img[outputShiftX + x];
				}
			}
		}
		time.Stop();
		int timeCopyInput = time.MicroSeconds();
		
		caffe::CPUTimer timer;
		timer.Start();
		 
		const int xOffset = (imgSizeX - resSizeX) / 2;
		const int yOffset = (imgSizeY - resSizeY) / 2;
		
		const int kernelSize = kernelSizeX * kernelSizeY;
		
		for (int row = 0; row < nOutputChannels; row++) {
			const int outOffset = row * dimData;
			Dtype *eo = &enlargedOutput[outOffset];
			for (int idx = indicesRow[row]; idx < indicesRow[row + 1]; idx++) {
				Dtype mult = kernel[idx];
				int kernelCol = indicesCol[idx];
				 
				std::div_t divRes = std::div(kernelCol, kernelSize);
				const int channelIdx = divRes.quot;
				kernelCol = divRes.rem;
				
				const int realKernelRow = kernelCol / kernelSizeX;
				const int realKernelCol = kernelCol % kernelSizeX;
			
				const int inOffset = channelIdx * dimData;
				
				const int layersDiff = yOffset * dimX + xOffset;
				const int diffStart = realKernelRow * dimX + realKernelCol;
				
				const int beginIndexOutput = layersDiff + kernelSizeX;
				const Dtype* ei = &enlargedInput[inOffset + diffStart - layersDiff];
				
				const int endIdx = (yOffset + resSizeY - 1) * dimX + kernelSizeX + xOffset + resSizeX;
	
				for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
					eo[outputIdx] += mult * ei[outputIdx];
				} 
			}
		}
		
		timer.Stop();
		int convoTime = timer.MicroSeconds();
		
		timer.Start();
		for (int ch = 0; ch < nOutputChannels; ch++) {
			for (int y = 0; y < resSizeY; y++) {
				const int resOffset = ch * resSizeX * resSizeY + y * resSizeX;
				const int eoOffset = ch * dimData + (y + yOffset) * dimX + (kernelSizeX + xOffset);
				for (int x = 0; x < resSizeX; x++) {
					res[resOffset + x] = enlargedOutput[eoOffset + x];
				}
			}
		}
 		
		timer.Stop();
		//LOG(INFO) << "malloc=" << timeMalloc << ", copy input=" << timeCopyInput << ", convo time=" <<  convoTime << ", output copy time = " << timer.MicroSeconds();
	}


	
	
	template<typename Dtype>
	inline void directConvolutionCenteredEx(
		const Dtype *kernel, // sparse matrix of a kernel in CSR format.
		const int *indicesCol, // sizeNonZeroes
		const int *indicesChannels, // nOutputChannels * nInputChannels + 1
		const int *indicesRow, // nOutputChannels + 1
		const int sizeNonZeroes,
		
		const int kernelSizeX, // single kernel sizeX
		const int kernelSizeY, // single kernel sizeY
		
		const Dtype* img, // image in original 3D-format: channels, width, height
		const int nInputChannels,
		const int imgSizeX, // size of a single channel
		const int imgSizeY, // size of a single channel
		
		Dtype *res, // output in original 3D-format: nOutputChannels, width, height
		const int nOutputChannels,
		const int resSizeX,
		const int resSizeY
	) {
		const int dimX = imgSizeX + 2 * kernelSizeX;
		const int dimY = imgSizeY;
		const int dimData = dimX * dimY;
		
		
		caffe::CPUTimer time;
		time.Start();
		 
	 
		std::vector<Dtype> enlargedOutput(dimData * nOutputChannels, 0);
		std::vector<Dtype> enlargedInput(dimData * nInputChannels, 0);
		
		
		time.Stop();
		int timeMalloc = time.MicroSeconds();
		
		time.Start();
		for (int ch = 0; ch < nInputChannels; ch++) {
			for (int y = 0; y < imgSizeY; y++) {
				const int inputShiftX = ch * dimData + y * dimX + kernelSizeX;
				const int outputShiftX = ch * imgSizeX * imgSizeY + y * imgSizeX;
				for (int x = 0; x < imgSizeX; x++) {
					enlargedInput[inputShiftX + x] = 
						img[outputShiftX + x];
				}
			}
		}
		time.Stop();
		int timeCopyInput = time.MicroSeconds();
		
		caffe::CPUTimer timer;
		timer.Start();
		 
		const int xOffset = (imgSizeX - resSizeX) / 2;
		const int yOffset = (imgSizeY - resSizeY) / 2;
		
		const int kernelSize = kernelSizeX * kernelSizeY;
		
		int cnt2 = 0;
		int cnt3 = 0;
		int cnt0 = 0;
		int cnt1 = 0;
		int cnt4 = 0;
		int cnt5 = 0;
		
		for (int row = 0; row < nOutputChannels; row++) {
			const int outOffset = row * dimData;
			Dtype *eo = &enlargedOutput[outOffset];
			const int offsetChannel = row * nInputChannels;
			// diff between (y,x) cells of input and output  
			const int layersDiff = yOffset * dimX + xOffset;
			
			const int beginIndexOutput = layersDiff + kernelSizeX;
			const int endIdx = (yOffset + resSizeY - 1) * dimX + kernelSizeX + xOffset + resSizeX;
			
			for (int channel = 0; channel < nInputChannels; channel++) {
				int begin = indicesChannels[offsetChannel + channel];
				int end = indicesChannels[offsetChannel + channel + 1];
				if (begin == end) {
					cnt0++;
					continue;
				}
				const int inOffset = channel * dimData;

				while (end - begin >= 8) {
					cnt5++;
					const Dtype mult = kernel[begin];
					const Dtype mult1 = kernel[begin + 1];
					const Dtype mult2 = kernel[begin + 2];
					const Dtype mult3 = kernel[begin + 3];
					const Dtype mult4 = kernel[begin + 4];
					const Dtype mult5 = kernel[begin + 5];
					const Dtype mult6 = kernel[begin + 6];
					const Dtype mult7 = kernel[begin + 7];
					
					const int diffStart = getStartDiff(dimX, indicesCol[begin], kernelSize, kernelSizeX);
					const int diffStart1 = getStartDiff(dimX, indicesCol[begin+1], kernelSize, kernelSizeX);
					const int diffStart2 = getStartDiff(dimX, indicesCol[begin+2], kernelSize, kernelSizeX);
					const int diffStart3 = getStartDiff(dimX, indicesCol[begin+3], kernelSize, kernelSizeX);
					const int diffStart4 = getStartDiff(dimX, indicesCol[begin+4], kernelSize, kernelSizeX);
					const int diffStart5 = getStartDiff(dimX, indicesCol[begin+5], kernelSize, kernelSizeX);
					const int diffStart6 = getStartDiff(dimX, indicesCol[begin+6], kernelSize, kernelSizeX);
					const int diffStart7 = getStartDiff(dimX, indicesCol[begin+7], kernelSize, kernelSizeX);
					
					const Dtype* ei = &enlargedInput[inOffset + diffStart - layersDiff];
					const Dtype* ei1 = &enlargedInput[inOffset + diffStart1 - layersDiff];
					const Dtype* ei2 = &enlargedInput[inOffset + diffStart2 - layersDiff];
					const Dtype* ei3 = &enlargedInput[inOffset + diffStart3 - layersDiff];
					const Dtype* ei4 = &enlargedInput[inOffset + diffStart4 - layersDiff];
					const Dtype* ei5 = &enlargedInput[inOffset + diffStart5 - layersDiff];
					const Dtype* ei6 = &enlargedInput[inOffset + diffStart6 - layersDiff];
					const Dtype* ei7 = &enlargedInput[inOffset + diffStart7 - layersDiff];
				
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += (
							mult * ei[outputIdx] + 
							mult1 * ei1[outputIdx] + 
							mult2 * ei2[outputIdx] + 
							mult3 * ei3[outputIdx] + 
							mult4 * ei4[outputIdx] +
							mult5 * ei5[outputIdx] + 
							mult6 * ei6[outputIdx] + 
							mult7 * ei7[outputIdx] 
							);
					}
					begin += 8;
				}		
				while (end - begin >= 4) {
					cnt4++;
					const Dtype mult = kernel[begin];
					const Dtype mult1 = kernel[begin + 1];
					const Dtype mult2 = kernel[begin + 2];
					const Dtype mult3 = kernel[begin + 3];
					
					const int diffStart = getStartDiff(dimX, indicesCol[begin], kernelSize, kernelSizeX);
					const int diffStart1 = getStartDiff(dimX, indicesCol[begin+1], kernelSize, kernelSizeX);
					const int diffStart2 = getStartDiff(dimX, indicesCol[begin+2], kernelSize, kernelSizeX);
					const int diffStart3 = getStartDiff(dimX, indicesCol[begin+3], kernelSize, kernelSizeX);
										
					const Dtype* ei = &enlargedInput[inOffset + diffStart - layersDiff];
					const Dtype* ei1 = &enlargedInput[inOffset + diffStart1 - layersDiff];
					const Dtype* ei2 = &enlargedInput[inOffset + diffStart2 - layersDiff];
					const Dtype* ei3 = &enlargedInput[inOffset + diffStart3 - layersDiff];
		
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += (mult * ei[outputIdx] + mult1 * ei1[outputIdx] + mult2 * ei2[outputIdx] + mult3 * ei3[outputIdx]);
					}
					begin += 4;
				}
				while (end - begin >= 3) {
					cnt3++;
					const Dtype mult = kernel[begin];
					const Dtype mult1 = kernel[begin + 1];
					const Dtype mult2 = kernel[begin + 2];
					
					const int diffStart = getStartDiff(dimX, indicesCol[begin], kernelSize, kernelSizeX);
					const int diffStart1 = getStartDiff(dimX, indicesCol[begin+1], kernelSize, kernelSizeX);
					const int diffStart2 = getStartDiff(dimX, indicesCol[begin+2], kernelSize, kernelSizeX);
										
					const Dtype* ei = &enlargedInput[inOffset + diffStart - layersDiff];
					const Dtype* ei1 = &enlargedInput[inOffset + diffStart1 - layersDiff];
					const Dtype* ei2 = &enlargedInput[inOffset + diffStart2 - layersDiff];
		
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += (mult * ei[outputIdx] + mult1 * ei1[outputIdx] + mult2 * ei2[outputIdx]);
					}
					begin += 3;
				}
				while (end - begin >= 2) {
					cnt2++;
					const Dtype mult = kernel[begin];
					const Dtype mult1 = kernel[begin + 1];
					const int diffStart = getStartDiff(dimX, indicesCol[begin], kernelSize, kernelSizeX);
					const int diffStart1 = getStartDiff(dimX, indicesCol[begin+1], kernelSize, kernelSizeX);
										
					const Dtype* ei = &enlargedInput[inOffset + diffStart - layersDiff];
					const Dtype* ei1 = &enlargedInput[inOffset + diffStart1 - layersDiff];
		
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += (mult * ei[outputIdx] + mult1 * ei1[outputIdx]);
					}
					begin += 2;
				}
				for (int idx = begin; idx < end; idx++) {
					const Dtype mult = kernel[idx];
					const int diffStart = getStartDiff(dimX, indicesCol[begin], kernelSize, kernelSizeX);
					
					const Dtype* ei = &enlargedInput[inOffset + diffStart - layersDiff];
		
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += mult * ei[outputIdx];
					}
				}
			}
		}
		
		timer.Stop();
		int convoTime = timer.MicroSeconds();
		
		timer.Start();
		for (int ch = 0; ch < nOutputChannels; ch++) {
			for (int y = 0; y < resSizeY; y++) {
				const int resOffset = ch * resSizeX * resSizeY + y * resSizeX;
				const int eoOffset = ch * dimData + (y + yOffset) * dimX + (kernelSizeX + xOffset);
				for (int x = 0; x < resSizeX; x++) {
					res[resOffset + x] = enlargedOutput[eoOffset + x];
				}
			}
		}
 		
		timer.Stop();
		
		LOG(INFO) << "cnt0 = " << cnt0 << ", cnt1 = " << cnt1 << ", cnt2 = " << cnt2 << ", cnt3 = " << cnt3 << ", cnt4 = " << cnt4 << ", cnt8 = " << cnt5;
		//LOG(INFO) << "malloc=" << timeMalloc << ", copy input=" << timeCopyInput << ", convo time=" <<  convoTime << ", output copy time = " << timer.MicroSeconds();
	}



	template<typename Dtype>
	inline void directConvolutionCenteredEx2(
		const Dtype *kernel, // sparse matrix of a kernel in CSR format.
		const int *indicesCol, // sizeNonZeroes
		const int *indicesChannels, // nOutputChannels * nInputChannels + 1
		const int *indicesRow, // nOutputChannels + 1
		const int sizeNonZeroes,
		
		const int kernelSizeX, // single kernel sizeX
		const int kernelSizeY, // single kernel sizeY
		
		const Dtype* img, // image in original 3D-format: channels, width, height
		const int nInputChannels,
		const int imgSizeX, // size of a single channel
		const int imgSizeY, // size of a single channel
		
		Dtype *res, // output in original 3D-format: nOutputChannels, width, height
		const int nOutputChannels,
		const int resSizeX,
		const int resSizeY
	) {
		const int dimX = imgSizeX + 2 * kernelSizeX;
		const int dimY = imgSizeY;
		const int dimData = dimX * dimY;
		
		
		caffe::CPUTimer time;
		time.Start();
		 
	 
		std::vector<Dtype> enlargedOutput(dimData * nOutputChannels, 0);
		std::vector<Dtype> enlargedInput(dimData * nInputChannels, 0);
		
		
		time.Stop();
		int timeMalloc = time.MicroSeconds();
		
		time.Start();
		for (int ch = 0; ch < nInputChannels; ch++) {
			for (int y = 0; y < imgSizeY; y++) {
				const int inputShiftX = ch * dimData + y * dimX + kernelSizeX;
				const int outputShiftX = ch * imgSizeX * imgSizeY + y * imgSizeX;
				for (int x = 0; x < imgSizeX; x++) {
					enlargedInput[inputShiftX + x] = 
						img[outputShiftX + x];
				}
			}
		}
		time.Stop();
		int timeCopyInput = time.MicroSeconds();
		
		caffe::CPUTimer timer;
		timer.Start();
		 
		const int xOffset = (imgSizeX - resSizeX) / 2;
		const int yOffset = (imgSizeY - resSizeY) / 2;
		
		const int kernelSize = kernelSizeX * kernelSizeY;
		
		int cnt2 = 0;
		int cnt16 = 0;
		int cnt0 = 0;
		int cnt1 = 0;
		int cnt4 = 0;
		int cnt5 = 0;
		
		for (int row = 0; row < nOutputChannels; row++) {
			const int outOffset = row * dimData;
			Dtype *eo = &enlargedOutput[outOffset];
			const int offsetChannel = row * nInputChannels;
			// diff between (y,x) cells of input and output  
			const int layersDiff = yOffset * dimX + xOffset;
			
			const int beginIndexOutput = layersDiff + kernelSizeX;
			const int endIdx = (yOffset + resSizeY - 1) * dimX + kernelSizeX + xOffset + resSizeX;
			
			{
				int begin = indicesRow[row];
				int end = indicesRow[row + 1];
				if (begin == end) {
					cnt0++;
					continue;
				}

				while (end - begin >= 16) {
					cnt16++;
					#define SIZE_R 16
					Dtype mult[SIZE_R];
					Dtype* ei[SIZE_R];
					
					#pragma unroll(SIZE_R)
					for (int i = 0; i < SIZE_R; i++) {
						mult[i] = kernel[begin + i];
						int diffStart = getStartDiff(dimX, indicesCol[begin + i], kernelSize, kernelSizeX);
						int inOffset = indicesCol[begin + i] / kernelSize * dimData;
						ei[i] = &enlargedInput[inOffset + diffStart - layersDiff];
					}
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += 
							mult[0] * ei[0][outputIdx] + 
							mult[1] * ei[1][outputIdx] + 
							mult[2] * ei[2][outputIdx] + 
							mult[3] * ei[3][outputIdx] + 
							mult[4] * ei[4][outputIdx] + 
							mult[5] * ei[5][outputIdx] + 
							mult[6] * ei[6][outputIdx] + 
							mult[7] * ei[7][outputIdx] +
							mult[8] * ei[8][outputIdx] + 
							mult[9] * ei[9][outputIdx] + 
							mult[10] * ei[10][outputIdx] + 
							mult[11] * ei[11][outputIdx] + 
							mult[12] * ei[12][outputIdx] + 
							mult[13] * ei[13][outputIdx] + 
							mult[14] * ei[14][outputIdx] + 
							mult[15] * ei[15][outputIdx];

					}
					begin += SIZE_R;
					#undef SIZE_R
				}

				while (end - begin >= 8) {
					cnt5++;

					#define SIZE_R 8
					Dtype mult[SIZE_R];
					Dtype* ei[SIZE_R];
					
					#pragma unroll(SIZE_R)
					for (int i = 0; i < SIZE_R; i++) {
						mult[i] = kernel[begin + i];
						int diffStart = getStartDiff(dimX, indicesCol[begin + i], kernelSize, kernelSizeX);
						int inOffset = indicesCol[begin + i] / kernelSize * dimData;
						ei[i] = &enlargedInput[inOffset + diffStart - layersDiff];
					}
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += 
							mult[0] * ei[0][outputIdx] + 
							mult[1] * ei[1][outputIdx] + 
							mult[2] * ei[2][outputIdx] + 
							mult[3] * ei[3][outputIdx] + 
							mult[4] * ei[4][outputIdx] + 
							mult[5] * ei[5][outputIdx] + 
							mult[6] * ei[6][outputIdx] + 
							mult[7] * ei[7][outputIdx];
					}
					begin += SIZE_R;
					#undef SIZE_R
				}
				
				
				while (end - begin >= 4) {
					cnt4++;
					#define SIZE_R 4
					Dtype mult[SIZE_R];
					Dtype* ei[SIZE_R];
					
					#pragma unroll(SIZE_R)
					for (int i = 0; i < SIZE_R; i++) {
						mult[i] = kernel[begin + i];
						int diffStart = getStartDiff(dimX, indicesCol[begin + i], kernelSize, kernelSizeX);
						int inOffset = indicesCol[begin + i] / kernelSize * dimData;
						ei[i] = &enlargedInput[inOffset + diffStart - layersDiff];
					} 
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += 
							mult[0] * ei[0][outputIdx] + 
							mult[1] * ei[1][outputIdx] + 
							mult[2] * ei[2][outputIdx] + 
							mult[3] * ei[3][outputIdx];
					}
					begin += SIZE_R;
					#undef SIZE_R
				}
				
				while (end - begin >= 2) {
					cnt2++;
					const Dtype mult = kernel[begin];
					const Dtype mult1 = kernel[begin + 1];
					const int diffStart = getStartDiff(dimX, indicesCol[begin], kernelSize, kernelSizeX);
					const int diffStart1 = getStartDiff(dimX, indicesCol[begin+1], kernelSize, kernelSizeX);
					
					const int inOffset = indicesCol[begin] / kernelSize * dimData;
					const int inOffset1 = indicesCol[begin + 1] / kernelSize * dimData;
					
					const Dtype* ei = &enlargedInput[inOffset + diffStart - layersDiff];
					const Dtype* ei1 = &enlargedInput[inOffset1 + diffStart1 - layersDiff];
		
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += (mult * ei[outputIdx] + mult1 * ei1[outputIdx]);
					}
					begin += 2;
				}
				for (int idx = begin; idx < end; idx++) {
					const Dtype mult = kernel[idx];
					const int diffStart = getStartDiff(dimX, indicesCol[begin], kernelSize, kernelSizeX);
					const int inOffset = indicesCol[begin] / kernelSize * dimData;
					
					const Dtype* ei = &enlargedInput[inOffset + diffStart - layersDiff];
		
					for (int outputIdx = beginIndexOutput; outputIdx < endIdx; outputIdx++) {
						eo[outputIdx] += mult * ei[outputIdx];
					}
				}
			}
		}
		
		timer.Stop();
		int convoTime = timer.MicroSeconds();
		
		timer.Start();
		for (int ch = 0; ch < nOutputChannels; ch++) {
			for (int y = 0; y < resSizeY; y++) {
				const int resOffset = ch * resSizeX * resSizeY + y * resSizeX;
				const int eoOffset = ch * dimData + (y + yOffset) * dimX + (kernelSizeX + xOffset);
				for (int x = 0; x < resSizeX; x++) {
					res[resOffset + x] = enlargedOutput[eoOffset + x];
				}
			}
		}
 		
		timer.Stop();
		
		//LOG(INFO) << "cnt0 = " << cnt0 << ", cnt1 = " << cnt1 << ", cnt2 = " << cnt2 << ", cnt16 = " << cnt16 << ", cnt4 = " << cnt4 << ", cnt8 = " << cnt5;
		//LOG(INFO) << "malloc=" << timeMalloc << ", copy input=" << timeCopyInput << ", convo time=" <<  convoTime << ", output copy time = " << timer.MicroSeconds();
	}



    template <typename Dtype> inline
	void gustavsonCompressed(
		const Dtype *kernelValues, 
		const int *indicesCol,
		const int *indicesRow,
		const int sizeNonZeroes,
		
		const Dtype *img,
		const int imgSizeX,
		const int imgSizeY,
		
		Dtype *res,
		const int resSizeX,
		const int resSizeY
	) {
		// zerofill result
	
	//	for (int i = 0; i < resSizeX * resSizeY; i++) {
	//		res[i] = 0;
	//	}
	/*
		sparse_gemmm(
			resSizeY, 
			imgSizeX, 
			imgSizeY,
			kernelValues, 
			indicesCol,
			indicesRow,
			img, 
			res 
		);
	*/	
		
		for (int row = 0; row < resSizeY; row++) {
			const int res_off = row * resSizeX;
			for (int idx = indicesRow[row]; idx < indicesRow[row + 1]; idx++) {
				const float mult = kernelValues[idx];
				const int kernel_col = indicesCol[idx];

				int image_line = kernel_col;
				const int img_off = image_line * imgSizeX; 

				#pragma GCC ivdep
				for (int image_col = 0; image_col < imgSizeX; image_col++) {
					res[res_off + image_col] += mult * img[img_off + image_col];
				}
			}
		}
		
		
	/*	for (int i = 0; i < sizeNonZeroes; i++) {
			const float mult = kernelValues[i];
			const int kernel_col = indicesCol[i];
			const int kernel_line = indicesRow[i]; 

			int image_line = kernel_col;
			
			const int res_off = kernel_line * resSizeX;
			const int img_off = image_line * imgSizeX; 
			#pragma GCC ivdep
			for (int image_col = 0; image_col < imgSizeX; image_col++) {
				res[res_off + image_col] += mult * img[img_off + image_col];
			}
		}
		*/
	}


};
