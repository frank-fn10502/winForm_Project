#include "StdAfx.h"
#include "TimeSystem.h"
#include <string>
#include <sstream>
#include <ctime>   // 取得現在時間


TimeSystem::TimeSystem()
{
   hour =   0;
   minute = 0;
   second = 0;
   
   time_system = 24;
   post_meridiem = 0;
   suffix = new char[10];
 //  suffix = " ";
   strcpy_s(suffix,10," ");

}
TimeSystem::~TimeSystem() 
{
	delete suffix; 
}
void TimeSystem::setOntime(int UTC)
{
   time_t sec_now = time(NULL);
   tm t;
   gmtime_s( &t,&sec_now ); 
//   tm *t = localtime( &sec_now ); 原本

   hour   = t.tm_hour;
   minute = t.tm_min;
   second = t.tm_sec; 

   setTimeZone(UTC);
   setTimeSystem(time_system);
//   time_system = 24;
//   post_meridiem = 0; 
//   strcpy_s(suffix,10," ");

   
}
void TimeSystem::setHour(int h)
{ 
   if( h < 0)
   {
   	 hour = time_system + h;
   }
   else if( h >= time_system)
   {
   	 hour = h - time_system;
   }
   else
   {
   	hour = h;
   }
   
   if( h < 0 || h>= time_system)
   {
   	   if( time_system == 12)
   	   {
	      if( strcmp(suffix ," a.m.") ) strcpy_s(suffix,10," p.m.");
	      else					  strcpy_s(suffix,10," a.m.");	
	   }
   }
   
}
void TimeSystem::setTimeZone(int UTC)
{
	setHour( hour+UTC );
}
void TimeSystem::setTimeSystem(int t_s)
{
	if( t_s == 24)
	{
	  time_system = 24;		
      hour = hour + post_meridiem * 12;	
      post_meridiem = 0;
	//  suffix = " ";
	  strcpy_s(suffix,10," ");
	}
	else if( t_s == 12)
	{
		time_system = 12;	
		if( hour/ 12 > 0) 
		{
			post_meridiem = 1;
			strcpy_s(suffix,10," p.m.");
		}
		else 
		{
		   post_meridiem = 0;	
		   strcpy_s(suffix,10," a.m.");
		}
		hour %= 12;
	}
	
}
void TimeSystem::one_second()
{
	second++;
	if( second >= 60)
	{
	   second = 0;
	   minute++;
	   if( minute >= 60)
	   {
	   	  minute = 0;
	   	  hour++;
	   	  if( hour >= time_system)
		  {		
			 hour = 0;
			 if(time_system == 12) 
			 {
			   if(strcmp(suffix," p.m.")) strcpy_s(suffix,9," p.m.");			   
			   else					      strcpy_s(suffix,9," a.m.");	  	 
			 }	
		  }
	   }
	}		
}

char* TimeSystem::getSuffix()
{
	return suffix;
}
const char* TimeSystem::cityName(int city)
{
	switch( city )
	{
		case 1:
			return "台北";
			break;
		case 2:
			return "倫敦";
			break;
		case 3:
			return "紐約";
			break;
		default:
			return " ";
			break;
	}
}
std::string TimeSystem::getTimes(int city)
{
	std::string name(cityName(city));
	std::string s; 

	std::stringstream ss1,ss2,ss3;

	ss1 << hour;
	std::string H = ss1.str();

	ss2 << minute;
	std::string M = ss2.str();

	ss3 << second;
	std::string S = ss3.str();

				s =	name +    ( (hour  < 10 ) ? "0" + H : H );
				s = s + ":" + ((minute < 10 ) ? "0" + M : M );
				s = s + ":" + ((second < 10 ) ? "0" + S : S );
				s = s + getSuffix();
	
	return s;
}
