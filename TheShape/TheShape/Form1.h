#pragma once
#include "TheColor.h"
#include "Circle.h"
#include "Cube.h"
#include "TheRectangle.h"

namespace TheShape 
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
	internal: System::Windows::Forms::TabControl^  select_shape;
	protected: 

	private: System::Windows::Forms::TabPage^	rectangle;
	private: System::Windows::Forms::TabPage^   circle;
	private: System::Windows::Forms::Panel^     compute_num;
	private: System::Windows::Forms::Label^     volume_num;
	private: System::Windows::Forms::Label^     volume_label;
	private: System::Windows::Forms::Label^     Area_num;
	private: System::Windows::Forms::Label^     Area_label;
	private: System::Windows::Forms::Panel^  Drawing_paper;
	private: System::Windows::Forms::CheckBox^  Rect_fill;
	private: System::Windows::Forms::Button^    produce_shape_Btn;
	private: System::Windows::Forms::Label^     current_shape;
	private: System::Windows::Forms::CheckBox^  square_checkbox;
	private: System::Windows::Forms::TextBox^   width_input;
	private: System::Windows::Forms::Label^     width_label;
	private: System::Windows::Forms::TextBox^   length_input;
	private: System::Windows::Forms::Label^     length_label;
	private: System::Windows::Forms::CheckBox^  Cirlcle_fill;
	private: System::Windows::Forms::Label^     update;
	private: System::Windows::Forms::TextBox^   Radius_input;
	private: System::Windows::Forms::Label^     Radius_label;
	private: System::Windows::Forms::ComboBox^  CircleColor_combobox;
	private: System::Windows::Forms::Label^  CircleColor_label;
	private: System::Windows::Forms::ComboBox^  RectColor_combobox;
	private: System::Windows::Forms::Label^  RectColor_label;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::TabPage^  cube;
	private: System::Windows::Forms::TextBox^  CubeHeight_input;
	private: System::Windows::Forms::Label^  CubeHeight_label;
	private: System::Windows::Forms::TextBox^  CubeWidth_input;
	private: System::Windows::Forms::Label^  CubeWidth_label;
	private: System::Windows::Forms::TextBox^  CubeLength_input;
	private: System::Windows::Forms::Label^  CubeLength_label;
	private: System::Windows::Forms::CheckBox^  cube_checkBox;
	private: System::Windows::Forms::ComboBox^  CubeColor_combobox;
	private: System::Windows::Forms::Label^  CubeColor_label;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		Circle c;
		TheRectangle r;
		Cube cu;
		/////////////////////
		Graphics^ mygraphics;
		Pen^ myPen;
		SolidBrush^ myBrush;
		/////////
		static array<Point>^ points_top   = gcnew array<Point>(5);
		static array<Point>^ points_under = gcnew array<Point>(5);


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::ToolTip^  toolTip1;
			this->width_input = (gcnew System::Windows::Forms::TextBox());
			this->length_input = (gcnew System::Windows::Forms::TextBox());
			this->Radius_input = (gcnew System::Windows::Forms::TextBox());
			this->CubeLength_input = (gcnew System::Windows::Forms::TextBox());
			this->CubeWidth_input = (gcnew System::Windows::Forms::TextBox());
			this->CubeHeight_input = (gcnew System::Windows::Forms::TextBox());
			this->select_shape = (gcnew System::Windows::Forms::TabControl());
			this->rectangle = (gcnew System::Windows::Forms::TabPage());
			this->RectColor_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->RectColor_label = (gcnew System::Windows::Forms::Label());
			this->square_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->width_label = (gcnew System::Windows::Forms::Label());
			this->length_label = (gcnew System::Windows::Forms::Label());
			this->Rect_fill = (gcnew System::Windows::Forms::CheckBox());
			this->circle = (gcnew System::Windows::Forms::TabPage());
			this->CircleColor_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->CircleColor_label = (gcnew System::Windows::Forms::Label());
			this->Radius_label = (gcnew System::Windows::Forms::Label());
			this->Cirlcle_fill = (gcnew System::Windows::Forms::CheckBox());
			this->cube = (gcnew System::Windows::Forms::TabPage());
			this->CubeColor_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->CubeColor_label = (gcnew System::Windows::Forms::Label());
			this->cube_checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->CubeHeight_label = (gcnew System::Windows::Forms::Label());
			this->CubeWidth_label = (gcnew System::Windows::Forms::Label());
			this->CubeLength_label = (gcnew System::Windows::Forms::Label());
			this->compute_num = (gcnew System::Windows::Forms::Panel());
			this->volume_num = (gcnew System::Windows::Forms::Label());
			this->volume_label = (gcnew System::Windows::Forms::Label());
			this->Area_num = (gcnew System::Windows::Forms::Label());
			this->Area_label = (gcnew System::Windows::Forms::Label());
			this->Drawing_paper = (gcnew System::Windows::Forms::Panel());
			this->produce_shape_Btn = (gcnew System::Windows::Forms::Button());
			this->current_shape = (gcnew System::Windows::Forms::Label());
			this->update = (gcnew System::Windows::Forms::Label());
			toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->select_shape->SuspendLayout();
			this->rectangle->SuspendLayout();
			this->circle->SuspendLayout();
			this->cube->SuspendLayout();
			this->compute_num->SuspendLayout();
			this->SuspendLayout();
			// 
			// width_input
			// 
			this->width_input->Location = System::Drawing::Point(42, 65);
			this->width_input->Name = L"width_input";
			this->width_input->Size = System::Drawing::Size(123, 27);
			this->width_input->TabIndex = 8;
			toolTip1->SetToolTip(this->width_input, L"< 400");
			this->width_input->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->width_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::input_KeyDown);
			this->width_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// length_input
			// 
			this->length_input->BackColor = System::Drawing::Color::White;
			this->length_input->Location = System::Drawing::Point(42, 30);
			this->length_input->Name = L"length_input";
			this->length_input->Size = System::Drawing::Size(123, 27);
			this->length_input->TabIndex = 6;
			toolTip1->SetToolTip(this->length_input, L"< 400");
			this->length_input->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->length_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::input_KeyDown);
			this->length_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// Radius_input
			// 
			this->Radius_input->Location = System::Drawing::Point(59, 29);
			this->Radius_input->Name = L"Radius_input";
			this->Radius_input->Size = System::Drawing::Size(113, 27);
			this->Radius_input->TabIndex = 8;
			toolTip1->SetToolTip(this->Radius_input, L"< 200");
			this->Radius_input->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->Radius_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::input_KeyDown);
			this->Radius_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// CubeLength_input
			// 
			this->CubeLength_input->BackColor = System::Drawing::Color::White;
			this->CubeLength_input->Location = System::Drawing::Point(40, 34);
			this->CubeLength_input->Name = L"CubeLength_input";
			this->CubeLength_input->Size = System::Drawing::Size(133, 27);
			this->CubeLength_input->TabIndex = 8;
			toolTip1->SetToolTip(this->CubeLength_input, L"< 200");
			this->CubeLength_input->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->CubeLength_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::input_KeyDown);
			this->CubeLength_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// CubeWidth_input
			// 
			this->CubeWidth_input->BackColor = System::Drawing::Color::White;
			this->CubeWidth_input->Location = System::Drawing::Point(39, 71);
			this->CubeWidth_input->Name = L"CubeWidth_input";
			this->CubeWidth_input->Size = System::Drawing::Size(134, 27);
			this->CubeWidth_input->TabIndex = 10;
			toolTip1->SetToolTip(this->CubeWidth_input, L"< 200");
			this->CubeWidth_input->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->CubeWidth_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::input_KeyDown);
			this->CubeWidth_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// CubeHeight_input
			// 
			this->CubeHeight_input->BackColor = System::Drawing::Color::White;
			this->CubeHeight_input->Location = System::Drawing::Point(39, 109);
			this->CubeHeight_input->Name = L"CubeHeight_input";
			this->CubeHeight_input->Size = System::Drawing::Size(134, 27);
			this->CubeHeight_input->TabIndex = 12;
			toolTip1->SetToolTip(this->CubeHeight_input, L"< 200");
			this->CubeHeight_input->TextChanged += gcnew System::EventHandler(this, &Form1::input_TextChanged);
			this->CubeHeight_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::input_KeyDown);
			this->CubeHeight_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::input_KeyPress);
			// 
			// select_shape
			// 
			this->select_shape->Controls->Add(this->rectangle);
			this->select_shape->Controls->Add(this->circle);
			this->select_shape->Controls->Add(this->cube);
			this->select_shape->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->select_shape->Location = System::Drawing::Point(12, 12);
			this->select_shape->Name = L"select_shape";
			this->select_shape->SelectedIndex = 0;
			this->select_shape->Size = System::Drawing::Size(251, 270);
			this->select_shape->TabIndex = 0;
			this->select_shape->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::select_shape_SelectedIndexChanged);
			// 
			// rectangle
			// 
			this->rectangle->BackColor = System::Drawing::Color::Silver;
			this->rectangle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rectangle->Controls->Add(this->RectColor_combobox);
			this->rectangle->Controls->Add(this->RectColor_label);
			this->rectangle->Controls->Add(this->square_checkbox);
			this->rectangle->Controls->Add(this->width_input);
			this->rectangle->Controls->Add(this->width_label);
			this->rectangle->Controls->Add(this->length_input);
			this->rectangle->Controls->Add(this->length_label);
			this->rectangle->Controls->Add(this->Rect_fill);
			this->rectangle->Location = System::Drawing::Point(4, 26);
			this->rectangle->Name = L"rectangle";
			this->rectangle->Padding = System::Windows::Forms::Padding(3);
			this->rectangle->Size = System::Drawing::Size(243, 240);
			this->rectangle->TabIndex = 1;
			this->rectangle->Text = L"四邊形";
			// 
			// RectColor_combobox
			// 
			this->RectColor_combobox->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->RectColor_combobox->DropDownHeight = 100;
			this->RectColor_combobox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->RectColor_combobox->DropDownWidth = 150;
			this->RectColor_combobox->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->RectColor_combobox->FormattingEnabled = true;
			this->RectColor_combobox->IntegralHeight = false;
			this->RectColor_combobox->Location = System::Drawing::Point(59, 98);
			this->RectColor_combobox->Name = L"RectColor_combobox";
			this->RectColor_combobox->Size = System::Drawing::Size(106, 24);
			this->RectColor_combobox->TabIndex = 11;
			// 
			// RectColor_label
			// 
			this->RectColor_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->RectColor_label->Location = System::Drawing::Point(6, 98);
			this->RectColor_label->Name = L"RectColor_label";
			this->RectColor_label->Size = System::Drawing::Size(54, 23);
			this->RectColor_label->TabIndex = 12;
			this->RectColor_label->Text = L"顏色: ";
			// 
			// square_checkbox
			// 
			this->square_checkbox->AutoSize = true;
			this->square_checkbox->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->square_checkbox->Location = System::Drawing::Point(10, 6);
			this->square_checkbox->Name = L"square_checkbox";
			this->square_checkbox->Size = System::Drawing::Size(78, 20);
			this->square_checkbox->TabIndex = 9;
			this->square_checkbox->Text = L"正方形";
			this->square_checkbox->UseVisualStyleBackColor = true;
			this->square_checkbox->CheckedChanged += gcnew System::EventHandler(this, &Form1::square_checkbox_CheckedChanged);
			// 
			// width_label
			// 
			this->width_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->width_label->Location = System::Drawing::Point(6, 64);
			this->width_label->Name = L"width_label";
			this->width_label->Size = System::Drawing::Size(35, 23);
			this->width_label->TabIndex = 7;
			this->width_label->Text = L"寬: ";
			// 
			// length_label
			// 
			this->length_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->length_label->Location = System::Drawing::Point(6, 29);
			this->length_label->Name = L"length_label";
			this->length_label->Size = System::Drawing::Size(35, 23);
			this->length_label->TabIndex = 5;
			this->length_label->Text = L"長: ";
			// 
			// Rect_fill
			// 
			this->Rect_fill->AutoSize = true;
			this->Rect_fill->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Rect_fill->Location = System::Drawing::Point(174, 132);
			this->Rect_fill->Name = L"Rect_fill";
			this->Rect_fill->Size = System::Drawing::Size(61, 20);
			this->Rect_fill->TabIndex = 4;
			this->Rect_fill->Text = L"填滿";
			this->Rect_fill->UseVisualStyleBackColor = true;
			// 
			// circle
			// 
			this->circle->BackColor = System::Drawing::Color::Silver;
			this->circle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->circle->Controls->Add(this->CircleColor_combobox);
			this->circle->Controls->Add(this->CircleColor_label);
			this->circle->Controls->Add(this->Radius_input);
			this->circle->Controls->Add(this->Radius_label);
			this->circle->Controls->Add(this->Cirlcle_fill);
			this->circle->Location = System::Drawing::Point(4, 26);
			this->circle->Name = L"circle";
			this->circle->Padding = System::Windows::Forms::Padding(3);
			this->circle->Size = System::Drawing::Size(243, 240);
			this->circle->TabIndex = 0;
			this->circle->Text = L"圓形";
			// 
			// CircleColor_combobox
			// 
			this->CircleColor_combobox->DropDownHeight = 50;
			this->CircleColor_combobox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CircleColor_combobox->DropDownWidth = 150;
			this->CircleColor_combobox->FormattingEnabled = true;
			this->CircleColor_combobox->IntegralHeight = false;
			this->CircleColor_combobox->Location = System::Drawing::Point(59, 74);
			this->CircleColor_combobox->Name = L"CircleColor_combobox";
			this->CircleColor_combobox->Size = System::Drawing::Size(113, 24);
			this->CircleColor_combobox->TabIndex = 9;
			// 
			// CircleColor_label
			// 
			this->CircleColor_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->CircleColor_label->Location = System::Drawing::Point(6, 74);
			this->CircleColor_label->Name = L"CircleColor_label";
			this->CircleColor_label->Size = System::Drawing::Size(61, 23);
			this->CircleColor_label->TabIndex = 10;
			this->CircleColor_label->Text = L"顏色: ";
			// 
			// Radius_label
			// 
			this->Radius_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Radius_label->Location = System::Drawing::Point(6, 29);
			this->Radius_label->Name = L"Radius_label";
			this->Radius_label->Size = System::Drawing::Size(61, 23);
			this->Radius_label->TabIndex = 7;
			this->Radius_label->Text = L"半徑: ";
			// 
			// Cirlcle_fill
			// 
			this->Cirlcle_fill->AutoSize = true;
			this->Cirlcle_fill->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Cirlcle_fill->Location = System::Drawing::Point(174, 104);
			this->Cirlcle_fill->Name = L"Cirlcle_fill";
			this->Cirlcle_fill->Size = System::Drawing::Size(61, 20);
			this->Cirlcle_fill->TabIndex = 5;
			this->Cirlcle_fill->Text = L"填滿";
			this->Cirlcle_fill->UseVisualStyleBackColor = true;
			// 
			// cube
			// 
			this->cube->BackColor = System::Drawing::Color::Silver;
			this->cube->Controls->Add(this->CubeColor_combobox);
			this->cube->Controls->Add(this->CubeColor_label);
			this->cube->Controls->Add(this->cube_checkBox);
			this->cube->Controls->Add(this->CubeHeight_input);
			this->cube->Controls->Add(this->CubeHeight_label);
			this->cube->Controls->Add(this->CubeWidth_input);
			this->cube->Controls->Add(this->CubeWidth_label);
			this->cube->Controls->Add(this->CubeLength_input);
			this->cube->Controls->Add(this->CubeLength_label);
			this->cube->Location = System::Drawing::Point(4, 26);
			this->cube->Name = L"cube";
			this->cube->Size = System::Drawing::Size(243, 240);
			this->cube->TabIndex = 2;
			this->cube->Text = L"立方體";
			// 
			// CubeColor_combobox
			// 
			this->CubeColor_combobox->DropDownHeight = 50;
			this->CubeColor_combobox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CubeColor_combobox->DropDownWidth = 150;
			this->CubeColor_combobox->FormattingEnabled = true;
			this->CubeColor_combobox->IntegralHeight = false;
			this->CubeColor_combobox->Location = System::Drawing::Point(57, 151);
			this->CubeColor_combobox->Name = L"CubeColor_combobox";
			this->CubeColor_combobox->Size = System::Drawing::Size(116, 24);
			this->CubeColor_combobox->TabIndex = 14;
			// 
			// CubeColor_label
			// 
			this->CubeColor_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->CubeColor_label->Location = System::Drawing::Point(4, 151);
			this->CubeColor_label->Name = L"CubeColor_label";
			this->CubeColor_label->Size = System::Drawing::Size(61, 23);
			this->CubeColor_label->TabIndex = 15;
			this->CubeColor_label->Text = L"顏色: ";
			// 
			// cube_checkBox
			// 
			this->cube_checkBox->AutoSize = true;
			this->cube_checkBox->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->cube_checkBox->Location = System::Drawing::Point(8, 8);
			this->cube_checkBox->Name = L"cube_checkBox";
			this->cube_checkBox->Size = System::Drawing::Size(95, 20);
			this->cube_checkBox->TabIndex = 13;
			this->cube_checkBox->Text = L"正立方體";
			this->cube_checkBox->UseVisualStyleBackColor = true;
			this->cube_checkBox->CheckedChanged += gcnew System::EventHandler(this, &Form1::cube_checkBox_CheckedChanged);
			// 
			// CubeHeight_label
			// 
			this->CubeHeight_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->CubeHeight_label->Location = System::Drawing::Point(3, 108);
			this->CubeHeight_label->Name = L"CubeHeight_label";
			this->CubeHeight_label->Size = System::Drawing::Size(35, 23);
			this->CubeHeight_label->TabIndex = 11;
			this->CubeHeight_label->Text = L"高: ";
			// 
			// CubeWidth_label
			// 
			this->CubeWidth_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->CubeWidth_label->Location = System::Drawing::Point(3, 70);
			this->CubeWidth_label->Name = L"CubeWidth_label";
			this->CubeWidth_label->Size = System::Drawing::Size(35, 23);
			this->CubeWidth_label->TabIndex = 9;
			this->CubeWidth_label->Text = L"寬: ";
			// 
			// CubeLength_label
			// 
			this->CubeLength_label->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->CubeLength_label->Location = System::Drawing::Point(4, 33);
			this->CubeLength_label->Name = L"CubeLength_label";
			this->CubeLength_label->Size = System::Drawing::Size(35, 23);
			this->CubeLength_label->TabIndex = 7;
			this->CubeLength_label->Text = L"長: ";
			// 
			// compute_num
			// 
			this->compute_num->BackColor = System::Drawing::Color::Silver;
			this->compute_num->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->compute_num->Controls->Add(this->volume_num);
			this->compute_num->Controls->Add(this->volume_label);
			this->compute_num->Controls->Add(this->Area_num);
			this->compute_num->Controls->Add(this->Area_label);
			this->compute_num->Location = System::Drawing::Point(16, 321);
			this->compute_num->Name = L"compute_num";
			this->compute_num->Size = System::Drawing::Size(243, 141);
			this->compute_num->TabIndex = 1;
			// 
			// volume_num
			// 
			this->volume_num->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->volume_num->Location = System::Drawing::Point(3, 89);
			this->volume_num->Name = L"volume_num";
			this->volume_num->Size = System::Drawing::Size(169, 19);
			this->volume_num->TabIndex = 3;
			this->volume_num->Text = L"None";
			// 
			// volume_label
			// 
			this->volume_label->AutoSize = true;
			this->volume_label->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->volume_label->Location = System::Drawing::Point(3, 70);
			this->volume_label->Name = L"volume_label";
			this->volume_label->Size = System::Drawing::Size(119, 19);
			this->volume_label->TabIndex = 2;
			this->volume_label->Text = L"體積 / 周長: ";
			// 
			// Area_num
			// 
			this->Area_num->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Area_num->Location = System::Drawing::Point(3, 29);
			this->Area_num->Name = L"Area_num";
			this->Area_num->Size = System::Drawing::Size(239, 19);
			this->Area_num->TabIndex = 1;
			this->Area_num->Text = L"None";
			// 
			// Area_label
			// 
			this->Area_label->AutoSize = true;
			this->Area_label->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Area_label->Location = System::Drawing::Point(3, 10);
			this->Area_label->Name = L"Area_label";
			this->Area_label->Size = System::Drawing::Size(139, 19);
			this->Area_label->TabIndex = 0;
			this->Area_label->Text = L"面積 / 表面積: ";
			// 
			// Drawing_paper
			// 
			this->Drawing_paper->AutoScroll = true;
			this->Drawing_paper->BackColor = System::Drawing::Color::White;
			this->Drawing_paper->Location = System::Drawing::Point(275, 38);
			this->Drawing_paper->Name = L"Drawing_paper";
			this->Drawing_paper->Size = System::Drawing::Size(522, 424);
			this->Drawing_paper->TabIndex = 2;
			// 
			// produce_shape_Btn
			// 
			this->produce_shape_Btn->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->produce_shape_Btn->Location = System::Drawing::Point(171, 288);
			this->produce_shape_Btn->Name = L"produce_shape_Btn";
			this->produce_shape_Btn->Size = System::Drawing::Size(88, 27);
			this->produce_shape_Btn->TabIndex = 3;
			this->produce_shape_Btn->Text = L"產生圖形";
			this->produce_shape_Btn->UseVisualStyleBackColor = true;
			this->produce_shape_Btn->Click += gcnew System::EventHandler(this, &Form1::produce_shape_Btn_Click);
			// 
			// current_shape
			// 
			this->current_shape->AutoSize = true;
			this->current_shape->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->current_shape->Location = System::Drawing::Point(272, 19);
			this->current_shape->Name = L"current_shape";
			this->current_shape->Size = System::Drawing::Size(124, 16);
			this->current_shape->TabIndex = 4;
			this->current_shape->Text = L"現在圖形: None";
			// 
			// update
			// 
			this->update->AutoSize = true;
			this->update->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->update->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->update->Location = System::Drawing::Point(55, 293);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(110, 16);
			this->update->TabIndex = 5;
			this->update->Text = L"按下按鈕更新";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(809, 477);
			this->Controls->Add(this->update);
			this->Controls->Add(this->current_shape);
			this->Controls->Add(this->produce_shape_Btn);
			this->Controls->Add(this->Drawing_paper);
			this->Controls->Add(this->compute_num);
			this->Controls->Add(this->select_shape);
			this->Name = L"Form1";
			this->Text = L"就只是畫圖";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->select_shape->ResumeLayout(false);
			this->rectangle->ResumeLayout(false);
			this->rectangle->PerformLayout();
			this->circle->ResumeLayout(false);
			this->circle->PerformLayout();
			this->cube->ResumeLayout(false);
			this->cube->PerformLayout();
			this->compute_num->ResumeLayout(false);
			this->compute_num->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	static int shape = 0;
	static bool change = false;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				mygraphics = Drawing_paper->CreateGraphics();
				myPen = gcnew Pen(Color::Black ,2);
				myBrush = gcnew SolidBrush(Color::Crimson);
				///////////////

				for(int i = 0 ; i < TheColor::getArrayNum() ; i++ )
				{
					RectColor_combobox->Items->  Add( TheColor::getOneOfArray(i) );		
					CircleColor_combobox->Items->Add( TheColor::getOneOfArray(i) );
					CubeColor_combobox->Items->  Add( TheColor::getOneOfArray(i) );
				}

			    RectColor_combobox->SelectedIndex = 0;
				CircleColor_combobox->SelectedIndex = 0;
				CubeColor_combobox->SelectedIndex = 0;

				length_input->Text = r.getLength().ToString();
				width_input->Text  = r.getWidth().ToString();
				
				Radius_input->Text = c.getRadius().ToString();

				CubeLength_input->Text = cu.getLength().ToString();
				CubeWidth_input->Text  = cu.getWidth().ToString();
				CubeHeight_input->Text = cu.getHeight().ToString();
			 } 
	private: System::Void input_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
			 {
				 if( !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 )
				 {
					e->Handled = true;
				 }
			 }
 	private: System::Void input_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
			 {
				 if( e->KeyCode == Keys::Delete || e->KeyCode == Keys::Back )
				 {
					change = false;
				 }
				 else change = true;
			 } 
	private: System::Void input_TextChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( change )
				 {
					 length_input->Text = Convert::ToInt32(length_input->Text).ToString();
					 width_input->Text  = Convert::ToInt32(width_input->Text ).ToString();

					 Radius_input->Text = Convert::ToInt32(Radius_input->Text).ToString();
					// Radius_input->SelectionStart = Radius_input->Text->Length;

					 CubeLength_input->Text = Convert::ToInt32(CubeLength_input->Text).ToString();
					 CubeWidth_input->Text  = Convert::ToInt32(CubeWidth_input->Text ).ToString();
					 CubeHeight_input->Text = Convert::ToInt32(CubeHeight_input->Text).ToString();

					 if( Convert::ToInt32(length_input->Text) > 400)
					 {
						length_input->Text = "400";
					 }
 					 else if( Convert::ToInt32(width_input->Text) > 400)
					 {
						width_input->Text = "400";
					 }
					 else if( Convert::ToInt32(Radius_input->Text) > 200)
					 {
						Radius_input->Text = "200";
					 }
					 else if( Convert::ToInt32(CubeLength_input->Text) > 200)
					 {
						CubeLength_input->Text = "200";
					 }
					 else if( Convert::ToInt32(CubeWidth_input->Text) > 200)
					 {
						CubeWidth_input->Text = "200";
					 }
					 else if( Convert::ToInt32(CubeHeight_input->Text) > 200)
					 {
						CubeHeight_input->Text = "200";
					 }
				 }			 

				 if( width_input->ReadOnly )
				 {
					width_input->Text = length_input->Text;
				 }
 				 if( CubeWidth_input->ReadOnly )
				 {
					 CubeWidth_input->Text  = CubeLength_input->Text;
					 CubeHeight_input->Text = CubeLength_input->Text;
				 }
			 }
	private: System::Void square_checkbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( square_checkbox->CheckState == CheckState::Checked )
				 {
					 width_input->ReadOnly = true;
					 width_input->BackColor = Color::Silver;

					 width_input->Text = length_input->Text;
				 }
				 else
				 {
					 width_input->ReadOnly = false;
					 width_input->BackColor = Color::White;
				 }
			 }	
	private: System::Void cube_checkBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( cube_checkBox->CheckState == CheckState::Checked )
				 {
					 CubeWidth_input ->ReadOnly = true;
					 CubeHeight_input->ReadOnly = true;

					 CubeWidth_input ->BackColor = Color::Silver;
					 CubeHeight_input->BackColor = Color::Silver;

					 CubeWidth_input ->Text = CubeLength_input->Text;
					 CubeHeight_input->Text = CubeLength_input->Text;
				 }
				 else
				 {
					 CubeWidth_input->ReadOnly  = false;
					 CubeHeight_input->ReadOnly = false;

					 CubeWidth_input->BackColor  = Color::White;
					 CubeHeight_input->BackColor = Color::White;
				 }
			 }
	private: System::Void select_shape_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
			    saveData();

				shape = select_shape->SelectedIndex;
			 }
	private: System::Void produce_shape_Btn_Click(System::Object^  sender, System::EventArgs^  e) 
			 {				 
				 saveData();				 
				 compute();
				 Drawing();
			 }
 /*=========================================================================================================*/
	 private: void compute()
			  {
				  if( shape <= 1)
				  {
					  Area_label->Text   = "面積:";
					  volume_label->Text = "周長:";
				  }
				  else
				  {
					  Area_label->Text   = "表面積:";
					  volume_label->Text = "體積:";
				  }
				  switch( shape )
				  {
				  case 0 :
					Area_num->Text = r.getArea().ToString();
					volume_num->Text = r.getperimeter().ToString();
					break;
				  case 1 :
					Area_num->Text = c.getArea().ToString();
					volume_num->Text = c.getperimeter().ToString();
					break;					
				  case 2 :
					Area_num->Text = cu.getSurfaceArea().ToString();
					volume_num->Text = cu.getVolume().ToString();
					break;

				  default:
					 break;
				  }
			  }
	 private: void Drawing()
			  {
			     current_shape->Text = getSelectTab();
				 mygraphics->Clear(Color::White);

				  switch( shape )
				  {
					  case 0:
						  if(  Rect_fill->CheckState == CheckState::Checked ) 
						  {
							myBrush->Color = r.getColor();
							mygraphics->FillRectangle(myBrush ,10 ,10 ,r.getLength() ,r.getWidth() );						
						  }
						  else 
						  {
							myPen->Color = r.getColor();
							mygraphics->DrawRectangle(myPen ,10 ,10 ,r.getLength() ,r.getWidth()  );
						  }
						  break;

					  case 1:
						  if( Cirlcle_fill->CheckState == CheckState::Checked ) 
						  {
							myBrush->Color = c.getColor();
							mygraphics->FillEllipse(myBrush ,10 ,10 ,c.getRadius() * 2 ,c.getRadius() * 2 );
						  }
						  else 
						  {
							myPen->Color = c.getColor();
							mygraphics->DrawEllipse(myPen ,10 ,10 ,c.getRadius() * 2 ,c.getRadius() * 2 );		
						  }		
						  break;

					  case 2:				  												  
						  DrawingCube();
						  break;

					  default:
						  break;
				  }	

			  }
	 private: void DrawingCube()
			  {
				  ThePoint();

				  myPen->Color = cu.getColor();
				  myPen->Width = 2;
				  mygraphics->DrawLines(myPen ,points_top);

				  for(int i = 1 ; i < 4 ; i++)
				  {
					mygraphics->DrawLine(myPen , points_top[i] ,points_under[i]);
				  }
				  for(int i = 1 ; i <= 2 ; i++)
				  {
					mygraphics->DrawLine(myPen , points_under[i] ,points_under[i+1]);
				  }
				  ///////////////內部///////////////////////////
				  myPen->Width = 1;
				  mygraphics->DrawLine(myPen , points_top[0] ,points_under[0]);
				  mygraphics->DrawLine(myPen , points_under[0] ,points_under[1]);
				  mygraphics->DrawLine(myPen , points_under[3] ,points_under[4]);
				  /////////////////////////////////////////////				  
			  }
	 private: void ThePoint()
			  {
					points_top[0] = Point(150 ,10);
					points_top[1] = Point( points_top[0].X + cu.getLength() ,points_top[0].Y );
					points_top[2] = Point( points_top[1].X - cu.getWidth() * Math::Abs(Math::Sin(10)),   
										   points_top[1].Y + cu.getWidth() * Math::Abs(Math::Cos(10)) ); 
					points_top[3] = Point( points_top[2].X - cu.getLength() ,points_top[2].Y );
					points_top[4] = Point(150 ,10);

					for( int i = 0 ; i < 5 ; i++)
					{
						points_under[i] = Point( points_top[i].X ,points_top[i].Y + cu.getHeight() );
					}
			  }
	 private: void saveData()//////////////////////
			  {
				if( shape == 0 )
				{
					if( length_input->Text != "") r.setLength( Convert::ToInt32(length_input->Text) );///////////
					if( width_input->Text != "")  r.setWidth ( Convert::ToInt32(width_input->Text) );/////////////

					r.setColor( RectColor_combobox->SelectedIndex );
				}
				else if( shape == 1 )
				{
					if( Radius_input->Text != "") c.setRadius( Convert::ToInt32(Radius_input->Text) );///////////////////

					c.setColor( CircleColor_combobox->SelectedIndex );
				}
				else if( shape == 2 )
				{
					if( length_input->Text != "") cu.setLength( Convert::ToInt32(CubeLength_input->Text) );///////////
					if( width_input->Text != "")  cu.setWidth ( Convert::ToInt32(CubeWidth_input->Text) );/////////////
					if( width_input->Text != "")  cu.setHeight( Convert::ToInt32(CubeHeight_input->Text) );/////////////

					cu.setColor( CubeColor_combobox->SelectedIndex );
				}
			  }   
	 private: String^ getSelectTab()
			  {
				 String^ str = select_shape->SelectedTab->ToString();
				 int start = str->IndexOf('{') + 1;
				 int count = str->IndexOf('}') - str->IndexOf('{') - 1;

				 return "現在圖形: " + str->Substring( start ,count ); // {圓形}
			  }
    
		

};// end of "public ref class Form1"

}//end of "namespace TheShape "

