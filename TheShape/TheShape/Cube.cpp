#include "StdAfx.h"
#include "Cube.h"

Cube::Cube(void)
{
	height = 100;
	this->setLength(100);
	this->setWidth (100);
}
int  Cube::getHeight(){ return height; }
void Cube::setHeight(int h){ height = h; }

int Cube::getVolume(){ return getArea() * height; }
int Cube::getSurfaceArea(){ return 2*getArea() + 2*getLength()*height + 2*getWidth()*height; }
