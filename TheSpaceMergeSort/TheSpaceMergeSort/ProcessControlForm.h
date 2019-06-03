#pragma once
#include "NumbersEntity.h"
#include "SMSortBehavior.h"
#include "SpaceMergeSort.h"
#include "ObserverImp.h"

#include "RandomNumbers.h"

public delegate void SetEntityAndSort(array<int>^);
public delegate void AttachOrDetach();

namespace TheSpaceMergeSort 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ProcessControlForm 的摘要
	/// </summary>
	public ref class ProcessControlForm : public System::Windows::Forms::Form
	{
	public:
		ProcessControlForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		ProcessControlForm(SetEntityAndSort^ setEntityAndSort ,AttachOrDetach^ attachOrDetach )
		{
			InitializeComponent();
			this->setEntityAndSort = setEntityAndSort;
			this->attachOrDetach = attachOrDetach;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~ProcessControlForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  createRandomNUM_button;
	protected:

	private: System::Windows::Forms::CheckBox^  noRepeat_checkBox;
	private: System::Windows::Forms::Panel^  create_panel;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TabControl^  create_control_tabControl;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label4;



	private: System::Windows::Forms::Panel^  controlStep_panel;
	private: System::Windows::Forms::Button^  connect_button;


	private: System::Windows::Forms::NumericUpDown^  randomNumEnd_numericUpDown;
	private: System::Windows::Forms::NumericUpDown^  randomNumStart_numericUpDown;
	private: System::Windows::Forms::NumericUpDown^  speed_numericUpDown;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Button^  startSort_button;
	protected:
	private: System::ComponentModel::Container ^components;

	

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>	
		SMSortBehavior^ numbersEntity;
		SpaceMergeSort^ spaceMergeSort;

		SetEntityAndSort^ setEntityAndSort;
	private: System::Windows::Forms::Button^  least_button;
	private: System::Windows::Forms::TextBox^  quantity_textBox;
	private: System::Windows::Forms::Button^  most_button;
	private: System::Windows::Forms::Button^  backState_button;
	private: System::Windows::Forms::Label^  stateDes_label;
	private: System::Windows::Forms::Button^  skipState_button;
			 AttachOrDetach^ attachOrDetach;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ProcessControlForm::typeid));
			this->createRandomNUM_button = (gcnew System::Windows::Forms::Button());
			this->noRepeat_checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->create_panel = (gcnew System::Windows::Forms::Panel());
			this->randomNumStart_numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->randomNumEnd_numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->create_control_tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->controlStep_panel = (gcnew System::Windows::Forms::Panel());
			this->speed_numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->startSort_button = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->connect_button = (gcnew System::Windows::Forms::Button());
			this->least_button = (gcnew System::Windows::Forms::Button());
			this->quantity_textBox = (gcnew System::Windows::Forms::TextBox());
			this->most_button = (gcnew System::Windows::Forms::Button());
			this->backState_button = (gcnew System::Windows::Forms::Button());
			this->stateDes_label = (gcnew System::Windows::Forms::Label());
			this->skipState_button = (gcnew System::Windows::Forms::Button());
			this->create_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->randomNumStart_numericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->randomNumEnd_numericUpDown))->BeginInit();
			this->create_control_tabControl->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->controlStep_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speed_numericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// createRandomNUM_button
			// 
			this->createRandomNUM_button->BackColor = System::Drawing::Color::Gray;
			this->createRandomNUM_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->createRandomNUM_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->createRandomNUM_button->Location = System::Drawing::Point(134, 96);
			this->createRandomNUM_button->Name = L"createRandomNUM_button";
			this->createRandomNUM_button->Size = System::Drawing::Size(86, 31);
			this->createRandomNUM_button->TabIndex = 0;
			this->createRandomNUM_button->Text = L"產生亂數";
			this->createRandomNUM_button->UseVisualStyleBackColor = false;
			this->createRandomNUM_button->Click += gcnew System::EventHandler(this, &ProcessControlForm::createRandomNUM_button_Click);
			// 
			// noRepeat_checkBox
			// 
			this->noRepeat_checkBox->Checked = true;
			this->noRepeat_checkBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->noRepeat_checkBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->noRepeat_checkBox->Location = System::Drawing::Point(35, 96);
			this->noRepeat_checkBox->Name = L"noRepeat_checkBox";
			this->noRepeat_checkBox->Size = System::Drawing::Size(93, 31);
			this->noRepeat_checkBox->TabIndex = 1;
			this->noRepeat_checkBox->Text = L"亂數不重複";
			this->noRepeat_checkBox->UseVisualStyleBackColor = true;
			this->noRepeat_checkBox->CheckedChanged += gcnew System::EventHandler(this, &ProcessControlForm::noRepeat_checkBox_CheckedChanged);
			// 
			// create_panel
			// 
			this->create_panel->BackColor = System::Drawing::Color::Transparent;
			this->create_panel->Controls->Add(this->least_button);
			this->create_panel->Controls->Add(this->quantity_textBox);
			this->create_panel->Controls->Add(this->most_button);
			this->create_panel->Controls->Add(this->randomNumStart_numericUpDown);
			this->create_panel->Controls->Add(this->randomNumEnd_numericUpDown);
			this->create_panel->Controls->Add(this->label3);
			this->create_panel->Controls->Add(this->label1);
			this->create_panel->Controls->Add(this->label2);
			this->create_panel->Controls->Add(this->createRandomNUM_button);
			this->create_panel->Controls->Add(this->noRepeat_checkBox);
			this->create_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->create_panel->Location = System::Drawing::Point(3, 3);
			this->create_panel->Name = L"create_panel";
			this->create_panel->Size = System::Drawing::Size(233, 143);
			this->create_panel->TabIndex = 2;
			// 
			// randomNumStart_numericUpDown
			// 
			this->randomNumStart_numericUpDown->Location = System::Drawing::Point(64, 45);
			this->randomNumStart_numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->randomNumStart_numericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->randomNumStart_numericUpDown->Name = L"randomNumStart_numericUpDown";
			this->randomNumStart_numericUpDown->Size = System::Drawing::Size(55, 25);
			this->randomNumStart_numericUpDown->TabIndex = 25;
			this->randomNumStart_numericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->randomNumStart_numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->randomNumStart_numericUpDown->ValueChanged += gcnew System::EventHandler(this, &ProcessControlForm::randomNumStart_numericUpDown_ValueChanged);
			// 
			// randomNumEnd_numericUpDown
			// 
			this->randomNumEnd_numericUpDown->Location = System::Drawing::Point(139, 45);
			this->randomNumEnd_numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->randomNumEnd_numericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->randomNumEnd_numericUpDown->Name = L"randomNumEnd_numericUpDown";
			this->randomNumEnd_numericUpDown->Size = System::Drawing::Size(55, 25);
			this->randomNumEnd_numericUpDown->TabIndex = 24;
			this->randomNumEnd_numericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->randomNumEnd_numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {64, 0, 0, 0});
			this->randomNumEnd_numericUpDown->ValueChanged += gcnew System::EventHandler(this, &ProcessControlForm::randomNumEnd_numericUpDown_ValueChanged);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(3, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 22);
			this->label3->TabIndex = 22;
			this->label3->Text = L"數量: ";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(3, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"亂數範圍: ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(119, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 22);
			this->label2->TabIndex = 12;
			this->label2->Text = L"~";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// create_control_tabControl
			// 
			this->create_control_tabControl->Controls->Add(this->tabPage1);
			this->create_control_tabControl->Controls->Add(this->tabPage2);
			this->create_control_tabControl->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->create_control_tabControl->HotTrack = true;
			this->create_control_tabControl->Location = System::Drawing::Point(10, 10);
			this->create_control_tabControl->Multiline = true;
			this->create_control_tabControl->Name = L"create_control_tabControl";
			this->create_control_tabControl->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->create_control_tabControl->SelectedIndex = 0;
			this->create_control_tabControl->Size = System::Drawing::Size(249, 181);
			this->create_control_tabControl->TabIndex = 24;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->tabPage1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage1->Controls->Add(this->create_panel);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->tabPage1->Location = System::Drawing::Point(4, 26);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(241, 151);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"產生亂數";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->tabPage2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage2->Controls->Add(this->controlStep_panel);
			this->tabPage2->Location = System::Drawing::Point(4, 26);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(241, 151);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"控制排序";
			// 
			// controlStep_panel
			// 
			this->controlStep_panel->Controls->Add(this->backState_button);
			this->controlStep_panel->Controls->Add(this->stateDes_label);
			this->controlStep_panel->Controls->Add(this->skipState_button);
			this->controlStep_panel->Controls->Add(this->speed_numericUpDown);
			this->controlStep_panel->Controls->Add(this->startSort_button);
			this->controlStep_panel->Controls->Add(this->label4);
			this->controlStep_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->controlStep_panel->Enabled = false;
			this->controlStep_panel->Location = System::Drawing::Point(3, 3);
			this->controlStep_panel->Name = L"controlStep_panel";
			this->controlStep_panel->Size = System::Drawing::Size(233, 143);
			this->controlStep_panel->TabIndex = 36;
			// 
			// speed_numericUpDown
			// 
			this->speed_numericUpDown->Location = System::Drawing::Point(50, 82);
			this->speed_numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->speed_numericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->speed_numericUpDown->Name = L"speed_numericUpDown";
			this->speed_numericUpDown->Size = System::Drawing::Size(55, 25);
			this->speed_numericUpDown->TabIndex = 37;
			this->speed_numericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->speed_numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->speed_numericUpDown->ValueChanged += gcnew System::EventHandler(this, &ProcessControlForm::speed_numericUpDown_ValueChanged);
			// 
			// startSort_button
			// 
			this->startSort_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->startSort_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->startSort_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->startSort_button->Location = System::Drawing::Point(146, 82);
			this->startSort_button->Name = L"startSort_button";
			this->startSort_button->Size = System::Drawing::Size(75, 26);
			this->startSort_button->TabIndex = 36;
			this->startSort_button->Text = L"開始";
			this->startSort_button->UseVisualStyleBackColor = false;
			this->startSort_button->Click += gcnew System::EventHandler(this, &ProcessControlForm::startSort_button_Click);
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(10, 82);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 22);
			this->label4->TabIndex = 26;
			this->label4->Text = L"速度: ";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// connect_button
			// 
			this->connect_button->BackColor = System::Drawing::Color::Gray;
			this->connect_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->connect_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->connect_button->Location = System::Drawing::Point(204, 10);
			this->connect_button->Name = L"connect_button";
			this->connect_button->Size = System::Drawing::Size(55, 20);
			this->connect_button->TabIndex = 25;
			this->connect_button->Text = L"detach";
			this->connect_button->UseVisualStyleBackColor = false;
			this->connect_button->Click += gcnew System::EventHandler(this, &ProcessControlForm::connect_button_Click);
			// 
			// least_button
			// 
			this->least_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"least_button.BackgroundImage")));
			this->least_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->least_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->least_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->least_button->Location = System::Drawing::Point(64, 10);
			this->least_button->Name = L"least_button";
			this->least_button->Size = System::Drawing::Size(20, 22);
			this->least_button->TabIndex = 27;
			this->least_button->TabStop = false;
			this->least_button->UseVisualStyleBackColor = true;
			// 
			// quantity_textBox
			// 
			this->quantity_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->quantity_textBox->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Bold));
			this->quantity_textBox->Location = System::Drawing::Point(84, 10);
			this->quantity_textBox->Name = L"quantity_textBox";
			this->quantity_textBox->Size = System::Drawing::Size(30, 22);
			this->quantity_textBox->TabIndex = 28;
			this->quantity_textBox->Text = L"64";
			this->quantity_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// most_button
			// 
			this->most_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"most_button.BackgroundImage")));
			this->most_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->most_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->most_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->most_button->Location = System::Drawing::Point(114, 10);
			this->most_button->Name = L"most_button";
			this->most_button->Size = System::Drawing::Size(20, 22);
			this->most_button->TabIndex = 26;
			this->most_button->TabStop = false;
			this->most_button->UseVisualStyleBackColor = true;
			// 
			// backState_button
			// 
			this->backState_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->backState_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"backState_button.BackgroundImage")));
			this->backState_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->backState_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->backState_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->backState_button->Location = System::Drawing::Point(13, 22);
			this->backState_button->Name = L"backState_button";
			this->backState_button->Size = System::Drawing::Size(25, 25);
			this->backState_button->TabIndex = 40;
			this->backState_button->TabStop = false;
			this->backState_button->UseVisualStyleBackColor = false;
			this->backState_button->Click += gcnew System::EventHandler(this, &ProcessControlForm::backState_button_Click);
			// 
			// stateDes_label
			// 
			this->stateDes_label->BackColor = System::Drawing::Color::White;
			this->stateDes_label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->stateDes_label->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->stateDes_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->stateDes_label->Location = System::Drawing::Point(38, 22);
			this->stateDes_label->Name = L"stateDes_label";
			this->stateDes_label->Size = System::Drawing::Size(158, 25);
			this->stateDes_label->TabIndex = 38;
			this->stateDes_label->Text = L"找到最大的8個數字";
			this->stateDes_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// skipState_button
			// 
			this->skipState_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->skipState_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"skipState_button.BackgroundImage")));
			this->skipState_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->skipState_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->skipState_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->skipState_button->Location = System::Drawing::Point(196, 22);
			this->skipState_button->Name = L"skipState_button";
			this->skipState_button->Size = System::Drawing::Size(25, 25);
			this->skipState_button->TabIndex = 39;
			this->skipState_button->TabStop = false;
			this->skipState_button->UseVisualStyleBackColor = false;
			this->skipState_button->Click += gcnew System::EventHandler(this, &ProcessControlForm::skipState_button_Click);
			// 
			// ProcessControlForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(269, 202);
			this->Controls->Add(this->connect_button);
			this->Controls->Add(this->create_control_tabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ProcessControlForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"控制";
			this->Load += gcnew System::EventHandler(this, &ProcessControlForm::ProcessControlForm_Load);
			this->create_panel->ResumeLayout(false);
			this->create_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->randomNumStart_numericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->randomNumEnd_numericUpDown))->EndInit();
			this->create_control_tabControl->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->controlStep_panel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speed_numericUpDown))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ProcessControlForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		this->least_button->Visible = false;
		this->most_button->Visible = false;
		this->quantity_textBox->Enabled = false;

		stateDes_label->Text = "";
	}
	private: System::Void createRandomNUM_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int quantity = Convert::ToInt32(quantity_textBox->Text);
		int start	 = Convert::ToInt32(randomNumStart_numericUpDown->Value);
		int end		 = Convert::ToInt32(randomNumEnd_numericUpDown->Value);
		bool noRepeat = noRepeat_checkBox->Checked;

		RandomNumbers^ Random = gcnew RandomNumbers(quantity ,start ,end ,noRepeat);
		setEntityAndSort( Random->getNumbers() );
	}
	private: System::Void backState_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		spaceMergeSort->backTheState();
	}
	private: System::Void skipState_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		spaceMergeSort->skipTheState();
	}
	private: System::Void startSort_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (spaceMergeSort->getSortTimer()->Enabled)
		{
			ButtonOnOff::setButtonStyle(createRandomNUM_button, true);
			create_panel->Enabled = true;
			spaceMergeSort->getSortTimer()->Enabled = false;		
			startSort_button->Text = "開始";
		}
		else
		{
			ButtonOnOff::setButtonStyle(createRandomNUM_button, false);
			create_panel->Enabled = false;
			spaceMergeSort->getSortTimer()->Enabled = true;			
			startSort_button->Text = "暫停";
		}		
	}
	private: System::Void speed_numericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		int speed = Convert::ToInt32(speed_numericUpDown->Value);
		spaceMergeSort->getSortTimer()->Interval = 1000 / speed;
	}
	private: System::Void connect_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (((Button^)sender)->Text == "detach") ((Button^)sender)->Text = "attach";
		else                                     ((Button^)sender)->Text = "detach";

		attachOrDetach();
	}

	private: System::Void noRepeat_checkBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		inputRandomStart();
	}
	private: System::Void randomNumStart_numericUpDown_ValueChanged(Object^  sender ,EventArgs^  e)
	{
		inputRandomStart();
	}
	private: System::Void randomNumEnd_numericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		inputRandomEnd();
	}
/*==============================================函式============================================================================*/
	private: void inputRandomStart()
	{
		int start = Convert::ToInt32(randomNumStart_numericUpDown->Value);
		int end = Convert::ToInt32(randomNumEnd_numericUpDown->Value);
		int quantity = Convert::ToInt32(quantity_textBox->Text);

		randomNumStart_numericUpDown->Value = start;
		if (noRepeat_checkBox->Checked)
		{
			if ((start + quantity) > end && (start + quantity) < randomNumEnd_numericUpDown->Maximum)
			{
				randomNumEnd_numericUpDown->Value = start + quantity - 1;
			}
			else
			{
				randomNumEnd_numericUpDown->Value = 1000;
				randomNumStart_numericUpDown->Value = 1000 - (quantity-1);
			}
		}
		else
		{
			if (start > end)
			{
				randomNumEnd_numericUpDown->Value = start;
			}
		}
	}
	private: void inputRandomEnd()
	{
		int start = Convert::ToInt32(randomNumStart_numericUpDown->Value);
		int end = Convert::ToInt32(randomNumEnd_numericUpDown->Value);
		int quantity = Convert::ToInt32(quantity_textBox->Text);

		randomNumEnd_numericUpDown->Value = end;

		if (noRepeat_checkBox->Checked)
		{
			if ((start + quantity) > end)
			{
				int num = (start + quantity - 1) - end;
				if ((start - num) >= 1)
				{
					randomNumStart_numericUpDown->Value = start - num;
				}
				else
				{
					randomNumStart_numericUpDown->Value = 1;
					randomNumEnd_numericUpDown->Value = quantity;
				}
			}
		}
		else
		{
			if (end < start)
			{
				randomNumStart_numericUpDown->Value = end;
			}
		}
	}
	
	public: void setControlForm(SMSortBehavior^ numbersEntity ,SpaceMergeSort^ spaceMergeSort ,bool detach)
	{
		this->numbersEntity = numbersEntity;
		this->spaceMergeSort = spaceMergeSort;

		//////////
		SortStateImp^ sortStateImp = gcnew SortStateImp(stateDes_label, backState_button, skipState_button);
		numbersEntity->addObserverStateInfo(sortStateImp);

		SortStatusImp^ sortStatusImp = gcnew SortStatusImp(startSort_button ,createRandomNUM_button ,create_panel);
		numbersEntity->addObserverSortStartEnd(sortStatusImp);

		int speed = Convert::ToInt32(speed_numericUpDown->Value);
		spaceMergeSort->getSortTimer()->Interval = 1000 / speed;

		controlStep_panel->Enabled = true;
		//////////
		//手動 notify
		numbersEntity->notifyChangeStateInfo(spaceMergeSort->getStepNum(), State::LASTSTATE);
		numbersEntity->notifyChangeSortStatus(true, true);

		create_control_tabControl->SelectedTab = tabPage2;
		if (detach) connect_button->Text = "attach";
	}

	};
}
