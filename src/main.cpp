#include <iostream>
#include <cv.h>
#include <highgui.h>

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

void showImage(Mat image){
	namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
	imshow( "Display Image", image );
	waitKey(0);
}


int main( int argc, char** argv )
{
	assertTrue(argc == 2, "Usage: ld <image_file>");
	Mat image = loadImage(argv[1]);
	assertTrue(image.data, "Can't load image.");
	showImage(image);

	return 0;
}


