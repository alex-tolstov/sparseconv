#ifndef CAFFE_CODEGEN_TRAD_H
#define CAFFE_CODEGEN_TRAD_H

template<typename Dtype>
void runTraditional20(const Dtype *input, const int imgSizeX, const int imgSizeY, Dtype *output, const int outputPitchX, const int resSizeX, const int resSizeY);

template<>
void runTraditional20<double>(const double *input, const int imgSizeX, const int imgSizeY, double *output, const int outputPitchX, const int resSizeX, const int resSizeY) {

}

template<> void runTraditional20<float>(const float *input, const int imgSizeX, const int imgSizeY, float *output, const int outputPitchX, const int resSizeX, const int resSizeY) {
    {
        const int outputChannelIdx=0;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=1;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
                    {__m256 factor = _mm256_set1_ps(-0.391116);
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.43902);
                        const int kernelCol=2;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                }
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=2;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
                    {__m256 factor = _mm256_set1_ps(0.474224);
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.56209);
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.512386);
                        const int kernelCol=4;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                }
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=3;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=4;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=5;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=6;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=7;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
                    {__m256 factor = _mm256_set1_ps(0.400998);
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.54322);
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.441568);
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.551391);
                        const int kernelCol=4;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.735526);
                        const int kernelCol=1;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.801157);
                        const int kernelCol=4;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.694164);
                        const int kernelCol=1;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.77963);
                        const int kernelCol=4;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.397199);
                        const int kernelCol=4;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                }
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=8;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=9;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
                    {__m256 factor = _mm256_set1_ps(0.434259);
                        const int kernelCol=4;
                        const int kernelRow=0;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.559004);
                        const int kernelCol=0;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.474154);
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.7786);
                        const int kernelCol=3;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.78912);
                        const int kernelCol=4;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.530108);
                        const int kernelCol=3;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.546822);
                        const int kernelCol=0;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.591119);
                        const int kernelCol=1;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.763197);
                        const int kernelCol=2;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.625386);
                        const int kernelCol=3;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                }
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=10;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
                    {__m256 factor = _mm256_set1_ps(0.612788);
                        const int kernelCol=1;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.601036);
                        const int kernelCol=2;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.416437);
                        const int kernelCol=2;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                }
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=11;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=12;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=13;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=14;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
                    {__m256 factor = _mm256_set1_ps(-0.645686);
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.585144);
                        const int kernelCol=0;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.793905);
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.42832);
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.555653);
                        const int kernelCol=0;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.44683);
                        const int kernelCol=1;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.444221);
                        const int kernelCol=2;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                }
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=15;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=16;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
                    {__m256 factor = _mm256_set1_ps(-0.42673);
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.842605);
                        const int kernelCol=2;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.767503);
                        const int kernelCol=3;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.527516);
                        const int kernelCol=0;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.403925);
                        const int kernelCol=1;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.384715);
                        const int kernelCol=2;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.707691);
                        const int kernelCol=3;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.465529);
                        const int kernelCol=4;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.412613);
                        const int kernelCol=0;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.903525);
                        const int kernelCol=1;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.495898);
                        const int kernelCol=2;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.426623);
                        const int kernelCol=1;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.795484);
                        const int kernelCol=2;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.499817);
                        const int kernelCol=3;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                }
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=17;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=18;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
                    {__m256 factor = _mm256_set1_ps(0.406751);
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                }
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
    {
        const int outputChannelIdx=19;
        const int res_off = outputPitchX * resSizeY * outputChannelIdx;
        for (int dim = 0; dim < resSizeX / 8; dim++) {
            const int shift = dim << 3;
            for (int y = 0; y < resSizeY; y++) {
                __m256 out = _mm256_setzero_ps();
                {
                    const int inputChannelIdx = 0;
                    const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
                    {__m256 factor = _mm256_set1_ps(-0.686802);
                        const int kernelCol=2;
                        const int kernelRow=0;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.517685);
                        const int kernelCol=1;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.53314);
                        const int kernelCol=3;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.571746);
                        const int kernelCol=4;
                        const int kernelRow=1;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.609644);
                        const int kernelCol=2;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.921052);
                        const int kernelCol=3;
                        const int kernelRow=2;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.551618);
                        const int kernelCol=1;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(0.44885);
                        const int kernelCol=2;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.55193);
                        const int kernelCol=4;
                        const int kernelRow=3;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                    {__m256 factor = _mm256_set1_ps(-0.389678);
                        const int kernelCol=4;
                        const int kernelRow=4;
                        const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
                        __m256 in = _mm256_loadu_ps(input + inOffset);
                        __m256 multiplied = _mm256_mul_ps(in, factor);
                        out = _mm256_add_ps(multiplied, out);}
                }
                _mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
            }
        }
    }
}



#endif //CAFFE_CODEGEN_TRAD_H
