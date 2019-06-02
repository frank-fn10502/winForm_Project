#include "StdAfx.h"
#include "Circle.h"

Circle::Circle(void)
{
	radius = 10;
}
void Circle::setRadius(int r){ radius = r; }

int	   Circle::getRadius()   { return radius; }
double Circle::getArea()	 { return radius * radius * PI;}
double Circle::getperimeter(){ return 2 * radius * PI; }