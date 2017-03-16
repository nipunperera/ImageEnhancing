//-----------Documentation for the luma noise reduction--------------------//
// 15/03/2017- Chamara- import the relevant header files
//						take the YCrCb compnonents of the RGB image
//						Filter the luma compnonents of the color space y
//						re convert the YCrCb color space to the RGB color space



#include "stdafx.h"
#include "noiseReduction.h"			//import the header file containing all the .h files and function definitions

using namespace std;
using namespace cv;



/*--------------------------starts luma noise filtering---------------------------------------------------*/
/* this function luminance noise reduction is done. It will used different filtering methods for the luma noise reduction.
It is used the y component of the YCbCr color space for the enahncement. After enhancing the y
both the three components are merged and convet in to RGB color space*/

//@para: Mat * inputImage :- pointer varible for the input image
//	     Mat *outputImage :- pointer variable for the outout image
//@return value: integer

int lumaNoiseFiltering(Mat * inputImage, Mat *outputImage)
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
	case 1:	lumaNoiseBoxFilter(&channels[0], &channels[1], &channels[2], outputImage, parameter); break;
	case 2: lumaNoiseGaussianFilter(&channels[0], &channels[1], &channels[2], outputImage, parameter); break;
	case 3:	lumaNoiseMedianFilter(&channels[0], &channels[1], &channels[2], outputImage, parameter); break;
	case 4: lumaNoiseBilateralFilter(&channels[0], &channels[1], &channels[2], outputImage, parameter); break;
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

int lumaNoiseBoxFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i)
{

	blur(*y, *y, Size(i, i), Point(-1, -1));
	
	vector<Mat> finalChannels = { *y, *Cb, *Cr };

	merge(finalChannels, *outputImage);			// merge the filtered components and the luma part to creat the output image in YCrCb color space	
	cvtColor(*outputImage, *outputImage, COLOR_YCrCb2BGR);

	return 0;
}

//filter the Cr and Cb components of the YCrCb image using Gaussian filter
int lumaNoiseGaussianFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i)
{


	GaussianBlur(*y, *y, Size(i, i), 0, 0, 1);
	
	vector<Mat> finalChannels = { *y, *Cb, *Cr };

	merge(finalChannels, *outputImage);

	cvtColor(*outputImage, *outputImage, COLOR_YCrCb2BGR);

	return 0;
}

//filter the Cr and Cb components of the YCrCb image using Median filter
int lumaNoiseMedianFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i)
{
	medianBlur(*y, *y, i);
	
	vector<Mat> finalChannels = { *y, *Cb, *Cr };
	merge(finalChannels, *outputImage);
	cvtColor(*outputImage, *outputImage, COLOR_YCrCb2BGR);

	return 0;
}

//filter the Cr and Cb components of the YCrCb image using Bilateral filter
int lumaNoiseBilateralFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i)
{
	bilateralFilter(*y, *y, i, i * 2, i / 2);
	
	vector<Mat> finalChannels = { *y, *Cb, *Cr };
	merge(finalChannels, *outputImage);
	cvtColor(*outputImage, *outputImage, COLOR_YCrCb2BGR);

	return 0;
}


