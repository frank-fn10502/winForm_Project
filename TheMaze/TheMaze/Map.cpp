#include "StdAfx.h"
#include "Map.h"

Map::Map(int row ,int column)
{
	this->row	 = row;
	this->column = column;

	map = gcnew array<int,2>(row ,column );
}
/*======================setter=============================*/

void Map::setMap(Dot^% dot ,int item )   { map[ dot->getI() ,dot->getJ() ] = item; }
void Map::setMap(int i ,int j ,int item ){ map[ i ,j] = item; }
/*======================getter=============================*/

char Map::getPosData(Dot^% dot)	   { return map[dot->getI() ,dot->getJ()]; }
char Map::getPosData(int i ,int j ){ return map[i ,j]; }
int  Map::getRow()	  { return row;    }
int  Map::getColumn() { return column; }
/*=========================================================*/

void Map::operator=(Map^% m)
{
	for(int i = 0 ;i < this->row ; i++ )
	{
		for(int j = 0 ; j < this->column ; j++ )
		{	
			this->map[i ,j] = m->getPosData(i ,j);
		}
	}
}
bool Map::inMapArea(Dot^% dot )
{
	return !(dot->getI() < 0 || dot->getI() > row-1 ||
		     dot->getJ() < 0 || dot->getJ() > column-1 );
}
bool Map::inBorder(Dot^% dot)
{
	return (dot->getI() == 0 || dot->getI() == row-1 ||
		    dot->getJ() == 0 || dot->getJ() == column-1 );
}