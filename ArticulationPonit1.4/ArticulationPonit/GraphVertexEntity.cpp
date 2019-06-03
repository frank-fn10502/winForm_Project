#include "StdAfx.h"
#include "GraphVertexEntity.h"

GraphVertexEntity::GraphVertexEntity(int name ,int dfn ,int low,int num) : VertexEntity()
{
	 setVertexLabel(name ,num);
	 setVertex(name ,dfn ,low);
}
Point GraphVertexEntity::getCenterPoint()
{
	return Point( vertexLabel->Location.X + vertexLabel->Size.Width  / 2 
				, vertexLabel->Location.Y + vertexLabel->Size.Height / 2 );
}
void GraphVertexEntity::setOriginalPos(int labelCenterX ,int labelCenterY)
{
	labelX = labelCenterX - vertexLabel->Size.Width  / 2;
	labelY = labelCenterY - vertexLabel->Size.Height / 2;

	setPos(labelX ,labelY);
}
void GraphVertexEntity::setPos(int labelX ,int labelY)
{
	vertexLabel->Location = System::Drawing::Point(labelX ,labelY);
}
void GraphVertexEntity::beginningStatus()
{
	vertexLabel->Location = System::Drawing::Point(labelX ,labelY);
}
/*------------------private--------------------------------------------------------*/
System::Void GraphVertexEntity::label_MouseEnter(Object^  sender ,EventArgs^  e) 
{
	someFocus = true;
	Focus = true;
}
System::Void GraphVertexEntity::label_MouseLeave(Object^  sender ,EventArgs^  e) 
{
	someFocus = true;
	Focus = false;
}
System::Void GraphVertexEntity::label_MouseDown(Object^ sender ,MouseEventArgs^  e)
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
System::Void GraphVertexEntity::label_MouseUp(Object^  sender ,MouseEventArgs^  e)
{
	someFocus = true;
	Focus	 = true;
	updating = false;
}
System::Void GraphVertexEntity::label_MouseMove(Object^  sender ,MouseEventArgs^  e)
{
	 if( updating )
	 {
		int moveX = Cursor::Position.X - mouseOriginalX;
		int moveY = Cursor::Position.Y - mouseOriginalY;

		((Label^)sender)->Location = Point(labelOriginalX + moveX ,labelOriginalY + moveY );
	 }	
}
void GraphVertexEntity::setVertexLabel(int name ,int num)
{
	 vertexLabel = gcnew Label();
	 vertexLabel->AllowDrop = true;
	 vertexLabel->BorderStyle = BorderStyle::FixedSingle;
	 vertexLabel->Font = (gcnew System::Drawing::Font(L"·L³n¥¿¶ÂÅé",9.75F ,FontStyle::Bold ,GraphicsUnit::Point ,136) ); 
	 vertexLabel->Location = System::Drawing::Point(20 ,20);///¼È®É
	 vertexLabel->Margin = System::Windows::Forms::Padding(0);
	 vertexLabel->Name = "vertexLabel" + num;
	 vertexLabel->Size = System::Drawing::Size(26, 20);
	 vertexLabel->Text = name.ToString();
	 vertexLabel->TextAlign = ContentAlignment::MiddleCenter;

 	 vertexLabel->MouseDown += gcnew MouseEventHandler(this ,&GraphVertexEntity::label_MouseDown);	
	 vertexLabel->MouseUp   += gcnew MouseEventHandler(this ,&GraphVertexEntity::label_MouseUp);
	 vertexLabel->MouseMove += gcnew MouseEventHandler(this ,&GraphVertexEntity::label_MouseMove);	
	 vertexLabel->MouseEnter += gcnew EventHandler(this ,&GraphVertexEntity::label_MouseEnter);	
	 vertexLabel->MouseLeave += gcnew EventHandler(this ,&GraphVertexEntity::label_MouseLeave);	
}