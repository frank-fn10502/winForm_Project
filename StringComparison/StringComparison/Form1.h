#pragma once
#include "StringCompare.h"


namespace StringComparison 
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
	private: System::Windows::Forms::RichTextBox^  Article;
	protected: 

	protected: 

	private: System::Windows::Forms::TextBox^  keyWords;

	protected: 
	private: System::Windows::Forms::Button^  Comparison_button;
	private: System::Windows::Forms::Button^  readFile_button;
	private: System::Windows::Forms::TextBox^ filePath;
    private: System::Windows::Forms::Label^   label1;
	private: System::Windows::Forms::Panel^   panel1;
	private: System::Windows::Forms::Label^   itemNum;
	private: System::Windows::Forms::Label^   label4;
	private: System::Windows::Forms::Label^   searchNum;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;
	    StringCompare^ searchString;//class

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->Article = (gcnew System::Windows::Forms::RichTextBox());
			this->keyWords = (gcnew System::Windows::Forms::TextBox());
			this->Comparison_button = (gcnew System::Windows::Forms::Button());
			this->readFile_button = (gcnew System::Windows::Forms::Button());
			this->filePath = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->itemNum = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->searchNum = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Article
			// 
			this->Article->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Article->Enabled = false;
			this->Article->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Article->ForeColor = System::Drawing::Color::Black;
			this->Article->Location = System::Drawing::Point(12, 41);
			this->Article->Name = L"Article";
			this->Article->ReadOnly = true;
			this->Article->Size = System::Drawing::Size(573, 518);
			this->Article->TabIndex = 0;
			this->Article->Text = L"";
			// 
			// keyWords
			// 
			this->keyWords->Enabled = false;
			this->keyWords->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->keyWords->Location = System::Drawing::Point(12, 10);
			this->keyWords->Name = L"keyWords";
			this->keyWords->Size = System::Drawing::Size(514, 25);
			this->keyWords->TabIndex = 1;
			this->keyWords->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::keyWords_KeyPress);
			// 
			// Comparison_button
			// 
			this->Comparison_button->Enabled = false;
			this->Comparison_button->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Comparison_button->Location = System::Drawing::Point(532, 10);
			this->Comparison_button->Name = L"Comparison_button";
			this->Comparison_button->Size = System::Drawing::Size(53, 25);
			this->Comparison_button->TabIndex = 2;
			this->Comparison_button->Text = L"尋找";
			this->Comparison_button->UseVisualStyleBackColor = true;
			this->Comparison_button->Click += gcnew System::EventHandler(this, &Form1::Comparison_button_Click);
			// 
			// readFile_button
			// 
			this->readFile_button->BackColor = System::Drawing::SystemColors::ControlLight;
			this->readFile_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->readFile_button->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->readFile_button->Location = System::Drawing::Point(826, 41);
			this->readFile_button->Name = L"readFile_button";
			this->readFile_button->Size = System::Drawing::Size(33, 23);
			this->readFile_button->TabIndex = 4;
			this->readFile_button->Text = L"...";
			this->readFile_button->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->readFile_button->UseVisualStyleBackColor = false;
			this->readFile_button->Click += gcnew System::EventHandler(this, &Form1::readFile_button_Click);
			// 
			// filePath
			// 
			this->filePath->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->filePath->Location = System::Drawing::Point(607, 41);
			this->filePath->Name = L"filePath";
			this->filePath->ReadOnly = true;
			this->filePath->Size = System::Drawing::Size(213, 23);
			this->filePath->TabIndex = 3;
			this->filePath->Text = L"請選擇檔案";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Controls->Add(this->itemNum);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->searchNum);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(607, 70);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(252, 267);
			this->panel1->TabIndex = 5;
			// 
			// itemNum
			// 
			this->itemNum->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->itemNum->Location = System::Drawing::Point(75, 44);
			this->itemNum->Name = L"itemNum";
			this->itemNum->Size = System::Drawing::Size(174, 21);
			this->itemNum->TabIndex = 3;
			this->itemNum->Text = L"0 個";
			this->itemNum->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(3, 44);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 21);
			this->label4->TabIndex = 2;
			this->label4->Text = L"符合項目:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// searchNum
			// 
			this->searchNum->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->searchNum->Location = System::Drawing::Point(75, 12);
			this->searchNum->Name = L"searchNum";
			this->searchNum->Size = System::Drawing::Size(174, 21);
			this->searchNum->TabIndex = 1;
			this->searchNum->Text = L"0 次";
			this->searchNum->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(3, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"比對次數:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(876, 574);
			this->Controls->Add(this->filePath);
			this->Controls->Add(this->readFile_button);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->Comparison_button);
			this->Controls->Add(this->keyWords);
			this->Controls->Add(this->Article);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"字串比較";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void readFile_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
				 openFileDialog->Filter = "txt files (*.txt)|*.txt";

				 if( openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK )
				 {	
					 if( StringCompare::setArticleByTxt(openFileDialog->FileName) )
					 {
						  enableSearchArea(openFileDialog->FileName);
					 }
					 else MessageBox::Show("檔案是空的!!");						
				 }
			 }
	private: System::Void keyWords_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
			 {
				 if( e->KeyChar == (char)13 )
				 {
					 e->Handled = true;//消除"ding"聲
					 search();
				 }
			 }
	private: System::Void Comparison_button_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
					search();
			 }
    /*===============================================函式============================================================*/
    private: void search()
			 {
				 keyWords->Text = (keyWords->Text)->Trim();
				 if( keyWords->Text == "" ) MessageBox::Show("請輸入字串!!");
				 else 
				 {
					  searchString = gcnew StringCompare( keyWords->Text );					  					  
					  changeColor( searchString->UseKMP() );	  
				 }
			 }

	/*===============================================介面============================================================*/
	private: void enableSearchArea(String^% path)
			 {
				filePath->Text  = path;	
				searchNum->Text = "0 次";
				itemNum->Text   = "無";
				keyWords->Text  = "";
				if( !keyWords->Enabled)		
				{
					keyWords->Enabled		   = true;
					Comparison_button->Enabled = true;
					Article->Enabled		   = true;
				}
				initializeArticle();
			 }
	private: void initializeArticle()
			 {
				Article->Clear();			
				Article->ForeColor = Color::Black;			
				Article->Text	   = StringCompare::getArticle();
			 }
	private: bool resultDisplay(array<int>^% strStarts)
			 {
				 searchNum->Text = searchString->getSearchNum() + " 次";
				 itemNum->Text = searchString->getArticleLength() + "";
				 if( strStarts == nullptr ) 
				 {
					  //itemNum->Text = "無";
					  MessageBox::Show( "搜索不到:\n" + "\"" + searchString->getKeywords() + "\"");
					  return false;
				 }	
				 else 
				 {
					 //itemNum->Text = strStarts->Length + " 個";					 
					 return true;
				 }
			 }
	private: void changeColor(array<int>^% strStarts)
			 {	
				 initializeArticle();
			 	 if( resultDisplay(strStarts) ) 
				 {
					 for(int i = 0 ; i < strStarts->Length ; i++)
					 {
						 Article->Select( strStarts[i] ,searchString->getKeywordsLength() );
						 Article->SelectionColor = Color::Red;
					 }	
				 }
			 }

	};//public ref class Form1 end
}//namespace StringComparison  end

