#ifndef DIRECT_SPARSE_CONVOLUTION_HPP_
#define DIRECT_SPARSE_CONVOLUTION_HPP_

#include "immintrin.h"

namespace caffe {

	
	template<typename Dtype> 
	void processRow(Dtype* output, int resSizeX, const Dtype* input, Dtype mult); 

	template<typename Dtype> 
	void processRowN(Dtype* output, int resSizeX, const Dtype* input, const int *shifts, Dtype* mult, int n); 

	template<> 
	void processRow<float>(float* output, int resSizeX, const float* input, float mult) {
		const int div8 = resSizeX / 8;
		const int rem8 = resSizeX % 8;
		__m256 factor = _mm256_set1_ps (mult);
		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;
			__m256 in = _mm256_loadu_ps (input + shift);
			__m256 out = _mm256_loadu_ps (output + shift);
			__m256 multiplied = _mm256_mul_ps (in, factor);
			__m256 added = _mm256_add_ps (multiplied, out);
			_mm256_storeu_ps (output + shift, added);
		}
		for (int x = resSizeX - rem8; x < resSizeX; x++) {
			output[x] += mult * input[x];
		}
	}
	
	template<> 
	void processRow<double>(double* output, int resSizeX, const double* input, double mult) {
		const int div8 = resSizeX >> 3;
		const int rem8 = resSizeX & 7;
		__m256d factor = _mm256_set1_pd (mult);
		for (int i = 0; i < div8; i++) {
			__m256d in = _mm256_loadu_pd (input + i * 8);
			__m256d out = _mm256_loadu_pd (output + i * 8);
			__m256d multiplied = _mm256_mul_pd (in, factor);
			__m256d added = _mm256_add_pd (multiplied, out);
			_mm256_store_pd (output + i * 8, added);
		}
		for (int x = resSizeX - rem8; x < resSizeX; x++) {
			output[x] += mult * input[x];
		}
	}
	
	template<typename Dtype> 
	void processRow4(Dtype* output, int resSizeX, const Dtype** input, Dtype* mult);	

	template<> 
	void processRow4<double>(double* output, int resSizeX, const double** input, double* mult) {
		throw 1;
	}
	
	template<> 
	void processRow4<float>(float* output, int resSizeX, const float** input, float* mult) {
		const int div8 = resSizeX / 8;
		
		__m256 factors[4];
		factors[0] = _mm256_set1_ps (mult[0]);
		factors[1] = _mm256_set1_ps (mult[1]);
		factors[2] = _mm256_set1_ps (mult[2]);
		factors[3] = _mm256_set1_ps (mult[3]);
		
		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;
			
			__m256 out = _mm256_load_ps (output + shift);
			
			for (int inputIdx = 0; inputIdx < 4; inputIdx++) {
				__m256 factor = factors[inputIdx];

				__m256 in = _mm256_loadu_ps (input[inputIdx] + shift);
				
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out = _mm256_add_ps (multiplied, out);
			}
			
			_mm256_store_ps (output + shift, out);
		}
	}
	
	template<typename Dtype> 
	void processRow8(Dtype* output, int resSizeX, const Dtype** input, Dtype* mult);	

	template<> 
	void processRow8<double>(double* output, int resSizeX, const double** input, double* mult) {
		throw 1;
	}
	
	template<> 
	void processRow8<float>(float* output, int resSizeX, const float** input, float* mult) {
		const int div8 = resSizeX / 8;
		
		__m256 factors[8];
		factors[0] = _mm256_set1_ps (mult[0]);
		factors[1] = _mm256_set1_ps (mult[1]);
		factors[2] = _mm256_set1_ps (mult[2]);
		factors[3] = _mm256_set1_ps (mult[3]);
		factors[4] = _mm256_set1_ps (mult[4]);
		factors[5] = _mm256_set1_ps (mult[5]);
		factors[6] = _mm256_set1_ps (mult[6]);
		factors[7] = _mm256_set1_ps (mult[7]);
			
		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;
			
			__m256 out = _mm256_load_ps (output + shift);
			
			for (int inputIdx = 0; inputIdx < 8; inputIdx++) {
				__m256 in = _mm256_loadu_ps (input[inputIdx] + shift);
				
				__m256 multiplied = _mm256_mul_ps (in, factors[inputIdx]);
				
				out = _mm256_add_ps (multiplied, out);
			}
			
			_mm256_store_ps (output + shift, out);
		}
	}
	
	template<> 
	inline void processRowN<float>(float* output, int resSizeX, const float* input, const int *shifts, float* mult, int n) {
		const int div8 = resSizeX / 8;
		
		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;
			
			__m256 out = _mm256_load_ps (output + shift);
			
			// n is unlimited
			// mult[inputIdx] is a constant in code
			// inputIdx is a constant in code
			// input also has a constant offset inside (should be changed)
			for (int inputIdx = 0; inputIdx < n; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[inputIdx]);

				__m256 in = _mm256_loadu_ps (input + shifts[inputIdx] + shift);
				
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out = _mm256_add_ps (multiplied, out);
			}
			
			_mm256_store_ps (output + shift, out);
		}
	}
	
	template<> 
	void processRowN<double>(double* output, int resSizeX, const double* input, const int *shifts, double* mult, int n) {
		throw 1;
	}
	
	inline int roundToMultipleOf(int value, int round) {
		if (value % round == 0) {
			return value;
		} else {
			return (value / round + 1) * round;
		}
	}

		
	/**
	 * Performs a convolution operation on sparse kernels.
	 * 
	 * This method is a baseline to faster approaches. Using of the family of these algorithms inspired by 
	 * https://arxiv.org/pdf/1608.01409.pdf 
	 * 
	 * Input of a kernel is CSR (compressed sparse row) format which is a default one for representing 
	 * sparse matrices and can be used by plenty of sparse SGEMM libraries.
	 * 
	 * Usually kernel input is not just a single 3x3 or 5x5 one. It is a combination of kernels that are applied to the input image
	 * according to internal parameters: size of kernel, number of input channels, number of output channels.
	 * 
	 * @param kernelValues 
	 * 				array of non-zero values in kernel.
	 * @param indicesCol 
	 * 				array of column indices per every value in kernel.
	 * @param indicesRow
	 * 				array of column indices inside row. indicesRow[row] is the first index of non-zero element in the row,
	 * 				indicesRow[row + 1] - 1 is the last index of non-zero element in the row. Hence, the size of the array
	 * 				equals to number of rows + 1, or just nOutputChannels + 1, because a number of rows in kernel equals to
	 * 				a number of output channels.
	 * @param sizeNonZeroes 
	 * 				amount of non-zero elements in kernel.
	 * 
	 * @param kernelSizeX 
	 * 				width of a single kernel (e.g. of 5x5 kernel, not the accumulated one).
	 * @param kernelSizeY
	 * 				height of a single kernel (e.g. of 5x5 kernel, not the accumulated one).
	 * 
	 * @param img
	 * 				pointer to the input data. In this case it contains a series of channels of input images, without im2col operation on them.
	 * @param nInputChannels
	 * 				an amount of input channels in img.
	 * @param imgSizeX 
	 * 				width of a single image (channel).
	 * @param imgSizeY
	 * 				height of a single image (channel).
	 * 
	 * @param res
	 * 				pointer to the output image, consisting of a number of output channels, every of them has equal width and height.
	 * @param nOutputChannels
	 * 				a number of output channels. 
	 * @param resSizeX
	 * 				width of an output channel. 
	 * @param resSizeY
	 * 				height of an output channel. 
	 */
	template<typename Dtype>
	inline void directConvolution(
		const Dtype *kernel, 
		const int *indicesCol,
		const int *indicesRow,
		const int sizeNonZeroes,
		
		const int kernelSizeX,
		const int kernelSizeY,
		
		const Dtype* img,
		const int nInputChannels,
		const int imgSizeX,
		const int imgSizeY,
		
		Dtype *res, 
		const int nOutputChannels,
		const int resSizeX,
		const int resSizeY
	) {
		const int pitchResSizeX = roundToMultipleOf(resSizeX, 8);
		
		Dtype* alignedResult;
		posix_memalign((void**)&alignedResult, 32, (nOutputChannels * pitchResSizeX * resSizeY) * sizeof(Dtype));
		for (int i = 0; i < pitchResSizeX * resSizeY * nOutputChannels; i++) {
			alignedResult[i] = 0;
		}
		
		const int kernelSize = kernelSizeX * kernelSizeY;
		for (int row = 0; row < nOutputChannels; row++) {
			const int res_off = pitchResSizeX * resSizeY * row;
			for (int idx = indicesRow[row]; idx < indicesRow[row + 1]; idx++) {
				const Dtype mult = kernel[idx];
				int kernelCol = indicesCol[idx];
				
				std::div_t divRes = std::div(kernelCol, kernelSize);
				const int channelIdx = divRes.quot;
				kernelCol = divRes.rem;
				
				const int realKernelRow = kernelCol / kernelSizeX;
				const int realKernelCol = kernelCol % kernelSizeX;
		
				const Dtype *input = img + imgSizeX * (imgSizeY * channelIdx + realKernelRow) + realKernelCol;
				
				Dtype *currRes = alignedResult + res_off;
				
				for (int y = 0; y < resSizeY; y++, currRes += pitchResSizeX, input += imgSizeX) {
				//	for (int x = 0; x < resSizeX; x++) {
				//		currRes[x] += mult * input[x];
				//	}
				
					processRow(currRes, resSizeX, input, mult); 
				}
			}
		}
		
		for (int ch = 0; ch < nOutputChannels; ch++) {
			for (int y = 0; y < resSizeY; y++) {
				for (int x = 0; x < resSizeX; x++) {
					res[ch * resSizeX * resSizeY + y * resSizeX + x] = alignedResult[ch * pitchResSizeX * resSizeY + y * pitchResSizeX + x];
				}
			}
		}
		free(alignedResult);
	}
	
	
	/**
	 * Performs a convolution operation on sparse kernels. 
	 * 
	 * This version is faster than baseline because it exploits less writing operations to the output matrix.
	 * 
	 * Input of a kernel is CSR (compressed sparse row) format which is a default one for representing 
	 * sparse matrices and can be used by plenty of sparse SGEMM libraries.
	 * 
	 * Usually kernel input is not just a single 3x3 or 5x5 one. It is a combination of kernels that are applied to the input image
	 * according to internal parameters: size of kernel, number of input channels, number of output channels.
	 * 
	 * @param kernelValues 
	 * 				array of non-zero values in kernel.
	 * @param indicesCol 
	 * 				array of column indices per every value in kernel.
	 * @param indicesRow
	 * 				array of column indices inside row. indicesRow[row] is the first index of non-zero element in the row,
	 * 				indicesRow[row + 1] - 1 is the last index of non-zero element in the row. Hence, the size of the array
	 * 				equals to number of rows + 1, or just nOutputChannels + 1, because a number of rows in kernel equals to
	 * 				a number of output channels.
	 * @param sizeNonZeroes 
	 * 				amount of non-zero elements in kernel.
	 * 
	 * @param kernelSizeX 
	 * 				width of a single kernel (e.g. of 5x5 kernel, not the accumulated one).
	 * @param kernelSizeY
	 * 				height of a single kernel (e.g. of 5x5 kernel, not the accumulated one).
	 * 
	 * @param img
	 * 				pointer to the input data. In this case it contains a series of channels of input 2D-matrices, without im2col operation on them.
	 * @param nInputChannels
	 * 				an amount of input channels in img.
	 * @param imgSizeX 
	 * 				width of a single image (channel).
	 * @param imgSizeY
	 * 				height of a single image (channel).
	 * 
	 * @param res
	 * 				pointer to the output data, consisting of a number of output channels, every of them has equal width and height.
	 * @param nOutputChannels
	 * 				a number of output channels. 
	 * @param resSizeX
	 * 				width of an output channel. 
	 * @param resSizeY
	 * 				height of an output channel. 
	 */
	template<typename Dtype>
	void directConvolution2(
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
		const int pitchResSizeX = roundToMultipleOf(resSizeX, 8);
		
		Dtype* alignedResult;
		posix_memalign((void**)&alignedResult, 32, (nOutputChannels * pitchResSizeX * resSizeY) * sizeof(Dtype));
		for (int i = 0; i < pitchResSizeX * resSizeY * nOutputChannels; i++) {
			alignedResult[i] = 0;
		}
		
		const int kernelSize = kernelSizeX * kernelSizeY;
		for (int row = 0; row < nOutputChannels; row++) {
			const int res_off = pitchResSizeX * resSizeY * row;
			int begin = indicesRow[row];
			const int end = indicesRow[row + 1];
			
			if (begin == end) {
				continue;
			}
			
			while (end - begin >= 16) {
				#define SIZE_R 16
				Dtype mult[SIZE_R];
				int inputShifts[SIZE_R];
				
				for (int i = 0; i < SIZE_R; i++) {
					mult[i] = kernel[begin + i];
					int kernelCol = indicesCol[begin + i];
					const int channelIdx = kernelCol / kernelSize;
					kernelCol %= kernelSize;
					
					const int realKernelRow = kernelCol / kernelSizeX;
					const int realKernelCol = kernelCol % kernelSizeX;
		
					inputShifts[i] = imgSizeX * (imgSizeY * channelIdx + realKernelRow) + realKernelCol;
				}
				
				Dtype *currRes = alignedResult + res_off;
				const Dtype* input = img;
				
				for (int y = 0; y < resSizeY; y++) {
					processRowN(currRes, resSizeX, input, inputShifts, mult, SIZE_R);
					
					const int rem8 = resSizeX % 8;
					for (int x = resSizeX - rem8; x < resSizeX; x++) {
						Dtype t = 0.0;
						for (int idx = 0; idx < SIZE_R; idx++) {
							 t += mult[idx] * input[inputShifts[idx] + x];
						}
						currRes[x] += t;
					}
					
					input += imgSizeX;
					currRes += pitchResSizeX;
				}
				begin += SIZE_R;
				
				#undef SIZE_R
			} 
			
			
			while (end - begin >= 8) {
				#define SIZE_R 8
				Dtype mult[SIZE_R];
				int inputShifts[SIZE_R];
				
				for (int i = 0; i < SIZE_R; i++) {
					mult[i] = kernel[begin + i];
					int kernelCol = indicesCol[begin + i];
					const int channelIdx = kernelCol / kernelSize;
					kernelCol %= kernelSize;
					
					const int realKernelRow = kernelCol / kernelSizeX;
					const int realKernelCol = kernelCol % kernelSizeX;
		
					inputShifts[i] = imgSizeX * (imgSizeY * channelIdx + realKernelRow) + realKernelCol;
				}
				
				Dtype *currRes = alignedResult + res_off;
				const Dtype* input = img;
				
				for (int y = 0; y < resSizeY; y++) {
					processRowN(currRes, resSizeX, input, inputShifts, mult, SIZE_R);
					
					const int rem8 = resSizeX % 8;
					for (int x = resSizeX - rem8; x < resSizeX; x++) {
						Dtype t = 0.0;
						for (int idx = 0; idx < SIZE_R; idx++) {
							 t += mult[idx] * input[inputShifts[idx] + x];
						}
						currRes[x] += t;
					}
					
					input += imgSizeX;
					currRes += pitchResSizeX;
				}
				begin += SIZE_R;
				
				#undef SIZE_R
			} 
			
			while (end - begin >= 4) {
				#define SIZE_R 4
				Dtype mult[SIZE_R];
				int inputShifts[SIZE_R];
				
				for (int i = 0; i < SIZE_R; i++) {
					mult[i] = kernel[begin + i];
					int kernelCol = indicesCol[begin + i];
					const int channelIdx = kernelCol / kernelSize;
					kernelCol %= kernelSize;
					
					const int realKernelRow = kernelCol / kernelSizeX;
					const int realKernelCol = kernelCol % kernelSizeX;
		
					inputShifts[i] = imgSizeX * (imgSizeY * channelIdx + realKernelRow) + realKernelCol;
				}
				
				Dtype *currRes = alignedResult + res_off;
				const Dtype* input = img;
				
				for (int y = 0; y < resSizeY; y++) {
					processRowN(currRes, resSizeX, input, inputShifts, mult, SIZE_R);
					
					const int rem8 = resSizeX % 8;
					for (int x = resSizeX - rem8; x < resSizeX; x++) {
						Dtype t = 0.0;
						for (int idx = 0; idx < SIZE_R; idx++) {
							 t += mult[idx] * input[inputShifts[idx] + x];
						}
						currRes[x] += t;
					}
					
					input += imgSizeX;
					currRes += pitchResSizeX;
				}
				begin += SIZE_R;
				
				#undef SIZE_R
			} 
			
			while (end - begin >= 2) {
				#define SIZE_R 2
				Dtype mult[SIZE_R];
				int inputShifts[SIZE_R];
				
				for (int i = 0; i < SIZE_R; i++) {
					mult[i] = kernel[begin + i];
					int kernelCol = indicesCol[begin + i];
					const int channelIdx = kernelCol / kernelSize;
					kernelCol %= kernelSize;
					
					const int realKernelRow = kernelCol / kernelSizeX;
					const int realKernelCol = kernelCol % kernelSizeX;
		
					inputShifts[i] = imgSizeX * (imgSizeY * channelIdx + realKernelRow) + realKernelCol;
				}
				
				Dtype *currRes = alignedResult + res_off;
				const Dtype* input = img;
				
				for (int y = 0; y < resSizeY; y++) {
					processRowN(currRes, resSizeX, input, inputShifts, mult, SIZE_R);
					
					const int rem8 = resSizeX % 8;
					for (int x = resSizeX - rem8; x < resSizeX; x++) {
						Dtype t = 0.0;
						for (int idx = 0; idx < SIZE_R; idx++) {
							 t += mult[idx] * input[inputShifts[idx] + x];
						}
						currRes[x] += t;
					}
					
					input += imgSizeX;
					currRes += pitchResSizeX;
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
		
				const Dtype *input = img + imgSizeX * (imgSizeY * channelIdx + realKernelRow) + realKernelCol;
				
				Dtype *currRes = alignedResult + res_off;
				
				for (int y = 0; y < resSizeY; y++, currRes += pitchResSizeX, input += imgSizeX) {
					for (int x = 0; x < resSizeX; x++) {
						currRes[x] += mult * input[x];
					}
				}
			}
		}
		for (int ch = 0; ch < nOutputChannels; ch++) {
			for (int y = 0; y < resSizeY; y++) {
				for (int x = 0; x < resSizeX; x++) {
					res[ch * resSizeX * resSizeY + y * resSizeX + x] = alignedResult[ch * pitchResSizeX * resSizeY + y * pitchResSizeX + x];
				}
			}
		}
		free(alignedResult);
	}
	
	/**
	 * Modified baseline direct convolution algorithm to use a bit different input format of kernels:
	 * there is one more array for channel indices. Hence, kernel input data can be grouped not only
	 * by row, but also by channel.
	 * 
	 * Method didn't show any performance gain.
	 */
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
}

#undef DIRECT_SPARSE_CONVOLUTION_HPP_
#endif
