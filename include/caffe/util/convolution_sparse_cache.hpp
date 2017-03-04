#ifndef CONVOLUTION_SPARSE_CACHE_HPP_
#define CONVOLUTION_SPARSE_CACHE_HPP_

#include "caffe/common.hpp"

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

	const int PERMUTATIONS[4] = {
			_MM_SHUFFLE(3, 2, 1, 0),
			_MM_SHUFFLE(0, 3, 2, 1),
			_MM_SHUFFLE(1, 0, 3, 2),
			_MM_SHUFFLE(2, 1, 0, 3),
	};

	const int BLENDS[8] = {
			0,
			(1 << 3) | ((1 << 3) << 4), // 0 0 0 1 0 0 0 1
			(1 << 2) | (1 << 3) | (((1 << 2) | (1 << 3)) << 4), // 0 0 1 1 0 0 1 1
			(1 << 1) | (1 << 2) | (1 << 3) | (((1 << 1) | (1 << 2) | (1 << 3)) << 4), // 0 1 1 1 0 1 1 1
			0,
			(~((1 << 3) | ((1 << 3) << 4))) & 0xFF, // 1 1 1 0 1 1 1 0
			(~((1 << 2) | (1 << 3) | (((1 << 2) | (1 << 3)) << 4))) & 0xFF, // 1 1 0 0 1 1 0 0
			(~((1 << 1) | (1 << 2) | (1 << 3) | (((1 << 1) | (1 << 2) | (1 << 3)) << 4))) & 0xFF // 1 0 0 0 1 0 0 0
	};

	__m256 run0(__m256 left, __m256 right) {
		return left;
	}

	__m256 run1(__m256 left, __m256 right) {
		__m256 blended = _mm256_blend_ps(left, right, (1 << 1) - 1);
		__m256 permuted = _mm256_permute_ps(blended, PERMUTATIONS[1]);
		__m256 swapped = _mm256_permute2f128_ps(permuted, permuted, 1);
		return _mm256_blend_ps(permuted, swapped, BLENDS[1]);
	}

	__m256 run2(__m256 left, __m256 right) {
		__m256 blended = _mm256_blend_ps(left, right, (1 << 2) - 1);
		__m256 permuted = _mm256_permute_ps(blended, PERMUTATIONS[2]);
		__m256 swapped = _mm256_permute2f128_ps(permuted, permuted, 1);
		return _mm256_blend_ps(permuted, swapped, BLENDS[2]);
	}

	__m256 run3(__m256 left, __m256 right) {
		__m256 blended = _mm256_blend_ps(left, right, (1 << 3) - 1);
		__m256 permuted = _mm256_permute_ps(blended, PERMUTATIONS[3]);
		__m256 swapped = _mm256_permute2f128_ps(permuted, permuted, 1);
		return _mm256_blend_ps(permuted, swapped, BLENDS[3]);
	}

	__m256 run4(__m256 left, __m256 right) {
		__m256 blended = _mm256_blend_ps(left, right, (1 << 4) - 1);
		__m256 swapped = _mm256_permute2f128_ps(blended, blended, 1);
		return swapped;
	}

	typedef __m256(*FunctionPointer)(__m256, __m256);
	FunctionPointer fp[5] = {&run0, &run1, &run2, &run3, &run4};

	__m256 join2Values(__m256 left, __m256 right, int shiftLeft) {
        // blend
        // permute
        // permute2f128ps
        // blend

        __m256 blended;
        __m256 permuted;
        __m256 swapped;
        switch (shiftLeft) {
            case 0:
                blended = _mm256_blend_ps(left, right, (1 << 0) - 1);
                return blended;
            case 1:
                blended = _mm256_blend_ps(left, right, (1 << 1) - 1);
                permuted = _mm256_permute_ps(blended, PERMUTATIONS[1]);
                swapped = _mm256_permute2f128_ps(permuted, permuted, 1);
                return _mm256_blend_ps(permuted, swapped, BLENDS[1]);
            case 2:
                blended = _mm256_blend_ps(left, right, (1 << 2) - 1);
                permuted = _mm256_permute_ps(blended, PERMUTATIONS[2]);
                swapped = _mm256_permute2f128_ps(permuted, permuted, 1);
                return _mm256_blend_ps(permuted, swapped, BLENDS[2]);
            case 3:
                blended = _mm256_blend_ps(left, right, (1 << 3) - 1);
                permuted = _mm256_permute_ps(blended, PERMUTATIONS[3]);
                swapped = _mm256_permute2f128_ps(permuted, permuted, 1);
                return _mm256_blend_ps(permuted, swapped, BLENDS[3]);
            case 4:
                blended = _mm256_blend_ps(left, right, (1 << 4) - 1);
                swapped = _mm256_permute2f128_ps(blended, blended, 1);
                return swapped;
            case 5:
                blended = _mm256_blend_ps(left, right, (1 << 5) - 1);
                permuted = _mm256_permute_ps(blended, PERMUTATIONS[1]);
                swapped = _mm256_permute2f128_ps(permuted, permuted, 1);

                return _mm256_blend_ps(permuted, swapped, BLENDS[5]);
            case 6:
                blended = _mm256_blend_ps(left, right, (1 << 6) - 1);
                permuted = _mm256_permute_ps(blended, PERMUTATIONS[2]);
                swapped = _mm256_permute2f128_ps(permuted, permuted, 1);

                return _mm256_blend_ps(permuted, swapped, BLENDS[6]);
            default:
                blended = _mm256_blend_ps(left, right, (1 << 7) - 1);
                permuted = _mm256_permute_ps(blended, PERMUTATIONS[3]);
                swapped = _mm256_permute2f128_ps(permuted, permuted, 1);
                return _mm256_blend_ps(permuted, swapped, BLENDS[7]);
        }
    }

	template<typename Dtype>
	void processRow2Output(
			Dtype* output,
			int outputStride,
			int resSizeY,
			int resSizeX,
			const Dtype* input,
			int nInputChannels,
            int inputSizeX,
            int inputSizeY,
			const Dtype* kernel,
			const int* cellInfo,
			const int* indicesChannel
	);

	template<>
	void processRow2Output<double>(
			double* output,
			int outputStride,
			int resSizeY,
			int resSizeX,
			const double* input,
			int nInputChannels,
            int inputSizeX,
            int inputSizeY,
			const double* kernel,
			const int* cellInfo,
			const int* indicesChannel
	){
		throw 1;
	}

	template<>
	void processRow2Output<float>(
		float* output,
		int resPitchSizeX,
		int resSizeY,
		int resSizeX,

		const float* input,
		int nInputChannels,
		int inputSizeX,
        int inputSizeY,

        const float* kernel,
		const int* cellInfo,
		const int* indicesChannel
	) {
		const int div8 = resSizeX / 8;

        const int inputSize = inputSizeX * inputSizeY;

		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;

			for (int inputRow = 0; inputRow < inputSizeY; inputRow++) {

				// output = N subsequent lines with the same offset, e.g. N=kernelSizeX
				// 2 might not be enough, for example if kernel={ {0, 0, 3}, {0, 0, 0}, {4, 0, 0} }

#define SIZE_RT 5
				__m256 collectedOutput[SIZE_RT];
				for (int innerOutputIdx = 0; innerOutputIdx < SIZE_RT; innerOutputIdx++) {
                    int realRowIdx = inputRow - innerOutputIdx;
					if (0 <= realRowIdx && realRowIdx < resSizeY) {
                        collectedOutput[innerOutputIdx] = _mm256_loadu_ps(
                                output + resPitchSizeX * realRowIdx + shift);
                    }
				}

				for (int inputChannel = 0; inputChannel < nInputChannels; inputChannel++) {
                    const int inputOffset = inputSize * inputChannel + inputRow * inputSizeX + shift;

					__m256 left = _mm256_loadu_ps (input + inputOffset);
                    __m256 right = _mm256_loadu_ps(input + inputOffset + 8);

                    const int begin = indicesChannel[inputChannel];
					const int end = indicesChannel[inputChannel + 1];
					for (int nonZeroValueIdx = begin; nonZeroValueIdx < end; nonZeroValueIdx++) {
						// kernelCol helps to extract correct input
						const int kernelColRow = cellInfo[nonZeroValueIdx];
						const int kernelCol = kernelColRow & 0xFF;
						// kernelRow helps to select correct output
						const int kernelRow = (kernelColRow >> 8) & 0xFF;

						int realRowIdx = inputRow - kernelRow;
						if (0 <= realRowIdx && realRowIdx < resSizeY) {

							__m256 multiplier = _mm256_set1_ps(kernel[nonZeroValueIdx]);

							__m256 generated = fp[kernelCol](left, right);//join2Values(left, right, kernelCol);

							collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow],
																	   _mm256_mul_ps(multiplier, generated));

						}
					}
				}

				for (int innerOutputIdx = 0; innerOutputIdx < SIZE_RT; innerOutputIdx++) {
					int realRowIdx = inputRow - innerOutputIdx;
					if (0 <= realRowIdx && realRowIdx < resSizeY) {
                        _mm256_storeu_ps(output + resPitchSizeX * realRowIdx + shift,
                                         collectedOutput[innerOutputIdx]);
                    }
				}
#undef SIZE_RT
			}
		}
	}


	template<typename Dtype>
	void directConvolutionRegisters(
			const Dtype *kernel,
			const int *cellInfo,
			const int *indicesChannels, // size = nInputChannels * nOutputChannels

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
        const int pitchResSizeY = roundToMultipleOf2(resSizeY, 8);

		Dtype* alignedResult;
		int status = posix_memalign((void**)&alignedResult, 32, (nOutputChannels * pitchResSizeX * pitchResSizeY) * sizeof(Dtype));

		if (status != 0) {
			throw "Cannot allocate memory";
		}

		for (int i = 0; i < pitchResSizeX * pitchResSizeY * nOutputChannels; i++) {
			alignedResult[i] = 0;
		}

		for (int outputChannelIdx = 0; outputChannelIdx < nOutputChannels; outputChannelIdx++) {
			const int outOffset = outputChannelIdx * pitchResSizeX * pitchResSizeY;
			Dtype *currRes = &alignedResult[outOffset];
			processRow2Output(
					currRes,
					pitchResSizeX,
					resSizeY,
					resSizeX,
					img,
					nInputChannels,
					imgSizeX,
                    imgSizeY,
					kernel,
					cellInfo,
					indicesChannels + nInputChannels * outputChannelIdx
			);
		}

		for (int ch = 0; ch < nOutputChannels; ch++) {
			for (int y = 0; y < resSizeY; y++) {
				for (int x = 0; x < resSizeX; x++) {
					res[ch * resSizeX * resSizeY + y * resSizeX + x] = alignedResult[ch * pitchResSizeX * pitchResSizeY + y * pitchResSizeX + x];
				}
			}
		}
		free(alignedResult);
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
