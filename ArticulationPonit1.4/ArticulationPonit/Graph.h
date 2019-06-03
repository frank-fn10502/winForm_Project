#pragma once
#include "LinkList.h"
#include "Stack.h"
#include "Vertices.h"
#include "VertexEntity.h"
#include "EdgeEntity.h"
#include "GrahDrawingEdge.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class Graph
{
protected:
	Vertices^ vertexEntities;
	EdgeEntity^ edgeEntity;

	Panel^ canvas;

	ref struct VertexStatus
	{
		int self;
		int parent;
		int myChild;
		int childNum;

		VertexStatus(int u ,int v ,int w ,int c)
		{
			self = u;
			parent = v;
			myChild = w;
			childNum = c;
		}
	};

public:
	Graph();
	Graph(Panel^% canvas ,int);

	Vertices^   getVertexEntities() { return vertexEntities; }
	EdgeEntity^ getEdgeEntity()		{ return edgeEntity;	 }
	

	void displayRetangle();
	virtual void displayAllData();
	void clearAllData();
	void beginningStatus();

	virtual LinkList<int>^ calulateArtPoint(int);

protected:
	int min(int a ,int b){ return (a <= b) ? a : b; }
};
