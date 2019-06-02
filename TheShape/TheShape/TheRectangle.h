#pragma once
#include "TheColor.h"

ref class TheRectangle : public TheColor
{
private:
	int length;
	int width;
public:
	TheRectangle(void);

	void setLength(int );
	void setWidth(int );

	int getLength();
	int getWidth();
	int getArea();
	int getperimeter();
};
