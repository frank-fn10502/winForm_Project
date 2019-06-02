#pragma once
#include "clock.h"
#include <string>

ref class Timmer : public Clock
{
private:
	int dsecond; //���� 
	int csecond; //����
	
public:
	Timmer() ;

	void setData(int ,int ,int ,int ,int );
	void setDsecond(int );
	void setCsecond(int );

	int getDsecond();
	int getCsecond();
	
	void oneCsecond();

	std::string getTimes();
	
};
