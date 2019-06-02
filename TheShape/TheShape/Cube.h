#pragma once
#include "TheRectangle.h"

ref class Cube : public TheRectangle
{
private:
	int height;
public:
	Cube(void);

	int getHeight();
	void setHeight(int );

	int getVolume();
	int getSurfaceArea();
};
