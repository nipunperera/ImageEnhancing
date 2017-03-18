#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "spline.h"
#include "math.h"

//----------------------------------------------dev chamara starts
//----------------------------------------------dev chamara starts
//----------------------------------------------dev chamara starts
#include <string>
#include <msclr\marshal_cppstd.h>
//----------------------------------------------dev chamara ends
//----------------------------------------------dev chamara ends
//----------------------------------------------dev chamara ends


cv::Mat editedImage;
cv::Mat tempAdjusted;


//----------------------------------------------dev chamara starts
//----------------------------------------------dev chamara starts
//----------------------------------------------dev chamara starts
std::string filterType;
//----------------------------------------------dev chamara ends
//----------------------------------------------dev chamara ends
//----------------------------------------------dev chamara ends

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

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  tempApply;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  pnlFiltering;
	private: System::Windows::Forms::ComboBox^  cmboxNoiseReduction;
	private: System::Windows::Forms::TrackBar^  trkBarLumina;
	private: System::Windows::Forms::Button^  btnLuminaApply;
	private: System::Windows::Forms::Button^  btnColorApply;
	private: System::Windows::Forms::TrackBar^  trkBarColor;
	private: System::Windows::Forms::Panel^  pnlShadowHighlights;

	private: System::Windows::Forms::Button^  btnHighLightsApply;
	private: System::Windows::Forms::Button^  btnShadowApply;
	private: System::Windows::Forms::TrackBar^  trkBarHighlights;
	private: System::Windows::Forms::TrackBar^  trkBarShadow;
	private: System::Windows::Forms::Label^  lblhindredColor;
	private: System::Windows::Forms::Label^  lblhundredLuma;
	private: System::Windows::Forms::Label^  lblzeroColor;
	private: System::Windows::Forms::Label^  lblzeroLumina;
	private: System::Windows::Forms::Label^  lblColor;
	private: System::Windows::Forms::Label^  lblLuminance;
	private: System::Windows::Forms::Label^  lblFilterType;
	private: System::Windows::Forms::Label^  lblNoiseReduction;
	private: System::Windows::Forms::Label^  lblMaxHighlights;

	private: System::Windows::Forms::Label^  lblMaxShadow;

	private: System::Windows::Forms::Label^  lblMinHighlights;

	private: System::Windows::Forms::Label^  lblMinShadow;

	private: System::Windows::Forms::Label^  lblHIghlights;
	private: System::Windows::Forms::Label^  lblShadow;
	private: System::Windows::Forms::Label^  lblShadowHighlights;
























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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tempApply = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pnlFiltering = (gcnew System::Windows::Forms::Panel());
			this->btnColorApply = (gcnew System::Windows::Forms::Button());
			this->trkBarColor = (gcnew System::Windows::Forms::TrackBar());
			this->btnLuminaApply = (gcnew System::Windows::Forms::Button());
			this->trkBarLumina = (gcnew System::Windows::Forms::TrackBar());
			this->cmboxNoiseReduction = (gcnew System::Windows::Forms::ComboBox());
			this->pnlShadowHighlights = (gcnew System::Windows::Forms::Panel());
			this->trkBarHighlights = (gcnew System::Windows::Forms::TrackBar());
			this->trkBarShadow = (gcnew System::Windows::Forms::TrackBar());
			this->btnHighLightsApply = (gcnew System::Windows::Forms::Button());
			this->btnShadowApply = (gcnew System::Windows::Forms::Button());
			this->lblNoiseReduction = (gcnew System::Windows::Forms::Label());
			this->lblFilterType = (gcnew System::Windows::Forms::Label());
			this->lblLuminance = (gcnew System::Windows::Forms::Label());
			this->lblColor = (gcnew System::Windows::Forms::Label());
			this->lblShadowHighlights = (gcnew System::Windows::Forms::Label());
			this->lblShadow = (gcnew System::Windows::Forms::Label());
			this->lblHIghlights = (gcnew System::Windows::Forms::Label());
			this->lblzeroLumina = (gcnew System::Windows::Forms::Label());
			this->lblzeroColor = (gcnew System::Windows::Forms::Label());
			this->lblhundredLuma = (gcnew System::Windows::Forms::Label());
			this->lblhindredColor = (gcnew System::Windows::Forms::Label());
			this->lblMinShadow = (gcnew System::Windows::Forms::Label());
			this->lblMinHighlights = (gcnew System::Windows::Forms::Label());
			this->lblMaxShadow = (gcnew System::Windows::Forms::Label());
			this->lblMaxHighlights = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->panel1->SuspendLayout();
			this->pnlFiltering->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trkBarColor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trkBarLumina))->BeginInit();
			this->pnlShadowHighlights->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trkBarHighlights))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trkBarShadow))->BeginInit();
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
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(33, 25);
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
			// tempApply
			// 
			this->tempApply->Location = System::Drawing::Point(72, 67);
			this->tempApply->Name = L"tempApply";
			this->tempApply->Size = System::Drawing::Size(80, 24);
			this->tempApply->TabIndex = 0;
			this->tempApply->Text = L"Apply";
			this->tempApply->UseVisualStyleBackColor = true;
			this->tempApply->Click += gcnew System::EventHandler(this, &MyForm::tempApply_Click);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->tempApply);
			this->panel1->Controls->Add(this->trackBar1);
			this->panel1->Location = System::Drawing::Point(676, 61);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(240, 108);
			this->panel1->TabIndex = 8;
			// 
			// pnlFiltering
			// 
			this->pnlFiltering->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pnlFiltering->Controls->Add(this->lblhindredColor);
			this->pnlFiltering->Controls->Add(this->lblhundredLuma);
			this->pnlFiltering->Controls->Add(this->lblzeroColor);
			this->pnlFiltering->Controls->Add(this->lblzeroLumina);
			this->pnlFiltering->Controls->Add(this->lblColor);
			this->pnlFiltering->Controls->Add(this->lblLuminance);
			this->pnlFiltering->Controls->Add(this->lblFilterType);
			this->pnlFiltering->Controls->Add(this->lblNoiseReduction);
			this->pnlFiltering->Controls->Add(this->btnColorApply);
			this->pnlFiltering->Controls->Add(this->trkBarColor);
			this->pnlFiltering->Controls->Add(this->btnLuminaApply);
			this->pnlFiltering->Controls->Add(this->trkBarLumina);
			this->pnlFiltering->Controls->Add(this->cmboxNoiseReduction);
			this->pnlFiltering->Location = System::Drawing::Point(676, 189);
			this->pnlFiltering->Name = L"pnlFiltering";
			this->pnlFiltering->Size = System::Drawing::Size(346, 178);
			this->pnlFiltering->TabIndex = 9;
			// 
			// btnColorApply
			// 
			this->btnColorApply->Location = System::Drawing::Point(259, 135);
			this->btnColorApply->Name = L"btnColorApply";
			this->btnColorApply->Size = System::Drawing::Size(80, 24);
			this->btnColorApply->TabIndex = 12;
			this->btnColorApply->Text = L"Apply";
			this->btnColorApply->UseVisualStyleBackColor = true;
			this->btnColorApply->Click += gcnew System::EventHandler(this, &MyForm::btnColorApply_Click);
			// 
			// trkBarColor
			// 
			this->trkBarColor->Location = System::Drawing::Point(19, 141);
			this->trkBarColor->Name = L"trkBarColor";
			this->trkBarColor->Size = System::Drawing::Size(208, 45);
			this->trkBarColor->TabIndex = 11;
			this->trkBarColor->TickFrequency = 0;
			this->trkBarColor->Scroll += gcnew System::EventHandler(this, &MyForm::trkBarColor_Scroll);
			// 
			// btnLuminaApply
			// 
			this->btnLuminaApply->Location = System::Drawing::Point(259, 93);
			this->btnLuminaApply->Name = L"btnLuminaApply";
			this->btnLuminaApply->Size = System::Drawing::Size(80, 24);
			this->btnLuminaApply->TabIndex = 1;
			this->btnLuminaApply->Text = L"Apply";
			this->btnLuminaApply->UseVisualStyleBackColor = true;
			this->btnLuminaApply->Click += gcnew System::EventHandler(this, &MyForm::btnLuminaApply_Click);
			// 
			// trkBarLumina
			// 
			this->trkBarLumina->Location = System::Drawing::Point(19, 93);
			this->trkBarLumina->Name = L"trkBarLumina";
			this->trkBarLumina->Size = System::Drawing::Size(208, 45);
			this->trkBarLumina->TabIndex = 10;
			this->trkBarLumina->TickFrequency = 0;
			this->trkBarLumina->Scroll += gcnew System::EventHandler(this, &MyForm::trkBarLumina_Scroll);
			// 
			// cmboxNoiseReduction
			// 
			this->cmboxNoiseReduction->FormattingEnabled = true;
			this->cmboxNoiseReduction->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Box", L"Gaussian", L"Median", L"" });
			this->cmboxNoiseReduction->Location = System::Drawing::Point(9, 50);
			this->cmboxNoiseReduction->Name = L"cmboxNoiseReduction";
			this->cmboxNoiseReduction->Size = System::Drawing::Size(218, 21);
			this->cmboxNoiseReduction->TabIndex = 0;
			this->cmboxNoiseReduction->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// pnlShadowHighlights
			// 
			this->pnlShadowHighlights->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pnlShadowHighlights->Controls->Add(this->lblMaxHighlights);
			this->pnlShadowHighlights->Controls->Add(this->lblMaxShadow);
			this->pnlShadowHighlights->Controls->Add(this->lblMinHighlights);
			this->pnlShadowHighlights->Controls->Add(this->lblMinShadow);
			this->pnlShadowHighlights->Controls->Add(this->lblHIghlights);
			this->pnlShadowHighlights->Controls->Add(this->lblShadow);
			this->pnlShadowHighlights->Controls->Add(this->lblShadowHighlights);
			this->pnlShadowHighlights->Controls->Add(this->trkBarHighlights);
			this->pnlShadowHighlights->Controls->Add(this->trkBarShadow);
			this->pnlShadowHighlights->Controls->Add(this->btnHighLightsApply);
			this->pnlShadowHighlights->Controls->Add(this->btnShadowApply);
			this->pnlShadowHighlights->Location = System::Drawing::Point(676, 373);
			this->pnlShadowHighlights->Name = L"pnlShadowHighlights";
			this->pnlShadowHighlights->Size = System::Drawing::Size(346, 134);
			this->pnlShadowHighlights->TabIndex = 13;
			// 
			// trkBarHighlights
			// 
			this->trkBarHighlights->Location = System::Drawing::Point(19, 87);
			this->trkBarHighlights->Maximum = 50;
			this->trkBarHighlights->Minimum = -50;
			this->trkBarHighlights->Name = L"trkBarHighlights";
			this->trkBarHighlights->Size = System::Drawing::Size(208, 45);
			this->trkBarHighlights->TabIndex = 5;
			this->trkBarHighlights->Scroll += gcnew System::EventHandler(this, &MyForm::trkBarHighlights_Scroll);
			// 
			// trkBarShadow
			// 
			this->trkBarShadow->Location = System::Drawing::Point(19, 36);
			this->trkBarShadow->Maximum = 50;
			this->trkBarShadow->Minimum = -50;
			this->trkBarShadow->Name = L"trkBarShadow";
			this->trkBarShadow->Size = System::Drawing::Size(208, 45);
			this->trkBarShadow->TabIndex = 4;
			this->trkBarShadow->Scroll += gcnew System::EventHandler(this, &MyForm::trkBarShadow_Scroll);
			// 
			// btnHighLightsApply
			// 
			this->btnHighLightsApply->Location = System::Drawing::Point(251, 87);
			this->btnHighLightsApply->Name = L"btnHighLightsApply";
			this->btnHighLightsApply->Size = System::Drawing::Size(77, 26);
			this->btnHighLightsApply->TabIndex = 3;
			this->btnHighLightsApply->Text = L"Apply";
			this->btnHighLightsApply->UseVisualStyleBackColor = true;
			this->btnHighLightsApply->Click += gcnew System::EventHandler(this, &MyForm::btnHighLightsApply_Click);
			// 
			// btnShadowApply
			// 
			this->btnShadowApply->Location = System::Drawing::Point(249, 36);
			this->btnShadowApply->Name = L"btnShadowApply";
			this->btnShadowApply->Size = System::Drawing::Size(79, 26);
			this->btnShadowApply->TabIndex = 2;
			this->btnShadowApply->Text = L"Apply";
			this->btnShadowApply->UseVisualStyleBackColor = true;
			this->btnShadowApply->Click += gcnew System::EventHandler(this, &MyForm::btnShadowApply_Click);
			// 
			// lblNoiseReduction
			// 
			this->lblNoiseReduction->AutoSize = true;
			this->lblNoiseReduction->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNoiseReduction->Location = System::Drawing::Point(81, 11);
			this->lblNoiseReduction->Name = L"lblNoiseReduction";
			this->lblNoiseReduction->Size = System::Drawing::Size(101, 13);
			this->lblNoiseReduction->TabIndex = 13;
			this->lblNoiseReduction->Text = L"Noise Reduction";
			// 
			// lblFilterType
			// 
			this->lblFilterType->AutoSize = true;
			this->lblFilterType->Location = System::Drawing::Point(13, 35);
			this->lblFilterType->Name = L"lblFilterType";
			this->lblFilterType->Size = System::Drawing::Size(56, 13);
			this->lblFilterType->TabIndex = 14;
			this->lblFilterType->Text = L"Filter Type";
			// 
			// lblLuminance
			// 
			this->lblLuminance->AutoSize = true;
			this->lblLuminance->Location = System::Drawing::Point(13, 77);
			this->lblLuminance->Name = L"lblLuminance";
			this->lblLuminance->Size = System::Drawing::Size(59, 13);
			this->lblLuminance->TabIndex = 15;
			this->lblLuminance->Text = L"Luminance";
			// 
			// lblColor
			// 
			this->lblColor->AutoSize = true;
			this->lblColor->Location = System::Drawing::Point(13, 125);
			this->lblColor->Name = L"lblColor";
			this->lblColor->Size = System::Drawing::Size(31, 13);
			this->lblColor->TabIndex = 16;
			this->lblColor->Text = L"Color";
			// 
			// lblShadowHighlights
			// 
			this->lblShadowHighlights->AutoSize = true;
			this->lblShadowHighlights->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblShadowHighlights->Location = System::Drawing::Point(81, 5);
			this->lblShadowHighlights->Name = L"lblShadowHighlights";
			this->lblShadowHighlights->Size = System::Drawing::Size(114, 13);
			this->lblShadowHighlights->TabIndex = 17;
			this->lblShadowHighlights->Text = L"Shadow/Highlights";
			// 
			// lblShadow
			// 
			this->lblShadow->AutoSize = true;
			this->lblShadow->Location = System::Drawing::Point(13, 20);
			this->lblShadow->Name = L"lblShadow";
			this->lblShadow->Size = System::Drawing::Size(46, 13);
			this->lblShadow->TabIndex = 17;
			this->lblShadow->Text = L"Shadow";
			// 
			// lblHIghlights
			// 
			this->lblHIghlights->AutoSize = true;
			this->lblHIghlights->Location = System::Drawing::Point(13, 71);
			this->lblHIghlights->Name = L"lblHIghlights";
			this->lblHIghlights->Size = System::Drawing::Size(57, 13);
			this->lblHIghlights->TabIndex = 18;
			this->lblHIghlights->Text = L"HighLights";
			// 
			// lblzeroLumina
			// 
			this->lblzeroLumina->AutoSize = true;
			this->lblzeroLumina->Location = System::Drawing::Point(6, 93);
			this->lblzeroLumina->Name = L"lblzeroLumina";
			this->lblzeroLumina->Size = System::Drawing::Size(13, 13);
			this->lblzeroLumina->TabIndex = 14;
			this->lblzeroLumina->Text = L"0";
			// 
			// lblzeroColor
			// 
			this->lblzeroColor->AutoSize = true;
			this->lblzeroColor->Location = System::Drawing::Point(6, 141);
			this->lblzeroColor->Name = L"lblzeroColor";
			this->lblzeroColor->Size = System::Drawing::Size(13, 13);
			this->lblzeroColor->TabIndex = 17;
			this->lblzeroColor->Text = L"0";
			// 
			// lblhundredLuma
			// 
			this->lblhundredLuma->AutoSize = true;
			this->lblhundredLuma->Location = System::Drawing::Point(228, 93);
			this->lblhundredLuma->Name = L"lblhundredLuma";
			this->lblhundredLuma->Size = System::Drawing::Size(25, 13);
			this->lblhundredLuma->TabIndex = 18;
			this->lblhundredLuma->Text = L"100";
			// 
			// lblhindredColor
			// 
			this->lblhindredColor->AutoSize = true;
			this->lblhindredColor->Location = System::Drawing::Point(228, 146);
			this->lblhindredColor->Name = L"lblhindredColor";
			this->lblhindredColor->Size = System::Drawing::Size(25, 13);
			this->lblhindredColor->TabIndex = 19;
			this->lblhindredColor->Text = L"100";
			// 
			// lblMinShadow
			// 
			this->lblMinShadow->AutoSize = true;
			this->lblMinShadow->Location = System::Drawing::Point(0, 36);
			this->lblMinShadow->Name = L"lblMinShadow";
			this->lblMinShadow->Size = System::Drawing::Size(22, 13);
			this->lblMinShadow->TabIndex = 20;
			this->lblMinShadow->Text = L"-50";
			// 
			// lblMinHighlights
			// 
			this->lblMinHighlights->AutoSize = true;
			this->lblMinHighlights->Location = System::Drawing::Point(3, 87);
			this->lblMinHighlights->Name = L"lblMinHighlights";
			this->lblMinHighlights->Size = System::Drawing::Size(22, 13);
			this->lblMinHighlights->TabIndex = 21;
			this->lblMinHighlights->Text = L"-50";
			// 
			// lblMaxShadow
			// 
			this->lblMaxShadow->AutoSize = true;
			this->lblMaxShadow->Location = System::Drawing::Point(221, 36);
			this->lblMaxShadow->Name = L"lblMaxShadow";
			this->lblMaxShadow->Size = System::Drawing::Size(19, 13);
			this->lblMaxShadow->TabIndex = 22;
			this->lblMaxShadow->Text = L"50";
			// 
			// lblMaxHighlights
			// 
			this->lblMaxHighlights->AutoSize = true;
			this->lblMaxHighlights->Location = System::Drawing::Point(223, 87);
			this->lblMaxHighlights->Name = L"lblMaxHighlights";
			this->lblMaxHighlights->Size = System::Drawing::Size(19, 13);
			this->lblMaxHighlights->TabIndex = 23;
			this->lblMaxHighlights->Text = L"50";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->pnlShadowHighlights);
			this->Controls->Add(this->pnlFiltering);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
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
			this->panel1->PerformLayout();
			this->pnlFiltering->ResumeLayout(false);
			this->pnlFiltering->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trkBarColor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trkBarLumina))->EndInit();
			this->pnlShadowHighlights->ResumeLayout(false);
			this->pnlShadowHighlights->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trkBarHighlights))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trkBarShadow))->EndInit();
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


			 //----------------------------------------------dev chamara starts
			 //----------------------------------------------dev chamara starts
			 //----------------------------------------------dev chamara starts

			 //----------------------Lumina Function------------------------//

			 /*--------------------------starts luma noise filtering---------------------------------------------------*/
			 /* this function luminance noise reduction is done. It will used different filtering methods for the luma noise reduction.
			 It is used the y component of the YCbCr color space for the enahncement. After enhancing the y
			 both the three components are merged and convet in to RGB color space*/

			 //@para: Mat * inputImage :- pointer varible for the input image
			 //	     Mat *outputImage :- pointer variable for the outout image
			 //@return value: integer

			 int lumaNoiseFiltering(cv::Mat *inputImage, int tempValue)
			 {
				 cv::Mat YCrCb;


				 cv::Mat channels[3];			//creating array of Mat variables for the 3 cmponents of the YCrCb

				 cvtColor(*inputImage, YCrCb, cv::COLOR_BGR2YCrCb, 3);
				 split(YCrCb, channels);


				 int parameter = tempValue;		//taking input values to select the filter type and its main parameter value for the process
				

				 if (filterType == "Box")
				 {
					 lumaNoiseBoxFilter(channels[0], channels[1], channels[2], parameter);
				 }
				 else if (filterType == "Gaussian")
				 {
					 lumaNoiseGaussianFilter(channels[0], channels[1], channels[2], parameter);
				 }
				 else if (filterType == "Median")
				 {
					 lumaNoiseMedianFilter(channels[0], channels[1], channels[2], parameter);
				 }
				 else if (filterType == "Bilateral")
				 {
					 lumaNoiseBilateralFilter(channels[0], channels[1], channels[2], parameter);
				 }
				 
				 return 0;

			 }
			 
			 //filter the Cr and Cb components of the YCrCb image using Box filter
			 int lumaNoiseBoxFilter(cv::Mat y, cv::Mat Cb, cv::Mat Cr, int i)
			 {
				 cv::Mat outputImage;
				 blur(y, y, cv::Size(i, i), cv::Point(-1, -1));

				 std::vector<cv::Mat> finalChannels = { y, Cb, Cr };

				 merge(finalChannels, outputImage);			// merge the filtered components and the luma part to creat the output image in YCrCb color space	
				 cvtColor(outputImage, tempAdjusted, cv::COLOR_YCrCb2BGR);
				 refreshPicBox(tempAdjusted);
				 return 0;
			 }


			 //filter the Cr and Cb components of the YCrCb image using Gaussian filter
			 int lumaNoiseGaussianFilter(cv::Mat y, cv::Mat Cb, cv::Mat Cr, int i)
			 {

				 cv::Mat outputImage;
				 GaussianBlur(y, y, cv::Size(i, i), 0, 0, 1);

				 std::vector<cv::Mat> finalChannels = { y, Cb, Cr };

				 merge(finalChannels, outputImage);

				 cvtColor(outputImage, tempAdjusted, cv::COLOR_YCrCb2BGR);
				 refreshPicBox(tempAdjusted);
				 return 0;
			 }

			 int lumaNoiseMedianFilter(cv::Mat y, cv::Mat Cb, cv::Mat Cr, int i)
			 {
				 cv::Mat outputImage;
				 medianBlur(y, y, i);

				 std::vector<cv::Mat> finalChannels = { y, Cb, Cr };
				 merge(finalChannels, outputImage);
				 cvtColor(outputImage, tempAdjusted, cv::COLOR_YCrCb2BGR);
				 refreshPicBox(tempAdjusted);
				 return 0;
			 }

			 //filter the Cr and Cb components of the YCrCb image using Bilateral filter
			 int lumaNoiseBilateralFilter(cv::Mat y, cv::Mat Cb, cv::Mat Cr, int i)
			 {
				 
				 cv::Mat outputImage;
				 bilateralFilter(y, y, i, i * 2, i / 2);

				 std::vector<cv::Mat> finalChannels = { y, Cb,Cr };
				 merge(finalChannels, outputImage);
				 cvtColor(outputImage, tempAdjusted, cv::COLOR_YCrCb2BGR);
				 refreshPicBox(tempAdjusted);
				 return 0;
			 }
			 /*-----------------------------------------------------------------------------*/
			 /*----------------------------ends luma filtering------------------------------*/



			 /*-------------------------------------------------------------------------------*/
			 /*----------------------------starts color filtering------------------------------*/

			 int colorNoiseFiltering(cv::Mat *inputImage, int tempValue)
			 {
				 cv::Mat YCrCb;


				 cv::Mat channels[3];			//creating array of Mat variables for the 3 cmponents of the YCrCb

				 cvtColor(*inputImage, YCrCb, cv::COLOR_BGR2YCrCb, 3);
				 split(YCrCb, channels);


				 int parameter = tempValue;		//taking input values to select the filter type and its main parameter value for the process



				 if (filterType == "Box")
				 {
					 colorNoiseBoxFilter(channels[0], channels[1], channels[2], parameter);
				 }
				else if (filterType == "Gaussian")
				 {
					 colorNoiseGaussianFilter(channels[0], channels[1], channels[2], parameter);
				 }
				 else if (filterType == "Median")
				 {
					 colorNoiseMedianFilter(channels[0], channels[1], channels[2], parameter);
				 }
				 else if (filterType == "Bilateral")
				 {
					colorNoiseBilateralFilter(channels[0], channels[1], channels[2], parameter);
				 }

				 return 0;

			 }
			 int colorNoiseBoxFilter(cv::Mat y, cv::Mat Cb, cv::Mat Cr, int i)
			 {
				 cv::Mat outputImage;
				 cv::blur(Cb, Cb, cv::Size(i, i), cv::Point(-1, -1));
				 cv::blur(Cr, Cr, cv::Size(i, i), cv::Point(-1, -1));

				 std::vector<cv::Mat> finalChannels = { y, Cb, Cr };

				 merge(finalChannels, outputImage);			// merge the filtered components and the luma part to creat the output image in YCrCb color space	
				 cvtColor(outputImage, tempAdjusted, cv::COLOR_YCrCb2BGR);
				 refreshPicBox(tempAdjusted);
				 return 0;
			 }

			 int colorNoiseGaussianFilter(cv::Mat y, cv::Mat Cb, cv::Mat Cr, int i)
			 {

				 cv::Mat outputImage;
				 cv::GaussianBlur(Cb, Cb, cv::Size(i, i), 0, 0, 1);
				 cv::GaussianBlur(Cr, Cr, cv::Size(i, i), 0, 0, 1);


				 std::vector<cv::Mat> finalChannels = { y, Cb, Cr };

				 merge(finalChannels, outputImage);

				 cvtColor(outputImage, tempAdjusted, cv::COLOR_YCrCb2BGR);
				 refreshPicBox(tempAdjusted);
				 return 0;
			 }


			 //filter the Cr and Cb components of the YCrCb image using Median filter
			 int colorNoiseMedianFilter(cv::Mat y, cv::Mat Cb, cv::Mat Cr, int i)
			 {
				 cv::Mat outputImage;
				 cv::medianBlur(Cb, Cb, i);
				 cv::medianBlur(Cr, Cr, i);

				 std::vector<cv::Mat> finalChannels = { y, Cb, Cr };
				 merge(finalChannels, outputImage);
				 cvtColor(outputImage, tempAdjusted, cv::COLOR_YCrCb2BGR);
				 refreshPicBox(tempAdjusted);
				 return 0;
			 }

			 //filter the Cr and Cb components of the YCrCb image using Bilateral filter
			 int colorNoiseBilateralFilter(cv::Mat y, cv::Mat Cb, cv::Mat Cr, int i)
			 {
				 cv::Mat outputImage;
				 cv::bilateralFilter(Cb, Cb, i, i * 2, i / 2);
				 cv::bilateralFilter(Cr, Cr, i, i * 2, i / 2);

				 std::vector<cv::Mat> finalChannels = { y, Cb, Cr };
				 merge(finalChannels, outputImage);
				 cvtColor(outputImage, tempAdjusted, cv::COLOR_YCrCb2BGR);
				 refreshPicBox(tempAdjusted);
				 return 0;
			 }


			//combo box change
			private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
						 msclr::interop::marshal_context context;
						 filterType = context.marshal_as<std::string>(cmboxNoiseReduction->SelectedItem->ToString());
			}
			private: System::Void btnLuminaApply_Click(System::Object^  sender, System::EventArgs^  e) {
						 editedImage = tempAdjusted;
						 btnLuminaApply->Enabled = false;
			}
					 //track bar lumina
			
			private: System::Void trkBarLumina_Scroll(System::Object^  sender, System::EventArgs^  e) {
						 // Acquire track bar value
						 int trackBarValue = (trkBarLumina->Value);
						 trackBarValue = trackBarValue * 2 + 1;
						 // Initiate a Mat to save the cache.jpg image
						 cv::Mat mainImage;
						 mainImage = editedImage;
						 //colourTempAdjustment(&mainImage, trackBarValue);
						 lumaNoiseFiltering(&mainImage, trackBarValue);
						 btnLuminaApply->Enabled = true;
			}
			private: System::Void trkBarColor_Scroll(System::Object^  sender, System::EventArgs^  e) {
						 // Acquire track bar value
						 int trackBarValue = (trkBarColor->Value);
						 trackBarValue = trackBarValue * 2 + 1;
						 // Initiate a Mat to save the cache.jpg image
						 cv::Mat mainImage;
						 mainImage = editedImage;
						 //colourTempAdjustment(&mainImage, trackBarValue);
						 colorNoiseFiltering(&mainImage, trackBarValue);
						 btnColorApply->Enabled = true;
			}

			private: System::Void btnColorApply_Click(System::Object^  sender, System::EventArgs^  e) {
						 editedImage= tempAdjusted;
						 btnColorApply->Enabled = false;
			}


			//----------------------------------------------dev chamara ends
			//----------------------------------------------dev chamara ends
			//----------------------------------------------dev chamara ends


			//----------------------------------------------dev chamara starts
			//----------------------------------------------dev chamara starts
			//----------------------------------------------dev chamara starts

			//-------------------------Shadow and recovery----------------------//
			//------------------------------------------------------------------//

					 int shadowRecovery(cv::Mat * image, int gamma)
					 {

						 cv::Mat im = *image;
						
						 int x, y;

						cv:: Mat redChan, greenChan, blueChan;
						 cv::Mat edited2[3];
						 split(*image, edited2);
						 redChan = edited2[2];
						 greenChan = edited2[1];
						 blueChan = edited2[0];


						 double gammaUnder = 0;
						 double gammaUpper = 0;

						 gammaUnder = 1 + 0.03*abs(gamma);				//define the appropriate gamma values for the shadow recovery
						 gammaUpper = 1 - 0.006*abs(gamma);


						 for (x = 0; x < im.rows; x++){						// check the pixel values of the image change the value if the pixel values are below the 90
							 for (y = 0; y < im.cols; y++){
								 /*cv::Vec3b intensity = im.at<cv::Vec3b>(x, y);
								 uchar blue = intensity.val[0];				//obtain the RGB values seperately
								 uchar green = intensity.val[1];
								 uchar red = intensity.val[2]; */

								 int blue = blueChan.at<uchar>(x, y);
								 int green = greenChan.at<uchar>(x, y);
								 int red = redChan.at<uchar>(x, y);

								 //blue value
								 if (blue < 90 && gamma >0)					//changing the RGB values seperately
								 {
									 blue = (int)90 * pow(((blue) / (double)90), gammaUpper);

								 }
								 else if (blue < 90 && gamma <0)
								 {
									 blue = (int)90 * pow(((blue) / (double)90), gammaUnder);

								 }
								 //green value
								 if (green < 90 && gamma >0)
								 {

									 green = (int)90 * pow(((green) / (double)90), gammaUpper);


								 }
								 else if (green < 90 && gamma <0)
								 {
									 green = (int)90 * pow(((green) / (double)90), gammaUnder);
									
								 }
								 //red value
								 if (red < 90 && gamma >0)
								 {

									 red = (int)90 * pow(((red) / (double)90), gammaUpper);

								 }
								 else if (red < 90 && gamma <0)
								 {
									 red = (int)90 * pow(((red) / (double)90), gammaUnder);

								 }

								 //im.at<cv::Vec3b>(x, y) = cv::Vec3b(blue, green, red);
								 blueChan.at<uchar>(x, y) = blue;
								 greenChan.at<uchar>(x, y) = green;
								 redChan.at<uchar>(x, y) = red;

							 }

						 }
						 std::vector<cv::Mat> finalChannels = { blueChan, greenChan, redChan };
						 merge(finalChannels, tempAdjusted);
												
						 refreshPicBox(tempAdjusted);
						 return 0;
					 }


					 //------------------High lights--------------//
					 int highlightsRecovery(cv::Mat * image, int gamma)
					 {

						 cv::Mat im = *image;

						 int x, y;

						 cv::Mat redChan, greenChan, blueChan;
						 cv::Mat edited2[3];
						 split(*image, edited2);
						 redChan = edited2[2];
						 greenChan = edited2[1];
						 blueChan = edited2[0];


						 double gammaUnder = 0;
						 double gammaUpper = 0;

						 gammaUpper = 1 + 0.03*abs(gamma);				//define the appropriate gamma values for the shadow recovery
						 gammaUnder = 1 - 0.006*abs(gamma);


						 for (x = 0; x < im.rows; x++){						// check the pixel values of the image change the value if the pixel values are below the 90
							 for (y = 0; y < im.cols; y++){
								 /*cv::Vec3b intensity = im.at<cv::Vec3b>(x, y);
								 uchar blue = intensity.val[0];				//obtain the RGB values seperately
								 uchar green = intensity.val[1];
								 uchar red = intensity.val[2]; */

								 int blue = blueChan.at<uchar>(x, y);
								 int green = greenChan.at<uchar>(x, y);
								 int red = redChan.at<uchar>(x, y);

								 //blue value
								 if (blue > 153 && gamma >0)					//changing the RGB values seperately
								 {
									 blue = 255-(int)102 * pow(((255-blue) / (double)102), gammaUpper);

								 }
								 else if (blue > 153 && gamma <0)
								 {
									 blue = 255-(int)102 * pow(((255-blue) / (double)102), gammaUnder);

								 }
								 //green value
								 if (green > 153 && gamma >0)
								 {

									 green = 255-(int)102 * pow(((255-green) / (double)102), gammaUpper);


								 }
								 else if (green > 153 && gamma <0)
								 {
									 green = 255-(int)102 * pow(((255-green) / (double)102), gammaUnder);

								 }
								 //red value
								 if (red > 153 && gamma >0)
								 {

									 red = 255-(int)102 * pow(((255-red) / (double)102), gammaUpper);

								 }
								 else if (red > 153 && gamma <0)
								 {
									 red = 255-(int)102 * pow(((255-red) / (double)102), gammaUnder);

								 }

								 //im.at<cv::Vec3b>(x, y) = cv::Vec3b(blue, green, red);
								 blueChan.at<uchar>(x, y) = blue;
								 greenChan.at<uchar>(x, y) = green;
								 redChan.at<uchar>(x, y) = red;

							 }

						 }
						 std::vector<cv::Mat> finalChannels = { blueChan, greenChan, redChan };
						 merge(finalChannels, tempAdjusted);

						 refreshPicBox(tempAdjusted);
						 return 0;
					 }


			

					
					
					private: System::Void btnShadowApply_Click(System::Object^  sender, System::EventArgs^  e) {
								
								 editedImage = tempAdjusted;
								 btnShadowApply->Enabled = false;
					}
					private: System::Void btnHighLightsApply_Click(System::Object^  sender, System::EventArgs^  e) {
								 editedImage = tempAdjusted;
								 btnHighLightsApply->Enabled = false;
					}
					
					private: System::Void trkBarShadow_Scroll(System::Object^  sender, System::EventArgs^  e) {
								 // Acquire track bar value
								 int trackBarValue = (trkBarShadow->Value);
								
								 // Initiate a Mat to save the cache.jpg image
								 cv::Mat mainImage;
								 mainImage = editedImage;
								 shadowRecovery(&mainImage, trackBarValue);
								 btnShadowApply->Enabled = true;
					}


					
					private: System::Void trkBarHighlights_Scroll(System::Object^  sender, System::EventArgs^  e) {
								 int trackBarValue = (trkBarHighlights->Value);

								 // Initiate a Mat to save the cache.jpg image
								 cv::Mat mainImage;
								 mainImage = editedImage;
								 highlightsRecovery(&mainImage, trackBarValue);
								 btnHighLightsApply->Enabled = true;
					}

					private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
					}
					
					//----------------------------------------------dev chamara ends
					//----------------------------------------------dev chamara ends
					//----------------------------------------------dev chamara ends

};

}
