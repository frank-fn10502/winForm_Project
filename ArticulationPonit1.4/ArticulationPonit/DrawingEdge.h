#pragma once
#include "GraphVertexEntity.h"
#include "DFSTreeVertexEntity.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class DrawingEdge
{
protected:
	array<int,2>^ relation;
	array<VertexEntity^>^ vertexEntity;
	Graphics^ myGraph;

	Timer^ drawEdge_Timer;
	
	static bool update;
public:
	static bool isUpDating(array<VertexEntity^>^ vertexEntity)
	{
		VertexEntity^ temp = vertexEntity[0];
		if( temp->GetType() == GraphVertexEntity::typeid )
		{
			return GraphVertexEntity::isUpDating();
		}
		else if( temp->GetType() == DFSTreeVertexEntity::typeid )
		{
			return DFSTreeVertexEntity::isUpDating();
		}
	}
	DrawingEdge(Graphics^% myGraph)
	{
		drawEdge_Timer = gcnew Timer();
		drawEdge_Timer->Interval = 50;

		this->myGraph = myGraph;
		//paint_once = true;
	}
	virtual void start(array<int,2>^ relation ,array<VertexEntity^>^ vertexEntity){}
	void stop()
	{
		myGraph->Clear(Color::White);
		drawEdge_Timer->Enabled = false;
	}
	virtual System::Void drawEdge(Object^ sender ,EventArgs^ e){}
};
