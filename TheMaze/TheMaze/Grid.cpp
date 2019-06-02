#include "StdAfx.h"
#include "Grid.h"

Grid::Grid(Dot^% position ,int come_dir)
{
	this->position		   = position;
	this->directionStatus  = gcnew array<int>(DIRNUM);
	for(int i = 0 ; i < DIRNUM ; i++) 
	{
		directionStatus[i] = 1;//先假設都無法行走
	}

	this->currentDirection = come_dir;
	this->nextDirection	   = ( come_dir + 1 ) % DIRNUM;
	this->checkTheWay	   = 0;
}
Grid::Grid(Dot^% position)
{
	this->position		   = position;
	this->directionStatus  = gcnew array<int>(DIRNUM);
	this->currentDirection = 0;
	this->nextDirection    = 0;//上方
	this->checkTheWay	   = 0;
}
/*======================setter=============================*/

void Grid::setCurrentDirStatus(int status)
{ 
	directionStatus[currentDirection] = status;
}
void Grid::setCurrentDir(int dir)
{ 
	currentDirection = dir; 
	checkTheWay++;
}
void Grid::setNextDir() { nextDirection = (currentDirection + 1) % DIRNUM; }
/*======================getter=============================*/

Dot^ Grid::getPosition()	   { return position; }
int	Grid::getCurrentDirStatus(){ return directionStatus[currentDirection]; }
int	Grid::getDirStatus(int i)  { return directionStatus[i]; }
int	Grid::getCurrentDir()	   { return currentDirection; }
int	Grid::getNextDir()		   { return nextDirection; }
String^ Grid::getDirName()	   { return DirName[currentDirection]; }
bool Grid::IsNoWay()//??AA?A?		 
{ 
	for(int i = 0 ; i < 4 ; i++)
	{
		if(directionStatus[i] == 0 )
		{
			return false;
		}
	}
	return (checkTheWay >= 4);//true;
}	
/*======================static function====================*/

Dot^ Grid::getForwardPosition(int dis)// 現在的點 ,前進"方向"
{
	return gcnew Dot(position->getI() + dis*row[currentDirection] 
				    ,position->getJ() + dis*column[currentDirection] );
}
int Grid::getNextComeDir()
{
	return (currentDirection + 2) % 4;
}
int Grid::getEntranceComeDir(Dot^% dot ,Map^% map)
{
	int startDir;
	if( dot->getI() == 0 )						 startDir = 0;
	else if( dot->getI() == map->getRow()-1 )	 startDir = 2;

	if( dot->getJ() == 0 )						 startDir = 3;
	else if( dot->getJ() == map->getColumn()-1 ) startDir = 1;

	return startDir;
}