#include "StdAfx.h"
#include "SpecialEffects.h"

SpecialEffects::SpecialEffects(int n)
{
	second = gcnew array<int>(n);
	open   = gcnew array<bool>(n);
	for(int i = 0 ; i < n ; i++ )
	{
		second[i] = 0;
		open[i]   = false;
	}
	coverNum = n;////////////////
}
//void SpecialEffects::setAnimationTime(int num ){ AnimationTime = num;  }
//int  SpecialEffects::getAnimationTime()        { return AnimationTime; }
int  SpecialEffects::getTick(){ return tick; }
void SpecialEffects::setTick(int num )		   
{ 
	tick = num;
	AnimationTime = tick*15;
}
void SpecialEffects::OneTick(int i)
{
	if( second[i] < AnimationTime )
	{
		second[i] += tick;
	}
	else 
	{
		second[i] = 0;
	}
}

int  SpecialEffects::getSecond(int i)		 { return second[i]; }
void SpecialEffects::setSecond(int i ,int n ){ second[i] = n;    }

bool SpecialEffects::getOpen(int i)			 { return open[i]; }
void SpecialEffects::setOpen(int i ,bool n )
{ 
	open[i] = n;   
	if( n ) coverNum -= 1;
}
int SpecialEffects::getCoverNum(){ return coverNum; }
bool SpecialEffects::Animationdone()
{
	for(int i = 0 ; i < second->Length ; i++ )
	{
		if( second[i] != 0 ) return false;
	}
	return true;
}