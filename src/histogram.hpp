#ifndef __HISTOGRAM_HPP__
#define __HISTOGRAM_HPP__

#include <cv.h>

cv::MatND histogram1D(cv::Mat image);

cv::Mat getHistogramAsImage(const cv::MatND& hist);

#endif // __HISTOGRAM_HPP__
