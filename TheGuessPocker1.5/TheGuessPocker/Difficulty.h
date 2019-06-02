#pragma once

using namespace System;

ref class Difficulty
{
private:
	String^ difficulty;

	int CardNum;

	bool UseRT;	
	bool UseTime;
	String^ RT;
	String^ Time;
public:
	Difficulty(void);
	Difficulty(int );

	void    setDifficulty(String^ );
	String^ getDifficulty();

	void setCardNum(int );
	int  getCardNum();

	void setUseRT(bool );
	bool getUseRT();
	void setUseTime(bool );
	bool getUseTime();

	void    setRT(String^ );
	String^ getRT();
	void    setTime(String^ );
	String^ getTime();
};
