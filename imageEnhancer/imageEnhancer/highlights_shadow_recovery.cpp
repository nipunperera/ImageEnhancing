
//-----------Documentation for the shadow higlights recovery--------------------//
// 15/03/2017- Chamara- import the relevant header files
//						take the RGB compnonents of the RGB image
//						take the pixel values in lower reiogn and upper region of the image and do a gamma correction appropritately.
//						output is not perfect as in the standards tools like Adobe light room. however sufficient enhamcemetn of the image is provided	
//						recollect the RGB components and show the image



#include "stdafx.h"
#include "noiseReduction.h"

using namespace std;
using namespace cv;



/*--------------------starts the shadow recovery-------------------*/

int shadowRecovery(Mat * image, Mat * out, int gamma)
{

	Mat im = *image;
	int x, y;

	int blue_new;
	int green_new;
	int red_new;

	double gammaUnder = 1 + 0.1*abs(gamma);				//define the appropriate gamma values for the shadow recovery
	double gammaUpper = 1 - 0.01*abs(gamma);


	for (x = 0; x < im.rows; x++){						// check the pixel values of the image change the value if the pixel values are below the 114
		for (y = 0; y < im.cols; y++){
			Vec3b intensity = im.at<Vec3b>(x, y);
			uchar blue = intensity.val[0];				//obtain the RGB values seperately
			uchar green = intensity.val[1];
			uchar red = intensity.val[2];

			blue_new = (int)blue;
			green_new = (int)green;
			red_new = (int)red;
			//blue value
			if (blue < 114 && gamma >0)					//changing the RGB values seperately
			{
				blue_new = (int)114 * pow(((blue) / (double)114), gammaUpper);
				
			}
			else if (blue < 114 && gamma <0)
			{
				blue_new = (int)114 * pow(((blue) / (double)114), gammaUnder);
				
			}
			//green value
			if (green < 114 && gamma >0)
			{

				green_new = (int)114 * pow(((green) / (double)114), gammaUpper);
				

			}
			else if (green < 114 && gamma <0)
			{
				green_new = (int)114 * pow(((green) / (double)114), gammaUnder);
				if (green_new < 0)
					green_new = 0;
			}
			//red value
			if (red < 114 && gamma >0)
			{

				red_new = (int)114 * pow(((red) / (double)114), gammaUpper);
				
			}
			else if (red < 114 && gamma <0)
			{
				red_new = (int)114 * pow(((red) / (double)114), gammaUnder);
				
			}

			im.at<Vec3b>(x, y) = Vec3b(blue_new, green_new, red_new);

		}
		
	}

	*out = im;
	return 0;
}

int highlightsRecovery(Mat * image, Mat * out, int gamma)
{
	Mat im = *image;
	int x, y;											//the process which has been done for the shadow recovery is repeated here. but the gamma values and the selected 
														//pixel values ranges are changed. 
	int blue_new;
	int green_new;
	int red_new;

	double gammaUnder = 1 + 0.09*abs(gamma);
	double gammaUpper = 1 - 0.009*abs(gamma);

	for (x = 0; x < im.rows; x++){
		for (y = 0; y < im.cols; y++){
			Vec3b intensity = im.at<Vec3b>(x, y);
			int blue = intensity.val[0];
			int green = intensity.val[1];
			int red = intensity.val[2];

			blue_new = (int)blue;
			green_new = (int)green;
			red_new = (int)red;
			//blue value
			if (blue > 153 && gamma >0)
			{
				blue_new = 255 - (int)102 * pow(((255 - blue) / (double)102), gammaUpper);
			}
			else if (blue > 153 && gamma <0)
			{
				blue_new = 255 - (int)102 * pow(((255 - blue) / (double)102), gammaUnder);
			}
			//green value
			if (green > 153 && gamma >0)
			{

				green_new = 255 - (int)102 * pow(((255 - green) / (double)102), gammaUpper);

			}
			else if (green > 153 && gamma <0)
			{
				green_new = 255 - (int)102 * pow(((255 - green) / (double)102), gammaUnder);
			}
			//red value
			if (red > 153 && gamma >0)
			{

				red_new = 255 - (int)102 * pow(((255 - red) / (double)102), gammaUpper);
			}
			else if (red > 153 && gamma <0)
			{
				red_new = 255 - (int)102 * pow(((255 - red) / (double)102), gammaUnder);
			}

			im.at<Vec3b>(x, y) = Vec3b(blue_new, green_new, red_new);

		}
	}
	
	*out = im;
	return 0;
}



