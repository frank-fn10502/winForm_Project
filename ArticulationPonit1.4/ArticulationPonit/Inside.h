#pragma once
#include "Graph.h"
#include "DFSTree.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



namespace ArticulationPonit 
{
	delegate void DisplayArtPointEntity(LinkList<int>^);
	/// <summary>
	/// Inside 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class Inside : public System::Windows::Forms::Form
	{
	public:
		Inside(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}
		Inside(Graph^% graph ,DisplayArtPointEntity^ displayArtPointEntity)
		{
			InitializeComponent();

			Maingraph = graph;
			this->displayArtPointEntity = displayArtPointEntity;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Inside()
		{
			if (components)
			{				
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  canvasTree_panel;
	protected: 

	protected: 

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::Button^  calculate_button;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  backStart_button;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::CheckBox^  viewDetail_checkBox;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  atartPointMin_button;
	private: System::Windows::Forms::Button^  atartPointMax_button;

	private: System::Windows::Forms::TextBox^  startPoint_textBox;
	protected: 
	private: System::ComponentModel::Container ^components;	

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>	
		Graph^ Maingraph;
		DFSTree^ dfsTree;
		DisplayArtPointEntity^ displayArtPointEntity;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Inside::typeid));
			this->canvasTree_panel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->calculate_button = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->viewDetail_checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->backStart_button = (gcnew System::Windows::Forms::Button());
			this->atartPointMin_button = (gcnew System::Windows::Forms::Button());
			this->atartPointMax_button = (gcnew System::Windows::Forms::Button());
			this->startPoint_textBox = (gcnew System::Windows::Forms::TextBox());
			this->canvasTree_panel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// canvasTree_panel
			// 
			this->canvasTree_panel->AutoScroll = true;
			this->canvasTree_panel->BackColor = System::Drawing::Color::White;
			this->canvasTree_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->canvasTree_panel->Controls->Add(this->panel2);
			this->canvasTree_panel->Controls->Add(this->label1);
			this->canvasTree_panel->Location = System::Drawing::Point(10, 49);
			this->canvasTree_panel->Name = L"canvasTree_panel";
			this->canvasTree_panel->Size = System::Drawing::Size(421, 485);
			this->canvasTree_panel->TabIndex = 10;
			this->canvasTree_panel->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Inside::canvasTree_panel_Scroll);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label18);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Location = System::Drawing::Point(256, 10);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(40, 20);
			this->panel2->TabIndex = 24;
			this->panel2->Visible = false;
			// 
			// label18
			// 
			this->label18->Font = (gcnew System::Drawing::Font(L"細明體", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label18->Location = System::Drawing::Point(15, 0);
			this->label18->Margin = System::Windows::Forms::Padding(0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(8, 20);
			this->label18->TabIndex = 25;
			this->label18->Text = L"/";
			this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"細明體", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label13->ForeColor = System::Drawing::Color::Fuchsia;
			this->label13->Location = System::Drawing::Point(0, 0);
			this->label13->Margin = System::Windows::Forms::Padding(0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(20, 20);
			this->label13->TabIndex = 23;
			this->label13->Text = L"10";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->Font = (gcnew System::Drawing::Font(L"細明體", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label12->Location = System::Drawing::Point(20, 0);
			this->label12->Margin = System::Windows::Forms::Padding(0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(20, 20);
			this->label12->TabIndex = 22;
			this->label12->Text = L"20";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(299, 10);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"10";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Visible = false;
			// 
			// calculate_button
			// 
			this->calculate_button->BackColor = System::Drawing::Color::Silver;
			this->calculate_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->calculate_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->calculate_button->Location = System::Drawing::Point(133, 5);
			this->calculate_button->Name = L"calculate_button";
			this->calculate_button->Size = System::Drawing::Size(62, 25);
			this->calculate_button->TabIndex = 14;
			this->calculate_button->Text = L"計算";
			this->calculate_button->UseVisualStyleBackColor = false;
			this->calculate_button->Click += gcnew System::EventHandler(this, &Inside::calculate_button_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(10, 7);
			this->label2->Margin = System::Windows::Forms::Padding(0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 23);
			this->label2->TabIndex = 11;
			this->label2->Text = L"起點:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->viewDetail_checkBox);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->label17);
			this->panel1->Controls->Add(this->label15);
			this->panel1->Controls->Add(this->backStart_button);
			this->panel1->Controls->Add(this->atartPointMin_button);
			this->panel1->Controls->Add(this->calculate_button);
			this->panel1->Controls->Add(this->atartPointMax_button);
			this->panel1->Controls->Add(this->startPoint_textBox);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(10, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(421, 41);
			this->panel1->TabIndex = 14;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(375, 8);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(25, 25);
			this->pictureBox1->TabIndex = 25;
			this->pictureBox1->TabStop = false;
			// 
			// viewDetail_checkBox
			// 
			this->viewDetail_checkBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->viewDetail_checkBox->Location = System::Drawing::Point(360, 8);
			this->viewDetail_checkBox->Name = L"viewDetail_checkBox";
			this->viewDetail_checkBox->Size = System::Drawing::Size(25, 25);
			this->viewDetail_checkBox->TabIndex = 28;
			this->viewDetail_checkBox->UseVisualStyleBackColor = true;
			this->viewDetail_checkBox->CheckedChanged += gcnew System::EventHandler(this, &Inside::viewDetail_checkBox_CheckedChanged);
			// 
			// label16
			// 
			this->label16->BackColor = System::Drawing::Color::Black;
			this->label16->Font = (gcnew System::Drawing::Font(L"細明體", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label16->ForeColor = System::Drawing::Color::White;
			this->label16->Location = System::Drawing::Point(312, 22);
			this->label16->Margin = System::Windows::Forms::Padding(0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(12, 12);
			this->label16->TabIndex = 26;
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label14->Font = (gcnew System::Drawing::Font(L"細明體", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label14->ForeColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(312, 3);
			this->label14->Margin = System::Windows::Forms::Padding(0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(12, 12);
			this->label14->TabIndex = 24;
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label17
			// 
			this->label17->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label17->Location = System::Drawing::Point(311, 17);
			this->label17->Margin = System::Windows::Forms::Padding(0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(64, 20);
			this->label17->TabIndex = 27;
			this->label17->Text = L"Dfn";
			this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label15
			// 
			this->label15->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label15->Location = System::Drawing::Point(311, -2);
			this->label15->Margin = System::Windows::Forms::Padding(0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(64, 20);
			this->label15->TabIndex = 25;
			this->label15->Text = L"Low";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// backStart_button
			// 
			this->backStart_button->BackColor = System::Drawing::Color::Silver;
			this->backStart_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"backStart_button.BackgroundImage")));
			this->backStart_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->backStart_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->backStart_button->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->backStart_button->Location = System::Drawing::Point(201, 5);
			this->backStart_button->Name = L"backStart_button";
			this->backStart_button->Size = System::Drawing::Size(25, 25);
			this->backStart_button->TabIndex = 21;
			this->backStart_button->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->backStart_button->UseVisualStyleBackColor = false;
			this->backStart_button->Click += gcnew System::EventHandler(this, &Inside::backStart_button_Click);
			// 
			// atartPointMin_button
			// 
			this->atartPointMin_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"atartPointMin_button.BackgroundImage")));
			this->atartPointMin_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->atartPointMin_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->atartPointMin_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->atartPointMin_button->Location = System::Drawing::Point(44, 7);
			this->atartPointMin_button->Name = L"atartPointMin_button";
			this->atartPointMin_button->Size = System::Drawing::Size(20, 23);
			this->atartPointMin_button->TabIndex = 20;
			this->atartPointMin_button->TabStop = false;
			this->atartPointMin_button->UseVisualStyleBackColor = true;
			this->atartPointMin_button->Click += gcnew System::EventHandler(this, &Inside::atartPointMin_button_Click);
			// 
			// atartPointMax_button
			// 
			this->atartPointMax_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"atartPointMax_button.BackgroundImage")));
			this->atartPointMax_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->atartPointMax_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->atartPointMax_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->atartPointMax_button->Location = System::Drawing::Point(98, 7);
			this->atartPointMax_button->Name = L"atartPointMax_button";
			this->atartPointMax_button->Size = System::Drawing::Size(20, 23);
			this->atartPointMax_button->TabIndex = 19;
			this->atartPointMax_button->TabStop = false;
			this->atartPointMax_button->UseVisualStyleBackColor = true;
			this->atartPointMax_button->Click += gcnew System::EventHandler(this, &Inside::atartPointMax_button_Click);
			// 
			// startPoint_textBox
			// 
			this->startPoint_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->startPoint_textBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->startPoint_textBox->Location = System::Drawing::Point(61, 7);
			this->startPoint_textBox->Name = L"startPoint_textBox";
			this->startPoint_textBox->Size = System::Drawing::Size(40, 23);
			this->startPoint_textBox->TabIndex = 18;
			this->startPoint_textBox->Text = L"0";
			this->startPoint_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->startPoint_textBox->TextChanged += gcnew System::EventHandler(this, &Inside::startPoint_textBox_TextChanged);
			this->startPoint_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Inside::startPoint_textBox_KeyPress);
			// 
			// Inside
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(443, 546);
			this->Controls->Add(this->canvasTree_panel);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Inside";
			this->Text = L"計算細節";
			this->Load += gcnew System::EventHandler(this, &Inside::Inside_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Inside::Inside_FormClosing);
			this->canvasTree_panel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Inside_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 dfsTree = gcnew DFSTree(canvasTree_panel ,Maingraph);

				 viewDetail_checkBox->Checked = true;
			 }
	private: System::Void Inside_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
			 {
				 dfsTree->clearAllData();
			 }
	private: System::Void canvasTree_panel_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) 
			 {
				 dfsTree->getEdgeEntity()->repaint();
			 }
	private: System::Void calculate_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 calculate_button->Enabled = false;
				 backStart_button->Enabled = true;
				 dfsTree->clearAllData();

				 int num = Convert::ToInt32(startPoint_textBox->Text);
				 displayArtPointEntity( dfsTree->calulateArtPoint(num) );

				 dfsTree->displayAllData();
			 }
	private: System::Void backStart_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 dfsTree->beginningStatus();
			 }
	private: System::Void viewDetail_checkBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 dfsTree->setDetailVisible(viewDetail_checkBox->Checked);
				 dfsTree->getEdgeEntity()->repaint();
			 }
	public: void reSetDFSTree()
			 {
				 startPoint_textBox->Text = "0";
				 dfsTree->clearAllData();
				 calculate_button->Enabled = true;
				 backStart_button->Enabled = false;
			 }
	/*===================================設定起始點==========================================================*/

	private: System::Void atartPointMin_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 startPoint_textBox->Text = "0";
			 }
	private: System::Void startPoint_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(startPoint_textBox->Text != "")
				 {
					 if(Convert::ToInt32(startPoint_textBox->Text) > (VertexEntity::getVertexNum()-1))
					 {
						startPoint_textBox->Text = (VertexEntity::getVertexNum()-1).ToString();
					 }
					 else if(Convert::ToInt32(startPoint_textBox->Text)  < 0)
					 {
						 startPoint_textBox->Text = "0";
					 }
					 else startPoint_textBox->Text = Convert::ToInt32(startPoint_textBox->Text).ToString();

					 calculate_button->Enabled = true;/////
				 }
			 }
	private: System::Void startPoint_textBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
			 {
				 if( !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 )
				 {
					e->Handled = true;
				 }
			 }
	private: System::Void atartPointMax_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				startPoint_textBox->Text = (VertexEntity::getVertexNum()-1).ToString();
			 }

	};
}
