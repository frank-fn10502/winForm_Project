#include "StdAfx.h"
#include "Timmer.h"
#include <sstream>
#include <string>

Timmer::Timmer() { dsecond = 0; csecond = 0; }

void Timmer::setDsecond(int ds){ dsecond = ds;}
void Timmer::setCsecond(int cs){ csecond = cs;}

int Timmer::getDsecond() { return dsecond; }
int Timmer::getCsecond() { return csecond; }

void Timmer::setData(int h,int min,int sec,int ds,int cs)
{
	setHour(h);
	setMinute(min);
	setSecond(sec);
	setDsecond(ds);  
	setCsecond(cs);
}

void Timmer::oneCsecond()
{
	csecond++;
	if( csecond >= 10)
	{
		csecond = 0;
		dsecond++;
		if( dsecond >= 10 )
		{
			dsecond = 0;
			second++;
			if( second >= 60)
		    {
			   second = 0;
			   minute++;
			   if( minute >= 60)
			   {
			   	  minute = 0;
			   	  hour++;

			   }
		    }	
		}
	}		
}
std::string Timmer::getTimes()
{
	std::string s; 

	std::stringstream ss1,ss2,ss3,ss4,ss5;

	ss1 << hour;
	std::string H = ss1.str();

	ss2 << minute;
	std::string M = ss2.str();

	ss3 << second;
	std::string S = ss3.str();

	ss4 << dsecond;
	std::string DS = ss4.str();

	ss5 << csecond;
	std::string CS = ss5.str();

	s =           ((hour  < 10 )  ? "0" + H : H );
	s = s + ":" + ((minute < 10 ) ? "0" + M : M );
	s = s + ":" + ((second < 10 ) ? "0" + S : S );
	s = s + "." + DS + CS;

	return s;
}

