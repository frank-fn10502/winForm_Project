#include "StdAfx.h"
#include "Countdown.h"

Countdown::Countdown() : Clock()
{
}
Countdown::Countdown(int h ,int min ,int sec) : Clock( h ,min ,sec )
{ 
}
Countdown::Countdown(String^ str)
{
	array<int>^ t = gcnew array<int>(3);
	String^ temp = "";
	str = str->Substring( str->IndexOf(" ")+1 );

	temp = str->Substring(0 ,2 );
	t[0] = Convert::ToInt16( temp );

	temp = str->Substring( str->IndexOf(":")+1 ,2 );
	t[1] = Convert::ToInt16( temp );

	temp = str->Substring( str->LastIndexOf(":")+1 );
	t[2] = Convert::ToInt16( temp );

	setData( t[0] ,t[1] ,t[2] );
}
void Countdown::setHour(int h){hour = h;}
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
         	return false;
		 }
		 
	 }
   }
   return true;
}
String^ Countdown::getTimes()
{
	String^ str ; 

	str =			   (hour   < 10 ) ? "0" + hour.ToString()   : hour.ToString()    ;
	str = str + ":" + ((minute < 10 ) ? "0" + minute.ToString() : minute.ToString() );
	str = str + ":" + ((second < 10 ) ? "0" + second.ToString() : second.ToString() );
	
	return str;
}