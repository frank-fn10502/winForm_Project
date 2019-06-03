#pragma once
#include "VertexEntity.h"
#include "DisplayMethod.h"

ref class Vertices
{
private:
	array<VertexEntity^>^ vertices;
	DisplayMethod^ displayMethod;

public:
	Vertices(array<VertexEntity^>^ vertices )
	{
		this->vertices = vertices;
		displayMethod  = gcnew DisplayMethod();
	}
	
	DisplayMethod^  getDisplayMethod()	{ return displayMethod; }
	array<VertexEntity^>^ getVertices()	{ return vertices;	    }
	VertexEntity^	 operator[](int n)	{ return vertices[n];   }

	void reSetVertexNum(int n)
	{
		Vertex::setVertexNum(n);
		for(int i = 0 ; i < n ; i++)
			vertices[i]->setVertex(i ,0 ,0);
	}
};
