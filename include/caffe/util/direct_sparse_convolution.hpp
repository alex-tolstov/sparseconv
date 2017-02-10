#ifndef DIRECT_SPARSE_CONVOLUTION_HPP_
#define DIRECT_SPARSE_CONVOLUTION_HPP_


namespace caffe {
	
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
