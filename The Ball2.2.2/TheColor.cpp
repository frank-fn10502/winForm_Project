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
Color TheColor::getColor()
{
	return color;
}
System::String^ TheColor::getColorString()
{
	 System::String^ str = color.ToString();  // ex: Color [Black]
	 int start = str->IndexOf('[') + 1;
	 int count = str->IndexOf(']') - str->IndexOf('[') - 1;

	 return str->Substring( start ,count );
}
System::String^ TheColor::getOneOfArray(int i)
{
	 System::String^ str = color_select[i].ToString(); // ex: Color [Black]
	 int start = str->IndexOf('[') + 1;
	 int count = str->IndexOf(']') - str->IndexOf('[') - 1;

	 return str->Substring( start ,count );
}
int TheColor::getArrayNum()
{
	return color_select->Length;
}