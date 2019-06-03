#pragma once
#include "DrawingEdge.h"

ref class DFSTreeDrawingEdge : public DrawingEdge
{
private:
	Pen^ PenNormalLine;
	Pen^ PenFocusLine;

	Pen^ PenNormalCurve;
	Pen^ PenFocusCurve;

	static bool paint_once;
public:
	DFSTreeDrawingEdge(Graphics^% myGraph) : DrawingEdge(myGraph)
	{
		PenNormalLine = gcnew Pen(Color::Black ,2);
		PenFocusLine  = gcnew Pen(Color::FromArgb(0, 255, 145) ,3);

		PenNormalCurve = gcnew Pen(Color::FromArgb(0, 30, 255) ,2);
		PenFocusCurve  = gcnew Pen(Color::FromArgb(255, 0, 251) ,3);

		drawEdge_Timer->Tick += gcnew System::EventHandler(this ,&DFSTreeDrawingEdge::drawEdge);		
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
		if( DrawingEdge::isUpDating(vertexEntity)|| paint_once || DFSTreeVertexEntity::isSomeFocus() ) 
		{
			myGraph->Clear(Color::White);//?
			for(int i = 0 ; i < Vertex::getVertexNum() ; i++ )
			{
				for(int j = (i+1) ; j < Vertex::getVertexNum()  ; j++ )
				{
					operation( relation[ i ,j ] ,vertexEntity[i] ,vertexEntity[j] );
				}
			}
			if( !DrawingEdge::isUpDating(vertexEntity) && paint_once )	    paint_once = false;
			else if( !DrawingEdge::isUpDating(vertexEntity) && DFSTreeVertexEntity::isSomeFocus() )
			{
				DFSTreeVertexEntity::reSeteSomeFocus();
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
				myGraph->DrawLine(PenFocusLine ,vertex1->getCenterPoint() ,vertex2->getCenterPoint() );
			}
			else 
			{
				myGraph->DrawLine(PenNormalLine ,vertex1->getCenterPoint() ,vertex2->getCenterPoint() );
			}		
		}
		else if( relation == 2 )
		{
			if( vertex1->getEntity()->Location.Y > vertex2->getEntity()->Location.Y	 )
			{
				VertexEntity^ temp = vertex1;
				vertex1 = vertex2;
				vertex2 = temp;
			}
			if( vertex1->isFocus() || vertex2->isFocus() ) 
			{
				myGraph->DrawCurve(PenFocusCurve ,calculateCurve(vertex1->getCenterPoint() ,vertex2->getCenterPoint()) );
			}
			else 
			{
				myGraph->DrawCurve(PenNormalCurve ,calculateCurve(vertex1->getCenterPoint() ,vertex2->getCenterPoint()) );
			}	
		}
	}
	array<PointF>^ calculateCurve(Point point1 ,Point point2)
	{
		PointF center = PointF((point1.X + point2.X) / 2.0 ,(point1.Y + point2.Y) /2.0 );
		double R = Math::Sqrt( Math::Pow((point1.X - point2.X) ,2) + Math::Pow((point1.Y - point2.Y) ,2) ) / 2;
		
		double point1_Degree = Math::Atan2( (point1.Y - center.Y) ,(point1.X - center.X) );
		double point2_Degree = Math::Atan2( (point2.Y - center.Y) ,(point2.X - center.X) );

		double point1_angel = point1_Degree * (180.0 / Math::PI);
		double point2_angel = point2_Degree * (180.0 / Math::PI);

		double angel;
		double degree;

		int Fragment = Math::Abs(point1_angel - point2_angel) / 3; //+ 2;

		array<PointF>^ points = gcnew array<PointF>(Fragment);
		//points[0] = point1;
		for(int i = 0 ; i < Fragment ; i++)
		{
			angel  = point1_angel + i * 3.0;
			degree = angel * (Math::PI / 180.0);

			points[i] = PointF( center.X + R * Math::Cos(degree) ,center.Y + R * Math::Sin(degree) );
		}
		//points[Fragment-1] = point2;

		return points;
	}
};
