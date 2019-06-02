#pragma once
#include "TimeSystem.h"
#include "Timmer.h"
#include "Countdown.h"
#include <string>


namespace TheClock 
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
			}
		private: System::Windows::Forms::Button^ toClock;
		private: System::Windows::Forms::Panel^  ClockTS;
		private: System::Windows::Forms::Label^  NewYork;

		private: System::Windows::Forms::Label^  London;

		private: System::Windows::Forms::Label^  Taipei;

		private: System::Windows::Forms::Button^  clockTOmenu;
		private: System::Windows::Forms::Timer^  timer1;
		private: System::ComponentModel::IContainer^  components;

		protected: 

		protected: 

		protected: 

		private:
			/// <summary>
			/// 設計工具所需的變數。
			/// </summary>
		TimeSystem c1,c2,c3;	
		//static	TimeSystem^ c = gcnew TimeSystem(3);
		Countdown c_d;
		Timmer t,moment;

		private: System::Windows::Forms::Panel^  timing;
		private: System::Windows::Forms::Label^  timClock;
		private: System::Windows::Forms::Button^ toTiming;
		private: System::Windows::Forms::Button^ timTOmenu;
		private: System::Windows::Forms::Button^ stop_timing;
	    private: System::Windows::Forms::Button^  split_time;


		private: System::Windows::Forms::Button^  start_timing;
		private: System::Windows::Forms::Timer^  timer2;
		private: System::Windows::Forms::FlowLayoutPanel^  record;
		private: System::Windows::Forms::Button^  toCountDown;
		private: System::Windows::Forms::Panel^  CountDown;
		private: System::Windows::Forms::Label^  CDclock;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::TextBox^  Hour_text;

		private: System::Windows::Forms::Button^  CountdTOMenu;

		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::TextBox^  Second_text;

		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::TextBox^  Minute_text;
		private: System::Windows::Forms::Button^  Start_tick;
		private: System::Windows::Forms::Timer^  timer3;
		private: System::Windows::Forms::Label^  tip;
		private: System::Windows::Forms::Button^  reset;
		private: System::Windows::Forms::Button^  rest_timing;
		private: System::Windows::Forms::Label^  prompt;
		private: System::Windows::Forms::CheckBox^ checkBox1;

		

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
			///
			/// </summary>
			void InitializeComponent(void)
			{
				this->components = (gcnew System::ComponentModel::Container());
				this->toClock = (gcnew System::Windows::Forms::Button());
				this->ClockTS = (gcnew System::Windows::Forms::Panel());
				this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				this->clockTOmenu = (gcnew System::Windows::Forms::Button());
				this->NewYork = (gcnew System::Windows::Forms::Label());
				this->London = (gcnew System::Windows::Forms::Label());
				this->Taipei = (gcnew System::Windows::Forms::Label());
				this->timing = (gcnew System::Windows::Forms::Panel());
				this->prompt = (gcnew System::Windows::Forms::Label());
				this->rest_timing = (gcnew System::Windows::Forms::Button());
				this->record = (gcnew System::Windows::Forms::FlowLayoutPanel());
				this->stop_timing = (gcnew System::Windows::Forms::Button());
				this->split_time = (gcnew System::Windows::Forms::Button());
				this->start_timing = (gcnew System::Windows::Forms::Button());
				this->timTOmenu = (gcnew System::Windows::Forms::Button());
				this->timClock = (gcnew System::Windows::Forms::Label());
				this->CountDown = (gcnew System::Windows::Forms::Panel());
				this->reset = (gcnew System::Windows::Forms::Button());
				this->tip = (gcnew System::Windows::Forms::Label());
				this->Start_tick = (gcnew System::Windows::Forms::Button());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->Second_text = (gcnew System::Windows::Forms::TextBox());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->Minute_text = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->Hour_text = (gcnew System::Windows::Forms::TextBox());
				this->CountdTOMenu = (gcnew System::Windows::Forms::Button());
				this->CDclock = (gcnew System::Windows::Forms::Label());
				this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				this->toTiming = (gcnew System::Windows::Forms::Button());
				this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
				this->toCountDown = (gcnew System::Windows::Forms::Button());
				this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
				this->ClockTS->SuspendLayout();
				this->timing->SuspendLayout();
				this->CountDown->SuspendLayout();
				this->SuspendLayout();
				// 
				// toClock
				// 
				this->toClock->BackColor = System::Drawing::SystemColors::ButtonHighlight;
				this->toClock->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->toClock->Location = System::Drawing::Point(53, 27);
				this->toClock->Name = L"toClock";
				this->toClock->Size = System::Drawing::Size(171, 41);
				this->toClock->TabIndex = 0;
				this->toClock->Text = L"時鐘";
				this->toClock->UseVisualStyleBackColor = false;
				this->toClock->Click += gcnew System::EventHandler(this, &Form1::toClock_Click);
				// 
				// ClockTS
				// 
				this->ClockTS->Controls->Add(this->checkBox1);
				this->ClockTS->Controls->Add(this->clockTOmenu);
				this->ClockTS->Controls->Add(this->NewYork);
				this->ClockTS->Controls->Add(this->London);
				this->ClockTS->Controls->Add(this->Taipei);
				this->ClockTS->Dock = System::Windows::Forms::DockStyle::Fill;
				this->ClockTS->ImeMode = System::Windows::Forms::ImeMode::NoControl;
				this->ClockTS->Location = System::Drawing::Point(0, 0);
				this->ClockTS->Name = L"ClockTS";
				this->ClockTS->Size = System::Drawing::Size(284, 262);
				this->ClockTS->TabIndex = 1;
				this->ClockTS->Visible = false;
				// 
				// checkBox1
				// 
				this->checkBox1->AutoSize = true;
				this->checkBox1->Location = System::Drawing::Point(204, 168);
				this->checkBox1->Name = L"checkBox1";
				this->checkBox1->Size = System::Drawing::Size(72, 16);
				this->checkBox1->TabIndex = 4;
				this->checkBox1->Text = L"12小時制";
				this->checkBox1->UseVisualStyleBackColor = true;
				this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
				// 
				// clockTOmenu
				// 
				this->clockTOmenu->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->clockTOmenu->Location = System::Drawing::Point(6, 222);
				this->clockTOmenu->Name = L"clockTOmenu";
				this->clockTOmenu->Size = System::Drawing::Size(75, 27);
				this->clockTOmenu->TabIndex = 3;
				this->clockTOmenu->Text = L"返回";
				this->clockTOmenu->UseVisualStyleBackColor = false;
				this->clockTOmenu->Click += gcnew System::EventHandler(this, &Form1::clockTOmenu_Click);
				// 
				// NewYork
				// 
				this->NewYork->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->NewYork->Font = (gcnew System::Drawing::Font(L"新細明體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->NewYork->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->NewYork->Location = System::Drawing::Point(0, 109);
				this->NewYork->Name = L"NewYork";
				this->NewYork->Size = System::Drawing::Size(284, 43);
				this->NewYork->TabIndex = 2;
				this->NewYork->Text = L"紐約 00:00:00 ";
				this->NewYork->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				// 
				// London
				// 
				this->London->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->London->Font = (gcnew System::Drawing::Font(L"新細明體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->London->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->London->Location = System::Drawing::Point(0, 66);
				this->London->Name = L"London";
				this->London->Size = System::Drawing::Size(284, 43);
				this->London->TabIndex = 1;
				this->London->Text = L"倫敦 00:00:00 ";
				this->London->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				// 
				// Taipei
				// 
				this->Taipei->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
					| System::Windows::Forms::AnchorStyles::Right));
				this->Taipei->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->Taipei->Font = (gcnew System::Drawing::Font(L"新細明體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->Taipei->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->Taipei->Location = System::Drawing::Point(0, 23);
				this->Taipei->Name = L"Taipei";
				this->Taipei->Size = System::Drawing::Size(284, 43);
				this->Taipei->TabIndex = 0;
				this->Taipei->Text = L"台北 00:00:00 ";
				this->Taipei->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				// 
				// timing
				// 
				this->timing->Controls->Add(this->prompt);
				this->timing->Controls->Add(this->rest_timing);
				this->timing->Controls->Add(this->record);
				this->timing->Controls->Add(this->stop_timing);
				this->timing->Controls->Add(this->split_time);
				this->timing->Controls->Add(this->start_timing);
				this->timing->Controls->Add(this->timTOmenu);
				this->timing->Controls->Add(this->timClock);
				this->timing->Dock = System::Windows::Forms::DockStyle::Fill;
				this->timing->ImeMode = System::Windows::Forms::ImeMode::NoControl;
				this->timing->Location = System::Drawing::Point(0, 0);
				this->timing->Name = L"timing";
				this->timing->Size = System::Drawing::Size(284, 262);
				this->timing->TabIndex = 2;
				this->timing->Visible = false;
				// 
				// prompt
				// 
				this->prompt->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->prompt->Location = System::Drawing::Point(173, 217);
				this->prompt->Name = L"prompt";
				this->prompt->Size = System::Drawing::Size(99, 23);
				this->prompt->TabIndex = 11;
				this->prompt->Text = L"(最多紀錄20項)";
				// 
				// rest_timing
				// 
				this->rest_timing->BackColor = System::Drawing::SystemColors::ControlLight;
				this->rest_timing->ForeColor = System::Drawing::SystemColors::ControlDark;
				this->rest_timing->Location = System::Drawing::Point(201, 97);
				this->rest_timing->Name = L"rest_timing";
				this->rest_timing->Size = System::Drawing::Size(68, 29);
				this->rest_timing->TabIndex = 10;
				this->rest_timing->Text = L"重設";
				this->rest_timing->UseVisualStyleBackColor = false;
				this->rest_timing->Click += gcnew System::EventHandler(this, &Form1::rest_timing_Click);
				// 
				// record
				// 
				this->record->AutoScroll = true;
				this->record->BackColor = System::Drawing::SystemColors::ButtonHighlight;
				this->record->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
				this->record->Location = System::Drawing::Point(12, 132);
				this->record->Name = L"record";
				this->record->Size = System::Drawing::Size(260, 84);
				this->record->TabIndex = 9;
				this->record->WrapContents = false;
				// 
				// stop_timing
				// 
				this->stop_timing->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->stop_timing->Location = System::Drawing::Point(12, 97);
				this->stop_timing->Name = L"stop_timing";
				this->stop_timing->Size = System::Drawing::Size(68, 29);
				this->stop_timing->TabIndex = 8;
				this->stop_timing->Text = L"停止";
				this->stop_timing->UseVisualStyleBackColor = false;
				this->stop_timing->Click += gcnew System::EventHandler(this, &Form1::stop_timing_Click);
				// 
				// split_time
				// 
				this->split_time->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->split_time->Location = System::Drawing::Point(201, 97);
				this->split_time->Name = L"split_time";
				this->split_time->Size = System::Drawing::Size(68, 29);
				this->split_time->TabIndex = 7;
				this->split_time->Text = L"時間分割";
				this->split_time->UseVisualStyleBackColor = false;
				this->split_time->Click += gcnew System::EventHandler(this, &Form1::split_time_Click);
				// 
				// start_timing
				// 
				this->start_timing->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->start_timing->Location = System::Drawing::Point(12, 97);
				this->start_timing->Name = L"start_timing";
				this->start_timing->Size = System::Drawing::Size(68, 29);
				this->start_timing->TabIndex = 6;
				this->start_timing->Text = L"開始";
				this->start_timing->UseVisualStyleBackColor = false;
				this->start_timing->Click += gcnew System::EventHandler(this, &Form1::start_timing_Click);
				// 
				// timTOmenu
				// 
				this->timTOmenu->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->timTOmenu->Location = System::Drawing::Point(12, 222);
				this->timTOmenu->Name = L"timTOmenu";
				this->timTOmenu->Size = System::Drawing::Size(75, 27);
				this->timTOmenu->TabIndex = 4;
				this->timTOmenu->Text = L"返回";
				this->timTOmenu->UseVisualStyleBackColor = false;
				this->timTOmenu->Click += gcnew System::EventHandler(this, &Form1::timTOmenu_Click);
				// 
				// timClock
				// 
				this->timClock->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->timClock->Font = (gcnew System::Drawing::Font(L"新細明體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->timClock->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->timClock->Location = System::Drawing::Point(12, 27);
				this->timClock->Name = L"timClock";
				this->timClock->Size = System::Drawing::Size(260, 60);
				this->timClock->TabIndex = 0;
				this->timClock->Text = L"00:00:00.00";
				this->timClock->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// CountDown
				// 
				this->CountDown->Controls->Add(this->reset);
				this->CountDown->Controls->Add(this->tip);
				this->CountDown->Controls->Add(this->Start_tick);
				this->CountDown->Controls->Add(this->label3);
				this->CountDown->Controls->Add(this->Second_text);
				this->CountDown->Controls->Add(this->label2);
				this->CountDown->Controls->Add(this->Minute_text);
				this->CountDown->Controls->Add(this->label1);
				this->CountDown->Controls->Add(this->Hour_text);
				this->CountDown->Controls->Add(this->CountdTOMenu);
				this->CountDown->Controls->Add(this->CDclock);
				this->CountDown->Dock = System::Windows::Forms::DockStyle::Fill;
				this->CountDown->Location = System::Drawing::Point(0, 0);
				this->CountDown->Name = L"CountDown";
				this->CountDown->Size = System::Drawing::Size(284, 262);
				this->CountDown->TabIndex = 5;
				this->CountDown->Visible = false;
				// 
				// reset
				// 
				this->reset->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->reset->Location = System::Drawing::Point(111, 220);
				this->reset->Name = L"reset";
				this->reset->Size = System::Drawing::Size(64, 29);
				this->reset->TabIndex = 10;
				this->reset->Text = L"重設";
				this->reset->UseVisualStyleBackColor = false;
				this->reset->Click += gcnew System::EventHandler(this, &Form1::reset_Click);
				// 
				// tip
				// 
				this->tip->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->tip->Location = System::Drawing::Point(18, 141);
				this->tip->Name = L"tip";
				this->tip->Size = System::Drawing::Size(247, 71);
				this->tip->TabIndex = 9;
				this->tip->Text = L"請輸入時,分,秒";
				this->tip->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				this->tip->Visible = false;
				// 
				// Start_tick
				// 
				this->Start_tick->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->Start_tick->Location = System::Drawing::Point(208, 222);
				this->Start_tick->Name = L"Start_tick";
				this->Start_tick->Size = System::Drawing::Size(64, 29);
				this->Start_tick->TabIndex = 8;
				this->Start_tick->Text = L"計時開始";
				this->Start_tick->UseVisualStyleBackColor = false;
				this->Start_tick->Click += gcnew System::EventHandler(this, &Form1::Start_tick_Click);
				// 
				// label3
				// 
				this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->label3->Location = System::Drawing::Point(192, 97);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(27, 27);
				this->label3->TabIndex = 7;
				this->label3->Text = L"秒:";
				this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// Second_text
				// 
				this->Second_text->Location = System::Drawing::Point(216, 101);
				this->Second_text->Name = L"Second_text";
				this->Second_text->Size = System::Drawing::Size(49, 22);
				this->Second_text->TabIndex = 6;
				this->Second_text->Text = L"00";
				// 
				// label2
				// 
				this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->label2->Location = System::Drawing::Point(103, 98);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(27, 27);
				this->label2->TabIndex = 5;
				this->label2->Text = L"分:";
				this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// Minute_text
				// 
				this->Minute_text->Location = System::Drawing::Point(127, 102);
				this->Minute_text->Name = L"Minute_text";
				this->Minute_text->Size = System::Drawing::Size(49, 22);
				this->Minute_text->TabIndex = 4;
				this->Minute_text->Text = L"00";
				// 
				// label1
				// 
				this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->label1->Location = System::Drawing::Point(20, 98);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(27, 27);
				this->label1->TabIndex = 3;
				this->label1->Text = L"時:";
				this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// Hour_text
				// 
				this->Hour_text->Location = System::Drawing::Point(44, 102);
				this->Hour_text->Name = L"Hour_text";
				this->Hour_text->Size = System::Drawing::Size(49, 22);
				this->Hour_text->TabIndex = 2;
				this->Hour_text->Text = L"00";
				// 
				// CountdTOMenu
				// 
				this->CountdTOMenu->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->CountdTOMenu->Location = System::Drawing::Point(15, 221);
				this->CountdTOMenu->Name = L"CountdTOMenu";
				this->CountdTOMenu->Size = System::Drawing::Size(64, 29);
				this->CountdTOMenu->TabIndex = 1;
				this->CountdTOMenu->Text = L"返回";
				this->CountdTOMenu->UseVisualStyleBackColor = false;
				this->CountdTOMenu->Click += gcnew System::EventHandler(this, &Form1::CountdTOMenu_Click);
				// 
				// CDclock
				// 
				this->CDclock->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->CDclock->Font = (gcnew System::Drawing::Font(L"新細明體", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->CDclock->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->CDclock->Location = System::Drawing::Point(22, 26);
				this->CDclock->Name = L"CDclock";
				this->CDclock->Size = System::Drawing::Size(247, 58);
				this->CDclock->TabIndex = 0;
				this->CDclock->Text = L"00:00:00";
				this->CDclock->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// timer1
				// 
				this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
				// 
				// toTiming
				// 
				this->toTiming->BackColor = System::Drawing::SystemColors::ButtonHighlight;
				this->toTiming->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->toTiming->Location = System::Drawing::Point(53, 171);
				this->toTiming->Name = L"toTiming";
				this->toTiming->Size = System::Drawing::Size(171, 41);
				this->toTiming->TabIndex = 3;
				this->toTiming->Text = L"計時器";
				this->toTiming->UseVisualStyleBackColor = false;
				this->toTiming->Click += gcnew System::EventHandler(this, &Form1::toTiming_Click);
				// 
				// timer2
				// 
				this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
				// 
				// toCountDown
				// 
				this->toCountDown->BackColor = System::Drawing::SystemColors::ButtonHighlight;
				this->toCountDown->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(136)));
				this->toCountDown->Location = System::Drawing::Point(53, 97);
				this->toCountDown->Name = L"toCountDown";
				this->toCountDown->Size = System::Drawing::Size(171, 41);
				this->toCountDown->TabIndex = 4;
				this->toCountDown->Text = L"倒數計時器";
				this->toCountDown->UseVisualStyleBackColor = false;
				this->toCountDown->Click += gcnew System::EventHandler(this, &Form1::toCountDown_Click);
				// 
				// timer3
				// 
				this->timer3->Tick += gcnew System::EventHandler(this, &Form1::timer3_Tick);
				// 
				// Form1
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::SystemColors::AppWorkspace;
				this->ClientSize = System::Drawing::Size(284, 262);
				this->Controls->Add(this->timing);
				this->Controls->Add(this->CountDown);
				this->Controls->Add(this->ClockTS);
				this->Controls->Add(this->toClock);
				this->Controls->Add(this->toTiming);
				this->Controls->Add(this->toCountDown);
				this->Name = L"Form1";
				this->Text = L"這是個時鐘";
				this->ClockTS->ResumeLayout(false);
				this->ClockTS->PerformLayout();
				this->timing->ResumeLayout(false);
				this->CountDown->ResumeLayout(false);
				this->CountDown->PerformLayout();
				this->ResumeLayout(false);

			}
	#pragma endregion

		/*===================================時鐘ClockTS======================================================*/

		private: System::Void toClock_Click(System::Object^  sender, System::EventArgs^  e) 
				 {
					c1.setOntime(8); //台北 8
					c2.setOntime(0); //倫敦 0 
					c3.setOntime(-5);//紐約 -5 

					ChangeTime();

					timer1->Enabled  = true;
					timer1->Interval = 1000;

					ClockTS->Visible = true; 
				 }	
		private: System::Void clockTOmenu_Click(System::Object^  sender, System::EventArgs^  e)  
				 {
					  timer1->Enabled  = false; 
					  ClockTS->Visible = false;
				 }
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
				 {
					  c1.one_second();
					  c2.one_second();
					  c3.one_second();

					  ChangeTime();
				 }
		private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
				 {
					 
			 			  if (checkBox1->CheckState == CheckState::Checked) 
						  {
							c1.setTimeSystem(12);
							c2.setTimeSystem(12);
							c3.setTimeSystem(12);;
						  }
						  else if (checkBox1->CheckState == CheckState::Unchecked)
						  {
							c1.setTimeSystem(24);
							c2.setTimeSystem(24); 
							c3.setTimeSystem(24);
						  }
					
						  ChangeTime();
				 }

		public : void ChangeTime()
				{
					  String^ Time1 = gcnew String(c1.getTimes(1).c_str());
					  String^ Time2 = gcnew String(c2.getTimes(2).c_str());
					  String^ Time3 = gcnew String(c3.getTimes(3).c_str());

					  Taipei->Text = Time1;
					  London->Text = Time2;
					  NewYork->Text= Time3;
				}

		
		/*===================================倒數計時CountDown======================================================*/
		private: System::Void toCountDown_Click(System::Object^  sender, System::EventArgs^  e) 
				 {
					 CountDown->Visible = true;					
					 reset->Visible = false;

					 tip->Text = "請輸入時,分,秒";
					 tip->Visible = true;
				 }
		private: System::Void CountdTOMenu_Click(System::Object^  sender, System::EventArgs^  e) //回到選單
				 {

					 CountDown->Visible = false;
					 timer3->Enabled = false;

					 c_d.setData(0,0,0);
					 String^ str = gcnew String(c_d.getTimes().c_str());
					 CDclock->Text = str;

					 Hour_text->Text = "00";
					 Minute_text->Text = "00";
					 Second_text->Text = "00";
				 }
		private: System::Void Start_tick_Click(System::Object^  sender, System::EventArgs^  e) //倒數開始
				 {
					 int h ,m ,s ;					 

					h = System::Convert::ToInt16( Hour_text->Text );
					m = System::Convert::ToInt16( Minute_text->Text );
					s = System::Convert::ToInt16( Second_text->Text );

					if( h == 0 && m == 0 && s == 0) tip->Text = " 沒有輸入資料 \n 請輸入時,分,秒";
					else
					{	
						 c_d.setData(h,m,s);

						 tip->Visible = false;	
						 reset->Visible = true;

						 String^ str = gcnew String(c_d.getTimes().c_str());
						 CDclock->Text = str;

						 timer3->Enabled = true;
						 timer3->Interval= 1000;
					}
				 }
		private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) 
				 {
					 if( c_d.countDown() ) 
					 {
						 reset->Visible = false;

						 timer3->Enabled= false;

						 tip->Text = "請重新輸入時,分,秒";
						 tip->Visible = true;

						 CDclock->Text = "時間到";
						 Hour_text->Text = "00";
						 Minute_text->Text = "00";
						 Second_text->Text = "00";
					 }
					 else				   
					 {
						 String^ s = gcnew String(c_d.getTimes().c_str());
						 CDclock->Text = s;
					 }

				 }
		private: System::Void reset_Click(System::Object^  sender, System::EventArgs^  e) 
				 {
						 reset->Visible = false;

						 timer3->Enabled= false;

						 tip->Text = "請輸入時,分,秒";
						 tip->Visible = true;

						 CDclock->Text = "00:00:00";
						 Hour_text->Text   = "00";
						 Minute_text->Text = "00";
						 Second_text->Text = "00";			 
				 }
		
		/*===================================計時器timing======================================================*/
	    static int l = 0, i = 0 , N = 20;

		public : void ResetBtn_turnON(bool turnON)
				{
					if( turnON )
					{
					  rest_timing->BackColor = System::Drawing::SystemColors::ActiveCaption;
					  rest_timing->ForeColor = System::Drawing::SystemColors::Desktop;
					}
					else
					{

					  rest_timing->BackColor = System::Drawing::SystemColors::ControlLight;
					  rest_timing->ForeColor = System::Drawing::SystemColors::ControlDark;
					}
				}
		private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e)  //開始計時
				 {					  
					  t.oneCsecond();
					  String^ s = gcnew String(t.getTimes().c_str());
					  timClock->Text = s;
				 }		
		private: System::Void toTiming_Click(System::Object^  sender, System::EventArgs^  e) 
				 {
					  timing->Visible = true; 

					  stop_timing->Visible = false;
					  split_time->Visible = false;

					  start_timing->Visible = true;
					  rest_timing->Visible  = true;

					  ResetBtn_turnON(false);

					  l = 0;
					  i = 0;
		  
					  timer2->Interval = 10;
				 }
		private: System::Void timTOmenu_Click(System::Object^  sender, System::EventArgs^  e) //返回選單
				 {
					  timing->Visible = false;

					  timer2->Enabled = false;
			  
					  t.setData(0,0,0,0,0);

					  String^ s = gcnew String(t.getTimes().c_str());
					  timClock->Text = s;

					  record->Controls->Clear();
				 }
		private: System::Void start_timing_Click(System::Object^  sender, System::EventArgs^  e) 
				 {
					  ResetBtn_turnON(true);

					  stop_timing->Visible = true;
					  split_time->Visible = true;

					  start_timing->Visible = false;
					  rest_timing->Visible  = false;

					  timer2->Enabled  = true;

				 }
		private: System::Void stop_timing_Click(System::Object^  sender, System::EventArgs^  e) //停止
				 {
					  stop_timing->Visible = false;
					  split_time->Visible =  false;

					  start_timing->Visible = true;
					  rest_timing->Visible  = true;

					  timer2->Enabled = false;
				 }
		private: System::Void rest_timing_Click(System::Object^  sender, System::EventArgs^  e) 
				 {
					 if( t.getCsecond() != 0 || t.getDsecond() != 0 || t.getSecond() != 0 || t.getMinute() != 0 || t.getHour() != 0)
					 {	
						  l = 0;
						  i = 0;
						  record->Controls->Clear();

						  t.setData(0,0,0,0,0);

						  String^ s = gcnew String(t.getTimes().c_str());
						  timClock->Text = s;
						  
						  ResetBtn_turnON(false);
					 }
				 }

	    private: System::Void split_time_Click(System::Object^  sender, System::EventArgs^  e) 
				 {
						AddNewLabel();
				 }	
		public : void AddNewLabel() //	public: System::Windows::Forms::Label^ AddNewLabel() // return label_record;
				{
					if( l < N )
					{
					  System::Windows::Forms::Label^ label_record = gcnew Label(); 
					  label_record->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
											 static_cast<System::Byte>(136)));
					  label_record->Size = System::Drawing::Size(235, 20);
					  label_record->Name = l.ToString();

					  label_record->Text = (l+1).ToString() + ". " +recording();

					  record->Controls->Add(label_record);
					  l+=1;
					  
					}
					else 
					{
						if( i == N ) i = 0;
						System::Windows::Forms::Label^ label = (Label^)record->Controls->Find(i.ToString(),true)[0];
						label->Text = (i+1).ToString() + ". " +recording() ;

						i++;
					}

				}
		public : String^ recording()
				{
					String^ str;
					
					
					if( l == 0)
					{
						str =		( (t.getHour()   < 10 ) ? "0" + t.getHour().ToString()   : t.getHour().ToString()  )+ ":"; 
						str = str + ( (t.getMinute() < 10 ) ? "0" + t.getMinute().ToString() : t.getMinute().ToString())+ ":"; 
						str = str + ( (t.getSecond() < 10 ) ? "0" + t.getSecond().ToString() : t.getSecond().ToString())+ ".";
						str = str + t.getDsecond().ToString() + t.getCsecond().ToString();
					}
					else
					{
						long  a,b,c;

						int h = 5,m = 4,s = 3,ds = 2,cs = 1;

						a= t.getHour() * 360000 + t.getMinute() * 6000 + t.getSecond() * 100 
							+ t.getDsecond() *10 + t.getCsecond();

						b= moment.getHour() * 360000 + moment.getMinute() * 6000 + moment.getSecond() * 100 
							+ moment.getDsecond() *10 + moment.getCsecond();

						c = a - b;

						cs = c % 10;
						ds = (c / 10) %10;
						s  = (c / 100) %60; ///////////////////////////////////////////////////
						m  = (c / 6000)%60;
						h  = (c / 360000);

						str =       ((h < 10) ? "0" + Convert::ToString(h) : Convert::ToString(h) ) + ":"; 
						str = str + ((m < 10) ? "0" + Convert::ToString(m) : Convert::ToString(m) ) + ":";
						str = str + ((s < 10) ? "0" + Convert::ToString(s) : Convert::ToString(s) ) + ".";
						str = str + Convert::ToString(ds) + Convert::ToString(cs);
					}
					moment.setData(t.getHour() ,t.getMinute() ,t.getSecond() ,t.getDsecond() ,t.getCsecond() );

					return  str;
				}

};//end of ref class Form1
}

