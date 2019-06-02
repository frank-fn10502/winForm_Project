#pragma once

ref class Mouse
{
public:
	static const int MAXPOWER = 500;

private:
	int power;

	GridStack^ stack;
	Grid^ grid;
	
	Dot^ lastPosition;
	bool lastPositionDead;

	Map^ map; //把迷宮地圖傳進來
public:
	Mouse(Maze^%);//迷宮的大小(包含 起始點)

	int	  getPower();
	Grid^ getCurrentGrid();
	Dot^  getLastPos();
	bool  getLastPosDead();

	void usePower();
	bool move();
	void findDirection();

private:
	void markLastPos(bool);
};
