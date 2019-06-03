#include "StdAfx.h"
#include "DFSTree.h"

DFSTree::DFSTree(Panel^% canvas ,Graph^% graph)
{
	this->canvas = canvas;
	tempGraphRelation = graph->getEdgeEntity()->getAllRelation();/////
	showDetail = false;

	setVertexEntities();
	setEdgeEntity();
}
void DFSTree::setDetailVisible(bool vis)
{
	showDetail = vis;
	for(int i = 0 ; i < Vertex::getVertexNum() ; i++)
	{
		((DFSTreeVertexEntity^)vertexEntities[i])->detailVisible(showDetail);
	}
}
void DFSTree::displayAllData()
{
	vertexEntities->getDisplayMethod()->displayPreShape(canvas ,vertexEntities->getVertices() );
	edgeEntity->displayEdgeEntityOnBoard();
}
LinkList<int>^ DFSTree::calulateArtPoint(int start)
{
	setVertexEntities();
	setEdgeEntity();

	int n = 0;
	int u = start,v = -1;
	int w = 0,child = 0;
	int offset = 0;
	int h = 0;

	LinkList<int>^ artPoints = gcnew LinkList<int>();
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
					artPoints->insert(vertexEntities[u]->getName());
			}
			else if(vertexEntities[w]->getLow() >= vertexEntities[u]->getDfn())
			{
				if(child == 2)
				{
					if( !artPoints->isExist(u) )
						artPoints->insert(vertexEntities[u]->getName());
				}
				else artPoints->insert(vertexEntities[u]->getName());		
			}
			w++;
			h--;
		}
		else
		{
			n++;
			vertexEntities[u]->setDfn(n);
			vertexEntities[u]->setLow(n);
			w = 0;
			child = 0;

			if( u == start && n == 1 )
			{
				setVertexEntitiesPos(vertexEntities[u] ,start ,h ,offset);
			}
		}


		for( ; w < VertexEntity::getVertexNum()  ; w++)
		{
			if( tempGraphRelation[u ,w] == 1 )
			{
				if( vertexEntities[w]->getDfn() == 0)
				{
					child++;
					stack->Push( gcnew VertexStatus(u ,v ,w ,child) );

					edgeEntity->setRelation(u ,w ,1);/////
					edgeEntity->setRelation(w ,u ,1);/////

					h++;
					if( child >= 2 ) offset++;

					setVertexEntitiesPos(vertexEntities[w] ,start ,h ,offset);

					v = u;
					u = w;
					break;
				}
				else if( w != v )
				{
					vertexEntities[u]->setLow( min(vertexEntities[u]->getLow() 
												  ,vertexEntities[w]->getDfn()) );
					edgeEntity->setRelation(u ,w ,2);/////2代表back edge
					edgeEntity->setRelation(w ,u ,2);/////
				}
			}		
		}
	}
	return artPoints;
}
/*-------------private---------------------------------------------*/

void DFSTree::setVertexEntitiesPos(VertexEntity^ vertexEntity ,int start ,int h ,int& offset)
{
	int basePosX = 66;//canvas->Size.Width / 4;
	if( vertexEntity->getName() == start )
	{
		vertexEntity ->setOriginalPos(basePosX , 30);
	}
	vertexEntity->setOriginalPos(basePosX + offset*(26 + 40), 30 + 40*h);
}
void DFSTree::setVertexEntities()
{
	array<DFSTreeVertexEntity^>^ tempEntities = gcnew array<DFSTreeVertexEntity^>(Vertex::getVertexNum());
	for(int i = 0 ; i < VertexEntity::getVertexNum() ; i++)
	{
		tempEntities[i] = gcnew DFSTreeVertexEntity(i ,0 ,0 ,(i+1));
		((DFSTreeVertexEntity^)tempEntities[i])->detailVisible(showDetail);/////
	}
	vertexEntities = gcnew Vertices(tempEntities);
}
void DFSTree::setEdgeEntity()
{
	edgeEntity = gcnew EdgeEntity(vertexEntities->getVertices() ,gcnew DFSTreeDrawingEdge(canvas->CreateGraphics()) ,VertexEntity::getVertexNum());
}