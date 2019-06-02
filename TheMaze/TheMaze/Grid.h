#pragma once

ref class Grid
{
private:
	static const int DIRNUM = 4;
	static array<String^>^ DirName = {"�_" ,"�F" ,"�n" ,"��"}; 

	static array<int>^ row	  = { -1 ,0 ,1 ,0  };
	static array<int>^ column = {  0 ,1 ,0 ,-1 };

private:
	Dot^ position;
	array<int>^ directionStatus;//4
	int currentDirection;
	int nextDirection;
	int checkTheWay;//�ˬd���� == 4 �N�N���ˬd���Ҧ���V�F

public:
	Grid(Dot^% ,int);//�I ,�i�Ӫ���V
	Grid(Dot^%);//������V

	void setCurrentDirStatus(int);// 1:�N���� , 0:�N���O���or���L����l
	void setCurrentDir(int);
	void setNextDir();

	Dot^	getPosition();
	int	    getCurrentDirStatus();
	int	    getDirStatus(int);
	int		getCurrentDir();
	int		getNextDir();
	String^ getDirName();
	bool	IsNoWay();

	Dot^ getForwardPosition(int);// �{�b���I ,�e�i"��V"
	int  getNextComeDir();

	static int getEntranceComeDir(Dot^% ,Map^%);
};
