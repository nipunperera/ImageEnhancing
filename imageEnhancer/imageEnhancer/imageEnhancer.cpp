//-------------------------------DOCUMENTATION--------------------------------------------
//	13/03/2017 - Nipun - Opening an image within project folder and displaying
//					   - Defining separate functions for reading and displaying the image
//					   - White balance functionality was added
//	14/03/2017 - Nipun - Colour temperature adjustment functionality was added


// Include header files
#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
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
	waitKey(0);									// Wait for a keystroke in the window
	return 0;
}

// Read RAW image
int readRAWImage()
{
	string imageName("RAW\\img4.nef");
	Mat rawImage;
	rawImage = imread(imageName.c_str(), 1);
	displayImage(&rawImage, "RAW Image");
	return 0;
}

// Calculate white balanced image
int whiteBalance(Mat *mainImage)
{
	Mat resolvedImage[3];				// Matrix for splitting BGR channels
	Mat grayImage;						// Convert to grayscale image
	cvtColor(*mainImage, grayImage, CV_BGR2GRAY);
	split(*mainImage, resolvedImage);	// Splitting the BGR channels
	//	displayImage(&grayImage, "Grayscale Image");
	//	cout << mean(grayImage)[0] << endl;

	double meanGray, meanBlue, meanGreen, meanRed;	// Declare variables to store mean channel values
	meanGray = mean(grayImage)[0];					// Mean grayscale intensity
	meanBlue = mean(resolvedImage[0])[0];			// Mean blue intensity
	meanGreen = mean(resolvedImage[1])[0];			// Mean green intensity
	meanRed = mean(resolvedImage[2])[0];			// Mean red intensity

	// Calculating each channel so that the mean is equal in all three
	// Contains BGR channels with mean intensity equal to the mean grayscale intensity
	Mat equalizedImage[3];
	equalizedImage[0] = resolvedImage[0] * meanGray / meanBlue;
	equalizedImage[1] = resolvedImage[1] * meanGray / meanGreen;
	equalizedImage[2] = resolvedImage[2] * meanGray / meanRed;

	// Merging the BGR channels and obtaining the white balanced image
	vector < Mat > arrayToMerge;
	arrayToMerge.push_back(equalizedImage[0]);
	arrayToMerge.push_back(equalizedImage[1]);
	arrayToMerge.push_back(equalizedImage[2]);

	Mat finalImage;
	merge(arrayToMerge, finalImage);
	displayImage(&finalImage, "White Balanced Image");
	return 0;
}

//Colour temperature adjustment
int colourTempAdjustment(Mat *mainImage)
{
	Mat resolvedImage[3];
	Mat blueChannel, greenChannel, redChannel;
	split(*mainImage, resolvedImage);	// Splitting the BGR channels
	// Create warmer image
	// Done by increasing the red channel and decreasing the blue channel 
	// and increasing saturation of the image in HSV colour space

	// Create a cooler image
	// Done by decreasing the red channel and increasing blue channel
	// and decreasing the saturation of the image in the HSV colour image
	redChannel = resolvedImage[2] + 50; 
	blueChannel = resolvedImage[0] - 50;
	greenChannel = resolvedImage[1];

	// Merging the BGR channels 
	vector < Mat > arrayToMerge;
	arrayToMerge.push_back(blueChannel);
	arrayToMerge.push_back(greenChannel);
	arrayToMerge.push_back(redChannel);

	// Image with altered red abd blue channels
	Mat bgrAdjusted;
	merge(arrayToMerge, bgrAdjusted);
	
	// Convert image to HSV colour space and splitting layers for saturation adjustment
	Mat hsvImage;
	Mat hsvResolved[3];
	cvtColor(bgrAdjusted, hsvImage, CV_BGR2HSV);
	split(hsvImage, hsvResolved);

	// Adjusting saturation
	Mat hNew, sNew, vNew;
	hNew = hsvResolved[0];
	sNew = hsvResolved[1] + 50;
	vNew = hsvResolved[2];

	// Merging the HSV channels 
	vector < Mat > arrayToMergeHSV;
	arrayToMergeHSV.push_back(hNew);
	arrayToMergeHSV.push_back(sNew);
	arrayToMergeHSV.push_back(vNew);

	// Converting the image back to BGR
	Mat hsvAdjusted;			// Image with altered saturation channel
	Mat tempAdjusted;
	merge(arrayToMergeHSV, hsvAdjusted);
	cvtColor(hsvAdjusted, tempAdjusted, CV_HSV2BGR);

	// Display image
	displayImage(&tempAdjusted, "Colour Temperature Adjusted Image");
	return 0;
}

// Main function
int main(int argc, char** argv)
{
	Mat mainImage;								// Declaring the variable to store the image
	readImage(&mainImage);						// Function call to read the image
	displayImage(&mainImage, "Original Image");
	//whiteBalance(&mainImage);
	colourTempAdjustment(&mainImage);
	return 0;
}