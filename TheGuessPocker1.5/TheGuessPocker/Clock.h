#pragma once

ref class Clock
{
protected:
   int hour;
   int minute;
   int second;

public:	
   Clock();
   Clock(int ,int ,int);
   virtual void setData(int ,int ,int );
   virtual void setHour(int )  ; //µÍ¿¿®Á¶° 
   virtual void setMinute(int );
   virtual void setSecond(int );
  
   int getHour()  ;
   int getMinute();
   int getSecond();
};
