#include <stdint.h>
#include <time.h>


#include "caffe/util/benchmark.hpp"
#include "caffe/common.hpp"

namespace caffe {


PreciseCPUTimer::PreciseCPUTimer() {
  this->initted_ = true;
  this->running_ = false;
  this->has_run_at_least_once_ = false;
}

void PreciseCPUTimer::Start() {
  if (!running()) {
	int res = clock_gettime(CLOCK_THREAD_CPUTIME_ID, &this->start_precise_);
	if (res != 0) {
		LOG(WARNING)<< "Timer start has an error: " << res;
	}
    this->running_ = true;
    this->has_run_at_least_once_ = true;
  }
}

void PreciseCPUTimer::Stop() {
  if (running()) {
	int res = clock_gettime(CLOCK_THREAD_CPUTIME_ID, &this->stop_precise_);
	if (res != 0) {
		LOG(WARNING)<< "Timer start has an error: " << res;
	}
    this->running_ = false;
  }
}

float PreciseCPUTimer::MilliSeconds() {
  if (!has_run_at_least_once()) {
    LOG(WARNING) << "Timer has never been run before reading time.";
    return 0;
  }
  if (running()) {
    Stop();
  } 
  double diff = 1000000000L * (this->stop_precise_.tv_sec - this->start_precise_.tv_sec) + this->stop_precise_.tv_nsec - this->start_precise_.tv_nsec;
  this->elapsed_milliseconds_ = (float) (diff / 1000. / 1000.);
  return this->elapsed_milliseconds_;
}

float PreciseCPUTimer::MicroSeconds() {
  if (!has_run_at_least_once()) {
    LOG(WARNING) << "Timer has never been run before reading time.";
    return 0;
  }
  if (running()) {
    Stop();
  }
  double diff = 1000000000L * (this->stop_precise_.tv_sec - this->start_precise_.tv_sec) + this->stop_precise_.tv_nsec - this->start_precise_.tv_nsec;
  double divided = diff / 1000.;
  this->elapsed_microseconds_ = static_cast<float>(divided);
  return this->elapsed_microseconds_;
}

}
