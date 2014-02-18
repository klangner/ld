#include <iostream>
#include <math.h>
#include <cv.h>
#include <highgui.h>
#include "histogram.hpp"
#include "morph.hpp"


using namespace cv;

const uint WIDTH = 320;
const uint HEIGHT = 240;

void assertTrue(bool p, string msg){
	if(!p){
		std::cout << msg << std::endl;
		exit(-1);
	}
}

Mat loadImage(const char* fileName){
	Mat image = imread( fileName, CV_LOAD_IMAGE_GRAYSCALE );
	Mat scaled;
	resize(image, scaled, Size(WIDTH, HEIGHT));
	return scaled;
}

void showImage(const char* title, Mat image){
	namedWindow(title, CV_WINDOW_AUTOSIZE );
	imshow(title, image );
}

Mat findSigns(Mat image){
	Mat binary;
	threshold(image, binary, 100, 255, THRESH_BINARY);
	return binary;
}

void drawCone(Mat& image, uint radius){

	int sampleCount = 2*180;
	// Init matrices for polar to cartesian transformation
	std::vector<float> magnitudes(sampleCount);
	std::vector<float> angles(sampleCount);
	std::vector<float> cols(sampleCount);
	std::vector<float> rows(sampleCount);
	for(float i = 0; i < sampleCount; i++){
		magnitudes[i] = radius;
		angles[i] = i/2;
	}
	polarToCart(magnitudes, angles, cols, rows, true);

	// Draw cone and calculate number of black pixels
	int counter = 0;
	for(int i = 0; i < sampleCount; i++){
		int x = cols[i] + WIDTH/2;
		int y = HEIGHT-rows[i];
		if(image.at<uchar>(y, x) == 0){
			counter ++;
		}
		else{
			image.at<uchar>(y, x) = 125;
		}
	}


	// Find median direction
	counter /= 2;
	for(int i = 0; i < sampleCount; i++){
		int x = cols[i] + WIDTH/2;
		int y = HEIGHT-rows[i];
		if(image.at<uchar>(y, x) == 0){
			counter --;
			if(counter <= 0){
				line(image, Point(WIDTH/2, HEIGHT), Point(x, y), Scalar(125));
				std::cout << "Angle: " << (90-i/2) << " degrees" << std::endl;
				break;
			}
		}
	}
}

int main( int argc, char** argv )
{
	assertTrue(argc == 2, "Usage: ld <image_file>");
	Mat image = loadImage(argv[1]);
	assertTrue(image.data, "Can't load image.");
	MatND hist = histogram1D(image);
	Mat histImage = getHistogramAsImage(hist);
	Mat output = findSigns(image);
	drawCone(output, WIDTH/2);
	showImage("Input", image);
//	showImage("Histogram", histImage);
	showImage("Output", output);

	waitKey(0);
	return 0;
}


