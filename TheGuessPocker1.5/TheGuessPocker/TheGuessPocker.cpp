// TheGuessPocker.cpp: �D�n�M���ɡC

#include "stdafx.h"
#include "SavePage.h"
#include "Form1.h"
#include "Home.h"

using namespace TheGuessPocker;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	int form = 1; //1
	int from = 0;
	int OldGame = 0;
	bool IsLoad = true;
	// �إߥ��󱱨���e�A���ҥ� Windows XP ��ı�ƮĪG
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �إߥD�����ð���
	while(form != -1)
    {
		if( form == 1)		  Application::Run(gcnew Home( &form ,&OldGame ,&IsLoad ,&from));
		else if( form == 2 )  Application::Run(gcnew Form1(&form ,&OldGame ,&IsLoad ,&from));//������
		else if( form == 10 ) Application::Run(gcnew SavePage(&form ,&OldGame ,IsLoad ,from));//
	}
	//Application::Run(gcnew Form1(&form ,&difficulty ,&OldGame ));
	return 0;
}
