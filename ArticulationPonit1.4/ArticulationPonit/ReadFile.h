#pragma once

using namespace System;
using namespace System::Windows::Forms;

//typedef void (*Process)(String^ );
public delegate void Process(String^);

ref class ReadFile
{
public:
	ReadFile(void){}
	void readTxtFile(Process^ process)//�Ƕi�� �B�z����k
	{
		 OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		 openFileDialog->Filter = "txt files (*.txt)|*.txt";

		 if(openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
		 {
			 process(openFileDialog->FileName);
		 }
	}
};
