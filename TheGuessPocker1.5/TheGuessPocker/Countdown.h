#pragma once
#include "clock.h"

using namespace System;

ref class Countdown : public Clock
{
public:
   Countdown();
   Countdown(int ,int ,int);
   Countdown(String^ );

   bool countDown();
   virtual void setHour(int h) override;
   String^ getTimes();
};
