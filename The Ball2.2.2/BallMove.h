#pragma once
#include "Ball.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TheBall {

	/// <summary>
	/// BallMove 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class BallMove : public System::Windows::Forms::Form
	{
	public:
		BallMove(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//			
		}
		BallMove(array<Ball^> ^% b , int N )
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			N_temp = N;
			b_temp = b;
			close = true;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~BallMove()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  Start_Move;
	private: System::Windows::Forms::Button^  Stop_Move;
	private: System::Windows::Forms::Button^  BackBtn;
	private: System::Windows::Forms::Label^  ball1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		int N_temp;
		array<Ball^> ^ b_temp;
		System::Drawing::Graphics^ formGraphics;
		System::Drawing::SolidBrush^ myBrush;

	public: static bool close;

					
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ball1 = (gcnew System::Windows::Forms::Label());
			this->Start_Move = (gcnew System::Windows::Forms::Button());
			this->Stop_Move = (gcnew System::Windows::Forms::Button());
			this->BackBtn = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->ball1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(510, 450);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BallMove::panel1_Paint);
			// 
			// ball1
			// 
			this->ball1->AutoEllipsis = true;
			this->ball1->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->ball1->ForeColor = System::Drawing::Color::Blue;
			this->ball1->Location = System::Drawing::Point(251, 120);
			this->ball1->Name = L"ball1";
			this->ball1->Size = System::Drawing::Size(73, 49);
			this->ball1->TabIndex = 0;
			this->ball1->Text = L"●";
			this->ball1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->ball1->Visible = false;
			// 
			// Start_Move
			// 
			this->Start_Move->Location = System::Drawing::Point(411, 481);
			this->Start_Move->Name = L"Start_Move";
			this->Start_Move->Size = System::Drawing::Size(67, 33);
			this->Start_Move->TabIndex = 1;
			this->Start_Move->Text = L"開始移動";
			this->Start_Move->UseVisualStyleBackColor = true;
			this->Start_Move->Click += gcnew System::EventHandler(this, &BallMove::Start_Move_Click);
			// 
			// Stop_Move
			// 
			this->Stop_Move->Location = System::Drawing::Point(218, 481);
			this->Stop_Move->Name = L"Stop_Move";
			this->Stop_Move->Size = System::Drawing::Size(67, 33);
			this->Stop_Move->TabIndex = 2;
			this->Stop_Move->Text = L"停止移動";
			this->Stop_Move->UseVisualStyleBackColor = true;
			this->Stop_Move->Click += gcnew System::EventHandler(this, &BallMove::Stop_Move_Click);
			// 
			// BackBtn
			// 
			this->BackBtn->Location = System::Drawing::Point(21, 481);
			this->BackBtn->Name = L"BackBtn";
			this->BackBtn->Size = System::Drawing::Size(67, 33);
			this->BackBtn->TabIndex = 3;
			this->BackBtn->Text = L"返回";
			this->BackBtn->UseVisualStyleBackColor = true;
			this->BackBtn->Click += gcnew System::EventHandler(this, &BallMove::BackBtn_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &BallMove::timer1_Tick);
			// 
			// BallMove
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 526);
			this->Controls->Add(this->BackBtn);
			this->Controls->Add(this->Stop_Move);
			this->Controls->Add(this->Start_Move);
			this->Controls->Add(this->panel1);
			this->Name = L"BallMove";
			this->Text = L"BallMove";
			this->Load += gcnew System::EventHandler(this, &BallMove::BallMove_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void BallMove_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 formGraphics = panel1->CreateGraphics();
				 myBrush = gcnew SolidBrush(Color::AliceBlue);

				 timer1->Interval= 15;
			 }
    private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
			 {
				 for(int i = 0 ; i< N_temp ; i ++)
				 {					
					DrawCircle(b_temp[i]->getBallposition_x() 
							  ,b_temp[i]->getBallposition_y() 
							  ,b_temp[i]->getBallsize()
							  ,b_temp[i]->getColor() );
				 }
			 }
	private: System::Void BackBtn_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 timer1->Enabled = false;
				 close = false;
				 this->Close();
			 }
	private: System::Void Start_Move_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 timer1->Enabled = true;			 			 
			 }
	private: System::Void Stop_Move_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 timer1->Enabled = false;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Ball::Moving(b_temp); 
				 panel1->Refresh();				
			 } 
	private: void DrawCircle(float loc_x ,float loc_y ,float size ,System::Drawing::Color col)
			 {
				myBrush->Color = col;
			    formGraphics->FillEllipse(myBrush ,loc_x ,loc_y ,size ,size );
			 }

};
}
