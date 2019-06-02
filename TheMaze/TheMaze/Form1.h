#pragma once


namespace TheMaze 
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
			srand((unsigned int)time(NULL));
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
	private: System::Windows::Forms::Panel^  game_section;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  maze_exit_label;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  maze_start_label;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  maze_size_label;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  select_file_button;
	private: System::Windows::Forms::TextBox^  file_path_textBox;
	private: System::Windows::Forms::Label^  maze_name_label;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  restart_game_button;
	private: System::Windows::Forms::Button^  pause_game_button;
	private: System::Windows::Forms::Button^  start_game_button;
	private: System::Windows::Forms::Button^  create_terrain_button;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  the_end_label;
	private: System::Windows::Forms::NumericUpDown^  search_speed;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  mouse_direction_label;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  mouse_position_label;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  mouse_power_label;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  health_bar;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::ImageList^  imageList2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		Maze^ maze;
		Mouse^ mouse;
		Graphics^ mygraphics;
		Graphics^ gamegraphics;
		SolidBrush^ myBrush;
		OpenFileDialog^ openFileDialog;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->game_section = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->create_terrain_button = (gcnew System::Windows::Forms::Button());
			this->maze_exit_label = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maze_start_label = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->maze_size_label = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->select_file_button = (gcnew System::Windows::Forms::Button());
			this->file_path_textBox = (gcnew System::Windows::Forms::TextBox());
			this->maze_name_label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->restart_game_button = (gcnew System::Windows::Forms::Button());
			this->pause_game_button = (gcnew System::Windows::Forms::Button());
			this->start_game_button = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->the_end_label = (gcnew System::Windows::Forms::Label());
			this->search_speed = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->mouse_direction_label = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->mouse_position_label = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->mouse_power_label = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->health_bar = (gcnew System::Windows::Forms::Panel());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->imageList2 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->search_speed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// game_section
			// 
			this->game_section->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->game_section->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->game_section->Location = System::Drawing::Point(10, 10);
			this->game_section->Name = L"game_section";
			this->game_section->Size = System::Drawing::Size(1200, 480);
			this->game_section->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->create_terrain_button);
			this->panel1->Controls->Add(this->maze_exit_label);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->maze_start_label);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->maze_size_label);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->select_file_button);
			this->panel1->Controls->Add(this->file_path_textBox);
			this->panel1->Controls->Add(this->maze_name_label);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(11, 553);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(348, 178);
			this->panel1->TabIndex = 2;
			// 
			// create_terrain_button
			// 
			this->create_terrain_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->create_terrain_button->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->create_terrain_button->Location = System::Drawing::Point(122, 43);
			this->create_terrain_button->Name = L"create_terrain_button";
			this->create_terrain_button->Size = System::Drawing::Size(86, 25);
			this->create_terrain_button->TabIndex = 20;
			this->create_terrain_button->Text = L"系統生成";
			this->create_terrain_button->UseVisualStyleBackColor = true;
			this->create_terrain_button->Click += gcnew System::EventHandler(this, &Form1::create_terrain_button_Click);
			// 
			// maze_exit_label
			// 
			this->maze_exit_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->maze_exit_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->maze_exit_label->Location = System::Drawing::Point(234, 146);
			this->maze_exit_label->Name = L"maze_exit_label";
			this->maze_exit_label->Size = System::Drawing::Size(109, 23);
			this->maze_exit_label->TabIndex = 19;
			this->maze_exit_label->Text = L"(  \?\?   , \?\?    )";
			this->maze_exit_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label6->Location = System::Drawing::Point(181, 146);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(47, 23);
			this->label6->TabIndex = 18;
			this->label6->Text = L"出口:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// maze_start_label
			// 
			this->maze_start_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->maze_start_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->maze_start_label->Location = System::Drawing::Point(63, 146);
			this->maze_start_label->Name = L"maze_start_label";
			this->maze_start_label->Size = System::Drawing::Size(112, 23);
			this->maze_start_label->TabIndex = 17;
			this->maze_start_label->Text = L"(  \?\?   , \?\?    )";
			this->maze_start_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label3->Location = System::Drawing::Point(10, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 23);
			this->label3->TabIndex = 16;
			this->label3->Text = L"入口:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// maze_size_label
			// 
			this->maze_size_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->maze_size_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->maze_size_label->Location = System::Drawing::Point(94, 114);
			this->maze_size_label->Name = L"maze_size_label";
			this->maze_size_label->Size = System::Drawing::Size(81, 23);
			this->maze_size_label->TabIndex = 15;
			this->maze_size_label->Text = L"\?\? x \?\?";
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label4->Location = System::Drawing::Point(10, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 23);
			this->label4->TabIndex = 14;
			this->label4->Text = L"迷宮大小:";
			// 
			// select_file_button
			// 
			this->select_file_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->select_file_button->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->select_file_button->Location = System::Drawing::Point(14, 43);
			this->select_file_button->Name = L"select_file_button";
			this->select_file_button->Size = System::Drawing::Size(86, 25);
			this->select_file_button->TabIndex = 13;
			this->select_file_button->Text = L"選擇檔案";
			this->select_file_button->UseVisualStyleBackColor = true;
			this->select_file_button->Click += gcnew System::EventHandler(this, &Form1::select_file_button_Click);
			// 
			// file_path_textBox
			// 
			this->file_path_textBox->Enabled = false;
			this->file_path_textBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->file_path_textBox->Location = System::Drawing::Point(14, 12);
			this->file_path_textBox->Name = L"file_path_textBox";
			this->file_path_textBox->ReadOnly = true;
			this->file_path_textBox->Size = System::Drawing::Size(318, 25);
			this->file_path_textBox->TabIndex = 12;
			this->file_path_textBox->Text = L"請先選擇檔案";
			// 
			// maze_name_label
			// 
			this->maze_name_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->maze_name_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->maze_name_label->Location = System::Drawing::Point(94, 82);
			this->maze_name_label->Name = L"maze_name_label";
			this->maze_name_label->Size = System::Drawing::Size(134, 23);
			this->maze_name_label->TabIndex = 11;
			this->maze_name_label->Text = L"unknow";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label1->Location = System::Drawing::Point(10, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 23);
			this->label1->TabIndex = 10;
			this->label1->Text = L"迷宮名稱:";
			// 
			// restart_game_button
			// 
			this->restart_game_button->Enabled = false;
			this->restart_game_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->restart_game_button->Location = System::Drawing::Point(258, 500);
			this->restart_game_button->Name = L"restart_game_button";
			this->restart_game_button->Size = System::Drawing::Size(88, 34);
			this->restart_game_button->TabIndex = 11;
			this->restart_game_button->Text = L"重新開始";
			this->restart_game_button->UseVisualStyleBackColor = true;
			this->restart_game_button->Click += gcnew System::EventHandler(this, &Form1::restart_game_button_Click);
			// 
			// pause_game_button
			// 
			this->pause_game_button->Enabled = false;
			this->pause_game_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->pause_game_button->Location = System::Drawing::Point(134, 500);
			this->pause_game_button->Name = L"pause_game_button";
			this->pause_game_button->Size = System::Drawing::Size(88, 34);
			this->pause_game_button->TabIndex = 10;
			this->pause_game_button->Text = L"暫停遊戲";
			this->pause_game_button->UseVisualStyleBackColor = true;
			this->pause_game_button->Click += gcnew System::EventHandler(this, &Form1::pause_game_button_Click);
			// 
			// start_game_button
			// 
			this->start_game_button->Enabled = false;
			this->start_game_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->start_game_button->Location = System::Drawing::Point(10, 500);
			this->start_game_button->Name = L"start_game_button";
			this->start_game_button->Size = System::Drawing::Size(88, 34);
			this->start_game_button->TabIndex = 9;
			this->start_game_button->Text = L"開始遊戲";
			this->start_game_button->UseVisualStyleBackColor = true;
			this->start_game_button->Click += gcnew System::EventHandler(this, &Form1::start_game_button_Click);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->the_end_label);
			this->panel2->Controls->Add(this->search_speed);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->mouse_direction_label);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->mouse_position_label);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->mouse_power_label);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->health_bar);
			this->panel2->Location = System::Drawing::Point(374, 500);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(836, 231);
			this->panel2->TabIndex = 12;
			// 
			// the_end_label
			// 
			this->the_end_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->the_end_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->the_end_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->the_end_label->Location = System::Drawing::Point(16, 167);
			this->the_end_label->Name = L"the_end_label";
			this->the_end_label->Size = System::Drawing::Size(200, 39);
			this->the_end_label->TabIndex = 22;
			this->the_end_label->Text = L"出口為: (\?\? ,\?\?)";
			this->the_end_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->the_end_label->Visible = false;
			// 
			// search_speed
			// 
			this->search_speed->Enabled = false;
			this->search_speed->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->search_speed->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->search_speed->Location = System::Drawing::Point(96, 120);
			this->search_speed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->search_speed->Name = L"search_speed";
			this->search_speed->Size = System::Drawing::Size(63, 25);
			this->search_speed->TabIndex = 21;
			this->search_speed->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->search_speed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->search_speed->ValueChanged += gcnew System::EventHandler(this, &Form1::search_speed_ValueChanged);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label2->Location = System::Drawing::Point(165, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 23);
			this->label2->TabIndex = 20;
			this->label2->Text = L"次/秒";
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label9->Location = System::Drawing::Point(17, 122);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(78, 23);
			this->label9->TabIndex = 19;
			this->label9->Text = L"搜索速度:";
			// 
			// mouse_direction_label
			// 
			this->mouse_direction_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->mouse_direction_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->mouse_direction_label->Location = System::Drawing::Point(101, 84);
			this->mouse_direction_label->Name = L"mouse_direction_label";
			this->mouse_direction_label->Size = System::Drawing::Size(111, 23);
			this->mouse_direction_label->TabIndex = 18;
			this->mouse_direction_label->Text = L"unknown";
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label7->Location = System::Drawing::Point(17, 84);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(78, 23);
			this->label7->TabIndex = 17;
			this->label7->Text = L"目前方向:";
			// 
			// mouse_position_label
			// 
			this->mouse_position_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->mouse_position_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->mouse_position_label->Location = System::Drawing::Point(101, 52);
			this->mouse_position_label->Name = L"mouse_position_label";
			this->mouse_position_label->Size = System::Drawing::Size(111, 23);
			this->mouse_position_label->TabIndex = 16;
			this->mouse_position_label->Text = L"(  \?\?   , \?\?    )";
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label5->Location = System::Drawing::Point(17, 52);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(78, 23);
			this->label5->TabIndex = 15;
			this->label5->Text = L"目前位置:";
			// 
			// label8
			// 
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label8->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label8->Location = System::Drawing::Point(12, 12);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(167, 30);
			this->label8->TabIndex = 13;
			this->label8->Text = L"老鼠123";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// mouse_power_label
			// 
			this->mouse_power_label->BackColor = System::Drawing::Color::Transparent;
			this->mouse_power_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->mouse_power_label->Location = System::Drawing::Point(713, 12);
			this->mouse_power_label->Margin = System::Windows::Forms::Padding(0);
			this->mouse_power_label->Name = L"mouse_power_label";
			this->mouse_power_label->Size = System::Drawing::Size(103, 30);
			this->mouse_power_label->TabIndex = 12;
			this->mouse_power_label->Text = L"xxx / xxx";
			this->mouse_power_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(182, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(30, 30);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// health_bar
			// 
			this->health_bar->BackColor = System::Drawing::Color::White;
			this->health_bar->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->health_bar->Location = System::Drawing::Point(212, 12);
			this->health_bar->Name = L"health_bar";
			this->health_bar->Size = System::Drawing::Size(498, 30);
			this->health_bar->TabIndex = 10;
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"add.png");
			this->imageList1->Images->SetKeyName(1, L"minus.png");
			this->imageList1->Images->SetKeyName(2, L"multiply.png");
			this->imageList1->Images->SetKeyName(3, L"divide.png");
			this->imageList1->Images->SetKeyName(4, L"money3.png");
			this->imageList1->Images->SetKeyName(5, L"exit2.png");
			this->imageList1->Images->SetKeyName(6, L"brick.png");
			// 
			// imageList2
			// 
			this->imageList2->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"imageList2.ImageStream")));
			this->imageList2->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList2->Images->SetKeyName(0, L"mouse0.png");
			this->imageList2->Images->SetKeyName(1, L"mouse1.png");
			this->imageList2->Images->SetKeyName(2, L"mouse2.png");
			this->imageList2->Images->SetKeyName(3, L"mouse3.png");
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1224, 741);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->restart_game_button);
			this->Controls->Add(this->pause_game_button);
			this->Controls->Add(this->start_game_button);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->game_section);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"老鼠走迷宮";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->search_speed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				mygraphics   = health_bar->CreateGraphics();
				gamegraphics = game_section->CreateGraphics();
				myBrush	     = gcnew SolidBrush(Color::Green);

				openFileDialog		   = gcnew OpenFileDialog();
				openFileDialog->Filter = "txt files (*.txt)|*.txt";
			 }
	private: System::Void select_file_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK )
				 {	 
					 if( createMazeMap(openFileDialog->FileName) ) 
					  {	
						displayMazeData(openFileDialog->FileName);

						createMouse();
						displayMouseData();

						startButtonStatus();
					 }
					 else MessageBox::Show("沒有入口!!");			 
				 }
			 }
	private: System::Void create_terrain_button_Click(System::Object^  sender, System::EventArgs^  e)//?Q?QA?D?
			 {
				 createMazeMap(Maze::createMap(24,60));
				 displayMazeData("系統生成");

				 createMouse();
				 displayMouseData();

				 startButtonStatus();
			 }
	private: System::Void restart_game_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {		 
				 reStart();
				 startButtonStatus();
			 }
	private: System::Void start_game_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 start_game_button->Enabled = false;
				 timer1->Interval = 1000 / Convert::ToInt16(search_speed->Value);//50
				 timer1->Enabled  = true;

				 pause_game_button->Enabled	  = true;
				 restart_game_button->Enabled = true;
			 }
	private: System::Void pause_game_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( timer1->Enabled )
				 {
					pause_game_button->Text = "繼續遊戲";
					timer1->Enabled		  = false;
					search_speed->Enabled = false;
				 }
				 else
				 {
					pause_game_button->Text = "暫停遊戲";
					timer1->Enabled		  = true;
					search_speed->Enabled = true;
				 }
			 }
	private: System::Void search_speed_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 timer1->Interval = 1000 / Convert::ToInt16(search_speed->Value);
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(mouse->move())
				 {
					 displayMousePos();
					 displayMousePath();
					 displayMouseHealth();
				 }
				 if( !theEnd() )
				 {
					 mouse->findDirection();
					 displayMouseDir();		
				 }
			 }
    /*=========================================函式============================================*/

	private: bool createMazeMap(String^% file_name)
			 {
				maze = gcnew Maze(file_name);

				if( maze->getEntrance() == nullptr ) return false;
				else							   
				{
					createMapOnBoard();
					return true;
				}
			 }
	private: void createMazeMap(Map^% map)
			 {
				maze = gcnew Maze(map);
				createMapOnBoard();
			 }
	private: void createMouse()
			 {
				mouse = gcnew Mouse( maze );
				createMouseOnBoard();
			 }
    /*=========================================介面============================================*/

	private: bool theEnd()
			 {
				bool end = false;
				if( end = (mouse->getCurrentGrid() == nullptr) )
				{
					the_end_label->Text = "迷宮沒有出口QQ";
				}
				else if(  end = (maze->getMazeMap()->getPosData(mouse->getCurrentGrid()->getPosition()) == Item::exitSymbol) )
				{
					maze->getMazeMap()->setMap(mouse->getCurrentGrid()->getPosition() ,Item::walkedMark);//設定出口為"走過"
					the_end_label->Text = "出口" + mouse->getCurrentGrid()->getPosition()->ToString();
				}
				else if( end =  (mouse->getPower() == 0)  )
				{
					the_end_label->Text = "老鼠已死亡!!!";
				}	
				if( end )
				{
					the_end_label->Visible	   = true;
					timer1->Enabled			   = false;//遊戲結束
					pause_game_button->Enabled = false;
				}
				return end;
			 }
	private: void reStart()
			 { 
				 gamegraphics->Clear(Color::White);
				 for(int i = 0 ; i < maze->getMazeMap()->getRow() ; i++ )
				 {
					for(int j = 0 ; j < maze->getMazeMap()->getColumn() ; j++ )
					{
						if( maze->getOriginalMap()->getPosData(i ,j) != Item::pathSymbol &&
							maze->getOriginalMap()->getPosData(i ,j) != Item::wallSymbol )
						{
							if( maze->getMazeMap()->getPosData(i ,j) != maze->getOriginalMap()->getPosData(i ,j) )
							{
								game_section->Controls->Add( AddNewPictureBoxOnMazeMap(i ,j ,i + " " + j) );
							}
						}
					}
				 }
				 maze->reSetMazeMap();
				 
				 mouse = gcnew Mouse( maze );
				 displayMouseData();
			 }
	private: void startButtonStatus() 
			  {
			     start_game_button->Enabled   = false;
				 pause_game_button->Text      = "暫停遊戲";
				 pause_game_button->Enabled   = false;
				 restart_game_button->Enabled = false;
				 search_speed->Enabled		  = true;
				 search_speed->Value          = 20;
				 timer1->Enabled			  = false;
				 the_end_label->Visible		  = false;
				 start_game_button->Enabled   = true;///
			  }
	/*----------------------------------------顯示所有數值--------------------------------*/
	private: void displayMazeData(String^ path)
			 {
				file_path_textBox->Text= path;
				maze_name_label->Text  = maze->getMazeName();			
				maze_size_label->Text  = maze->getMazeMap()->getRow() + " x " + maze->getMazeMap()->getColumn();
				maze_start_label->Text = maze->getEntrance()->ToString();
				maze_exit_label->Text  = (maze->getExit() != nullptr) ? maze->getExit()->ToString() : "unknown";		
			 }
	private: void displayMouseData()
			 {
				 displayMousePos();
				 displayMouseDir();
				 displayMouseHealth();
			 }
	/*----------------------------------------老鼠的狀態----------------------------------*/
	private: void displayMousePos()
			 {
				int i = mouse->getCurrentGrid()->getPosition()->getI();
				int j = mouse->getCurrentGrid()->getPosition()->getJ();

				if(maze->getMazeMap()->getPosData(i ,j) != Item::pathSymbol &&
				   maze->getMazeMap()->getPosData(i ,j) != Item::walkedMark )
				{
					PictureBox^ PowerPbox = (PictureBox^)game_section->Controls->Find( i + " " + j ,false)[0];
					game_section->Controls->Remove(PowerPbox);
				}
			    mouse_position_label->Text = mouse->getCurrentGrid()->getPosition()->ToString();
				
				PictureBox^ pbox = (PictureBox^)game_section->Controls->Find("mouse_image",false)[0];
				pbox->Location = Drawing::Point(j * 20 ,i * 20);
			 }
	private: void displayMouseDir()
			 {
				mouse_direction_label->Text= mouse->getCurrentGrid()->getDirName();

				PictureBox^ pbox = (PictureBox^)game_section->Controls->Find("mouse_image",false)[0];
				pbox->Image = imageList2->Images[mouse->getCurrentGrid()->getCurrentDir()];		
			 }
	private: void displayMouseHealth()//drawHealthBar()
			 {
				mouse_power_label->Text = mouse->getPower().ToString() + " / " + Mouse::MAXPOWER; 

				mygraphics->Clear(Color::White);
				float power = (float)mouse->getPower() / Mouse::MAXPOWER;

				if( power > (1/2.0) )	   myBrush->Color = Color::Green;
				else if( power > (1/4.0) ) myBrush->Color = Color::Yellow;
				else if( power > (1/8.0) ) myBrush->Color = Color::Orange;
				else					   myBrush->Color = Color::Red;

				mygraphics->FillRectangle(myBrush ,0.0 ,0.0 ,health_bar->Width * power ,(float)health_bar->Height );
			 }
	private: void displayMousePath()//老鼠的行蹤 放到地圖上
			 {				 
				if( mouse->getLastPosDead() == true ) myBrush->Color = Color::LightGray;
				else								  myBrush->Color = Color::Orange;

				gamegraphics->FillRectangle(myBrush ,mouse->getLastPos()->getJ() * 20 + 3
												    ,mouse->getLastPos()->getI() * 20 + 3
													,14 ,14 );

			 }
	/*----------------------------------------創造出地圖,老鼠-----------------------------*/
	private: void createMapOnBoard()
			 {
				 gamegraphics->Clear(Color::White);
				 game_section->Controls->Clear();//先將地圖清空
				 for(int i = 0 ; i < maze->getMazeMap()->getRow() ; i++ )
				 {
					for(int j = 0 ; j < maze->getMazeMap()->getColumn() ; j++ )
					{
						if( maze->getMazeMap()->getPosData(i ,j) != '0' )
						{
							game_section->Controls->Add( AddNewPictureBoxOnMazeMap(i ,j ,i + " " + j) );
						}
					}
				}
			 }
	private: void createMouseOnBoard()//暫時
			 {
				PictureBox^ pictureBox_temp =  AddNewPictureBoxOnMazeMap(mouse->getCurrentGrid()->getPosition()->getI() ,
																		 mouse->getCurrentGrid()->getPosition()->getJ() , 
																		 "mouse_image");
			    pictureBox_temp->Image = imageList2->Images[mouse->getCurrentGrid()->getCurrentDir()];
				game_section->Controls->Add( pictureBox_temp );
			 }
 	private: PictureBox^ AddNewPictureBoxOnMazeMap(int i ,int j ,String^ name )
			 {
				 PictureBox^ pictureBox_temp  = gcnew PictureBox();
					
				 pictureBox_temp->Location = Drawing::Point(j * 20 ,i * 20);
				 pictureBox_temp->Size	   = Drawing::Size(20, 20);
				 pictureBox_temp->SizeMode = PictureBoxSizeMode::StretchImage;
				 pictureBox_temp->Name     = name;
				 pictureBox_temp->Image    = getItemImage(maze->getOriginalMap()->getPosData(i,j));
					 			
				 return pictureBox_temp;
			 }
	private: Image^ getItemImage(char item)//對應到 imageList1 的圖片
			 {
				 for(int i = 0 ; i < Item::energySymbol->Length ; i++ )
				{
					if( item == Item::energySymbol[i] )
					{
						return imageList1->Images[i];
					}
				}
				 if( item == Item::exitSymbol )
				{
					return imageList1->Images[5];
				}
				 else if( item == Item::wallSymbol  )
				{
					return imageList1->Images[6];
				}
				return nullptr;//找不到 (設定圖片時不會給圖片)
			 }
	};//end of public ref class Form1
}//end of namespace TheMaze

