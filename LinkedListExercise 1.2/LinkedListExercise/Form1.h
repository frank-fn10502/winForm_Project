#pragma once

namespace LinkedListExercise 
{
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
			delete list;
		}
	private: System::Windows::Forms::Panel^  display_panel;
	private: System::Windows::Forms::Button^  sort_method_button;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  insert_button;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  insert_content_textBox;
	private: System::Windows::Forms::Button^  delete_button;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  edit_change_textBox;
	private: System::Windows::Forms::RadioButton^  edit_content_radio;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  edit_content_textBox;
	private: System::Windows::Forms::RadioButton^  edit_pos_radio;
	private: System::Windows::Forms::Button^  edit_button;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  result_pos_label;
	private: System::Windows::Forms::Button^  query_button;
	private: System::Windows::Forms::RadioButton^  query_content_radio;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  query_content_textBox;
	private: System::Windows::Forms::RadioButton^  query_pos_radio;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Button^  to_first_button1;
	private: System::Windows::Forms::Button^  to_end_button1;
	private: System::Windows::Forms::TextBox^  insert_pos_textBox;
	private: System::Windows::Forms::Button^  to_first_button2;
	private: System::Windows::Forms::Button^  to_end_button2;
	private: System::Windows::Forms::TextBox^  delete_pos_textBox;
	private: System::Windows::Forms::Button^  to_first_button3;
	private: System::Windows::Forms::Button^  to_end_button3;
	private: System::Windows::Forms::TextBox^  edit_pos_textBox;
	private: System::Windows::Forms::Button^  to_first_button4;
	private: System::Windows::Forms::Button^  to_end_button4;
	private: System::Windows::Forms::TextBox^  query_pos_textBox;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  sort_method_label;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  result_content_label;
	private: System::Windows::Forms::Label^  edit_warning_label;
	private: System::Windows::Forms::Timer^  timer1;


	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  label9;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		Numbers* list;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->display_panel = (gcnew System::Windows::Forms::Panel());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->sort_method_button = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->to_first_button1 = (gcnew System::Windows::Forms::Button());
			this->to_end_button1 = (gcnew System::Windows::Forms::Button());
			this->insert_button = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->insert_content_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->insert_pos_textBox = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->to_first_button2 = (gcnew System::Windows::Forms::Button());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->to_end_button2 = (gcnew System::Windows::Forms::Button());
			this->delete_pos_textBox = (gcnew System::Windows::Forms::TextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->edit_warning_label = (gcnew System::Windows::Forms::Label());
			this->to_first_button3 = (gcnew System::Windows::Forms::Button());
			this->to_end_button3 = (gcnew System::Windows::Forms::Button());
			this->edit_pos_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->edit_change_textBox = (gcnew System::Windows::Forms::TextBox());
			this->edit_content_radio = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->edit_content_textBox = (gcnew System::Windows::Forms::TextBox());
			this->edit_pos_radio = (gcnew System::Windows::Forms::RadioButton());
			this->edit_button = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->result_content_label = (gcnew System::Windows::Forms::Label());
			this->to_first_button4 = (gcnew System::Windows::Forms::Button());
			this->to_end_button4 = (gcnew System::Windows::Forms::Button());
			this->query_pos_textBox = (gcnew System::Windows::Forms::TextBox());
			this->result_pos_label = (gcnew System::Windows::Forms::Label());
			this->query_button = (gcnew System::Windows::Forms::Button());
			this->query_content_radio = (gcnew System::Windows::Forms::RadioButton());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->query_content_textBox = (gcnew System::Windows::Forms::TextBox());
			this->query_pos_radio = (gcnew System::Windows::Forms::RadioButton());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->sort_method_label = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->display_panel->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// display_panel
			// 
			this->display_panel->AutoScroll = true;
			this->display_panel->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->display_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->display_panel->Controls->Add(this->label9);
			this->display_panel->Controls->Add(this->label16);
			this->display_panel->Controls->Add(this->label14);
			this->display_panel->Controls->Add(this->label10);
			this->display_panel->Controls->Add(this->label13);
			this->display_panel->Controls->Add(this->label12);
			this->display_panel->Location = System::Drawing::Point(236, 45);
			this->display_panel->Name = L"display_panel";
			this->display_panel->Size = System::Drawing::Size(585, 355);
			this->display_panel->TabIndex = 0;
			// 
			// label16
			// 
			this->label16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label16->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label16->ForeColor = System::Drawing::Color::Blue;
			this->label16->Location = System::Drawing::Point(30, 20);
			this->label16->Margin = System::Windows::Forms::Padding(0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(10, 25);
			this->label16->TabIndex = 4;
			this->label16->Text = L"1";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label16->Visible = false;
			// 
			// label14
			// 
			this->label14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label14->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label14->Location = System::Drawing::Point(30, 75);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(55, 25);
			this->label14->TabIndex = 3;
			this->label14->Text = L"1256";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label14->Visible = false;
			// 
			// label10
			// 
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label10->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label10->Location = System::Drawing::Point(190, 20);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(55, 25);
			this->label10->TabIndex = 2;
			this->label10->Text = L"\?\?123456789";
			this->label10->Visible = false;
			// 
			// label13
			// 
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label13->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label13->Location = System::Drawing::Point(115, 20);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(55, 25);
			this->label13->TabIndex = 1;
			this->label13->Text = L"\?\?123456789";
			this->label13->Visible = false;
			// 
			// label12
			// 
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label12->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label12->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label12->Location = System::Drawing::Point(40, 20);
			this->label12->Margin = System::Windows::Forms::Padding(0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(55, 25);
			this->label12->TabIndex = 0;
			this->label12->Text = L"1256";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label12->Visible = false;
			// 
			// sort_method_button
			// 
			this->sort_method_button->FlatAppearance->BorderSize = 0;
			this->sort_method_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->sort_method_button->Location = System::Drawing::Point(127, 365);
			this->sort_method_button->Margin = System::Windows::Forms::Padding(0);
			this->sort_method_button->Name = L"sort_method_button";
			this->sort_method_button->Size = System::Drawing::Size(89, 25);
			this->sort_method_button->TabIndex = 2;
			this->sort_method_button->TabStop = false;
			this->sort_method_button->Text = L"backward";
			this->sort_method_button->UseVisualStyleBackColor = true;
			this->sort_method_button->Click += gcnew System::EventHandler(this, &Form1::sort_method_button_Click);
			// 
			// label11
			// 
			this->label11->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label11->Location = System::Drawing::Point(12, 365);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(112, 25);
			this->label11->TabIndex = 18;
			this->label11->Text = L"更改排序方法:";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->tabControl1->HotTrack = true;
			this->tabControl1->ItemSize = System::Drawing::Size(40, 23);
			this->tabControl1->Location = System::Drawing::Point(9, 20);
			this->tabControl1->Margin = System::Windows::Forms::Padding(0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->Padding = System::Drawing::Point(2, 3);
			this->tabControl1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(217, 339);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 5;
			this->tabControl1->TabStop = false;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::tabControl1_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Silver;
			this->tabPage1->Controls->Add(this->to_first_button1);
			this->tabPage1->Controls->Add(this->to_end_button1);
			this->tabPage1->Controls->Add(this->insert_button);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->insert_content_textBox);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->insert_pos_textBox);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->tabPage1->Location = System::Drawing::Point(4, 27);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(209, 308);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"新增";
			// 
			// to_first_button1
			// 
			this->to_first_button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"to_first_button1.BackgroundImage")));
			this->to_first_button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->to_first_button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->to_first_button1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->to_first_button1->Location = System::Drawing::Point(63, 20);
			this->to_first_button1->Name = L"to_first_button1";
			this->to_first_button1->Size = System::Drawing::Size(30, 25);
			this->to_first_button1->TabIndex = 8;
			this->to_first_button1->TabStop = false;
			this->to_first_button1->UseVisualStyleBackColor = true;
			this->to_first_button1->Click += gcnew System::EventHandler(this, &Form1::to_first_button);
			// 
			// to_end_button1
			// 
			this->to_end_button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"to_end_button1.BackgroundImage")));
			this->to_end_button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->to_end_button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->to_end_button1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->to_end_button1->Location = System::Drawing::Point(133, 20);
			this->to_end_button1->Name = L"to_end_button1";
			this->to_end_button1->Size = System::Drawing::Size(30, 25);
			this->to_end_button1->TabIndex = 7;
			this->to_end_button1->TabStop = false;
			this->to_end_button1->UseVisualStyleBackColor = true;
			this->to_end_button1->Click += gcnew System::EventHandler(this, &Form1::to_end_button_Click);
			// 
			// insert_button
			// 
			this->insert_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->insert_button->Location = System::Drawing::Point(138, 98);
			this->insert_button->Name = L"insert_button";
			this->insert_button->Size = System::Drawing::Size(65, 28);
			this->insert_button->TabIndex = 6;
			this->insert_button->Text = L"新增";
			this->insert_button->UseVisualStyleBackColor = true;
			this->insert_button->Click += gcnew System::EventHandler(this, &Form1::insert_button_Click);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(6, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"內容:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// insert_content_textBox
			// 
			this->insert_content_textBox->Location = System::Drawing::Point(63, 55);
			this->insert_content_textBox->Name = L"insert_content_textBox";
			this->insert_content_textBox->Size = System::Drawing::Size(100, 25);
			this->insert_content_textBox->TabIndex = 4;
			this->insert_content_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(6, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"位置:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// insert_pos_textBox
			// 
			this->insert_pos_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->insert_pos_textBox->Location = System::Drawing::Point(93, 20);
			this->insert_pos_textBox->Name = L"insert_pos_textBox";
			this->insert_pos_textBox->Size = System::Drawing::Size(40, 25);
			this->insert_pos_textBox->TabIndex = 2;
			this->insert_pos_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->insert_pos_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->insert_pos_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Silver;
			this->tabPage2->Controls->Add(this->panel1);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->tabPage2->Location = System::Drawing::Point(4, 27);
			this->tabPage2->Margin = System::Windows::Forms::Padding(0);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Size = System::Drawing::Size(209, 308);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"刪除";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->to_first_button2);
			this->panel1->Controls->Add(this->delete_button);
			this->panel1->Controls->Add(this->to_end_button2);
			this->panel1->Controls->Add(this->delete_pos_textBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Enabled = false;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(209, 308);
			this->panel1->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(6, 20);
			this->label4->Margin = System::Windows::Forms::Padding(0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 25);
			this->label4->TabIndex = 8;
			this->label4->Text = L"位置:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// to_first_button2
			// 
			this->to_first_button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"to_first_button2.BackgroundImage")));
			this->to_first_button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->to_first_button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->to_first_button2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->to_first_button2->Location = System::Drawing::Point(63, 20);
			this->to_first_button2->Name = L"to_first_button2";
			this->to_first_button2->Size = System::Drawing::Size(30, 25);
			this->to_first_button2->TabIndex = 14;
			this->to_first_button2->TabStop = false;
			this->to_first_button2->UseVisualStyleBackColor = true;
			this->to_first_button2->Click += gcnew System::EventHandler(this, &Form1::to_first_button);
			// 
			// delete_button
			// 
			this->delete_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->delete_button->Location = System::Drawing::Point(138, 55);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(65, 28);
			this->delete_button->TabIndex = 11;
			this->delete_button->Text = L"刪除";
			this->delete_button->UseVisualStyleBackColor = true;
			this->delete_button->Click += gcnew System::EventHandler(this, &Form1::delete_button_Click);
			// 
			// to_end_button2
			// 
			this->to_end_button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"to_end_button2.BackgroundImage")));
			this->to_end_button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->to_end_button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->to_end_button2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->to_end_button2->Location = System::Drawing::Point(133, 20);
			this->to_end_button2->Name = L"to_end_button2";
			this->to_end_button2->Size = System::Drawing::Size(30, 25);
			this->to_end_button2->TabIndex = 13;
			this->to_end_button2->TabStop = false;
			this->to_end_button2->UseVisualStyleBackColor = true;
			this->to_end_button2->Click += gcnew System::EventHandler(this, &Form1::to_end_button_Click);
			// 
			// delete_pos_textBox
			// 
			this->delete_pos_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->delete_pos_textBox->Location = System::Drawing::Point(93, 20);
			this->delete_pos_textBox->Name = L"delete_pos_textBox";
			this->delete_pos_textBox->Size = System::Drawing::Size(40, 25);
			this->delete_pos_textBox->TabIndex = 12;
			this->delete_pos_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->delete_pos_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->delete_pos_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::Silver;
			this->tabPage3->Controls->Add(this->panel2);
			this->tabPage3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->tabPage3->Location = System::Drawing::Point(4, 27);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(209, 308);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"修改";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->edit_warning_label);
			this->panel2->Controls->Add(this->to_first_button3);
			this->panel2->Controls->Add(this->to_end_button3);
			this->panel2->Controls->Add(this->edit_pos_textBox);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->edit_change_textBox);
			this->panel2->Controls->Add(this->edit_content_radio);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->edit_content_textBox);
			this->panel2->Controls->Add(this->edit_pos_radio);
			this->panel2->Controls->Add(this->edit_button);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Enabled = false;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(209, 308);
			this->panel2->TabIndex = 28;
			// 
			// edit_warning_label
			// 
			this->edit_warning_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->edit_warning_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->edit_warning_label->Location = System::Drawing::Point(21, 222);
			this->edit_warning_label->Name = L"edit_warning_label";
			this->edit_warning_label->Size = System::Drawing::Size(112, 25);
			this->edit_warning_label->TabIndex = 28;
			this->edit_warning_label->Text = L"(查不到相同內容)";
			this->edit_warning_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->edit_warning_label->Visible = false;
			// 
			// to_first_button3
			// 
			this->to_first_button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"to_first_button3.BackgroundImage")));
			this->to_first_button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->to_first_button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->to_first_button3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->to_first_button3->Location = System::Drawing::Point(63, 20);
			this->to_first_button3->Name = L"to_first_button3";
			this->to_first_button3->Size = System::Drawing::Size(30, 25);
			this->to_first_button3->TabIndex = 27;
			this->to_first_button3->TabStop = false;
			this->to_first_button3->UseVisualStyleBackColor = true;
			this->to_first_button3->Click += gcnew System::EventHandler(this, &Form1::to_first_button);
			// 
			// to_end_button3
			// 
			this->to_end_button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"to_end_button3.BackgroundImage")));
			this->to_end_button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->to_end_button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->to_end_button3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->to_end_button3->Location = System::Drawing::Point(133, 20);
			this->to_end_button3->Name = L"to_end_button3";
			this->to_end_button3->Size = System::Drawing::Size(30, 25);
			this->to_end_button3->TabIndex = 26;
			this->to_end_button3->TabStop = false;
			this->to_end_button3->UseVisualStyleBackColor = true;
			this->to_end_button3->Click += gcnew System::EventHandler(this, &Form1::to_end_button_Click);
			// 
			// edit_pos_textBox
			// 
			this->edit_pos_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->edit_pos_textBox->Location = System::Drawing::Point(93, 20);
			this->edit_pos_textBox->Name = L"edit_pos_textBox";
			this->edit_pos_textBox->Size = System::Drawing::Size(40, 25);
			this->edit_pos_textBox->TabIndex = 25;
			this->edit_pos_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->edit_pos_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->edit_pos_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(6, 153);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 25);
			this->label3->TabIndex = 24;
			this->label3->Text = L"修改內容:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// edit_change_textBox
			// 
			this->edit_change_textBox->Location = System::Drawing::Point(6, 181);
			this->edit_change_textBox->Name = L"edit_change_textBox";
			this->edit_change_textBox->Size = System::Drawing::Size(189, 25);
			this->edit_change_textBox->TabIndex = 23;
			this->edit_change_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// edit_content_radio
			// 
			this->edit_content_radio->AutoSize = true;
			this->edit_content_radio->Location = System::Drawing::Point(182, 62);
			this->edit_content_radio->Name = L"edit_content_radio";
			this->edit_content_radio->Size = System::Drawing::Size(14, 13);
			this->edit_content_radio->TabIndex = 22;
			this->edit_content_radio->UseVisualStyleBackColor = true;
			this->edit_content_radio->CheckedChanged += gcnew System::EventHandler(this, &Form1::edit_radio_CheckedChanged);
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(6, 55);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 25);
			this->label5->TabIndex = 21;
			this->label5->Text = L"內容:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// edit_content_textBox
			// 
			this->edit_content_textBox->Location = System::Drawing::Point(63, 55);
			this->edit_content_textBox->Name = L"edit_content_textBox";
			this->edit_content_textBox->Size = System::Drawing::Size(100, 25);
			this->edit_content_textBox->TabIndex = 20;
			this->edit_content_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// edit_pos_radio
			// 
			this->edit_pos_radio->AutoSize = true;
			this->edit_pos_radio->Location = System::Drawing::Point(182, 27);
			this->edit_pos_radio->Name = L"edit_pos_radio";
			this->edit_pos_radio->Size = System::Drawing::Size(14, 13);
			this->edit_pos_radio->TabIndex = 19;
			this->edit_pos_radio->UseVisualStyleBackColor = true;
			this->edit_pos_radio->CheckedChanged += gcnew System::EventHandler(this, &Form1::edit_radio_CheckedChanged);
			// 
			// edit_button
			// 
			this->edit_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->edit_button->Location = System::Drawing::Point(138, 222);
			this->edit_button->Name = L"edit_button";
			this->edit_button->Size = System::Drawing::Size(65, 28);
			this->edit_button->TabIndex = 18;
			this->edit_button->Text = L"修改";
			this->edit_button->UseVisualStyleBackColor = true;
			this->edit_button->Click += gcnew System::EventHandler(this, &Form1::edit_button_Click);
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(6, 20);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 25);
			this->label6->TabIndex = 17;
			this->label6->Text = L"位置:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::Silver;
			this->tabPage4->Controls->Add(this->panel3);
			this->tabPage4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->tabPage4->Location = System::Drawing::Point(4, 27);
			this->tabPage4->Margin = System::Windows::Forms::Padding(0);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(209, 308);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"查詢";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->result_content_label);
			this->panel3->Controls->Add(this->to_first_button4);
			this->panel3->Controls->Add(this->to_end_button4);
			this->panel3->Controls->Add(this->query_pos_textBox);
			this->panel3->Controls->Add(this->result_pos_label);
			this->panel3->Controls->Add(this->query_button);
			this->panel3->Controls->Add(this->query_content_radio);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->query_content_textBox);
			this->panel3->Controls->Add(this->query_pos_radio);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Enabled = false;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(209, 308);
			this->panel3->TabIndex = 34;
			// 
			// result_content_label
			// 
			this->result_content_label->AutoEllipsis = true;
			this->result_content_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->result_content_label->Location = System::Drawing::Point(0, 208);
			this->result_content_label->Name = L"result_content_label";
			this->result_content_label->Size = System::Drawing::Size(203, 69);
			this->result_content_label->TabIndex = 34;
			this->result_content_label->Text = L"內容: ";
			// 
			// to_first_button4
			// 
			this->to_first_button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"to_first_button4.BackgroundImage")));
			this->to_first_button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->to_first_button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->to_first_button4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->to_first_button4->Location = System::Drawing::Point(63, 20);
			this->to_first_button4->Name = L"to_first_button4";
			this->to_first_button4->Size = System::Drawing::Size(30, 25);
			this->to_first_button4->TabIndex = 33;
			this->to_first_button4->TabStop = false;
			this->to_first_button4->UseVisualStyleBackColor = true;
			this->to_first_button4->Click += gcnew System::EventHandler(this, &Form1::to_first_button);
			// 
			// to_end_button4
			// 
			this->to_end_button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"to_end_button4.BackgroundImage")));
			this->to_end_button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->to_end_button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->to_end_button4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->to_end_button4->Location = System::Drawing::Point(133, 20);
			this->to_end_button4->Name = L"to_end_button4";
			this->to_end_button4->Size = System::Drawing::Size(30, 25);
			this->to_end_button4->TabIndex = 32;
			this->to_end_button4->TabStop = false;
			this->to_end_button4->UseVisualStyleBackColor = true;
			this->to_end_button4->Click += gcnew System::EventHandler(this, &Form1::to_end_button_Click);
			// 
			// query_pos_textBox
			// 
			this->query_pos_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->query_pos_textBox->Location = System::Drawing::Point(93, 20);
			this->query_pos_textBox->Name = L"query_pos_textBox";
			this->query_pos_textBox->Size = System::Drawing::Size(40, 25);
			this->query_pos_textBox->TabIndex = 31;
			this->query_pos_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->query_pos_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->query_pos_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// result_pos_label
			// 
			this->result_pos_label->AutoEllipsis = true;
			this->result_pos_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->result_pos_label->Location = System::Drawing::Point(0, 139);
			this->result_pos_label->Name = L"result_pos_label";
			this->result_pos_label->Size = System::Drawing::Size(203, 69);
			this->result_pos_label->TabIndex = 30;
			this->result_pos_label->Text = L"位置: ";
			// 
			// query_button
			// 
			this->query_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->query_button->Location = System::Drawing::Point(138, 98);
			this->query_button->Name = L"query_button";
			this->query_button->Size = System::Drawing::Size(65, 28);
			this->query_button->TabIndex = 29;
			this->query_button->Text = L"查詢";
			this->query_button->UseVisualStyleBackColor = true;
			this->query_button->Click += gcnew System::EventHandler(this, &Form1::query_button_Click);
			// 
			// query_content_radio
			// 
			this->query_content_radio->AutoSize = true;
			this->query_content_radio->Location = System::Drawing::Point(182, 62);
			this->query_content_radio->Name = L"query_content_radio";
			this->query_content_radio->Size = System::Drawing::Size(14, 13);
			this->query_content_radio->TabIndex = 28;
			this->query_content_radio->UseVisualStyleBackColor = true;
			this->query_content_radio->CheckedChanged += gcnew System::EventHandler(this, &Form1::query_radio_CheckedChanged);
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(6, 55);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 25);
			this->label7->TabIndex = 27;
			this->label7->Text = L"內容:";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// query_content_textBox
			// 
			this->query_content_textBox->Location = System::Drawing::Point(63, 55);
			this->query_content_textBox->Name = L"query_content_textBox";
			this->query_content_textBox->Size = System::Drawing::Size(100, 25);
			this->query_content_textBox->TabIndex = 26;
			this->query_content_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// query_pos_radio
			// 
			this->query_pos_radio->AutoSize = true;
			this->query_pos_radio->Location = System::Drawing::Point(182, 27);
			this->query_pos_radio->Name = L"query_pos_radio";
			this->query_pos_radio->Size = System::Drawing::Size(14, 13);
			this->query_pos_radio->TabIndex = 25;
			this->query_pos_radio->UseVisualStyleBackColor = true;
			this->query_pos_radio->CheckedChanged += gcnew System::EventHandler(this, &Form1::query_radio_CheckedChanged);
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(6, 20);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(46, 25);
			this->label8->TabIndex = 24;
			this->label8->Text = L"位置:";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// sort_method_label
			// 
			this->sort_method_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->sort_method_label->Location = System::Drawing::Point(236, 20);
			this->sort_method_label->Name = L"sort_method_label";
			this->sort_method_label->Size = System::Drawing::Size(235, 25);
			this->sort_method_label->TabIndex = 19;
			this->sort_method_label->Text = L"目前排序方法: forward";
			this->sort_method_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label9
			// 
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label9->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label9->ForeColor = System::Drawing::Color::Blue;
			this->label9->Location = System::Drawing::Point(115, 77);
			this->label9->Margin = System::Windows::Forms::Padding(0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 25);
			this->label9->TabIndex = 5;
			this->label9->Text = L"12";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label9->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(834, 411);
			this->Controls->Add(this->sort_method_label);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->sort_method_button);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->display_panel);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"串列";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->display_panel->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 edit_pos_radio->Checked  = true;
				 query_pos_radio->Checked = true;

				 list = new Numbers();
			 }
	private: System::Void edit_radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				to_first_button3->Enabled = edit_pos_radio->Checked;
				to_end_button3->Enabled	  = edit_pos_radio->Checked;
				edit_pos_textBox->Enabled = edit_pos_radio->Checked;
				edit_pos_textBox->Text    = "";

				edit_content_textBox->Enabled = edit_content_radio->Checked;
				edit_content_textBox->Text    = "";
			 }
	private: System::Void query_radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				to_first_button4->Enabled  = query_pos_radio->Checked;
				to_end_button4->Enabled	   = query_pos_radio->Checked;
				query_pos_textBox->Enabled = query_pos_radio->Checked;	
				query_pos_textBox->Text    = "";

				query_content_textBox->Enabled = query_content_radio->Checked;
				query_content_textBox->Text    = "";
			 }
	private: System::Void input_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
			 {
				 if( !Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 127)//數字 ,backspace ,delete
				 {
					e->Handled = true;
				 }
			 }
	private: System::Void input_TextChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 TextBox^ input_pos = (TextBox^)sender;

				 if(input_pos->Text != "")
				 {
					 int posNum = Convert::ToInt32(input_pos->Text);

					 if( list->getCount() > 0 && posNum <= 0 )
					 {
						input_pos->Text = "1";
					 }
					 else if(posNum > list->getCount() )
					 {
						 if( input_pos->Name == "insert_pos_textBox" )
						 {
							if(posNum > (list->getCount()+1)) input_pos->Text = (list->getCount()+1).ToString();
						 }
						 else 
						 {
							 input_pos->Text = list->getCount().ToString();
						 }
					 }
				 }
			 }
	private: System::Void to_first_button(System::Object^  sender, System::EventArgs^  e)
			 {
				  Button^ btn  = (Button^)sender;
				  String^ name = btn->Name;

				  if( name == "to_first_button1" )	    insert_pos_textBox->Text = "1";
				  else if( name == "to_first_button2" ) delete_pos_textBox->Text = "1";
				  else if( name == "to_first_button3" ) edit_pos_textBox->Text   = "1";
				  else if( name == "to_first_button4" ) query_pos_textBox->Text	 = "1";
			 }
	private: System::Void to_end_button_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				  Button^ btn  = (Button^)sender;
				  String^ name = btn->Name;

				  if( name == "to_end_button1" )	  insert_pos_textBox->Text = (list->getCount()+1).ToString();
				  else if( name == "to_end_button2" ) delete_pos_textBox->Text = list->getCount().ToString();
				  else if( name == "to_end_button3" ) edit_pos_textBox->Text  = list->getCount().ToString();
				  else if( name == "to_end_button4" ) query_pos_textBox->Text = list->getCount().ToString();
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				edit_warning_label->Visible = false;
				timer1->Enabled  = false;
			 }
	private: System::Void tabControl1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( tabControl1->SelectedIndex == 3 )
				 {
					result_pos_label->Text     = "位置: ";
					result_content_label->Text = "內容: ";
				 }
			 }
	private: System::Void list_node_MouseHover(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Label^ temp_label = (Label^)sender;
				 
				 if(temp_label->Text->Length > 4 )
				 {
					 temp_label->Size = MeasureTextSize(temp_label);
				 }
			 }
	private: System::Void list_node_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
			 {
				 ((Label^)sender)->Size = Drawing::Size(55, 25);
			 }
	private: System::Void list_number_MouseHover(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Label^ temp_label = (Label^)sender;
				 
				 if(temp_label->Text->Length > 1 )
				 {
					 temp_label->Size = MeasureTextSize(temp_label);
				 }
			 }
	private: System::Void list_number_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
			 {
				 ((Label^)sender)->Size = Drawing::Size(10, 25);
			 }
	private: Drawing::Size MeasureTextSize( Label^% temp_label)
			 {
				Graphics^ g = display_panel->CreateGraphics();

				SizeF textSize = g->MeasureString( temp_label->Text ,temp_label->Font );

				return Drawing::Size( (int)Math::Ceiling(textSize.Width)+10, 25);
			 }
/*================================================按鈕==========================================================*/

	private: System::Void insert_button_Click(System::Object^  sender, System::EventArgs^  e)//未完成(編號)
			 {
				 String^ str1 = insert_pos_textBox->Text;
				 String^ str2 = insert_content_textBox->Text;
				 
				 if(  str1 != "" && str2 != "" )
				 {
					try
					{
						list->insertLink(Convert::ToInt32(str1) ,Convert::ToInt32(str2) );
			
						displayList();
						if(list->getCount() == 1)//將"刪除","修改","查詢"設成可以使用
						{
							panel1->Enabled = true;
							panel2->Enabled = true;
							panel3->Enabled = true;
						}
					}
					catch(Exception^ e)
					{
						if (e->GetType() == StackOverflowException::typeid)
						{
							throw;	
						}
						MessageBox::Show("數值太大\n" + "最多: " + int::MaxValue );
					}
					insert_pos_textBox->Text	 = "";
					insert_content_textBox->Text = "";
				}
			 }
	private: System::Void delete_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( delete_pos_textBox->Text != "" && list->getCount() > 0)
				 {
					list->deleteLink(Convert::ToInt32(delete_pos_textBox->Text) );

					displayList();
					if(list->getCount() == 0)//將"刪除","修改","查詢"設成不可以使用
					{
						panel1->Enabled = false;
						panel2->Enabled = false;
						panel3->Enabled = false;
					}
					delete_pos_textBox->Text = "";
				 }
			 }
	private: System::Void edit_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( edit_pos_textBox->Enabled )
				 {
					 String^ str1 = edit_pos_textBox->Text;
					 String^ str2 = edit_change_textBox->Text;

				    if( str1 != "" && str2 != "" )
					{
						list->editLinkByPos(Convert::ToInt32(str1) 
										   ,Convert::ToInt32(str2) );

						Label^ label = (Label^)display_panel->Controls->Find( "createlabel" + str1,false)[0];
						label->Text  = str2;

						edit_pos_textBox->Text = "";
						edit_change_textBox->Text = "";
					}
				 }
				 else if( edit_content_textBox->Enabled )
				 {
					String^ str1 = edit_content_textBox->Text;
					String^ str2 = edit_change_textBox->Text;

				    if( str1 != "" && str2 != "" )
					{
						if( list->editLinkByContent(Convert::ToInt32(str1) ,Convert::ToInt32(str2) ) )
						{
							displayList();
						}
						else
						{
							edit_warning_label->Visible = true;
							timer1->Interval = 3000;
							timer1->Enabled  = true;
						}
						edit_content_textBox->Text = "";
						edit_change_textBox->Text  = "";
					}
				 }
			 }
	private: System::Void query_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( query_pos_textBox->Enabled )
				 {
					 String^ str1 = query_pos_textBox->Text;

				    if( str1 != "" )
					{
						int content = list->queryLinkByPos(Convert::ToInt32(str1) );

						result_pos_label->Text     = "位置: " + str1;
						result_content_label->Text = "內容: " + content.ToString();

						query_pos_textBox->Text = "";
					}
				 }
				 else if( query_content_textBox->Enabled )
				 {
					String^ str1 = query_content_textBox->Text;

				    if( str1 != "" )
					{
						array<int>^ possitions = list->queryLinkByContent(Convert::ToInt32(str1) );
						
						if( possitions != nullptr )
						{
							String^ str_temp = "";
							for(int i = 0 ; i < possitions->Length ; i++)
							{
								if( i == 0 ) str_temp = possitions[i].ToString();
								else		 str_temp += " ," + possitions[i];
							}
							result_pos_label->Text     = "位置: " + str_temp;
							result_content_label->Text = "內容: " + str1;
						}
						else
						{
							result_pos_label->Text     = "位置: 查不到";
							result_content_label->Text = "內容: " + str1;
						}

						query_content_textBox->Text = "";
					}
				 }
			 }
	private: System::Void sort_method_button_Click(System::Object^  sender, System::EventArgs^  e)
			 {

				 if( list->getForward() )
				 {
					list->setForward(false);
					sort_method_label->Text = "目前排序方法: backward";

					sort_method_button->Text = "forward";
				 }
				 else
				 {
					list->setForward(true);
					sort_method_label->Text = "目前排序方法: forward";

					sort_method_button->Text = "backward";
				 }
				 if( tabControl1->SelectedIndex == 3 )
				 {
					result_pos_label->Text     = "位置: ";
					result_content_label->Text = "內容: ";
				 }	
				 displayList();
			 }
/*================================================介面==========================================================*/

	private: void displayList()
			 {
				 array<int>^ temp_num;
				 if(list->getForward() ) temp_num = list->forwardList();
				 else					 temp_num = list->backwardList();

				 display_panel->Controls->Clear();
				 for(int i = 0 ; i < list->getCount() ; i++)
				 {
					 display_panel->Controls->Add( AddNewNumLabel(i+1 ,i) );
					 display_panel->Controls->Add( AddNewLabel(temp_num[i] ,i ) );
				 }
			 }
	private: Label^ AddNewNumLabel(int text ,int pos )
			 {
				Label^ label_temp  = gcnew Label();
				
				label_temp->BorderStyle = BorderStyle::FixedSingle;
				label_temp->Font =  (gcnew Drawing::Font(L"微軟正黑體", 8.25F, FontStyle::Bold, GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
				label_temp->ForeColor = Color::Blue;
				label_temp->TextAlign = ContentAlignment::MiddleCenter;

				label_temp->Size = Drawing::Size(10, 25);
				label_temp->Location = Point(30 + pos%6 * 85 , 20 + pos/6 *75);

				label_temp->Name = "createNumlabel" + text.ToString();
				label_temp->Text = text.ToString();

				label_temp->MouseLeave += gcnew System::EventHandler(this, &Form1::list_number_MouseLeave);
				label_temp->MouseHover += gcnew System::EventHandler(this, &Form1::list_number_MouseHover);

				return label_temp ;			
			 }
	private: Label^ AddNewLabel(int text ,int pos )
			 {
				Label^ label_temp  = gcnew Label();
				
				label_temp->BorderStyle = BorderStyle::FixedSingle;
				label_temp->Font = (gcnew Drawing::Font(L"微軟正黑體", 12, FontStyle::Bold, GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
				label_temp->TextAlign = ContentAlignment::TopLeft;
				

				label_temp->Size = Drawing::Size(55, 25);
				label_temp->Location = Point(40 + pos%6 * 85 , 20 + pos/6 *75);

				label_temp->Name = "createlabel" + (pos+1).ToString();	
				label_temp->Text = text.ToString();

				label_temp->MouseLeave += gcnew System::EventHandler(this, &Form1::list_node_MouseLeave);
				label_temp->MouseHover += gcnew System::EventHandler(this, &Form1::list_node_MouseHover);

				return label_temp ;			
			 }
	};//end of public ref class Form1
}//end of namespace LinkedListExercise 

