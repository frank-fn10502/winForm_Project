#pragma once
#include "VertexEntity.h"
#include "GraphVertexEntity.h"
#include "DFSTreeVertexEntity.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class DisplayMethod
{
public:
	DisplayMethod(){}
	void displayCircle(Panel^ canvas ,array<VertexEntity^>^ vertexEntities)
	{
		const int R = 150;
		double degree = 360.0 / Vertex::getVertexNum();
		int midX = canvas->Size.Width  / 2;
		int midY = canvas->Size.Height / 2;
		double angel;

		int labelCenterX;
		int labelCenterY;

		for(int i = 0 ; i < Vertex::getVertexNum()  ; i++ )
		{
			canvas->Controls->Add(vertexEntities[i]->getEntity() );
			angel = (degree*i) * (Math::PI / 180.0);

			labelCenterX = midX + R * Math::Sin(angel);
			labelCenterY = midY - R * Math::Cos(angel);
			
			vertexEntities[i]->setOriginalPos(labelCenterX ,labelCenterY);
		}
	}
	void displayRetangle(Panel^ canvas ,array<VertexEntity^>^ vertexEntities)
	{
		const int width = 30 ,height = 30;
		int column = 0 ,row = 0;

		int labelhalfWidth  = vertexEntities[0]->getEntity()->Size.Width  / 2;
		int labelhalfHeight = vertexEntities[0]->getEntity()->Size.Height / 2;
		int labelX;
		int labelY;

		for(int i = 0 ; i < Vertex::getVertexNum()  ; i++ )
		{
			canvas->Controls->Add(vertexEntities[i]->getEntity() );

			if(  width + (column-i%2) * 50 + labelhalfWidth >= canvas->Size.Width )
			{
				column = 0;
				row += 2;
			}
			labelX = width  + (column-i%2) * 50				- labelhalfWidth ;
			labelY = height + (row+i%2) * 50  + row/2 * 50  - labelhalfHeight;
			column++;
			
			vertexEntities[i]->setPos(labelX ,labelY);
		}
	}
	void displayPreShape(Panel^ canvas ,array<VertexEntity^>^ vertexEntities)
	{
		for(int i = 0 ; i < Vertex::getVertexNum() ; i++ )
		{
			canvas->Controls->Add(vertexEntities[i]->getEntity() );
			canvas->Controls->Add(((DFSTreeVertexEntity^)vertexEntities[i])->getDatailEntity() );
		}
	}
};
