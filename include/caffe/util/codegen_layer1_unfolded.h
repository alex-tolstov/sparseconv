//
// Created by alex on 17.03.17.
//

#ifndef CAFFE_CODEGEN_LAYER1_UNFOLDED_H
#define CAFFE_CODEGEN_LAYER1_UNFOLDED_H


template<typename Dtype>
void run20Unfolded(const Dtype *img, const int imgSizeX, const int imgSizeY, Dtype *output, const int outputPitchX,
          const int outputSizeX, const int outputSizeY);

template<>
void run20Unfolded<double>(const double *img, const int imgSizeX, const int imgSizeY, double *output, const int outputPitchX,
                  const int outputSizeX, const int outputSizeY) {
    throw 1;
}


template<>
void run20Unfolded(const float *input, const int imgSizeX, const int imgSizeY, float *output, const int outputPitchX, const int resSizeX, const int resSizeY) {
    const int kernelSizeY = 5;
    const int inputSize = imgSizeX * imgSizeY;
    {
        int outputChannelIdx=0;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=1;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            __m256 collectedOutput[5];
            collectedOutput[0] = _mm256_setzero_ps();
            collectedOutput[1] = _mm256_setzero_ps();
            collectedOutput[2] = _mm256_setzero_ps();
            collectedOutput[3] = _mm256_setzero_ps();
            collectedOutput[4] = _mm256_setzero_ps();
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                collectedOutput[4] = collectedOutput[3];
                collectedOutput[3] = collectedOutput[2];
                collectedOutput[2] = collectedOutput[1];
                collectedOutput[1] = collectedOutput[0];
                collectedOutput[0] = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
                    {
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const float value=-0.391116;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=4;
                        const float value=0.43902;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                }
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
                }
            }
        }
    }
    {
        int outputChannelIdx=2;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            __m256 collectedOutput[5];
            collectedOutput[0] = _mm256_setzero_ps();
            collectedOutput[1] = _mm256_setzero_ps();
            collectedOutput[2] = _mm256_setzero_ps();
            collectedOutput[3] = _mm256_setzero_ps();
            collectedOutput[4] = _mm256_setzero_ps();
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                collectedOutput[4] = collectedOutput[3];
                collectedOutput[3] = collectedOutput[2];
                collectedOutput[2] = collectedOutput[1];
                collectedOutput[1] = collectedOutput[0];
                collectedOutput[0] = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
                    {
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const float value=0.474224;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const float value=0.56209;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=2;
                        const float value=0.512386;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                }
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
                }
            }
        }
    }
    {
        int outputChannelIdx=3;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=4;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=5;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=6;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=7;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            __m256 collectedOutput[5];
            collectedOutput[0] = _mm256_setzero_ps();
            collectedOutput[1] = _mm256_setzero_ps();
            collectedOutput[2] = _mm256_setzero_ps();
            collectedOutput[3] = _mm256_setzero_ps();
            collectedOutput[4] = _mm256_setzero_ps();
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                collectedOutput[4] = collectedOutput[3];
                collectedOutput[3] = collectedOutput[2];
                collectedOutput[2] = collectedOutput[1];
                collectedOutput[1] = collectedOutput[0];
                collectedOutput[0] = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
                    {
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const float value=0.400998;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const float value=0.54322;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const float value=0.441568;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=1;
                        const float value=-0.551391;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=2;
                        const float value=0.735526;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=2;
                        const float value=-0.801157;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=3;
                        const float value=0.694164;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=3;
                        const float value=-0.77963;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=4;
                        const float value=-0.397199;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                }
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
                }
            }
        }
    }
    {
        int outputChannelIdx=8;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=9;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            __m256 collectedOutput[5];
            collectedOutput[0] = _mm256_setzero_ps();
            collectedOutput[1] = _mm256_setzero_ps();
            collectedOutput[2] = _mm256_setzero_ps();
            collectedOutput[3] = _mm256_setzero_ps();
            collectedOutput[4] = _mm256_setzero_ps();
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                collectedOutput[4] = collectedOutput[3];
                collectedOutput[3] = collectedOutput[2];
                collectedOutput[2] = collectedOutput[1];
                collectedOutput[1] = collectedOutput[0];
                collectedOutput[0] = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
                    {
                        const int kernelCol=4;
                        const int kernelRow=0;
                        const float value=0.434259;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=0;
                        const int kernelRow=1;
                        const float value=0.559004;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const float value=0.474154;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=3;
                        const int kernelRow=1;
                        const float value=0.7786;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=1;
                        const float value=0.78912;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=3;
                        const int kernelRow=3;
                        const float value=-0.530108;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=0;
                        const int kernelRow=4;
                        const float value=-0.546822;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=4;
                        const float value=-0.591119;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=4;
                        const float value=-0.763197;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=3;
                        const int kernelRow=4;
                        const float value=-0.625386;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                }
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
                }
            }
        }
    }
    {
        int outputChannelIdx=10;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            __m256 collectedOutput[5];
            collectedOutput[0] = _mm256_setzero_ps();
            collectedOutput[1] = _mm256_setzero_ps();
            collectedOutput[2] = _mm256_setzero_ps();
            collectedOutput[3] = _mm256_setzero_ps();
            collectedOutput[4] = _mm256_setzero_ps();
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                collectedOutput[4] = collectedOutput[3];
                collectedOutput[3] = collectedOutput[2];
                collectedOutput[2] = collectedOutput[1];
                collectedOutput[1] = collectedOutput[0];
                collectedOutput[0] = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
                    {
                        const int kernelCol=1;
                        const int kernelRow=2;
                        const float value=0.612788;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=2;
                        const float value=0.601036;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=3;
                        const float value=0.416437;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                }
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
                }
            }
        }
    }
    {
        int outputChannelIdx=11;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=12;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=13;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=14;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            __m256 collectedOutput[5];
            collectedOutput[0] = _mm256_setzero_ps();
            collectedOutput[1] = _mm256_setzero_ps();
            collectedOutput[2] = _mm256_setzero_ps();
            collectedOutput[3] = _mm256_setzero_ps();
            collectedOutput[4] = _mm256_setzero_ps();
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                collectedOutput[4] = collectedOutput[3];
                collectedOutput[3] = collectedOutput[2];
                collectedOutput[2] = collectedOutput[1];
                collectedOutput[1] = collectedOutput[0];
                collectedOutput[0] = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
                    {
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const float value=-0.645686;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=0;
                        const int kernelRow=1;
                        const float value=-0.585144;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const float value=-0.793905;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const float value=-0.42832;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=0;
                        const int kernelRow=2;
                        const float value=-0.555653;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=3;
                        const float value=0.44683;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=3;
                        const float value=0.444221;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                }
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
                }
            }
        }
    }
    {
        int outputChannelIdx=15;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=16;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            __m256 collectedOutput[5];
            collectedOutput[0] = _mm256_setzero_ps();
            collectedOutput[1] = _mm256_setzero_ps();
            collectedOutput[2] = _mm256_setzero_ps();
            collectedOutput[3] = _mm256_setzero_ps();
            collectedOutput[4] = _mm256_setzero_ps();
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                collectedOutput[4] = collectedOutput[3];
                collectedOutput[3] = collectedOutput[2];
                collectedOutput[2] = collectedOutput[1];
                collectedOutput[1] = collectedOutput[0];
                collectedOutput[0] = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
                    {
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const float value=-0.42673;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const float value=-0.842605;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=3;
                        const int kernelRow=1;
                        const float value=-0.767503;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=0;
                        const int kernelRow=2;
                        const float value=0.527516;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=2;
                        const float value=0.403925;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=2;
                        const float value=-0.384715;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=3;
                        const int kernelRow=2;
                        const float value=-0.707691;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=2;
                        const float value=-0.465529;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=0;
                        const int kernelRow=3;
                        const float value=0.412613;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=3;
                        const float value=0.903525;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=3;
                        const float value=0.495898;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=4;
                        const float value=0.426623;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=4;
                        const float value=0.795484;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=3;
                        const int kernelRow=4;
                        const float value=0.499817;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                }
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
                }
            }
        }
    }
    {
        int outputChannelIdx=17;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
                }
            }
        }
    }
    {
        int outputChannelIdx=18;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            __m256 collectedOutput[5];
            collectedOutput[0] = _mm256_setzero_ps();
            collectedOutput[1] = _mm256_setzero_ps();
            collectedOutput[2] = _mm256_setzero_ps();
            collectedOutput[3] = _mm256_setzero_ps();
            collectedOutput[4] = _mm256_setzero_ps();
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                collectedOutput[4] = collectedOutput[3];
                collectedOutput[3] = collectedOutput[2];
                collectedOutput[2] = collectedOutput[1];
                collectedOutput[1] = collectedOutput[0];
                collectedOutput[0] = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
                    {
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const float value=0.406751;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                }
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
                }
            }
        }
    }
    {
        int outputChannelIdx=19;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            __m256 collectedOutput[5];
            collectedOutput[0] = _mm256_setzero_ps();
            collectedOutput[1] = _mm256_setzero_ps();
            collectedOutput[2] = _mm256_setzero_ps();
            collectedOutput[3] = _mm256_setzero_ps();
            collectedOutput[4] = _mm256_setzero_ps();
            for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
                collectedOutput[4] = collectedOutput[3];
                collectedOutput[3] = collectedOutput[2];
                collectedOutput[2] = collectedOutput[1];
                collectedOutput[1] = collectedOutput[0];
                collectedOutput[0] = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
                    {
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const float value=-0.686802;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const float value=-0.517685;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=3;
                        const int kernelRow=1;
                        const float value=0.53314;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=1;
                        const float value=0.571746;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=2;
                        const float value=0.609644;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=3;
                        const int kernelRow=2;
                        const float value=0.921052;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=1;
                        const int kernelRow=3;
                        const float value=0.551618;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=2;
                        const int kernelRow=3;
                        const float value=0.44885;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=3;
                        const float value=-0.55193;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                    {
                        const int kernelCol=4;
                        const int kernelRow=4;
                        const float value=-0.389678;
                        __m256 multiplier = _mm256_set1_ps(value);
                        __m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
                        collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
                    }
                }
                const int realRowIdx = inputRow - (kernelSizeY - 1);
                if (realRowIdx >= 0) {
                    _mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
                }
            }
        }
    }
}




#endif //CAFFE_CODEGEN_LAYER1_UNFOLDED_H
