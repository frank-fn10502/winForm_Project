#include "StdAfx.h"
#include "Item.h"

int Item::getPower(char symbol)
{
	for(int i = 0 ; i < energySymbol->Length ; i++ )
	{
		if( symbol == energySymbol[i] ) return power[i];
	}
	return -100000;//遇到奇怪的東西?!?!
}
bool Item::isEnergy(char symbol)
{
	for(int i = 0 ; i < energySymbol->Length ; i++ )
	{
		if( symbol == energySymbol[i] ) return true;
	}
	return false;
}