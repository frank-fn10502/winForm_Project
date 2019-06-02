#include "StdAfx.h"
#include "Clock.h"

Clock::Clock()
{
   hour = 0;
   minute = 0;
   second = 0;  
}
Clock::Clock(int h ,int min ,int sec)
{ 
  setData(h ,min ,sec); 
}
void Clock::setData(int h,int min,int sec)
{
	setHour(h);
	setMinute(min);
	setSecond(sec);
}
void Clock::setHour(int h)	  { hour   = (h   < 24) ? h   : 0; }; //µêÀÀ¨ç¦¡ 
void Clock::setMinute(int min){ minute = (min < 59) ? min : 0; };
void Clock::setSecond(int sec){ second = (sec < 59) ? sec : 0; };
  
int Clock::getHour()  { return hour ;   };
int Clock::getMinute(){ return minute ; };
int Clock::getSecond(){ return second ; };