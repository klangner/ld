#include "histogram.hpp"

using namespace cv;

// Create 1 dimensional histogram
MatND histogram1D(Mat image){
	int channels[] = {0};
	int histSize[] = {256};
	float sranges[] = { 0, 256 };
	const float* ranges[] = { sranges };
	MatND hist;
	calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges, true, false);
	return hist;
}

// Convert histogram data into image.
Mat getHistogramAsImage(const MatND& hist){
	// Get min and max bin values
	double minVal = 0;
	double maxVal = 0;
	minMaxLoc(hist, &minVal, &maxVal, 0, 0);

	// Canvas for histogram
	Mat canvas(256, 256, CV_8U, Scalar(255));

	// Set highest point to 90% of nbins
	int hpt = static_cast<int>(0.9*256);

	// Draw vertical lines for each bin
	for(int h = 0; h < 256; h++){
		float binValue = hist.at<float>(h);
		int intensity = static_cast<int>(binValue*hpt/maxVal);
		line(canvas, Point(h, 256), Point(h, 256-intensity), Scalar::all(0));
	}

	return canvas;
}
