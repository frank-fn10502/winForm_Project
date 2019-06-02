#pragma once

using namespace System;
using namespace System::IO;

ref class Maze
{
private:
	Map^ originalMap;//原版 遊戲中不會動到
	Map^ mazeMap;	 //吃掉能量 ,走過的記號 ,遊戲參考的map

	Dot^ entrance;
	Dot^ exit;

	String^ mazeName;
public:
	Maze(String^%);
	Maze(Map^%);

	Map^    getOriginalMap();
	Map^    getMazeMap();
	Dot^    getEntrance();
	Dot^    getExit();
	String^ getMazeName();

	void reSetMazeMap();

private:
	void setMazeByTxt(String^%);
	void setMaze(int ,int ,String^% );
	void setMazeNameByTxt(String^%);
	void findEnrance_Exit();

/*------------創造地圖-------------------*/
public:
	static Map^ createMap(int ,int);

private:
	static Dot^ createEntrancePoint(int ,int);
	static Dot^ createExitPoint(int ,int ,Dot^%);
	static bool exitNotEntrance(Dot^% ,Dot^%);
	static void makeExitLink(Map^% ,Dot^%);

	static Map^ createMapSimple(int row ,int column);
	static void setGridDirStatus(Grid^% grid ,Map^% map ,int &theWay);
	static void setForwardDir(Grid^% ,int);
	static char getPosItem();
};
