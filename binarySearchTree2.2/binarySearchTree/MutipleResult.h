#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace binarySearchTree 
{
	/// <summary>
	/// MutipleResult ���K�n
	///
	/// ĵ�i: �p�G�z�ܧ�o�����O���W�١A�N�����ܧ�P�o�����O�Ҩ̾ڤ��Ҧ� .resx �ɮ����p��
	///          Managed �귽�sĶ���u�㪺 'Resource File Name' �ݩʡC
	///          �_�h�A�o�ǳ]�p�u��
	///          �N�L�k�P�o�Ӫ�����p����a�y�t�Ƹ귽
	///          ���T���ʡC
	/// </summary>
	public ref class MutipleResult : public System::Windows::Forms::Form
	{
	public:
		MutipleResult(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
		}
		MutipleResult(Forest* dictionary ,array<String^,2>^ insertData)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
			insertDictionary(dictionary ,insertData);
		}
		MutipleResult(Forest* dictionary ,String^ file)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
			insertDictionaryByFile(dictionary ,file);
		}
		MutipleResult(Forest* dictionary ,array<String^>^ deleteData)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
			deleteDictionary(dictionary ,deleteData);
		}
	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~MutipleResult()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: 
	private: System::Windows::Forms::Button^  go_back_button;
	private: System::Windows::Forms::Label^  fail_num_label;
	private: System::Windows::Forms::Label^  success_num_label;
	private: System::Windows::Forms::Label^  fail_label;
	private: System::Windows::Forms::Label^  success_label;
	private: System::Windows::Forms::RichTextBox^  display_richTextBox;



	private: System::ComponentModel::Container ^components;


	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		msclr::interop::marshal_context context;

		bool mode;
		String^ str;
		int success ,fail;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�o�Ӥ�k�����e�C
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->go_back_button = (gcnew System::Windows::Forms::Button());
			this->fail_num_label = (gcnew System::Windows::Forms::Label());
			this->success_num_label = (gcnew System::Windows::Forms::Label());
			this->fail_label = (gcnew System::Windows::Forms::Label());
			this->success_label = (gcnew System::Windows::Forms::Label());
			this->display_richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// go_back_button
			// 
			this->go_back_button->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->go_back_button->Location = System::Drawing::Point(100, 219);
			this->go_back_button->Name = L"go_back_button";
			this->go_back_button->Size = System::Drawing::Size(98, 29);
			this->go_back_button->TabIndex = 29;
			this->go_back_button->Text = L"�T�w";
			this->go_back_button->UseVisualStyleBackColor = true;
			this->go_back_button->Click += gcnew System::EventHandler(this, &MutipleResult::go_back_button_Click);
			// 
			// fail_num_label
			// 
			this->fail_num_label->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->fail_num_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->fail_num_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->fail_num_label->Location = System::Drawing::Point(227, 21);
			this->fail_num_label->Name = L"fail_num_label";
			this->fail_num_label->Size = System::Drawing::Size(61, 23);
			this->fail_num_label->TabIndex = 28;
			this->fail_num_label->Text = L"10";
			this->fail_num_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// success_num_label
			// 
			this->success_num_label->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->success_num_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->success_num_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->success_num_label->Location = System::Drawing::Point(90, 21);
			this->success_num_label->Name = L"success_num_label";
			this->success_num_label->Size = System::Drawing::Size(61, 23);
			this->success_num_label->TabIndex = 27;
			this->success_num_label->Text = L"100";
			this->success_num_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// fail_label
			// 
			this->fail_label->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->fail_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->fail_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->fail_label->Location = System::Drawing::Point(157, 21);
			this->fail_label->Name = L"fail_label";
			this->fail_label->Size = System::Drawing::Size(66, 23);
			this->fail_label->TabIndex = 26;
			this->fail_label->Text = L"�䤣��:";
			this->fail_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// success_label
			// 
			this->success_label->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->success_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->success_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->success_label->Location = System::Drawing::Point(6, 21);
			this->success_label->Name = L"success_label";
			this->success_label->Size = System::Drawing::Size(78, 23);
			this->success_label->TabIndex = 25;
			this->success_label->Text = L"�[�J���\:";
			this->success_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// display_richTextBox
			// 
			this->display_richTextBox->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->display_richTextBox->Location = System::Drawing::Point(10, 59);
			this->display_richTextBox->Name = L"display_richTextBox";
			this->display_richTextBox->Size = System::Drawing::Size(280, 145);
			this->display_richTextBox->TabIndex = 24;
			this->display_richTextBox->Text = L"1. apple --> ī�G     �[�J���\\n2. apple --> ī�G     �[�J���\\n3. apple --> ī�G     �[�J���\\n4. app" 
				L"le --> ī�G     �[�J���\\n5. apple --> ī�G     �[�J���\\n6. apple --> ī�G     �[�J���\";
			// 
			// MutipleResult
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 269);
			this->Controls->Add(this->go_back_button);
			this->Controls->Add(this->fail_num_label);
			this->Controls->Add(this->success_num_label);
			this->Controls->Add(this->fail_label);
			this->Controls->Add(this->success_label);
			this->Controls->Add(this->display_richTextBox);
			this->Name = L"MutipleResult";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"���G";
			this->Load += gcnew System::EventHandler(this, &MutipleResult::MutipleResult_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void insertDictionary(Forest* dictionary ,array<String^,2>^ insertData)
			 {
				 str = "";
				 success = 0;
				 fail    = 0;
				 bool result;
				 for(int i = 0 ; i < insertData->Length/2 ; i ++ )
				 {
					 result = dictionary->insertNode( getStdString(insertData[i,0])
													, getStdString(insertData[i,1]));

					 if( result ) success++;
					 else		  fail++;

					 if( i > 0 ) str += "\n";

					 str += insertData[i,0] + /*" --> " + insertData[i,1] +*/ "     " + (result? "�[�J���\" : "����");
				 }
				 mode = true;
			 }
	private: void insertDictionaryByFile(Forest* dictionary ,String^ file)
			 {
				 str = "";
				 success = 0;
				 fail    = 0;
				 bool result;
				 String^ ChStr;
				 std::string en ,ch;
				 fstream fin;
				 fin.open(getStdString(file).c_str(),ios::in);
				 while( fin >> en >> ch )
				 {
					 std::transform(en.begin(), en.end(), en.begin(), ::tolower);
					 ChStr = gcnew String(ch.c_str());
					 ChStr = ChStr->ToLower();

					 
					 result = dictionary->insertNode(en ,getStdString(ChStr) );

					 if( result ) success++;
					 else		  fail++;

					 if( str != "" ) str += "\n";

					 str += gcnew String( en.c_str() ) + /*" --> " + 
						    gcnew String( ch.c_str() ) +*/ "     " + (result? "�[�J���\" : "����");
				 }
				 fin.close();
				 mode = true;
			 }
	private: void deleteDictionary(Forest* dictionary ,array<String^>^ deleteData)
			 {
				 str = "";
				 success = 0;
				 fail    = 0;
				 bool result;
				 for(int i = 0 ; i < deleteData->Length ; i ++ )
				 {
					 result = dictionary->deleteNode( getStdString(deleteData[i]) );

					 if( result ) success++;
					 else		  fail++;

					 if( i > 0 ) str += "\n";

					 str += deleteData[i] + "     " + (result? "�R�����\" : "�䤣��");
				 }
				 mode = false;
			 }
	private: std::string getStdString(String^ str)
			 {
				return context.marshal_as<std::string>(str);
			 }
	/*=====================================================================================*/
	private: System::Void MutipleResult_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( mode )
				 {
					 this->Text = "�[�J���G";
					 success_label->Text = "�[�J���\:";
					 fail_label->Text = "����:";
				 }
				 else
				 {
					 this->Text = "�R�����G";
					 success_label->Text = "�R�����\:";
					 fail_label->Text = "�䤣��:";
				 }
				 success_num_label->Text = success.ToString();
				 fail_num_label->Text    = fail.ToString();
				 display_richTextBox->Text = str;
			 }
	private: System::Void go_back_button_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 this->Close();
			 }
	};
}
