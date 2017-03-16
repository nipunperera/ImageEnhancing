//-------------------------------DOCUMENTATION--------------------------------------------
//	13/03/2017 - Nipun - Opening an image within project folder and displaying
//					   - Defining separate functions for reading and displaying the image
//					   - White balance functionality was added


// Include header files
#include "stdafx.h"
#include "noiseReduction.h"
/*#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>*/


using namespace cv;
using namespace std;

// Image read function
int readImage(Mat *mainImage)
{
	string imageName("E:\\Sem7\\Machine vision\\opencv_test\\project1\\data\\sd.jpg");
	*mainImage = imread(imageName.c_str(), IMREAD_COLOR);
	return 0;
}

// Display image
int displayImage(Mat *mainImage, string imageDes)
{
	Mat tempImage;
	tempImage = *mainImage;
	if (tempImage.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	namedWindow(imageDes, WINDOW_AUTOSIZE);		// Create a window for display.
	imshow(imageDes, tempImage);                // Show our image inside it.
	waitKey(0);									// Wait for a keystroke in the window
	return 0;
}

// Main function
int main(int argc, char** argv)
{
	Mat inputImage;	
	Mat outputImage;							// Declaring the variable to store the image

	readImage(&inputImage);						// Function call to read the image
	displayImage(&inputImage, "Original Image");

	lumaNoiseFiltering(&inputImage, &outputImage);

	namedWindow("Input", WINDOW_AUTOSIZE);
	imshow("Input", inputImage);

	namedWindow("Output Image", WINDOW_AUTOSIZE);
	imshow("Output Image", outputImage);
	waitKey(0);

	return 0;
}