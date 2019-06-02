#pragma once
#include "MutipleResult.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;


namespace binarySearchTree 
{
	/// <summary>
	/// EditDictionary 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class EditDictionary : public System::Windows::Forms::Form
	{
	public:
		EditDictionary(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}
		EditDictionary(Forest* dictionary)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			this->dictionary = dictionary;
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~EditDictionary()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: 
	private: System::Windows::Forms::TabControl^  tabControl1;	
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  single_result_label;
	private: System::Windows::Forms::Panel^  edit_panel;
	private: System::Windows::Forms::TextBox^  single_ch_textBox;
	private: System::Windows::Forms::TextBox^  single_en_textBox;
	private: System::Windows::Forms::Label^  ch_label;
	private: System::Windows::Forms::Button^  single_button;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  border_label;
	private: System::Windows::Forms::Button^  multiple_button;
	private: System::Windows::Forms::TextBox^  multiple_en_textBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  go_back_button;
	private: System::Windows::Forms::Button^  switch_button;
	private: System::Windows::Forms::Button^  select_file_button;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  del_warring_label;

	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		msclr::interop::marshal_context context;
		bool insert;
		Forest* dictionary;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->single_ch_textBox = (gcnew System::Windows::Forms::TextBox());
			this->single_en_textBox = (gcnew System::Windows::Forms::TextBox());
			this->ch_label = (gcnew System::Windows::Forms::Label());
			this->single_button = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->single_result_label = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->select_file_button = (gcnew System::Windows::Forms::Button());
			this->border_label = (gcnew System::Windows::Forms::Label());
			this->multiple_button = (gcnew System::Windows::Forms::Button());
			this->multiple_en_textBox = (gcnew System::Windows::Forms::TextBox());
			this->edit_panel = (gcnew System::Windows::Forms::Panel());
			this->go_back_button = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->switch_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->del_warring_label = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->edit_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->tabControl1->Location = System::Drawing::Point(5, 5);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(260, 232);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->single_ch_textBox);
			this->tabPage1->Controls->Add(this->single_en_textBox);
			this->tabPage1->Controls->Add(this->ch_label);
			this->tabPage1->Controls->Add(this->single_button);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->single_result_label);
			this->tabPage1->Location = System::Drawing::Point(4, 26);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(252, 202);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"加入單個";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// single_ch_textBox
			// 
			this->single_ch_textBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->single_ch_textBox->Location = System::Drawing::Point(50, 49);
			this->single_ch_textBox->Name = L"single_ch_textBox";
			this->single_ch_textBox->Size = System::Drawing::Size(196, 25);
			this->single_ch_textBox->TabIndex = 26;
			// 
			// single_en_textBox
			// 
			this->single_en_textBox->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->single_en_textBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->single_en_textBox->Location = System::Drawing::Point(50, 13);
			this->single_en_textBox->Name = L"single_en_textBox";
			this->single_en_textBox->Size = System::Drawing::Size(196, 25);
			this->single_en_textBox->TabIndex = 24;
			// 
			// ch_label
			// 
			this->ch_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->ch_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->ch_label->Location = System::Drawing::Point(6, 49);
			this->ch_label->Name = L"ch_label";
			this->ch_label->Size = System::Drawing::Size(58, 25);
			this->ch_label->TabIndex = 27;
			this->ch_label->Text = L"中文:";
			this->ch_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// single_button
			// 
			this->single_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->single_button->Location = System::Drawing::Point(166, 91);
			this->single_button->Name = L"single_button";
			this->single_button->Size = System::Drawing::Size(80, 29);
			this->single_button->TabIndex = 23;
			this->single_button->Text = L"加入";
			this->single_button->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label6->Location = System::Drawing::Point(6, 13);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 25);
			this->label6->TabIndex = 25;
			this->label6->Text = L"英文:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// single_result_label
			// 
			this->single_result_label->BackColor = System::Drawing::Color::White;
			this->single_result_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->single_result_label->Location = System::Drawing::Point(3, 140);
			this->single_result_label->Name = L"single_result_label";
			this->single_result_label->Size = System::Drawing::Size(246, 59);
			this->single_result_label->TabIndex = 22;
			this->single_result_label->Text = L"unknow";
			this->single_result_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->single_result_label->Visible = false;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->select_file_button);
			this->tabPage2->Controls->Add(this->border_label);
			this->tabPage2->Controls->Add(this->multiple_button);
			this->tabPage2->Controls->Add(this->multiple_en_textBox);
			this->tabPage2->Controls->Add(this->del_warring_label);
			this->tabPage2->Location = System::Drawing::Point(4, 26);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(252, 202);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"加入多個";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// select_file_button
			// 
			this->select_file_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->select_file_button->Location = System::Drawing::Point(78, 163);
			this->select_file_button->Name = L"select_file_button";
			this->select_file_button->Size = System::Drawing::Size(87, 29);
			this->select_file_button->TabIndex = 30;
			this->select_file_button->Text = L"選擇檔案";
			this->select_file_button->UseVisualStyleBackColor = true;
			this->select_file_button->Click += gcnew System::EventHandler(this, &EditDictionary::select_file_button_Click);
			// 
			// border_label
			// 
			this->border_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->border_label->Location = System::Drawing::Point(-6, 137);
			this->border_label->Name = L"border_label";
			this->border_label->Size = System::Drawing::Size(271, 23);
			this->border_label->TabIndex = 28;
			this->border_label->Text = L"=========================================";
			this->border_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// multiple_button
			// 
			this->multiple_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->multiple_button->Location = System::Drawing::Point(166, 105);
			this->multiple_button->Name = L"multiple_button";
			this->multiple_button->Size = System::Drawing::Size(80, 29);
			this->multiple_button->TabIndex = 27;
			this->multiple_button->Text = L"加入";
			this->multiple_button->UseVisualStyleBackColor = true;
			// 
			// multiple_en_textBox
			// 
			this->multiple_en_textBox->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->multiple_en_textBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->multiple_en_textBox->Location = System::Drawing::Point(6, 6);
			this->multiple_en_textBox->Multiline = true;
			this->multiple_en_textBox->Name = L"multiple_en_textBox";
			this->multiple_en_textBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->multiple_en_textBox->Size = System::Drawing::Size(240, 93);
			this->multiple_en_textBox->TabIndex = 26;
			// 
			// edit_panel
			// 
			this->edit_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->edit_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->edit_panel->Controls->Add(this->tabControl1);
			this->edit_panel->Location = System::Drawing::Point(6, 48);
			this->edit_panel->Name = L"edit_panel";
			this->edit_panel->Size = System::Drawing::Size(275, 252);
			this->edit_panel->TabIndex = 25;
			// 
			// go_back_button
			// 
			this->go_back_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->go_back_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->go_back_button->Location = System::Drawing::Point(104, 306);
			this->go_back_button->Name = L"go_back_button";
			this->go_back_button->Size = System::Drawing::Size(74, 29);
			this->go_back_button->TabIndex = 28;
			this->go_back_button->Text = L"返回";
			this->go_back_button->UseVisualStyleBackColor = true;
			this->go_back_button->Click += gcnew System::EventHandler(this, &EditDictionary::go_back_button_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &EditDictionary::timer1_Tick);
			// 
			// switch_button
			// 
			this->switch_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->switch_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->switch_button->Location = System::Drawing::Point(208, 9);
			this->switch_button->Name = L"switch_button";
			this->switch_button->Size = System::Drawing::Size(74, 25);
			this->switch_button->TabIndex = 29;
			this->switch_button->Text = L"刪除";
			this->switch_button->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->switch_button->UseVisualStyleBackColor = true;
			this->switch_button->Click += gcnew System::EventHandler(this, &EditDictionary::switch_button_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label1->Location = System::Drawing::Point(125, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 25);
			this->label1->TabIndex = 30;
			this->label1->Text = L"更改模式:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// del_warring_label
			// 
			this->del_warring_label->BackColor = System::Drawing::Color::White;
			this->del_warring_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->del_warring_label->ForeColor = System::Drawing::Color::Red;
			this->del_warring_label->Location = System::Drawing::Point(6, 137);
			this->del_warring_label->Name = L"del_warring_label";
			this->del_warring_label->Size = System::Drawing::Size(240, 55);
			this->del_warring_label->TabIndex = 31;
			this->del_warring_label->Text = L"請輸入英文!!!";
			this->del_warring_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->del_warring_label->Visible = false;
			// 
			// EditDictionary
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(293, 347);
			this->Controls->Add(this->switch_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->go_back_button);
			this->Controls->Add(this->edit_panel);
			this->Name = L"EditDictionary";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"加入";
			this->Load += gcnew System::EventHandler(this, &EditDictionary::EditDictionary_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->edit_panel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool isEnglish(String^ str)
			 {
				 for(int i = 0 ; i < str->Length ; i++ )
				 {
					 if( str[i] < 0 || str[i] > 127 ) return false;
				 }
				 return true;
			 }
	private: bool insertDictionary(String^ str)//只檢查格式大致上對
			 {
				 array<String^>^ data = str->Split('\n');
				 array<String^,2>^ word = gcnew array<String^,2>(data->Length ,2);
				 array<String^>^ temp;		 

				 for(int i = 0 ; i < data->Length ; i ++ )
				 {
					 temp = splitData( data[i]->Trim() );
					 for(int j = 0 ; j < temp->Length ; j++ )
					 {
						 if( temp[j] == nullptr ) return false;
						 else					  word[ i,j ] = temp[j];
					 }
				 }
				 MutipleResult^ result_display = gcnew MutipleResult(dictionary ,word );
				 result_display->ShowDialog(this);

				 return true;
			 }
	private: bool deleteDictionary(String^ str)//只檢查格式大致上對
			 {
				 array<String^>^ data = str->Split('\n');
				 for(int i = 0 ; i < data->Length ; i ++ )
				 {
					 data[i] = data[i]->Trim();
					 if( data[i] == "" ) return false;
					 else
					 {
						 for(int j = 0 ; j < data[i]->Length ; j++ )
						 {
							 if(data[i][j] == ' ' ) return false;
						 }
						 if( !isEnglish(data[i]) )		return false;
					 }
				 }
				 MutipleResult^ result_display = gcnew MutipleResult(dictionary ,data );
				 result_display->ShowDialog(this);

				 return true;
			 }
	private: array<String^>^ splitData(String^ data)
			 {
				 array<String^>^ word = gcnew array<String^>(2);
				 String^ temp = "";

				 for(int i = 0 ,j = 0; i <= data->Length ; i++ )
				 {
					if(i < data->Length && data[i] != ' ') temp += data[i];
					else
					{
						if( temp != "" ) 
						{
							word[j++] = temp;
							temp = "";
						}
					}
				 }
				 return word;
			 }
	private: std::string getStdString(String^ str)
			 {
				return context.marshal_as<std::string>(str);
			 }
	/*=================================介面=====================================================*/

	private: void changeMode()
			 {
				 if( insert )
				 {
					this->Text = "加入";
					tabPage1->Text = "加入單個";
					tabPage2->Text = "加入多個";

					single_button->Text   = "加入";
					multiple_button->Text = "加入";

					del_warring_label->Visible = false;

					ch_label->Visible		    = true;
					single_ch_textBox->Visible  = true;
					border_label->Visible	    = true;
					select_file_button->Visible = true;

					single_button->Click   -= gcnew System::EventHandler(this, &EditDictionary::single_delete_button_Click);
					multiple_button->Click -= gcnew System::EventHandler(this, &EditDictionary::multiple_delete_button_Click);
					single_button->Click   += gcnew System::EventHandler(this, &EditDictionary::single_insert_button_Click);
					multiple_button->Click += gcnew System::EventHandler(this, &EditDictionary::multiple_insert_button_Click);

					edit_panel->Enabled = true;
					switch_button->Text = "刪除";
					if( dictionary->getNodeNumber() <= 0 )
						switch_button->Enabled = false;
				 }
				 else
				 {
					this->Text = "刪除";
					tabPage1->Text = "刪除單個";
					tabPage2->Text = "刪除多個";

					single_button->Text   = "刪除";
					multiple_button->Text = "刪除";

					del_warring_label->Visible = true;

					ch_label->Visible = false;
					single_ch_textBox->Visible = false;
					border_label->Visible = false;
					select_file_button->Visible = false;

					single_button->Click   -= gcnew System::EventHandler(this, &EditDictionary::single_insert_button_Click);
					multiple_button->Click -= gcnew System::EventHandler(this, &EditDictionary::multiple_insert_button_Click);
					single_button->Click   += gcnew System::EventHandler(this, &EditDictionary::single_delete_button_Click);
					multiple_button->Click += gcnew System::EventHandler(this, &EditDictionary::multiple_delete_button_Click);

					edit_panel->Enabled = true;
					switch_button->Text = "加入";
				 }
			 }
	/*==========================================================================================*/
	private: System::Void EditDictionary_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 insert = true;
				 timer1->Interval = 1500;
				 changeMode();
			 }
	private: System::Void switch_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 insert = ( insert == true ) ? false : true;
				 changeMode();
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 single_result_label->Visible = false;
				 timer1->Enabled = false;
			 }
	private: System::Void single_insert_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 single_en_textBox->Text = single_en_textBox->Text->Trim();
				 single_ch_textBox->Text = single_ch_textBox->Text->Trim();
				 if( single_en_textBox->Text != "" && single_ch_textBox->Text != "" )
				 {
					 if( isEnglish(single_en_textBox->Text) )
					 {
						 msclr::interop::marshal_context context;
						 std::string en = context.marshal_as<std::string>(single_en_textBox->Text);
						 std::string ch = context.marshal_as<std::string>(single_ch_textBox->Text);

						 if( dictionary->insertNode(en ,ch) )
						 {
							  single_result_label->ForeColor = Color::Blue;
							  single_result_label->Text	   = single_en_textBox->Text + " --> " + single_ch_textBox->Text + "\n加入成功";
							  single_result_label->Visible = true;

							  if( dictionary->getNodeNumber() > 0 )
							  {
								  switch_button->Enabled = true;
							  }

							  single_en_textBox->Text = "";
							  single_ch_textBox->Text = "";
						 }
						 else 
						 {
							 single_result_label->ForeColor = Color::Red;
							 single_result_label->Text	  = "已經有這個單字了";
							 single_result_label->Visible = true;
						 }
						 timer1->Enabled = true;
					 }
					 else MessageBox::Show("請加入\"英文\" !!!");
				 }
				 else
				 {
					 if( single_en_textBox->Text == "" && single_ch_textBox->Text == "" )
					 {
						 MessageBox::Show("請輸入\"英文\"和\"中文翻譯\" !!!");
					 }
					 else if( single_en_textBox->Text == "" && single_ch_textBox->Text != "" )
					 {
						 MessageBox::Show("請輸入\"英文\" !!!");
					 }
					 else if( single_en_textBox->Text != "" && single_ch_textBox->Text == "" )
					 {
						 MessageBox::Show("請輸入\"中文翻譯\" !!!");
					 }
				 }				
			 }
	private: System::Void multiple_insert_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				multiple_en_textBox->Text = multiple_en_textBox->Text->Trim();
				String^ str = multiple_en_textBox->Text;
				if( str != "" )
				{
					if( ! insertDictionary(str) )
					{
						MessageBox::Show("格式錯誤 !!!");
					}
					else 
					{
					    if( dictionary->getNodeNumber() > 0 )
					    {
						    switch_button->Enabled = true;
					    }
						multiple_en_textBox->Text = "";
					}
				}
				else MessageBox::Show("請輸入資料 !!!" );
			 }
	private: System::Void single_delete_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 single_en_textBox->Text = single_en_textBox->Text->Trim();
				 if( single_en_textBox->Text != "" )
				 {
					 if( isEnglish(single_en_textBox->Text) )
					 {
						 msclr::interop::marshal_context context;
						 std::string en = context.marshal_as<std::string>(single_en_textBox->Text);

						 String^ str = dictionary->query(en ,0);
						 if( dictionary->deleteNode(en ) )
						 {
							  single_result_label->ForeColor = Color::Blue;
							  single_result_label->Text	=  str + "\n刪除成功";
							  single_result_label->Visible = true;
							
							  if( dictionary->getNodeNumber() <= 0 )
							  {
								  edit_panel->Enabled = false;
							  }
							  single_en_textBox->Text = "";
						 }
						 else 
						 {
							 single_result_label->ForeColor = Color::Red;
							 single_result_label->Text = "查不到這個單字";
							 single_result_label->Visible = true;
						 }
						 timer1->Enabled = true;
					 }
					 else MessageBox::Show("請輸入\"英文\" !!!");
				 }
				 else if( single_en_textBox->Text == "" )
				 {
					 MessageBox::Show("請輸入要刪除的英文單字!!!");
				 }				
			 }
	private: System::Void multiple_delete_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				multiple_en_textBox->Text = multiple_en_textBox->Text->Trim();
				String^ str = multiple_en_textBox->Text;
				if( str != "" )
				{	
					if( !deleteDictionary(str) )
					{
						MessageBox::Show("格式錯誤 !!!");
					}
					else 
					{
					    if( dictionary->getNodeNumber() <= 0 )
					    {
						    edit_panel->Enabled = false;
					    }
						multiple_en_textBox->Text = "";
					}
				}
				else MessageBox::Show("請輸入資料 !!!" );
			 }
	private: System::Void select_file_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
				 openFileDialog->Filter = "txt files (*.txt)|*.txt";

				 if( openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK )
				 {	
					 MutipleResult^ result_display = gcnew MutipleResult(dictionary ,openFileDialog->FileName );
					 result_display->ShowDialog(this);

					 if( dictionary->getNodeNumber() > 0 )
					 {
						 switch_button->Enabled = true;
					 }
				 }
			 }
	private: System::Void go_back_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 //this->Visible = false;
				 this->Close();
				 //this->Hide();
			 }
	};
}
