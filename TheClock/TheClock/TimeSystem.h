#pragma once
#include <string>
#include "clock.h"

ref class TimeSystem : public Clock 
{
private:
   int time_system;
   int post_meridiem;
   char* suffix;
	
   const char* cityName(int );
	
public:
   TimeSystem();
   ~TimeSystem();

   void setOntime(int ); 
   virtual void setHour(int) override;
   void setTimeZone(int); 
   void setTimeSystem(int ) ;

   void one_second();

   char* getSuffix();
   std::string getTimes(int);
};
