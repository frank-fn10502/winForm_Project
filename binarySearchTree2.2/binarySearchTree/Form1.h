#pragma once
#include "EditDictionary.h"


namespace binarySearchTree 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

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
	protected:
	private: System::Windows::Forms::Label^  search_num_label;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  query_panel;
	private: System::Windows::Forms::Button^  query_button;
	private: System::Windows::Forms::TextBox^  query_en_textBox;
	private: System::Windows::Forms::Label^  word_num_label;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::RichTextBox^  all_word_richTextBox;
	private: System::Windows::Forms::RichTextBox^  query_result_richTextBox;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  switch_button;
	private: System::Windows::Forms::Button^  edit_button;


	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		msclr::interop::marshal_context context;
		Forest* dictionary;
		EditDictionary^ edit;
		int preWordNum;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->word_num_label = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->search_num_label = (gcnew System::Windows::Forms::Label());
			this->query_panel = (gcnew System::Windows::Forms::Panel());
			this->query_result_richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->query_button = (gcnew System::Windows::Forms::Button());
			this->query_en_textBox = (gcnew System::Windows::Forms::TextBox());
			this->all_word_richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->edit_button = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->switch_button = (gcnew System::Windows::Forms::Button());
			this->query_panel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// word_num_label
			// 
			this->word_num_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->word_num_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->word_num_label->Location = System::Drawing::Point(91, 12);
			this->word_num_label->Name = L"word_num_label";
			this->word_num_label->Size = System::Drawing::Size(108, 23);
			this->word_num_label->TabIndex = 19;
			this->word_num_label->Text = L"unknow";
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label5->Location = System::Drawing::Point(7, 12);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(78, 23);
			this->label5->TabIndex = 18;
			this->label5->Text = L"單字數量:";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(7, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"搜索次數:";
			// 
			// search_num_label
			// 
			this->search_num_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->search_num_label->Location = System::Drawing::Point(76, 38);
			this->search_num_label->Name = L"search_num_label";
			this->search_num_label->Size = System::Drawing::Size(76, 21);
			this->search_num_label->TabIndex = 1;
			this->search_num_label->Text = L"unknow";
			// 
			// query_panel
			// 
			this->query_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->query_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->query_panel->Controls->Add(this->query_result_richTextBox);
			this->query_panel->Controls->Add(this->query_button);
			this->query_panel->Controls->Add(this->query_en_textBox);
			this->query_panel->Controls->Add(this->search_num_label);
			this->query_panel->Controls->Add(this->label1);
			this->query_panel->Location = System::Drawing::Point(10, 45);
			this->query_panel->Name = L"query_panel";
			this->query_panel->Size = System::Drawing::Size(455, 244);
			this->query_panel->TabIndex = 1;
			// 
			// query_result_richTextBox
			// 
			this->query_result_richTextBox->BackColor = System::Drawing::Color::White;
			this->query_result_richTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->query_result_richTextBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->query_result_richTextBox->Location = System::Drawing::Point(10, 73);
			this->query_result_richTextBox->Name = L"query_result_richTextBox";
			this->query_result_richTextBox->ReadOnly = true;
			this->query_result_richTextBox->Size = System::Drawing::Size(433, 150);
			this->query_result_richTextBox->TabIndex = 22;
			this->query_result_richTextBox->Text = L"";
			// 
			// query_button
			// 
			this->query_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->query_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->query_button->Location = System::Drawing::Point(397, 10);
			this->query_button->Name = L"query_button";
			this->query_button->Size = System::Drawing::Size(46, 25);
			this->query_button->TabIndex = 1;
			this->query_button->Text = L"查詢";
			this->query_button->UseVisualStyleBackColor = true;
			this->query_button->Click += gcnew System::EventHandler(this, &Form1::query_button_Click);
			// 
			// query_en_textBox
			// 
			this->query_en_textBox->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->query_en_textBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->query_en_textBox->Location = System::Drawing::Point(10, 10);
			this->query_en_textBox->Name = L"query_en_textBox";
			this->query_en_textBox->Size = System::Drawing::Size(381, 25);
			this->query_en_textBox->TabIndex = 0;
			// 
			// all_word_richTextBox
			// 
			this->all_word_richTextBox->BackColor = System::Drawing::Color::White;
			this->all_word_richTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->all_word_richTextBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->all_word_richTextBox->Location = System::Drawing::Point(8, 41);
			this->all_word_richTextBox->Name = L"all_word_richTextBox";
			this->all_word_richTextBox->ReadOnly = true;
			this->all_word_richTextBox->Size = System::Drawing::Size(435, 132);
			this->all_word_richTextBox->TabIndex = 21;
			this->all_word_richTextBox->Text = L"1. abcdeabcdeabcdeabcde --> abcdeabcdeabcdeabcdeabcdeabcde";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->all_word_richTextBox);
			this->panel1->Controls->Add(this->edit_button);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->word_num_label);
			this->panel1->Location = System::Drawing::Point(10, 295);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(455, 185);
			this->panel1->TabIndex = 23;
			// 
			// edit_button
			// 
			this->edit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->edit_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->edit_button->Location = System::Drawing::Point(369, 6);
			this->edit_button->Name = L"edit_button";
			this->edit_button->Size = System::Drawing::Size(74, 29);
			this->edit_button->TabIndex = 21;
			this->edit_button->Text = L"編輯";
			this->edit_button->UseVisualStyleBackColor = true;
			this->edit_button->Click += gcnew System::EventHandler(this, &Form1::edit_button_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// switch_button
			// 
			this->switch_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->switch_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->switch_button->Location = System::Drawing::Point(12, 4);
			this->switch_button->Name = L"switch_button";
			this->switch_button->Size = System::Drawing::Size(97, 33);
			this->switch_button->TabIndex = 24;
			this->switch_button->Text = L"英 --> 中";
			this->switch_button->UseVisualStyleBackColor = true;
			this->switch_button->Click += gcnew System::EventHandler(this, &Form1::switch_button_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(477, 482);
			this->Controls->Add(this->switch_button);
			this->Controls->Add(this->query_panel);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"二元搜尋樹";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->query_panel->ResumeLayout(false);
			this->query_panel->PerformLayout();
			this->panel1->ResumeLayout(false);
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
	/*=================================介面============================================*/

	private: void beforeEditDictionary()
			 {
				 search_num_label->Text = "unknow";
				 query_result_richTextBox->Text = "";

				 word_num_label->Text		= dictionary->getNodeNumber().ToString();
				 all_word_richTextBox->Text = dictionary->inorder();

				 if( dictionary->getNodeNumber() > 0) query_panel->Enabled = true;
				 else								  query_panel->Enabled = false;
			 }
	/*===============================================================================*/

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 dictionary = new Forest();

				 timer1->Interval = 100;
				 beforeEditDictionary();
				 preWordNum = dictionary->getNodeNumber();
			 }
	private: System::Void switch_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 dictionary->setSearchMode((dictionary->getMode()+1)%2);
				 if( dictionary->getMode() == 0 ) switch_button->Text = "英 --> 中";
				 else							  switch_button->Text = "中 --> 英";

				 all_word_richTextBox->Text = dictionary->inorder();

				 search_num_label->Text = "unknow";
				 query_result_richTextBox->Text = "";
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
			 {
				 if( !edit->Visible ) 
				 {
					 edit_button->Enabled = true;
					 timer1->Enabled = false;
				 }
				 else if( preWordNum != dictionary->getNodeNumber() )
				 {
					preWordNum = dictionary->getNodeNumber();
					beforeEditDictionary();
				 }
			 }
	private: System::Void edit_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 edit = gcnew EditDictionary(dictionary);
				 edit->Show(this);

				 edit_button->Enabled = false;
				 timer1->Enabled = true;
			 }
	private: System::Void query_button_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 query_en_textBox->Text = query_en_textBox->Text->Trim();
				 if( query_en_textBox->Text != "" )
				 {
					if( dictionary->getMode() == 1 || isEnglish(query_en_textBox->Text) )
					{
						std::string en = context.marshal_as<std::string>(query_en_textBox->Text);

						query_result_richTextBox->Text = dictionary->query(en ,dictionary->getMode());
						search_num_label->Text = dictionary->getSearchNum().ToString();

						query_en_textBox->Text = "";
					}
					else MessageBox::Show("請輸入\"" +(dictionary->getMode()==0 ? "英文" : "中文") + "\" !!!");
				 }
				 else if( query_en_textBox->Text == "" )
				 {
					 MessageBox::Show("請輸入要查詢的\"" +(dictionary->getMode()==0 ? "英文" : "中文") + "\" !!!");
				 }
			 }
	};//end of ref class Form1 
}//end of namespace binarySearchTree

