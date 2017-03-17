#ifndef CSR_HPP_
#define CSR_HPP_

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

	template <class Dtype>
	inline void convertKernelToCompressedChannelsSpecial(
			const Dtype *kernel,
			const int sizeX,
			const int sizeY,
			const int kernelSizeX,
			const int kernelSizeY,
			std::vector<Dtype> &values,
			std::vector<int> &cellInfo,
			std::vector<int> &indicesChannel,
			std::vector<int> &indicesRow
	) {
		const int kernelSize = kernelSizeX * kernelSizeY;
		const int channelSize = kernelSize;
		int lastIndex = 0;
		indicesRow.push_back(0);
		indicesChannel.push_back(0);
        std::vector<int> counts(1 + kernelSize, 0);

//        std::stringstream fileName;
//        fileName << "/home/alex/paulsutter/weights_" << sizeX * sizeY << ".csv";
//        LOG(INFO) << "kernels csv fileName=" << fileName.str();
//        std::ofstream f;
//        f.open(fileName.str().c_str());
//
//        f << "nOutputChannels=" << sizeY << ", nInputChannels=" << sizeX / channelSize << ", kernelSizeX=" << kernelSizeX << ", kernelSizeY=" << kernelSizeY << std::endl;

		for (int y = 0; y < sizeY; y++) {
			const int nChannels = sizeX / channelSize;
			for (int ch = 0; ch < nChannels; ch++) {
				int countInTheChannel = 0;
				for (int kRow = 0; kRow < kernelSizeY; kRow++) {
					for (int kCol = 0; kCol < kernelSizeX; kCol++) {
                        Dtype value = kernel[y * sizeX + ch * channelSize + kRow * kernelSizeX + kCol];
//                        if (kCol != 0) {
//                            f << ",";
//                        }
//                        f << value;
                        if (value != 0) {
                            values.push_back(value);

                            int kx = kCol;
                            int ky = kRow;

                            cellInfo.push_back(kx + (ky << 8));

                            countInTheChannel++;
                        }
                    }
//                    f << std::endl;
                }
//                f << std::endl << std::endl;
                counts[countInTheChannel]++;
				lastIndex += countInTheChannel;
				indicesChannel.push_back(lastIndex);
			}
//            f << std::endl << std::endl << std::endl;
            indicesRow.push_back(lastIndex);
		}

//        f.close();


	}


	template <typename Dtype>
	inline void transpose(Dtype *matrix, int size_x, int size_y) {
		std::vector<Dtype> transp(size_x * size_y);
		int new_size_x = size_y;
		int new_size_y = size_x;
		for (int y = 0; y < new_size_y; y++) {
			for (int x = 0; x < new_size_x; x++) {
				transp[y * new_size_x + x] = matrix[x * size_x + y];
			}
		}
		for (int i = 0; i < size_x * size_y; i++) {
			matrix[i] = transp[i];
		}
	}

}

#undef CSR_HPP_
#endif
