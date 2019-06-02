#pragma once

ref class Item//先是固定的
{
public:
	static const char exitSymbol = '#';
	static const char wallSymbol = '1';
	static const char walkedMark = '2';
	static const char pathSymbol = '0';
	static array<char>^ energySymbol = gcnew array<char>{ '+' ,'-' ,'*' ,'/' ,'$' };;
	static array<int>^  power        = gcnew array<int>{ 30 ,10 ,50 ,80 ,100 };

public:
	static int getPower(char);
	static bool isEnergy(char);
};
