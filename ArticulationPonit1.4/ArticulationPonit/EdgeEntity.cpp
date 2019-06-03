#include "StdAfx.h"
#include "EdgeEntity.h"

EdgeEntity::EdgeEntity(array<VertexEntity^>^ vertexEntity ,DrawingEdge^ drawingEdge ,int num) : Edge(num)
{
	this->vertexEntity = vertexEntity;
	this->drawingEdge = drawingEdge;
}
void EdgeEntity::clearAllData()
{
	drawingEdge->stop();
}
void EdgeEntity::repaint()
{
	//drawingEdge->oneMorePaint(true);
	if( drawingEdge->GetType() == GrahDrawingEdge::typeid )
	{
		GrahDrawingEdge::oneMorePaint(true);
	}
	else if( drawingEdge->GetType() == DFSTreeDrawingEdge::typeid )
	{
		DFSTreeDrawingEdge::oneMorePaint(true);
	}
}
void EdgeEntity::displayEdgeEntityOnBoard()
{
	drawingEdge->start(relation ,vertexEntity);
}
