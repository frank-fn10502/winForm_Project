#pragma once
#include "TheColor.h"
#include "BallMove.h"
#include <stdlib.h>
#include <time.h>


namespace TheBall {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			srand((unsigned int)time(NULL));
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^   StartBtn;  
	private: System::Windows::Forms::Label^    Ball_number;
	private: System::Windows::Forms::TextBox^  BallN_input;
    private: System::Windows::Forms::Label^    Ball_sele;
    private: System::Windows::Forms::ComboBox^ Ball_sele_comboBox;
/*=============================panel====================================*/ //參考
	private: System::Windows::Forms::Panel^   Selection_Panel;	
	private: System::Windows::Forms::Label^   WhatBall;
    private: System::Windows::Forms::Label^   Ball_Speed;   
	private: System::Windows::Forms::Label^   Ball_Color;
	private: System::Windows::Forms::ComboBox^Ball_Color_comboBox;
	private: System::Windows::Forms::TextBox^ BallPos_y_input;
	private: System::Windows::Forms::Label^   BallPosition_y;
	private: System::Windows::Forms::TextBox^ BallPos_x_input;
	private: System::Windows::Forms::Label^   BallPosition_x;
	private: System::Windows::Forms::Label^   Ball_Position;
	private: System::Windows::Forms::TextBox^ BallDir_y_input;
	private: System::Windows::Forms::Label^   BallDirection_y;
	private: System::Windows::Forms::TextBox^ BallDir_x_input;
	private: System::Windows::Forms::Label^   BallDirection_x;
	private: System::Windows::Forms::Label^   Ball_Direction;
	private: System::Windows::Forms::Button^  AllrandomBtn;
	private: System::Windows::Forms::Button^  in_Allrandom_N;
	private: System::Windows::Forms::Label^   label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^  Ballspeed_input;
/*=============================panel====================================*/	
	
	System::ComponentModel::Container ^components;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		static array<Ball^> ^b ; 
		static int N = 5;
		static int LABEL = 0 ,TEXTBOX = 0; 
		static int SN = 0;
		//////////////////

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->StartBtn = (gcnew System::Windows::Forms::Button());
			this->Ball_number = (gcnew System::Windows::Forms::Label());
			this->BallN_input = (gcnew System::Windows::Forms::TextBox());
			this->Selection_Panel = (gcnew System::Windows::Forms::Panel());
			this->Ballspeed_input = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->in_Allrandom_N = (gcnew System::Windows::Forms::Button());
			this->WhatBall = (gcnew System::Windows::Forms::Label());
			this->Ball_Color_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Ball_Color = (gcnew System::Windows::Forms::Label());
			this->BallPos_y_input = (gcnew System::Windows::Forms::TextBox());
			this->BallPosition_y = (gcnew System::Windows::Forms::Label());
			this->BallPos_x_input = (gcnew System::Windows::Forms::TextBox());
			this->BallPosition_x = (gcnew System::Windows::Forms::Label());
			this->Ball_Position = (gcnew System::Windows::Forms::Label());
			this->BallDir_y_input = (gcnew System::Windows::Forms::TextBox());
			this->BallDirection_y = (gcnew System::Windows::Forms::Label());
			this->BallDir_x_input = (gcnew System::Windows::Forms::TextBox());
			this->BallDirection_x = (gcnew System::Windows::Forms::Label());
			this->Ball_Direction = (gcnew System::Windows::Forms::Label());
			this->Ball_Speed = (gcnew System::Windows::Forms::Label());
			this->Ball_sele_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Ball_sele = (gcnew System::Windows::Forms::Label());
			this->AllrandomBtn = (gcnew System::Windows::Forms::Button());
			this->Selection_Panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// StartBtn
			// 
			this->StartBtn->Location = System::Drawing::Point(184, 308);
			this->StartBtn->Name = L"StartBtn";
			this->StartBtn->Size = System::Drawing::Size(75, 22);
			this->StartBtn->TabIndex = 0;
			this->StartBtn->Text = L"開始";
			this->StartBtn->UseVisualStyleBackColor = true;
			this->StartBtn->Visible = false;
			this->StartBtn->Click += gcnew System::EventHandler(this, &Form1::StartBtn_Click);
			// 
			// Ball_number
			// 
			this->Ball_number->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Ball_number->Location = System::Drawing::Point(13, 22);
			this->Ball_number->Name = L"Ball_number";
			this->Ball_number->Size = System::Drawing::Size(82, 19);
			this->Ball_number->TabIndex = 1;
			this->Ball_number->Text = L"球的數目: ";
			this->Ball_number->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// BallN_input
			// 
			this->BallN_input->Location = System::Drawing::Point(101, 22);
			this->BallN_input->Name = L"BallN_input";
			this->BallN_input->Size = System::Drawing::Size(82, 22);
			this->BallN_input->TabIndex = 2;
			this->BallN_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::BallN_input_KeyDown);
			// 
			// Selection_Panel
			// 
			this->Selection_Panel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Selection_Panel->Controls->Add(this->Ballspeed_input);
			this->Selection_Panel->Controls->Add(this->textBox1);
			this->Selection_Panel->Controls->Add(this->label1);
			this->Selection_Panel->Controls->Add(this->in_Allrandom_N);
			this->Selection_Panel->Controls->Add(this->WhatBall);
			this->Selection_Panel->Controls->Add(this->Ball_Color_comboBox);
			this->Selection_Panel->Controls->Add(this->Ball_Color);
			this->Selection_Panel->Controls->Add(this->BallPos_y_input);
			this->Selection_Panel->Controls->Add(this->BallPosition_y);
			this->Selection_Panel->Controls->Add(this->BallPos_x_input);
			this->Selection_Panel->Controls->Add(this->BallPosition_x);
			this->Selection_Panel->Controls->Add(this->Ball_Position);
			this->Selection_Panel->Controls->Add(this->BallDir_y_input);
			this->Selection_Panel->Controls->Add(this->BallDirection_y);
			this->Selection_Panel->Controls->Add(this->BallDir_x_input);
			this->Selection_Panel->Controls->Add(this->BallDirection_x);
			this->Selection_Panel->Controls->Add(this->Ball_Direction);
			this->Selection_Panel->Controls->Add(this->Ball_Speed);
			this->Selection_Panel->Location = System::Drawing::Point(16, 81);
			this->Selection_Panel->Name = L"Selection_Panel";
			this->Selection_Panel->Size = System::Drawing::Size(243, 221);
			this->Selection_Panel->TabIndex = 20;
			this->Selection_Panel->Visible = false;
			// 
			// Ballspeed_input
			// 
			this->Ballspeed_input->Location = System::Drawing::Point(100, 76);
			this->Ballspeed_input->Name = L"Ballspeed_input";
			this->Ballspeed_input->Size = System::Drawing::Size(56, 22);
			this->Ballspeed_input->TabIndex = 58;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(100, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(56, 22);
			this->textBox1->TabIndex = 57;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(13, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 19);
			this->label1->TabIndex = 56;
			this->label1->Text = L"球的大小:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// in_Allrandom_N
			// 
			this->in_Allrandom_N->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->in_Allrandom_N->Location = System::Drawing::Point(164, 13);
			this->in_Allrandom_N->Name = L"in_Allrandom_N";
			this->in_Allrandom_N->Size = System::Drawing::Size(72, 23);
			this->in_Allrandom_N->TabIndex = 55;
			this->in_Allrandom_N->Text = L"亂數";
			this->in_Allrandom_N->UseVisualStyleBackColor = false;
			// 
			// WhatBall
			// 
			this->WhatBall->AutoSize = true;
			this->WhatBall->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->WhatBall->Location = System::Drawing::Point(15, 15);
			this->WhatBall->Name = L"WhatBall";
			this->WhatBall->Size = System::Drawing::Size(143, 16);
			this->WhatBall->TabIndex = 54;
			this->WhatBall->Text = L"第 %d 顆球的屬性";
			this->WhatBall->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Ball_Color_comboBox
			// 
			this->Ball_Color_comboBox->FormattingEnabled = true;
			this->Ball_Color_comboBox->Location = System::Drawing::Point(66, 175);
			this->Ball_Color_comboBox->Name = L"Ball_Color_comboBox";
			this->Ball_Color_comboBox->Size = System::Drawing::Size(116, 20);
			this->Ball_Color_comboBox->TabIndex = 53;
			// 
			// Ball_Color
			// 
			this->Ball_Color->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Ball_Color->Location = System::Drawing::Point(12, 172);
			this->Ball_Color->Name = L"Ball_Color";
			this->Ball_Color->Size = System::Drawing::Size(42, 23);
			this->Ball_Color->TabIndex = 52;
			this->Ball_Color->Text = L"顏色";
			this->Ball_Color->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BallPos_y_input
			// 
			this->BallPos_y_input->Location = System::Drawing::Point(148, 144);
			this->BallPos_y_input->Name = L"BallPos_y_input";
			this->BallPos_y_input->Size = System::Drawing::Size(34, 22);
			this->BallPos_y_input->TabIndex = 50;
			// 
			// BallPosition_y
			// 
			this->BallPosition_y->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->BallPosition_y->Location = System::Drawing::Point(127, 144);
			this->BallPosition_y->Name = L"BallPosition_y";
			this->BallPosition_y->Size = System::Drawing::Size(31, 18);
			this->BallPosition_y->TabIndex = 51;
			this->BallPosition_y->Text = L"Y: ";
			// 
			// BallPos_x_input
			// 
			this->BallPos_x_input->Location = System::Drawing::Point(84, 143);
			this->BallPos_x_input->Name = L"BallPos_x_input";
			this->BallPos_x_input->Size = System::Drawing::Size(34, 22);
			this->BallPos_x_input->TabIndex = 48;
			// 
			// BallPosition_x
			// 
			this->BallPosition_x->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->BallPosition_x->Location = System::Drawing::Point(63, 143);
			this->BallPosition_x->Name = L"BallPosition_x";
			this->BallPosition_x->Size = System::Drawing::Size(31, 18);
			this->BallPosition_x->TabIndex = 49;
			this->BallPosition_x->Text = L"X: ";
			// 
			// Ball_Position
			// 
			this->Ball_Position->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Ball_Position->Location = System::Drawing::Point(12, 143);
			this->Ball_Position->Name = L"Ball_Position";
			this->Ball_Position->Size = System::Drawing::Size(45, 19);
			this->Ball_Position->TabIndex = 47;
			this->Ball_Position->Text = L"位置";
			this->Ball_Position->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BallDir_y_input
			// 
			this->BallDir_y_input->Location = System::Drawing::Point(148, 110);
			this->BallDir_y_input->Name = L"BallDir_y_input";
			this->BallDir_y_input->Size = System::Drawing::Size(34, 22);
			this->BallDir_y_input->TabIndex = 45;
			// 
			// BallDirection_y
			// 
			this->BallDirection_y->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->BallDirection_y->Location = System::Drawing::Point(127, 110);
			this->BallDirection_y->Name = L"BallDirection_y";
			this->BallDirection_y->Size = System::Drawing::Size(31, 18);
			this->BallDirection_y->TabIndex = 46;
			this->BallDirection_y->Text = L"Y: ";
			// 
			// BallDir_x_input
			// 
			this->BallDir_x_input->Location = System::Drawing::Point(84, 109);
			this->BallDir_x_input->Name = L"BallDir_x_input";
			this->BallDir_x_input->Size = System::Drawing::Size(34, 22);
			this->BallDir_x_input->TabIndex = 43;
			// 
			// BallDirection_x
			// 
			this->BallDirection_x->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->BallDirection_x->Location = System::Drawing::Point(63, 109);
			this->BallDirection_x->Name = L"BallDirection_x";
			this->BallDirection_x->Size = System::Drawing::Size(31, 18);
			this->BallDirection_x->TabIndex = 44;
			this->BallDirection_x->Text = L"X: ";
			// 
			// Ball_Direction
			// 
			this->Ball_Direction->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Ball_Direction->Location = System::Drawing::Point(12, 109);
			this->Ball_Direction->Name = L"Ball_Direction";
			this->Ball_Direction->Size = System::Drawing::Size(45, 19);
			this->Ball_Direction->TabIndex = 42;
			this->Ball_Direction->Text = L"方向";
			this->Ball_Direction->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Ball_Speed
			// 
			this->Ball_Speed->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Ball_Speed->Location = System::Drawing::Point(12, 76);
			this->Ball_Speed->Name = L"Ball_Speed";
			this->Ball_Speed->Size = System::Drawing::Size(82, 19);
			this->Ball_Speed->TabIndex = 37;
			this->Ball_Speed->Text = L"球的速度:";
			this->Ball_Speed->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Ball_sele_comboBox
			// 
			this->Ball_sele_comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Ball_sele_comboBox->FormattingEnabled = true;
			this->Ball_sele_comboBox->Location = System::Drawing::Point(100, 52);
			this->Ball_sele_comboBox->Name = L"Ball_sele_comboBox";
			this->Ball_sele_comboBox->Size = System::Drawing::Size(83, 20);
			this->Ball_sele_comboBox->TabIndex = 21;
			this->Ball_sele_comboBox->Visible = false;
			this->Ball_sele_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::Ball_sele_comboBox_SelectedIndexChanged);
			// 
			// Ball_sele
			// 
			this->Ball_sele->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Ball_sele->Location = System::Drawing::Point(14, 52);
			this->Ball_sele->Name = L"Ball_sele";
			this->Ball_sele->Size = System::Drawing::Size(81, 23);
			this->Ball_sele->TabIndex = 22;
			this->Ball_sele->Text = L"設定屬性";
			this->Ball_sele->Visible = false;
			// 
			// AllrandomBtn
			// 
			this->AllrandomBtn->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->AllrandomBtn->Location = System::Drawing::Point(189, 50);
			this->AllrandomBtn->Name = L"AllrandomBtn";
			this->AllrandomBtn->Size = System::Drawing::Size(71, 25);
			this->AllrandomBtn->TabIndex = 23;
			this->AllrandomBtn->Text = L"全部亂數";
			this->AllrandomBtn->UseVisualStyleBackColor = true;
			this->AllrandomBtn->Visible = false;
			this->AllrandomBtn->Click += gcnew System::EventHandler(this, &Form1::AllrandomBtn_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(271, 338);
			this->Controls->Add(this->AllrandomBtn);
			this->Controls->Add(this->Ball_sele);
			this->Controls->Add(this->Ball_sele_comboBox);
			this->Controls->Add(this->BallN_input);
			this->Controls->Add(this->Ball_number);
			this->Controls->Add(this->StartBtn);
			this->Controls->Add(this->Selection_Panel);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Selection_Panel->ResumeLayout(false);
			this->Selection_Panel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void BallN_input_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) // 沒排除 數字 以外的輸入
			 {			 
				 if( e->KeyCode == Keys::Enter )
				 {
					 N = Convert::ToInt32(BallN_input->Text);
					 b = gcnew array<Ball^>(N);		

					 Ball_sele_comboBox->Items->Clear();
					 for(int i = 0 ; i < N ; i++)
					 {
						b[i] = gcnew Ball();
						Ball_sele_comboBox->Items->Add("第"+(i+1).ToString()+"顆球");					
					 }				 
					 Ball_sele_comboBox->SelectedIndex = 0;			
					 
					 AllrandomBtn->Visible = true;
					 Ball_sele->Visible = true;
					 Ball_sele_comboBox->Visible = true;
					 Selection_Panel->Visible = true;
					 StartBtn->Visible = true;
				 }
			 }	
	private: System::Void Ball_sele_comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				LABEL = 0;
				TEXTBOX = 0;
				Selection_Panel->Controls->Clear();
				SN = Ball_sele_comboBox->SelectedIndex;

				AddNewBallselection();
				SaveData();
			 }  
	private: System::Void SingleRandomBtn_Click(System::Object^  sender, System::EventArgs^  e) ////////////////////////////
			 {
				RandomNum_Set(SN ,SN+1 );
			 }
    private: System::Void AllrandomBtn_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				RandomNum_Set(0 ,N );
			}
 	private: System::Void StartBtn_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
			    SaveData();

				BallMove^ ballmove = gcnew BallMove(b , N );
				this->Hide();
				ballmove->ShowDialog(this);

				if( BallMove::close ) this->Close();
			    else				  
				{
					changeData();
					this->Show();
				}			
			 }
/*================================================存值===============================================================*/
	private: void SaveData()
			 {
				for(int i = 0 ; i < TEXTBOX ; ++i)
				{
					System::Windows::Forms::TextBox^ textbox = (TextBox^)Selection_Panel->Controls->Find(i.ToString() + "T",true)[0]; 
					setData(i ,Convert::ToDouble(textbox->Text) );			
				}
				System::Windows::Forms::ComboBox^ combobox = (ComboBox^)Selection_Panel->Controls->Find("C",true)[0];
				b[SN]->setColor( combobox->SelectedIndex );
			 }
	private: void setData(int setw ,double d)
			 {
				switch(setw)
				{
					case 0:
						b[SN]->setBallsize(d);
						break;
					case 1:
						b[SN]->setBallsp(d);
						break;
					case 2:
						b[SN]->setBalldir_x(d);
						break;
					case 3:
						b[SN]->setBalldir_y(d);
						break;
					case 4:
						b[SN]->setBallpos_x(d);
						break;
					case 5:
						b[SN]->setBallpos_y(d);
						break;
				}
			 }
/*================================================動態panel==========================================================*/
	private: void AddNewBallselection()
			 {
				Panel^ Selection = gcnew Panel();

				Selection->Size = System::Drawing::Size(243, 221);
				Selection->Name = SN.ToString();
				Selection->Location = System::Drawing::Point(0, 0);
				Selection->BackColor = System::Drawing::SystemColors::ActiveCaption;
						
				Selection_Panel->Controls->Add(Selection);
				AddNewControl(Selection);			
			 }
    private: void AddNewControl(Panel^% panel_se )
			 {
			    String^ str = "第" + (SN+1).ToString() + "顆球的屬性";
				panel_se->Controls->Add(AddNewLabel(str ,143,16,15,15));

				panel_se->Controls->Add(AddNewLabel("球的大小:" ,81 ,22 ,14 ,45));
				panel_se->Controls->Add(AddNewTextBox(b[SN]->getBallsize().ToString() ,34 ,22 ,100 ,45));

				panel_se->Controls->Add(AddNewLabel("球的速度:" ,81 ,22 ,14 ,78));
				panel_se->Controls->Add(AddNewTextBox(b[SN]->getBallspeed().ToString() ,34 ,22 ,100 ,78));	

				panel_se->Controls->Add(AddNewLabel("方向" ,45 ,22 ,14 ,111));
				panel_se->Controls->Add(AddNewLabel("X:" ,31 ,22 ,65 ,111));
				panel_se->Controls->Add(AddNewTextBox(b[SN]->getBalldirection_x().ToString() ,34 ,22 ,86 ,111));
				panel_se->Controls->Add(AddNewLabel("Y:",31 ,22 ,129 ,111));
				panel_se->Controls->Add(AddNewTextBox(b[SN]->getBalldirection_y().ToString() ,34 ,22 ,150, 111));
				
				panel_se->Controls->Add(AddNewLabel("位置" ,45 ,22 ,14 ,144));
				panel_se->Controls->Add(AddNewLabel("X:" ,31 ,22 ,65 ,144));
				panel_se->Controls->Add(AddNewTextBox(b[SN]->getBallposition_x().ToString() ,34 ,22 ,86 ,144));
				panel_se->Controls->Add(AddNewLabel("Y:",31 ,22 ,129 ,144));
				panel_se->Controls->Add(AddNewTextBox(b[SN]->getBallposition_y().ToString() ,34 ,22 ,150, 144));

				panel_se->Controls->Add(AddNewLabel("顏色" ,45 ,22 ,14 ,177));
				panel_se->Controls->Add(AddNewComboBox(116 ,22 ,68, 180));

				panel_se->Controls->Add(AddNewButton(72 ,23 ,159 ,15));

				for(int  i = 0 ; i < TEXTBOX ; ++i)
				{
					TextBox^ textbox = (TextBox^)panel_se->Controls->Find(i.ToString() + "T",true)[0];
					textbox->BringToFront();
				}
			 }
	private: Label^ AddNewLabel(String^ text , int size_x,int size_y,int loc_x , int loc_y)
			 {
				Label^ label_temp  = gcnew Label();
				
				label_temp->Font = (gcnew System::Drawing::Font(L"新細明體", 12, FontStyle::Bold, GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
				label_temp->Size = Drawing::Size(size_x, size_y);
				label_temp->Location = Point(loc_x, loc_y);

				label_temp->TextAlign = ContentAlignment::MiddleLeft;

				label_temp->Name =  LABEL.ToString() + "L";
				//label_temp->ForeColor = Color::Gray;
				label_temp->Text = text;

				LABEL++;

				return label_temp ;			
			 }
	private: TextBox^ AddNewTextBox(String^ text, int size_x,int size_y,int loc_x , int loc_y)
			 {
				TextBox^ texbox_temp = gcnew TextBox();

				texbox_temp->Size = Drawing::Size(size_x, size_y);
				texbox_temp->Location = Point(loc_x, loc_y);

				texbox_temp->Name = TEXTBOX.ToString() + "T";
			//	texbox_temp->ForeColor = Color::Gray;
				texbox_temp->Text = text;

				TEXTBOX++;

				return texbox_temp;
			 }
    private: ComboBox^ AddNewComboBox(int size_x ,int size_y ,int loc_x ,int loc_y )
			 {
				ComboBox^ combobox_temp  = gcnew ComboBox();
				
				combobox_temp->Size     = Drawing::Size(size_x, size_y);
				combobox_temp->Location = Point(loc_x, loc_y);

				combobox_temp->Name = "C";
				combobox_temp->DropDownStyle = ComboBoxStyle::DropDownList;
				

				for(int i = 0 ; i < TheColor::getArrayNum() ; i ++)
				{
					combobox_temp->Items->Add( TheColor::getOneOfArray(i) );
				}
				combobox_temp->SelectedIndex = combobox_temp->Items->IndexOf(b[SN]->getColorString());

				return combobox_temp;
			 }
	private: Button^ AddNewButton(int size_x ,int size_y ,int loc_x ,int loc_y)
			 {
				Button^ Button_temp = gcnew Button();
		
				Button_temp->Size = Drawing::Size(size_x, size_y);
				Button_temp->Location = Point(loc_x, loc_y);

				Button_temp->TextAlign = ContentAlignment::MiddleCenter;

				Button_temp->Click += gcnew System::EventHandler(this, &Form1::SingleRandomBtn_Click); //////////////////////

				Button_temp->Text = "亂數";			
				Button_temp->Font = (gcnew System::Drawing::Font(L"新細明體", 9, FontStyle::Bold, GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));

				return Button_temp;
			 }


/*================================================亂數的產生==========================================================*/
	private: void RandomNum_Set(int start , int end )
			 {
				 int px,py;
				 int sign_x,sign_y;
				 for(int i = start ; i < end ; i++ )
				 {	
					 //System::Random^ rand1 = gcnew System::Random( (int)System::DateTime::Now::get().Millisecond);
					 // b[i]->setBallsize(rand1->Next(21 ,101));
					// b[i]->setBallsp  (rand1->Next(2 ,12) );

					 b[i]->setBallsize( (rand()%80)+21 ); 
					 b[i]->setBallsp((rand()%5)+1);

					 sign_x = (rand()%100)+1;			 
					 if( sign_x %2 == 0)  b[i]->setBalldir_x(  ( rand()%5)+1  );//5
					 else				  b[i]->setBalldir_x(0-((rand()%5)+1) );
					  
					 sign_y = (rand()%100)+1;
					 if( sign_y %2 == 0)  b[i]->setBalldir_y(  ( rand()%5)+1  );
					 else				  b[i]->setBalldir_y(0-((rand()%5)+1) );				 

					 px = ( 510 - b[i]->getBallsize() );
					 py = ( 450 - b[i]->getBallsize() );
					 b[i]->setBallposition((rand()%px)+1 ,(rand()%py)+1 );

					 b[i]->setColor( rand()%TheColor::getArrayNum() );
					 for(int j = 0 ; j < i ; j++ )
					 {			 
						 if( b[i]->getColor() == b[j]->getColor()) 
						 {
							b[i]->setColor( rand()%TheColor::getArrayNum() );
						 }
					 }					 
				 }
				 changeData();
			 }
	private: void changeData()
			 {
				for(int  i = 0 ; i < TEXTBOX ; ++i)
				{
					System::Windows::Forms::TextBox^ textbox = (TextBox^)Selection_Panel->Controls->Find(i.ToString() + "T",true)[0]; 
					textbox->Text = getData(i).ToString();				
				}
				System::Windows::Forms::ComboBox^ combobox = (ComboBox^)Selection_Panel->Controls->Find("C",true)[0]; 
				combobox->SelectedIndex = combobox->Items->IndexOf( b[SN]->getColorString() );		
			 }
	private: double getData(int w )
			 {
				switch( w )
				{
					case 0: 
						return b[SN]->getBallsize();
						break;
					case 1: 
						return b[SN]->getBallspeed();
						break;
					case 2: 
						return b[SN]->getBalldirection_x();
						break;
					case 3: 
						return b[SN]->getBalldirection_y();
						break;
					case 4: 
						return b[SN]->getBallposition_x();
						break;
					case 5: 
						return b[SN]->getBallposition_y();
						break;
				}
			 }

/*=====================================================================================================================*/


};
}

