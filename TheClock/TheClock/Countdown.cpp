#include "StdAfx.h"
#include "Countdown.h"
#include <string>
#include <sstream>

bool Countdown::countDown()
{
   second--;
   if( second < 0)
   { 
     if( minute >0 )
     {
     	minute--;
     	second = 59;
	 }
	 else if( minute == 0 )
	 {
	     if( hour > 0 )
         {
   	        hour--;
   	        minute = 59;
   	        second = 59;
         }
		 
         else
         {
         	second = 0;
         	return true;
		 }
		 
	 }
   }
   return false;
}
std::string Countdown::getTimes()
{
	std::string s; 

	std::stringstream ss1,ss2,ss3;

	ss1 << hour;
	std::string H = ss1.str();

	ss2 << minute;
	std::string M = ss2.str();

	ss3 << second;
	std::string S = ss3.str();

	s =	           (hour  < 10 )  ? "0" + H : H  ;
	s = s + ":" + ((minute < 10 ) ? "0" + M : M );
	s = s + ":" + ((second < 10 ) ? "0" + S : S );
	
	return s;
}
