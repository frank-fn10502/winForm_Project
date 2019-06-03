#pragma once
#include "edge.h"
#include "GrahDrawingEdge.h"
#include "DFSTreeDrawingEdge.h"

ref class EdgeEntity : public Edge
{
private:
	array<VertexEntity^>^ vertexEntity;
	DrawingEdge^ drawingEdge;

public:
	EdgeEntity(array<VertexEntity^>^ vertexEntity ,DrawingEdge^ drawingEdge ,int num);

	void clearAllData();
	void repaint();
	void displayEdgeEntityOnBoard();
};
