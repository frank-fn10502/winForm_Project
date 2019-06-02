#pragma once

#include "PlayingCard.h"

#include "time.h"
#include "stdlib.h"
#include "stdio.h"


namespace ThePocker 
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
			srand( (unsigned)time( NULL ) );
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
	private: System::Windows::Forms::ImageList^  imageList1;


	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox3;

	private: System::Windows::Forms::PictureBox^  pictureBox4;


	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::Panel^  com_intro;
	private: System::Windows::Forms::Label^  computer_money;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  computer_betting;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  mid_label;
	private: System::Windows::Forms::Label^  player_CardType;
	private: System::Windows::Forms::Label^  computer_CardType;
	private: System::Windows::Forms::Panel^  player_intro;
	private: System::Windows::Forms::TextBox^  money_input;

	private: System::Windows::Forms::Label^  player_betting;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  player_money;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::Panel^  com_CardGroup;
	private: System::Windows::Forms::Panel^  player_CardGroup;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  roundOverBtn;
	private: System::Windows::Forms::Button^  againBtn;

	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		Graphics^ mygraphics;
		Label^    myLabel;
		array<Rectangle>^ rectangle;

		PlayingCard^ player;
		/// </summary>
		static int over = 0;
		static int tick = 0;
		static int cardNum = 1;
		int PlayerMoney;
		int PlayerBetting;
		int ComputerMoney;
		int ComputerBetting;
		/////////


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->com_intro = (gcnew System::Windows::Forms::Panel());
			this->computer_betting = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->computer_money = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mid_label = (gcnew System::Windows::Forms::Label());
			this->player_CardType = (gcnew System::Windows::Forms::Label());
			this->computer_CardType = (gcnew System::Windows::Forms::Label());
			this->player_intro = (gcnew System::Windows::Forms::Panel());
			this->money_input = (gcnew System::Windows::Forms::TextBox());
			this->player_betting = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->player_money = (gcnew System::Windows::Forms::Label());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->com_CardGroup = (gcnew System::Windows::Forms::Panel());
			this->player_CardGroup = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->roundOverBtn = (gcnew System::Windows::Forms::Button());
			this->againBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->BeginInit();
			this->com_intro->SuspendLayout();
			this->player_intro->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->BeginInit();
			this->com_CardGroup->SuspendLayout();
			this->player_CardGroup->SuspendLayout();
			this->SuspendLayout();
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
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(9, 4);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(72, 96);
			this->pictureBox6->TabIndex = 12;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(98, 4);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(72, 96);
			this->pictureBox7->TabIndex = 13;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(194, 4);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(72, 96);
			this->pictureBox8->TabIndex = 14;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(283, 4);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(72, 96);
			this->pictureBox9->TabIndex = 15;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(369, 4);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(72, 96);
			this->pictureBox10->TabIndex = 16;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(369, 4);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(72, 96);
			this->pictureBox5->TabIndex = 7;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(194, 4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(72, 96);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(283, 4);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(72, 96);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(98, 4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(72, 96);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(9, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(72, 96);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(2, 3);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(17, 18);
			this->pictureBox11->TabIndex = 17;
			this->pictureBox11->TabStop = false;
			// 
			// com_intro
			// 
			this->com_intro->BackColor = System::Drawing::Color::Silver;
			this->com_intro->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->com_intro->Controls->Add(this->computer_betting);
			this->com_intro->Controls->Add(this->label4);
			this->com_intro->Controls->Add(this->computer_money);
			this->com_intro->Controls->Add(this->pictureBox11);
			this->com_intro->Location = System::Drawing::Point(464, 63);
			this->com_intro->Name = L"com_intro";
			this->com_intro->Size = System::Drawing::Size(189, 105);
			this->com_intro->TabIndex = 18;
			// 
			// computer_betting
			// 
			this->computer_betting->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->computer_betting->Location = System::Drawing::Point(3, 42);
			this->computer_betting->Name = L"computer_betting";
			this->computer_betting->Size = System::Drawing::Size(186, 18);
			this->computer_betting->TabIndex = 20;
			this->computer_betting->Text = L"000";
			this->computer_betting->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(3, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(147, 18);
			this->label4->TabIndex = 19;
			this->label4->Text = L"下注總金額: ";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// computer_money
			// 
			this->computer_money->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->computer_money->Location = System::Drawing::Point(25, 3);
			this->computer_money->Name = L"computer_money";
			this->computer_money->Size = System::Drawing::Size(159, 18);
			this->computer_money->TabIndex = 18;
			this->computer_money->Text = L"3,000";
			this->computer_money->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(12, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 30);
			this->label2->TabIndex = 19;
			this->label2->Text = L"電腦";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(12, 287);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 30);
			this->label3->TabIndex = 20;
			this->label3->Text = L"玩家";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mid_label
			// 
			this->mid_label->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->mid_label->Location = System::Drawing::Point(197, 216);
			this->mid_label->Name = L"mid_label";
			this->mid_label->Size = System::Drawing::Size(91, 30);
			this->mid_label->TabIndex = 21;
			this->mid_label->Text = L"電腦回合";
			this->mid_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// player_CardType
			// 
			this->player_CardType->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->player_CardType->Location = System::Drawing::Point(75, 287);
			this->player_CardType->Name = L"player_CardType";
			this->player_CardType->Size = System::Drawing::Size(383, 30);
			this->player_CardType->TabIndex = 22;
			this->player_CardType->Text = L"同花順";
			this->player_CardType->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// computer_CardType
			// 
			this->computer_CardType->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->computer_CardType->Location = System::Drawing::Point(75, 23);
			this->computer_CardType->Name = L"computer_CardType";
			this->computer_CardType->Size = System::Drawing::Size(373, 30);
			this->computer_CardType->TabIndex = 23;
			this->computer_CardType->Text = L"同花順";
			this->computer_CardType->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// player_intro
			// 
			this->player_intro->BackColor = System::Drawing::Color::Silver;
			this->player_intro->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->player_intro->Controls->Add(this->money_input);
			this->player_intro->Controls->Add(this->player_betting);
			this->player_intro->Controls->Add(this->label7);
			this->player_intro->Controls->Add(this->player_money);
			this->player_intro->Controls->Add(this->pictureBox12);
			this->player_intro->Location = System::Drawing::Point(464, 316);
			this->player_intro->Name = L"player_intro";
			this->player_intro->Size = System::Drawing::Size(189, 107);
			this->player_intro->TabIndex = 24;
			// 
			// money_input
			// 
			this->money_input->BackColor = System::Drawing::Color::White;
			this->money_input->Location = System::Drawing::Point(2, 73);
			this->money_input->Name = L"money_input";
			this->money_input->Size = System::Drawing::Size(133, 22);
			this->money_input->TabIndex = 22;
			this->money_input->TextChanged += gcnew System::EventHandler(this, &Form1::money_input_TextChanged);
			this->money_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::money_input_KeyDown);
			this->money_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::money_input_KeyPress);
			// 
			// player_betting
			// 
			this->player_betting->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->player_betting->Location = System::Drawing::Point(3, 42);
			this->player_betting->Name = L"player_betting";
			this->player_betting->Size = System::Drawing::Size(185, 18);
			this->player_betting->TabIndex = 20;
			this->player_betting->Text = L"000";
			this->player_betting->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(3, 24);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(147, 18);
			this->label7->TabIndex = 19;
			this->label7->Text = L"下注總金額: ";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// player_money
			// 
			this->player_money->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->player_money->Location = System::Drawing::Point(25, 3);
			this->player_money->Name = L"player_money";
			this->player_money->Size = System::Drawing::Size(159, 18);
			this->player_money->TabIndex = 18;
			this->player_money->Text = L"3,000";
			this->player_money->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(2, 3);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(17, 18);
			this->pictureBox12->TabIndex = 17;
			this->pictureBox12->TabStop = false;
			// 
			// com_CardGroup
			// 
			this->com_CardGroup->Controls->Add(this->pictureBox1);
			this->com_CardGroup->Controls->Add(this->pictureBox2);
			this->com_CardGroup->Controls->Add(this->pictureBox4);
			this->com_CardGroup->Controls->Add(this->pictureBox3);
			this->com_CardGroup->Controls->Add(this->pictureBox5);
			this->com_CardGroup->Location = System::Drawing::Point(7, 63);
			this->com_CardGroup->Name = L"com_CardGroup";
			this->com_CardGroup->Size = System::Drawing::Size(454, 105);
			this->com_CardGroup->TabIndex = 25;
			// 
			// player_CardGroup
			// 
			this->player_CardGroup->Controls->Add(this->pictureBox10);
			this->player_CardGroup->Controls->Add(this->pictureBox9);
			this->player_CardGroup->Controls->Add(this->pictureBox8);
			this->player_CardGroup->Controls->Add(this->pictureBox7);
			this->player_CardGroup->Controls->Add(this->pictureBox6);
			this->player_CardGroup->Location = System::Drawing::Point(7, 316);
			this->player_CardGroup->Name = L"player_CardGroup";
			this->player_CardGroup->Size = System::Drawing::Size(454, 107);
			this->player_CardGroup->TabIndex = 26;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// roundOverBtn
			// 
			this->roundOverBtn->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->roundOverBtn->Location = System::Drawing::Point(464, 280);
			this->roundOverBtn->Name = L"roundOverBtn";
			this->roundOverBtn->Size = System::Drawing::Size(85, 30);
			this->roundOverBtn->TabIndex = 27;
			this->roundOverBtn->Text = L"回合結束";
			this->roundOverBtn->UseVisualStyleBackColor = true;
			this->roundOverBtn->Click += gcnew System::EventHandler(this, &Form1::roundOverBtn_Click);
			// 
			// againBtn
			// 
			this->againBtn->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->againBtn->Location = System::Drawing::Point(568, 280);
			this->againBtn->Name = L"againBtn";
			this->againBtn->Size = System::Drawing::Size(85, 30);
			this->againBtn->TabIndex = 28;
			this->againBtn->Text = L"再來一回";
			this->againBtn->UseVisualStyleBackColor = true;
			this->againBtn->Visible = false;
			this->againBtn->Click += gcnew System::EventHandler(this, &Form1::againBtn_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 435);
			this->Controls->Add(this->againBtn);
			this->Controls->Add(this->roundOverBtn);
			this->Controls->Add(this->player_CardGroup);
			this->Controls->Add(this->com_CardGroup);
			this->Controls->Add(this->player_intro);
			this->Controls->Add(this->com_intro);
			this->Controls->Add(this->player_CardType);
			this->Controls->Add(this->computer_CardType);
			this->Controls->Add(this->mid_label);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->EndInit();
			this->com_intro->ResumeLayout(false);
			this->player_intro->ResumeLayout(false);
			this->player_intro->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->EndInit();
			this->com_CardGroup->ResumeLayout(false);
			this->player_CardGroup->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 timer1->Interval = 250;
				 player = gcnew PlayingCard(2);

				 computer_CardType->Text = "";
				 player_CardType->Text = "";
				 
				 PlayerMoney  = 3000;//////
				 ComputerMoney = 3000;/////
				 computer_money->Text = ComputerMoney.ToString();//////
				 player_money->Text   = PlayerMoney.ToString();//////

				 int first = rand() % 100;
				 if( first % 2 == 0 )      playerTurn(); 
				 else if( first % 2 != 0 ) computerTurn();			 
			 }	
 	private: System::Void againBtn_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
 				for(int i = 0 ; i < 10 ; i++)
				{
					PictureBox^ pbox = (PictureBox^)Form1::Controls->Find("pictureBox" + (i+1).ToString(),true)[0]; 
					pbox->Image = imageList1->Images[0];
				}
				mygraphics->Clear(Form1::BackColor);
				myLabel->ForeColor = Color::Black;

				computer_CardType->Text = "";
				player_CardType->Text = "";
				////////////////////////////////////
				if( PlayerMoney == 0 || ComputerMoney == 0 ) 
				{
					 PlayerMoney  = 3000;//////
					 ComputerMoney = 3000;/////
					 computer_money->Text = ComputerMoney.ToString();//////
					 player_money->Text   = PlayerMoney.ToString();//////
				}
				 player = gcnew PlayingCard(2);
				 over = 0;

				 int first = rand() % 100;
				 if( first % 2 == 0 )      playerTurn(); 
				 else if( first % 2 != 0 ) computerTurn();	

				 againBtn->Visible = false;
			 }
	private: System::Void roundOverBtn_Click(System::Object^  sender, System::EventArgs^  e) 
			 {	
 				 mygraphics->Clear(Form1::BackColor);
				 myLabel->ForeColor = Color::Black;
				 ///////////
				 player_betting->Text = money_input->Text;
				 PlayerBetting  = Convert::ToInt16(player_betting->Text);

				 PlayerMoney -= PlayerBetting;
				 player_money->Text = PlayerMoney.ToString();
				 ////////////////
				 money_input->Text = "0";				 
				 computerTurn();
			 }
	private: void computerTurn()
			 {				 
				 money_input->BackColor = Color::Silver;
				 money_input->ReadOnly = true;
				 roundOverBtn->Enabled = false;

				 over++;				 			 
				 if( over == 3) Comparison();
				 else			
				 {
					 computer_betting->Text = "000";

 					 rectangle = gcnew array<Rectangle>(1);
					 rectangle[0]  = com_CardGroup->ClientRectangle;
					 SelectA(0);
				 }
			 }
 	private: void playerTurn()
			 {
				 over++;				 			 
				 if( over == 3) Comparison();
				 else			
				 {
					 player_betting->Text = "000";

 					 rectangle = gcnew array<Rectangle>(1);
					 rectangle[0]  = player_CardGroup->ClientRectangle;
					 SelectA(1);

					 money_input->ReadOnly = false;
					 money_input->BackColor = Color::White;
				     roundOverBtn->Enabled = true;
				 }
			 }
 	private: void Comparison()
			 {	
			    
				int t = player->Compare(player_CardType ,computer_CardType );

				for(int i = 0 ; i < 10 ; i++)
				{
					PictureBox^ pbox = (PictureBox^)Form1::Controls->Find("pictureBox" + (i+1).ToString(),true)[0]; 
					pbox->Image = imageList1->Images[player->getHandCard(i)];
				}
				if( t == 0) 
				{
					ComputerMoney += PlayerBetting + ComputerBetting;
					computer_money->Text = ComputerMoney.ToString();

					SelectA(0);
					mid_label->Text = "電腦獲勝";
				}
				else if( t == 1) 
				{
					PlayerMoney += ComputerBetting + PlayerBetting;
					player_money->Text = PlayerMoney.ToString();

					SelectA(1);
					mid_label->Text = "玩家獲勝";
				}
				else if( t == -1) 
				{
					mid_label->Text = "平手";
				}


				if( PlayerMoney == 0 || ComputerMoney == 0 ) 
				{
					againBtn->Text = "重新開始";
					againBtn->ForeColor = Color::Red;
				}
				else
				{
					againBtn->Text = "再來一回";
					againBtn->ForeColor = Color::Black;
				}
				againBtn->Visible = true;
			 }
	private: void SelectA(int s)
			 {
				if(s == 0)
				{
					 mygraphics = com_CardGroup->CreateGraphics();
					 mid_label->Text = "電腦回合";
					 myLabel = (Label^ )Form1::Controls->Find("label2",true)[0];
					 timer1->Enabled = true;
				}
				else if(s == 1)
				{
					 mygraphics = player_CardGroup->CreateGraphics();
					 mid_label->Text = "玩家回合";
					 myLabel = (Label^ )Form1::Controls->Find("label3",true)[0];
					 timer1->Enabled = true;
				}
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {	
				 int a = rand() % 255;
				 int b = rand() % 255;
				 int c = rand() % 255;

				Color color = Color::FromArgb(a,b,c);

				for(int i = 0 ; i < rectangle->Length ; i++ )
				{
					ControlPaint::DrawBorder( mygraphics, rectangle[0] , 
						color ,ButtonBorderStyle::Solid );
				}
				myLabel->ForeColor = color;

				 if(tick <= 1000 ) tick+=250;   //////////////3000
				 else			   
				 {
					for(int i = 0 ; i < rectangle->Length ; i++ )
					{
						ControlPaint::DrawBorder( mygraphics, rectangle[i] , 
												  Color::Blue ,ButtonBorderStyle::Solid );
					}
					myLabel->ForeColor = Color::Blue;
					tick = 0;
					timer1->Enabled = false;

					if(myLabel->Name == "label2" && over != 3)
					{
						mygraphics->Clear(Form1::BackColor);
						myLabel->ForeColor = Color::Black;

						ComputerBetting = rand()%ComputerMoney + 1;
						ComputerMoney -= ComputerBetting;

						computer_money->Text   = ComputerMoney.ToString();
						computer_betting->Text = ComputerBetting.ToString();

						playerTurn();
					}
				 }
			 }
 	private: System::Void money_input_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
			 {
				 if( e->KeyCode == Keys::Enter )
				 {
					player_betting->Text = money_input->Text;
					PlayerBetting  = Convert::ToInt16(player_betting->Text);

					int temp = PlayerMoney - PlayerBetting;
					player_money->Text = temp.ToString();
				 }
			 }
 	private: System::Void money_input_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
			 {
				 if( !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 )
				 {
					e->Handled = true;
				 }
			 }
	private: System::Void money_input_TextChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 int num = Convert::ToInt32(money_input->Text);
				 if( num > PlayerMoney ) money_input->Text = PlayerMoney.ToString();
			 }



};//end class Form1
}//end namespace ThePocker 

