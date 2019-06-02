#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;////////


namespace TheGuessPocker 
{
	/// <summary>
	/// SavePage 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class SavePage : public System::Windows::Forms::Form
	{
	public:
		SavePage(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}
		SavePage(int *form ,int* OldGame ,bool IsLoad ,int from)
		{
			InitializeComponent();
			*form = -1;	

			ToForm       = form;
			TheOldGame   = OldGame;
			this->IsLoad = IsLoad;
			this->from   = from;
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~SavePage()
		{
			if (components)
			{
				delete components;				
			}
			if(*ToForm != 2)File::Delete(fileName1);
		}

	private: System::Windows::Forms::Label^  SampleLabel1;
	private: System::Windows::Forms::Panel^  SavePanel;
	private: System::Windows::Forms::Label^  SampleLabel2;
	private: System::Windows::Forms::Label^  TitleLabel;
	private: System::Windows::Forms::Button^  BackToSome;
	private: System::Windows::Forms::Button^  SampleBtn;
	private: System::Windows::Forms::Button^  BackToHome;
	private: System::Windows::Forms::Panel^  CoverSavePanel;

	private: System::Windows::Forms::Button^  SureBtn;
	private: System::Windows::Forms::Button^  CencelBtn;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::Container ^components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>		
		int* ToForm;
		int* TheOldGame;
		bool IsLoad;
		int  from;
		/*--------------------------*/
		int currentSave;
	    static int SaveNum = 10;
	    static array<bool>^ exist = gcnew array<bool>(SaveNum);;
	    static String^ Path      = Path::GetFullPath( "..\\Save\\" );
	    static String^ fileName1 = Path  +  "GameSave100.txt"; 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->SampleLabel1 = (gcnew System::Windows::Forms::Label());
			this->SavePanel = (gcnew System::Windows::Forms::Panel());
			this->CoverSavePanel = (gcnew System::Windows::Forms::Panel());
			this->SureBtn = (gcnew System::Windows::Forms::Button());
			this->CencelBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SampleBtn = (gcnew System::Windows::Forms::Button());
			this->SampleLabel2 = (gcnew System::Windows::Forms::Label());
			this->TitleLabel = (gcnew System::Windows::Forms::Label());
			this->BackToSome = (gcnew System::Windows::Forms::Button());
			this->BackToHome = (gcnew System::Windows::Forms::Button());
			this->SavePanel->SuspendLayout();
			this->CoverSavePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// SampleLabel1
			// 
			this->SampleLabel1->BackColor = System::Drawing::Color::DarkGray;
			this->SampleLabel1->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->SampleLabel1->Location = System::Drawing::Point(0, 30);
			this->SampleLabel1->Name = L"SampleLabel1";
			this->SampleLabel1->Size = System::Drawing::Size(482, 25);
			this->SampleLabel1->TabIndex = 0;
			this->SampleLabel1->Text = L"遊戲存檔1: 2017/6/4 下午 11:25:41";
			this->SampleLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->SampleLabel1->Visible = false;
			// 
			// SavePanel
			// 
			this->SavePanel->AutoScroll = true;
			this->SavePanel->BackColor = System::Drawing::Color::Silver;
			this->SavePanel->Controls->Add(this->CoverSavePanel);
			this->SavePanel->Controls->Add(this->SampleBtn);
			this->SavePanel->Controls->Add(this->SampleLabel2);
			this->SavePanel->Controls->Add(this->TitleLabel);
			this->SavePanel->Controls->Add(this->SampleLabel1);
			this->SavePanel->Location = System::Drawing::Point(0, 0);
			this->SavePanel->Name = L"SavePanel";
			this->SavePanel->Size = System::Drawing::Size(584, 350);
			this->SavePanel->TabIndex = 1;
			// 
			// CoverSavePanel
			// 
			this->CoverSavePanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->CoverSavePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CoverSavePanel->Controls->Add(this->SureBtn);
			this->CoverSavePanel->Controls->Add(this->CencelBtn);
			this->CoverSavePanel->Controls->Add(this->label1);
			this->CoverSavePanel->Location = System::Drawing::Point(153, 113);
			this->CoverSavePanel->Name = L"CoverSavePanel";
			this->CoverSavePanel->Size = System::Drawing::Size(240, 115);
			this->CoverSavePanel->TabIndex = 4;
			// 
			// SureBtn
			// 
			this->SureBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->SureBtn->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->SureBtn->Location = System::Drawing::Point(132, 57);
			this->SureBtn->Name = L"SureBtn";
			this->SureBtn->Size = System::Drawing::Size(85, 35);
			this->SureBtn->TabIndex = 4;
			this->SureBtn->Text = L"確定";
			this->SureBtn->UseVisualStyleBackColor = false;
			this->SureBtn->Click += gcnew System::EventHandler(this, &SavePage::SureBtn_Click);
			// 
			// CencelBtn
			// 
			this->CencelBtn->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->CencelBtn->Location = System::Drawing::Point(20, 57);
			this->CencelBtn->Name = L"CencelBtn";
			this->CencelBtn->Size = System::Drawing::Size(85, 35);
			this->CencelBtn->TabIndex = 3;
			this->CencelBtn->Text = L"取消";
			this->CencelBtn->UseVisualStyleBackColor = true;
			this->CencelBtn->Click += gcnew System::EventHandler(this, &SavePage::CencelBtn_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(27, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(199, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"確定覆蓋存檔嗎\?";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// SampleBtn
			// 
			this->SampleBtn->BackColor = System::Drawing::Color::DarkGray;
			this->SampleBtn->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->SampleBtn->Location = System::Drawing::Point(487, 30);
			this->SampleBtn->Name = L"SampleBtn";
			this->SampleBtn->Size = System::Drawing::Size(65, 25);
			this->SampleBtn->TabIndex = 3;
			this->SampleBtn->Text = L"刪除";
			this->SampleBtn->UseVisualStyleBackColor = false;
			this->SampleBtn->Visible = false;
			// 
			// SampleLabel2
			// 
			this->SampleLabel2->BackColor = System::Drawing::Color::DarkGray;
			this->SampleLabel2->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->SampleLabel2->Location = System::Drawing::Point(0, 60);
			this->SampleLabel2->Name = L"SampleLabel2";
			this->SampleLabel2->Size = System::Drawing::Size(573, 25);
			this->SampleLabel2->TabIndex = 2;
			this->SampleLabel2->Text = L"遊戲存檔2: ---- / - / -  -- --:--:-- ";
			this->SampleLabel2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->SampleLabel2->Visible = false;
			// 
			// TitleLabel
			// 
			this->TitleLabel->BackColor = System::Drawing::Color::Transparent;
			this->TitleLabel->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->TitleLabel->Location = System::Drawing::Point(0, 5);
			this->TitleLabel->Name = L"TitleLabel";
			this->TitleLabel->Size = System::Drawing::Size(502, 25);
			this->TitleLabel->TabIndex = 1;
			this->TitleLabel->Text = L"遊戲存檔";
			this->TitleLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// BackToSome
			// 
			this->BackToSome->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->BackToSome->Location = System::Drawing::Point(10, 364);
			this->BackToSome->Name = L"BackToSome";
			this->BackToSome->Size = System::Drawing::Size(85, 35);
			this->BackToSome->TabIndex = 2;
			this->BackToSome->Text = L"返回未知";
			this->BackToSome->UseVisualStyleBackColor = true;
			this->BackToSome->Click += gcnew System::EventHandler(this, &SavePage::BackToSome_Click);
			// 
			// BackToHome
			// 
			this->BackToHome->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->BackToHome->Location = System::Drawing::Point(116, 364);
			this->BackToHome->Name = L"BackToHome";
			this->BackToHome->Size = System::Drawing::Size(85, 35);
			this->BackToHome->TabIndex = 3;
			this->BackToHome->Text = L"返回選單";
			this->BackToHome->UseVisualStyleBackColor = true;
			this->BackToHome->Click += gcnew System::EventHandler(this, &SavePage::BackToHome_Click);
			// 
			// SavePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(584, 411);
			this->Controls->Add(this->BackToHome);
			this->Controls->Add(this->BackToSome);
			this->Controls->Add(this->SavePanel);
			this->Name = L"SavePage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SavePage";
			this->Load += gcnew System::EventHandler(this, &SavePage::SavePage_Load);
			this->SavePanel->ResumeLayout(false);
			this->CoverSavePanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SavePage_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( IsLoad ) TitleLabel->Text = "載入遊戲";
				 else		  TitleLabel->Text = "遊戲存檔";

				 if( from == 1)      
				 {
					 BackToSome->Text = "返回選單";
					 BackToHome->Visible = false;
				 }
				 else if( from == 2) 
				 {
					 BackToSome->Text = "返回遊戲";
					 BackToHome->Visible = true;
				 }
				 CoverSavePanel->Visible = false;
				 				 
				 SetSavePanel();
			 }
	private: void SetSavePanel()
			 {
				 for(int i = 1 ; i <= SaveNum ; i++ )
				 {	
					 SavePanel->Controls->Add( AddNewLabel(i) );
					 if(!IsLoad ) 
						 SavePanel->Controls->Add( AddNewButton(i) );
				 }
			 }
    /*-----------------------------------AddNewLabel-----------------------------------------------*/
	private: Label^ AddNewLabel(int num)
			 {
				Label^ labelTemp  = gcnew Label();
				
				labelTemp->Font = (gcnew Drawing::Font(L"新細明體", 15.75F, FontStyle::Bold, GraphicsUnit::Point, 
				static_cast<System::Byte>(136)) );

				labelTemp->Size      = Drawing::Size(482, 25);//502, 25
				labelTemp->Location  = Drawing::Point(0,num*30 );
				labelTemp->BackColor = Color::DarkGray;
				labelTemp->TextAlign = ContentAlignment::MiddleLeft;
				labelTemp->Name = num.ToString();		
				labelTemp->Text = setLabelText( num );

				labelTemp->MouseEnter += gcnew System::EventHandler(this, &SavePage::SaveLabel_MouseEnter);
				labelTemp->MouseLeave += gcnew System::EventHandler(this, &SavePage::SaveLabel_MouseLeave);
				labelTemp->Click      += gcnew System::EventHandler(this, &SavePage::SaveLabel_Click);

				return labelTemp;			
			 }
	private: System::Void SaveLabel_Click(System::Object^  sender, System::EventArgs^  e) 
			 {	
				 Label^ labelTemp = (Label^)sender;
				 int num = Convert::ToInt16( labelTemp->Name );
				 currentSave = num;

				 if( IsLoad ) 
				 {
					 if( exist[num-1] )
					 {
						 *TheOldGame = num;
						 *ToForm     = 2;
						 this->Close();
					 }
				 }
				 else
				 {						 
					 if( !exist[num-1] ) SaveData(labelTemp );
					 else	
					 {					 
						 for(int i = 1 ; i <= SaveNum ; i ++)
						 {
							Label^ Lab  = (Label^)SavePanel->Controls->Find( i.ToString() ,true)[0];
							Lab->Enabled = false;
							//Lab->MouseEnter -= gcnew System::EventHandler(this, &SavePage::SaveLabel_MouseEnter);
							//Lab->MouseLeave -= gcnew System::EventHandler(this, &SavePage::SaveLabel_MouseLeave);
							//Lab->Click      -= gcnew System::EventHandler(this, &SavePage::SaveLabel_Click);

							if( exist[ i-1 ] )
							{
								Button^ Btn = (Button^)SavePanel->Controls->Find("Button"+ i.ToString() ,true)[0];
								Btn->Enabled = false;
							}
						 }
						 CoverSavePanel->Visible = true;
					 }
				 }
			 }

	private: System::Void SaveLabel_MouseEnter(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Label^ labelTemp   = (Label^)sender;				 
				 labelTemp->BackColor = Color::White;

				 int num = Convert::ToInt16( labelTemp->Name );
				 if( !IsLoad && exist[num-1] )
				 {				 
					 Button^ Button_temp = (Button^)SavePanel->Controls->Find("Button"+ num.ToString() ,true)[0];
					 Button_temp->BackColor = Color::White;
				 }
			 }
	private: System::Void SaveLabel_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Label^ labelTemp   = (Label^)sender;
				 labelTemp->BackColor = Color::DarkGray;
				 
				 int num = Convert::ToInt16( labelTemp->Name );
				 if( !IsLoad && exist[num-1] )
				 {	 
					 Button^ Button_temp = (Button^)SavePanel->Controls->Find("Button"+ num.ToString() ,true)[0];
					 Button_temp->BackColor = Color::DarkGray;
				 }
			 }
    /*-----------------------------------AddNewButton----------------------------------------------*/
	private: Button^ AddNewButton(int num )
			 {
				Button^ Btn = gcnew Button();
		
				Btn->BackColor = Color::DarkGray;
				Btn->Size      = Drawing::Size(65, 25);
				Btn->Location  = Drawing::Point(487, num*30 ); //450
				Btn->TextAlign = ContentAlignment::MiddleCenter;
				Btn->Name = "Button" + num.ToString();			
				Btn->Text = "刪除";			
				Btn->Font = (gcnew Drawing::Font(L"新細明體", 12, FontStyle::Bold, GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));

				Btn->Click  += gcnew System::EventHandler(this, &SavePage::DeleteBtn_Click);
				Btn->Visible = exist[num-1];

				return Btn;
			 }
	private: System::Void DeleteBtn_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 Button^ Btn   = (Button^)sender;
				 String^ str = Btn->Name;
				 str = str->Substring( str->IndexOf("n")+1 );
				 int num = Convert::ToInt16( str );

				 String^ fileName = Path  +  "GameSave" + num.ToString() + ".txt";
				 File::Delete(fileName);

				 Label^ labelTemp  = (Label^)SavePanel->Controls->Find( num.ToString() ,true)[0];
				 labelTemp->Text = setLabelText( num );////

				 Btn->Visible = false;
			 }
    /*-----------------------------------CoverSavePanel-------------------------------------------------*/
    private: System::Void SureBtn_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Label^ labelTemp  = (Label^)SavePanel->Controls->Find( currentSave.ToString() ,true)[0];
		
				 SaveData( labelTemp );
				 BackSavePage();
			 }
	private: System::Void CencelBtn_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				BackSavePage();
			 }
	private: void BackSavePage()
			 {
				 for(int i = 1 ; i <= SaveNum ; i ++)
				 {
					
					Label^ labelTemp  = (Label^)SavePanel->Controls->Find( i.ToString() ,true)[0];
					labelTemp->Enabled = true;
					//labelTemp->MouseEnter += gcnew System::EventHandler(this, &SavePage::SaveLabel_MouseEnter);
					//labelTemp->MouseLeave += gcnew System::EventHandler(this, &SavePage::SaveLabel_MouseLeave);
					//labelTemp->Click      += gcnew System::EventHandler(this, &SavePage::SaveLabel_Click);
					if( i == currentSave ) labelTemp->BackColor = Color::DarkGray;

					if( exist[ i-1 ] )
					{
						Button^ Btn = (Button^)SavePanel->Controls->Find("Button"+ i.ToString() ,true)[0];
						Btn->Enabled = true;
						if( i == currentSave ) Btn->BackColor = Color::DarkGray;
					}				
				 }

				 CoverSavePanel->Visible = false;
			 }
    /*-------------------------------------------------------------------------------------------------*/
	private: void SaveData(Label^% labelTemp )
			 {
				 String^ fileName2 = Path  +  "GameSave" + currentSave.ToString() + ".txt";
				 File::Copy(fileName1 ,fileName2 ,true);
				 labelTemp->Text = setLabelText( currentSave );	 	

				 Button^ Btn = (Button^)SavePanel->Controls->Find("Button"+ currentSave ,true)[0];
				 Btn->Visible = true;
			 }
	private: String^ setLabelText(int num)
			 {
				String^ str;
				if(num < 10 ) str = "遊戲存檔" + num.ToString() + "  : ";
				else		  str = "遊戲存檔" + num.ToString() + ": "  ;

				String^ fileName = Path  +  "GameSave" + num.ToString() + ".txt"; ///////////// 
				if( File::Exists( fileName ) ) 
				{
					StreamReader^ TheSave = File::OpenText(fileName);
				    
					//String^ StrTemp;// = TheSave->ReadLine() ;
					//while (( StrTemp = TheSave->ReadLine() ) != nullptr )
					//{	
					//	if( StrTemp->StartsWith("時間:") )
					//	{
					//		StrTemp = StrTemp->Substring( StrTemp->IndexOf(" ")+1 );
					//		str += StrTemp;
					//	}
					//	else if( StrTemp->StartsWith("記憶時間:") )
					//	{
					//		StrTemp = " ( 倒數: " + StrTemp->Substring( StrTemp->IndexOf(" ")+1 );
					//		str += StrTemp;
					//		break;
					//	}
					//}		
					String^ StrTemp  = TheSave->ReadLine() ;
					StrTemp = StrTemp->Substring( StrTemp->IndexOf(" ")+1 );
					str += StrTemp;

					TheSave->Close();

					exist[num-1] = true;
				}
				else 
				{
					str += "---- / - / -  -- --:--:-- ";
					exist[num-1] = false;
				}
				return str;
			 }
    /*-------------------------------------------------------------------------------------------------*/
	private: System::Void BackToSome_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				*ToForm     = from;
				*TheOldGame = 100;
				this->Close();
			 }
	private: System::Void BackToHome_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
 				 *ToForm = 1;
				 this->Close();
			 }
	};//end of class SavePage
}//end of namespace TheGuessPocker 
