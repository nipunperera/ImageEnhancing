//-----------Documentation for the color noise reduction--------------------//
// 15/03/2017- Chamara- import the relevant header files
//						take the YCrCb compnonents of the RGB image
//						Filter the Chroma compnonents of the color space Cr and Cb
//						re convert the YCrCb color space to the RGB color space



#include "stdafx.h"
#include "noiseReduction.h"			//import the header file containing all the .h files and function definitions

using namespace std;
using namespace cv;



/*--------------------------starts color noise filtering---------------------------------------------------*/
/* this function color noise reduction is done. It will used different filtering methods for the color noise reduction.
It is used the Cb and Cr components of the YCbCr color space for the enahncement. After enhancing the Cb and Cr
both the three components are merged and convet in to RGB color space*/

//@para: Mat * inputImage :- pointer varible for the input image
//	     Mat *outputImage :- pointer variable for the outout image
//@return value: integer

int colorNoiseFiltering(Mat * inputImage, Mat *outputImage)
{
	Mat YCrCb;

	
	Mat channels[3];			//creating array of Mat variables for the 3 cmponents of the YCrCb

	cvtColor(*inputImage, YCrCb, COLOR_BGR2YCrCb, 3);
	split(YCrCb, channels);

	
	int selectNumber;			//taking input values to select the filter type and its main parameter value for the process
	int parameter;
	cin >> selectNumber;
	cout << endl; 
	cin >> parameter;
	cout << endl;
	
	switch (selectNumber)
	{
		case 1:	colorNoiseBoxFilter(&channels[0], &channels[1], &channels[2], outputImage, parameter); break;
		case 2: colorNoiseGaussianFilter(&channels[0], &channels[1], &channels[2], outputImage, parameter); break;
		case 3:	colorNoiseMedianFilter(&channels[0], &channels[1], &channels[2], outputImage, parameter); break;
		case 4: colorNoiseBilateralFilter(&channels[0], &channels[1], &channels[2], outputImage, parameter); break;
		default:cout << "Press valid key";
		break;
	}

	//colorNoiseBoxFilter(&channels[0], &channels[1], &channels[2], outputImage, 11);
	//colorNoiseGaussianFilter(&channels[0], &channels[1], &channels[2], outputImage, 101);
	//colorNoiseMedianFilter(&channels[0], &channels[1], &channels[2], outputImage, 101);
	//colorNoiseBilateralFilter(&channels[0], &channels[1], &channels[2], outputImage, 1);

	
	/*colorNoiseGaussianFilter(&channels);
	colorNoiseMedianFilter(&channels);
	colorNoiseBilateralFilter(&channels);*/
	return 0;
}

//filter the Cr and Cb components of the YCrCb image using Box filter

int colorNoiseBoxFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i)
{

	blur(*Cb, *Cb, Size(i, i), Point(-1, -1));
	blur(*Cr, *Cr, Size(i, i), Point(-1, -1));
	
	vector<Mat> finalChannels = { *y, *Cb, *Cr };
	
	merge(finalChannels, *outputImage);			// merge the filtered components and the luma part to creat the output image in YCrCb color space	
	cvtColor(*outputImage, *outputImage, COLOR_YCrCb2BGR);

	return 0;
}

//filter the Cr and Cb components of the YCrCb image using Gaussian filter
int colorNoiseGaussianFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i)
{
	
	
	GaussianBlur(*Cb, *Cb, Size(i, i), 0, 0, 1);
	GaussianBlur(*Cr, *Cr, Size(i, i), 0, 0, 1);

	
	vector<Mat> finalChannels = { *y, *Cb, *Cr };
	
	merge(finalChannels, *outputImage);
	
	cvtColor(*outputImage, *outputImage, COLOR_YCrCb2BGR);
	
	return 0;
}

//filter the Cr and Cb components of the YCrCb image using Median filter
int colorNoiseMedianFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i)
{
	medianBlur(*Cb, *Cb, i);
	medianBlur(*Cr, *Cr, i);

	vector<Mat> finalChannels = { *y, *Cb, *Cr };
	merge(finalChannels, *outputImage);
	cvtColor(*outputImage, *outputImage, COLOR_YCrCb2BGR);

	return 0;
}

//filter the Cr and Cb components of the YCrCb image using Bilateral filter
int colorNoiseBilateralFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i)
{
	bilateralFilter(*Cb, *Cb, i, i * 2, i / 2);
	bilateralFilter(*Cr, *Cr, i, i * 2, i / 2);

	vector<Mat> finalChannels = { *y, *Cb, *Cr };
	merge(finalChannels, *outputImage);
	cvtColor(*outputImage, *outputImage, COLOR_YCrCb2BGR);

	return 0;
}


/*-----------------------------------ends color noise filtering-------------------------------------------*/


/*-----------------------------------starts luminocity fitlering------------------------------------------*/
/*in this section it filter the Y component of the */



/*int main()
{

	/*string imageName("../data/sd.jpg");
	Mat image;
	Mat processedImage;

	Mat yComoponent;
	Mat CbComoponent;
	Mat CrComoponent;

	Mat chan[3];

	image = imread(imageName.c_str(), IMREAD_COLOR);


	if (image.empty())
	{
	cout << "Could not open the image" << std::endl;
	return -1;
	}

	cvtColor(image, processedImage, COLOR_BGR2YCrCb,3);

	Mat outputImage;

	GaussianBlur(image, outputImage, Size(11, 11), 0, 0,1);
	imshow("before process", outputImage);

	split(processedImage, chan);

	/*Mat	portions(chan[0].size(), chan[0].type(), 127);

	vector<Mat> yChannels = { chan[0], portions, portions };
	merge(yChannels, yComoponent);
	imshow("Before Display Y", yComoponent);
	cvtColor(yComoponent, yComoponent, COLOR_YCrCb2BGR);
	imshow("Display Y",yComoponent);

	vector<Mat> CbChannels = { portions, chan[1], portions };
	merge(CbChannels, CbComoponent);
	imshow("Before Display Cb", CbComoponent);
	cvtColor(CbComoponent, CbComoponent, COLOR_YCrCb2BGR);
	imshow("Display Cb", CbComoponent);

	vector<Mat> CrChannels = { portions, portions, chan[2] };
	merge(CrChannels, CrComoponent);
	imshow("Before Display Cr", CrComoponent);
	cvtColor(CrComoponent, CrComoponent, COLOR_YCrCb2BGR);
	imshow("Display Cr", CrComoponent);

	waitKey(0);*/

	//GaussianBlur(chan[0], chan[0], Size(11, 11), 0, 0, 1);
	/****GaussianBlur(chan[2], chan[2], Size(1, 1), 0, 0, 1);
	GaussianBlur(chan[1], chan[1], Size(1, 1), 0, 0, 1);


	Mat YCCoutputImage;

	vector<Mat> Channels = { chan[0], chan[1],chan[2] };
	merge(Channels, YCCoutputImage);


	cvtColor(YCCoutputImage, YCCoutputImage, COLOR_YCrCb2BGR);
	imshow("outputImage", YCCoutputImage);

	waitKey(0);*****/

	/*Mat inputImage;
	Mat outputImage;
	readImage(&inputImage);
	colorNoiseFiltering(&inputImage, &outputImage);

	imshow("Input", inputImage);
	imshow("Output Image", outputImage);
	waitKey(0);

}*/