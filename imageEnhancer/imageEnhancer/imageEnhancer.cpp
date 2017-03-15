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

	// Wait till user presses a key
	waitKey(0);

	return 0;
}


//----------------Saturation - Colour Space Conversion------------------------------//
int saturation(Mat *mainImage, string imageDes)
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

	// convert BGR image to HsV
	cvtColor(tempImage, newImage, CV_BGR2HSV);
	namedWindow("Original image", CV_WINDOW_AUTOSIZE);
	imshow("Original image", tempImage);

	namedWindow("HSV", CV_WINDOW_AUTOSIZE);
	imshow("HSV", newImage);

	// Wait till user presses a key
	waitKey(0);

	/// Using 50 bins for hue and 60 for saturation
	int h_bins = 50; int s_bins = 60;
	int histSize[] = { h_bins, s_bins };
	// hue varies from 0 to 179, saturation from 0 to 255
	float h_ranges[] = { 0, 180 };
	float s_ranges[] = { 0, 256 };
	const float* ranges[] = { h_ranges, s_ranges };
	// Use the o-th and 1-st channels
	int channels[] = { 0, 1 };
	/// Histograms
	MatND hist_base;
	MatND hist_half_down;

	/// Calculate the histograms for the HSV images
	calcHist(&newImage, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false);
	normalize(hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat());


	double sat;

	std::cout << "Enter the Saturation value: "; std::cin >> sat;

	vector<Mat> hsv_planes;
	split(newImage, hsv_planes);
	Mat h = hsv_planes[0]; // H channel
	Mat s = hsv_planes[1]; // S channel
	Mat v = hsv_planes[2]; // V channel



//	namedWindow("hue", CV_WINDOW_AUTOSIZE);
//	imshow("hue", h);
	namedWindow("saturation original", CV_WINDOW_AUTOSIZE);
	imshow("saturation original", s);
	namedWindow("saturation", CV_WINDOW_AUTOSIZE);
	imshow("saturation", s*sat);
//	namedWindow("value", CV_WINDOW_AUTOSIZE);
//	imshow("value", v);

	hsv_planes[1] = s*sat;
	namedWindow("Original image", CV_WINDOW_AUTOSIZE);
	imshow("Original image", tempImage);
	namedWindow("HSV", CV_WINDOW_AUTOSIZE);
	imshow("HSV", newImage);

	//BGR to Gray Scale
//	if (imageDes == "gray")
//	{
//		cvtColor(tempImage, newImage, COLOR_BGR2GRAY);
//	}

	//BGR to HSV
//	if (imageDes == "BGR")
//	{
//		cvtColor(tempImage, newImage, CV_BGR2HSV);
//	}
	
	waitKey(0);

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

	//Saturation
	saturation(&mainImage, "BGR");

	// Wait till user presses a key
	waitKey(0);

	return 0;
}

