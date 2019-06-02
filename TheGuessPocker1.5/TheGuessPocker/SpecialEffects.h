#pragma once

ref class SpecialEffects
{
private:
	int tick;
	int AnimationTime;
	array<int>^ second;
	array<bool>^ open;
	/*-----------------*/
	int coverNum;
public:
	SpecialEffects(int );

	//void setAnimationTime(int );////
	//int  getAnimationTime();
	int  getTick();
	void setTick(int );
	void OneTick(int );

	int  getSecond(int );
	void setSecond(int ,int );

	bool getOpen(int );
	void setOpen(int ,bool );

	int  getCoverNum();
	bool Animationdone();
};
