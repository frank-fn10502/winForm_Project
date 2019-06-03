#pragma once
#include "AVLTree.h"
#include "Tree2_3_4.h"
#include "RedBlackTree.h"

#include "TestData.h"

namespace TheBlancedTree 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// DisplayForm 的摘要
	/// </summary>
	public ref class DisplayForm : public System::Windows::Forms::Form
	{
	public:
		DisplayForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~DisplayForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  insert_button;
	protected:
	private: System::Windows::Forms::TextBox^  input_textBox;
	private: System::Windows::Forms::Button^  delete_button;
	private: System::Windows::Forms::Panel^  display_panel;
	private: System::Windows::Forms::Panel^  process_panel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  processes_comboBox;
	private: System::Windows::Forms::TabControl^  display_tabControl;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Panel^  display_panel2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TabControl^  process_tabControl;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::ComboBox^  processes_comboBox2;
	private: System::Windows::Forms::Panel^  process_panel2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::ComboBox^  processes_comboBox3;
	private: System::Windows::Forms::Panel^  process_panel3;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::Panel^  display_panel3;
	private: System::Windows::Forms::Label^  label9;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		Tree2_3_4::Tree2_3_4Entity^ tree2_3_4Entity;
		Tree2_3_4::Tree2_3_4Display^ displayTree2_3_4Entity;

		AVLTree::AVLTreeEntity^ avlTreeEntity;
		AVLTree::AVLTreeDisplay^ displayAVLTreeEntity;

		RedBlackTree::RedBlackTreeEntity^ redBlackTreeEntity;
		RedBlackTree::RedBlackTreeDisplay^ displayRedBlackTreeEntity;


		TestData^ testData;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->process_tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->processes_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->process_panel = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->processes_comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->process_panel2 = (gcnew System::Windows::Forms::Panel());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->processes_comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->process_panel3 = (gcnew System::Windows::Forms::Panel());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->insert_button = (gcnew System::Windows::Forms::Button());
			this->input_textBox = (gcnew System::Windows::Forms::TextBox());
			this->display_panel = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->display_tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->display_panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->display_panel3 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->process_tabControl->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->process_panel->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->display_panel->SuspendLayout();
			this->display_tabControl->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->display_panel2->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->display_panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->process_tabControl);
			this->panel1->Controls->Add(this->delete_button);
			this->panel1->Controls->Add(this->insert_button);
			this->panel1->Controls->Add(this->input_textBox);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(209, 471);
			this->panel1->TabIndex = 0;
			// 
			// process_tabControl
			// 
			this->process_tabControl->Controls->Add(this->tabPage3);
			this->process_tabControl->Controls->Add(this->tabPage4);
			this->process_tabControl->Controls->Add(this->tabPage5);
			this->process_tabControl->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->process_tabControl->Location = System::Drawing::Point(-1, 84);
			this->process_tabControl->Name = L"process_tabControl";
			this->process_tabControl->SelectedIndex = 0;
			this->process_tabControl->Size = System::Drawing::Size(209, 386);
			this->process_tabControl->TabIndex = 1;
			this->process_tabControl->SelectedIndexChanged += gcnew System::EventHandler(this, &DisplayForm::process_tabControl_SelectedIndexChanged);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->tabPage3->Controls->Add(this->processes_comboBox);
			this->tabPage3->Controls->Add(this->process_panel);
			this->tabPage3->Location = System::Drawing::Point(4, 23);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(201, 359);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"AVLTree";
			// 
			// processes_comboBox
			// 
			this->processes_comboBox->BackColor = System::Drawing::Color::White;
			this->processes_comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->processes_comboBox->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->processes_comboBox->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->processes_comboBox->ForeColor = System::Drawing::SystemColors::InfoText;
			this->processes_comboBox->FormattingEnabled = true;
			this->processes_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"加入: 50", L"刪除: 30", L"加入: 20" });
			this->processes_comboBox->Location = System::Drawing::Point(2, 6);
			this->processes_comboBox->Name = L"processes_comboBox";
			this->processes_comboBox->Size = System::Drawing::Size(199, 24);
			this->processes_comboBox->TabIndex = 1;
			// 
			// process_panel
			// 
			this->process_panel->AutoScroll = true;
			this->process_panel->AutoScrollMinSize = System::Drawing::Size(20, 20);
			this->process_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->process_panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->process_panel->Controls->Add(this->label8);
			this->process_panel->Controls->Add(this->label7);
			this->process_panel->Controls->Add(this->label5);
			this->process_panel->Controls->Add(this->label6);
			this->process_panel->Controls->Add(this->label4);
			this->process_panel->Controls->Add(this->label3);
			this->process_panel->Location = System::Drawing::Point(0, 36);
			this->process_panel->Name = L"process_panel";
			this->process_panel->Size = System::Drawing::Size(201, 323);
			this->process_panel->TabIndex = 0;
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(0, 150);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(197, 30);
			this->label8->TabIndex = 6;
			this->label8->Text = L"完成!!!";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(133)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(0, 60);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(197, 30);
			this->label7->TabIndex = 5;
			this->label7->Text = L"平衡完成";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(0, 120);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(197, 30);
			this->label5->TabIndex = 4;
			this->label5->Text = L"不須平衡";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::Silver;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(0, 90);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(197, 30);
			this->label6->TabIndex = 3;
			this->label6->Text = L"節點: 50 平衡因子: 1";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(0, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(197, 30);
			this->label4->TabIndex = 2;
			this->label4->Text = L"狀況: RL";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Silver;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(197, 30);
			this->label3->TabIndex = 1;
			this->label3->Text = L"節點: 50 平衡因子: -2";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->tabPage4->Controls->Add(this->processes_comboBox2);
			this->tabPage4->Controls->Add(this->process_panel2);
			this->tabPage4->Location = System::Drawing::Point(4, 23);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(201, 359);
			this->tabPage4->TabIndex = 1;
			this->tabPage4->Text = L"2-3-4Tree";
			// 
			// processes_comboBox2
			// 
			this->processes_comboBox2->BackColor = System::Drawing::Color::White;
			this->processes_comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->processes_comboBox2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->processes_comboBox2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->processes_comboBox2->ForeColor = System::Drawing::SystemColors::InfoText;
			this->processes_comboBox2->FormattingEnabled = true;
			this->processes_comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"132", L"789", L"456", L"789", L"456",
					L"123", L"546"
			});
			this->processes_comboBox2->Location = System::Drawing::Point(2, 6);
			this->processes_comboBox2->Name = L"processes_comboBox2";
			this->processes_comboBox2->Size = System::Drawing::Size(199, 24);
			this->processes_comboBox2->TabIndex = 3;
			// 
			// process_panel2
			// 
			this->process_panel2->AutoScroll = true;
			this->process_panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->process_panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->process_panel2->Location = System::Drawing::Point(0, 36);
			this->process_panel2->Name = L"process_panel2";
			this->process_panel2->Size = System::Drawing::Size(201, 323);
			this->process_panel2->TabIndex = 2;
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->tabPage5->Controls->Add(this->processes_comboBox3);
			this->tabPage5->Controls->Add(this->process_panel3);
			this->tabPage5->Location = System::Drawing::Point(4, 23);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(201, 359);
			this->tabPage5->TabIndex = 2;
			this->tabPage5->Text = L"紅黑樹";
			// 
			// processes_comboBox3
			// 
			this->processes_comboBox3->BackColor = System::Drawing::Color::White;
			this->processes_comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->processes_comboBox3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->processes_comboBox3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->processes_comboBox3->ForeColor = System::Drawing::SystemColors::InfoText;
			this->processes_comboBox3->FormattingEnabled = true;
			this->processes_comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"132", L"789", L"456", L"789", L"456",
					L"123", L"546"
			});
			this->processes_comboBox3->Location = System::Drawing::Point(2, 6);
			this->processes_comboBox3->Name = L"processes_comboBox3";
			this->processes_comboBox3->Size = System::Drawing::Size(199, 24);
			this->processes_comboBox3->TabIndex = 5;
			// 
			// process_panel3
			// 
			this->process_panel3->AutoScroll = true;
			this->process_panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->process_panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->process_panel3->Location = System::Drawing::Point(0, 36);
			this->process_panel3->Name = L"process_panel3";
			this->process_panel3->Size = System::Drawing::Size(201, 323);
			this->process_panel3->TabIndex = 4;
			// 
			// delete_button
			// 
			this->delete_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->delete_button->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->delete_button->Location = System::Drawing::Point(131, 43);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(73, 27);
			this->delete_button->TabIndex = 2;
			this->delete_button->Text = L"刪除";
			this->delete_button->UseVisualStyleBackColor = true;
			this->delete_button->Click += gcnew System::EventHandler(this, &DisplayForm::delete_button_Click);
			// 
			// insert_button
			// 
			this->insert_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->insert_button->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->insert_button->Location = System::Drawing::Point(52, 43);
			this->insert_button->Name = L"insert_button";
			this->insert_button->Size = System::Drawing::Size(73, 27);
			this->insert_button->TabIndex = 1;
			this->insert_button->Text = L"加入";
			this->insert_button->UseVisualStyleBackColor = true;
			this->insert_button->Click += gcnew System::EventHandler(this, &DisplayForm::insert_button_Click);
			// 
			// input_textBox
			// 
			this->input_textBox->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->input_textBox->Location = System::Drawing::Point(5, 10);
			this->input_textBox->Name = L"input_textBox";
			this->input_textBox->Size = System::Drawing::Size(199, 27);
			this->input_textBox->TabIndex = 1;
			// 
			// display_panel
			// 
			this->display_panel->AutoScroll = true;
			this->display_panel->BackColor = System::Drawing::Color::White;
			this->display_panel->Controls->Add(this->label1);
			this->display_panel->Location = System::Drawing::Point(3, 3);
			this->display_panel->Name = L"display_panel";
			this->display_panel->Size = System::Drawing::Size(1200, 420);
			this->display_panel->TabIndex = 1;
			this->display_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DisplayForm::display_panel_Paint);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(52, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"50";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// display_tabControl
			// 
			this->display_tabControl->Controls->Add(this->tabPage1);
			this->display_tabControl->Controls->Add(this->tabPage2);
			this->display_tabControl->Controls->Add(this->tabPage6);
			this->display_tabControl->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->display_tabControl->Location = System::Drawing::Point(227, 12);
			this->display_tabControl->Margin = System::Windows::Forms::Padding(0);
			this->display_tabControl->Name = L"display_tabControl";
			this->display_tabControl->SelectedIndex = 0;
			this->display_tabControl->Size = System::Drawing::Size(617, 471);
			this->display_tabControl->TabIndex = 1;
			this->display_tabControl->SelectedIndexChanged += gcnew System::EventHandler(this, &DisplayForm::display_tabControl_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->AutoScroll = true;
			this->tabPage1->Controls->Add(this->display_panel);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(609, 442);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"AVLTree";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->AutoScroll = true;
			this->tabPage2->Controls->Add(this->display_panel2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(609, 442);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"2-3-4Tree";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// display_panel2
			// 
			this->display_panel2->AutoScroll = true;
			this->display_panel2->BackColor = System::Drawing::Color::White;
			this->display_panel2->Controls->Add(this->label2);
			this->display_panel2->Location = System::Drawing::Point(3, 3);
			this->display_panel2->Name = L"display_panel2";
			this->display_panel2->Size = System::Drawing::Size(4000, 420);
			this->display_panel2->TabIndex = 2;
			this->display_panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DisplayForm::display_panel2_Paint);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(52, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 30);
			this->label2->TabIndex = 0;
			this->label2->Text = L"30";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabPage6
			// 
			this->tabPage6->AutoScroll = true;
			this->tabPage6->Controls->Add(this->display_panel3);
			this->tabPage6->Location = System::Drawing::Point(4, 25);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(609, 442);
			this->tabPage6->TabIndex = 2;
			this->tabPage6->Text = L"紅黑樹";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// display_panel3
			// 
			this->display_panel3->AutoScroll = true;
			this->display_panel3->BackColor = System::Drawing::Color::White;
			this->display_panel3->Controls->Add(this->label9);
			this->display_panel3->Location = System::Drawing::Point(0, 0);
			this->display_panel3->Name = L"display_panel3";
			this->display_panel3->Size = System::Drawing::Size(2000, 420);
			this->display_panel3->TabIndex = 3;
			this->display_panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DisplayForm::display_panel3_Paint);
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label9->Location = System::Drawing::Point(52, 6);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(30, 30);
			this->label9->TabIndex = 0;
			this->label9->Text = L"60";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DisplayForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gray;
			this->ClientSize = System::Drawing::Size(856, 495);
			this->Controls->Add(this->display_tabControl);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"DisplayForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"平衡樹";
			this->Load += gcnew System::EventHandler(this, &DisplayForm::DisplayForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->process_tabControl->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->process_panel->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->display_panel->ResumeLayout(false);
			this->display_tabControl->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->display_panel2->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			this->display_panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DisplayForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		avlTreeEntity = gcnew AVLTree::AVLTreeEntity();
		displayAVLTreeEntity = gcnew AVLTree::AVLTreeDisplay(avlTreeEntity ,display_panel ,process_panel ,processes_comboBox);
		avlTreeEntity->registerObserver(displayAVLTreeEntity);

		tree2_3_4Entity = gcnew Tree2_3_4::Tree2_3_4Entity();
		displayTree2_3_4Entity = gcnew Tree2_3_4::Tree2_3_4Display(tree2_3_4Entity ,display_panel2 ,process_panel2 ,processes_comboBox2 );
		tree2_3_4Entity->registerObserver(displayTree2_3_4Entity);

		redBlackTreeEntity = gcnew RedBlackTree::RedBlackTreeEntity();
		displayRedBlackTreeEntity = gcnew RedBlackTree::RedBlackTreeDisplay(redBlackTreeEntity ,display_panel3 ,process_panel3 ,processes_comboBox3 );
		redBlackTreeEntity->registerObserver(displayRedBlackTreeEntity);

		testData = gcnew TestData(avlTreeEntity ,tree2_3_4Entity ,redBlackTreeEntity);/////
	}
	private: System::Void insert_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if( isLegalString(input_textBox->Text) )
		{
			if( avlTreeEntity->insert( Convert::ToInt32(input_textBox->Text) ) )
			{
				tree2_3_4Entity->insert( Convert::ToInt32(input_textBox->Text) );
				redBlackTreeEntity->insert( Convert::ToInt32(input_textBox->Text) );
			}
			else MessageBox::Show("不可輸入相同數值");
		}
		//testData->insertData(50);
	}
	private: System::Void delete_button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if( isLegalString(input_textBox->Text) )
		{
			if( !avlTreeEntity->remove( Convert::ToInt32(input_textBox->Text) ) )
			{
				MessageBox::Show("找不到");
			}
			tree2_3_4Entity->remove( Convert::ToInt32(input_textBox->Text) );
			redBlackTreeEntity->remove( Convert::ToInt32(input_textBox->Text) );
		}
		//testData->deleteData(100);
	}

	private: System::Void process_tabControl_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		display_tabControl->SelectedIndex = process_tabControl->SelectedIndex;
		
	}
	private: System::Void display_tabControl_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		process_tabControl->SelectedIndex = display_tabControl->SelectedIndex;
	}
	private: System::Void display_panel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
	{
		displayAVLTreeEntity->paint();
	}
	private: System::Void display_panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
	{
		displayTree2_3_4Entity ->paint();
	}
	private: System::Void display_panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
	{
		displayRedBlackTreeEntity->paint();
	}	
	/*==================函式====================================================================================================*/
	private: bool isLegalString(String^ str)
	{
		if( str == "") 
		{
			MessageBox::Show("不可為空!!!");
			return false;
		}
		else
		{
			for each (Char ch in str)
			{
				if(!Char::IsDigit(ch))
				{
					MessageBox::Show("請輸入正整數!!!");
					return false;
				}
			}
		}
		return true;
	}
	
	};//end of public ref class DisplayForm
}//end of namespace TheBlancedTree
