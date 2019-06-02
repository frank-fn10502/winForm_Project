#pragma once
#include "CardGroup.h"
#include "Countdown.h"
#include "Difficulty.h"

namespace TheGuessPocker 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;////////

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
		Form1(int *form ,int* OldGame,bool* IsLoad ,int* from)
		{
			InitializeComponent();
			*form = -1;
			*from =  2;

			ToForm        = form;
			TheOldGame    = OldGame;
			this->IsLoad  = IsLoad;
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

    private: System::Windows::Forms::Panel^       panel1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^       timer1;
	private: System::Windows::Forms::Label^		  score;
	private: System::Windows::Forms::Button^      optionBtn;

	private: System::Windows::Forms::ImageList^   imageList1;
    private: System::Windows::Forms::PictureBox^  sample123;
	private: System::Windows::Forms::Label^		  timeLabel;
	private: System::Windows::Forms::Timer^       TimeTimer;
	private: System::Windows::Forms::Label^		  DifficultyLabel;
	private: System::Windows::Forms::Timer^		  AnimationTimer;



	private: System::Windows::Forms::Panel^  GameOverPanel;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^ BackHome;
	private: System::Windows::Forms::Button^ ReStart;

	private: System::Windows::Forms::Panel^  OptionPanel;
	private: System::Windows::Forms::Button^  BackHome2;
	private: System::Windows::Forms::Button^  ReStart2;
	private: System::Windows::Forms::Button^  LoadBtn;
	private: System::Windows::Forms::Button^  SaveBtn;
	private: System::Windows::Forms::Button^  BackToGame;

	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>	
		bool GameStarted;
		bool Gameover;
		int  flop;
		/*-------------------*/
		int  SCORE;		
		CardGroup^  game;		
		Difficulty^ dif;
		Countdown^  time;////
		String^ GameTime;	
		/*-------------------*/		
	    int*  ToForm;
		int*  TheOldGame;
		bool* IsLoad;
		/*-------------------*/
		static String^ Path     = Path::GetFullPath( "..\\Save\\" );////
		static String^ fileTemp = Path  +  "GameSave100" + ".txt"; ////
		/////////////////////


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->sample123 = (gcnew System::Windows::Forms::PictureBox());
			this->GameOverPanel = (gcnew System::Windows::Forms::Panel());
			this->BackHome = (gcnew System::Windows::Forms::Button());
			this->ReStart = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->OptionPanel = (gcnew System::Windows::Forms::Panel());
			this->BackToGame = (gcnew System::Windows::Forms::Button());
			this->LoadBtn = (gcnew System::Windows::Forms::Button());
			this->SaveBtn = (gcnew System::Windows::Forms::Button());
			this->BackHome2 = (gcnew System::Windows::Forms::Button());
			this->ReStart2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->score = (gcnew System::Windows::Forms::Label());
			this->optionBtn = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->TimeTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->DifficultyLabel = (gcnew System::Windows::Forms::Label());
			this->AnimationTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sample123))->BeginInit();
			this->GameOverPanel->SuspendLayout();
			this->OptionPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->sample123);
			this->panel1->Location = System::Drawing::Point(0, 50);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(840, 646);
			this->panel1->TabIndex = 1;
			// 
			// sample123
			// 
			this->sample123->Cursor = System::Windows::Forms::Cursors::No;
			this->sample123->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"sample123.Image")));
			this->sample123->Location = System::Drawing::Point(10, 10);
			this->sample123->Name = L"sample123";
			this->sample123->Size = System::Drawing::Size(72, 96);
			this->sample123->TabIndex = 1;
			this->sample123->TabStop = false;
			this->sample123->Visible = false;
			// 
			// GameOverPanel
			// 
			this->GameOverPanel->BackColor = System::Drawing::Color::Silver;
			this->GameOverPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->GameOverPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->GameOverPanel->Controls->Add(this->BackHome);
			this->GameOverPanel->Controls->Add(this->ReStart);
			this->GameOverPanel->Controls->Add(this->label10);
			this->GameOverPanel->Controls->Add(this->label12);
			this->GameOverPanel->Controls->Add(this->label13);
			this->GameOverPanel->Controls->Add(this->label11);
			this->GameOverPanel->Location = System::Drawing::Point(606, 40);
			this->GameOverPanel->Name = L"GameOverPanel";
			this->GameOverPanel->Size = System::Drawing::Size(290, 275);
			this->GameOverPanel->TabIndex = 12;
			// 
			// BackHome
			// 
			this->BackHome->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->BackHome->Location = System::Drawing::Point(175, 230);
			this->BackHome->Name = L"BackHome";
			this->BackHome->Size = System::Drawing::Size(100, 30);
			this->BackHome->TabIndex = 17;
			this->BackHome->Text = L"回主選單";
			this->BackHome->UseVisualStyleBackColor = true;
			this->BackHome->Click += gcnew System::EventHandler(this, &Form1::BackHome_Click);
			// 
			// ReStart
			// 
			this->ReStart->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->ReStart->Location = System::Drawing::Point(16, 230);
			this->ReStart->Name = L"ReStart";
			this->ReStart->Size = System::Drawing::Size(100, 30);
			this->ReStart->TabIndex = 16;
			this->ReStart->Text = L"重新開始";
			this->ReStart->UseVisualStyleBackColor = true;
			this->ReStart->Click += gcnew System::EventHandler(this, &Form1::ReStart_Click);
			// 
			// label10
			// 
			this->label10->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label10->Location = System::Drawing::Point(27, 16);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(232, 30);
			this->label10->TabIndex = 15;
			this->label10->Text = L"遊戲難度: 未知";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label12
			// 
			this->label12->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label12->Location = System::Drawing::Point(27, 106);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(232, 30);
			this->label12->TabIndex = 14;
			this->label12->Text = L"分數: ∞";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label13->Location = System::Drawing::Point(27, 151);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(232, 30);
			this->label13->TabIndex = 13;
			this->label13->Text = L"剩餘牌數: 52";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label11
			// 
			this->label11->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label11->Location = System::Drawing::Point(27, 61);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(232, 30);
			this->label11->TabIndex = 12;
			this->label11->Text = L"剩餘時間: 00:00:00";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// OptionPanel
			// 
			this->OptionPanel->BackColor = System::Drawing::Color::Silver;
			this->OptionPanel->Controls->Add(this->BackToGame);
			this->OptionPanel->Controls->Add(this->LoadBtn);
			this->OptionPanel->Controls->Add(this->SaveBtn);
			this->OptionPanel->Controls->Add(this->BackHome2);
			this->OptionPanel->Controls->Add(this->ReStart2);
			this->OptionPanel->Location = System::Drawing::Point(284, 230);
			this->OptionPanel->Name = L"OptionPanel";
			this->OptionPanel->Size = System::Drawing::Size(281, 176);
			this->OptionPanel->TabIndex = 2;
			// 
			// BackToGame
			// 
			this->BackToGame->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->BackToGame->Location = System::Drawing::Point(93, 124);
			this->BackToGame->Name = L"BackToGame";
			this->BackToGame->Size = System::Drawing::Size(100, 30);
			this->BackToGame->TabIndex = 21;
			this->BackToGame->Text = L"返回遊戲";
			this->BackToGame->UseVisualStyleBackColor = true;
			this->BackToGame->Click += gcnew System::EventHandler(this, &Form1::BackToGame_Click);
			// 
			// LoadBtn
			// 
			this->LoadBtn->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->LoadBtn->Location = System::Drawing::Point(154, 69);
			this->LoadBtn->Name = L"LoadBtn";
			this->LoadBtn->Size = System::Drawing::Size(100, 30);
			this->LoadBtn->TabIndex = 20;
			this->LoadBtn->Text = L"載入";
			this->LoadBtn->UseVisualStyleBackColor = true;
			this->LoadBtn->Click += gcnew System::EventHandler(this, &Form1::LoadBtn_Click);
			// 
			// SaveBtn
			// 
			this->SaveBtn->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->SaveBtn->Location = System::Drawing::Point(38, 69);
			this->SaveBtn->Name = L"SaveBtn";
			this->SaveBtn->Size = System::Drawing::Size(100, 30);
			this->SaveBtn->TabIndex = 19;
			this->SaveBtn->Text = L"存檔";
			this->SaveBtn->UseVisualStyleBackColor = true;
			this->SaveBtn->Click += gcnew System::EventHandler(this, &Form1::SaveBtn_Click);
			// 
			// BackHome2
			// 
			this->BackHome2->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->BackHome2->Location = System::Drawing::Point(154, 18);
			this->BackHome2->Name = L"BackHome2";
			this->BackHome2->Size = System::Drawing::Size(100, 30);
			this->BackHome2->TabIndex = 18;
			this->BackHome2->Text = L"回主選單";
			this->BackHome2->UseVisualStyleBackColor = true;
			this->BackHome2->Click += gcnew System::EventHandler(this, &Form1::BackHome_Click);
			// 
			// ReStart2
			// 
			this->ReStart2->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->ReStart2->Location = System::Drawing::Point(38, 18);
			this->ReStart2->Name = L"ReStart2";
			this->ReStart2->Size = System::Drawing::Size(100, 30);
			this->ReStart2->TabIndex = 17;
			this->ReStart2->Text = L"重新開始";
			this->ReStart2->UseVisualStyleBackColor = true;
			this->ReStart2->Click += gcnew System::EventHandler(this, &Form1::ReStart_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// score
			// 
			this->score->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->score->Location = System::Drawing::Point(558, 9);
			this->score->Name = L"score";
			this->score->Size = System::Drawing::Size(151, 28);
			this->score->TabIndex = 7;
			this->score->Text = L"分數: None";
			this->score->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// optionBtn
			// 
			this->optionBtn->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->optionBtn->Location = System::Drawing::Point(758, 9);
			this->optionBtn->Name = L"optionBtn";
			this->optionBtn->Size = System::Drawing::Size(70, 28);
			this->optionBtn->TabIndex = 8;
			this->optionBtn->Text = L"選項";
			this->optionBtn->UseVisualStyleBackColor = true;
			this->optionBtn->Click += gcnew System::EventHandler(this, &Form1::optionBtn_Click);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"0.png");
			this->imageList1->Images->SetKeyName(1, L"1.png");
			this->imageList1->Images->SetKeyName(2, L"2.png");
			this->imageList1->Images->SetKeyName(3, L"3.png");
			this->imageList1->Images->SetKeyName(4, L"4.png");
			this->imageList1->Images->SetKeyName(5, L"5.png");
			this->imageList1->Images->SetKeyName(6, L"6.png");
			this->imageList1->Images->SetKeyName(7, L"7.png");
			this->imageList1->Images->SetKeyName(8, L"8.png");
			this->imageList1->Images->SetKeyName(9, L"9.png");
			this->imageList1->Images->SetKeyName(10, L"10.png");
			this->imageList1->Images->SetKeyName(11, L"11.png");
			this->imageList1->Images->SetKeyName(12, L"12.png");
			this->imageList1->Images->SetKeyName(13, L"13.png");
			this->imageList1->Images->SetKeyName(14, L"14.png");
			this->imageList1->Images->SetKeyName(15, L"15.png");
			this->imageList1->Images->SetKeyName(16, L"16.png");
			this->imageList1->Images->SetKeyName(17, L"17.png");
			this->imageList1->Images->SetKeyName(18, L"18.png");
			this->imageList1->Images->SetKeyName(19, L"19.png");
			this->imageList1->Images->SetKeyName(20, L"20.png");
			this->imageList1->Images->SetKeyName(21, L"21.png");
			this->imageList1->Images->SetKeyName(22, L"22.png");
			this->imageList1->Images->SetKeyName(23, L"23.png");
			this->imageList1->Images->SetKeyName(24, L"24.png");
			this->imageList1->Images->SetKeyName(25, L"25.png");
			this->imageList1->Images->SetKeyName(26, L"26.png");
			this->imageList1->Images->SetKeyName(27, L"27.png");
			this->imageList1->Images->SetKeyName(28, L"28.png");
			this->imageList1->Images->SetKeyName(29, L"29.png");
			this->imageList1->Images->SetKeyName(30, L"30.png");
			this->imageList1->Images->SetKeyName(31, L"31.png");
			this->imageList1->Images->SetKeyName(32, L"32.png");
			this->imageList1->Images->SetKeyName(33, L"33.png");
			this->imageList1->Images->SetKeyName(34, L"34.png");
			this->imageList1->Images->SetKeyName(35, L"35.png");
			this->imageList1->Images->SetKeyName(36, L"36.png");
			this->imageList1->Images->SetKeyName(37, L"37.png");
			this->imageList1->Images->SetKeyName(38, L"38.png");
			this->imageList1->Images->SetKeyName(39, L"39.png");
			this->imageList1->Images->SetKeyName(40, L"40.png");
			this->imageList1->Images->SetKeyName(41, L"41.png");
			this->imageList1->Images->SetKeyName(42, L"42.png");
			this->imageList1->Images->SetKeyName(43, L"43.png");
			this->imageList1->Images->SetKeyName(44, L"44.png");
			this->imageList1->Images->SetKeyName(45, L"45.png");
			this->imageList1->Images->SetKeyName(46, L"46.png");
			this->imageList1->Images->SetKeyName(47, L"47.png");
			this->imageList1->Images->SetKeyName(48, L"48.png");
			this->imageList1->Images->SetKeyName(49, L"49.png");
			this->imageList1->Images->SetKeyName(50, L"50.png");
			this->imageList1->Images->SetKeyName(51, L"51.png");
			this->imageList1->Images->SetKeyName(52, L"52.png");
			// 
			// timeLabel
			// 
			this->timeLabel->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->timeLabel->Location = System::Drawing::Point(316, 9);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(151, 28);
			this->timeLabel->TabIndex = 9;
			this->timeLabel->Text = L"00:00:00";
			this->timeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TimeTimer
			// 
			this->TimeTimer->Tick += gcnew System::EventHandler(this, &Form1::TimeTimer_Tick);
			// 
			// DifficultyLabel
			// 
			this->DifficultyLabel->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->DifficultyLabel->Location = System::Drawing::Point(12, 9);
			this->DifficultyLabel->Name = L"DifficultyLabel";
			this->DifficultyLabel->Size = System::Drawing::Size(151, 28);
			this->DifficultyLabel->TabIndex = 10;
			this->DifficultyLabel->Text = L"難度: 未知";
			this->DifficultyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// AnimationTimer
			// 
			this->AnimationTimer->Tick += gcnew System::EventHandler(this, &Form1::AnimationTimer_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(840, 697);
			this->Controls->Add(this->GameOverPanel);
			this->Controls->Add(this->DifficultyLabel);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->OptionPanel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->optionBtn);
			this->Controls->Add(this->score);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sample123))->EndInit();
			this->GameOverPanel->ResumeLayout(false);
			this->OptionPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {	
			    dif  = gcnew Difficulty();
 				GameData();		 
				/*----------------------------------*/
				GameLoadSet();
				if( File::Exists(fileTemp) ) File::Delete(fileTemp);				
			 }
 	private: System::Void TimeTimer_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				if( !time->countDown() ) 
				{
					if( !GameStarted ) GameStartSet();
					else			   TheEnd(); //結束遊戲
				}
				else timeLabel->Text = time->getTimes();
			 }
	private: System::Void pictureBox_Click(System::Object^  sender, System::EventArgs^  e) ////////
			 {
				++flop;
								
				PictureBox^ pbox = (PictureBox^)sender;
				int n = Convert::ToInt16( pbox->Name );

				pbox->Image  = imageList1->Images[ game->getCard(n) ];
				pbox->Click -= gcnew System::EventHandler(this, &Form1::pictureBox_Click);
				pbox->Cursor = Cursors::No;

				if( flop == 1 )
				{
					game->setTheOne( n );
				}
				else if( flop == 2 )
				{
					game->setThePair( game->getTheOne() ,n  );
					game->setThePair( n , game->getTheOne() );
					flop = 0;				
				}
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 for(int i = 0 ; i < game->getCardNum() ; i++ )
				 {
					if( game->getThePair(i) != -1 )
					{					
						 SCORE += game->ISPair(i ,game->getThePair(i) );				
						 score->Text = "分數: " + SCORE.ToString();
					}
				 }
				 if( game->getCoverNum() <= 4 && game->Animationdone() )
				 {
					 if( game->IsNoPair() ) TheEnd(); //結束遊戲
				 }
			 }
	private: System::Void AnimationTimer_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 for(int i = 0 ; i < game->getCardNum() ; i++ ) 
				 {
					 SpecialEffects(i);///接下來0.8s會顯示特效,但判斷已經結束
				 }
				 if( Gameover ) 
				 {
					 if( GameOverPanel->Location.X > 284)
					 {
						 GameOverPanel->Location = Drawing::Point(GameOverPanel->Location.X - 50 ,124 );	
					 }
					 else
					 {
						GameOverPanel->Location = Drawing::Point(284 ,124 );//GameOverPanel (284, 124)	
						AnimationTimer->Enabled  = false;
					 }
				 }
			 }
	private: System::Void BackHome_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				*ToForm = 1;
				this->Close();
			 }
	private: System::Void SaveBtn_Click(System::Object^  sender, System::EventArgs^  e)
			 { 
				 StreamWriter^ sw = gcnew StreamWriter(fileTemp);  
				 sw->WriteLine("時間: "+ DateTime::Now         );
				 sw->WriteLine("難度: "+ dif->getDifficulty()  );
				 sw->WriteLine("記憶時間: "+ dif->getUseRT()   ); 
				 sw->WriteLine("倒數時間: "+ dif->getRT()	   ); 
				 sw->WriteLine("使用時間: "+ dif->getUseTime() ); 
				 sw->WriteLine("遊戲時間: "+ dif->getTime()    );
				 sw->WriteLine("牌數: "+ game->getCardNum()    );
				 sw->WriteLine("================"); 
				 if( dif->getUseTime() ) sw->WriteLine("剩餘時間: "+ time->getTimes()  );
				 else				     sw->WriteLine("剩餘時間: "+ "∞"  );		 
				 sw->WriteLine("分數: "+ SCORE.ToString()      );		 
				 
				 for(int i = 0 ; i < game->getCardNum() ; i++ )
				 {
					 sw->WriteLine( i.ToString() + ": "+ game->getOpen(i).ToString() 
								  + ","+game->getCard(i).ToString() );
				 }			 
				 sw->Close(); 
				 
				 *IsLoad = false;
				 *ToForm = 10;			 
				 this->Close();
			 }
	private: System::Void LoadBtn_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 *IsLoad = true;
				 *ToForm = 10;//到存檔頁面
				 this->Close();
			 }
	private: System::Void ReStart_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 GameLoadSet();
			 }
	private: System::Void BackToGame_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				IsPause( false );
			 }
	private: System::Void optionBtn_Click(System::Object^  sender, System::EventArgs^  e) ////////////////////
			 {
				 LoadBtn->Enabled = false;
				 for(int i = 1 ; i <= 10 ; i ++)
				 {
					 String^ fileName = Path  +  "GameSave" + i.ToString() + ".txt";
					 if( File::Exists( fileName ) )
					 {
						LoadBtn->Enabled = true;
						break;
					 }
				 }
				 IsPause( true );
			 }

	/*=========================================================================================*/
	private: void GameData()
			 {
				 if( (*TheOldGame) == 0 )
				 {
					 String^ PathData = Path::GetFullPath( "..\\GameData\\" );
					 String^ fileName = PathData + "Game.txt";
					 StreamReader^ TheData = File::OpenText( fileName );
					 BasicData( TheData );
					 TheData->Close();
				 }
				 else
				 {
				     String^ fileName = Path  + "GameSave" + (*TheOldGame).ToString() + ".txt";
					 StreamReader^ TheSave = File::OpenText(fileName);	         
					 BasicData( TheSave );

					 game = gcnew CardGroup( dif->getCardNum() );////
					 if( dif->getUseRT() ) time = gcnew Countdown( dif->getRT() );////

					 String^ str;  
					 while ((str = TheSave->ReadLine()) != nullptr)   
					 {   
						 if( str->StartsWith("剩餘時間: ") )
						 {
							if( dif->getUseTime() )
							{
								str = str->Substring( str->IndexOf(" ")+1 );
								GameTime = str;							
							}
						 }
						 else if( str->StartsWith("分數: ") )
						 {
							str = str->Substring( str->IndexOf(" ")+1 );
							int num = Convert::ToInt16( str );
							SCORE = num;
						 }
						 else if( Char::IsDigit( str ,0) )
						 {
							 String^ temp = str->Substring( 0 ,str->IndexOf(":") );
							 int  i = Convert::ToInt16( temp );
							 temp = str->Substring( str->IndexOf(" ")+1 ,str->IndexOf(",") - str->IndexOf(" ") -1 );
							 bool tempB = Convert::ToBoolean( temp );

							 temp = str->Substring( str->IndexOf(",")+1 );
							 int cardnum = Convert::ToInt16( temp ); 

							 game->setOpen(i ,tempB  );
							 game->setCard(i ,cardnum);
						 }						 
					 }  
					 TheSave->Close();					 
				 }
			 }
    private: void BasicData(StreamReader^ TheData )
			 {			 
				 String^ str;		 
				 while (( str = TheData->ReadLine() ) != nullptr )
				 {	
					 if( str->StartsWith("難度: ") )
					 {
						str = str->Substring( str->IndexOf(" ")+1 );
						dif->setDifficulty( str );
					 }
					 else if( str->StartsWith("記憶時間: ") )
					 {
						str = str->Substring( str->IndexOf(" ")+1 );
						bool temp = Convert::ToBoolean( str );
						dif->setUseRT( temp );
					 }
 					 else if( str->StartsWith("倒數時間: ") )
					 {
						if( dif->getUseRT() )
						{
							str = str->Substring( str->IndexOf(" ")+1 );
							dif->setRT( str );
						}
						else dif->setRT( "None" );
					 }
					 else if( str->StartsWith("使用時間: ") )
					 {
						str = str->Substring( str->IndexOf(" ")+1 );
						bool temp = Convert::ToBoolean( str );
						dif->setUseTime( temp );
					 }
 					 else if( str->StartsWith("遊戲時間: ") )
					 {
						str = str->Substring( str->IndexOf(" ")+1 );
						dif->setTime( str );
					 }
					 else if( str->StartsWith("牌數: ") )
					 {						    
						str = str->Substring( str->IndexOf(" ")+1 );
						int num = Convert::ToInt16( str );
						dif->setCardNum( num );
						break;
					 }			 
				 }
			 }
	private: void GameLoadSet()
			 {
				 GameStarted = false;
				 Gameover    = false;
				 flop = 0;

				 if( *TheOldGame == 0)
				 {
				    SCORE = 0;
					game = gcnew CardGroup( dif->getCardNum() );
					if( dif->getUseRT() ) 
					{ 
						time = gcnew Countdown( dif->getRT() ); 
					}
					GameTime = dif->getTime();////
				 }
				 else *TheOldGame = 0;//歸零
				 /*-----------------------------------*/
				 game->setTick( 50 );
				 /*----------------------------------*/
				 GameOverPanel->Location  = Drawing::Point(840 ,124 );
				 GameOverPanel->Visible   = false;
				 OptionPanel->Visible     = false;

				 optionBtn->Enabled       = true;

				 DifficultyLabel->Text   = "難度: " + dif->getDifficulty();
				 score->Text             = "分數: " + SCORE.ToString();

				 timer1->Interval		  = game->getTick();
				 AnimationTimer->Interval = game->getTick();
				 TimeTimer->Interval      = 1000;

				 panel1->Controls->Clear();
				 for(int i = 0 ; i < game->getCardNum() ; i++ )
					panel1->Controls->Add( AddNewPictureBox( i ,dif->getUseRT() ) );

				 if( dif->getUseRT() )
				 {
					 timeLabel->Text    = dif->getRT();
					 TimeTimer->Enabled = true;
				 }
				 else GameStartSet();
			 }
	private: PictureBox^ AddNewPictureBox(int i ,bool open)
			 {
				 PictureBox^ pictureBox_temp  = gcnew PictureBox();
					
				 pictureBox_temp->Location = Drawing::Point(10 + (i %10)* (10+72), 10 + (i /10) * (10+ 96));
				 pictureBox_temp->Size	   = Drawing::Size(62, 86);//72, 96
				 pictureBox_temp->Name     = i.ToString();
				 pictureBox_temp->SizeMode = PictureBoxSizeMode::StretchImage;
				 if( !game->getOpen(i) )
				 {
					if( open ) pictureBox_temp->Image = imageList1->Images[ game->getCard(i) ];
					else	   
					{
						pictureBox_temp->Image  = imageList1->Images[0];
						pictureBox_temp->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
					}
				 }
				 else if( game->getOpen(i) )
				 {
					pictureBox_temp->Image = nullptr;
				 }
				 			
				 return pictureBox_temp;
			 }
	private: void GameStartSet()
			 {
				GameStarted = true;
				if( dif->getUseRT() )
				{
					for(int i = 0 ; i < game->getCardNum() ; i++ )
					{
						if( !game->getOpen(i) )
						{
							PictureBox^ pbox = (PictureBox^)panel1->Controls->Find( i.ToString(),true)[0];
							pbox->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
							pbox->Image  = imageList1->Images[0];
						}
					}
				}
				timeLabel->Text = GameTime;//dif->getTime();
				if( dif->getUseTime() ) 
				{
					 TimeTimer->Enabled  = true;
					 if( dif->getUseTime() ) 
						 time = gcnew Countdown( GameTime );
				}
				else 
				{
					if( TimeTimer->Enabled )
					{
						TimeTimer->Enabled  = false;
					}
				}	
				timer1->Enabled          = true;
				AnimationTimer->Enabled  = true;
			 }
	private: void SpecialEffects(int i)
			 {			  
				if( game->getSecond(i) != 0 )
				{
					if( game->getSecond(i) < 0 ) game->setSecond( i ,0 );///

					PictureBox^ pbox = (PictureBox^)panel1->Controls->Find( i.ToString(),true)[0];
					if( game->getSecond(i) < game->getTick()*5 )
					{													
						pbox->Location = Drawing::Point(pbox->Location.X -1 ,pbox->Location.Y-1 );					
						pbox->Width  = pbox->Width  + 2;
						pbox->Height = pbox->Height + 2;
					}
					else if( game->getSecond(i) < game->getTick()*10 )
					{					
						pbox->Location = Drawing::Point(pbox->Location.X+1 ,pbox->Location.Y+1 );
						pbox->Width  = pbox->Width  - 2;
						pbox->Height = pbox->Height - 2;
					}
					else if( game->getSecond(i) >= game->getTick()*15 )//15
					{
						pbox->Location = Drawing::Point(10 + (i %10)* (10+72), 10 + (i /10) * (10+ 96));
						pbox->Size = Drawing::Size(62 ,86);//72, 96

						if( !game->getOpen(i) )
						{
							pbox->Image  = imageList1->Images[0];
							pbox->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);						
						}
						else 
						{
							pbox->Image = nullptr;			
						}
						pbox->Cursor = Cursors::Default;
					}
					game->OneTick(i);
				}			
			 }
	private: void TheEnd()//////////////
			 {
				GameOverPanel->Visible = true;
				Gameover		   = true;

				if( dif->getUseTime() ) 
				{
					TimeTimer->Enabled = false;
				}
				timer1->Enabled	   = false;
				
				optionBtn->Enabled = false;
				for(int i = 0 ; i < game->getCardNum() ; i++ )
				{
					if( !game->getOpen(i) )
					{
						PictureBox^ pbox = (PictureBox^)panel1->Controls->Find( i.ToString(),true)[0];
						pbox->Click -= gcnew System::EventHandler(this, &Form1::pictureBox_Click);
						pbox->Image  = imageList1->Images[ game->getCard(i) ];
						pbox->Cursor = Cursors::Default;
					}
				}		
				label10->Text     = "遊戲難度: " + dif->getDifficulty();
				label11->Text     = "剩餘時間: " + timeLabel->Text;////
				label12->Text     = "分數: "     + SCORE.ToString();
				label13->Text     = "剩餘牌數: " + game->getCoverNum();
			 }
	private: void IsPause(bool pause)
			 {
				for(int i = 0 ; i < game->getCardNum() ; i++ )
				{				
					if( !game->getOpen(i) )
					{
						PictureBox^ pbox = (PictureBox^) panel1->Controls->Find( i.ToString(),true)[0];
						pbox->Enabled = true;
					}
					if( pause && game->getSecond(i) != 0 )
					{
						game->setSecond(i ,1000 );
						SpecialEffects(i);////////////////////
					}
				}	
				if( dif->getUseTime() || dif->getUseRT() ) TimeTimer->Enabled = !pause;
				timer1->Enabled          = !pause;
				AnimationTimer->Enabled  = !pause;

				optionBtn->Enabled   = !pause;
				OptionPanel->Visible =  pause;
			 }
	};//end of class Form1
}//end of namespace TheGuessPocker

