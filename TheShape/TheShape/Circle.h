#pragma once
#include "TheColor.h"

ref class Circle : public TheColor
{
private: 
	int radius;
	static const double PI = 3.14159;

public:
	Circle(void);
	void setRadius(int );

	int getRadius();
	double getArea();
	double getperimeter();
};
