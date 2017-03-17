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
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  tempApply;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  luminanceApply;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  contrastApply;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  exposureApply;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TrackBar^  trackBar5;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Button^  hueApply;


	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TrackBar^  trackBar7;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Button^  saturationApply;
	private: System::Windows::Forms::TrackBar^  trackBar8;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TrackBar^  trackBar9;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Button^  valueApply;
	private: System::Windows::Forms::TrackBar^  trackBar10;
	private: System::Windows::Forms::Button^  ContrastAutoAdjust;




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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tempApply = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->luminanceApply = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->contrastApply = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->exposureApply = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->hueApply = (gcnew System::Windows::Forms::Button());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->saturationApply = (gcnew System::Windows::Forms::Button());
			this->trackBar8 = (gcnew System::Windows::Forms::TrackBar());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->trackBar9 = (gcnew System::Windows::Forms::TrackBar());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->valueApply = (gcnew System::Windows::Forms::Button());
			this->trackBar10 = (gcnew System::Windows::Forms::TrackBar());
			this->ContrastAutoAdjust = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->BeginInit();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->BeginInit();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar10))->BeginInit();
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
			this->pictureBox1->Location = System::Drawing::Point(16, 33);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(853, 591);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(947, 66);
			this->trackBar1->Margin = System::Windows::Forms::Padding(4);
			this->trackBar1->Maximum = 5;
			this->trackBar1->Minimum = -5;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(221, 56);
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
			this->label1->Location = System::Drawing::Point(100, 4);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 23);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Temperature ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Blue;
			this->label3->Location = System::Drawing::Point(912, 66);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 18);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Cold";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(1163, 66);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 18);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Warm";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->tempApply);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(901, 33);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(446, 67);
			this->panel1->TabIndex = 8;
			// 
			// tempApply
			// 
			this->tempApply->Location = System::Drawing::Point(323, 19);
			this->tempApply->Margin = System::Windows::Forms::Padding(4);
			this->tempApply->Name = L"tempApply";
			this->tempApply->Size = System::Drawing::Size(107, 30);
			this->tempApply->TabIndex = 0;
			this->tempApply->Text = L"Apply";
			this->tempApply->UseVisualStyleBackColor = true;
			this->tempApply->Click += gcnew System::EventHandler(this, &MyForm::tempApply_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(1163, 141);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 18);
			this->label2->TabIndex = 12;
			this->label2->Text = L"High";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Blue;
			this->label5->Location = System::Drawing::Point(912, 141);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 18);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Low";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(100, 4);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(97, 23);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Luminance";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(947, 141);
			this->trackBar2->Margin = System::Windows::Forms::Padding(4);
			this->trackBar2->Maximum = 255;
			this->trackBar2->Minimum = -255;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(221, 56);
			this->trackBar2->TabIndex = 9;
			this->trackBar2->TickFrequency = 0;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::Luminance_Scroll);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->luminanceApply);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Location = System::Drawing::Point(901, 108);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(446, 67);
			this->panel2->TabIndex = 13;
			// 
			// luminanceApply
			// 
			this->luminanceApply->Location = System::Drawing::Point(323, 19);
			this->luminanceApply->Margin = System::Windows::Forms::Padding(4);
			this->luminanceApply->Name = L"luminanceApply";
			this->luminanceApply->Size = System::Drawing::Size(107, 30);
			this->luminanceApply->TabIndex = 0;
			this->luminanceApply->Text = L"Apply";
			this->luminanceApply->UseVisualStyleBackColor = true;
			this->luminanceApply->Click += gcnew System::EventHandler(this, &MyForm::Luminance_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(1163, 291);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(36, 18);
			this->label7->TabIndex = 22;
			this->label7->Text = L"High";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Blue;
			this->label8->Location = System::Drawing::Point(912, 291);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 18);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Low";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Location = System::Drawing::Point(114, 4);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(76, 23);
			this->label9->TabIndex = 20;
			this->label9->Text = L"Contrast";
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(947, 291);
			this->trackBar4->Margin = System::Windows::Forms::Padding(4);
			this->trackBar4->Maximum = 100;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(221, 56);
			this->trackBar4->TabIndex = 19;
			this->trackBar4->TickFrequency = 0;
			this->trackBar4->Value = 50;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::Contrast_Scroll);
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->contrastApply);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Location = System::Drawing::Point(901, 258);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(446, 67);
			this->panel3->TabIndex = 23;
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
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Red;
			this->label10->Location = System::Drawing::Point(1163, 216);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(36, 18);
			this->label10->TabIndex = 17;
			this->label10->Text = L"High";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Blue;
			this->label11->Location = System::Drawing::Point(912, 216);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(33, 18);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Low";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label12->Location = System::Drawing::Point(114, 4);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(83, 23);
			this->label12->TabIndex = 15;
			this->label12->Text = L"Exposure";
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(947, 216);
			this->trackBar3->Margin = System::Windows::Forms::Padding(4);
			this->trackBar3->Maximum = 100;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(221, 56);
			this->trackBar3->TabIndex = 14;
			this->trackBar3->TickFrequency = 0;
			this->trackBar3->Value = 50;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::Exposure_Scroll);
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Controls->Add(this->exposureApply);
			this->panel4->Controls->Add(this->label12);
			this->panel4->Location = System::Drawing::Point(901, 183);
			this->panel4->Margin = System::Windows::Forms::Padding(4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(446, 67);
			this->panel4->TabIndex = 18;
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
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Red;
			this->label13->Location = System::Drawing::Point(1163, 366);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(36, 18);
			this->label13->TabIndex = 28;
			this->label13->Text = L"High";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::Blue;
			this->label14->Location = System::Drawing::Point(912, 366);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(33, 18);
			this->label14->TabIndex = 27;
			this->label14->Text = L"Low";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label15->Location = System::Drawing::Point(134, 4);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(42, 23);
			this->label15->TabIndex = 26;
			this->label15->Text = L"Hue";
			// 
			// trackBar5
			// 
			this->trackBar5->Location = System::Drawing::Point(947, 366);
			this->trackBar5->Margin = System::Windows::Forms::Padding(4);
			this->trackBar5->Maximum = 100;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(221, 56);
			this->trackBar5->TabIndex = 25;
			this->trackBar5->TickFrequency = 0;
			this->trackBar5->Value = 50;
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel5->Controls->Add(this->hueApply);
			this->panel5->Controls->Add(this->label15);
			this->panel5->Location = System::Drawing::Point(901, 333);
			this->panel5->Margin = System::Windows::Forms::Padding(4);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(446, 67);
			this->panel5->TabIndex = 29;
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
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::Red;
			this->label16->Location = System::Drawing::Point(1163, 441);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(36, 18);
			this->label16->TabIndex = 34;
			this->label16->Text = L"High";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Blue;
			this->label17->Location = System::Drawing::Point(912, 441);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(33, 18);
			this->label17->TabIndex = 33;
			this->label17->Text = L"Low";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label18->Location = System::Drawing::Point(105, 4);
			this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(92, 23);
			this->label18->TabIndex = 32;
			this->label18->Text = L"Saturation";
			// 
			// trackBar7
			// 
			this->trackBar7->Location = System::Drawing::Point(947, 441);
			this->trackBar7->Margin = System::Windows::Forms::Padding(4);
			this->trackBar7->Maximum = 100;
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->Size = System::Drawing::Size(221, 56);
			this->trackBar7->TabIndex = 31;
			this->trackBar7->TickFrequency = 0;
			this->trackBar7->Value = 50;
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel6->Controls->Add(this->saturationApply);
			this->panel6->Controls->Add(this->label18);
			this->panel6->Location = System::Drawing::Point(901, 408);
			this->panel6->Margin = System::Windows::Forms::Padding(4);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(446, 67);
			this->panel6->TabIndex = 35;
			// 
			// saturationApply
			// 
			this->saturationApply->Location = System::Drawing::Point(323, 19);
			this->saturationApply->Margin = System::Windows::Forms::Padding(4);
			this->saturationApply->Name = L"saturationApply";
			this->saturationApply->Size = System::Drawing::Size(107, 30);
			this->saturationApply->TabIndex = 0;
			this->saturationApply->Text = L"Apply";
			this->saturationApply->UseVisualStyleBackColor = true;
			this->saturationApply->Click += gcnew System::EventHandler(this, &MyForm::Saturation_Click);
			// 
			// trackBar8
			// 
			this->trackBar8->Location = System::Drawing::Point(947, 366);
			this->trackBar8->Margin = System::Windows::Forms::Padding(4);
			this->trackBar8->Maximum = 50;
			this->trackBar8->Minimum = -50;
			this->trackBar8->Name = L"trackBar8";
			this->trackBar8->Size = System::Drawing::Size(221, 56);
			this->trackBar8->TabIndex = 30;
			this->trackBar8->TickFrequency = 0;
			this->trackBar8->Scroll += gcnew System::EventHandler(this, &MyForm::Hue_Scroll);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Red;
			this->label19->Location = System::Drawing::Point(1163, 516);
			this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(36, 18);
			this->label19->TabIndex = 40;
			this->label19->Text = L"High";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Blue;
			this->label20->Location = System::Drawing::Point(912, 516);
			this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(33, 18);
			this->label20->TabIndex = 39;
			this->label20->Text = L"Low";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label21->Location = System::Drawing::Point(121, 4);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(55, 23);
			this->label21->TabIndex = 38;
			this->label21->Text = L"Value";
			// 
			// trackBar9
			// 
			this->trackBar9->Location = System::Drawing::Point(947, 516);
			this->trackBar9->Margin = System::Windows::Forms::Padding(4);
			this->trackBar9->Maximum = 50;
			this->trackBar9->Minimum = -50;
			this->trackBar9->Name = L"trackBar9";
			this->trackBar9->Size = System::Drawing::Size(221, 56);
			this->trackBar9->TabIndex = 37;
			this->trackBar9->TickFrequency = 0;
			this->trackBar9->Scroll += gcnew System::EventHandler(this, &MyForm::Value_Scroll);
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel7->Controls->Add(this->valueApply);
			this->panel7->Controls->Add(this->label21);
			this->panel7->Location = System::Drawing::Point(901, 483);
			this->panel7->Margin = System::Windows::Forms::Padding(4);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(446, 67);
			this->panel7->TabIndex = 41;
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
			// trackBar10
			// 
			this->trackBar10->Location = System::Drawing::Point(947, 441);
			this->trackBar10->Margin = System::Windows::Forms::Padding(4);
			this->trackBar10->Maximum = 50;
			this->trackBar10->Minimum = -50;
			this->trackBar10->Name = L"trackBar10";
			this->trackBar10->Size = System::Drawing::Size(221, 56);
			this->trackBar10->TabIndex = 36;
			this->trackBar10->TickFrequency = 0;
			this->trackBar10->Scroll += gcnew System::EventHandler(this, &MyForm::Saturation_Scroll);
			// 
			// ContrastAutoAdjust
			// 
			this->ContrastAutoAdjust->Location = System::Drawing::Point(901, 574);
			this->ContrastAutoAdjust->Name = L"ContrastAutoAdjust";
			this->ContrastAutoAdjust->Size = System::Drawing::Size(446, 34);
			this->ContrastAutoAdjust->TabIndex = 42;
			this->ContrastAutoAdjust->Text = L"Contrast Auto-adjust";
			this->ContrastAutoAdjust->UseVisualStyleBackColor = true;
			this->ContrastAutoAdjust->Click += gcnew System::EventHandler(this, &MyForm::ContrastAutoAdjust_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1685, 838);
			this->Controls->Add(this->ContrastAutoAdjust);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->trackBar9);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->trackBar10);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->trackBar7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->trackBar8);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->trackBar5);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->EndInit();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar10))->EndInit();
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
	private: System::Void Luminance_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValue2 = trackBar2->Value;

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage;
				 Luminance(&mainImage, trackBarValue2);
				 luminanceApply->Enabled = true;
	}
	private: System::Void Luminance_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted;
				 luminanceApply->Enabled = false;
	}
	private: System::Void Exposure_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValue3 = trackBar3->Value;
				 int trackBarValue4 = trackBar4->Value;

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage;
				 Exposure(&mainImage, trackBarValue3, trackBarValue4);
				 exposureApply->Enabled = true;
	}
	private: System::Void Exposure_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted;
				 exposureApply->Enabled = false;
	}

	private: System::Void Contrast_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValue4 = trackBar4->Value;
				 int trackBarValue3 = trackBar3->Value;

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage;
				 Contrast(&mainImage, trackBarValue4, trackBarValue3);
				 contrastApply->Enabled = true;
	}
	private: System::Void Contrast_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted;
				 contrastApply->Enabled = false;
	}
	private: System::Void Hue_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValueHue = trackBar8->Value;
				 int trackBarValueSaturation = trackBar10->Value;
				 int trackBarValueValue = trackBar9->Value;

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage;
				 Hue(&mainImage, trackBarValueHue, trackBarValueSaturation, trackBarValueValue);
				 hueApply->Enabled = true;
	}
	private: System::Void Hue_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted;
				 hueApply->Enabled = false;
	}
	private: System::Void Saturation_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValueHue = trackBar8->Value;
				 int trackBarValueSaturation = trackBar10->Value;
				 int trackBarValueValue = trackBar9->Value;

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage;
				 Saturation(&mainImage, trackBarValueHue, trackBarValueSaturation, trackBarValueValue);
				 saturationApply->Enabled = true;
	}
	private: System::Void Saturation_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted;
				 saturationApply->Enabled = false;
	}
	private: System::Void Value_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 // Acquire track bar value
				 int trackBarValueHue = trackBar8->Value;
				 int trackBarValueSaturation = trackBar10->Value;
				 int trackBarValueValue = trackBar9->Value;

				 // Initiate a Mat to save the cache.jpg image
				 cv::Mat mainImage;
				 mainImage = editedImage;
				 Value(&mainImage, trackBarValueHue, trackBarValueSaturation, trackBarValueValue);
				 valueApply->Enabled = true;
	}
	private: System::Void Value_Click(System::Object^  sender, System::EventArgs^  e) {
				 editedImage = tempAdjusted;
				 valueApply->Enabled = false;
	}
	private: System::Void ContrastAutoAdjust_Click(System::Object^  sender, System::EventArgs^  e) {
				 cv::Mat img;
				 std::vector<cv::Mat> channels;
				 cvtColor(editedImage, img, CV_BGR2YCrCb);			// Change the color image from BGR to YCrCb format
				 cv::split(img, channels);						// Split the image into channels
				 cv::equalizeHist(channels[0], channels[0]);		// Equalize histogram on the 1st channel (Y)
				 cv::merge(channels, img);						// Merge the 3 channels 
				 cvtColor(img, tempAdjusted, CV_YCrCb2BGR);		// Back to BGR
				 //imshow("Histogram Equalized Image", img);	// Shows image
				 refreshPicBox(tempAdjusted);
				 editedImage = tempAdjusted;
				 //valueApply->Enabled = false;
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

			 void Luminance(cv::Mat *mainImage, int tempValue)
			 {
				 cv::Mat img;
				 cvtColor(editedImage, img, CV_BGR2YCrCb);			// Change the color image from BGR to YCrCb format

				 //Initialize
				 int luminosity = tempValue;
//				 int luminosity = elem4 - 255;

				 // Loop for each pixel in each HSV plane
				 for (int y = 0; y<img.cols; y++)
				 {
					 for (int x = 0; x<img.rows; x++)
					 {
						 int cur1 = img.at<cv::Vec3b>(cv::Point(y, x))[0];			// Y-Luminosity Plane
						 cur1 += luminosity;
						 if (cur1 < 0) cur1 = 0; else if (cur1 > 255) cur1 = 255;
						 img.at<cv::Vec3b>(cv::Point(y, x))[0] = cur1;
					 }
				 }
				 cvtColor(img, tempAdjusted, CV_YCrCb2BGR);			// Back to BGR
	//			 imshow("image", tempAdjusted);						// Display adjusted image
				 refreshPicBox(tempAdjusted);
			 }
			 void Exposure(cv::Mat *mainImage, int tempValue, int tempValue1)
			 {
				 int exposure = tempValue - 50;
				 double ContrastNew = tempValue1 / 50.0;				// Or divide by smaller no. to increase range
				 editedImage.convertTo(tempAdjusted, -1, ContrastNew, exposure);	//Linear Transform - per pixel - contrast*im+brightness
	//			 imshow("image", tempAdjusted);
				 refreshPicBox(tempAdjusted);
			 }
			 void Contrast(cv::Mat *mainImage, int tempValue, int tempValue1)
			 {
				 int exposure = tempValue1 - 50;
				 double ContrastNew = tempValue / 50.0;				// Or divide by smaller no. to increase range
				 editedImage.convertTo(tempAdjusted, -1, ContrastNew, exposure);	//Linear Transform - per pixel - contrast*im+brightness
	//			 imshow("image", tempAdjusted);
				 refreshPicBox(tempAdjusted);
			 }

			 void Hue(cv::Mat *mainImage, int tempValueHue, int tempValueSaturation, int tempValueValue)
			 {
				 cv::Mat img;
				 cvtColor(editedImage, img, CV_BGR2HSV);		//Convert from BGR to HSV
				 //Initialize
				 int hue = tempValueHue;
				 int saturation = tempValueSaturation;
				 int value = tempValueValue;
				 // Loop for each pixel in each HSV plane
				 for (int y = 0; y<img.cols; y++)
				 {
					 for (int x = 0; x<img.rows; x++)
					 {
						 int cur1 = img.at<cv::Vec3b>(cv::Point(y, x))[0];			// Hue Plane
						 int cur2 = img.at<cv::Vec3b>(cv::Point(y, x))[1];			// Saturation Plane
						 int cur3 = img.at<cv::Vec3b>(cv::Point(y, x))[2];			// Value Plane
						 cur1 += hue;
						 cur2 += saturation;
						 cur3 += value;

						 if (cur1 < 0) cur1 = 0; else if (cur1 > 255) cur1 = 255;
						 if (cur2 < 0) cur2 = 0; else if (cur2 > 255) cur2 = 255;
						 if (cur3 < 0) cur3 = 0; else if (cur3 > 255) cur3 = 255;

						 img.at<cv::Vec3b>(cv::Point(y, x))[0] = cur1;
						 img.at<cv::Vec3b>(cv::Point(y, x))[1] = cur2;
						 img.at<cv::Vec3b>(cv::Point(y, x))[2] = cur3;
					 }
				 }
				 cvtColor(img, tempAdjusted, CV_HSV2BGR);			// Convert HSV to BGR
	//			 imshow("image", tempAdjusted);						// Dispay adjusted image
				 refreshPicBox(tempAdjusted);
			 }

			 void Saturation(cv::Mat *mainImage, int tempValueHue, int tempValueSaturation, int tempValueValue)
			 {
				 cv::Mat img;
				 cvtColor(editedImage, img, CV_BGR2HSV);		//Convert from BGR to HSV
				 //Initialize
				 int hue = tempValueHue;
				 int saturation = tempValueSaturation;
				 int value = tempValueValue;
				 // Loop for each pixel in each HSV plane
				 for (int y = 0; y<img.cols; y++)
				 {
					 for (int x = 0; x<img.rows; x++)
					 {
						 int cur1 = img.at<cv::Vec3b>(cv::Point(y, x))[0];			// Hue Plane
						 int cur2 = img.at<cv::Vec3b>(cv::Point(y, x))[1];			// Saturation Plane
						 int cur3 = img.at<cv::Vec3b>(cv::Point(y, x))[2];			// Value Plane
						 cur1 += hue;
						 cur2 += saturation;
						 cur3 += value;

						 if (cur1 < 0) cur1 = 0; else if (cur1 > 255) cur1 = 255;
						 if (cur2 < 0) cur2 = 0; else if (cur2 > 255) cur2 = 255;
						 if (cur3 < 0) cur3 = 0; else if (cur3 > 255) cur3 = 255;

						 img.at<cv::Vec3b>(cv::Point(y, x))[0] = cur1;
						 img.at<cv::Vec3b>(cv::Point(y, x))[1] = cur2;
						 img.at<cv::Vec3b>(cv::Point(y, x))[2] = cur3;
					 }
				 }
				 cvtColor(img, tempAdjusted, CV_HSV2BGR);			// Convert HSV to BGR
				 //	imshow("image", tempAdjusted);						// Dispay adjusted image
				 refreshPicBox(tempAdjusted);
			 }
			 

			 void Value(cv::Mat *mainImage, int tempValueHue, int tempValueSaturation, int tempValueValue)
			 {
				 cv::Mat img;
				 cvtColor(editedImage, img, CV_BGR2HSV);		//Convert from BGR to HSV
				 //Initialize
				 int hue = tempValueHue;
				 int saturation = tempValueSaturation;
				 int value = tempValueValue;
				 // Loop for each pixel in each HSV plane
				 for (int y = 0; y<img.cols; y++)
				 {
					 for (int x = 0; x<img.rows; x++)
					 {
						 int cur1 = img.at<cv::Vec3b>(cv::Point(y, x))[0];			// Hue Plane
						 int cur2 = img.at<cv::Vec3b>(cv::Point(y, x))[1];			// Saturation Plane
						 int cur3 = img.at<cv::Vec3b>(cv::Point(y, x))[2];			// Value Plane
						 cur1 += hue;
						 cur2 += saturation;
						 cur3 += value;

						 if (cur1 < 0) cur1 = 0; else if (cur1 > 255) cur1 = 255;
						 if (cur2 < 0) cur2 = 0; else if (cur2 > 255) cur2 = 255;
						 if (cur3 < 0) cur3 = 0; else if (cur3 > 255) cur3 = 255;

						 img.at<cv::Vec3b>(cv::Point(y, x))[0] = cur1;
						 img.at<cv::Vec3b>(cv::Point(y, x))[1] = cur2;
						 img.at<cv::Vec3b>(cv::Point(y, x))[2] = cur3;
					 }
				 }
				 cvtColor(img, tempAdjusted, CV_HSV2BGR);			// Convert HSV to BGR
				 //			 imshow("image", tempAdjusted);						// Dispay adjusted image
				 refreshPicBox(tempAdjusted);
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