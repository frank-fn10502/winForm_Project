// TheSpaceMergeSort.cpp: �D�n�M���ɡC

#include "stdafx.h"
#include "TheSortForm.h"

using namespace TheSpaceMergeSort;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �إߥ��󱱨���e�A���ҥ� Windows XP ��ı�ƮĪG
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �إߥD�����ð���
	Application::Run(gcnew TheSortForm());
	return 0;
}
