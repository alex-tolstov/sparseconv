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
};
