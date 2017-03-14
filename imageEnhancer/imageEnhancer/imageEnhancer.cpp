//14/03/2017

// Include header files
#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>			// Added for Exposure, Contrast Adjustment

using namespace cv;
using namespace std;

// Image read function
int readImage(Mat *mainImage)
{
	string imageName("Images\\flower.jpg");
	*mainImage = imread(imageName.c_str(), IMREAD_COLOR);		// Load Image
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

//----------------Exposure and Contrast Adjustment---------------------//
// Takes an input image as source image
int exposureContrast(Mat *mainImage)
{
	Mat tempImage;
	tempImage = *mainImage;

	// Check image existance
	if (tempImage.empty())                  
	{
		cout << "Could not open the image" << endl;
		return -1;
	}

	double alpha;		//Contrast control - Gain parameter
	int beta;			//Brightness/Exposure control - Bias parameter

	//Initialize zero matrix to store adjusted image - same size and type as original
	Mat newImage = Mat::zeros(tempImage.size(), tempImage.type());	

	// Initialize Values from user input
	std::cout << " Basic Linear Transform " << std::endl;
	std::cout << "Enter the alpha value (1-3): "; std::cin >> alpha;
	std::cout << "Enter the beta value (0-100): "; std::cin >> beta;

	// new_image(i,j) = alpha*tempImage(i,j) + beta operation 
	// Access each pixel of each RGB colour planes
	for (int j = 0; j < tempImage.rows; j++) {			// Loop rows
		for (int i = 0; i < tempImage.cols; i++) {		// Loop columns
			for (int c = 0; c < 3; c++) {				// Loop 3 RGB (0,1,2) colour planes
				newImage.at<Vec3b>(j, i)[c] =
					saturate_cast<uchar>(alpha*(tempImage.at<Vec3b>(j, i)[c]) + beta);	//Converts type 
			}
		}
	}
	// Optimized version of above
	//tempImage.convertTo(new_image, -1, alpha, beta);

	// Create Windows
	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	// Display images
	imshow("Original Image", tempImage);
	imshow("New Image", newImage);

	return 0;
}


//----------------Colour Space Conversion------------------------------//
int colourSpace(Mat *mainImage, string imageDes)
{
	Mat tempImage;
	tempImage = *mainImage;

	// Check image existance
	if (tempImage.empty())
	{
		cout << "Could not open the image" << endl;
		return -1;
	}

	Mat newImage;

	//BGR to Gray Scale
//	if (imageDes == "gray")
//	{
//		cvtColor(tempImage, newImage, COLOR_BGR2GRAY);
//	}

	//BGR to HSV
//	if (imageDes == "gray")
//	{
//		cvtColor(tempImage, newImage, CV_BGR2HSV);
//	}
	
	return 0;
}

// Main function
int main(int argc, char** argv)
{
	Mat mainImage;								// Declaring the variable to store the image
	readImage(&mainImage);						// Function call to read the image
	displayImage(&mainImage, "Original Image");

	//Exposure and Contrast
	exposureContrast(&mainImage);

	// Wait till user presses a key
	waitKey();

	return 0;
}

