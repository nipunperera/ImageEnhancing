#include "MainForm.h"
#include <Windows.h>


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]



int main(array<System::String^>^ args)
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUIImageEnhancer::MainForm form;
	Application::Run(%form);
}

