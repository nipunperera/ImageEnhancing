//-------------------------------DOCUMENTATION--------------------------------------------
//	13/03/2017 - Nipun - Opening an image within project folder and displaying
//					   - Defining separate functions for reading and displaying the image


// Include header files
#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

// Image read function
int readImage(Mat *mainImage)
{
	string imageName("Images\\flower.jpg");
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
	waitKey(0);											// Wait for a keystroke in the window
	return 0;
}

// Calculate white balanced image
int whiteBalance(Mat *mainImage)
{
	Mat resolvedImage[3];				// Matrix for splitting BGR channels
	split(*mainImage, resolvedImage);	// Splitting the BGR channels
	displayImage(&resolvedImage[0], "Blue Channel");
	return 0;
}

// Main function
int main(int argc, char** argv)
{
	Mat mainImage;								// Declaring the variable to store the image
	readImage(&mainImage);						// Function call to read the image
	displayImage(&mainImage, "Original Image");
	whiteBalance(&mainImage);
	return 0;
}