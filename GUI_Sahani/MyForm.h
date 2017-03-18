#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>


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
	private: System::Windows::Forms::Label^  labelLuminanceHigh;
	private: System::Windows::Forms::Label^  labelLuminanceLow;
	private: System::Windows::Forms::Label^  labelLuminance;
	private: System::Windows::Forms::TrackBar^  trackBarLuminance;
	private: System::Windows::Forms::Panel^  panelLuminance;
	private: System::Windows::Forms::Button^  luminanceApply;

	private: System::Windows::Forms::Label^  labelContrastHigh;
	private: System::Windows::Forms::Label^  labelContrastLow;
	private: System::Windows::Forms::Label^  labelContrast;
	private: System::Windows::Forms::TrackBar^  trackBarContrast;
	private: System::Windows::Forms::Panel^  panelContrast;
	private: System::Windows::Forms::Button^  contrastApply;

	private: System::Windows::Forms::Label^  labelExposureHigh;
	private: System::Windows::Forms::Label^  labelExposureLow;
	private: System::Windows::Forms::Label^  labelExposure;
	private: System::Windows::Forms::TrackBar^  trackBarExposure;
	private: System::Windows::Forms::Panel^  panelExposure;
	private: System::Windows::Forms::Button^  exposureApply;

	private: System::Windows::Forms::Label^  labelHueHigh;
	private: System::Windows::Forms::Label^  labelHueLow;
	private: System::Windows::Forms::Label^  labelHue;
	private: System::Windows::Forms::TrackBar^  trackBarHue;
	private: System::Windows::Forms::Panel^  panelHue;
	private: System::Windows::Forms::Button^  hueApply;

	private: System::Windows::Forms::Label^  labelSaturationHigh;
	private: System::Windows::Forms::Label^  labelSaturationLow;
	private: System::Windows::Forms::Label^  labelSaturation;
	private: System::Windows::Forms::TrackBar^  trackBarSaturation;
	private: System::Windows::Forms::Panel^  panelSaturation;
	private: System::Windows::Forms::Button^  saturationApply;

	private: System::Windows::Forms::Label^  labelValueHigh; 
	private: System::Windows::Forms::Label^  labelValueLow;
	private: System::Windows::Forms::Label^  labelValue;
	private: System::Windows::Forms::TrackBar^  trackBarValue;
	private: System::Windows::Forms::Panel^  panelValue;
	private: System::Windows::Forms::Button^  valueApply;

	private: System::Windows::Forms::Button^  ContrastAutoAdjust;
	private: System::Windows::Forms::Button^  UNDO;

	private: System::Windows::Forms::TrackBar^  trackBar7;
	private: System::Windows::Forms::Button^  ExposureAutoAdjust;

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
			this->labelLuminanceHigh = (gcnew System::Windows::Forms::Label());
			this->labelLuminanceLow = (gcnew System::Windows::Forms::Label());
			this->labelLuminance = (gcnew System::Windows::Forms::Label());
			this->trackBarLuminance = (gcnew System::Windows::Forms::TrackBar());
			this->panelLuminance = (gcnew System::Windows::Forms::Panel());
			this->luminanceApply = (gcnew System::Windows::Forms::Button());
			this->labelContrastHigh = (gcnew System::Windows::Forms::Label());
			this->labelContrastLow = (gcnew System::Windows::Forms::Label());
			this->labelContrast = (gcnew System::Windows::Forms::Label());
			this->trackBarContrast = (gcnew System::Windows::Forms::TrackBar());
			this->panelContrast = (gcnew System::Windows::Forms::Panel());
			this->contrastApply = (gcnew System::Windows::Forms::Button());
			this->labelExposureHigh = (gcnew System::Windows::Forms::Label());
			this->labelExposureLow = (gcnew System::Windows::Forms::Label());
			this->labelExposure = (gcnew System::Windows::Forms::Label());
			this->trackBarExposure = (gcnew System::Windows::Forms::TrackBar());
			this->panelExposure = (gcnew System::Windows::Forms::Panel());
			this->exposureApply = (gcnew System::Windows::Forms::Button());
			this->labelHueHigh = (gcnew System::Windows::Forms::Label());
			this->labelHueLow = (gcnew System::Windows::Forms::Label());
			this->labelHue = (gcnew System::Windows::Forms::Label());
			this->panelHue = (gcnew System::Windows::Forms::Panel());
			this->hueApply = (gcnew System::Windows::Forms::Button());
			this->trackBarHue = (gcnew System::Windows::Forms::TrackBar());
			this->labelSaturationHigh = (gcnew System::Windows::Forms::Label());
			this->labelSaturationLow = (gcnew System::Windows::Forms::Label());
			this->labelSaturation = (gcnew System::Windows::Forms::Label());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->panelSaturation = (gcnew System::Windows::Forms::Panel());
			this->saturationApply = (gcnew System::Windows::Forms::Button());
			this->labelValueHigh = (gcnew System::Windows::Forms::Label());
			this->labelValueLow = (gcnew System::Windows::Forms::Label());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->trackBarValue = (gcnew System::Windows::Forms::TrackBar());
			this->panelValue = (gcnew System::Windows::Forms::Panel());
			this->valueApply = (gcnew System::Windows::Forms::Button());
			this->trackBarSaturation = (gcnew System::Windows::Forms::TrackBar());
			this->ContrastAutoAdjust = (gcnew System::Windows::Forms::Button());
			this->UNDO = (gcnew System::Windows::Forms::Button());
			this->ExposureAutoAdjust = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarLuminance))->BeginInit();
			this->panelLuminance->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarContrast))->BeginInit();
			this->panelContrast->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarExposure))->BeginInit();
			this->panelExposure->SuspendLayout();
			this->panelHue->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarHue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->BeginInit();
			this->panelSaturation->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarValue))->BeginInit();
			this->panelValue->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSaturation))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1685, 28);
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
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// importToolStripMenuItem
			// 
			this->importToolStripMenuItem->Name = L"importToolStripMenuItem";
			this->importToolStripMenuItem->Size = System::Drawing::Size(129, 26);
			this->importToolStripMenuItem->Text = L"Import";
			this->importToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::importToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(129, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 44);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(853, 591);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// labelLuminanceHigh
			// 
			this->labelLuminanceHigh->AutoSize = true;
			this->labelLuminanceHigh->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelLuminanceHigh->ForeColor = System::Drawing::Color::Red;
			this->labelLuminanceHigh->Location = System::Drawing::Point(1163, 88);
			this->labelLuminanceHigh->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelLuminanceHigh->Name = L"labelLuminanceHigh";
			this->labelLuminanceHigh->Size = System::Drawing::Size(36, 18);
			this->labelLuminanceHigh->TabIndex = 12;
			this->labelLuminanceHigh->Text = L"High";
			// 
			// labelLuminanceLow
			// 
			this->labelLuminanceLow->AutoSize = true;
			this->labelLuminanceLow->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelLuminanceLow->ForeColor = System::Drawing::Color::Blue;
			this->labelLuminanceLow->Location = System::Drawing::Point(912, 88);
			this->labelLuminanceLow->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelLuminanceLow->Name = L"labelLuminanceLow";
			this->labelLuminanceLow->Size = System::Drawing::Size(33, 18);
			this->labelLuminanceLow->TabIndex = 11;
			this->labelLuminanceLow->Text = L"Low";
			// 
			// labelLuminance
			// 
			this->labelLuminance->AutoSize = true;
			this->labelLuminance->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelLuminance->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelLuminance->Location = System::Drawing::Point(105, 4);
			this->labelLuminance->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelLuminance->Name = L"labelLuminance";
			this->labelLuminance->Size = System::Drawing::Size(97, 23);
			this->labelLuminance->TabIndex = 10;
			this->labelLuminance->Text = L"Luminance";
			// 
			// trackBarLuminance
			// 
			this->trackBarLuminance->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->trackBarLuminance->Location = System::Drawing::Point(44, 25);
			this->trackBarLuminance->Margin = System::Windows::Forms::Padding(4);
			this->trackBarLuminance->Maximum = 255;
			this->trackBarLuminance->Minimum = -255;
			this->trackBarLuminance->Name = L"trackBarLuminance";
			this->trackBarLuminance->Size = System::Drawing::Size(221, 56);
			this->trackBarLuminance->TabIndex = 9;
			this->trackBarLuminance->TickFrequency = 0;
			this->trackBarLuminance->Scroll += gcnew System::EventHandler(this, &MyForm::Luminance_Scroll);
			// 
			// panelLuminance
			// 
			this->panelLuminance->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panelLuminance->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelLuminance->Controls->Add(this->luminanceApply);
			this->panelLuminance->Controls->Add(this->labelLuminance);
			this->panelLuminance->Controls->Add(this->trackBarLuminance);
			this->panelLuminance->Location = System::Drawing::Point(901, 55);
			this->panelLuminance->Margin = System::Windows::Forms::Padding(4);
			this->panelLuminance->Name = L"panelLuminance";
			this->panelLuminance->Size = System::Drawing::Size(446, 67);
			this->panelLuminance->TabIndex = 13;
			// 
			// luminanceApply
			// 
			this->luminanceApply->Location = System::Drawing::Point(323, 25);
			this->luminanceApply->Margin = System::Windows::Forms::Padding(4);
			this->luminanceApply->Name = L"luminanceApply";
			this->luminanceApply->Size = System::Drawing::Size(107, 30);
			this->luminanceApply->TabIndex = 0;
			this->luminanceApply->Text = L"Apply";
			this->luminanceApply->UseVisualStyleBackColor = true;
			this->luminanceApply->Click += gcnew System::EventHandler(this, &MyForm::Luminance_Click);
			// 
			// labelContrastHigh
			// 
			this->labelContrastHigh->AutoSize = true;
			this->labelContrastHigh->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelContrastHigh->ForeColor = System::Drawing::Color::Red;
			this->labelContrastHigh->Location = System::Drawing::Point(1163, 238);
			this->labelContrastHigh->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelContrastHigh->Name = L"labelContrastHigh";
			this->labelContrastHigh->Size = System::Drawing::Size(36, 18);
			this->labelContrastHigh->TabIndex = 22;
			this->labelContrastHigh->Text = L"High";
			// 
			// labelContrastLow
			// 
			this->labelContrastLow->AutoSize = true;
			this->labelContrastLow->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelContrastLow->ForeColor = System::Drawing::Color::Blue;
			this->labelContrastLow->Location = System::Drawing::Point(912, 238);
			this->labelContrastLow->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelContrastLow->Name = L"labelContrastLow";
			this->labelContrastLow->Size = System::Drawing::Size(33, 18);
			this->labelContrastLow->TabIndex = 21;
			this->labelContrastLow->Text = L"Low";
			// 
			// labelContrast
			// 
			this->labelContrast->AutoSize = true;
			this->labelContrast->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelContrast->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelContrast->Location = System::Drawing::Point(114, 4);
			this->labelContrast->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelContrast->Name = L"labelContrast";
			this->labelContrast->Size = System::Drawing::Size(76, 23);
			this->labelContrast->TabIndex = 20;
			this->labelContrast->Text = L"Contrast";
			// 
			// trackBarContrast
			// 
			this->trackBarContrast->BackColor = System::Drawing::SystemColors::Control;
			this->trackBarContrast->Location = System::Drawing::Point(947, 238);
			this->trackBarContrast->Margin = System::Windows::Forms::Padding(4);
			this->trackBarContrast->Maximum = 100;
			this->trackBarContrast->Name = L"trackBarContrast";
			this->trackBarContrast->Size = System::Drawing::Size(221, 56);
			this->trackBarContrast->TabIndex = 19;
			this->trackBarContrast->TickFrequency = 0;
			this->trackBarContrast->Value = 50;
			this->trackBarContrast->Scroll += gcnew System::EventHandler(this, &MyForm::Contrast_Scroll);
			// 
			// panelContrast
			// 
			this->panelContrast->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panelContrast->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelContrast->Controls->Add(this->contrastApply);
			this->panelContrast->Controls->Add(this->labelContrast);
			this->panelContrast->Location = System::Drawing::Point(901, 205);
			this->panelContrast->Margin = System::Windows::Forms::Padding(4);
			this->panelContrast->Name = L"panelContrast";
			this->panelContrast->Size = System::Drawing::Size(446, 67);
			this->panelContrast->TabIndex = 23;
			// 
			// contrastApply
			// 
			this->contrastApply->Location = System::Drawing::Point(323, 19);
			this->contrastApply->Margin = System::Windows::Forms::Padding(4);
			this->contrastApply->Name = L"contrastApply";
			this->contrastApply->Size = System::Drawing::Size(107, 30);
			this->contrastApply->TabIndex = 0;
			this->contrastApply->Text = L"Apply";
			this->contrastApply->UseVisualStyleBackColor = true;
			this->contrastApply->Click += gcnew System::EventHandler(this, &MyForm::Contrast_Click);
			// 
			// labelExposureHigh
			// 
			this->labelExposureHigh->AutoSize = true;
			this->labelExposureHigh->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelExposureHigh->ForeColor = System::Drawing::Color::Red;
			this->labelExposureHigh->Location = System::Drawing::Point(1163, 163);
			this->labelExposureHigh->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelExposureHigh->Name = L"labelExposureHigh";
			this->labelExposureHigh->Size = System::Drawing::Size(36, 18);
			this->labelExposureHigh->TabIndex = 17;
			this->labelExposureHigh->Text = L"High";
			// 
			// labelExposureLow
			// 
			this->labelExposureLow->AutoSize = true;
			this->labelExposureLow->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelExposureLow->ForeColor = System::Drawing::Color::Blue;
			this->labelExposureLow->Location = System::Drawing::Point(912, 163);
			this->labelExposureLow->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelExposureLow->Name = L"labelExposureLow";
			this->labelExposureLow->Size = System::Drawing::Size(33, 18);
			this->labelExposureLow->TabIndex = 16;
			this->labelExposureLow->Text = L"Low";
			// 
			// labelExposure
			// 
			this->labelExposure->AutoSize = true;
			this->labelExposure->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelExposure->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelExposure->Location = System::Drawing::Point(114, 4);
			this->labelExposure->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelExposure->Name = L"labelExposure";
			this->labelExposure->Size = System::Drawing::Size(83, 23);
			this->labelExposure->TabIndex = 15;
			this->labelExposure->Text = L"Exposure";
			// 
			// trackBarExposure
			// 
			this->trackBarExposure->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->trackBarExposure->Location = System::Drawing::Point(947, 163);
			this->trackBarExposure->Margin = System::Windows::Forms::Padding(4);
			this->trackBarExposure->Maximum = 100;
			this->trackBarExposure->Name = L"trackBarExposure";
			this->trackBarExposure->Size = System::Drawing::Size(221, 56);
			this->trackBarExposure->TabIndex = 14;
			this->trackBarExposure->TickFrequency = 0;
			this->trackBarExposure->Value = 50;
			this->trackBarExposure->Scroll += gcnew System::EventHandler(this, &MyForm::Exposure_Scroll);
			// 
			// panelExposure
			// 
			this->panelExposure->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panelExposure->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelExposure->Controls->Add(this->exposureApply);
			this->panelExposure->Controls->Add(this->labelExposure);
			this->panelExposure->Location = System::Drawing::Point(901, 130);
			this->panelExposure->Margin = System::Windows::Forms::Padding(4);
			this->panelExposure->Name = L"panelExposure";
			this->panelExposure->Size = System::Drawing::Size(446, 67);
			this->panelExposure->TabIndex = 18;
			// 
			// exposureApply
			// 
			this->exposureApply->Location = System::Drawing::Point(323, 19);
			this->exposureApply->Margin = System::Windows::Forms::Padding(4);
			this->exposureApply->Name = L"exposureApply";
			this->exposureApply->Size = System::Drawing::Size(107, 30);
			this->exposureApply->TabIndex = 0;
			this->exposureApply->Text = L"Apply";
			this->exposureApply->UseVisualStyleBackColor = true;
			this->exposureApply->Click += gcnew System::EventHandler(this, &MyForm::Exposure_Click);
			// 
			// labelHueHigh
			// 
			this->labelHueHigh->AutoSize = true;
			this->labelHueHigh->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelHueHigh->ForeColor = System::Drawing::Color::Red;
			this->labelHueHigh->Location = System::Drawing::Point(1163, 313);
			this->labelHueHigh->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelHueHigh->Name = L"labelHueHigh";
			this->labelHueHigh->Size = System::Drawing::Size(36, 18);
			this->labelHueHigh->TabIndex = 28;
			this->labelHueHigh->Text = L"High";
			// 
			// labelHueLow
			// 
			this->labelHueLow->AutoSize = true;
			this->labelHueLow->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelHueLow->ForeColor = System::Drawing::Color::Blue;
			this->labelHueLow->Location = System::Drawing::Point(912, 313);
			this->labelHueLow->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelHueLow->Name = L"labelHueLow";
			this->labelHueLow->Size = System::Drawing::Size(33, 18);
			this->labelHueLow->TabIndex = 27;
			this->labelHueLow->Text = L"Low";
			// 
			// labelHue
			// 
			this->labelHue->AutoSize = true;
			this->labelHue->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelHue->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelHue->Location = System::Drawing::Point(134, 4);
			this->labelHue->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelHue->Name = L"labelHue";
			this->labelHue->Size = System::Drawing::Size(42, 23);
			this->labelHue->TabIndex = 26;
			this->labelHue->Text = L"Hue";
			// 
			// panelHue
			// 
			this->panelHue->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panelHue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelHue->Controls->Add(this->hueApply);
			this->panelHue->Controls->Add(this->labelHue);
			this->panelHue->Controls->Add(this->trackBarHue);
			this->panelHue->Location = System::Drawing::Point(901, 280);
			this->panelHue->Margin = System::Windows::Forms::Padding(4);
			this->panelHue->Name = L"panelHue";
			this->panelHue->Size = System::Drawing::Size(446, 67);
			this->panelHue->TabIndex = 29;
			// 
			// hueApply
			// 
			this->hueApply->Location = System::Drawing::Point(323, 19);
			this->hueApply->Margin = System::Windows::Forms::Padding(4);
			this->hueApply->Name = L"hueApply";
			this->hueApply->Size = System::Drawing::Size(107, 30);
			this->hueApply->TabIndex = 0;
			this->hueApply->Text = L"Apply";
			this->hueApply->UseVisualStyleBackColor = true;
			this->hueApply->Click += gcnew System::EventHandler(this, &MyForm::Hue_Click);
			// 
			// trackBarHue
			// 
			this->trackBarHue->BackColor = System::Drawing::SystemColors::Control;
			this->trackBarHue->Location = System::Drawing::Point(44, 31);
			this->trackBarHue->Margin = System::Windows::Forms::Padding(4);
			this->trackBarHue->Maximum = 360;
			this->trackBarHue->Minimum = -360;
			this->trackBarHue->Name = L"trackBarHue";
			this->trackBarHue->Size = System::Drawing::Size(221, 56);
			this->trackBarHue->TabIndex = 30;
			this->trackBarHue->TickFrequency = 0;
			this->trackBarHue->Scroll += gcnew System::EventHandler(this, &MyForm::Hue_Scroll);
			// 
			// labelSaturationHigh
			// 
			this->labelSaturationHigh->AutoSize = true;
			this->labelSaturationHigh->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSaturationHigh->ForeColor = System::Drawing::Color::Red;
			this->labelSaturationHigh->Location = System::Drawing::Point(1163, 388);
			this->labelSaturationHigh->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelSaturationHigh->Name = L"labelSaturationHigh";
			this->labelSaturationHigh->Size = System::Drawing::Size(36, 18);
			this->labelSaturationHigh->TabIndex = 34;
			this->labelSaturationHigh->Text = L"High";
			// 
			// labelSaturationLow
			// 
			this->labelSaturationLow->AutoSize = true;
			this->labelSaturationLow->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSaturationLow->ForeColor = System::Drawing::Color::Blue;
			this->labelSaturationLow->Location = System::Drawing::Point(912, 388);
			this->labelSaturationLow->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelSaturationLow->Name = L"labelSaturationLow";
			this->labelSaturationLow->Size = System::Drawing::Size(33, 18);
			this->labelSaturationLow->TabIndex = 33;
			this->labelSaturationLow->Text = L"Low";
			// 
			// labelSaturation
			// 
			this->labelSaturation->AutoSize = true;
			this->labelSaturation->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSaturation->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelSaturation->Location = System::Drawing::Point(105, 4);
			this->labelSaturation->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelSaturation->Name = L"labelSaturation";
			this->labelSaturation->Size = System::Drawing::Size(92, 23);
			this->labelSaturation->TabIndex = 32;
			this->labelSaturation->Text = L"Saturation";
			// 
			// trackBar7
			// 
			this->trackBar7->Location = System::Drawing::Point(947, 388);
			this->trackBar7->Margin = System::Windows::Forms::Padding(4);
			this->trackBar7->Maximum = 100;
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->Size = System::Drawing::Size(221, 56);
			this->trackBar7->TabIndex = 31;
			this->trackBar7->TickFrequency = 0;
			this->trackBar7->Value = 50;
			// 
			// panelSaturation
			// 
			this->panelSaturation->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panelSaturation->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelSaturation->Controls->Add(this->saturationApply);
			this->panelSaturation->Controls->Add(this->labelSaturation);
			this->panelSaturation->Location = System::Drawing::Point(901, 355);
			this->panelSaturation->Margin = System::Windows::Forms::Padding(4);
			this->panelSaturation->Name = L"panelSaturation";
			this->panelSaturation->Size = System::Drawing::Size(446, 67);
			this->panelSaturation->TabIndex = 35;
			// 
			// saturationApply
			// 
			this->saturationApply->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->saturationApply->Location = System::Drawing::Point(323, 19);
			this->saturationApply->Margin = System::Windows::Forms::Padding(4);
			this->saturationApply->Name = L"saturationApply";
			this->saturationApply->Size = System::Drawing::Size(107, 30);
			this->saturationApply->TabIndex = 0;
			this->saturationApply->Text = L"Apply";
			this->saturationApply->UseVisualStyleBackColor = true;
			this->saturationApply->Click += gcnew System::EventHandler(this, &MyForm::Saturation_Click);
			// 
			// labelValueHigh
			// 
			this->labelValueHigh->AutoSize = true;
			this->labelValueHigh->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelValueHigh->ForeColor = System::Drawing::Color::Red;
			this->labelValueHigh->Location = System::Drawing::Point(1163, 463);
			this->labelValueHigh->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelValueHigh->Name = L"labelValueHigh";
			this->labelValueHigh->Size = System::Drawing::Size(36, 18);
			this->labelValueHigh->TabIndex = 40;
			this->labelValueHigh->Text = L"High";
			// 
			// labelValueLow
			// 
			this->labelValueLow->AutoSize = true;
			this->labelValueLow->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelValueLow->ForeColor = System::Drawing::Color::Blue;
			this->labelValueLow->Location = System::Drawing::Point(912, 463);
			this->labelValueLow->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelValueLow->Name = L"labelValueLow";
			this->labelValueLow->Size = System::Drawing::Size(33, 18);
			this->labelValueLow->TabIndex = 39;
			this->labelValueLow->Text = L"Low";
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelValue->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelValue->Location = System::Drawing::Point(121, 4);
			this->labelValue->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(55, 23);
			this->labelValue->TabIndex = 38;
			this->labelValue->Text = L"Value";
			// 
			// trackBarValue
			// 
			this->trackBarValue->BackColor = System::Drawing::SystemColors::Control;
			this->trackBarValue->Location = System::Drawing::Point(947, 463);
			this->trackBarValue->Margin = System::Windows::Forms::Padding(4);
			this->trackBarValue->Maximum = 255;
			this->trackBarValue->Minimum = -255;
			this->trackBarValue->Name = L"trackBarValue";
			this->trackBarValue->Size = System::Drawing::Size(221, 56);
			this->trackBarValue->TabIndex = 37;
			this->trackBarValue->TickFrequency = 0;
			this->trackBarValue->Scroll += gcnew System::EventHandler(this, &MyForm::Value_Scroll);
			// 
			// panelValue
			// 
			this->panelValue->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panelValue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelValue->Controls->Add(this->valueApply);
			this->panelValue->Controls->Add(this->labelValue);
			this->panelValue->Location = System::Drawing::Point(901, 430);
			this->panelValue->Margin = System::Windows::Forms::Padding(4);
			this->panelValue->Name = L"panelValue";
			this->panelValue->Size = System::Drawing::Size(446, 67);
			this->panelValue->TabIndex = 41;
			// 
			// valueApply
			// 
			this->valueApply->Location = System::Drawing::Point(323, 19);
			this->valueApply->Margin = System::Windows::Forms::Padding(4);
			this->valueApply->Name = L"valueApply";
			this->valueApply->Size = System::Drawing::Size(107, 30);
			this->valueApply->TabIndex = 0;
			this->valueApply->Text = L"Apply";
			this->valueApply->UseVisualStyleBackColor = true;
			this->valueApply->Click += gcnew System::EventHandler(this, &MyForm::Value_Click);
			// 
			// trackBarSaturation
			// 
			this->trackBarSaturation->BackColor = System::Drawing::SystemColors::Control;
			this->trackBarSaturation->Location = System::Drawing::Point(947, 388);
			this->trackBarSaturation->Margin = System::Windows::Forms::Padding(4);
			this->trackBarSaturation->Maximum = 255;
			this->trackBarSaturation->Minimum = -255;
			this->trackBarSaturation->Name = L"trackBarSaturation";
			this->trackBarSaturation->Size = System::Drawing::Size(221, 56);
			this->trackBarSaturation->TabIndex = 36;
			this->trackBarSaturation->TickFrequency = 0;
			this->trackBarSaturation->Scroll += gcnew System::EventHandler(this, &MyForm::Saturation_Scroll);
			// 
			// ContrastAutoAdjust
			// 
			this->ContrastAutoAdjust->BackColor = System::Drawing::SystemColors::Info;
			this->ContrastAutoAdjust->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ContrastAutoAdjust->Location = System::Drawing::Point(901, 578);
			this->ContrastAutoAdjust->Name = L"ContrastAutoAdjust";
			this->ContrastAutoAdjust->Size = System::Drawing::Size(446, 34);
			this->ContrastAutoAdjust->TabIndex = 42;
			this->ContrastAutoAdjust->Text = L"Contrast Auto-adjust";
			this->ContrastAutoAdjust->UseVisualStyleBackColor = false;
			this->ContrastAutoAdjust->Click += gcnew System::EventHandler(this, &MyForm::ContrastAutoAdjust_Click);
			// 
			// UNDO
			// 
			this->UNDO->BackColor = System::Drawing::SystemColors::Highlight;
			this->UNDO->Location = System::Drawing::Point(1354, 31);
			this->UNDO->Name = L"UNDO";
			this->UNDO->Size = System::Drawing::Size(124, 38);
			this->UNDO->TabIndex = 43;
			this->UNDO->Text = L"UNDO";
			this->UNDO->UseVisualStyleBackColor = false;
			this->UNDO->Click += gcnew System::EventHandler(this, &MyForm::UNDO_Click);
			// 
			// ExposureAutoAdjust
			// 
			this->ExposureAutoAdjust->BackColor = System::Drawing::SystemColors::Info;
			this->ExposureAutoAdjust->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExposureAutoAdjust->Location = System::Drawing::Point(901, 529);
			this->ExposureAutoAdjust->Name = L"ExposureAutoAdjust";
			this->ExposureAutoAdjust->Size = System::Drawing::Size(446, 34);
			this->ExposureAutoAdjust->TabIndex = 44;
			this->ExposureAutoAdjust->Text = L"Exposure Auto-adjust";
			this->ExposureAutoAdjust->UseVisualStyleBackColor = false;
			this->ExposureAutoAdjust->Click += gcnew System::EventHandler(this, &MyForm::ExposureAutoAdjust_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1685, 838);
			this->Controls->Add(this->labelExposureHigh);
			this->Controls->Add(this->ExposureAutoAdjust);
			this->Controls->Add(this->UNDO);
			this->Controls->Add(this->ContrastAutoAdjust);
			this->Controls->Add(this->labelValueHigh);
			this->Controls->Add(this->labelValueLow);
			this->Controls->Add(this->trackBarValue);
			this->Controls->Add(this->panelValue);
			this->Controls->Add(this->trackBarSaturation);
			this->Controls->Add(this->labelSaturationHigh);
			this->Controls->Add(this->labelSaturationLow);
			this->Controls->Add(this->trackBar7);
			this->Controls->Add(this->panelSaturation);
			this->Controls->Add(this->labelHueHigh);
			this->Controls->Add(this->labelHueLow);
			this->Controls->Add(this->panelHue);
			this->Controls->Add(this->trackBarContrast);
			this->Controls->Add(this->labelContrastHigh);
			this->Controls->Add(this->labelContrastLow);
			this->Controls->Add(this->panelContrast);
			this->Controls->Add(this->labelExposureLow);
			this->Controls->Add(this->labelLuminanceHigh);
			this->Controls->Add(this->labelLuminanceLow);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panelLuminance);
			this->Controls->Add(this->trackBarExposure);
			this->Controls->Add(this->panelExposure);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarLuminance))->EndInit();
			this->panelLuminance->ResumeLayout(false);
			this->panelLuminance->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarContrast))->EndInit();
			this->panelContrast->ResumeLayout(false);
			this->panelContrast->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarExposure))->EndInit();
			this->panelExposure->ResumeLayout(false);
			this->panelExposure->PerformLayout();
			this->panelHue->ResumeLayout(false);
			this->panelHue->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarHue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->EndInit();
			this->panelSaturation->ResumeLayout(false);
			this->panelSaturation->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarValue))->EndInit();
			this->panelValue->ResumeLayout(false);
			this->panelValue->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSaturation))->EndInit();
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

	private: System::Void Luminance_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValueLuminance = trackBarLuminance->Value;				// Get Luminance slider value

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage.clone();
				 Luminance(&mainImage, trackBarValueLuminance);						// Call Luminance function
				 luminanceApply->Enabled = true;
	}
	private: System::Void Luminance_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted.clone();								// Luminance changes made permanent
				 luminanceApply->Enabled = false;
				 trackBarLuminance->Value = 0;										// Center slider
	}
	private: System::Void Exposure_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValueExposure = trackBarExposure->Value;				// Get Exposure slider value
				 int trackBarValueContrast = trackBarContrast->Value;				// Get Contrast slider value

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage.clone();
				 Exposure(&mainImage, trackBarValueExposure, trackBarValueContrast);	//Call Exposure function
				 exposureApply->Enabled = true;
	}
	private: System::Void Exposure_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted.clone();								// Exposure changes made permanent
				 exposureApply->Enabled = false;
				 trackBarExposure->Value = 50;										// Center slider
	}

	private: System::Void Contrast_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValueExposure = trackBarExposure->Value;				// Get Exposure slider value
				 int trackBarValueContrast = trackBarContrast->Value;				// Get Contrast slider value

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage.clone();
				 Contrast(&mainImage, trackBarValueExposure, trackBarValueContrast);	//Call Contrast function
				 contrastApply->Enabled = true;
	}
	private: System::Void Contrast_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted.clone();								// Contrast changes made permanent
				 contrastApply->Enabled = false;
				 trackBarContrast->Value = 50;										// Center slider
	}
	private: System::Void Hue_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValueHue = trackBarHue->Value;
				 int trackBarValueSaturation = trackBarSaturation->Value;
				 int trackBarValueValue = trackBarValue->Value;

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage.clone();
				 Hue(&mainImage, trackBarValueHue, trackBarValueSaturation, trackBarValueValue); //Call Hue function
				 hueApply->Enabled = true;
	}
	private: System::Void Hue_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted.clone();								// Hue changes made permanent
				 hueApply->Enabled = false;
				 trackBarHue->Value = 0;											// Center slider
	}
	private: System::Void Saturation_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValueHue = trackBarHue->Value;
				 int trackBarValueSaturation = trackBarSaturation->Value;
				 int trackBarValueValue = trackBarValue->Value;

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage.clone();
				 Saturation(&mainImage, trackBarValueHue, trackBarValueSaturation, trackBarValueValue);	// Call Saturation function
				 saturationApply->Enabled = true;
	}
	private: System::Void Saturation_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted.clone();								// Saturation changes made permanent
				 saturationApply->Enabled = false;
				 trackBarSaturation->Value = 0;										// Center slider
	}
	private: System::Void Value_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValueHue = trackBarHue->Value;
				 int trackBarValueSaturation = trackBarSaturation->Value;
				 int trackBarValueValue = trackBarValue->Value;

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage.clone();
				 Value(&mainImage, trackBarValueHue, trackBarValueSaturation, trackBarValueValue);	//Call Value function
				 valueApply->Enabled = true;
	}
	private: System::Void Value_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted.clone();								// Value changes made permanent
				 valueApply->Enabled = false;
				 trackBarValue->Value = 0;											// Center slider
	}
	private: System::Void ContrastAutoAdjust_Click(System::Object^  sender, System::EventArgs^  e) {
				 cv::Mat img;
				 std::vector<cv::Mat> channels;
				 cvtColor(editedImage, img, CV_BGR2YCrCb);							// Change the color image from BGR to YCrCb format
				 cv::split(img, channels);											// Split the image into channels
				 cv::equalizeHist(channels[0], channels[0]);						// Equalize histogram on the 1st channel (Y)
				 cv::merge(channels, img);											// Merge the 3 channels 
				 cvtColor(img, tempAdjusted, CV_YCrCb2BGR);							// Back to BGR
				 //imshow("Histogram Equalized Image", img);						// Shows image
				 refreshPicBox(tempAdjusted);										// Update picture displayed
				 editedImage = tempAdjusted.clone();
				 //valueApply->Enabled = false;
	}
	private: System::Void ExposureAutoAdjust_Click(System::Object^  sender, System::EventArgs^  e) {
				 double min, max, alpha, beta;
				 cv::Mat tempIm = editedImage.clone();
				 cv::minMaxLoc(tempIm, &min, &max);
				 alpha = 255 / (max - min);
				 beta = min * alpha;
				 tempIm.convertTo(tempAdjusted, -1, alpha, beta);					//Linear Transform per pixel
				 refreshPicBox(tempAdjusted);										// Update picture displayed
				 editedImage = tempAdjusted.clone();
	}
	private: System::Void UNDO_Click(System::Object^  sender, System::EventArgs^  e) {
				 refreshPicBox(editedImage);										// Revert to previous image
				 //Reposition sliders to the center
				 trackBarLuminance->Value = 0;
				 trackBarExposure->Value = 50;
				 trackBarContrast->Value = 50;
				 trackBarHue->Value = 0;
				 trackBarSaturation->Value = 0;
				 trackBarValue->Value = 0;
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
				 if (tempImage.empty())											   // Check for invalid input
				 {
					 return -1;
				 }
				 namedWindow(imageDes, cv::WINDOW_AUTOSIZE);						// Create a window for display.
				 imshow(imageDes, tempImage);									    // Show our image inside it.
				 cv::waitKey(0);													// Wait for a keystroke in the window
				 return 0;
			 }

			 void Luminance(cv::Mat *mainImageLum, int tempValue)
			 {
				 cv::Mat img;
				 cvtColor(*mainImageLum, img, CV_BGR2YCrCb);						// Change the color image from BGR to YCrCb format

				 //Initialize
				 int luminosity = tempValue;										// Slider Value
//				 int luminosity = elem4 - 255;

				 // Loop for each pixel in Y plane
				 for (int y = 0; y<img.cols; y++)
				 {
					 for (int x = 0; x<img.rows; x++)
					 {
						 int cur1 = img.at<cv::Vec3b>(cv::Point(y, x))[0];			// Y-Luminosity Plane
						 cur1 += luminosity;										// Change 
						 if (cur1 < 0) cur1 = 0; else if (cur1 > 255) cur1 = 255;	// Check thresholds
						 img.at<cv::Vec3b>(cv::Point(y, x))[0] = cur1;				// Adjust pixel
					 }
				 }
				 cvtColor(img, tempAdjusted, CV_YCrCb2BGR);							// Back to BGR
				 //imshow("image", tempAdjusted);									// Display adjusted image
				 refreshPicBox(tempAdjusted);										// Update picture displayed
			 }
			 void Exposure(cv::Mat *mainImageEx, int tempValueExposure, int tempValueContrast)
			 {
				 int exposure = tempValueExposure - 50;
				 double ContrastNew = tempValueContrast / 50.0;						// Or divide by smaller no. to increase range
				 cv::Mat temp = *mainImageEx;
				 temp.convertTo(tempAdjusted, -1, ContrastNew, exposure);			//Linear Transform - per pixel
				//imshow("image", tempAdjusted);
				 refreshPicBox(tempAdjusted);										// Update picture displayed
			 }
			 void Contrast(cv::Mat *mainImageCon, int tempValueExposure, int tempValueContrast)
			 {
				 int exposure = tempValueExposure - 50;
				 double ContrastNew = tempValueContrast / 50.0;						// Or divide by smaller no. to increase range
				 cv::Mat temp = *mainImageCon;
				 temp.convertTo(tempAdjusted, -1, ContrastNew, exposure);			//Linear Transform - per pixel - contrast*im+brightness
	//			 imshow("image", tempAdjusted);
				 refreshPicBox(tempAdjusted);										// Update picture displayed
			 }

			 void Hue(cv::Mat *mainImageHue, int tempValueHue, int tempValueSaturation, int tempValueValue)
			 {
				 cv::Mat img;
				 cvtColor(*mainImageHue, img, CV_BGR2HSV);							//Convert from BGR to HSV
				 //Initialize
				 int hue = tempValueHue;											// Hue slider value

				 // Loop for each pixel in Hue plane
				 for (int y = 0; y<img.cols; y++)
				 {
					 for (int x = 0; x<img.rows; x++)
					 {
						 int cur1 = img.at<cv::Vec3b>(cv::Point(y, x))[0];			// Hue Plane
					//	 int cur2 = img.at<cv::Vec3b>(cv::Point(y, x))[1];			// Saturation Plane
					//	 int cur3 = img.at<cv::Vec3b>(cv::Point(y, x))[2];			// Value Plane
						 cur1 += hue;
						// cur2 += saturation;
						 //cur3 += value;

						 if (cur1 < 0) cur1 = 0; else if (cur1 > 255) cur1 = 255;	// Check thresholds
					//	 if (cur2 < 0) cur2 = 0; else if (cur2 > 255) cur2 = 255;
					//	 if (cur3 < 0) cur3 = 0; else if (cur3 > 255) cur3 = 255;

						 img.at<cv::Vec3b>(cv::Point(y, x))[0] = cur1;				// Adjust pixel Hue
					//	 img.at<cv::Vec3b>(cv::Point(y, x))[1] = cur2;
					//	 img.at<cv::Vec3b>(cv::Point(y, x))[2] = cur3;
					 }
				 }
				 cvtColor(img, tempAdjusted, CV_HSV2BGR);							// Convert HSV to BGR
	//			 imshow("image", tempAdjusted);										// Dispay adjusted image
				 refreshPicBox(tempAdjusted);										// Update picture displayed
			 }

			 void Saturation(cv::Mat *mainImageSat, int tempValueHue, int tempValueSaturation, int tempValueValue)
			 {
				 cv::Mat img;
				 cvtColor(*mainImageSat, img, CV_BGR2HSV);							//Convert from BGR to HSV
				 //Initialize
				 int saturation = tempValueSaturation;								// Saturation Slider value
				 // Loop for each pixel in Saturation plane
				 for (int y = 0; y<img.cols; y++)
				 {
					 for (int x = 0; x<img.rows; x++)
					 {
						 int cur2 = img.at<cv::Vec3b>(cv::Point(y, x))[1];			// Saturation Plane
						 cur2 += saturation;			
						 if (cur2 < 0) cur2 = 0; else if (cur2 > 255) cur2 = 255;	// Check thresholds
						 img.at<cv::Vec3b>(cv::Point(y, x))[1] = cur2;				// Adjust pixel Saturation
					 }
				 }
				 cvtColor(img, tempAdjusted, CV_HSV2BGR);							// Convert HSV to BGR
				 //	imshow("image", tempAdjusted);									// Dispay adjusted image
				 refreshPicBox(tempAdjusted);										// Update picture displayed
			 }
			 

			 void Value(cv::Mat *mainImageVal, int tempValueHue, int tempValueSaturation, int tempValueValue)
			 {
				 cv::Mat img;
				 cvtColor(*mainImageVal, img, CV_BGR2HSV);							//Convert from BGR to HSV
				 //Initialize
				 int value = tempValueValue;										// Value Slider Value
				 // Loop for each pixel in Value plane
				 for (int y = 0; y<img.cols; y++)
				 {
					 for (int x = 0; x<img.rows; x++)
					 {
						 int cur3 = img.at<cv::Vec3b>(cv::Point(y, x))[2];			// Value Plane
						 cur3 += value;
						 if (cur3 < 0) cur3 = 0; else if (cur3 > 255) cur3 = 255;	// Check Threshholds
						 img.at<cv::Vec3b>(cv::Point(y, x))[2] = cur3;				// Adjust pixel Value 
					 }
				 }
				 cvtColor(img, tempAdjusted, CV_HSV2BGR);							// Convert HSV to BGR
				 refreshPicBox(tempAdjusted);										// Update Picture displayed
			 }
			 
			 int refreshPicBox(cv::Mat displayImage)
			 {
				 System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
				 System::IntPtr ptr(displayImage.ptr());
				 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(displayImage.cols, displayImage.rows, displayImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
				 System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
				 graphics->DrawImage(b, rect);
				 return 0;
			 }

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}

};
}