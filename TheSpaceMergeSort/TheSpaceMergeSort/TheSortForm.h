#pragma once
#include "NumbersEntity.h"
#include "SMSortBehavior.h"
#include "SpaceMergeSort.h"
#include "ObserverImp.h"

#include "ProcessControlForm.h"

namespace TheSpaceMergeSort 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// TheSortForm 的摘要
	/// </summary>
	public ref class TheSortForm : public System::Windows::Forms::Form
	{
	public:
		TheSortForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~TheSortForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  sort_panel;
	private: System::Windows::Forms::Label^  stateDes_label;
	private: System::Windows::Forms::Button^  openControl_button;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		Form^ controlPanel;
		NumbersEntity^ numbersEntity;
		SpaceMergeSort^ spaceMergeSort;
		bool detach;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->sort_panel = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->stateDes_label = (gcnew System::Windows::Forms::Label());
			this->openControl_button = (gcnew System::Windows::Forms::Button());
			this->sort_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Teal;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(0, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(10, 300);
			this->label1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Teal;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Location = System::Drawing::Point(13, 329);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(10, 21);
			this->label2->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Teal;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Location = System::Drawing::Point(510, 287);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(10, 63);
			this->label3->TabIndex = 2;
			// 
			// sort_panel
			// 
			this->sort_panel->BackColor = System::Drawing::Color::White;
			this->sort_panel->Controls->Add(this->label8);
			this->sort_panel->Controls->Add(this->label7);
			this->sort_panel->Controls->Add(this->label6);
			this->sort_panel->Controls->Add(this->label5);
			this->sort_panel->Controls->Add(this->label3);
			this->sort_panel->Controls->Add(this->label1);
			this->sort_panel->Controls->Add(this->label2);
			this->sort_panel->Location = System::Drawing::Point(5, 40);
			this->sort_panel->Name = L"sort_panel";
			this->sort_panel->Size = System::Drawing::Size(832, 350);
			this->sort_panel->TabIndex = 3;
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::Color::Teal;
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Location = System::Drawing::Point(556, 213);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(10, 137);
			this->label8->TabIndex = 6;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::Color::Teal;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label7->Location = System::Drawing::Point(572, 204);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(10, 146);
			this->label7->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::Teal;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Location = System::Drawing::Point(525, 258);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(10, 92);
			this->label6->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::Teal;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->Location = System::Drawing::Point(540, 227);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(10, 123);
			this->label5->TabIndex = 3;
			// 
			// stateDes_label
			// 
			this->stateDes_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->stateDes_label->Location = System::Drawing::Point(161, 9);
			this->stateDes_label->Name = L"stateDes_label";
			this->stateDes_label->Size = System::Drawing::Size(493, 28);
			this->stateDes_label->TabIndex = 5;
			this->stateDes_label->Text = L"找到最大的8個數字temp";
			this->stateDes_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openControl_button
			// 
			this->openControl_button->BackColor = System::Drawing::Color::Gray;
			this->openControl_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->openControl_button->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->openControl_button->Location = System::Drawing::Point(818, 9);
			this->openControl_button->Name = L"openControl_button";
			this->openControl_button->Size = System::Drawing::Size(19, 23);
			this->openControl_button->TabIndex = 6;
			this->openControl_button->Text = L"→";
			this->openControl_button->UseVisualStyleBackColor = false;
			this->openControl_button->Click += gcnew System::EventHandler(this, &TheSortForm::openControl_button_Click);
			// 
			// TheSortForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(843, 394);
			this->Controls->Add(this->openControl_button);
			this->Controls->Add(this->stateDes_label);
			this->Controls->Add(this->sort_panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"TheSortForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"排序";
			this->Load += gcnew System::EventHandler(this, &TheSortForm::TheSortForm_Load);
			this->LocationChanged += gcnew System::EventHandler(this, &TheSortForm::TheSortForm_LocationChanged);
			this->sort_panel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TheSortForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		createControlForm();

		sort_panel->Controls->Clear();
		stateDes_label->Text = "";

		detach = false;
	}
	private: System::Void openControl_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		createControlForm();
	}
	private: System::Void TheSortForm_LocationChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (controlPanel != nullptr)
		{		
			controlPanel->Location = Point(this->Location.X + this->Size.Width +10, this->Location.Y);
		}
	}
	private: System::Void ProcessControlForm_LocationChanged(System::Object^  sender, System::EventArgs^  e)
	{
		this->Location = Point(controlPanel->Location.X - this->Size.Width +10, controlPanel->Location.Y);
	}
	private: System::Void ProcessControlForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		ButtonOnOff::setButtonStyle(openControl_button ,true);
	}
/*==============================================函式============================================================================*/
	private: void setEntityAndSort(array<int>^ numbers)
	{
		numbersEntity  = gcnew NumbersEntity(numbers);
		//加入observer
		NumbersImp^ numbersImp = gcnew NumbersImp(sort_panel);
		numbersEntity->addEntityBehavior(numbersImp);

		spaceMergeSort = gcnew SpaceMergeSort(numbersEntity);
		//加入observers
		LargestPosImp^ largestPosImp = gcnew LargestPosImp(sort_panel);
		spaceMergeSort->getNumbersEntity()->addObserverLargestPos(largestPosImp);

		SelectPosImp^ selectPosImp = gcnew SelectPosImp(sort_panel);
		spaceMergeSort->getNumbersEntity()->addObserverSelectPos(selectPosImp);

		StateDesImp^ stateDesImp = gcnew StateDesImp(stateDes_label);
		spaceMergeSort->getNumbersEntity()->addObserverStateInfo(stateDesImp);

		//畫圖
		numbersEntity->notifyStatusChange();/////
		
		((ProcessControlForm^)controlPanel)->setControlForm(spaceMergeSort->getNumbersEntity() ,spaceMergeSort ,detach);
	}
	private: void attachOrDetach()
	{
		if (!detach)
		{
			controlPanel->LocationChanged -= gcnew System::EventHandler(this, &TheSortForm::ProcessControlForm_LocationChanged);
			this->LocationChanged -= gcnew System::EventHandler(this, &TheSortForm::TheSortForm_LocationChanged);
			detach = true;
		}
		else
		{
			controlPanel->LocationChanged += gcnew System::EventHandler(this, &TheSortForm::ProcessControlForm_LocationChanged);
			this->LocationChanged		  += gcnew System::EventHandler(this, &TheSortForm::TheSortForm_LocationChanged);
			controlPanel->Location = Point(this->Location.X + this->Size.Width +10 , this->Location.Y);

			detach = false;
		}
	}
	private: void createControlForm()
	{
		controlPanel = gcnew ProcessControlForm(gcnew SetEntityAndSort(this, &TheSortForm::setEntityAndSort) ,
											gcnew AttachOrDetach(this, &TheSortForm::attachOrDetach)	  );

		controlPanel->Location = Point(this->Location.X + this->Size.Width +10, this->Location.Y);
		controlPanel->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &TheSortForm::ProcessControlForm_FormClosed);

		if (!detach)
		{
			controlPanel->LocationChanged += gcnew System::EventHandler(this, &TheSortForm::ProcessControlForm_LocationChanged);		
		}
		controlPanel->Show();


		if (this->numbersEntity != nullptr)
		{
			((ProcessControlForm^)controlPanel)->setControlForm(spaceMergeSort->getNumbersEntity(), spaceMergeSort ,detach);
		}		
		ButtonOnOff::setButtonStyle(openControl_button ,false);
	}

	};
}
