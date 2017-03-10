//
// Created by alex on 09.03.17.
//

#ifndef CAFFE_CODEGEN_H
#define CAFFE_CODEGEN_H

namespace caffe {

template<typename Dtype>
std::string directConvolutionRegistersCodegen(
        const Dtype *kernel,
        const int *cellInfo,
        const int *indicesChannels, // size = nInputChannels * nOutputChannels

        const int kernelSizeX,

        const int kernelSizeY,

        const int nInputChannels,
        const int nOutputChannels
) {
    std::stringstream code;

    code << "void run(const float *input, const int imgSizeX, const int imgSizeY, float *output, const int outputPitchX, const int resSizeX, const int resSizeY) {" << std::endl;

    code << "\tconst int kernelSizeY = " << kernelSizeY << ";" << std::endl;
    code << "\tconst int inputSize = imgSizeX * imgSizeY;" << std::endl;
    for (int outputChannelIdx = 0; outputChannelIdx < nOutputChannels; outputChannelIdx++) {
        code << "\t{" << std::endl;

        code << "\tint outputChannelIdx=" << outputChannelIdx << ";" << std::endl;
        code << "\tfor (int dim = 0; dim < resSizeX / 8; dim++) {" << std::endl;
        code << "\t\tconst int shift = dim << 3;" << std::endl;
        code << "\t\t__m256 collectedOutput[" << kernelSizeY << "];" << std::endl;
        for (int i = 0; i < kernelSizeY; i++) {
            code << "\t\tcollectedOutput[" << i << "] = _mm256_setzero_ps();" << std::endl;
        }
        code << "\t\tfor (int inputRow = 0; inputRow < imgSizeY; inputRow++) {" << std::endl;
        for (int i = kernelSizeY - 1; i > 0; i--) {
            code << "\t\t\tcollectedOutput[" << i << "] = collectedOutput[" << i - 1 << "];" << std::endl;
        }
        code << "\t\t\tcollectedOutput[0] = _mm256_setzero_ps();" << std::endl;

        for (int inputChannelIdx = 0; inputChannelIdx < nInputChannels; inputChannelIdx++) {
            code << "\t\t\tconst int inputChannelIdx = " << inputChannelIdx << ";" << std::endl;
            code << "\t\t\tconst int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;" << std::endl;

            const int beginIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx];
            const int endIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx + 1];

            for (int kernelValueIdx = beginIdx; kernelValueIdx < endIdx; kernelValueIdx++) {
                const int kernelColRow = cellInfo[kernelValueIdx];
                const int kernelCol = kernelColRow & 0xFF;
                const int kernelRow = (kernelColRow >> 8) & 0xFF;
                const Dtype value = kernel[kernelValueIdx];

                code << "\t\t\t{" << std::endl;
                code << "\t\t\t\tconst int kernelCol=" << kernelCol << ";"<< std::endl;
                code << "\t\t\t\tconst int kernelRow=" << kernelRow << ";"<< std::endl;
                code << "\t\t\t\tconst float value=" << value << ";"<< std::endl;
                code << "\t\t\t\t__m256 multiplier = _mm256_set1_ps(value);"<< std::endl;
                code << "\t\t\t\t__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);"<< std::endl;
                code << "\t\t\t\tcollectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));"<< std::endl;
                code << "\t\t\t}" << std::endl;
            }
        }

        code << "\t\t\tconst int realRowIdx = inputRow - (kernelSizeY - 1);" << std::endl;
        code << "\t\t\tif (realRowIdx >= 0) {" << std::endl;
        code << "\t\t\t\t_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);" << std::endl;
        code << "\t\t\t}" << std::endl;

        code << "\t\t}" << std::endl;
        code << "\t}" << std::endl;
        code << "\t}" << std::endl;
    }
    code << "}" << std::endl; // function
    return code.str();
}
}
#endif //CAFFE_CODEGEN_H
