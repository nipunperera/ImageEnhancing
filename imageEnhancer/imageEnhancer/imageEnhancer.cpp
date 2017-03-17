//-------------------------------Documentation--------------------------------------//
//14/03/2017 - Exposure Adjustment
//14/03/2017 - Contrast Adjustment
//15/03/2017 - Saturation Adjustment - Colour Space Conversion
//16/03/2017 - GUI for Hue, Saturation and Value and algorithm optimization

// Include header files
#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>	//Added to additional dependancies
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>			// Added for Exposure, Contrast Adjustment

using namespace cv;
using namespace std;

/// Global variables
Mat src, img, image;

int elem1 = 255, elem2 = 255, elem3 = 255;
int elem4 = 255 ;
int alpha_slider = 1;
int bright = 50, contrast = 50;
double alpha;
double beta;

int const max_elem = 500;
double const max_alpha = 3;

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

//----------------Exposure and Contrast Adjustment - OLD---------------------//
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
	int beta;			//Exposure (Brightness) control - Bias parameter

	//Initialize zero matrix to store adjusted image - same size and type as original
	Mat newImage = Mat::zeros(tempImage.size(), tempImage.type());	

	// Initialize Values from user input
	std::cout << " Basic Linear Transform " << std::endl;
	std::cout << "Enter the Contrast (alpha) value (1-3): "; std::cin >> alpha;
	std::cout << "Enter the Exposure (beta) value (0-100): "; std::cin >> beta;

	// new_image(i,j) = alpha*tempImage(i,j) + beta operation 
	// Access each pixel of each BGR colour planes
	for (int j = 0; j < tempImage.rows; j++) {			// Loop rows
		for (int i = 0; i < tempImage.cols; i++) {		// Loop columns
			for (int c = 0; c < 3; c++) {				// Loop 3 BGR (0,1,2) colour planes
				newImage.at<Vec3b>(j, i)[c] =
					saturate_cast<uchar>(alpha*(tempImage.at<Vec3b>(j, i)[c]) + beta);	//Converts type 
			}
		}
	}
	// Optimized version of above - used in GUI
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
//---------------------Contrast :( ----------------------------------------//
void Contrast1(int, void *)
{
	int contra = elem4 - 1;
	image = src;
	// new_image(i,j) = alpha*tempImage(i,j) + beta operation 
	// Access each pixel of each BGR colour planes
	for (int y = 0; y < image.cols; y++) {			// Loop columns
		for (int x = 0; x < image.rows; x++) {		// Loop rows
			int cur1 = image.at<Vec3b>(Point(y, x))[0];
			int cur2 = image.at<Vec3b>(Point(y, x))[1];
			int cur3 = image.at<Vec3b>(Point(y, x))[2];
			cur1 *= contra;
			cur2 *= contra;
			cur3 *= contra;
			if (cur1 < 0) cur1 = 0; else if (cur1 > 255) cur1 = 255;
			if (cur2 < 0) cur2 = 0; else if (cur2 > 255) cur2 = 255;
			if (cur3 < 0) cur3 = 0; else if (cur3 > 255) cur3 = 255;

			image.at<Vec3b>(Point(y, x))[0] = cur1;
			image.at<Vec3b>(Point(y, x))[1] = cur2;
			image.at<Vec3b>(Point(y, x))[2] = cur3;
		}
	}
	imshow("image", image);
}

//------------------------------Histogram Equalization----------------------------//
int HistEq()
{
	vector<Mat> channels;
	cvtColor(src, image, CV_BGR2YCrCb);			// Change the color image from BGR to YCrCb format
	split(image, channels);						// Split the image into channels
	equalizeHist(channels[0], channels[0]);		// Equalize histogram on the 1st channel (Y)
	merge(channels, image);						// Merge the 3 channels 
	cvtColor(image, image, CV_YCrCb2BGR);		// Back to BGR
	imshow("Histogram Equalized Image", image);	// Shows image
	waitKey(0);									//wait for key press
	return 0;
}

//----------------Saturation - Colour Space Conversion - OLD ------------------------------//
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
	// convert BGR image to HSV
	cvtColor(tempImage, newImage, CV_BGR2HSV);
	namedWindow("Original image", CV_WINDOW_AUTOSIZE);		//Display Original BGR image
	imshow("Original image", tempImage);
	namedWindow("HSV Original", CV_WINDOW_AUTOSIZE);		//Display HSV image
	imshow("HSV Original", newImage);
	// Wait till user presses a key
	waitKey(0);

	// hue varies from 0 to 179, saturation from 0 to 255
	float h_ranges[] = { 0, 180 };
	float s_ranges[] = { 0, 256 };
	const float* ranges[] = { h_ranges, s_ranges };
	// Use the o-th and 1-st channels
	int channels[] = { 0, 1 };
	double sat;
	std::cout << "Enter the Saturation value: "; std::cin >> sat;		//User input normalized sat value
	vector<Mat> hsv_planes;
	split(newImage, hsv_planes);
	Mat h = hsv_planes[0]; // H channel
	Mat s = hsv_planes[1]; // S channel
	Mat v = hsv_planes[2]; // V channel

//	namedWindow("hue", CV_WINDOW_AUTOSIZE);			// Display Hue image
//	imshow("hue", h);
	namedWindow("saturation original", CV_WINDOW_AUTOSIZE);		// Display oiginal saturation image
	imshow("saturation original", s);
	namedWindow("saturation", CV_WINDOW_AUTOSIZE);		// Display New saturated image
	imshow("saturation", s*sat);
//	namedWindow("value", CV_WINDOW_AUTOSIZE);			// Display Value image
//	imshow("value", v);

	hsv_planes[1] = s*sat;
	namedWindow("Original image", CV_WINDOW_AUTOSIZE);
	imshow("Original image", tempImage);
	namedWindow("HSV", CV_WINDOW_AUTOSIZE);
	imshow("HSV", newImage);
//	Mat satBGR;
	// convert HSV image to BGR
//	cvtColor(newImage, satBGR, CV_HSV2BGR);
//	namedWindow("BGR", CV_WINDOW_AUTOSIZE);
//	imshow("BGR", satBGR);
	waitKey(0);
	return 0;
}

//------------------Saturation Adjustment with GUI ------------------------//
void HSV()
{
	cvtColor(src, img, CV_BGR2HSV);		//Convert from BGR to HSV

	//Initialize
	int hue = elem1 - 255;
	int saturation = elem2 - 255;
	int value = elem3 - 255;

	// Loop for each pixel in each HSV plane
	for (int y = 0; y<img.cols; y++)
	{
		for (int x = 0; x<img.rows; x++)
		{
			int cur1 = img.at<Vec3b>(Point(y, x))[0];			// Hue Plane
			int cur2 = img.at<Vec3b>(Point(y, x))[1];			// Saturation Plane
			int cur3 = img.at<Vec3b>(Point(y, x))[2];			// Value Plane
			cur1 += hue;
			cur2 += saturation;
			cur3 += value;

			if (cur1 < 0) cur1 = 0; else if (cur1 > 255) cur1 = 255;
			if (cur2 < 0) cur2 = 0; else if (cur2 > 255) cur2 = 255;
			if (cur3 < 0) cur3 = 0; else if (cur3 > 255) cur3 = 255;

			img.at<Vec3b>(Point(y, x))[0] = cur1;
			img.at<Vec3b>(Point(y, x))[1] = cur2;
			img.at<Vec3b>(Point(y, x))[2] = cur3;
		}
	}

	cvtColor(img, image, CV_HSV2BGR);			// Convert HSV to BGR
	imshow("image", image);						// Dispay adjusted image
}
void Hue(int, void *)
{
	HSV();
}
void Saturation(int, void *)
{
	HSV();
}
void Value(int, void *)
{
	HSV();
}
void Luminance(int, void *)
{
	cvtColor(src, img, CV_BGR2YCrCb);			// Change the color image from BGR to YCrCb format

	//Initialize
	int luminosity = elem4 - 255;

	// Loop for each pixel in each HSV plane
	for (int y = 0; y<img.cols; y++)
	{
		for (int x = 0; x<img.rows; x++)
		{
			int cur1 = img.at<Vec3b>(Point(y, x))[0];			// Y-Luminosity Plane
			cur1 += luminosity;
			if (cur1 < 0) cur1 = 0; else if (cur1 > 255) cur1 = 255;
			img.at<Vec3b>(Point(y, x))[0] = cur1;
		}
	}
	cvtColor(img, image, CV_YCrCb2BGR);			// Back to BGR
	imshow("image", image);						// Display adjusted image
}

// -------------------- Exposure and Contrast Adjustment with GUI----------------//
void BC()
{
	int exposure = bright - 50;
	double ContrastNew = contrast / 50.0;				// Or divide by smaller no. to increase range
	src.convertTo(image, -1, ContrastNew, exposure);	//Linear Transform - per pixel - contrast*im+brightness
	imshow("image", image);
}
void Brightness(int, void *)
{
	BC();
}
void Contrast(int, void *)
{
	BC();
}

// Main function
int main(int argc, char** argv)
{
	Mat mainImage;								// Declaring the variable to store the image
	readImage(&mainImage);						// Function call to read the image
	displayImage(&mainImage, "Original Image");

	src = mainImage;
	//Exposure and Contrast
//	exposureContrast(&mainImage);				// Old contrast Function call
	HistEq();									//Auto-adjust Contrast ;)
	//Saturation
//	saturation(&mainImage, "BGR");				// Old saturation Function call

	namedWindow("image");													// Creates a window for UIs
	imshow("image", mainImage);												// Dispay original image
	createTrackbar("Hue", "image", &elem1, max_elem, Hue);					// Slider for user to change Hue
	createTrackbar("Saturation", "image", &elem2, max_elem, Saturation);	// Slider for user to change Saturation
	createTrackbar("Value", "image", &elem3, max_elem, Value);				// Slider for user to change Value
	createTrackbar("Luminance", "image", &elem4, max_elem, Luminance);		// Slider for user to change Luminance
//	createTrackbar("Contrast1", "image", &elem4, max_alpha, Contrast1);
	createTrackbar("Exposure","image",&bright, 100, Brightness);			// Slider for user to change Exposure
	createTrackbar("Contrast", "image", &contrast, 100, Contrast);			// Slider for user to change Contrast

	// Wait till user presses a key
	waitKey(0);
	return 0;
}

