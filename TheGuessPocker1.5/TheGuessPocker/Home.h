#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;////////


namespace TheGuessPocker 
{

	/// <summary>
	/// Home ���K�n
	///
	/// ĵ�i: �p�G�z�ܧ�o�����O���W�١A�N�����ܧ�P�o�����O�Ҩ̾ڤ��Ҧ� .resx �ɮ����p��
	///          Managed �귽�sĶ���u�㪺 'Resource File Name' �ݩʡC
	///          �_�h�A�o�ǳ]�p�u��
	///          �N�L�k�P�o�Ӫ�����p����a�y�t�Ƹ귽
	///          ���T���ʡC
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
		}
		Home(int *form ,int* OldGame ,bool* IsLoad ,int* from)
		{
			InitializeComponent();
			*form    = -1;	////
			*from    =  1;
			*OldGame =  0;
			*IsLoad  = true;

			ToForm   = form;
		}
	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  NewGame;
	private: System::Windows::Forms::Button^  OldGameStart;

	protected: 


	private: System::Windows::Forms::Panel^  HomePanel;
	private: System::Windows::Forms::Panel^  SetUpPanel;
	private: System::Windows::Forms::ComboBox^  DifficultyComboBox;
	private: System::Windows::Forms::Label^  DifficultyLabel;
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::CheckBox^  UseRTcheckBox;

	protected:

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		int*  ToForm;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�o�Ӥ�k�����e�C
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->NewGame = (gcnew System::Windows::Forms::Button());
			this->OldGameStart = (gcnew System::Windows::Forms::Button());
			this->HomePanel = (gcnew System::Windows::Forms::Panel());
			this->UseRTcheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->DifficultyComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DifficultyLabel = (gcnew System::Windows::Forms::Label());
			this->SetUpPanel = (gcnew System::Windows::Forms::Panel());
			this->HomePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// NewGame
			// 
			this->NewGame->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->NewGame->Location = System::Drawing::Point(90, 56);
			this->NewGame->Name = L"NewGame";
			this->NewGame->Size = System::Drawing::Size(104, 33);
			this->NewGame->TabIndex = 0;
			this->NewGame->Text = L"�s�C��";
			this->NewGame->UseVisualStyleBackColor = true;
			this->NewGame->Click += gcnew System::EventHandler(this, &Home::NewGame_Click);
			// 
			// OldGameStart
			// 
			this->OldGameStart->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->OldGameStart->Location = System::Drawing::Point(90, 104);
			this->OldGameStart->Name = L"OldGameStart";
			this->OldGameStart->Size = System::Drawing::Size(104, 33);
			this->OldGameStart->TabIndex = 1;
			this->OldGameStart->Text = L"���J�s��";
			this->OldGameStart->UseVisualStyleBackColor = true;
			this->OldGameStart->Click += gcnew System::EventHandler(this, &Home::OldGameStart_Click);
			// 
			// HomePanel
			// 
			this->HomePanel->Controls->Add(this->UseRTcheckBox);
			this->HomePanel->Controls->Add(this->DifficultyComboBox);
			this->HomePanel->Controls->Add(this->DifficultyLabel);
			this->HomePanel->Controls->Add(this->NewGame);
			this->HomePanel->Controls->Add(this->OldGameStart);
			this->HomePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HomePanel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->HomePanel->Location = System::Drawing::Point(0, 0);
			this->HomePanel->Name = L"HomePanel";
			this->HomePanel->Size = System::Drawing::Size(284, 261);
			this->HomePanel->TabIndex = 3;
			// 
			// UseRTcheckBox
			// 
			this->UseRTcheckBox->AutoSize = true;
			this->UseRTcheckBox->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->UseRTcheckBox->Location = System::Drawing::Point(157, 165);
			this->UseRTcheckBox->Name = L"UseRTcheckBox";
			this->UseRTcheckBox->Size = System::Drawing::Size(95, 20);
			this->UseRTcheckBox->TabIndex = 5;
			this->UseRTcheckBox->Text = L"�O�Юɶ�";
			this->UseRTcheckBox->UseVisualStyleBackColor = true;
			// 
			// DifficultyComboBox
			// 
			this->DifficultyComboBox->DropDownHeight = 50;
			this->DifficultyComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->DifficultyComboBox->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->DifficultyComboBox->FormattingEnabled = true;
			this->DifficultyComboBox->IntegralHeight = false;
			this->DifficultyComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"²��", L"���q", L"�x��"});
			this->DifficultyComboBox->Location = System::Drawing::Point(78, 163);
			this->DifficultyComboBox->Name = L"DifficultyComboBox";
			this->DifficultyComboBox->Size = System::Drawing::Size(64, 24);
			this->DifficultyComboBox->TabIndex = 4;
			// 
			// DifficultyLabel
			// 
			this->DifficultyLabel->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->DifficultyLabel->Location = System::Drawing::Point(35, 165);
			this->DifficultyLabel->Name = L"DifficultyLabel";
			this->DifficultyLabel->Size = System::Drawing::Size(55, 19);
			this->DifficultyLabel->TabIndex = 3;
			this->DifficultyLabel->Text = L"����: ";
			this->DifficultyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SetUpPanel
			// 
			this->SetUpPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SetUpPanel->Location = System::Drawing::Point(0, 0);
			this->SetUpPanel->Name = L"SetUpPanel";
			this->SetUpPanel->Size = System::Drawing::Size(284, 261);
			this->SetUpPanel->TabIndex = 3;
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->HomePanel);
			this->Controls->Add(this->SetUpPanel);
			this->Name = L"Home";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Home";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			this->HomePanel->ResumeLayout(false);
			this->HomePanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void Home_Load(System::Object^  sender, System::EventArgs^  e) 
			 { 
				 String^ Path = Path::GetFullPath( "..\\Save\\" );
				 /*------------------------------------*/
				 DifficultyComboBox->SelectedIndex = 0;
				 UseRTcheckBox->Checked = false;
				 
				 OldGameStart->Enabled = false;
				 String^ fileName;
				 for(int i = 1 ; i <= 10 ; i ++)
				 {
					 fileName = Path  +  "GameSave" + i.ToString() + ".txt";
					 if( File::Exists( fileName ) )		
					 {
						OldGameStart->Enabled = true;
						break;
					 }
				 }
			 }
	private: System::Void NewGame_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				int num = DifficultyComboBox->SelectedIndex;

				String^ Path1 = Path::GetFullPath( "..\\Difficulty\\" );
				String^ fileName1 = Path1  +  num.ToString() + ".txt";
				String^ str = File::ReadAllText( fileName1 ,System::Text::Encoding::GetEncoding("big5") );
				if( UseRTcheckBox->Checked )
				{
					str = str->Replace("�O�Юɶ�: false" ,"�O�Юɶ�: true");
				}
				else
				{
					String^ temp = str->Substring(str->IndexOf("�˼Ʈɶ�:") ,14 );
					str = str->Replace(temp ,"�˼Ʈɶ�: None");
				}

				String^ Path2 = Path::GetFullPath( "..\\GameData\\" );
				String^ fileName2 = Path2  +  "Game.txt";
				File::WriteAllText(fileName2 ,str);

				//File::Copy(fileName1 ,fileName2 ,true);
				*ToForm = 2;
				this->Close();
			 }
	private: System::Void OldGameStart_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 *ToForm = 10;  //��s�ɭ���
				 this->Close();
			 }

	};//end of class Home 
}//end of namespace TheGuessPocker
