#pragma once
#include "clock.h"
#include <string>

ref class Countdown : public Clock
{
public:
   bool countDown();
   virtual void setHour(int h)override {hour = h;}; 
   //�|�л\ Clock ����  virtual void setHour(int h) { hour   = (h   < 24) ? h   : 0; };
   std::string getTimes();
};
