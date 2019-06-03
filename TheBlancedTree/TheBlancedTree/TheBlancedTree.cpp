#include "DisplayForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace TheBlancedTree;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// 建立主視窗並執行
	Application::Run(gcnew DisplayForm());
	return 0;
}