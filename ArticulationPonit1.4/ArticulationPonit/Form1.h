#pragma once
#include "ReadFile.h"/////
#include "Graph.h"
#include "DFSTree.h"
#include "Inside.h"


namespace ArticulationPonit 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;//StreamReader ,StreamWriter

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
	private: System::Windows::Forms::Button^  calculate_button;
	private: System::Windows::Forms::Label^  artNum_label;
	private: System::Windows::Forms::Button^  displayCircle_button;

	private: System::Windows::Forms::Button^  displayRetangle_button;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  artPoints_panel;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  canvas_panel;
	private: System::Windows::Forms::TextBox^  filePath_textBox;
	private: System::Windows::Forms::Button^  selectFile_button;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  detail_button;

	private: System::ComponentModel::Container ^components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>	
		Graph^ graph;
		Inside^ detailForm;
		bool calculateOnce;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->calculate_button = (gcnew System::Windows::Forms::Button());
			this->artNum_label = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->artPoints_panel = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->canvas_panel = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->filePath_textBox = (gcnew System::Windows::Forms::TextBox());
			this->selectFile_button = (gcnew System::Windows::Forms::Button());
			this->displayCircle_button = (gcnew System::Windows::Forms::Button());
			this->detail_button = (gcnew System::Windows::Forms::Button());
			this->displayRetangle_button = (gcnew System::Windows::Forms::Button());
			this->artPoints_panel->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->canvas_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// calculate_button
			// 
			this->calculate_button->BackColor = System::Drawing::Color::Silver;
			this->calculate_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->calculate_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->calculate_button->ForeColor = System::Drawing::Color::Black;
			this->calculate_button->Location = System::Drawing::Point(448, 12);
			this->calculate_button->Name = L"calculate_button";
			this->calculate_button->Size = System::Drawing::Size(60, 30);
			this->calculate_button->TabIndex = 12;
			this->calculate_button->Text = L"計算";
			this->calculate_button->UseVisualStyleBackColor = false;
			this->calculate_button->Click += gcnew System::EventHandler(this, &Form1::calculate_button_Click);
			// 
			// artNum_label
			// 
			this->artNum_label->BackColor = System::Drawing::Color::Transparent;
			this->artNum_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->artNum_label->Location = System::Drawing::Point(500, 54);
			this->artNum_label->Name = L"artNum_label";
			this->artNum_label->Size = System::Drawing::Size(58, 25);
			this->artNum_label->TabIndex = 11;
			this->artNum_label->Text = L"xx個";
			this->artNum_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(445, 54);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 25);
			this->label5->TabIndex = 10;
			this->label5->Text = L"關節點: ";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// artPoints_panel
			// 
			this->artPoints_panel->AutoScroll = true;
			this->artPoints_panel->BackColor = System::Drawing::Color::Transparent;
			this->artPoints_panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->artPoints_panel->Controls->Add(this->panel4);
			this->artPoints_panel->Controls->Add(this->panel3);
			this->artPoints_panel->Location = System::Drawing::Point(448, 80);
			this->artPoints_panel->Name = L"artPoints_panel";
			this->artPoints_panel->Size = System::Drawing::Size(113, 300);
			this->artPoints_panel->TabIndex = 9;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Controls->Add(this->label3);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Location = System::Drawing::Point(0, 30);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(109, 30);
			this->panel4->TabIndex = 5;
			this->panel4->Visible = false;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(50, 1);
			this->label3->Margin = System::Windows::Forms::Padding(0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"20";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(0, 1);
			this->label2->Margin = System::Windows::Forms::Padding(0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"100.";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(109, 30);
			this->panel3->TabIndex = 4;
			this->panel3->Visible = false;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(50, 1);
			this->label4->Margin = System::Windows::Forms::Padding(0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 25);
			this->label4->TabIndex = 7;
			this->label4->Text = L"1";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(0, 1);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"1.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// canvas_panel
			// 
			this->canvas_panel->AutoScroll = true;
			this->canvas_panel->BackColor = System::Drawing::Color::White;
			this->canvas_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->canvas_panel->Controls->Add(this->label6);
			this->canvas_panel->Controls->Add(this->richTextBox1);
			this->canvas_panel->Location = System::Drawing::Point(11, 41);
			this->canvas_panel->Name = L"canvas_panel";
			this->canvas_panel->Size = System::Drawing::Size(420, 339);
			this->canvas_panel->TabIndex = 8;
			this->canvas_panel->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::canvas_panel_Scroll);
			// 
			// label6
			// 
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(234, 26);
			this->label6->Margin = System::Windows::Forms::Padding(0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(26, 20);
			this->label6->TabIndex = 1;
			this->label6->Text = L"10";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label6->Visible = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(84, 92);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(225, 203);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->Visible = false;
			// 
			// filePath_textBox
			// 
			this->filePath_textBox->BackColor = System::Drawing::Color::Silver;
			this->filePath_textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->filePath_textBox->Enabled = false;
			this->filePath_textBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->filePath_textBox->Location = System::Drawing::Point(11, 12);
			this->filePath_textBox->Name = L"filePath_textBox";
			this->filePath_textBox->ReadOnly = true;
			this->filePath_textBox->Size = System::Drawing::Size(327, 23);
			this->filePath_textBox->TabIndex = 13;
			this->filePath_textBox->Text = L"請選擇檔案...";
			// 
			// selectFile_button
			// 
			this->selectFile_button->BackColor = System::Drawing::Color::Silver;
			this->selectFile_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"selectFile_button.BackgroundImage")));
			this->selectFile_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->selectFile_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->selectFile_button->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->selectFile_button->Location = System::Drawing::Point(344, 12);
			this->selectFile_button->Name = L"selectFile_button";
			this->selectFile_button->Size = System::Drawing::Size(25, 25);
			this->selectFile_button->TabIndex = 14;
			this->selectFile_button->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->selectFile_button->UseVisualStyleBackColor = false;
			this->selectFile_button->Click += gcnew System::EventHandler(this, &Form1::selectFile_button_Click);
			// 
			// displayCircle_button
			// 
			this->displayCircle_button->BackColor = System::Drawing::Color::Silver;
			this->displayCircle_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"displayCircle_button.BackgroundImage")));
			this->displayCircle_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->displayCircle_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->displayCircle_button->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->displayCircle_button->Location = System::Drawing::Point(375, 12);
			this->displayCircle_button->Name = L"displayCircle_button";
			this->displayCircle_button->Size = System::Drawing::Size(25, 25);
			this->displayCircle_button->TabIndex = 15;
			this->displayCircle_button->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->displayCircle_button->UseVisualStyleBackColor = false;
			this->displayCircle_button->Click += gcnew System::EventHandler(this, &Form1::displayCircle_button_Click);
			// 
			// detail_button
			// 
			this->detail_button->BackColor = System::Drawing::Color::Silver;
			this->detail_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->detail_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->detail_button->ForeColor = System::Drawing::Color::Black;
			this->detail_button->Location = System::Drawing::Point(514, 21);
			this->detail_button->Name = L"detail_button";
			this->detail_button->Size = System::Drawing::Size(47, 21);
			this->detail_button->TabIndex = 16;
			this->detail_button->Text = L"細節..";
			this->detail_button->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->detail_button->UseVisualStyleBackColor = false;
			this->detail_button->Click += gcnew System::EventHandler(this, &Form1::detail_button_Click);
			// 
			// displayRetangle_button
			// 
			this->displayRetangle_button->BackColor = System::Drawing::Color::Silver;
			this->displayRetangle_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"displayRetangle_button.BackgroundImage")));
			this->displayRetangle_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->displayRetangle_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->displayRetangle_button->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->displayRetangle_button->Location = System::Drawing::Point(406, 12);
			this->displayRetangle_button->Name = L"displayRetangle_button";
			this->displayRetangle_button->Size = System::Drawing::Size(25, 25);
			this->displayRetangle_button->TabIndex = 16;
			this->displayRetangle_button->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->displayRetangle_button->UseVisualStyleBackColor = false;
			this->displayRetangle_button->Click += gcnew System::EventHandler(this, &Form1::displayRetangle_button_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(573, 390);
			this->Controls->Add(this->displayRetangle_button);
			this->Controls->Add(this->detail_button);
			this->Controls->Add(this->displayCircle_button);
			this->Controls->Add(this->filePath_textBox);
			this->Controls->Add(this->selectFile_button);
			this->Controls->Add(this->calculate_button);
			this->Controls->Add(this->artNum_label);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->artPoints_panel);
			this->Controls->Add(this->canvas_panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"圖";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->artPoints_panel->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->canvas_panel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {		 
				 graph = gcnew Graph(canvas_panel ,20);

				 detailForm = nullptr;
			 	 adjustButton(calculate_button ,false);
				 adjustButton(detail_button ,false);
			 }
	private: System::Void canvas_panel_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) 
			 {
				 graph->getEdgeEntity()->repaint();
			 }
	private: System::Void detailForm_FormClosed(Object ^,FormClosedEventArgs ^)
			 {
				 detailForm = nullptr;
				 adjustButton(detail_button ,true);
				 adjustButton(calculate_button ,calculateOnce);
			 }
	private: System::Void selectFile_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 ReadFile readfile;	
				 readfile.readTxtFile( gcnew Process(this ,&ArticulationPonit::Form1::processFileData) );//傳 如何處理txt檔的"函式"
			 }
	private: System::Void displayCircle_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 graph->beginningStatus();
			 }
	private: System::Void displayRetangle_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 graph->displayRetangle();
			 }
	private: System::Void calculate_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 displayArtPointEntity( graph->calulateArtPoint(0) );
			 }
	private: System::Void detail_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 adjustButton(detail_button ,false);
				 
				 detailForm = gcnew Inside(graph ,gcnew DisplayArtPointEntity(this ,&Form1::displayArtPointEntity));//傳按下detail_button時會發生的事 ,來達成同步
				 detailForm->FormClosed += gcnew FormClosedEventHandler(this ,&Form1::detailForm_FormClosed);//直接把

				 detailForm->Show(this);
				 
				 calculateOnce = calculate_button->Enabled;//存calculate_button的狀態
				 adjustButton(calculate_button ,false);
			 }
	/*===========================================================函式===============================================================*/
	private: void displayArtPointEntity(LinkList<int>^ list)
			 {
				 calculateOnce = false;//代表 Graph::calculate_button 已經按過了 ,不會回復
				 adjustButton(calculate_button ,false);
				 artPoints_panel->Controls->Clear();

				 artNum_label->Text  = list->getNum() + "個";
				 list->displayData( gcnew DisplayDataOnBord<int>(this ,&ArticulationPonit::Form1::displayData<int>) );
			 }
	private: void processFileData(String^ fileName)
			 {
				setDataChangeStatus(fileName);/////

				//使用原版c++ 或 c++/cli 的讀檔方法
				StreamReader ^ sr = gcnew StreamReader(fileName);
				///

				//處理方法...
				int temp_char;
				int i = 0,j = 0 ,n;
				bool first = true;
				while( (temp_char = sr->Read())!= -1 )
				{ 
					if(Char::IsDigit(temp_char) )
					{
						n = temp_char - '0';
						graph->getEdgeEntity()->setRelation(i ,j ,n);
						j++;
					}
					else if( temp_char == '\n')
					{
						if(first)
						{
							graph->getVertexEntities()->reSetVertexNum(j);
							first = false;
						}
						j = 0;
						i++;
					}
				}
				////
				sr->Close();

				graph->displayAllData();
			 }

	/*-------------------------關節點的實體------------------------------------*/
	private: generic <class ItemType>
			 void displayData(int num ,int data)
			 {
				 artPoints_panel->Controls->Add( addNewArtPoint(num ,data) );
			 }
	private: Panel^ addNewArtPoint(int num ,int data)
			 {
				Panel^ artPoint = gcnew Panel();
				artPoint->Size = System::Drawing::Size(109, 30);
				artPoint->Name = num + "panel";
				artPoint->Location    = System::Drawing::Point(0, (num-1) * 30);
				artPoint->BackColor   = Color::FromArgb(224 ,224 ,224);
				artPoint->BorderStyle = BorderStyle::Fixed3D;

				artPoint->Controls->Add( addNewLabelNum(num.ToString()) );
				artPoint->Controls->Add( addNewLabelContent(num.ToString() ,data.ToString()) );

				return artPoint;
			 }
	private: Label^ addNewLabelNum(String^ num)
			 {
				Label^ label_temp  = gcnew Label();
				
				label_temp->Font = (gcnew System::Drawing::Font(L"微軟正黑體" ,12 ,FontStyle::Bold ,System::Drawing::GraphicsUnit::Point ,136) );
				label_temp->Location = System::Drawing::Point(0, 1);
				label_temp->Size = System::Drawing::Size(45, 25);
				label_temp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

				label_temp->Name = num + "labelNum";
				label_temp->Text = num + ".";

				return label_temp ;				
			 }
	private: Label^ addNewLabelContent(String^ num , String^ content)
			 {
				Label^ label_temp  = gcnew Label();
				
				label_temp->Font = (gcnew System::Drawing::Font(L"微軟正黑體" ,9.75F ,FontStyle::Regular ,System::Drawing::GraphicsUnit::Point ,136) );
				label_temp->Location = System::Drawing::Point(50, 1);
				label_temp->Size = System::Drawing::Size(50, 25);
				label_temp->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;

				label_temp->Name = num + "labelContent";
				label_temp->Text = content;

				return label_temp ;				
			 }
	/*-------------------------------------------------------------------------*/
	/*===========================================================外觀===============================================================*/

	private: void setBeginingStatus()
			 {
				artNum_label->Text = "xx個";
				artPoints_panel->Controls->Clear();
				graph->clearAllData();
			 }
	private: void setDataChangeStatus(String^ fileName)
			 {
				setBeginingStatus();
				calculateOnce = true;//代表 Graph::calculate_button 還沒按過

				filePath_textBox->Text = fileName;

				if(detailForm != nullptr) detailForm->reSetDFSTree();
				if(detailForm == nullptr) 
				{
					adjustButton(this->calculate_button ,calculateOnce);
					adjustButton(this->detail_button ,true);
				}
			 }
	private: void adjustButton(Button^% myButton ,bool enable)
			 {
				 if( enable )
				 {
					 myButton->Enabled   = true;
					 myButton->BackColor = Color::Silver;
				 }
				 else
				 {
					 myButton->BackColor = Color::DarkGray;
					 myButton->Enabled   = false;
				 }
			 }
	}; 
}

