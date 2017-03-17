//
// Created by alex on 11.03.17.
//

#ifndef CAFFE_CODEGEN_TRAD_50_H
#define CAFFE_CODEGEN_TRAD_50_H

template<typename Dtype>
void runOutputReusage50(const Dtype *input, const int imgSizeX, const int imgSizeY, Dtype *output, const int outputPitchX, const int resSizeX, const int resSizeY);


template<> void runOutputReusage50<double>(const double *input, const int imgSizeX, const int imgSizeY, double *output, const int outputPitchX, const int resSizeX, const int resSizeY) {

}

template<> void runOutputReusage50<float>(const float *input, const int imgSizeX, const int imgSizeY, float *output, const int outputPitchX, const int resSizeX, const int resSizeY) {
{
const int outputChannelIdx=0;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.087093);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.117631);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0901724);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0844744);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0971134);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0962267);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.115854);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0800291);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.194571);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.140035);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.195615);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.107228);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.149);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0743691);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.090619);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.227651);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.137566);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0949185);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109253);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0880255);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.121079);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0723767);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0734622);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.085332);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0724659);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0856205);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0998973);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.180652);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105076);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0965637);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.119319);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.224018);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0861403);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0797489);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0873525);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0939081);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.133764);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0800868);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.126302);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0672784);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.162675);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0976002);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.152247);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.113335);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0766736);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0758972);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.100397);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0778442);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0977676);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.2134);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.334498);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0898559);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.155049);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.226526);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119183);
const int kernelCol=0;
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
const int outputChannelIdx=1;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.075621);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0832304);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.10521);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0880511);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0800956);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.131415);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105543);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.120462);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0835156);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0892466);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0888557);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.105145);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0850468);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.168989);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.06649);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.14716);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105592);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100154);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.112351);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0891006);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.114672);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139077);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0759203);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.160606);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119015);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0896665);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.102302);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.095138);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.113316);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.115657);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.159014);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.103061);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139031);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.135486);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0907559);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.119445);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0834563);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.219572);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.174998);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.168421);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.158671);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.262878);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.193542);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106634);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.30445);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.202558);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.159915);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0888196);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0865489);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0837638);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.153743);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.126899);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.164978);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0665279);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0935718);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.137286);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125693);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0748015);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0894365);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0921936);
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
const int outputChannelIdx=2;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0847939);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0892034);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0890025);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.239175);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109093);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119172);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.1235);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.114087);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0959884);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0813905);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0951169);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.150053);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0942986);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.104137);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.103587);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0761365);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.110909);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0880755);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0870259);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0994556);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100761);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101587);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.10429);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0789495);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.139261);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.175375);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111048);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0943601);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.150504);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0863141);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.154629);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0920056);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0745018);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.097653);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.127104);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.132459);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133395);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130881);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130166);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.191673);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0889678);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.155534);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.175916);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.127526);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.11028);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0874695);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.160347);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0996356);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.141814);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.104548);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0999871);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0979483);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101713);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.119287);
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
const int outputChannelIdx=3;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0779188);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.106685);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0772077);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0870592);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0787443);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0825109);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0990487);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.079468);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0988611);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0753826);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.150629);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119387);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0866931);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.127521);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.180087);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0725039);
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
const int outputChannelIdx=4;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.103327);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.144678);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.086106);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0850608);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100583);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0682415);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.140381);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111977);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.123662);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.123399);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.136723);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.165432);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.148626);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.220888);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0948303);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.131552);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0937091);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139237);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.125272);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0772846);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0887833);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.16906);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0925404);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.106773);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0811346);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0926005);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.091755);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.121342);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0867957);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.105253);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108158);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0953289);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.115899);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0821086);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0843575);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0832002);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125342);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.094491);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0840623);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0867825);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.169812);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.14739);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100172);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.136565);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.297372);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.159823);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.167866);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0979196);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.088395);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0905967);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.122748);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.105756);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0877351);
const int kernelCol=1;
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
const int outputChannelIdx=5;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.117745);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0965142);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0906439);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.133699);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0870465);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.117471);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106967);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.116553);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0881769);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.16088);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0960158);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0930259);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0997052);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0653143);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0916231);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.131305);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0784685);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.094165);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.095016);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0754893);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0875551);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.243027);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119188);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0910387);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.174865);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.166578);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.134981);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0989096);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0789238);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0860155);
const int kernelCol=1;
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
const int outputChannelIdx=6;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0867528);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0860998);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0985397);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.098704);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.116725);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0948687);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0999331);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.21514);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.135009);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0636052);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109835);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.077166);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0898488);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.145617);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.127117);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0914925);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.14137);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.185791);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119352);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.245386);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0842055);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0815265);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0850104);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0847846);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.107178);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0729055);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0853564);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.10326);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0787723);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0748462);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110886);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0967489);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.126012);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.139389);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0866825);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0801109);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.105555);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.216026);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.186543);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.162477);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0804904);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0678279);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0932505);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.234431);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.178317);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.173971);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100046);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0956385);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130451);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0805137);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111173);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0861174);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0966374);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.139703);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.105149);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.143814);
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
const int outputChannelIdx=7;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0920848);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0825418);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0802229);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0943389);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.100683);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0956136);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.104759);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0809228);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110809);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0838708);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110222);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0693809);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106475);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.112372);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.123454);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.152359);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130408);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0871141);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.112294);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.180812);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110876);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0923056);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.112757);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.115819);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0996636);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.114518);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111188);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.135302);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0895692);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.169902);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.262153);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.277003);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.219125);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0935541);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.127959);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.131161);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0766062);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.113645);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.137016);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.132127);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.103474);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0740664);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.135113);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.129994);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.147261);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.113474);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.10141);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0822431);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.128936);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.124371);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.138334);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0739948);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0997861);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0971029);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.160717);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.140756);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.190819);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0726729);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.094151);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0681606);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.248424);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.130356);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.134539);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.113988);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105159);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.156299);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.170236);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.104257);
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
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.113563);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.113702);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0977948);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111954);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.126434);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0901937);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0910278);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0997539);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.10695);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0799678);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.172167);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0989068);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.101655);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.141301);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109889);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0919135);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.176716);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139729);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0763849);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.105553);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.18001);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0827305);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.138587);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.356874);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.35993);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.310296);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0709881);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.151349);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.075141);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.097998);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0912165);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.078899);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125361);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.145669);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.138202);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0807292);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0956773);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.141682);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.191376);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.210964);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0666355);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0938235);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.129207);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.145545);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.088447);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.10579);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.158313);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.170085);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0892906);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.153882);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.129603);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111998);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.150448);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.121043);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.140741);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.118997);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105802);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.124695);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0762789);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0773116);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0851332);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0777527);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.113815);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0820231);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.11945);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.121194);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.17942);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.236079);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0940043);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0943094);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.13409);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.213762);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.19968);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.137524);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.182399);
const int kernelCol=1;
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
const int outputChannelIdx=9;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0924206);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0870904);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110519);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0712501);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0830293);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0765312);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.125159);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.129786);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.110745);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0753979);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.129067);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.114103);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.110532);
const int kernelCol=3;
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
const int outputChannelIdx=10;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0772874);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0928444);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0782257);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0835263);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0891315);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0830908);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130365);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11012);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0849913);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0879567);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.123001);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125392);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0807893);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.136614);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.1997);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.108806);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.13358);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0847588);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0759018);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.128414);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0565811);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0892281);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0974511);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.109825);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.116184);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.095385);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11509);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0945198);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.140686);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125855);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.121914);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0810037);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0809517);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.123137);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.168447);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.074463);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0773545);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0858599);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.110076);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11353);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0928387);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.136689);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.1002);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.112164);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0819091);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.133124);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0871974);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0775762);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11998);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0881525);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.117487);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.114762);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0981107);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.135616);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.143201);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.139772);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.107109);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.158933);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.135685);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105851);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0920218);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.104469);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101842);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.135564);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0840334);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0716224);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.200959);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.10156);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.188892);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.168423);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0937879);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.107963);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0872514);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0934455);
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
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0850881);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0977313);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.134867);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0838312);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0798863);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11975);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0992802);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0820744);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.124808);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.100772);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0987558);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0766985);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.122897);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0849589);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.106631);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.11396);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.20054);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108648);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.140743);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0922559);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.102575);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.118539);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.12278);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.123597);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0838313);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0817756);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0870479);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106888);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100517);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.152653);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0956809);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.104733);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.131783);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.13472);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.07253);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.074072);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.109205);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.133337);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.132198);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0973514);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.154984);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.18528);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.123638);
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
const int outputChannelIdx=12;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0942564);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0887085);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0775959);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0852994);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0844413);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111432);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.125117);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0860642);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0981082);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.098937);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100565);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.169396);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.117538);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0889671);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0783278);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.125797);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.119037);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.21011);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.172418);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.087846);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.202944);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0980844);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0944143);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0853357);
const int kernelCol=2;
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
const int outputChannelIdx=13;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0859894);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0943317);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0738837);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.114086);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0941739);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0693603);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.114575);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0919943);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.126646);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0906981);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0958105);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0809737);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.129521);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.257652);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.246413);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0858276);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.140427);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.171159);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.148357);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.087771);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.087448);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109078);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0883508);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0937541);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0982258);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.114657);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.22216);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.111863);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.139206);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0813903);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.187479);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.177266);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0895943);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0781304);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.116475);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.128777);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.1398);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.121787);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0901454);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.14254);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0900394);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.103022);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0858841);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0867624);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.122437);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105299);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110633);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0899813);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.140135);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.242824);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.111876);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.160348);
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
const int outputChannelIdx=14;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
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
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0859981);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.080552);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0838375);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125912);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106934);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.11394);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0897398);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0839137);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0841658);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0792969);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0814871);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.108624);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0700198);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.172305);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.232536);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0967917);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0879883);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0878036);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0991426);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.115818);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.217336);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.194671);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.205593);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0678035);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.102272);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.136562);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0830561);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0809259);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.124877);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.169687);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0999905);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.126874);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.160292);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0849051);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0988056);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.152604);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.091227);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.10869);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0935476);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100108);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0781687);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.283413);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.104927);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.175286);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.215725);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.15741);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0783575);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.104999);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.121944);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0870812);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0764424);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.10872);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.140138);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.14808);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.119492);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0892419);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.142906);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.169279);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.174202);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.14361);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.208097);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0807371);
const int kernelCol=3;
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
const int outputChannelIdx=16;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
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
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0841785);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0856641);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0774846);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109319);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0845919);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0853525);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0732171);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.108841);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.115373);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0764752);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0837843);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0858369);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.10275);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.117871);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119411);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.165222);
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
const int outputChannelIdx=18;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0911551);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0704895);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.134789);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0851036);
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
const int outputChannelIdx=19;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=20;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0734521);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0811747);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0808819);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0854197);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0715709);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.083013);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.096428);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.179409);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.211004);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0865669);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0876085);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.1047);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0867808);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0738434);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0978356);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.092319);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.090928);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.077949);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0897179);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0723755);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.10623);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.096104);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139619);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0766427);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0873597);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.156365);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0882244);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.143804);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0952379);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0890759);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109929);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0947915);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0812292);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109745);
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
const int outputChannelIdx=21;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0872684);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.11166);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0917594);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0801733);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0984575);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0946015);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.095072);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0904121);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0829394);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.148302);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.116981);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0937416);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.122954);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100708);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0977974);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.106448);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0954797);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.102005);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.10531);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0916075);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0837641);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0883965);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.116709);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0906965);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0941381);
const int kernelCol=1;
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
const int outputChannelIdx=22;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0916827);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0932864);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0946767);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0912518);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11964);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0850904);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0971618);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105252);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0912862);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0792791);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0813143);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.102954);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.118944);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.159092);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.147891);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.178421);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.195142);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.112747);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.183237);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.232441);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0851863);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0895101);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.148623);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0946903);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.114362);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.11077);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0952768);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0823222);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0745257);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0705777);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.112314);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0849613);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.113942);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.163378);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.126676);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.104027);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.102572);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.113124);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0856795);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133703);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.114754);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.212885);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.231971);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.102225);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.226046);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0854446);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.10619);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0989978);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.106838);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0845336);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.231092);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108821);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0801922);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.21521);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0888544);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0896244);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.134522);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.215915);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.12403);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.189727);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0772091);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.105518);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0917484);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.120644);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0685671);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125792);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.192076);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0794171);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100948);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0747423);
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
const int outputChannelIdx=23;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0946372);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.127464);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0955228);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0776987);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111044);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.158058);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.137975);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0996163);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0978467);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.072695);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0799789);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.121581);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.206644);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0921712);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.097015);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.149103);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.145559);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.123457);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.179445);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0925671);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.126647);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0979208);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.127524);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.14458);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.115316);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.127303);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.107814);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0920427);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.256155);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.325046);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.266819);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.153357);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.138573);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.212707);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.187344);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.215664);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.131279);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11118);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0968534);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.13415);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.141818);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.11274);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.145529);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.140268);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0866571);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11973);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0786333);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.069856);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.107011);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0647216);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.12993);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.115947);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.183608);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.252232);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.126535);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.166188);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.220566);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.125648);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0986921);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.17983);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.169633);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0856632);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.124071);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0902519);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.135472);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0950887);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.147784);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0946155);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.148486);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.107027);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.150302);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139187);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119715);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.164963);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0989683);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0768112);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0778631);
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
const int outputChannelIdx=24;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=25;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=26;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.080336);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0955836);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.103614);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0782405);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.11198);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11009);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.223571);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.148464);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.216515);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.14185);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.204545);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.1028);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.174419);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.169641);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.103261);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.07685);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.102547);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0939916);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.102726);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100867);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0939716);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0812376);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.125599);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.135557);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.09935);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0847388);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0771583);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.132453);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0946927);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0967645);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0831232);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0913018);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.161993);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0812854);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.133053);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.181828);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.167901);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125412);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.150765);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.150504);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.119785);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0701463);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.069346);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0960264);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0821804);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0919132);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.134725);
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
const int outputChannelIdx=27;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=28;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=29;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0968331);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101878);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.09717);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.132328);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0936032);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0706842);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0758442);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0780516);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0769701);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0913823);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.107401);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0964631);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0798834);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.122581);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.148562);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.105378);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0999568);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119391);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133549);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.080145);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.106692);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0775744);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.103557);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.132417);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.116696);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0863773);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0896176);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0820649);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.125285);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.145875);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.100818);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.13155);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0913502);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.094416);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.114447);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.119537);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.088575);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106261);
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
const int outputChannelIdx=30;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0828872);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=31;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0750437);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0916723);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0793583);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0834551);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0914921);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0766358);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.12678);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101804);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.079074);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0869813);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.131843);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.143418);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0856216);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.150606);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0920879);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0693259);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0766829);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.128629);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.185714);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.128273);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0914367);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.12752);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.128401);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.129786);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.166121);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108649);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.077885);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0990139);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.186986);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.312188);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.182496);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.127797);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0911706);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.088069);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0848819);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.145548);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.137434);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0886899);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0850504);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.121592);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.114815);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.109623);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0905932);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.148137);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.163848);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.167518);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0891263);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.088284);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0852974);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139294);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.164787);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.116785);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.214219);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.194377);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0873947);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.118974);
const int kernelCol=1;
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
const int outputChannelIdx=32;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0820794);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0871057);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0889692);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.1186);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0929606);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.101103);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0773035);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.105548);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101109);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100785);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.136863);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.07012);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.088928);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0731273);
const int kernelCol=0;
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
const int outputChannelIdx=33;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.101052);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0943252);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0942927);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0842644);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0824009);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0991386);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0864374);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.154735);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0908046);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.097201);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0921335);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133276);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0974601);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.113778);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.160762);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.168401);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0845179);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.161394);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.134754);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0862001);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.14757);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.158928);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.22396);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.122765);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.156901);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.131235);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.104392);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0961268);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105877);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.1298);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.082377);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0816141);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.144114);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.110744);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0914276);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0998793);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0718741);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.11142);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.135328);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0974718);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0774605);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.185869);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0595804);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.123529);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.107155);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0948154);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.132627);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.153454);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0808253);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.105036);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.12481);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0866249);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.137602);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0937416);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.216158);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.15085);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0985612);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0851867);
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
const int outputChannelIdx=34;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=35;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0840728);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0847088);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0963021);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0881292);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0759686);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=36;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.119992);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0689726);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125824);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0838233);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.087085);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.1899);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0723302);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0905979);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.198958);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.134495);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0744225);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0824013);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.162512);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.128902);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.152182);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.201271);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0937719);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.106427);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0849666);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.177719);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109383);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0787971);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.138205);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.119987);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.119421);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0984712);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0838668);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.148566);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0972653);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.185069);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.143179);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0816305);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0803857);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.364391);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.178726);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.111025);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0878425);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0999972);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0820483);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0870558);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.135091);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0997451);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.100917);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.100728);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.194389);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0951144);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.102942);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.232866);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.224606);
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
const int outputChannelIdx=37;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0810473);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0802014);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106395);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0802614);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0839845);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.104216);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0841906);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0689672);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0950813);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0923448);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0781113);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.155709);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.122298);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0728623);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0698443);
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
const int outputChannelIdx=38;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.09634);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0823479);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0803782);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0911998);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0921548);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.108047);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110217);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.11757);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0880633);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.127103);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.152167);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0813925);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0971821);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0957791);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.128453);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.107625);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.10467);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.135038);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.17716);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.227619);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130118);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.164056);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.142446);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.149346);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.199906);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130404);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.156732);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.080405);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.09196);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0867444);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0896564);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108451);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.116282);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0811998);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.140017);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.14131);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11594);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.110184);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0929791);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0903313);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.103481);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.114084);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.125767);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.112659);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130324);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0881564);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100974);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0754732);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.131787);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.102301);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0833798);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0761482);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.17787);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.153464);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0922177);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0964281);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0973812);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.149621);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139155);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.14353);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.157951);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0797211);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.174959);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.134758);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.24499);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.216951);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.204697);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.124351);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0791336);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.167252);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0926623);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0816357);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0685144);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.152884);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.18962);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.210826);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.102618);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.112688);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.105442);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.150986);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0793592);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.195243);
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
const int outputChannelIdx=39;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0876805);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.154174);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110116);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.136571);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.129899);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0954491);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0960169);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.161577);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.162036);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.174856);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0839849);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.07892);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.14224);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.134894);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.132942);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0727548);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.116671);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0850042);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0718048);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0809817);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0936765);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0855218);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.123686);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.145576);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.167353);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.209253);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0743332);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.102965);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0786823);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.147299);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.132949);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.121554);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.12666);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.17669);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.126052);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0785878);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0840104);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.119515);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.102943);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.105216);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0837196);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0837249);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0758198);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0813446);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0761812);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.129326);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0758425);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0954928);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.129745);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.151733);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0897873);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0840546);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0953047);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.16321);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.218538);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0939155);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0811996);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.125146);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.17206);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.12655);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.10742);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0948069);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0860016);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108676);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.213143);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0842481);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.128308);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.113483);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0749723);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.204744);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.253469);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.145047);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.193197);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.153564);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.142653);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0759);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0802262);
const int kernelCol=3;
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
const int outputChannelIdx=40;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0778401);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.11665);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0790568);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0839403);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.136975);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0971091);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0880177);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.165463);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101382);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0881674);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0610339);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0920239);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0877703);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.131216);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.158325);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.119127);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.158715);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11712);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.118502);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.132478);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.104);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0824302);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0998634);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.121608);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.111402);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0896544);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.169049);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.111182);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.11506);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.085493);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.162904);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.151636);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0807656);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0811087);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0856028);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.197257);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.162907);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.138342);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.149424);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.13779);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.304863);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.317362);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0935271);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.204373);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.191198);
const int kernelCol=1;
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
const int outputChannelIdx=41;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0735456);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0968426);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.154013);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0791771);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106614);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.123086);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0748044);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0840645);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.141512);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130238);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.120686);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.098034);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.167541);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.154627);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11166);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.127394);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0799964);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0980411);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100646);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.125784);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0788354);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0772855);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.104081);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.132097);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0863118);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0780802);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.14126);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.121532);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0921855);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0976462);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133835);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.113029);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.121081);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.12232);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108035);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0906751);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0813395);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0869501);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101675);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0893105);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0913248);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.107194);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.130675);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.224909);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0922474);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0916223);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.133799);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.149342);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.18334);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.160771);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.221479);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.123574);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0865142);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.149841);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.260016);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.17945);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.226592);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.158294);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.222479);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.104659);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.229722);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0960442);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.124866);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0767457);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.091684);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.131513);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0955816);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0956286);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.138622);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.115112);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0916137);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0785096);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0977287);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.107953);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.112542);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0935496);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0988602);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.120793);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111532);
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
const int outputChannelIdx=42;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0826938);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0768708);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0881949);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.107853);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0780097);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0763575);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0868555);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0948735);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0827098);
const int kernelCol=2;
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
const int outputChannelIdx=43;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0820729);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0770632);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0857745);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111522);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.105569);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.116504);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0855521);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.12642);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.117725);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.115708);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0863128);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.084944);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109648);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.12708);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0998908);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0860054);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11439);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.149036);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.168059);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.10068);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.252053);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.274384);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0876583);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100309);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0931946);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.112895);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111663);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.127713);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.076568);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.081591);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0831282);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.11001);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.135641);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0891685);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.123419);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111491);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.15918);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.126709);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.082266);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.109814);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0915182);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0854833);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0963669);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.137525);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.09946);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0840698);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.095555);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.12668);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.184479);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0922917);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101222);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.102054);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.114796);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0954115);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.088244);
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
const int outputChannelIdx=44;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=45;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0824089);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.092892);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.114549);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.112424);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.108185);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0908759);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0928819);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.150353);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.140267);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0915768);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0980969);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.092103);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.249702);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.172995);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0867421);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.10763);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.131947);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.166557);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.124481);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133866);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.175352);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110899);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0968771);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0737255);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.115174);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.168574);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.201296);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.16706);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.104381);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0912727);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108152);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.141876);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.204972);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.113208);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.178553);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.184247);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.097841);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.183894);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.239218);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.232037);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.106428);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0722855);
const int kernelCol=0;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0808371);
const int kernelCol=1;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.14243);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.101321);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.117839);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0850733);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0997931);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133253);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0794506);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.087024);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.084827);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.103708);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0829338);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.124214);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.072993);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119706);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.213392);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.141211);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.237191);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.209832);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0984445);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0919312);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.159516);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.157889);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0923368);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133933);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.087415);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0812743);
const int kernelCol=0;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.135221);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.109259);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.101732);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0817193);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0940479);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.186501);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.079584);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0902116);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.116944);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0713124);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0908776);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.110768);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.130481);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0768607);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0945728);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0875522);
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
const int outputChannelIdx=46;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0898676);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100457);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0805529);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=47;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0752398);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0782208);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=48;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);
}
}
}
{
const int outputChannelIdx=49;
const int res_off = outputPitchX * resSizeY * outputChannelIdx;
for (int dim = 0; dim < resSizeX / 8; dim++) {
const int shift = dim << 3;
for (int y = 0; y < resSizeY; y++) {
__m256 out = _mm256_setzero_ps();
{
const int inputChannelIdx = 0;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 1;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0816678);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0849964);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 2;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0792151);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0775923);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0697536);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106822);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.13);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0959272);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 3;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 4;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 5;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 6;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 7;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0729069);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.137336);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.155092);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.117518);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.145866);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139941);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.100433);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.1055);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 8;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 9;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.114087);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.106146);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.10754);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.124775);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0994088);
const int kernelCol=0;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.234804);
const int kernelCol=1;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.261913);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.123127);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 10;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0958504);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.122352);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.091286);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108537);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.118337);
const int kernelCol=1;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0973859);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 11;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 12;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 13;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 14;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(-0.0918572);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.106086);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.108877);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.123434);
const int kernelCol=3;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.105071);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.106594);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.155934);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0824559);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0851788);
const int kernelCol=4;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 15;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
}
{
const int inputChannelIdx = 16;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.111551);
const int kernelCol=0;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.123268);
const int kernelCol=1;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.111102);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.128672);
const int kernelCol=3;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0962704);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.099889);
const int kernelCol=2;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.192832);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.185826);
const int kernelCol=0;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0997821);
const int kernelCol=1;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.146488);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.346038);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.0912396);
const int kernelCol=4;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.179292);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.211999);
const int kernelCol=4;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0874721);
const int kernelCol=2;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.238863);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 17;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0719837);
const int kernelCol=2;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 18;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.0827547);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
}
{
const int inputChannelIdx = 19;
const int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;
{__m256 factor = _mm256_set1_ps(0.185562);
const int kernelCol=2;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.110692);
const int kernelCol=4;
const int kernelRow=0;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133632);
const int kernelCol=4;
const int kernelRow=1;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(0.119658);
const int kernelCol=3;
const int kernelRow=2;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.133227);
const int kernelCol=2;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.121068);
const int kernelCol=3;
const int kernelRow=3;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.0792873);
const int kernelCol=3;
const int kernelRow=4;
const int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;
__m256 in = _mm256_loadu_ps(input + inOffset);
__m256 multiplied = _mm256_mul_ps(in, factor);
out = _mm256_add_ps(multiplied, out);}
{__m256 factor = _mm256_set1_ps(-0.139038);
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


#endif //CAFFE_CODEGEN_TRAD_50_H
