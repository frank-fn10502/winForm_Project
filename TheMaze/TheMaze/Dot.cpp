#include "StdAfx.h"
#include "Dot.h"

Dot::Dot(int i ,int j )
{
	setDot(i ,j);
}
Dot::Dot(Dot^% dot)
{
	setDot(dot->getI() ,dot->getJ() );	
}
/*======================setter=============================*/

void Dot::setDot(int i,int j)
{
	setI(i);
	setJ(j);
}
void Dot::setI(int i){ this->i = i; }
void Dot::setJ(int j){ this->j = j; }
/*======================getter=============================*/

int Dot::getI(){ return i; }
int Dot::getJ(){ return j; }
/*======================function=============================*/
bool Dot::operator==(Dot^% dot)
{
	return (this->i == dot->getI() && this->j == dot->getJ());
}
String^ Dot::ToString()
{
	return String::Format("( {0,-4} ,{1,-4} )" ,i ,j );
}
