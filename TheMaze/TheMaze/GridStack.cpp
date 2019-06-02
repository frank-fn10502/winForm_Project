#include "StdAfx.h"
#include "GridStack.h"

GridStack::GridStack(int num)
{
	this->stack = gcnew array<Grid^>(num);
	top  = 0;
	base = 0;
}
int GridStack::getTop(){ return top; }
Grid^ GridStack::pop()
{
	if( top > base ) return stack[--top];
	else			 return nullptr;
}
bool GridStack::push(Grid^% grid)
{
	if( top >= base )
	{
		stack[top++] = grid;
		return true;
	}
	else return false;
}