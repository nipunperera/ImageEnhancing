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


//Vignette with offset
int vignetteFilterOffset(Mat *image, int sigma, int offset_x,int offset_y){

	Mat imageTemp = *image;
	vector<Mat> channels(3), filtChannel;
	Mat filteredChannel[3];

	int im_height = imageTemp.rows;
	int im_width  = imageTemp.cols;

	int xLen =0 , yLen =0;
	bool xFlag = false  ,yFlag = false;
	if ( (im_height - offset_y ) <  im_height/2 ) {
			yLen = offset_y ;

	}
	else 
	{ 
			yLen = im_height - offset_y ;
			yFlag = true;
	}

	if ( (im_width - offset_x ) <  im_width/2 ) {
			xLen = offset_x ;

	}
	else 
	{ 
			xLen = im_width - offset_x ;
			xFlag = true;
	}
	
	int cropX=0,cropY=0;
	if(xFlag | yFlag){

		cropY = xFlag ? yLen- offset_y : offset_y;
		cropX = yFlag ? xLen- offset_x : offset_x;
		
	}
	
	//cout << xLen << " : " << yLen << endl;
	//cout << cropX << " : " << cropY << endl;
	
	Mat kernel_x = getGaussianKernel(yLen * 2, sigma);
	Mat kernel_y = getGaussianKernel(xLen * 2, sigma);
	Mat filter = kernel_x * kernel_y.t();
	Mat mask (imageTemp.rows,imageTemp.cols, CV_8UC1);

	
	cout << cropX << " : " << cropY << endl;
	cout << filter.rows << " : " << filter.cols << endl;

	Rect cropRect(cropX,cropY,imageTemp.cols,imageTemp.rows);
	
	Mat filterCropped = filter(cropRect);
	normalize(filterCropped,mask,0,255,NORM_MINMAX, CV_8UC1);
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

	namedWindow("Filter", WINDOW_AUTOSIZE);		    // Create a window for display.
	imshow("Filter", mask);                // Show our image inside it.
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
	vignetteFilterOffset(&mainImage, 200, 350,350);
	waitKey(0);											// Wait for a keystroke in the window
	return 0;
}