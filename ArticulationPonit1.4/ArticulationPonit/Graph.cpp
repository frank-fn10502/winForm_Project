#include "StdAfx.h"
#include "Graph.h"

/*=============================Graph=====================================*/
Graph::Graph(){}
Graph::Graph(Panel^% canvas ,int num)
{
	array<GraphVertexEntity^>^ tempEntities = gcnew array<GraphVertexEntity^>(num);
	for(int i = 0 ; i < num ; i++)
		tempEntities[i] = gcnew GraphVertexEntity(i ,0 ,0 ,(i+1));

	vertexEntities = gcnew Vertices(tempEntities);

	this->canvas = canvas;

	edgeEntity = gcnew EdgeEntity(tempEntities ,gcnew GrahDrawingEdge(canvas->CreateGraphics()),num);
}
void Graph::displayRetangle()
{
	vertexEntities->getDisplayMethod()->displayRetangle( canvas ,vertexEntities->getVertices() );
	edgeEntity->repaint();
}
void Graph::displayAllData()
{
	vertexEntities->getDisplayMethod()->displayCircle( canvas ,vertexEntities->getVertices() );
	edgeEntity->displayEdgeEntityOnBoard();
}
void Graph::clearAllData()
{
	canvas->Controls->Clear();
	edgeEntity->clearAllData();
}
void Graph::beginningStatus()/////
{
	for(int i = 0 ; i < Vertex::getVertexNum()  ; i++)
		vertexEntities[i]->beginningStatus();

	edgeEntity->repaint();
}
LinkList<int>^ Graph::calulateArtPoint(int start)
{
	int n = 0;
	int u = start ,v = -1;
	int w = 0 ,child = 0;

	LinkList<int>^ artPoints  = gcnew LinkList<int>();
	Stack<VertexStatus^>^ stack = gcnew Stack<VertexStatus^>();//紀錄這一點的 自己( u ) ,parent( v ) ,目前比對的點( w ) ,child數目( child ) 

	while(true)
	{
		if(w == Vertex::getVertexNum() )
		{
			if(stack->isEmpty()) break;

			VertexStatus^ save = stack->pop();
			u = save->self;
			v = save->parent;
			w = save->myChild;
			child = save->childNum;

			vertexEntities[u]->setLow( min(vertexEntities[u]->getLow() ,vertexEntities[w]->getLow()) );

			if( u == start )
			{
				if(child == 2)
					artPoints->insert(vertexEntities[u]->getName());//放進 "串列"
			}
			else if(vertexEntities[w]->getLow() >= vertexEntities[u]->getDfn())
			{
				if(child == 2)
				{
					if( !artPoints->isExist(u) )
						artPoints->insert(vertexEntities[u]->getName());//放進 "串列"
				}
				else artPoints->insert(vertexEntities[u]->getName());   //放進 "串列"			
			}
			w++;
		}
		else
		{
			n++;
			vertexEntities[u]->setDfn(n);
			vertexEntities[u]->setLow(n);
			w = 0;
			child = 0;
		}
		for( ; w < VertexEntity::getVertexNum()  ; w++)
		{
			if( edgeEntity->getRelation(u ,w) == 1)
			{
				if( vertexEntities[w]->getDfn() == 0)
				{
					child++;
					stack->Push( gcnew VertexStatus(u ,v ,w ,child) );

					v = u;
					u = w;
					break;
				}
				else if( w != v )
				{
					vertexEntities[u]->setLow( min(vertexEntities[u]->getLow() ,vertexEntities[w]->getDfn()) );
				}
			}		
		}
	}
	return artPoints;
}
