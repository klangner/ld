#include <iostream>
#include <cv.h>
#include <highgui.h>
#include "histogram.hpp"

using namespace std;
using namespace cv;

void assertTrue(bool p, string msg){
	if(!p){
		cout << msg << endl;
		exit(-1);
	}
}

Mat loadImage(const char* fileName){
	Mat image = imread( fileName, CV_LOAD_IMAGE_GRAYSCALE );
	Mat scaled(800, 600, CV_8UC1);
	resize(image, scaled, Size(800, 600));
	return scaled;
}

void showImage(const char* title, Mat image){
	namedWindow(title, CV_WINDOW_AUTOSIZE );
	imshow(title, image );
}

Mat processImage(Mat image){
	Mat binary(800, 600, CV_8UC1);
	threshold(image, binary, 100, 255, THRESH_BINARY);
	return binary;
}

int main( int argc, char** argv )
{
	assertTrue(argc == 2, "Usage: ld <image_file>");
	Mat image = loadImage(argv[1]);
	assertTrue(image.data, "Can't load image.");
	MatND hist = histogram1D(image);
	Mat histImage = getHistogramAsImage(hist);
	Mat output = processImage(image);
//	showImage("Input", image);
	showImage("Output", output);

	waitKey(0);
	return 0;
}


