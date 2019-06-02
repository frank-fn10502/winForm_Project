#include "StdAfx.h"
#include "Mouse.h"

Mouse::Mouse(Maze^% maze)//迷宮的大小(包含 起始點 )
{
	this->power	= MAXPOWER;		
	this->stack	= gcnew GridStack(maze->getMazeMap()->getRow() * maze->getMazeMap()->getColumn() );
	this->grid	= gcnew Grid( maze->getEntrance() ,Grid::getEntranceComeDir(maze->getEntrance() ,maze->getMazeMap()) );	
	this->lastPosition	   = nullptr;
	this->lastPositionDead = false;

	this->map = maze->getMazeMap();
}
/*======================getter=============================*/

int	 Mouse::getPower()		 { return power;			}
Grid^Mouse::getCurrentGrid() { return grid;				}
Dot^ Mouse::getLastPos()	 { return lastPosition;		}
bool Mouse::getLastPosDead() { return lastPositionDead; }
/*======================function===========================*/

void Mouse::usePower()
{ 
	power--;//走一步 消耗1能量

	char item = map->getPosData(grid->getPosition());
	if( Item::isEnergy(item))
	{
		power += Item::getPower(item);
	}
}
bool Mouse::move()
{
	if( grid->IsNoWay() )
	{
		markLastPos(true);
		grid = stack->pop();
		if(grid != nullptr)					
		{
			usePower();
			return true;
		}
	}
	else if( grid->getCurrentDirStatus() == 0 )
	{
		grid->setCurrentDirStatus(1);//出去的方向
		markLastPos(false);
		stack->push( grid );
		grid = gcnew Grid(grid->getForwardPosition(1) ,grid->getNextComeDir() );//設定進來的方向(4個方向)
	
		usePower();
		return true;
	}
	return false;
}
void Mouse::findDirection()
{
	grid->setCurrentDir( grid->getNextDir() );

	Dot^ nextPosition = grid->getForwardPosition(1);

	if( !map->inMapArea(nextPosition) )
	{
		grid->setCurrentDirStatus(1);
	}
	else
	{
		if( map->getPosData( nextPosition ) != Item::wallSymbol && 
			map->getPosData( nextPosition ) != Item::walkedMark ) 
		{
			grid->setCurrentDirStatus(0);
		}
	}

	grid->setNextDir();
}
/*======================private function===================*/

void Mouse::markLastPos(bool dead)
{
	map->setMap(grid->getPosition() ,Item::walkedMark );//前一個位置 走過標記
	lastPosition	 = grid->getPosition();
	lastPositionDead = dead;
}