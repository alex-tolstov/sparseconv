#ifndef CONVOLUTION_CODE_GENERATION_HPP_
#define CONVOLUTION_CODE_GENERATION_HPP_

namespace caffe {
	
	inline int roundToMultipleOf2(int value, int round) {
		if (value % round == 0) {
			return value;
		} else {
			return (value / round + 1) * round;
		}
	}

	template<typename Dtype> 
	void processRowNF(Dtype* output, int resSizeX, const Dtype* input, const int* inputShifts, const Dtype* mult, int n);
		
	template<> 
	void processRowNF<float>(float* output, int resSizeX, const float* input, const int* inputShifts, const float* mult, int n) {
		const int div8 = resSizeX / 8;
		
		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;
			
			__m256 out = _mm256_set1_ps(0.0f);
			for (int inputIdx = 0; inputIdx < n; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[inputIdx]);

				__m256 in = _mm256_loadu_ps (input + inputShifts[inputIdx] + shift);
				
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out = _mm256_add_ps (multiplied, out);
			}
			
			_mm256_store_ps (output + shift, out);
		}
	}
	
	template<> 
	void processRowNF<double>(double* output, int resSizeX, const double* input, const int* inputShifts, const double* mult, int n) {
		throw 1;
	}
	
	template<typename Dtype> 
	void processRowNF2(Dtype* output, Dtype* output2, int resSizeX, const Dtype *input, const int* inputShift0, const int* inputShift1, const Dtype* mult, const Dtype* mult2, int n, int n2);
		
	template<> 
	void processRowNF2<float>(float* output, float* output2, int resSizeX, const float *input, const int* inputShift0, const int* inputShift1, const float* mult, const float* mult2, int n, int n2) {
		const int div8 = resSizeX / 8;
		
		int min = std::min(n, n2);
		
		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;
			
			__m256 out = _mm256_set1_ps(0.0f);
			__m256 out2 = _mm256_set1_ps(0.0f);
			for (int inputIdx = 0; inputIdx < min; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[inputIdx]);
				__m256 factor2 = _mm256_set1_ps (mult2[inputIdx]);

				// probably, it is cached
				__m256 in = _mm256_loadu_ps (input + inputShift0[inputIdx] + shift);
				__m256 in2 = _mm256_loadu_ps (input + inputShift1[inputIdx] + shift);
				
				__m256 multiplied = _mm256_mul_ps (in, factor);
				__m256 multiplied2 = _mm256_mul_ps (in2, factor2);
				
				out = _mm256_add_ps (multiplied, out);
				out2 = _mm256_add_ps (multiplied2, out2);
			}
			
			for (int inputIdx = min; inputIdx < n; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[inputIdx]);

				__m256 in = _mm256_loadu_ps (input + inputShift0[inputIdx] + shift);
				
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out = _mm256_add_ps (multiplied, out);
			}
			
			for (int inputIdx = min; inputIdx < n2; inputIdx++) {
				__m256 factor2 = _mm256_set1_ps (mult2[inputIdx]);

				__m256 in2 = _mm256_loadu_ps (input + inputShift1[inputIdx] + shift);
				
				__m256 multiplied2 = _mm256_mul_ps (in2, factor2);
				
				out2 = _mm256_add_ps (multiplied2, out2);
			}
			
			_mm256_store_ps (output + shift, out);
			_mm256_store_ps (output2 + shift, out2);
		}
	}
	
	template<> 
	void processRowNF2<double>(double* output, double* output2, int resSizeX, const double *input, const int* inputShift0, const int* inputShift1, const double* mult, const double* mult2, int n, int n2) {
		throw 1;
	}
	
		template<typename Dtype> 
	inline void processRowNF4(
		Dtype** output, 
		int resSizeX, 
		const Dtype*** input, 
		const Dtype** mult,  
		int* n
	);
		
	template<> 
	inline void processRowNF4<float>(
		float** output, 
		int resSizeX, 
		const float*** input, 
		const float** mult,  
		int* n
	) {
		const int div8 = resSizeX / 8;
		
		int min = std::min(std::min(n[0], n[1]), std::min(n[2], n[3]));
		
		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;
			
			__m256 out = _mm256_set1_ps(0.0f);
			__m256 out2 = _mm256_set1_ps(0.0f);
			__m256 out3 = _mm256_set1_ps(0.0f);
			__m256 out4 = _mm256_set1_ps(0.0f);

			for (int inputIdx = 0; inputIdx < min; inputIdx++) {
				__m256 factor =  _mm256_set1_ps (mult[0][inputIdx]);
				__m256 factor2 = _mm256_set1_ps (mult[1][inputIdx]);
				__m256 factor3 = _mm256_set1_ps (mult[2][inputIdx]);
				__m256 factor4 = _mm256_set1_ps (mult[3][inputIdx]);

				// probably, it is cached
				__m256 in  = _mm256_loadu_ps (input[0][inputIdx] + shift);
				__m256 in2 = _mm256_loadu_ps (input[1][inputIdx] + shift);
				__m256 in3 = _mm256_loadu_ps (input[2][inputIdx] + shift);
				__m256 in4 = _mm256_loadu_ps (input[3][inputIdx] + shift);
				
				__m256 multiplied  = _mm256_mul_ps (in,  factor);
				__m256 multiplied2 = _mm256_mul_ps (in2, factor2);
				__m256 multiplied3 = _mm256_mul_ps (in3, factor3);
				__m256 multiplied4 = _mm256_mul_ps (in4, factor4);
				
				out  = _mm256_add_ps (multiplied,  out);
				out2 = _mm256_add_ps (multiplied2, out2);
				out3 = _mm256_add_ps (multiplied3, out3);
				out4 = _mm256_add_ps (multiplied4, out4);
			}
			
			for (int inputIdx = min; inputIdx < n[0]; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[0][inputIdx]);
				__m256 in = _mm256_loadu_ps (input[0][inputIdx] + shift);
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out = _mm256_add_ps (multiplied, out);
			}
			
			for (int inputIdx = min; inputIdx < n[1]; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[1][inputIdx]);
				__m256 in = _mm256_loadu_ps (input[1][inputIdx] + shift);
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out2 = _mm256_add_ps (multiplied, out2);
			}

			for (int inputIdx = min; inputIdx < n[2]; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[2][inputIdx]);
				__m256 in = _mm256_loadu_ps (input[2][inputIdx] + shift);
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out3 = _mm256_add_ps (multiplied, out3);
			}

			for (int inputIdx = min; inputIdx < n[3]; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[3][inputIdx]);
				__m256 in = _mm256_loadu_ps (input[3][inputIdx] + shift);
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out4 = _mm256_add_ps (multiplied, out4);
			}
			
			_mm256_store_ps (output[0] + shift, out);
			_mm256_store_ps (output[1] + shift, out2);
			_mm256_store_ps (output[2] + shift, out3);
			_mm256_store_ps (output[3] + shift, out4);
		}
	}
	
	template<> 
	inline void processRowNF4<double>(
		double** output, 
		int resSizeX, 
		const double*** input, 
		const double** mult,  
		int* n
	){}

	/*
	
	template<> 
	inline void processRowNFF2<float>(float* output, float* output2, int resSizeX, const float** input, const float** input2, const float* mult, const float* mult2, int n, int n2) {
		const int div8 = resSizeX / 8;
		
		int min = std::min(n, n2);
		
		for (int i = 0; i < div8; i++) {
			const int shift = i << 3;
			
			__m256 out = _mm256_set1_ps(0.0f);
			__m256 out2 = _mm256_set1_ps(0.0f);
			for (int inputIdx = 0; inputIdx < min; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[inputIdx]);
				__m256 factor2 = _mm256_set1_ps (mult2[inputIdx]);

				// we're reading the same input and sharing it between the members. moreover, it is aligned
				__m256 in = _mm256_load_ps (input[inputIdx] + shift);
				
				if (shift + 8 <= minShift1) {
					// do nothing
				} else {
					// do shift
				} else {
					// do multiplication
				}
				
				__m256 multiplied = _mm256_mul_ps (in, factor);
				__m256 multiplied2 = _mm256_mul_ps (in2, factor2);
				
				out = _mm256_add_ps (multiplied, out);
				out2 = _mm256_add_ps (multiplied2, out2);
			}
			
			for (int inputIdx = min; inputIdx < n; inputIdx++) {
				__m256 factor = _mm256_set1_ps (mult[inputIdx]);

				__m256 in = _mm256_loadu_ps (input[inputIdx] + shift);
				
				__m256 multiplied = _mm256_mul_ps (in, factor);
				
				out = _mm256_add_ps (multiplied, out);
			}
			
			for (int inputIdx = min; inputIdx < n2; inputIdx++) {
				__m256 factor2 = _mm256_set1_ps (mult2[inputIdx]);

				__m256 in2 = _mm256_loadu_ps (input2[inputIdx] + shift);
				
				__m256 multiplied2 = _mm256_mul_ps (in2, factor2);
				
				out2 = _mm256_add_ps (multiplied2, out2);
			}
			
			_mm256_store_ps (output + shift, out);
			_mm256_store_ps (output2 + shift, out2);
		}
	}
	*/
	
	// steps of re-using memory
	// 1. reusing input
	// how to do it? we have several input channels. by means processing kernels of the same input channel one can reuse input
	// drawbacks: it is possible that output cannot be reused in that case unless single output channel is processed separately.
	// 
	// 2. reusing output
	// one can reuse all output fields by consequent processing, writing only once.
	// but for this case we need to be careful to read 3 things:
	//  - input (cannot be hardcoded), and it is better to reuse it (how??).
	//  - mult (hardcoded)
	//  - kernel settings for every case (hardcoded), i.e. offset of input
	// 
	// NEXT STEP HERE IS TO TRY CLASSIC IMPLEMENTATION
	// 
	// 3. reusing both input and output
	// process 2, 3, 4 subsequent output channels at the moment. write once to them, but read from the same input!
	// how to read from the same input? it is hard because even if the input is the same, it can be that non-zero values have different indices.
	// in this case we have 2 possibilities:
	// 1) input will be cached anyway (and it is good)
	// 2) make calculation with the whole input. just shift input after reading. -- interesting idea, need to think more about it.
	template<typename Dtype>
	void generateCode(
		const Dtype *kernel, 
		const int *indicesCol,
		const int *indicesRow,
		const int sizeNonZeroes,
	
		const int kernelSizeX,
		const int kernelSizeY
	) {
		printf("{");
			
		printf("}");
	}
	/*
	template<typename Dtype>
	void directConvolutionWriteOutput4(
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
		const int pitchResSizeX = roundToMultipleOf2(resSizeX, 8);
		
		Dtype* alignedResult;
		posix_memalign((void**)&alignedResult, 32, (nOutputChannels * pitchResSizeX * resSizeY) * sizeof(Dtype));
		for (int i = 0; i < pitchResSizeX * resSizeY * nOutputChannels; i++) {
			alignedResult[i] = 0;
		}
		
		std::vector<const Dtype*> inputs(sizeNonZeroes);
		std::vector<const Dtype*> outputs(nOutputChannels);
		
		const int kernelSize = kernelSizeX * kernelSizeY;
		for (int row = 0; row < nOutputChannels; row += 4) {
			for (int shift = 0; shift < 4; shift++) {
				outputs[row + shift] = alignedResult + pitchResSizeX * resSizeY * (row + shift);
			}
			
			const int begin = indicesRow[row];
			const int end =   indicesRow[row + 1];
			const int end2 =  indicesRow[row + 2];
			const int end3 =  indicesRow[row + 3];
			const int end4 =  indicesRow[row + 4];
			
			for (int idx = begin; idx < end4; idx++) {
				int kernelCol = indicesCol[idx];
				
				std::div_t divRes = std::div(kernelCol, kernelSize);
				const int channelIdx = divRes.quot;
				kernelCol = divRes.rem;
				
				const int realKernelRow = kernelCol / kernelSizeX;
				const int realKernelCol = kernelCol % kernelSizeX;
		
				const Dtype *input = img + imgSizeX * (imgSizeY * channelIdx + realKernelRow) + realKernelCol;

				inputs[idx] = input;
			}
			
			for (int y = 0; y < resSizeY; y++) {
				processRowNF4(currRes, currRes2, resSizeX, &inputs[begin], &inputs[end], &kernel[begin], &kernel[end], end - begin, end2 - end);
			
				for (int shift = 0; shift < 4; shift++) {
					currRes[row + shift] += pitchResSizeX;
				}
				
				for (int idx = begin; idx < end4; idx++) {
					inputs[idx] += imgSizeX;
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
	*/
	
	template<typename Dtype>
	void directConvolutionWriteOutput(
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
		const int pitchResSizeX = roundToMultipleOf2(resSizeX, 8);
		
		Dtype* alignedResult;
		posix_memalign((void**)&alignedResult, 32, (nOutputChannels * pitchResSizeX * resSizeY) * sizeof(Dtype));
		for (int i = 0; i < pitchResSizeX * resSizeY * nOutputChannels; i++) {
			alignedResult[i] = 0;
		}
		
		std::vector<int> inputShifts(sizeNonZeroes);
		const int kernelSize = kernelSizeX * kernelSizeY;
		for (int row = 0; row < nOutputChannels; row += 2) {
			const int res_off = pitchResSizeX * resSizeY * row;
			const int res_off2 = pitchResSizeX * resSizeY * (row + 1);
			
			const int begin = indicesRow[row];
			const int end =   indicesRow[row + 1];
			const int end2 =  indicesRow[row + 2];
			
			for (int idx = begin; idx < end2; idx++) {
				int kernelCol = indicesCol[idx];
				
				std::div_t divRes = std::div(kernelCol, kernelSize);
				const int channelIdx = divRes.quot;
				kernelCol = divRes.rem;
				
				const int realKernelRow = kernelCol / kernelSizeX;
				const int realKernelCol = kernelCol % kernelSizeX;
		
				inputShifts[idx] = imgSizeX * (imgSizeY * channelIdx + realKernelRow) + realKernelCol;
			}
			
			Dtype *currRes  = alignedResult + res_off;
			Dtype *currRes2 = alignedResult + res_off2;
			
			const Dtype *imgg = img;
			
			for (int y = 0; y < resSizeY; y++, imgg += imgSizeX, currRes += pitchResSizeX, currRes2 += pitchResSizeX) {
				processRowNF2(currRes, currRes2, resSizeX, imgg, &inputShifts[begin], &inputShifts[end], &kernel[begin], &kernel[end], end - begin, end2 - end);
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
	
	
	template<typename Dtype>
	void directConvolutionWriteOutput1(
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
		const int pitchResSizeX = roundToMultipleOf2(resSizeX, 8);
		
		Dtype* alignedResult;
		posix_memalign((void**)&alignedResult, 32, (nOutputChannels * pitchResSizeX * resSizeY) * sizeof(Dtype));
		for (int i = 0; i < pitchResSizeX * resSizeY * nOutputChannels; i++) {
			alignedResult[i] = 0;
		}
		
		std::vector<int> inputShifts(sizeNonZeroes);
		const int kernelSize = kernelSizeX * kernelSizeY;
		for (int row = 0; row < nOutputChannels; row++) {
			const int res_off = pitchResSizeX * resSizeY * row;

			const int begin = indicesRow[row];
			const int end =   indicesRow[row + 1];
			
			for (int idx = begin; idx < end; idx++) {
				int kernelCol = indicesCol[idx];
				
				std::div_t divRes = std::div(kernelCol, kernelSize);
				const int channelIdx = divRes.quot;
				kernelCol = divRes.rem;
				
				const int realKernelRow = kernelCol / kernelSizeX;
				const int realKernelCol = kernelCol % kernelSizeX;
		
				inputShifts[idx] = imgSizeX * (imgSizeY * channelIdx + realKernelRow) + realKernelCol;
			}
			
			Dtype *currRes  = alignedResult + res_off;
			
			const Dtype *imgg = img;
			
			for (int y = 0; y < resSizeY; y++, imgg += imgSizeX, currRes += pitchResSizeX) {
				processRowNF(currRes, resSizeX, imgg, &inputShifts[begin], &kernel[begin], end - begin);
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

#undef CONVOLUTION_CODE_GENERATION_HPP_
#endif // CONVOLUTION_CODE_GENERATION_HPP_
