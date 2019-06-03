#pragma once
#include "DrawingEdge.h"

ref class GrahDrawingEdge : public DrawingEdge
{
private:
	Pen^ PenNormal;
	Pen^ PenFocus;
	
	static bool paint_once;
public:
	GrahDrawingEdge(Graphics^% myGraph) : DrawingEdge(myGraph)
	{
		PenNormal = gcnew Pen(Color::Black ,2);
		PenFocus  = gcnew Pen(Color::FromArgb(0, 255, 145) ,3);

		drawEdge_Timer->Tick += gcnew System::EventHandler(this ,&GrahDrawingEdge::drawEdge);
	}
	virtual void start(array<int,2>^ relation ,array<VertexEntity^>^ vertexEntity) override
	{
		this->relation = relation;
		this->vertexEntity = vertexEntity;

		paint_once = true;
		drawEdge_Timer->Enabled = true;
	}
	static void oneMorePaint(bool oneMore){ paint_once = oneMore; }
	virtual System::Void drawEdge(Object^  sender ,EventArgs^  e)  override
	{
		if( DrawingEdge::isUpDating(vertexEntity) || paint_once || GraphVertexEntity::isSomeFocus() ) 
		{
			myGraph->Clear(Color::White);
			for(int i = 0 ; i < Vertex::getVertexNum() ; i++ )
			{
				for(int j = (i+1) ; j < Vertex::getVertexNum()  ; j++ )
				{
					operation( relation[ i ,j ] ,vertexEntity[i] ,vertexEntity[j] );
				}
			}
			if( !DrawingEdge::isUpDating(vertexEntity) && paint_once )	  paint_once = false;
			else if( !DrawingEdge::isUpDating(vertexEntity) && GraphVertexEntity::isSomeFocus() )
			{
				GraphVertexEntity::reSeteSomeFocus();
			}
			else if( DrawingEdge::isUpDating(vertexEntity) && !paint_once ) paint_once = true;
		}
	}
private:
	void operation(int relation ,VertexEntity^ vertex1 ,VertexEntity^ vertex2)
	{
		if( relation == 1 )
		{
			if( vertex1->isFocus() || vertex2->isFocus() ) 
			{
				myGraph->DrawLine(PenFocus ,vertex1->getCenterPoint() ,vertex2->getCenterPoint() );
			}
			else 
			{
				myGraph->DrawLine(PenNormal ,vertex1->getCenterPoint() ,vertex2->getCenterPoint() );
			}		
		}
	}
};
