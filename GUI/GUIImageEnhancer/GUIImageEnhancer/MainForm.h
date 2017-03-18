#pragma once

#include <Windows.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <msclr/marshal_cppstd.h>


namespace GUIImageEnhancer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	bool imageImport = false;
	bool cropSelected = false;
	bool cropStarted = false;
	bool vignetteSelected = false;

	int rectSX=0;
	int rectSY=0; 
	int rectWidth=0;
	int rectHeight = 0;
	int vignetteCenterX =0 ,vignetteCenterY =0;

	cv::Mat mainImage,croppedImage,vignetteImage ;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importToolStripMenuItem;
	private: System::Windows::Forms::Button^  cropButton;
	private: System::Windows::Forms::Button^  vignetteButton;


	private: System::Windows::Forms::Button^  cropResetButton;
	private: System::Windows::Forms::Panel^  vignettePanel;
	private: System::Windows::Forms::Button^  vignetteApplyButton;




	private: System::Windows::Forms::TrackBar^  vignetteTrackBar;
	private: System::Windows::Forms::Button^  vignetteCancelButton;


	private: System::Windows::Forms::Button^  vignetteResetButton;

	private: System::Windows::Forms::Panel^  cropPanel;

	private: System::Windows::Forms::Button^  cropApplyButton;
	private: System::Windows::Forms::Button^  cropCancelButton;





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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cropButton = (gcnew System::Windows::Forms::Button());
			this->vignetteButton = (gcnew System::Windows::Forms::Button());
			this->cropResetButton = (gcnew System::Windows::Forms::Button());
			this->vignettePanel = (gcnew System::Windows::Forms::Panel());
			this->vignetteCancelButton = (gcnew System::Windows::Forms::Button());
			this->vignetteResetButton = (gcnew System::Windows::Forms::Button());
			this->vignetteApplyButton = (gcnew System::Windows::Forms::Button());
			this->vignetteTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->cropPanel = (gcnew System::Windows::Forms::Panel());
			this->cropApplyButton = (gcnew System::Windows::Forms::Button());
			this->cropCancelButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->vignettePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vignetteTrackBar))->BeginInit();
			this->cropPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 36);
			this->pictureBox1->MaximumSize = System::Drawing::Size(600, 500);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 500);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainForm::pictureBox1_Click);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(909, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->importToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// importToolStripMenuItem
			// 
			this->importToolStripMenuItem->Name = L"importToolStripMenuItem";
			this->importToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->importToolStripMenuItem->Text = L"Import";
			this->importToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::importToolStripMenuItem_Click);
			// 
			// cropButton
			// 
			this->cropButton->Enabled = false;
			this->cropButton->Location = System::Drawing::Point(618, 36);
			this->cropButton->Name = L"cropButton";
			this->cropButton->Size = System::Drawing::Size(75, 23);
			this->cropButton->TabIndex = 2;
			this->cropButton->Text = L"Crop";
			this->cropButton->UseVisualStyleBackColor = true;
			this->cropButton->Click += gcnew System::EventHandler(this, &MainForm::cropButton_Click);
			// 
			// vignetteButton
			// 
			this->vignetteButton->Enabled = false;
			this->vignetteButton->Location = System::Drawing::Point(699, 36);
			this->vignetteButton->Name = L"vignetteButton";
			this->vignetteButton->Size = System::Drawing::Size(75, 23);
			this->vignetteButton->TabIndex = 3;
			this->vignetteButton->Text = L"Vignette";
			this->vignetteButton->UseVisualStyleBackColor = true;
			this->vignetteButton->Click += gcnew System::EventHandler(this, &MainForm::vignetteButton_Click);
			// 
			// cropResetButton
			// 
			this->cropResetButton->Location = System::Drawing::Point(97, 15);
			this->cropResetButton->Name = L"cropResetButton";
			this->cropResetButton->Size = System::Drawing::Size(75, 23);
			this->cropResetButton->TabIndex = 4;
			this->cropResetButton->Text = L"Reset";
			this->cropResetButton->UseVisualStyleBackColor = true;
			this->cropResetButton->Click += gcnew System::EventHandler(this, &MainForm::cropResetButton_Click);
			// 
			// vignettePanel
			// 
			this->vignettePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->vignettePanel->Controls->Add(this->vignetteCancelButton);
			this->vignettePanel->Controls->Add(this->vignetteResetButton);
			this->vignettePanel->Controls->Add(this->vignetteApplyButton);
			this->vignettePanel->Controls->Add(this->vignetteTrackBar);
			this->vignettePanel->Location = System::Drawing::Point(618, 124);
			this->vignettePanel->Name = L"vignettePanel";
			this->vignettePanel->Size = System::Drawing::Size(264, 128);
			this->vignettePanel->TabIndex = 5;
			this->vignettePanel->Tag = L"Vignette ";
			this->vignettePanel->Visible = false;
			// 
			// vignetteCancelButton
			// 
			this->vignetteCancelButton->Location = System::Drawing::Point(14, 73);
			this->vignetteCancelButton->Name = L"vignetteCancelButton";
			this->vignetteCancelButton->Size = System::Drawing::Size(71, 23);
			this->vignetteCancelButton->TabIndex = 202;
			this->vignetteCancelButton->Text = L"Cancel";
			this->vignetteCancelButton->UseVisualStyleBackColor = true;
			this->vignetteCancelButton->Click += gcnew System::EventHandler(this, &MainForm::vignetteCancelButton_Click);
			// 
			// vignetteResetButton
			// 
			this->vignetteResetButton->Location = System::Drawing::Point(95, 73);
			this->vignetteResetButton->Name = L"vignetteResetButton";
			this->vignetteResetButton->Size = System::Drawing::Size(75, 23);
			this->vignetteResetButton->TabIndex = 201;
			this->vignetteResetButton->Text = L"Reset";
			this->vignetteResetButton->UseVisualStyleBackColor = true;
			this->vignetteResetButton->Click += gcnew System::EventHandler(this, &MainForm::vignetteResetButton_Click);
			// 
			// vignetteApplyButton
			// 
			this->vignetteApplyButton->Location = System::Drawing::Point(176, 73);
			this->vignetteApplyButton->Name = L"vignetteApplyButton";
			this->vignetteApplyButton->Size = System::Drawing::Size(75, 23);
			this->vignetteApplyButton->TabIndex = 1;
			this->vignetteApplyButton->Text = L"Apply";
			this->vignetteApplyButton->UseVisualStyleBackColor = true;
			this->vignetteApplyButton->Click += gcnew System::EventHandler(this, &MainForm::vignetteApplyButton_Click);
			// 
			// vignetteTrackBar
			// 
			this->vignetteTrackBar->LargeChange = 1;
			this->vignetteTrackBar->Location = System::Drawing::Point(30, 22);
			this->vignetteTrackBar->Maximum = 100;
			this->vignetteTrackBar->Name = L"vignetteTrackBar";
			this->vignetteTrackBar->Size = System::Drawing::Size(209, 45);
			this->vignetteTrackBar->TabIndex = 200;
			this->vignetteTrackBar->Value = 50;
			this->vignetteTrackBar->ValueChanged += gcnew System::EventHandler(this, &MainForm::vignetteTrackBar_ValueChanged);
			this->vignetteTrackBar->TabIndexChanged += gcnew System::EventHandler(this, &MainForm::vignetteTrackBar_TabIndexChanged);
			// 
			// cropPanel
			// 
			this->cropPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->cropPanel->Controls->Add(this->cropApplyButton);
			this->cropPanel->Controls->Add(this->cropCancelButton);
			this->cropPanel->Controls->Add(this->cropResetButton);
			this->cropPanel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->cropPanel->Location = System::Drawing::Point(618, 65);
			this->cropPanel->Name = L"cropPanel";
			this->cropPanel->Size = System::Drawing::Size(264, 53);
			this->cropPanel->TabIndex = 6;
			this->cropPanel->Visible = false;
			// 
			// cropApplyButton
			// 
			this->cropApplyButton->Location = System::Drawing::Point(178, 15);
			this->cropApplyButton->Name = L"cropApplyButton";
			this->cropApplyButton->Size = System::Drawing::Size(75, 23);
			this->cropApplyButton->TabIndex = 6;
			this->cropApplyButton->Text = L"Apply";
			this->cropApplyButton->UseVisualStyleBackColor = true;
			this->cropApplyButton->Click += gcnew System::EventHandler(this, &MainForm::cropApplyButton_Click);
			// 
			// cropCancelButton
			// 
			this->cropCancelButton->Location = System::Drawing::Point(16, 15);
			this->cropCancelButton->Name = L"cropCancelButton";
			this->cropCancelButton->Size = System::Drawing::Size(75, 23);
			this->cropCancelButton->TabIndex = 5;
			this->cropCancelButton->Text = L"Cancel";
			this->cropCancelButton->UseVisualStyleBackColor = true;
			this->cropCancelButton->Click += gcnew System::EventHandler(this, &MainForm::cropCancelButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(909, 546);
			this->Controls->Add(this->cropPanel);
			this->Controls->Add(this->vignettePanel);
			this->Controls->Add(this->vignetteButton);
			this->Controls->Add(this->cropButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->vignettePanel->ResumeLayout(false);
			this->vignettePanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vignetteTrackBar))->EndInit();
			this->cropPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void importToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


				 OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
				 openFileDialog1->Filter = "All Graphics Types|*.bmp;*.jpg;*.jpeg;*.png;*.tif;*.tiff";
				 openFileDialog1->Title = "Select an Inage File";

				 // Show the Dialog.  
				 // If the user clicked OK in the dialog and  
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 // Assign the cursor in the Stream to  
					 // the Form's Cursor property. 
					 // cache.jpg is the copy of the original image used for editing

					 pictureBox1->Load(openFileDialog1->FileName);

					 System::String^ filePath=openFileDialog1->FileName;
					 std::string conFilePath=msclr::interop::marshal_as< std::string >( filePath);
					 mainImage = cv::imread(conFilePath);
					 imageImport = true;
					 cropButton->Enabled = true;
					 vignetteButton->Enabled = true;

				 }

			 }
	private: System::Void cropButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 cropSelected = true;
				 cropPanel->Visible = true;
				 vignetteButton->Enabled = false;

			 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {


			 }
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				 if(vignetteSelected){

					 vignetteCenterX = e->X;
					 vignetteCenterY = e->Y;

					 int tabValue = vignetteTrackBar->Value;
					 int sigma = mainImage.cols * tabValue /100 ;
					 vignetteImage = vignetteFilterOffset(&mainImage, sigma , vignetteCenterX , vignetteCenterY);
					 refreshPicBox(vignetteImage); 
				 }


			 }
	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				 if(cropSelected && cropStarted){


					 //pictureBox1->Refresh();
					 System::Drawing::Pen^ myBrush = gcnew System::Drawing::Pen(System::Drawing::Color::Red);
					 System::Drawing::Graphics^ formGraphics;

					 formGraphics = pictureBox1->CreateGraphics();

					 System::IntPtr ptr(mainImage.ptr());
					 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(mainImage.cols, mainImage.rows, mainImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					 formGraphics->DrawImage(b, 0, 0,mainImage.cols, mainImage.rows);

					 rectWidth = e->X - rectSX;
					 rectHeight= e->Y - rectSY;
					 formGraphics->DrawRectangle(myBrush, System::Drawing::Rectangle(rectSX , rectSY, rectWidth, rectHeight));

					 delete myBrush;
					 delete formGraphics; 

				 }

			 }
	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				 if(cropSelected){

					 rectSX = e->X;
					 rectSY = e->Y;
					 cropStarted = true;

				 }
			 }
	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				 if(cropSelected && cropStarted){

					 cropStarted = false;
					 // rectWidth = mainImage.cols * rectWidth/ 600 ;  // 600- width of the picture box
					 //rectHeight = mainImage.rows * rectHeight/ 500 ; // 400- height of the picture box
					 cv::Rect cropRectangle (rectSX, rectSY , rectWidth, rectHeight);
					 croppedImage = mainImage(cropRectangle);
					 pictureBox1->Refresh();
					 refreshPicBox(croppedImage);
				 }

			 }


	private: System::Void cropResetButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 pictureBox1->Refresh();
				 cropStarted = false;
				 cropSelected = true;
				 refreshPicBox(mainImage);
			 }
	private: System::Void vignetteButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 cropStarted = false;
				 cropSelected = false;
				 cropButton->Enabled = false;
				 vignetteSelected = true;
				 vignettePanel->Visible = true;
				 vignetteCenterX = mainImage.cols / 2 ;
				 vignetteCenterY = mainImage.rows / 2;
				 int tabValue = vignetteTrackBar->Value;
				 int sigma = mainImage.cols * tabValue /100 ;
				 vignetteImage = vignetteFilterOffset(&mainImage, sigma , vignetteCenterX , vignetteCenterY);
				 refreshPicBox(vignetteImage); 


			 }
	private: System::Void vignetteTrackBar_TabIndexChanged(System::Object^  sender, System::EventArgs^  e) {


			 }

			 cv::Mat vignetteFilterOffset(cv::Mat *image, int sigma, int offset_x,int offset_y){

				 cv::Mat imageTemp = *image;
				 std::vector<cv::Mat> channels(3), filtChannel;
				 cv::Mat filteredChannel[3];

				 int im_height = imageTemp.rows;
				 int im_width  = imageTemp.cols;

				 int xLen =0 , yLen =0;
				 bool xFlag = false  ,yFlag = false;
				 if ( (im_height - offset_y ) <  im_height/2 ) {
					 yLen = offset_y ;

				 }
				 else 
				 { 
					 yLen = im_height - offset_y ;
					 yFlag = true;
				 }

				 if ( (im_width - offset_x ) <  im_width/2 ) {
					 xLen = offset_x ;

				 }
				 else 
				 { 
					 xLen = im_width - offset_x ;
					 xFlag = true;
				 }

				 int cropX=0,cropY=0;
				 if(xFlag | yFlag){

					 cropY = yFlag ? yLen- offset_y : 0;
					 cropX = xFlag ? xLen- offset_x : 0;

				 }

				 cv::Mat kernel_x = cv::getGaussianKernel(yLen * 2, sigma);
				 cv::Mat kernel_y = cv::getGaussianKernel(xLen * 2, sigma);
				 cv::Mat filter = kernel_x * kernel_y.t();
				 cv::Mat mask (imageTemp.rows,imageTemp.cols, CV_8UC1);

				 cv::Rect cropRect(cropX,cropY,imageTemp.cols,imageTemp.rows);

				 cv::Mat filterCropped = filter(cropRect);
				 cv::normalize(filterCropped,mask,0,255,cv::NORM_MINMAX, CV_8UC1);
				 split(imageTemp,channels);

				 filteredChannel[0] = channels[0].mul(mask)/255;
				 filteredChannel[1] = channels[1].mul(mask)/255;
				 filteredChannel[2] = channels[2].mul(mask)/255;

				 filtChannel.push_back(filteredChannel[0]);
				 filtChannel.push_back(filteredChannel[1]);
				 filtChannel.push_back(filteredChannel[2]);

				 cv::Mat filteredImage(imageTemp.rows,imageTemp.cols, CV_8UC3);
				 cv::merge(filtChannel,filteredImage);
				 return filteredImage;	

			 }


	private: System::Void vignetteTrackBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 int tabValue = vignetteTrackBar->Value;
				 if(vignetteSelected){

					 int sigma = mainImage.cols * tabValue /100 ;
					 vignetteImage = vignetteFilterOffset(&mainImage, sigma , vignetteCenterX , vignetteCenterY);
					 refreshPicBox(vignetteImage); 
				 }
			 }
	private: System::Void vignetteResetButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 vignetteTrackBar->Value = 50;
				 vignetteSelected= true;
				 vignetteCenterX = mainImage.cols / 2 ;
				 vignetteCenterY = mainImage.rows / 2;
				 int tabValue = vignetteTrackBar->Value;
				 int sigma = mainImage.cols * tabValue /100 ;
				 vignetteImage = vignetteFilterOffset(&mainImage, sigma , vignetteCenterX , vignetteCenterY);
				 refreshPicBox(vignetteImage); 

			 }
	private: System::Void vignetteCancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 refreshPicBox(mainImage);
				 vignetteSelected = false;
				 vignettePanel->Visible = false;
				 cropButton->Enabled = true;
			 }

			 int refreshPicBox(cv::Mat displayImage)
			 {
				 // pictureBox1->Refresh();
				 System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
				 //graphics->Clear(System::Drawing::Color::White);
				 System::IntPtr ptr(displayImage.ptr());
				 try{
					 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(displayImage.cols, displayImage.rows, displayImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					 pictureBox1->Image = b;
				 }
				 catch(  System::ArgumentException^ e){
					 if(!displayImage.empty()){
						 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(displayImage.cols, displayImage.rows, displayImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
						 pictureBox1->Image = b;  
					 }
				 }
				 //graphics->DrawImage(b, 0, 0,displayImage.cols, displayImage.rows);

				 return 0;
			 }
	private: System::Void vignetteApplyButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 mainImage = vignetteImage;
				 System::IntPtr ptr(mainImage.ptr());
				 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(mainImage.cols, mainImage.rows, mainImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
				 pictureBox1->Image = b;
				 vignetteSelected = false; 
				 vignettePanel->Visible = false;
				 cropButton->Enabled = true;
			 }
	private: System::Void cropApplyButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 cropSelected= false;
				 cropStarted = false;
				 mainImage = croppedImage;
				 cropPanel->Visible = false;
				 vignetteButton->Enabled = true;

			 }
	private: System::Void cropCancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 cropSelected= false;
				 cropStarted = false;
				 cropPanel->Visible = false;
				 vignetteButton->Enabled = true;
				 refreshPicBox(mainImage);

			 }
	};


}
