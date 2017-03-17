#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "spline.h"
#include "math.h"

cv::Mat editedImage;
cv::Mat tempAdjusted;

namespace MyGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  tempApply;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tempApply = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1264, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->importToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// importToolStripMenuItem
			// 
			this->importToolStripMenuItem->Name = L"importToolStripMenuItem";
			this->importToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->importToolStripMenuItem->Text = L"Import";
			this->importToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::importToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 480);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(710, 88);
			this->trackBar1->Maximum = 5;
			this->trackBar1->Minimum = -5;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(166, 45);
			this->trackBar1->TabIndex = 2;
			this->trackBar1->TickFrequency = 0;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(747, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Temperature ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(765, 185);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Colour";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Blue;
			this->label3->Location = System::Drawing::Point(684, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Cold";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(872, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Warm";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->tempApply);
			this->panel1->Location = System::Drawing::Point(676, 61);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(240, 108);
			this->panel1->TabIndex = 8;
			// 
			// tempApply
			// 
			this->tempApply->Location = System::Drawing::Point(75, 70);
			this->tempApply->Name = L"tempApply";
			this->tempApply->Size = System::Drawing::Size(80, 24);
			this->tempApply->TabIndex = 0;
			this->tempApply->Text = L"Apply";
			this->tempApply->UseVisualStyleBackColor = true;
			this->tempApply->Click += gcnew System::EventHandler(this, &MyForm::tempApply_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void importToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
		// Displays an OpenFileDialog so the user can select an image file.  
		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "All Graphics Types|*.bmp;*.jpg;*.jpeg;*.png;*.tif;*.tiff";
		openFileDialog1->Title = "Select an Image File";

		// Show the Dialog.  
		// If the user clicked OK in the dialog and  
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
		// Assign the cursor in the Stream to  
		// the Form's Cursor property. 
		// cache.jpg is the copy of the original image used for editing
			pictureBox1->Load(openFileDialog1->FileName);
			pictureBox1->Image->Save("cache.jpg", System::Drawing::Imaging::ImageFormat::Jpeg);
			editedImage = cv::imread("cache.jpg", cv::IMREAD_COLOR);
		}
	}
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		// Acquire track bar value
		int trackBarValue = trackBar1->Value;

		// Initiate a Mat to save the cache.jpg image
		cv::Mat mainImage;
		mainImage = editedImage;
		colourTempAdjustment(&mainImage, trackBarValue);
		tempApply->Enabled = true;
	}

	private: System::Void tempApply_Click(System::Object^  sender, System::EventArgs^  e) {
		editedImage = tempAdjusted;
		tempApply->Enabled = false;
	}

	// Functions defined in opencv
			cv::Mat readImage()
			 {
				 cv::String imageName("cache.jpg");
				 cv::Mat mainImage;
				 mainImage = cv::imread(imageName.c_str(), cv::IMREAD_COLOR);
				 return mainImage;
			 }

			 // Display image
			 int displayImage(cv::Mat *mainImage, cv::String imageDes)
			 {
				 cv::Mat tempImage;
				 tempImage = *mainImage;
				 if (tempImage.empty())                      // Check for invalid input
				 {
					 return -1;
				 }
				 namedWindow(imageDes, cv::WINDOW_AUTOSIZE);		// Create a window for display.
				 imshow(imageDes, tempImage);                // Show our image inside it.
				 cv::waitKey(0);									// Wait for a keystroke in the window
				 return 0;
			 }

			 //Colour temperature adjustment
			int colourTempAdjustment(cv::Mat *mainImage, int tempValue)
			 {
				int absTemp = abs(tempValue);
				 cv::Mat resolvedImage[3];
				 cv::Mat blueChannel, greenChannel, redChannel;
				 split(*mainImage, resolvedImage);	// Splitting the BGR channels

				// Create warmer image
				// Done by increasing the red channel and decreasing the blue channel 
				// and increasing saturation of the image in HSV colour space

				// Create a cooler image
				// Done by decreasing the red channel and increasing blue channel
				// and decreasing the saturation of the image in the HSV colour image

				// Spline interpolation 
				 std::vector<double> X(5), Y(5), Z(5);
				 X[0] = 0; X[1] = 64; X[2] = 128; X[3] = 192; X[4] = 255;

				 Y[0] = 5 * absTemp;  Y[1] = 64 + (7 * absTemp); Y[2] = 128 + (8 * absTemp);
				 Y[3] = 192 + (10 * absTemp); Y[4] = 255;

				 Z[0] = 0; Z[1] = 64 - (5 * absTemp); Z[2] = 128 - (7 * absTemp);
				 Z[3] = 192 - (8 * absTemp); Z[4] = 255 - (10 * absTemp);

				 // Creating spline functions
				 tk::spline incIntensity, decIntensity;
				 incIntensity.set_points(X, Y);    
				 decIntensity.set_points(X, Z);

				 redChannel = resolvedImage[2]; //+ (10 * tempValue); 
				 blueChannel = resolvedImage[0]; //- (10 * tempValue);
				 greenChannel = resolvedImage[1];

				 int width = redChannel.cols;
				 int height = redChannel.rows;
				 int nElements = width*height;

				 // Calculating interpolated value for each matrix element
				 uchar* p1 = resolvedImage[2].data;
				 uchar* p2 = resolvedImage[0].data;

				 for (int i = 0; i < nElements; ++i)
				 {
					 if (tempValue >= 0)
					 {
						 p1[i] = (uchar)(incIntensity(p1[i]));
						 p2[i] = (uchar)(decIntensity(p2[i]));
					 }
					 else
					 {
						 p1[i] = (uchar)(decIntensity(p1[i]));
						 p2[i] = (uchar)(incIntensity(p2[i]));
					 }
				 }

				 // Merging the BGR channels 
				 std::vector < cv::Mat > arrayToMerge;
				 arrayToMerge.push_back(blueChannel);
				 arrayToMerge.push_back(greenChannel);
				 arrayToMerge.push_back(redChannel);

				 // Image with altered red abd blue channels
				 cv::Mat bgrAdjusted;
				 merge(arrayToMerge, bgrAdjusted);

				 // Convert image to HSV colour space and splitting layers for saturation adjustment
				 cv::Mat hsvImage;
				 cv::Mat hsvResolved[3];
				 cvtColor(bgrAdjusted, hsvImage, CV_BGR2HSV);
				 split(hsvImage, hsvResolved);

				 // Adjusting saturation
				 cv::Mat hNew, sNew, vNew;
				 hNew = hsvResolved[0];
				 sNew = hsvResolved[1]; // +(10 * tempValue);
				 vNew = hsvResolved[2];

				 // Calculate interpolated value for saturation layer
				 uchar* p3 = sNew.data;

				 for (int i = 0; i < nElements; ++i)
				 {
					 if (tempValue >= 0)
					 {
						 p3[i] = (uchar)(incIntensity(p3[i]));
					 }
					 else
					 {
						 p3[i] = (uchar)(decIntensity(p3[i]));
					 }	 
				 }

				 // Merging the HSV channels 
				 std::vector < cv::Mat > arrayToMergeHSV;
				 arrayToMergeHSV.push_back(hNew);
				 arrayToMergeHSV.push_back(sNew);
				 arrayToMergeHSV.push_back(vNew);

				 // Converting the image back to BGR
				 cv::Mat hsvAdjusted;			// Image with altered saturation channel
				 merge(arrayToMergeHSV, hsvAdjusted);
				 cvtColor(hsvAdjusted, tempAdjusted, CV_HSV2BGR);
				 refreshPicBox(tempAdjusted);
				 return 0;
			 }

			 //refresh the image in the picture box
			 int refreshPicBox(cv::Mat displayImage)
			 {
				 System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
				 System::IntPtr ptr(displayImage.ptr());
				 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(displayImage.cols, displayImage.rows, displayImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
				 System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
				 graphics->DrawImage(b, rect);
				 return 0;
			 }


};

}
