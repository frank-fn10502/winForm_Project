#include "StdAfx.h"
#include "DFSTreeVertexEntity.h"

DFSTreeVertexEntity::DFSTreeVertexEntity(int name ,int dfn ,int low,int num) : VertexEntity()
{
	 setVertexLabel(name ,num);
	 setDetail(num);
	 setVertex(name ,dfn ,low);
}
Point DFSTreeVertexEntity::getCenterPoint()
{
	return Point( vertexLabel->Location.X + vertexLabel->Size.Width  / 2 
				, vertexLabel->Location.Y + vertexLabel->Size.Height / 2 );
}
void DFSTreeVertexEntity::setOriginalPos(int labelCenterX ,int labelCenterY)
{
	labelX = labelCenterX - vertexLabel->Size.Width  / 2;
	labelY = labelCenterY - vertexLabel->Size.Height / 2;

	setPos(labelX ,labelY);
}
void DFSTreeVertexEntity::setPos(int labelX ,int labelY)
{
	vertexLabel->Location = System::Drawing::Point(labelX ,labelY);
	detail->Location = System::Drawing::Point(labelX - 41 ,labelY - 10);/////
}
void DFSTreeVertexEntity::beginningStatus()
{
	vertexLabel->Location = System::Drawing::Point(labelX ,labelY);
	detail->Location = Point(vertexLabel->Location.X - 41 ,vertexLabel->Location.Y - 10 );
}

/*------------------private--------------------------------------------------------*/
System::Void DFSTreeVertexEntity::label_MouseEnter(Object^  sender ,EventArgs^  e) 
{
	someFocus = true;
	Focus = true;
}
System::Void DFSTreeVertexEntity::label_MouseLeave(Object^  sender ,EventArgs^  e) 
{
	someFocus = true;
	Focus = false;
}
System::Void DFSTreeVertexEntity::label_MouseDown(Object^ sender ,MouseEventArgs^  e)
{
	 if( !updating )
	 {
		Focus	 = true;
		updating = true;
		mouseOriginalX = Cursor::Position.X;
		mouseOriginalY = Cursor::Position.Y;

		labelOriginalX = ((Label^)sender)->Location.X;
		labelOriginalY = ((Label^)sender)->Location.Y;
	 }
}
System::Void DFSTreeVertexEntity::label_MouseUp(Object^  sender ,MouseEventArgs^  e)
{
	someFocus = true;
	Focus	 = true;
	updating = false;
}
System::Void DFSTreeVertexEntity::label_MouseMove(Object^  sender ,MouseEventArgs^  e)
{
	 if( updating )
	 {
		int moveX = Cursor::Position.X - mouseOriginalX;
		int moveY = Cursor::Position.Y - mouseOriginalY;

		((Label^)sender)->Location = Point(labelOriginalX + moveX ,labelOriginalY + moveY );
		detail->Location = Point(vertexLabel->Location.X - 41 ,vertexLabel->Location.Y - 10 );
	 }	
}
void DFSTreeVertexEntity::setVertexLabel(int name ,int num)
{
	 vertexLabel = gcnew Label();
	 vertexLabel->AllowDrop = true;
	 vertexLabel->BorderStyle = BorderStyle::FixedSingle;
	 vertexLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體",9.75F ,FontStyle::Bold ,GraphicsUnit::Point ,136) ); 
	 vertexLabel->Location = System::Drawing::Point(20 ,20);///暫時
	 vertexLabel->Margin = System::Windows::Forms::Padding(0);
	 vertexLabel->Name = "vertexLabel" + num;
	 vertexLabel->Size = System::Drawing::Size(26, 20);
	 vertexLabel->Text = name.ToString();
	 vertexLabel->TextAlign = ContentAlignment::MiddleCenter;

 	 vertexLabel->MouseDown += gcnew MouseEventHandler(this ,&DFSTreeVertexEntity::label_MouseDown);	
	 vertexLabel->MouseUp   += gcnew MouseEventHandler(this ,&DFSTreeVertexEntity::label_MouseUp);
	 vertexLabel->MouseMove += gcnew MouseEventHandler(this ,&DFSTreeVertexEntity::label_MouseMove);	
 	 vertexLabel->MouseEnter += gcnew EventHandler(this ,&DFSTreeVertexEntity::label_MouseEnter);	
	 vertexLabel->MouseLeave += gcnew EventHandler(this ,&DFSTreeVertexEntity::label_MouseLeave);
}
void DFSTreeVertexEntity::setDetail(int num)
{
	setVertexDfn(num);
	setVertexLow(num);
	setSlash(num);

	detail = gcnew Panel();
	detail->Controls->Add(vertexDfn);
	detail->Controls->Add(vertexLow);
	detail->Controls->Add(slash);
	slash->BringToFront();

	detail->Size = System::Drawing::Size(40, 20);
	//detail->Location = System::Drawing::Point(30, 154);/////
	detail->Name = "detail" + num;

	detail->Visible = false;
}
void DFSTreeVertexEntity::setVertexDfn(int num)
{
	vertexDfn = gcnew Label();
	vertexDfn->Font = (gcnew System::Drawing::Font(L"細明體" ,8.25F ,FontStyle::Regular ,GraphicsUnit::Point ,136) );
	vertexDfn->Margin = System::Windows::Forms::Padding(0);	
	vertexDfn->Size = System::Drawing::Size(20, 20);	
	vertexDfn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

	vertexDfn->Location = System::Drawing::Point(20, 0);
	vertexDfn->Name = "vertexDfn" + num;
}
void DFSTreeVertexEntity::setVertexLow(int num)
{
	vertexLow = gcnew Label();
	vertexLow->Font = (gcnew System::Drawing::Font(L"細明體" ,8.25F ,FontStyle::Regular ,GraphicsUnit::Point ,136) );
	vertexLow->Margin = System::Windows::Forms::Padding(0);
	vertexLow->Size = System::Drawing::Size(20, 20);	
	vertexLow->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

	vertexLow->ForeColor= Color::FromArgb(0, 192, 192);
	vertexLow->Location = System::Drawing::Point(0, 0);
	vertexLow->Name = "vertexLow" + num;
}
void DFSTreeVertexEntity::setSlash(int num)
{
	slash = gcnew Label();
	slash->Font = (gcnew System::Drawing::Font(L"細明體",8.25F ,FontStyle::Regular ,GraphicsUnit::Point ,136) );
	slash->Margin = System::Windows::Forms::Padding(0);
	slash->Size = System::Drawing::Size(8, 20);
	slash->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	
	slash->Location = System::Drawing::Point(15, 0);
	slash->Name = "slash" + num;
	slash->Text = "/";
}