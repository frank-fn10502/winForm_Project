// ArticulationPonit.cpp: �D�n�M���ɡC
#include "stdafx.h"
#include "Form1.h"
#include "Inside.h"

using namespace ArticulationPonit;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �إߥ��󱱨���e�A���ҥ� Windows XP ��ı�ƮĪG
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �إߥD�����ð���
	Application::Run(gcnew Form1());
	//Application::Run(gcnew Inside());
	return 0;
}
