#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace binarySearchTree 
{
	/// <summary>
	/// MutipleResult 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class MutipleResult : public System::Windows::Forms::Form
	{
	public:
		MutipleResult(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}
		MutipleResult(Forest* dictionary ,array<String^,2>^ insertData)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			insertDictionary(dictionary ,insertData);
		}
		MutipleResult(Forest* dictionary ,String^ file)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			insertDictionaryByFile(dictionary ,file);
		}
		MutipleResult(Forest* dictionary ,array<String^>^ deleteData)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			deleteDictionary(dictionary ,deleteData);
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MutipleResult()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: 
	private: System::Windows::Forms::Button^  go_back_button;
	private: System::Windows::Forms::Label^  fail_num_label;
	private: System::Windows::Forms::Label^  success_num_label;
	private: System::Windows::Forms::Label^  fail_label;
	private: System::Windows::Forms::Label^  success_label;
	private: System::Windows::Forms::RichTextBox^  display_richTextBox;



	private: System::ComponentModel::Container ^components;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		msclr::interop::marshal_context context;

		bool mode;
		String^ str;
		int success ,fail;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->go_back_button = (gcnew System::Windows::Forms::Button());
			this->fail_num_label = (gcnew System::Windows::Forms::Label());
			this->success_num_label = (gcnew System::Windows::Forms::Label());
			this->fail_label = (gcnew System::Windows::Forms::Label());
			this->success_label = (gcnew System::Windows::Forms::Label());
			this->display_richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// go_back_button
			// 
			this->go_back_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->go_back_button->Location = System::Drawing::Point(100, 219);
			this->go_back_button->Name = L"go_back_button";
			this->go_back_button->Size = System::Drawing::Size(98, 29);
			this->go_back_button->TabIndex = 29;
			this->go_back_button->Text = L"確定";
			this->go_back_button->UseVisualStyleBackColor = true;
			this->go_back_button->Click += gcnew System::EventHandler(this, &MutipleResult::go_back_button_Click);
			// 
			// fail_num_label
			// 
			this->fail_num_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->fail_num_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->fail_num_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->fail_num_label->Location = System::Drawing::Point(227, 21);
			this->fail_num_label->Name = L"fail_num_label";
			this->fail_num_label->Size = System::Drawing::Size(61, 23);
			this->fail_num_label->TabIndex = 28;
			this->fail_num_label->Text = L"10";
			this->fail_num_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// success_num_label
			// 
			this->success_num_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->success_num_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->success_num_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->success_num_label->Location = System::Drawing::Point(90, 21);
			this->success_num_label->Name = L"success_num_label";
			this->success_num_label->Size = System::Drawing::Size(61, 23);
			this->success_num_label->TabIndex = 27;
			this->success_num_label->Text = L"100";
			this->success_num_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// fail_label
			// 
			this->fail_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->fail_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->fail_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->fail_label->Location = System::Drawing::Point(157, 21);
			this->fail_label->Name = L"fail_label";
			this->fail_label->Size = System::Drawing::Size(66, 23);
			this->fail_label->TabIndex = 26;
			this->fail_label->Text = L"找不到:";
			this->fail_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// success_label
			// 
			this->success_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->success_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->success_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->success_label->Location = System::Drawing::Point(6, 21);
			this->success_label->Name = L"success_label";
			this->success_label->Size = System::Drawing::Size(78, 23);
			this->success_label->TabIndex = 25;
			this->success_label->Text = L"加入成功:";
			this->success_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// display_richTextBox
			// 
			this->display_richTextBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->display_richTextBox->Location = System::Drawing::Point(10, 59);
			this->display_richTextBox->Name = L"display_richTextBox";
			this->display_richTextBox->Size = System::Drawing::Size(280, 145);
			this->display_richTextBox->TabIndex = 24;
			this->display_richTextBox->Text = L"1. apple --> 蘋果     加入成功\n2. apple --> 蘋果     加入成功\n3. apple --> 蘋果     加入成功\n4. app" 
				L"le --> 蘋果     加入成功\n5. apple --> 蘋果     加入成功\n6. apple --> 蘋果     加入成功";
			// 
			// MutipleResult
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 269);
			this->Controls->Add(this->go_back_button);
			this->Controls->Add(this->fail_num_label);
			this->Controls->Add(this->success_num_label);
			this->Controls->Add(this->fail_label);
			this->Controls->Add(this->success_label);
			this->Controls->Add(this->display_richTextBox);
			this->Name = L"MutipleResult";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"結果";
			this->Load += gcnew System::EventHandler(this, &MutipleResult::MutipleResult_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void insertDictionary(Forest* dictionary ,array<String^,2>^ insertData)
			 {
				 str = "";
				 success = 0;
				 fail    = 0;
				 bool result;
				 for(int i = 0 ; i < insertData->Length/2 ; i ++ )
				 {
					 result = dictionary->insertNode( getStdString(insertData[i,0])
													, getStdString(insertData[i,1]));

					 if( result ) success++;
					 else		  fail++;

					 if( i > 0 ) str += "\n";

					 str += insertData[i,0] + /*" --> " + insertData[i,1] +*/ "     " + (result? "加入成功" : "重複");
				 }
				 mode = true;
			 }
	private: void insertDictionaryByFile(Forest* dictionary ,String^ file)
			 {
				 str = "";
				 success = 0;
				 fail    = 0;
				 bool result;
				 String^ ChStr;
				 std::string en ,ch;
				 fstream fin;
				 fin.open(getStdString(file).c_str(),ios::in);
				 while( fin >> en >> ch )
				 {
					 std::transform(en.begin(), en.end(), en.begin(), ::tolower);
					 ChStr = gcnew String(ch.c_str());
					 ChStr = ChStr->ToLower();

					 
					 result = dictionary->insertNode(en ,getStdString(ChStr) );

					 if( result ) success++;
					 else		  fail++;

					 if( str != "" ) str += "\n";

					 str += gcnew String( en.c_str() ) + /*" --> " + 
						    gcnew String( ch.c_str() ) +*/ "     " + (result? "加入成功" : "重複");
				 }
				 fin.close();
				 mode = true;
			 }
	private: void deleteDictionary(Forest* dictionary ,array<String^>^ deleteData)
			 {
				 str = "";
				 success = 0;
				 fail    = 0;
				 bool result;
				 for(int i = 0 ; i < deleteData->Length ; i ++ )
				 {
					 result = dictionary->deleteNode( getStdString(deleteData[i]) );

					 if( result ) success++;
					 else		  fail++;

					 if( i > 0 ) str += "\n";

					 str += deleteData[i] + "     " + (result? "刪除成功" : "找不到");
				 }
				 mode = false;
			 }
	private: std::string getStdString(String^ str)
			 {
				return context.marshal_as<std::string>(str);
			 }
	/*=====================================================================================*/
	private: System::Void MutipleResult_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( mode )
				 {
					 this->Text = "加入結果";
					 success_label->Text = "加入成功:";
					 fail_label->Text = "重複:";
				 }
				 else
				 {
					 this->Text = "刪除結果";
					 success_label->Text = "刪除成功:";
					 fail_label->Text = "找不到:";
				 }
				 success_num_label->Text = success.ToString();
				 fail_num_label->Text    = fail.ToString();
				 display_richTextBox->Text = str;
			 }
	private: System::Void go_back_button_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 this->Close();
			 }
	};
}
