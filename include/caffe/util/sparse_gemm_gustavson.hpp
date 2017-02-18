#ifndef SPARSE_GEMM_GUSTAVSON_HPP_
#define SPARSE_GEMM_GUSTAVSON_HPP_

namespace caffe {
	
	/**
	 * Performs sparse-dense matrix multiplication C = A * B using Gustavson algorithm.
	 * 
	 * Original paper by F. Gustavson: "Two Fast Algorithms for Sparse Matrices: Multiplication and Permuted Transposition."
	 * 
	 * Input of a kernel is CSR (compressed sparse row) format which is a default one for representing 
	 * sparse matrices and can be used by plenty of sparse SGEMM libraries.
	 * 
	 * Usually kernel input is not just a single 3x3 or 5x5 one. It is a combination of kernels that are applied to the input image
	 * according to internal parameters: size of kernel, number of input channels, number of output channels.
	 * 
	 * @param kernelValues 
	 * 				array of non-zero values in kernel (matrix A).
	 * @param indicesCol 
	 * 				array of column indices per every value in kernel.
	 * @param indicesRow
	 * 				array of column indices inside row. indicesRow[row] is the first index of non-zero element in the row,
	 * 				indicesRow[row + 1] - 1 is the last index of non-zero element in the row. Hence, the size of the array
	 * 				equals to number of rows + 1.
	 * @param sizeNonZeroes 
	 * 				amount of non-zero elements in kernel.
	 * 
	 * @param img
	 * 				pointer to the input image (matrix B). Usually it contains an image after "im2col" operation.
	 * @param imgSizeX 
	 * 				width of img.
	 * @param imgSizeY
	 * 				height of img.
	 * 
	 * @param res
	 * 				pointer to the output image (matrix C).
	 * @param resSizeX
	 * 				width of res. Must be equal to imgSizeX.
	 * @param resSizeY
	 * 				height of res. Must be equal to number of rows in the kernel matrix.
	 */
	template <typename Dtype> 
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
		for (int i = 0; i < resSizeX * resSizeY; i++) {
			res[i] = 0;
		}
		
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
	}
}


#undef SPARSE_GEMM_GUSTAVSON_HPP_ 
#endif
