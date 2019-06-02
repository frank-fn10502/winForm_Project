#include "StdAfx.h"
#include "Maze.h"

Maze::Maze(String^% file_name)
{
	entrance = nullptr;
	exit	 = nullptr;
	setMazeNameByTxt(file_name);
	setMazeByTxt(file_name);	
	findEnrance_Exit();
}
Maze::Maze(Map^% map)
{
	entrance = nullptr;
	exit	 = nullptr;
	originalMap = map;
	mazeMap     = gcnew Map( map->getRow() ,map->getColumn() );
	mazeMap->operator = (originalMap);
	mazeName = "�t�Υͦ�";	
	findEnrance_Exit();
}
/*======================getter=============================*/

Map^    Maze::getOriginalMap(){ return originalMap; }
Map^    Maze::getMazeMap()	  { return mazeMap;		}
Dot^    Maze::getEntrance()	  { return entrance;	}
Dot^    Maze::getExit()		  { return exit;		}
String^ Maze::getMazeName()	  { return mazeName;	}
/*=========================================================*/

void Maze::reSetMazeMap()
{
	mazeMap->operator=(originalMap);
}
/*======================private function===================*/

void Maze::setMazeByTxt(String^% file_name)
{
	StreamReader ^ sr = gcnew StreamReader(file_name ,System::Text::Encoding::ASCII);
	String^ str = "";
	String^ temp_str;

	int temp_row = 0;
	while( (temp_str = sr->ReadLine()) != nullptr )
	{ 
		str += temp_str->Trim(); 
		if(temp_str != "") temp_row++;
	}
	sr->Close();

	int row	   = temp_row;
	int column = str->Length / row;

	setMaze(row ,column ,str);
}
void Maze::setMaze(int row ,int column ,String^% str)
{
	originalMap = gcnew Map( row ,column );
	mazeMap     = gcnew Map( row ,column );

	for(int i = 0 ,k = 0 ;i < originalMap->getRow() ; i++ )
	{
		for(int j = 0 ; j < originalMap->getColumn() ; j++ ,k++ )
		{
			originalMap->setMap( i ,j ,str[k] );
		}
	}
	mazeMap->operator =(originalMap);
}
void Maze::setMazeNameByTxt(String^% fileName)
{
	array<String^>^ words = fileName->Split('\\');
	String^ word = words[words->Length-1];

	mazeName = word->Substring(0 ,word->IndexOf(".txt") );
}
void Maze::findEnrance_Exit()//���]�g�c�J�f�u�s�b�̥~��
{
	bool out = false;
	for(int i = 0 ;i < mazeMap->getRow() ; i++ )
	{
		for(int j = 0 ; j < mazeMap->getColumn() ; j++ )
		{
			if( i == 0 || i == (mazeMap->getRow()-1 ) || j == 0 || j == (mazeMap->getColumn()-1 ) )//�W�U���k
			{
				if( mazeMap->getPosData(i ,j) == '0' && entrance == nullptr )
				{
					entrance = gcnew Dot(i ,j );
				}
				else if( mazeMap->getPosData(i ,j) == Item::exitSymbol && exit == nullptr )
				{
					exit = gcnew Dot(i ,j );
				}
				if( entrance != nullptr && exit != nullptr  ) 
				{
					out = true;
					break;
				}
			}
		}
		if(out) break;
	}
}
/*=====================static function===================*/

Map^ Maze::createMap(int row ,int column)
{
	Map^ mapSimple = createMapSimple(row ,column);
	Dot^ entrance  = createEntrancePoint(row ,column);//gcnew Dot(0 ,1);//���T�w
	mapSimple->setMap(entrance ,Item::pathSymbol );

	GridStack^ stack  = gcnew GridStack(row * column);
	Grid^ currentGrid = gcnew Grid(entrance);

	int theWay;
	while(true)
	{
		setGridDirStatus(currentGrid ,mapSimple ,theWay);//�C��s�@��N���s�j���i�H������
		/*----------------------------------------*/	
		if( currentGrid->IsNoWay() )
		{
			currentGrid = stack->pop();
			if(currentGrid == nullptr) break;
		}
		else 
		{		
			setForwardDir(currentGrid ,theWay);
		
			mapSimple->setMap(currentGrid->getForwardPosition(1) ,getPosItem());
			mapSimple->setMap(currentGrid->getForwardPosition(2) ,getPosItem());
			stack->push( currentGrid );
			currentGrid = gcnew Grid(currentGrid->getForwardPosition(2));
		}
	}
	//�X�f�]�w
	Dot^ exit  = createExitPoint(row ,column ,entrance);//gcnew Dot(23 ,5);
	makeExitLink(mapSimple ,exit);
	mapSimple->setMap(exit ,Item::exitSymbol);
	
	return mapSimple;
}
Dot^ Maze::createEntrancePoint(int row ,int column)
{
	Dot^ dot;
	int dir = rand()%4;//�|����
	switch(dir)
	{
	case 0:
		dot = gcnew Dot(0 ,rand()%(column-2)+1);//�W
		break;
	case 1:
		dot = gcnew Dot(rand()%(row-2)+1 ,column-1);//�k
		break;
	case 2:
		dot = gcnew Dot(row-1 ,rand()%(column-2)+1);//�U
		break;
	case 3:
		dot = gcnew Dot(rand()%(row-2)+1 ,0 );//��
		break;
	default:
		dot = gcnew Dot(-1 ,-1 );//��
	}
	return dot;
}
Dot^ Maze::createExitPoint(int row ,int column ,Dot^% entrance)
{
	Dot^ dot;
	int dir;
	while(true)
	{
		dir = rand()%4;//�|����
		switch(dir)
		{
		case 0:
			dot = gcnew Dot(0 ,rand()%(column-2)+1);//�W
			break;
		case 1:
			dot = gcnew Dot(rand()%(row-2)+1 ,column-1);//�k
			break;
		case 2:
			dot = gcnew Dot(row-1 ,rand()%(column-2)+1);//�U
			break;
		case 3:
			dot = gcnew Dot(rand()%(row-2)+1 ,0 );//��
			break;
		default:
			dot = gcnew Dot(-1 ,-1 );//��
		}
		if(exitNotEntrance(entrance ,dot)) break;
	}
	return dot;
}
bool Maze::exitNotEntrance(Dot^% entrance,Dot^% exit)
{
	if( exit == entrance) return false;//���i���|

	Grid^ grid = gcnew Grid(exit);
	for(int i = 0 ; i < 4 ; i++ )//���i�۳s
	{
		grid->setCurrentDir( grid->getNextDir() );
		Dot^ nextPosition = grid->getForwardPosition(1);
		if( nextPosition == entrance )
		{
			return false;
		}
		grid->setNextDir();//�U�@�Ӥ�V
	}
	return true;
}
void Maze::makeExitLink(Map^% map ,Dot^% exit)
{
	Grid^ grid = gcnew Grid(exit);
	Dot^ nextPosition;
	for(int i = 0 ; i < 4 ; i++ )
	{
		grid->setCurrentDir( grid->getNextDir() );
		nextPosition = grid->getForwardPosition(1);
		if( map->inMapArea(nextPosition) && !map->inBorder(nextPosition) && 
			map->getPosData(nextPosition) == Item::wallSymbol )
		{
			map->setMap(nextPosition ,Item::pathSymbol);
			break;
		}
		grid->setNextDir();//�U�@�Ӥ�V
	}
	grid = gcnew Grid(nextPosition);
	for(int i = 0 ; i < 4 ; i++ )
	{
		grid->setCurrentDir( grid->getNextDir() );
		Dot^ nextPosition = grid->getForwardPosition(1);
		if( map->inMapArea(nextPosition) && !map->inBorder(nextPosition) && 
			map->getPosData(nextPosition) == Item::wallSymbol )
		{
			//grid->setCurrentDir(1);
			map->setMap(nextPosition ,Item::pathSymbol);
			break;
		}
		grid->setNextDir();//�U�@�Ӥ�V
	}
}
Map^ Maze::createMapSimple(int row ,int column)
{
	Map^ mapSimple = gcnew Map(row ,column);
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < column ; j++)
		{
			mapSimple->setMap(i ,j ,Item::wallSymbol);
		}
	}
	return mapSimple;
}
void Maze::setGridDirStatus(Grid^% grid ,Map^% map ,int &theWay)
{
	theWay = 0;
	for(int i = 0 ; i < 4 ; i++ )//���T�w�|�Ӥ�즳���ǥi�H��
	{
		grid->setCurrentDir( grid->getNextDir() );
		Dot^ nextPosition = grid->getForwardPosition(2);

		if( !map->inMapArea(nextPosition) || map->getPosData(nextPosition) != Item::wallSymbol  || map->inBorder(nextPosition))
		{
			grid->setCurrentDirStatus(1);
		}
		else
		{
			grid->setCurrentDirStatus(0);
			theWay++;
		}
		grid->setNextDir();//�U�@�Ӥ�V
	}
}
void Maze::setForwardDir(Grid^% grid ,int theWay)
{
	array<int>^ choose = gcnew array<int>(theWay);
	for(int i = 0 ,k = 0; i < 4 ; i++ )
	{
		if( grid->getDirStatus(i) == 0 ) choose[k++] = i;
	}
	grid->setCurrentDir(choose[rand()%theWay]);//�üƨM�w���@�Ӥ�V
}
char Maze::getPosItem()
{
	int n1 = rand()%1000 + 1;
	int n2 = rand()%500 + 1;

	return (n1 % n2 == 0) ? Item::energySymbol[rand() % Item::energySymbol->Length] : Item::pathSymbol;
}