//-------------------------------DOCUMENTATION---------------------------------------
//	13/03/2017 - Nipun - Opening an image within project folder and displaying
//  14/03/2017 - Dileepa - Added image saving function
//	15/03/2017 - Dileepa - Image cropping function added


// Include header files
#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
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

//Image save Function
int saveImage(Mat *image, string imageName){

	char  savePath[100];
	sprintf(savePath,"Images\\%s.jpg",imageName.c_str());
	imwrite( savePath, *image );
	return 0;

}

//Image crop
// @input  image - a pointer to the image to be cropped
// @inout  cropRectangle - a pointer to a cv::Rect object which defines the boundary of the crop

int imageCrop(Mat *image , Rect *cropRectangle){

	Mat imageTemp= *image;
	// Crop the full image to that image contained by the rectangle 
	Mat croppedImage = imageTemp(*cropRectangle);
	namedWindow("Cropped Image", WINDOW_AUTOSIZE);		  // Create a window for display.
	imshow("Cropped Image", croppedImage);                // Show our image inside it.
	return 0;
}

//Vignette 
int vignetteFilter(Mat *image, int sigma){

	Mat imageTemp = *image;
	vector<Mat> channels(3), filtChannel;
	Mat filteredChannel[3];

	Mat kernel_x = getGaussianKernel(imageTemp.rows, sigma);
	Mat kernel_y = getGaussianKernel(imageTemp.cols, sigma);
	Mat filter = kernel_x * kernel_y.t();
	Mat mask (imageTemp.rows,imageTemp.cols, CV_8UC1);
	normalize(filter,mask,0,255,NORM_MINMAX, CV_8UC1);
	
	split(imageTemp,channels);
	
	filteredChannel[0] = channels[0].mul(mask)/255;
	filteredChannel[1] = channels[1].mul(mask)/255;
	filteredChannel[2] = channels[2].mul(mask)/255;

	filtChannel.push_back(filteredChannel[0]);
	filtChannel.push_back(filteredChannel[1]);
	filtChannel.push_back(filteredChannel[2]);
	
	Mat filteredImage(imageTemp.rows,imageTemp.cols, CV_8UC3);
	merge(filtChannel,filteredImage);
	
	namedWindow("Filtered Image", WINDOW_AUTOSIZE);		    // Create a window for display.
	imshow("Filtered Image", filteredImage);                // Show our image inside it.
	return 0;

}


// Main function
int main(int argc, char** argv)
{
	Mat mainImage;								// Declaring the variable to store the image
	readImage(&mainImage);						// Function call to read the image
	if (mainImage.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	
	namedWindow("Original Image", WINDOW_AUTOSIZE);		// Create a window for display.
	imshow("Original Image", mainImage);                // Show our image inside it.
	saveImage(&mainImage, "new");

	Rect tempRect(50,100, 200 ,200);   // This rectangle dimensions should be given through the mouse events
	//imageCrop(&mainImage,&tempRect);
	vignetteFilter(&mainImage, 80);
	waitKey(0);											// Wait for a keystroke in the window
	return 0;
}