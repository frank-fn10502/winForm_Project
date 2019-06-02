#include "StdAfx.h"
#include "TheColor.h"


TheColor::TheColor(void)
{	
  color = color_select[0];
}
void TheColor::setColor(int s)
{
	color = color_select[s];
}
	
System::Drawing::Color TheColor::getColor()
{
	return color;
}
/*
array<System::Drawing::Color>^% TheColor::getColorArray()
{
	return color_select;
}
*/
System::String^ TheColor::getOneOfArray(int i)
{
	 System::String^ str = color_select[i].ToString();
	 int start = str->IndexOf('[') + 1;
	 int count = str->IndexOf(']') - str->IndexOf('[') - 1;

	 return str->Substring( start ,count );
}
int TheColor::getArrayNum()
{
	return color_select->Length;
}
