#pragma once
#include "vertex.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class VertexEntity : public Vertex
{
protected:
	static int mouseOriginalX = 0 ,mouseOriginalY = 0;
	static int labelOriginalX = 0 ,labelOriginalY = 0;
	int labelX ,labelY;
	bool Focus;

public:
	VertexEntity(){ Focus = false; }

	bool isFocus(){ return Focus; }

	virtual Label^ getEntity(){ return nullptr; }
	virtual Point getCenterPoint(){ return Point(0,0);}
	virtual void setOriginalPos(int labelCenterX ,int labelCenterY){}
	virtual void setPos(int labelX ,int labelY){}
	virtual void beginningStatus(){}
};
