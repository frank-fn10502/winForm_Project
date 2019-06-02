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

	Map^ map; //��g�c�a�϶Ƕi��
public:
	Mouse(Maze^%);//�g�c���j�p(�]�t �_�l�I)

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
