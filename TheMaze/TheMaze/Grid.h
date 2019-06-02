#pragma once

ref class Grid
{
private:
	static const int DIRNUM = 4;
	static array<String^>^ DirName = {"北" ,"東" ,"南" ,"西"}; 

	static array<int>^ row	  = { -1 ,0 ,1 ,0  };
	static array<int>^ column = {  0 ,1 ,0 ,-1 };

private:
	Dot^ position;
	array<int>^ directionStatus;//4
	int currentDirection;
	int nextDirection;
	int checkTheWay;//檢查次數 == 4 就代表檢查完所有方向了

public:
	Grid(Dot^% ,int);//點 ,進來的方向
	Grid(Dot^%);//不給方向

	void setCurrentDirStatus(int);// 1:代表死路 , 0:代表不是牆壁or走過的格子
	void setCurrentDir(int);
	void setNextDir();

	Dot^	getPosition();
	int	    getCurrentDirStatus();
	int	    getDirStatus(int);
	int		getCurrentDir();
	int		getNextDir();
	String^ getDirName();
	bool	IsNoWay();

	Dot^ getForwardPosition(int);// 現在的點 ,前進"方向"
	int  getNextComeDir();

	static int getEntranceComeDir(Dot^% ,Map^%);
};
