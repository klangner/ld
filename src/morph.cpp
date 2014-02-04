#include "histogram.hpp"

using namespace cv;

// Find edges in the image
Mat gradient(const Mat& image){
	Mat result;
	morphologyEx(image ,result, MORPH_GRADIENT, Mat());

	return result;
}
