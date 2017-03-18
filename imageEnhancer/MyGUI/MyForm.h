#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "spline.h"
#include "math.h"
#include <msclr\marshal_cppstd.h>
#include"exif.h"
#include"exif.cpp"

//#include "pcdushantha.cpp"

cv::Mat editedImage;
cv::Mat tempAdjusted;

int Sharpsigma = 0;
int Sharpweight = 0;

std::string sharpningType;

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
	private: System::Windows::Forms::PictureBox^  RGBHist;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  shapning;
	private: System::Windows::Forms::Label^  sharpninglabel;
	private: System::Windows::Forms::Label^  weight;
	private: System::Windows::Forms::Label^  sigmaValue;
	private: System::Windows::Forms::TrackBar^  weightTrack;

	private: System::Windows::Forms::TrackBar^  sigmatrack;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private: System::Windows::Forms::Button^  EXIF;








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
			this->RGBHist = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->shapning = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->sharpninglabel = (gcnew System::Windows::Forms::Label());
			this->weight = (gcnew System::Windows::Forms::Label());
			this->sigmaValue = (gcnew System::Windows::Forms::Label());
			this->weightTrack = (gcnew System::Windows::Forms::TrackBar());
			this->sigmatrack = (gcnew System::Windows::Forms::TrackBar());
			this->EXIF = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RGBHist))->BeginInit();
			this->shapning->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->weightTrack))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sigmatrack))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(12, 4, 0, 4);
			this->menuStrip1->Size = System::Drawing::Size(2849, 44);
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
			this->fileToolStripMenuItem->Size = System::Drawing::Size(64, 36);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// importToolStripMenuItem
			// 
			this->importToolStripMenuItem->Name = L"importToolStripMenuItem";
			this->importToolStripMenuItem->Size = System::Drawing::Size(186, 38);
			this->importToolStripMenuItem->Text = L"Import";
			this->importToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::importToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(186, 38);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(24, 52);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1280, 923);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(1420, 169);
			this->trackBar1->Margin = System::Windows::Forms::Padding(6);
			this->trackBar1->Maximum = 5;
			this->trackBar1->Minimum = -5;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(332, 90);
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
			this->label1->Location = System::Drawing::Point(1494, 131);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(188, 35);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Temperature ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(1530, 356);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 31);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Colour";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Blue;
			this->label3->Location = System::Drawing::Point(1368, 169);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 27);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Cold";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(1744, 169);
			this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 27);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Warm";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->tempApply);
			this->panel1->Location = System::Drawing::Point(1352, 117);
			this->panel1->Margin = System::Windows::Forms::Padding(6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(476, 204);
			this->panel1->TabIndex = 8;
			// 
			// tempApply
			// 
			this->tempApply->Location = System::Drawing::Point(150, 135);
			this->tempApply->Margin = System::Windows::Forms::Padding(6);
			this->tempApply->Name = L"tempApply";
			this->tempApply->Size = System::Drawing::Size(160, 46);
			this->tempApply->TabIndex = 0;
			this->tempApply->Text = L"Apply";
			this->tempApply->UseVisualStyleBackColor = true;
			this->tempApply->Click += gcnew System::EventHandler(this, &MyForm::tempApply_Click);
			// 
			// RGBHist
			// 
			this->RGBHist->Location = System::Drawing::Point(1889, 117);
			this->RGBHist->Name = L"RGBHist";
			this->RGBHist->Size = System::Drawing::Size(800, 300);
			this->RGBHist->TabIndex = 9;
			this->RGBHist->TabStop = false;
			this->RGBHist->Click += gcnew System::EventHandler(this, &MyForm::RGBHist_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(2107, 79);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(200, 35);
			this->label5->TabIndex = 10;
			this->label5->Text = L"RGB Histogram";
			// 
			// shapning
			// 
			this->shapning->Controls->Add(this->comboBox1);
			this->shapning->Controls->Add(this->label9);
			this->shapning->Controls->Add(this->label8);
			this->shapning->Controls->Add(this->label7);
			this->shapning->Controls->Add(this->label6);
			this->shapning->Controls->Add(this->sharpninglabel);
			this->shapning->Controls->Add(this->weight);
			this->shapning->Controls->Add(this->sigmaValue);
			this->shapning->Controls->Add(this->weightTrack);
			this->shapning->Controls->Add(this->sigmatrack);
			this->shapning->Location = System::Drawing::Point(1373, 437);
			this->shapning->Name = L"shapning";
			this->shapning->Size = System::Drawing::Size(510, 312);
			this->shapning->TabIndex = 11;
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Gaussian", L"Luminance" });
			this->comboBox1->Location = System::Drawing::Point(194, 9);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(306, 33);
			this->comboBox1->TabIndex = 12;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(362, 254);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(36, 25);
			this->label9->TabIndex = 8;
			this->label9->Text = L"10";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(362, 139);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(36, 25);
			this->label8->TabIndex = 7;
			this->label8->Text = L"16";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(77, 254);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(24, 25);
			this->label7->TabIndex = 6;
			this->label7->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(77, 139);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"0";
			// 
			// sharpninglabel
			// 
			this->sharpninglabel->AutoSize = true;
			this->sharpninglabel->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sharpninglabel->Location = System::Drawing::Point(4, 4);
			this->sharpninglabel->Name = L"sharpninglabel";
			this->sharpninglabel->Size = System::Drawing::Size(143, 35);
			this->sharpninglabel->TabIndex = 4;
			this->sharpninglabel->Text = L"Sharpness";
			// 
			// weight
			// 
			this->weight->AutoSize = true;
			this->weight->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->weight->Location = System::Drawing::Point(166, 167);
			this->weight->Name = L"weight";
			this->weight->Size = System::Drawing::Size(115, 35);
			this->weight->TabIndex = 3;
			this->weight->Text = L"WEIGHT";
			// 
			// sigmaValue
			// 
			this->sigmaValue->AutoSize = true;
			this->sigmaValue->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sigmaValue->Location = System::Drawing::Point(188, 60);
			this->sigmaValue->Name = L"sigmaValue";
			this->sigmaValue->Size = System::Drawing::Size(93, 35);
			this->sigmaValue->TabIndex = 2;
			this->sigmaValue->Text = L"SIGMA";
			// 
			// weightTrack
			// 
			this->weightTrack->Location = System::Drawing::Point(66, 205);
			this->weightTrack->Name = L"weightTrack";
			this->weightTrack->Size = System::Drawing::Size(332, 90);
			this->weightTrack->TabIndex = 1;
			this->weightTrack->Scroll += gcnew System::EventHandler(this, &MyForm::weightTrack_Scroll);
			// 
			// sigmatrack
			// 
			this->sigmatrack->Location = System::Drawing::Point(66, 98);
			this->sigmatrack->Maximum = 16;
			this->sigmatrack->Name = L"sigmatrack";
			this->sigmatrack->Size = System::Drawing::Size(332, 90);
			this->sigmatrack->TabIndex = 0;
			this->sigmatrack->Scroll += gcnew System::EventHandler(this, &MyForm::sigmatrack_Scroll);
			// 
			// EXIF
			// 
			this->EXIF->Location = System::Drawing::Point(2020, 508);
			this->EXIF->Name = L"EXIF";
			this->EXIF->Size = System::Drawing::Size(238, 48);
			this->EXIF->TabIndex = 13;
			this->EXIF->Text = L"EXIF Data";
			this->EXIF->UseVisualStyleBackColor = true;
			this->EXIF->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::EXIF_MouseClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2849, 1310);
			this->Controls->Add(this->EXIF);
			this->Controls->Add(this->shapning);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->RGBHist);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RGBHist))->EndInit();
			this->shapning->ResumeLayout(false);
			this->shapning->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->weightTrack))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sigmatrack))->EndInit();
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
			refreshHistBox(Histogram(&editedImage));
		}
	}
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		// Acquire track bar value
		int trackBarValue = trackBar1->Value;

		// Initiate a Mat to save the cache.jpg image
		cv::Mat mainImage;
		mainImage = editedImage;
		colourTempAdjustment(&mainImage, trackBarValue);
		refreshHistBox(Histogram(&editedImage));
		tempApply->Enabled = true;
	}

	private: System::Void sigmatrack_Scroll(System::Object^  sender, System::EventArgs^  e) {

		// Acquire track bar value
		Sharpsigma = sigmatrack->Value;

		// Initiate a Mat to save the cache.jpg image
		cv::Mat mainImage;
		mainImage = editedImage;

		if (sharpningType == "Gaussian") {

			GaussianSharpning(&mainImage, &editedImage, Sharpsigma, Sharpweight);
		}

		else if (sharpningType == "Luminance") {

			LuminanceSharpning(&mainImage, &editedImage, Sharpsigma, Sharpweight);

		}
		refreshHistBox(Histogram(&mainImage));
		
			 }
	private: System::Void weightTrack_Scroll(System::Object^  sender, System::EventArgs^  e ) {

		// Acquire track bar value
		Sharpweight = weightTrack->Value;

		// Initiate a Mat to save the cache.jpg image
		cv::Mat mainImage;
		mainImage = editedImage;

		if (sharpningType == "Gaussian") {

			GaussianSharpning(&mainImage, &editedImage, Sharpsigma, Sharpweight);
		}

		else if(sharpningType == "Luminance") {
		
			LuminanceSharpning(&mainImage, &editedImage, Sharpsigma, Sharpweight);
		
		}
		

		refreshHistBox(Histogram(&mainImage));

		
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


			 int GaussianSharpning(cv::Mat* mainImage, cv::Mat* editedImage, int Gvalue, int Wvalue) {

				  cv::Mat Gimage, Simage;
				

				  if (Gvalue == 0 || Wvalue == 0) {  *mainImage = *editedImage  ; refreshPicBox(*mainImage); return 0; }
					
					
				  else {

					  GaussianBlur(*editedImage,Gimage, cv::Size(0, 0), Gvalue);

					  addWeighted(*editedImage, (Wvalue + 1), Gimage, -Wvalue, 0, Simage);
					  *mainImage = Simage;
					  refreshPicBox(*mainImage);
					  return  0;
				  }

			 }

			 int LuminanceSharpning(cv::Mat* mainImage,  cv::Mat* editedImage,int Gvalue, int Wvalue) {

				 if (Gvalue == 0 || Wvalue == 0) { *mainImage = *editedImage; refreshPicBox(*mainImage); return 0; }

				 else {
					 cv::Mat dst , Limage;

					 cvtColor(*editedImage, dst, cv::COLOR_BGR2YUV);
					 /// Separate the image in 3 places ( B, G and R )
					 std::vector<cv::Mat> yuv_planes;
			
					 split(dst, yuv_planes);
					
					 cv::Mat Y0;

					 GaussianBlur(yuv_planes[0], Limage, cv::Size(0, 0), Gvalue);

					
					 addWeighted(yuv_planes[0], (Wvalue + 1), Limage, -Wvalue, 0, Y0);
					 yuv_planes[0] = Y0;
					 merge(yuv_planes, dst);

					
					 cvtColor(dst, Limage, cv::COLOR_YUV2BGR);

					 *mainImage = Limage;
					 
					 refreshPicBox(*mainImage);
					 return  0;
					
				 }
				


			 }

			 cv::Mat Histogram(cv::Mat* editedImage) {

				 cv::Mat dst;
				 cvtColor(*editedImage, dst, cv::COLOR_BGR2GRAY);


				 /// Separate the image in 3 places ( B, G and R )
				 std::vector<cv::Mat> bgr_planes;


				 split(*editedImage, bgr_planes);


				 /// Establish the number of bins
				 int histSize = 254;
				 int ShadowHistSize = 2.55 * 25;
				 int HighlightHistSize = 2.55 * 25;

				 /// Set the ranges ( for B,G,R) )
				 float range[] = { 1, 255 };
				 const float* histRange = { range };

				 float ShadowRange[] = { 0, 2.55 * 25 };
				 const float* ShadowHistRange = { ShadowRange };

				 float HighlightRange[] = { 2.55 * 75, 255 };
				 const float* HighlightHistRange = { HighlightRange };

				 bool uniform = true; bool accumulate = false;

				 cv::Mat b_hist, g_hist, r_hist, hist, shadowHist, highlightHist;

				// b_hist.setTo(cv::Scalar::all(0));
				// g_hist.setTo(cv::Scalar::all(0));
				// r_hist.setTo(cv::Scalar::all(0));

				 /// Compute the histograms:
				 calcHist(&bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
				 calcHist(&bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
				 calcHist(&bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
				 calcHist(&dst, 1, 0, cv::Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);
				 calcHist(&dst, 1, 0, cv::Mat(), shadowHist, 1, &ShadowHistSize, &ShadowHistRange, uniform, accumulate);
				 calcHist(&dst, 1, 0, cv::Mat(), highlightHist, 1, &HighlightHistSize, &HighlightHistRange, uniform, accumulate);


				 // Draw the histograms for B, G and R
				 int hist_w = 800; int hist_h = 300;
				 int bin_w = cvRound((double)hist_w / histSize);
				 int bin_Sw = cvRound((double)hist_w / ShadowHistSize);
				 int bin_Hw = cvRound((double)hist_w / HighlightHistSize);

				 cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(255, 255, 255));

				 cv::Mat histnew(hist_h, hist_w, CV_8UC3, cv::Scalar(255, 255, 255));

				 cv::Mat ShadowHist(hist_h, hist_w, CV_8UC3, cv::Scalar(255, 255, 255));
				 cv::Mat HighlightHist(hist_h, hist_w, CV_8UC3, cv::Scalar(255, 255, 255));


				 /// Normalize the result to [ 0, histImage.rows ]
				 normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
				 normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
				 normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
				 normalize(hist, hist, 0, histnew.rows, cv::NORM_MINMAX, -1, cv::Mat());
				 normalize(shadowHist, shadowHist, 0, ShadowHist.rows, cv::NORM_MINMAX, -1, cv::Mat());
				 normalize(highlightHist, highlightHist, 0, HighlightHist.rows, cv::NORM_MINMAX, -1, cv::Mat());
				 

				 /// Draw for each channel
				 for (int i = 1; i < histSize; i++)
				 {
					 line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
						 cv::Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
						 cv::Scalar(255, 0, 0), 2, cv::LINE_AA, 0);
					 line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
						 cv::Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
						 cv::Scalar(80, 200, 80), 2, cv::LINE_AA, 0);
					 line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
						 cv::Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
						 cv::Scalar(0, 0, 255), 2 ,cv::LINE_AA, 0);


					 line(histnew, cv::Point(bin_w*(i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
						 cv::Point(bin_w*(i), hist_h - cvRound(hist.at<float>(i))),
						 cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);




				 }
				 for (int i = 1; i < ShadowHistSize; i++)
				 {

					 line(ShadowHist, cv::Point(bin_Sw*(i - 1), hist_h - cvRound(shadowHist.at<float>(i - 1))),
						 cv::Point(bin_Sw*(i), hist_h - cvRound(shadowHist.at<float>(i))),
						 cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

				 }

				 for (int i = 1; i < HighlightHistSize; i++)
				 {

					 line(HighlightHist, cv::Point(bin_Sw*(i - 1), hist_h - cvRound(highlightHist.at<float>(i - 1))),
						 cv::Point(bin_Sw*(i), hist_h - cvRound(highlightHist.at<float>(i))),
						 cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

				 }


				 return histImage;
				 /// Display
				

			 }

			 int metadata() {
				 MessageBox::Show("META DATA");
				 FILE *fp = fopen("cache.jpg", "rb");
				 if (!fp) {
					 MessageBox::Show("Can't open file");
					 return -1;
				 }
				 fseek(fp, 0, SEEK_END);
				 unsigned long fsize = ftell(fp);
				 rewind(fp);
				 unsigned char *buf = new unsigned char[fsize];
				 if (fread(buf, 1, fsize, fp) != fsize) {
					 MessageBox::Show("Can't read file");
					 delete[] buf;
					 return -2;
				 }
				 fclose(fp);

				 // Parse EXIF
				 easyexif::EXIFInfo result;
				 int code = result.parseFrom(buf, fsize);
				 delete[] buf;
				 if (code) {
					 MessageBox::Show("Error parsing EXIF");
					 return -3;
				 }
				 
				 MessageBox::Show("Camera Make  " );
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

			 int refreshHistBox(cv::Mat displayImage)
			 {
				 System::Drawing::Graphics^ graphics = RGBHist->CreateGraphics();
				 System::IntPtr ptr(displayImage.ptr());
				 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(displayImage.cols, displayImage.rows, displayImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
				 System::Drawing::RectangleF rect(0, 0, RGBHist->Width, RGBHist->Height);
				 graphics->DrawImage(b, rect);
				 return 0;
			 }


private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void RGBHist_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	msclr::interop::marshal_context context;
	sharpningType = context.marshal_as<std::string>(comboBox1->SelectedItem->ToString());
}

private: System::Void EXIF_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
	int metadata();


}

};



}
