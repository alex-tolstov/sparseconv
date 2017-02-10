#ifdef USE_MKL

namespace caffe {
	
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
	

	/**
	 * Runs sparse GEMM using MKL library and the functions described here: 
	 * https://software.intel.com/en-us/node/468594
	 */  
    template <typename Dtype> inline
	void gustavsonCompressedMKL(
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
	}
}

#endif // USE_MKL
