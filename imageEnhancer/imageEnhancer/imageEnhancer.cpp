//-------------------------------DOCUMENTATION---------------------------------------
//	13/03/2017 - Nipun - Opening an image within project folder and displaying
//  14/03/2017 - Dileepa - Added image saving function
//	15/03/2017 - Dileepa - Image cropping function added


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
	imageCrop(&mainImage,&tempRect);
	waitKey(0);											// Wait for a keystroke in the window
	return 0;
}