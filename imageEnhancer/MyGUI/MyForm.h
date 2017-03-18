#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "spline.h"
#include "math.h"

cv::Mat editedImage;
cv::Mat tempAdjusted;
cv::Mat bgrAdjusted;
cv::Mat adjRchan, adjGchan, adjBchan;


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
	private: System::Windows::Forms::Panel^  tempPanel;


	private: System::Windows::Forms::Button^  tempApply;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::Button^  loadColourAdj;
	private: System::Windows::Forms::Button^  loadTempAdj;
	private: System::Windows::Forms::Panel^  rgbPanel;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  rgbApply;
	private: System::Windows::Forms::TrackBar^  blueTrackBar;

	private: System::Windows::Forms::TrackBar^  greenTrackBar;
	private: System::Windows::Forms::TrackBar^  redTrackBar;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;



	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
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
			this->tempPanel = (gcnew System::Windows::Forms::Panel());
			this->tempApply = (gcnew System::Windows::Forms::Button());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->loadColourAdj = (gcnew System::Windows::Forms::Button());
			this->loadTempAdj = (gcnew System::Windows::Forms::Button());
			this->rgbPanel = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->rgbApply = (gcnew System::Windows::Forms::Button());
			this->blueTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->greenTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->redTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->tempPanel->SuspendLayout();
			this->rgbPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::SkyBlue;
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
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(28, 96);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 480);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(32, 43);
			this->trackBar1->Maximum = 5;
			this->trackBar1->Minimum = -5;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(166, 45);
			this->trackBar1->TabIndex = 2;
			this->trackBar1->TickFrequency = 0;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::tempTrackBar_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(72, 16);
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
			this->label2->Location = System::Drawing::Point(95, 12);
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
			this->label3->Location = System::Drawing::Point(3, 43);
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
			this->label4->Location = System::Drawing::Point(196, 43);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Warm";
			// 
			// tempPanel
			// 
			this->tempPanel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->tempPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tempPanel->Controls->Add(this->label4);
			this->tempPanel->Controls->Add(this->label3);
			this->tempPanel->Controls->Add(this->tempApply);
			this->tempPanel->Controls->Add(this->label1);
			this->tempPanel->Controls->Add(this->trackBar1);
			this->tempPanel->Location = System::Drawing::Point(858, 257);
			this->tempPanel->Name = L"tempPanel";
			this->tempPanel->Size = System::Drawing::Size(240, 130);
			this->tempPanel->TabIndex = 8;
			this->tempPanel->Visible = false;
			// 
			// tempApply
			// 
			this->tempApply->Location = System::Drawing::Point(75, 74);
			this->tempApply->Name = L"tempApply";
			this->tempApply->Size = System::Drawing::Size(80, 24);
			this->tempApply->TabIndex = 0;
			this->tempApply->Text = L"Apply";
			this->tempApply->UseVisualStyleBackColor = true;
			this->tempApply->Click += gcnew System::EventHandler(this, &MyForm::tempApply_Click);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Text = L"notifyIcon1";
			this->notifyIcon1->Visible = true;
			// 
			// loadColourAdj
			// 
			this->loadColourAdj->BackColor = System::Drawing::Color::DimGray;
			this->loadColourAdj->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loadColourAdj.BackgroundImage")));
			this->loadColourAdj->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->loadColourAdj->Location = System::Drawing::Point(28, 27);
			this->loadColourAdj->Name = L"loadColourAdj";
			this->loadColourAdj->Size = System::Drawing::Size(64, 64);
			this->loadColourAdj->TabIndex = 9;
			this->loadColourAdj->UseVisualStyleBackColor = false;
			this->loadColourAdj->Click += gcnew System::EventHandler(this, &MyForm::loadColourAdj_Click);
			this->loadColourAdj->MouseHover += gcnew System::EventHandler(this, &MyForm::loadColourAdj_MouseHover);
			// 
			// loadTempAdj
			// 
			this->loadTempAdj->BackColor = System::Drawing::Color::Yellow;
			this->loadTempAdj->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loadTempAdj.BackgroundImage")));
			this->loadTempAdj->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->loadTempAdj->Location = System::Drawing::Point(98, 27);
			this->loadTempAdj->Name = L"loadTempAdj";
			this->loadTempAdj->Size = System::Drawing::Size(64, 64);
			this->loadTempAdj->TabIndex = 10;
			this->loadTempAdj->UseVisualStyleBackColor = false;
			this->loadTempAdj->Click += gcnew System::EventHandler(this, &MyForm::loadTempAdj_Click);
			this->loadTempAdj->MouseHover += gcnew System::EventHandler(this, &MyForm::loadTempAdj_MouseHover);
			// 
			// rgbPanel
			// 
			this->rgbPanel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->rgbPanel->Controls->Add(this->label7);
			this->rgbPanel->Controls->Add(this->label6);
			this->rgbPanel->Controls->Add(this->label5);
			this->rgbPanel->Controls->Add(this->rgbApply);
			this->rgbPanel->Controls->Add(this->blueTrackBar);
			this->rgbPanel->Controls->Add(this->greenTrackBar);
			this->rgbPanel->Controls->Add(this->redTrackBar);
			this->rgbPanel->Controls->Add(this->label2);
			this->rgbPanel->Location = System::Drawing::Point(858, 217);
			this->rgbPanel->Name = L"rgbPanel";
			this->rgbPanel->Size = System::Drawing::Size(240, 216);
			this->rgbPanel->TabIndex = 11;
			this->rgbPanel->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Blue;
			this->label7->Location = System::Drawing::Point(207, 116);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 18);
			this->label7->TabIndex = 19;
			this->label7->Text = L"B";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Green;
			this->label6->Location = System::Drawing::Point(207, 77);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 18);
			this->label6->TabIndex = 18;
			this->label6->Text = L"G";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(207, 40);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(16, 18);
			this->label5->TabIndex = 17;
			this->label5->Text = L"R";
			// 
			// rgbApply
			// 
			this->rgbApply->Location = System::Drawing::Point(81, 164);
			this->rgbApply->Name = L"rgbApply";
			this->rgbApply->Size = System::Drawing::Size(80, 24);
			this->rgbApply->TabIndex = 16;
			this->rgbApply->Text = L"Apply";
			this->rgbApply->UseVisualStyleBackColor = true;
			this->rgbApply->Click += gcnew System::EventHandler(this, &MyForm::rgbApply_Click);
			// 
			// blueTrackBar
			// 
			this->blueTrackBar->Location = System::Drawing::Point(42, 113);
			this->blueTrackBar->Maximum = 20;
			this->blueTrackBar->Minimum = 1;
			this->blueTrackBar->Name = L"blueTrackBar";
			this->blueTrackBar->Size = System::Drawing::Size(166, 45);
			this->blueTrackBar->TabIndex = 15;
			this->blueTrackBar->TickFrequency = 0;
			this->blueTrackBar->Value = 10;
			this->blueTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::blueTrackBar_Scroll);
			// 
			// greenTrackBar
			// 
			this->greenTrackBar->Location = System::Drawing::Point(42, 76);
			this->greenTrackBar->Maximum = 20;
			this->greenTrackBar->Minimum = 1;
			this->greenTrackBar->Name = L"greenTrackBar";
			this->greenTrackBar->Size = System::Drawing::Size(166, 45);
			this->greenTrackBar->TabIndex = 14;
			this->greenTrackBar->TickFrequency = 0;
			this->greenTrackBar->Value = 10;
			this->greenTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::greenTrackBar_Scroll);
			// 
			// redTrackBar
			// 
			this->redTrackBar->Location = System::Drawing::Point(42, 39);
			this->redTrackBar->Maximum = 20;
			this->redTrackBar->Minimum = 1;
			this->redTrackBar->Name = L"redTrackBar";
			this->redTrackBar->Size = System::Drawing::Size(166, 45);
			this->redTrackBar->TabIndex = 13;
			this->redTrackBar->TickFrequency = 0;
			this->redTrackBar->Value = 10;
			this->redTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::redTrackBar_Scroll);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->loadTempAdj);
			this->Controls->Add(this->loadColourAdj);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->rgbPanel);
			this->Controls->Add(this->tempPanel);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->tempPanel->ResumeLayout(false);
			this->tempPanel->PerformLayout();
			this->rgbPanel->ResumeLayout(false);
			this->rgbPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redTrackBar))->EndInit();
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
	
	private: System::Void tempTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
		// Acquire track bar value
		int trackBarValue = trackBar1->Value;

		// Initiate a Mat to save the cache.jpg image
		cv::Mat mainImage;
		mainImage = editedImage;
		colourTempAdjustment(&mainImage, trackBarValue);
		tempApply->Enabled = true;
	}

	private: System::Void loadColourAdj_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::ToolTip^ ToolTip1 = gcnew System::Windows::Forms::ToolTip;
		ToolTip1->SetToolTip(loadColourAdj, "Adjust RGB Palettes");
	}

	private: System::Void loadTempAdj_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::ToolTip^ ToolTip1 = gcnew System::Windows::Forms::ToolTip;
		ToolTip1->SetToolTip(loadTempAdj, "Adjust Colour Temperature");
	}

	private: System::Void tempApply_Click(System::Object^  sender, System::EventArgs^  e) {
		editedImage = tempAdjusted.clone();
		tempApply->Enabled = false;
	}

	private: System::Void loadColourAdj_Click(System::Object^  sender, System::EventArgs^  e) {
		// Updating global RGB channels 
		cv::Mat edited2[3];
		split(editedImage, edited2);
		adjRchan = edited2[2];
		adjGchan = edited2[1];
		adjBchan = edited2[0];

		// Controlling panels
		rgbPanel->Visible = true;
		tempPanel->Visible = false;
	}

	private: System::Void loadTempAdj_Click(System::Object^  sender, System::EventArgs^  e) {
		// Controlling panels
		rgbPanel->Visible = false;
		tempPanel->Visible = true;
	}

	private: System::Void rgbApply_Click(System::Object^  sender, System::EventArgs^  e) {
		editedImage = bgrAdjusted.clone();
	}

	private: System::Void redTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
		cv::Mat edited2[3], redChan, greenChan, blueChan;
		split(editedImage, edited2);
		redChan = edited2[2];
		greenChan = edited2[1];
		blueChan = edited2[0];
		float fGamma = redTrackBar->Value / 10.0;
		unsigned char lut[256];

		for (int i = 0; i < 256; i++)
		{
			lut[i] = cv::saturate_cast<uchar>(pow((float)(i / 255.0), fGamma) * 255.0f);
		}

		cv::MatIterator_<uchar> it, end;

		for (it = redChan.begin<uchar>(), end = redChan.end<uchar>(); it != end; it++)

		*it = lut[(*it)];

		adjRchan = redChan;

		// Merging the BGR channels 
		std::vector < cv::Mat > arrayToMerge;
		arrayToMerge.push_back(adjBchan);
		arrayToMerge.push_back(adjGchan);
		arrayToMerge.push_back(adjRchan);


		// Image with altered red abd blue channels
		cv::Mat bgrAdjusted;
		merge(arrayToMerge, bgrAdjusted);
		refreshPicBox(bgrAdjusted);
		}

	private: System::Void greenTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
		cv::Mat edited2[3], redChan, greenChan, blueChan;
		split(editedImage, edited2);
		redChan = edited2[2];
		greenChan = edited2[1];
		blueChan = edited2[0];
		float fGamma = greenTrackBar->Value / 10.0;
		unsigned char lut[256];

		for (int i = 0; i < 256; i++)
		{
			lut[i] = cv::saturate_cast<uchar>(pow((float)(i / 255.0), fGamma) * 255.0f);
		}

		cv::MatIterator_<uchar> it, end;


		for (it = greenChan.begin<uchar>(), end = greenChan.end<uchar>(); it != end; it++)

			*it = lut[(*it)];
		adjGchan = greenChan;
		// Merging the BGR channels 
		std::vector < cv::Mat > arrayToMerge;
		arrayToMerge.push_back(adjBchan);
		arrayToMerge.push_back(adjGchan);
		arrayToMerge.push_back(adjRchan);

		// Image with altered red abd blue channels
		cv::Mat bgrAdjusted;
		merge(arrayToMerge, bgrAdjusted);
		refreshPicBox(bgrAdjusted);
		}

	private: System::Void blueTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
		cv::Mat edited2[3], redChan, greenChan, blueChan;
		split(editedImage, edited2);
		redChan = edited2[2];
		greenChan = edited2[1];
		blueChan = edited2[0];
		float fGamma = blueTrackBar->Value / 10.0;
		unsigned char lut[256];

		for (int i = 0; i < 256; i++)
		{
			lut[i] = cv::saturate_cast<uchar>(pow((float)(i / 255.0), fGamma) * 255.0f);
		}

		cv::MatIterator_<uchar> it, end;

	
		for (it = blueChan.begin<uchar>(), end = blueChan.end<uchar>(); it != end; it++)

		*it = lut[(*it)];
		adjBchan = blueChan;
		// Merging the BGR channels 
		std::vector < cv::Mat > arrayToMerge;
		arrayToMerge.push_back(adjBchan);
		arrayToMerge.push_back(adjGchan);
		arrayToMerge.push_back(adjRchan);
			
		// Image with altered red abd blue channels
		cv::Mat bgrAdjusted;
		merge(arrayToMerge, bgrAdjusted);
		refreshPicBox(bgrAdjusted);
		}	
		// Functions defined in opencv
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
				 uchar* p1 = redChannel.data;
				 uchar* p2 = blueChannel.data;

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
