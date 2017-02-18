#ifndef CONVOLUTION_SPARSE_CACHE_HPP_
#define CONVOLUTION_SPARSE_CACHE_HPP_


namespace caffe {

	template<typename Dtype> 
	void processRoww(Dtype* output, int resSizeX, const Dtype* input, Dtype mult); 

	template<> 
	void processRoww<float>(float* output, int resSizeX, const float* input, float mult) {
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
	void processRoww<double>(double* output, int resSizeX, const double* input, double mult) {
		throw 1;
	}
	
	
	template<typename Dtype>
	inline void processRowNFix(
		Dtype* output, 
		int outputStride, 
		int resSizeX, 
		const Dtype* input, 
		const Dtype* kernel, 
		const int* indicesCol, 
		const int n
	);
	
	template<> 
	inline void processRowNFix<double>(
		double* output, 
		int outputStride, 
		int resSizeX, 
		const double* input, 
		const double* kernel, 
		const int* indicesCol, 
		const int n
	) {
	}

	template<> 
	inline void processRowNFix<float>(
		float* output, 
		int outputStride, 
		int resSizeX, 
		const float* input, 
		const float* kernel, 
		const int* indicesCol, 
		const int n
	) {
		const int div8 = resSizeX / 8;
		
		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;
			
			__m256 in = _mm256_loadu_ps (input + shift);
			
			for (int inputIdx = 0; inputIdx < n; inputIdx++) {
				const int outputChannel = indicesCol[inputIdx];
				const float mult = kernel[inputIdx];
				const int outputShift = outputChannel * outputStride + shift;

    			__m256 out = _mm256_load_ps (output + outputShift);
				
				__m256 factor = _mm256_set1_ps (mult);
				
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out = _mm256_add_ps (multiplied, out);

				_mm256_store_ps (output + outputShift, out);
			}
		}
	}

	
	
	template<typename Dtype>
	void directConvolutionSparseCache(
		const Dtype *kernel, // kernel matrix has to be transposed
		const int *indicesCol, // column index is a number in range [0..nOutputChannels)
		const int *indicesRow, // row index is a number in range [0..nInputChannels * kernelDim)
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
		const int pitchResSizeX = roundToMultipleOf2(resSizeX, 8);
		
		Dtype* alignedResult;
		int status = posix_memalign((void**)&alignedResult, 32, (nOutputChannels * pitchResSizeX * resSizeY) * sizeof(Dtype));

		for (int i = 0; i < pitchResSizeX * resSizeY * nOutputChannels; i++) {
			alignedResult[i] = 0;
		}
		
		std::vector<int> inputShifts(sizeNonZeroes);
		const int kernelSize = kernelSizeX * kernelSizeY;
		for (int rowGroup = 0; rowGroup < nInputChannels; rowGroup++) {
			for (int realKernelRow = 0; realKernelRow < kernelSizeY; realKernelRow++) {
				for (int realKernelCol = 0; realKernelCol < kernelSizeX; realKernelCol++) {
					const int inputShift = imgSizeX * (imgSizeY * rowGroup + realKernelRow) + realKernelCol;
					
					const int row = rowGroup * kernelSize + realKernelRow * kernelSizeX + realKernelCol;
					
					const int begin = indicesRow[row];
					const int end   = indicesRow[row + 1];

					for (int outputY = 0; outputY < resSizeY; outputY++) {

						processRowNFix(
							&alignedResult[outputY * pitchResSizeX], 
							resSizeY * pitchResSizeX, 
							resSizeX,
							&img[inputShift + outputY * imgSizeX], 
							&kernel[begin], 
							&indicesCol[begin], 
							end - begin
						);
					}

					
			/*		for (int idx = begin; idx < end; idx++) {
						const int outputChannel = indicesCol[idx];
						const int outputShift = outputChannel * pitchResSizeX * resSizeY;
						const Dtype mult = kernel[idx];
					
						for (int outputY = 0; outputY < resSizeY; outputY++) {
							// reusing of mult
//							processRoww(&alignedResult[outputShift + outputY * pitchResSizeX], resSizeX, &img[inputShift + outputY * imgSizeX], mult);
							
							for (int outputX = 0; outputX < resSizeX; outputX++) {
								Dtype inputValue = img[inputShift + outputY * imgSizeX + outputX];
								const int outputChannel = indicesCol[idx];
								const Dtype kernelValue = kernel[idx];
								const int outputShift = outputChannel * pitchResSizeX * resSizeY;
								alignedResult[outputShift + outputY * pitchResSizeX + outputX] += inputValue * kernelValue;
							}
							
						}
					}
					 */
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
	
	
}

#undef CONVOLUTION_SPARSE_CACHE_HPP_
#endif // CONVOLUTION_SPARSE_CACHE_HPP_
