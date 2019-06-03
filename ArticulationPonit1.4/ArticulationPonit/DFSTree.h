#pragma once
#include "graph.h"
#include "DFSTreeDrawingEdge.h"

ref class DFSTree : public Graph
{
private:
	array<int,2>^ tempGraphRelation;
	bool showDetail;

public:
	DFSTree(Panel^% canvas ,Graph^% graph);

	void setDetailVisible(bool);
	virtual void displayAllData() override;

	virtual LinkList<int>^ calulateArtPoint(int start) override;

private:
	void setVertexEntitiesPos(VertexEntity^ vertexEntity ,int start ,int n ,int& offset);
	void setVertexEntities();
	void setEdgeEntity();
};