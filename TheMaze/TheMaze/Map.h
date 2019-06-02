#pragma once

ref class Map
{
private:
	array<int,2>^ map;
	int row;
	int column;

public:
	Map(int ,int);

	void setMap(Dot^% ,int );
	void setMap(int ,int ,int );

	char getPosData(Dot^%);
	char getPosData(int ,int);
	int  getRow();
	int  getColumn();

	void operator=(Map^%);
	bool inMapArea(Dot^%);
	bool inBorder(Dot^%);
};
