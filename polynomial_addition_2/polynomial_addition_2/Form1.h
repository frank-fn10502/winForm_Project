#pragma once
#include "Polynomial.h"


namespace polynomial_addition_2 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;//StreamReader ,StreamWriter

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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  path_A;
	private: System::Windows::Forms::Button^  fileA_button;
	private: System::Windows::Forms::Button^  fileB_button;
	private: System::Windows::Forms::TextBox^  path_B;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  poly_A;
	private: System::Windows::Forms::TextBox^  poly_B;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  operation_button;
	private: System::Windows::Forms::TextBox^  poly_C;
	private: System::Windows::Forms::Button^  cl_fAB_buton;

	private: System::Windows::Forms::Button^  cl_fB_buton;
	private: System::Windows::Forms::Button^  cl_fA_buton;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  save_button;
	private: System::Windows::Forms::Label^  label5;
	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;
		Polynomial^ polyA;
	    Polynomial^ polyB;
		Polynomial^ polyC;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->path_A = (gcnew System::Windows::Forms::TextBox());
			this->fileA_button = (gcnew System::Windows::Forms::Button());
			this->fileB_button = (gcnew System::Windows::Forms::Button());
			this->path_B = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->poly_C = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->poly_A = (gcnew System::Windows::Forms::TextBox());
			this->poly_B = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->operation_button = (gcnew System::Windows::Forms::Button());
			this->cl_fA_buton = (gcnew System::Windows::Forms::Button());
			this->cl_fB_buton = (gcnew System::Windows::Forms::Button());
			this->cl_fAB_buton = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->save_button = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(13, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"檔案一 :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// path_A
			// 
			this->path_A->AllowDrop = true;
			this->path_A->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->path_A->Enabled = false;
			this->path_A->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->path_A->Location = System::Drawing::Point(77, 30);
			this->path_A->Name = L"path_A";
			this->path_A->ReadOnly = true;
			this->path_A->Size = System::Drawing::Size(395, 25);
			this->path_A->TabIndex = 1;
			// 
			// fileA_button
			// 
			this->fileA_button->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->fileA_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->fileA_button->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->fileA_button->Location = System::Drawing::Point(478, 30);
			this->fileA_button->Name = L"fileA_button";
			this->fileA_button->Size = System::Drawing::Size(37, 25);
			this->fileA_button->TabIndex = 2;
			this->fileA_button->Text = L"...";
			this->fileA_button->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->fileA_button->UseVisualStyleBackColor = false;
			this->fileA_button->Click += gcnew System::EventHandler(this, &Form1::get_file_button_Click);
			// 
			// fileB_button
			// 
			this->fileB_button->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->fileB_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->fileB_button->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->fileB_button->Location = System::Drawing::Point(478, 80);
			this->fileB_button->Name = L"fileB_button";
			this->fileB_button->Size = System::Drawing::Size(37, 25);
			this->fileB_button->TabIndex = 5;
			this->fileB_button->Text = L"...";
			this->fileB_button->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->fileB_button->UseVisualStyleBackColor = false;
			this->fileB_button->Click += gcnew System::EventHandler(this, &Form1::get_file_button_Click);
			// 
			// path_B
			// 
			this->path_B->AllowDrop = true;
			this->path_B->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->path_B->Enabled = false;
			this->path_B->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->path_B->Location = System::Drawing::Point(77, 80);
			this->path_B->Name = L"path_B";
			this->path_B->ReadOnly = true;
			this->path_B->Size = System::Drawing::Size(395, 25);
			this->path_B->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(13, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"檔案二 :";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel1->Controls->Add(this->fileB_button);
			this->panel1->Controls->Add(this->path_A);
			this->panel1->Controls->Add(this->path_B);
			this->panel1->Controls->Add(this->fileA_button);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(562, 142);
			this->panel1->TabIndex = 6;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel2->Controls->Add(this->poly_C);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->poly_A);
			this->panel2->Controls->Add(this->poly_B);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Location = System::Drawing::Point(12, 171);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(562, 185);
			this->panel2->TabIndex = 7;
			// 
			// poly_C
			// 
			this->poly_C->AllowDrop = true;
			this->poly_C->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->poly_C->Enabled = false;
			this->poly_C->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->poly_C->Location = System::Drawing::Point(59, 130);
			this->poly_C->Name = L"poly_C";
			this->poly_C->ReadOnly = true;
			this->poly_C->Size = System::Drawing::Size(456, 25);
			this->poly_C->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(13, 130);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 25);
			this->label5->TabIndex = 6;
			this->label5->Text = L"C(x) :";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// poly_A
			// 
			this->poly_A->AllowDrop = true;
			this->poly_A->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->poly_A->Enabled = false;
			this->poly_A->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->poly_A->Location = System::Drawing::Point(59, 30);
			this->poly_A->Name = L"poly_A";
			this->poly_A->ReadOnly = true;
			this->poly_A->Size = System::Drawing::Size(456, 25);
			this->poly_A->TabIndex = 1;
			// 
			// poly_B
			// 
			this->poly_B->AllowDrop = true;
			this->poly_B->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->poly_B->Enabled = false;
			this->poly_B->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->poly_B->Location = System::Drawing::Point(59, 80);
			this->poly_B->Name = L"poly_B";
			this->poly_B->ReadOnly = true;
			this->poly_B->Size = System::Drawing::Size(456, 25);
			this->poly_B->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(13, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"B(x) :";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(13, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 25);
			this->label4->TabIndex = 0;
			this->label4->Text = L"A(x) :";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// operation_button
			// 
			this->operation_button->BackColor = System::Drawing::SystemColors::ControlDark;
			this->operation_button->Enabled = false;
			this->operation_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->operation_button->Location = System::Drawing::Point(14, 10);
			this->operation_button->Name = L"operation_button";
			this->operation_button->Size = System::Drawing::Size(86, 35);
			this->operation_button->TabIndex = 5;
			this->operation_button->Text = L"相加";
			this->operation_button->UseVisualStyleBackColor = false;
			this->operation_button->Click += gcnew System::EventHandler(this, &Form1::operation_button_Click);
			// 
			// cl_fA_buton
			// 
			this->cl_fA_buton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cl_fA_buton->Enabled = false;
			this->cl_fA_buton->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->cl_fA_buton->Location = System::Drawing::Point(14, 10);
			this->cl_fA_buton->Name = L"cl_fA_buton";
			this->cl_fA_buton->Size = System::Drawing::Size(86, 35);
			this->cl_fA_buton->TabIndex = 6;
			this->cl_fA_buton->Text = L"clear file1";
			this->cl_fA_buton->UseVisualStyleBackColor = false;
			this->cl_fA_buton->Click += gcnew System::EventHandler(this, &Form1::clear_buton_Click);
			// 
			// cl_fB_buton
			// 
			this->cl_fB_buton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cl_fB_buton->Enabled = false;
			this->cl_fB_buton->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->cl_fB_buton->Location = System::Drawing::Point(14, 50);
			this->cl_fB_buton->Name = L"cl_fB_buton";
			this->cl_fB_buton->Size = System::Drawing::Size(86, 35);
			this->cl_fB_buton->TabIndex = 7;
			this->cl_fB_buton->Text = L"clear file2";
			this->cl_fB_buton->UseVisualStyleBackColor = false;
			this->cl_fB_buton->Click += gcnew System::EventHandler(this, &Form1::clear_buton_Click);
			// 
			// cl_fAB_buton
			// 
			this->cl_fAB_buton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cl_fAB_buton->Enabled = false;
			this->cl_fAB_buton->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->cl_fAB_buton->Location = System::Drawing::Point(14, 90);
			this->cl_fAB_buton->Name = L"cl_fAB_buton";
			this->cl_fAB_buton->Size = System::Drawing::Size(86, 35);
			this->cl_fAB_buton->TabIndex = 8;
			this->cl_fAB_buton->Text = L"clear all";
			this->cl_fAB_buton->UseVisualStyleBackColor = false;
			this->cl_fAB_buton->Click += gcnew System::EventHandler(this, &Form1::clear_buton_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel3->Controls->Add(this->cl_fAB_buton);
			this->panel3->Controls->Add(this->cl_fB_buton);
			this->panel3->Controls->Add(this->cl_fA_buton);
			this->panel3->Location = System::Drawing::Point(590, 12);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(116, 142);
			this->panel3->TabIndex = 8;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel4->Controls->Add(this->save_button);
			this->panel4->Controls->Add(this->operation_button);
			this->panel4->Location = System::Drawing::Point(590, 171);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(116, 185);
			this->panel4->TabIndex = 9;
			// 
			// save_button
			// 
			this->save_button->BackColor = System::Drawing::SystemColors::ControlDark;
			this->save_button->Enabled = false;
			this->save_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->save_button->Location = System::Drawing::Point(14, 50);
			this->save_button->Name = L"save_button";
			this->save_button->Size = System::Drawing::Size(86, 35);
			this->save_button->TabIndex = 6;
			this->save_button->Text = L"儲存答案";
			this->save_button->UseVisualStyleBackColor = false;
			this->save_button->Click += gcnew System::EventHandler(this, &Form1::save_button_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(724, 371);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"多項式相加";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
			 }
	private: System::Void get_file_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {				 
				 Button^ button = (Button^)sender;
				 if( (button->Name)->Contains( "A" ) )		file_input( polyA ,"A" );
				 else if( (button->Name)->Contains( "B" ) ) file_input( polyB ,"B" );
			 }
	private: System::Void clear_buton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Button^ button = (Button^)sender;
				 if( (button->Name)->Contains( "A" ) ) ClearTextBoxGroup( "A" );
				 if( (button->Name)->Contains( "B" ) ) ClearTextBoxGroup( "B" );
			 }
 	private: System::Void operation_button_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				polyC = polyA + polyB;
				enable_textbox( poly_C ,polyC->polynomial_form() );

				enable_button( save_button );
			 }
	private: System::Void save_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 SaveFileDialog ^ saveFileDialog = gcnew SaveFileDialog();
				 saveFileDialog->Filter = "txt files (*.txt)|*.txt";

				 if( saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK )
				 {
					 StreamWriter^ sw = gcnew StreamWriter( saveFileDialog->FileName );
					 for(int i = 0 ; i < polyC->getNum() ; i++ )
					 {
						if(i != 0 ) sw->Write(" ");

						sw->Write( polyC->getCoef(i) + " " + polyC->getExp(i) );
					 }
					 sw->Close();
				 }
			 }
    /*====================================函式=============================================*/

	private: void file_input(Polynomial^% poly ,String^ ch)
			 {
				 OpenFileDialog^ FileDialog1 = gcnew OpenFileDialog();
				 FileDialog1->Filter = "txt files (*.txt)|*.txt";

				 if( FileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK )
				 {
					 StreamReader ^ sr = gcnew StreamReader( FileDialog1->FileName );
					 String^ str = sr->ReadToEnd();
					 sr->Close();

					 if( file_correct( str ) )
					 {
						 poly = gcnew Polynomial( str );//產生物件
						 setTextBox(poly ,FileDialog1->FileName ,ch );

						 disable_textbox( poly_C );
						 disable_button( save_button );
					 }
				 } 
			 }
	private: bool file_correct(String^ str)
			 {
				 if( str->Length == 0 ) 
				 {
					 MessageBox::Show("檔案沒有東西!!!");
					 return false;
				 }
				 else
				 {
					 bool text = false;
					 int count = 0;

					  for(int i = 0 ; i < str->Length ; i++ )
					  {
							if( str[i] == ' ' || str[i] == '\n'|| str[i] == '\r')	text = false; //txt 換行是\r\n
							else if( Char::IsDigit(str[i]) )
							{
								if( !text ) count++;//只有在(第一次碰到)("空白"過後)的"非空白"是 "數字"或"-",才算是一個數字的開始
								text = true;
							}
							else if( str[i] == '-' )
							{
								if( (i != 0 && Char::IsDigit(str[i-1]) ) || !Char::IsDigit(str[i+1]) ) //"-" 前面是數字or後面"不是"數字就格式錯誤( 8-8 or - 8 )
								{
									MessageBox::Show("檔案格式錯誤 !!!\n( 8-8 or - 8 )");
									return false;
								}
							}
							else
							{
								MessageBox::Show("只可以有 '-','數字','空白' !!!");
								return false;
							}
					  }
					  if( count%2 == 1 ) 
					  {
						  MessageBox::Show("第一個數字是'係數'\n第二個數字是'次方' !!!");
						  return false;
					  }
				 }
				 return true;
			 }
    /*====================================介面=============================================*/

    private: void setTextBox(Polynomial^% poly ,String^ path ,String^ ch)
			 {
				TextBox^ tbox1 = (TextBox^)panel1->Controls->Find( "path_"+ ch,true)[0];
				TextBox^ tbox2 = (TextBox^)panel2->Controls->Find( "poly_"+ ch ,true)[0];

				enable_textbox( tbox1 ,path );
				enable_textbox( tbox2 ,poly->polynomial_form() );

				Button^ button = (Button^)panel3->Controls->Find( "cl_f" + ch + "_buton",true)[0];
				enable_button( button );

				if( poly_A->Enabled & poly_B->Enabled ) 
				{
					enable_button( operation_button );//打開 運算按鈕
					enable_button( cl_fAB_buton );
				}
			 }
    private: void ClearTextBoxGroup( String^ ch )
			 {
				TextBox^ tbox1 = (TextBox^)panel1->Controls->Find( "path_"+ ch,true)[0];
				TextBox^ tbox2 = (TextBox^)panel2->Controls->Find( "poly_"+ ch ,true)[0];

				disable_textbox( tbox1  );
				disable_textbox( tbox2  );
				disable_textbox( poly_C );
				
				Button^ button = (Button^)panel3->Controls->Find( "cl_f" + ch + "_buton",true)[0];
				disable_button( button );

				disable_button( cl_fAB_buton	 );
				disable_button( operation_button );
				disable_button( save_button		 );
			 }
	private: void disable_button(Button^ button)
			 {
				if( button->Enabled ) 
				{
					button->Enabled = false;		
					button->BackColor = SystemColors::ControlDark;
				}
			 }
	private: void enable_button(Button^ button )
			 {
				if( !button->Enabled ) 
				{
					button->Enabled = true;
					button->BackColor = SystemColors::ButtonFace;
				}
			 }
	private: void disable_textbox(TextBox^ textbox)
			 {
				 if( textbox->Enabled )
				 {
					textbox->Enabled = false;
					textbox->BackColor = SystemColors::ScrollBar;
					textbox->Text = "";
				 }
			 }
	private: void enable_textbox(TextBox^ textbox ,String^ str)
			 {
				 if( !textbox->Enabled )
				 {
					textbox->Enabled = true;
					textbox->BackColor = SystemColors::ButtonHighlight;					
				 }
				 textbox->Text = str;
			 }


	};
}

