#include "DisplayForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace TheBlancedTree;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �إߥD�����ð���
	Application::Run(gcnew DisplayForm());
	return 0;
}