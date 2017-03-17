#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>
#include<math.h>


using namespace std;
using namespace cv;

int colorNoiseBoxFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *output, int i);
int colorNoiseGaussianFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i);
int colorNoiseMedianFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i);
int colorNoiseBilateralFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i);
int colorNoiseFiltering(Mat * inputImage, Mat *outputImage);

int lumaNoiseBoxFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *output, int i);
int lumaNoiseGaussianFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i);
int lumaNoiseMedianFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i);
int lumaNoiseBilateralFilter(Mat *y, Mat *Cb, Mat *Cr, Mat *outputImage, int i);
int lumaNoiseFiltering(Mat * inputImage, Mat *outputImage);

int shadowRecovery(Mat * image, Mat * out, int gamma);
int highlightsRecovery(Mat * image, Mat * out, int gamma);