#include "StdAfx.h"
#include "TheRectangle.h"

TheRectangle::TheRectangle()
{
	length = 10;
	width = 10;
}
void TheRectangle::setLength(int l){ length = l; }
void TheRectangle::setWidth(int w) { width = w;  }

int TheRectangle::getLength(){ return length; }
int TheRectangle::getWidth() { return width;  }
int TheRectangle::getArea()  { return length * width; }
int TheRectangle::getperimeter(){ return (length + width) * 2; }