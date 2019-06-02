#include "StdAfx.h"
#include "Mouse.h"

Mouse::Mouse(Maze^% maze)//�g�c���j�p(�]�t �_�l�I )
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
	power--;//���@�B ����1��q

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
		grid->setCurrentDirStatus(1);//�X�h����V
		markLastPos(false);
		stack->push( grid );
		grid = gcnew Grid(grid->getForwardPosition(1) ,grid->getNextComeDir() );//�]�w�i�Ӫ���V(4�Ӥ�V)
	
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
	map->setMap(grid->getPosition() ,Item::walkedMark );//�e�@�Ӧ�m ���L�аO
	lastPosition	 = grid->getPosition();
	lastPositionDead = dead;
}