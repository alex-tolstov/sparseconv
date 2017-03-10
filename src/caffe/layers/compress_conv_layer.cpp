#include <vector>
#include <fstream>
#include "caffe/filler.hpp"
#include "caffe/layer.hpp"
#include "caffe/util/io.hpp"
#include "caffe/util/im2col.hpp"
#include "caffe/util/math_functions.hpp"
#include "caffe/util/benchmark.hpp"
#include "caffe/vision_layers.hpp"
#include "caffe/util/csr.hpp"


#include <cmath>
#include "caffe/util/codegen.h"

namespace caffe {

template <typename Dtype>
void CConvolutionLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
		
  BaseConvolutionLayer <Dtype>::LayerSetUp(bottom, top); 
  
  this->calculated = false;
  /************ For dynamic network surgery ***************/
	CConvolutionParameter cconv_param = this->layer_param_.cconvolution_param();
	
  if(this->blobs_.size()==2 && (this->bias_term_)){
    this->blobs_.resize(4);
    // Intialize and fill the weightmask & biasmask
    this->blobs_[2].reset(new Blob<Dtype>(this->blobs_[0]->shape()));
    shared_ptr<Filler<Dtype> > weight_mask_filler(GetFiller<Dtype>(
        cconv_param.weight_mask_filler()));
    weight_mask_filler->Fill(this->blobs_[2].get());
    this->blobs_[3].reset(new Blob<Dtype>(this->blobs_[1]->shape()));
    shared_ptr<Filler<Dtype> > bias_mask_filler(GetFiller<Dtype>(
        cconv_param.bias_mask_filler()));
    bias_mask_filler->Fill(this->blobs_[3].get());    
  }  
  else if(this->blobs_.size()==1 && (!this->bias_term_)){
    this->blobs_.resize(2);	  
    // Intialize and fill the weightmask
    this->blobs_[1].reset(new Blob<Dtype>(this->blobs_[0]->shape()));
    shared_ptr<Filler<Dtype> > bias_mask_filler(GetFiller<Dtype>(
        cconv_param.bias_mask_filler()));
    bias_mask_filler->Fill(this->blobs_[1].get());      
  }  
	
  // Intializing the tmp tensor
  this->weight_tmp_.Reshape(this->blobs_[0]->shape());
  this->bias_tmp_.Reshape(this->blobs_[1]->shape());  
	
	// Intialize the hyper-parameters
  this->std = 0;this->mu = 0;   
  this->gamma = cconv_param.gamma(); 
  this->power = cconv_param.power();
  this->crate = cconv_param.c_rate();  
  this->iter_stop_ = cconv_param.iter_stop();
  /********************************************************/
}

template <typename Dtype>
void CConvolutionLayer<Dtype>::compute_output_shape() {
  this->height_out_ = (this->height_ + 2 * this->pad_h_ - this->kernel_h_)
      / this->stride_h_ + 1;
  this->width_out_ = (this->width_ + 2 * this->pad_w_ - this->kernel_w_)
      / this->stride_w_ + 1;
  LOG(INFO)<< "Out size = (h: " << this->height_out_ << ", w:"<< this->width_out_ << ")";
}

template <typename Dtype>
void CConvolutionLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {  
      
  const Dtype* weight = this->blobs_[0]->mutable_cpu_data();    
  Dtype* weightMask = this->blobs_[2]->mutable_cpu_data(); 
  Dtype* weightTmp = this->weight_tmp_.mutable_cpu_data(); 
  const Dtype* bias = NULL;
  Dtype* biasMask = NULL;  
  Dtype* biasTmp = NULL;
  if (this->bias_term_) {
    bias = this->blobs_[1]->mutable_cpu_data(); 
    biasMask = this->blobs_[3]->mutable_cpu_data();
    biasTmp = this->bias_tmp_.mutable_cpu_data();
  }

  if (this->phase_ == TRAIN){
		// Calculate the mean and standard deviation of learnable parameters 
    if (this->std==0 && this->iter_==0){      
			unsigned int ncount = 0;
			unsigned int maskFaults = 0;
			for (unsigned int k = 0;k < this->blobs_[0]->count(); ++k) {
				this->mu  += fabs(weightMask[k]*weight[k]);       
				this->std += weightMask[k]*weight[k]*weight[k];
				if (weightMask[k]*weight[k]!=0) ncount++;
				if (weightMask[k] == 0.0) maskFaults++;
			}
			if (this->bias_term_) {
				for (unsigned int k = 0;k < this->blobs_[1]->count(); ++k) {
					this->mu  += fabs(biasMask[k]*bias[k]);
					this->std += biasMask[k]*bias[k]*bias[k];
					if (biasMask[k]*bias[k]!=0) ncount++;
				}       
			}
			this->mu /= ncount; this->std -= ncount*mu*mu; 
			this->std /= ncount; this->std = sqrt(std);
			LOG(INFO)<<mu<<"  "<<std<<"  "<<ncount<< ", mask faults = " << maskFaults;     
		} 
		
		// Demonstrate the sparsity of compressed convolutional layer
		/********************************************************/
		if(this->iter_%100==0){
			unsigned int ncount = 0;
			unsigned int total = this->blobs_[0]->count();
			unsigned int maskZeroes = 0;
			for (unsigned int k = 0;k < this->blobs_[0]->count(); ++k) {
				if (weightMask[k]*weight[k]!=0) ncount++;
				if (weightMask[k] == 0) {
					maskZeroes++;
				}
			}
			LOG(INFO)<<"total weights = " << total << ", non-zero elements = " << ncount << ", percentage=" << 100 * ncount / total <<  "%, zeroes in mask = " << maskZeroes << "\n";
			if (this->bias_term_) {
				for (unsigned int k = 0;k < this->blobs_[1]->count(); ++k) {
					if (biasMask[k]*bias[k]!=0) ncount++;
				}       
			}
			LOG(INFO)<<ncount<<" non-zeroes" << " \n";
			LOG(INFO)<<"Internal params: gamma= " << this->gamma << ", power=" << this->power << ", mu=" << mu << ", crate="  << crate << ", std=" << std << "\n";
		}	
		/********************************************************/		
		
		// Calculate the weight mask and bias mask with probability
		Dtype r = static_cast<Dtype>(rand())/static_cast<Dtype>(RAND_MAX);
		if (pow(1+(this->gamma)*(this->iter_),-(this->power))>r && (this->iter_)<(this->iter_stop_)) { 	
			
			for (unsigned int k = 0;k < this->blobs_[0]->count(); ++k) {
				if (weightMask[k]==1 && fabs(weight[k])<=0.9*std::max(mu+crate*std,Dtype(0))) 
					weightMask[k] = 0;
				else if (weightMask[k]==0 && fabs(weight[k])>1.1*std::max(mu+crate*std,Dtype(0)))
					weightMask[k] = 1;
			}	
			if (this->bias_term_) {       
				for (unsigned int k = 0;k < this->blobs_[1]->count(); ++k) {
					if (biasMask[k]==1 && fabs(bias[k])<=0.9*std::max(mu+crate*std,Dtype(0))) 
						biasMask[k] = 0;
					else if (biasMask[k]==0 && fabs(bias[k])>1.1*std::max(mu+crate*std,Dtype(0)))
						biasMask[k] = 1;
				}    
			} 
		}
	} 
	int zeroes = 0;
  // Calculate the current (masked) weight and bias
	for (unsigned int k = 0;k < this->blobs_[0]->count(); ++k) {
		weightTmp[k] = weight[k]*weightMask[k];
		if (weightTmp[k] == 0) {
			zeroes++;
		}
	}
	if (this->phase_ != TRAIN) {
		LOG(INFO)<<"zeroes in weight coefficients = " << zeroes << "\n";
	}
	if (this->bias_term_){
		for (unsigned int k = 0;k < this->blobs_[1]->count(); ++k) {
			biasTmp[k] = bias[k]*biasMask[k];
		}
	}
	
  LOG(INFO)<< "batch size = " << this->num_  << " bottom size (like number of images of a different size, 1 by default) = " << bottom.size();
	// Forward calculation with (masked) weight and bias 

  std::vector<Dtype> nonZeroValues;
  std::vector<int> indicesX;
  std::vector<int> indicesChannel;
  std::vector<int> indicesY;
  const int kernel_dim = this->blobs_[0]->count() / this->num_output_;
//  transpose(weightTmp, kernel_dim, this->num_output_);
//  caffe::convertKernelToCompressedChannels(weightTmp, kernel_dim, this->num_output_, this->kernel_h_*this->kernel_w_, nonZeroValues, indicesX, indicesChannel, indicesY);

	caffe::convertKernelToCompressedChannelsSpecial(weightTmp, kernel_dim, this->num_output_, this->kernel_w_, this->kernel_h_, nonZeroValues, indicesX, indicesChannel, indicesY);
//  caffe::convertKernelToCompressed(weightTmp, this->num_output_, kernel_dim, nonZeroValues, indicesX, indicesY);



//  std::string code = caffe::directConvolutionRegistersCodegen(&nonZeroValues[0], &indicesX[0], &indicesChannel[0], this->kernel_h_, this->kernel_w_, this->channels_, this->num_output_);
//  std::stringstream fileName;
//  fileName << "/home/alex/paulsutter/code_" << this->num_output_;
//    LOG(INFO) << "FileName=" << fileName.str();
//  std::ofstream f;
//    f.open(fileName.str().c_str());
//    f << code;
//    f.close();
//


//  transpose(weightTmp, this->num_output_, kernel_dim);



  for (int i = 0; i < bottom.size(); ++i) {
    const Dtype* bottom_data = bottom[i]->cpu_data();
    Dtype* top_data = top[i]->mutable_cpu_data();
//    LOG(INFO) << "top data size = " << top[i]->count();
	
	caffe::PreciseCPUTimer timer;
	timer.Start();
	
    for (int n = 0; n < this->num_; ++n) {
	  // multiplication of all outputs of a previous layer by series of matrices
      // 1. imgToCol
      // 2. weightTmp to sparse representation for every sub-image in input.
      // 3. fill values of every of new sub-images in output by means sparse-dense multiplication(s).

        this->forward_cpu_sparse_conv_ch (
                bottom_data + bottom[i]->offset(n),
                &nonZeroValues[0],
                &indicesX[0],
                &indicesChannel[0],
                &indicesY[0],
                nonZeroValues.size(),
                top_data + top[i]->offset(n));

	//  this->forward_cpu_gemm(bottom_data + bottom[i]->offset(n), weightTmp, top_data + top[i]->offset(n));
	}
    
  	timer.Stop();
	LOG(INFO) << "sparse direct convolution calculus microseconds = " << timer.MicroSeconds();
/*
    timer.Start();
    for (int n = 0; n < this->num_; ++n) {
	  this->forward_cpu_sparse_gemm (
		bottom_data + bottom[i]->offset(n), 
		&nonZeroValues[0], 
		&indicesX[0],
		&indicesY[0],
		nonZeroValues.size(),
		top_data + top[i]->offset(n));
	}
   	timer.Stop();
	LOG(INFO) << "sparse gemm conv calculus microseconds = " << timer.MicroSeconds();

	timer.Start();
	
    for (int n = 0; n < this->num_; ++n) {
	  this->forward_cpu_gemm(bottom_data + bottom[i]->offset(n), weightTmp, top_data + top[i]->offset(n));
	}
	
   	timer.Stop();
	LOG(INFO) << "dense gemm conv calculus microseconds = " << timer.MicroSeconds();
	*/ 
 //   timer.Start();
		
    for (int n = 0; n < this->num_; ++n) {
	   if (this->bias_term_) {
	 	 this->forward_cpu_bias(top_data + top[i]->offset(n), biasTmp);
	   }
    }
  //  timer.Stop();
  //  LOG(INFO) << "bias calculus microseconds = " << timer.MicroSeconds();
  }
}


template <typename Dtype>
void CConvolutionLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
	const Dtype* weightTmp = this->weight_tmp_.cpu_data();  
	const Dtype* weightMask = this->blobs_[2]->cpu_data();
	Dtype* weight_diff = this->blobs_[0]->mutable_cpu_diff();
  for (int i = 0; i < top.size(); ++i) {
    const Dtype* top_diff = top[i]->cpu_diff();    
    // Bias gradient, if necessary.
    if (this->bias_term_ && this->param_propagate_down_[1]) {
			const Dtype* biasMask = this->blobs_[3]->cpu_data();
      Dtype* bias_diff = this->blobs_[1]->mutable_cpu_diff();			
			for (unsigned int k = 0;k < this->blobs_[1]->count(); ++k) {
				bias_diff[k] = bias_diff[k]*biasMask[k];
			}
      for (int n = 0; n < this->num_; ++n) {
        this->backward_cpu_bias(bias_diff, top_diff + top[i]->offset(n));
      }
    }
    if (this->param_propagate_down_[0] || propagate_down[i]) {
			const Dtype* bottom_data = bottom[i]->cpu_data();
			Dtype* bottom_diff = bottom[i]->mutable_cpu_diff();	
			for (unsigned int k = 0;k < this->blobs_[0]->count(); ++k) {
				weight_diff[k] = weight_diff[k]*weightMask[k];
			}
      for (int n = 0; n < this->num_; ++n) {
        // gradient w.r.t. weight. Note that we will accumulate diffs.
        if (this->param_propagate_down_[0]) {
          this->weight_cpu_gemm(bottom_data + bottom[i]->offset(n),
              top_diff + top[i]->offset(n), weight_diff);
        }
        // gradient w.r.t. bottom data, if necessary.
        if (propagate_down[i]) {
          this->backward_cpu_gemm(top_diff + top[i]->offset(n), weightTmp,
              bottom_diff + bottom[i]->offset(n));
        }
      }
    }
  }
}

#ifdef CPU_ONLY
STUB_GPU(CConvolutionLayer);
#endif

INSTANTIATE_CLASS(CConvolutionLayer);

}  // namespace caffe
