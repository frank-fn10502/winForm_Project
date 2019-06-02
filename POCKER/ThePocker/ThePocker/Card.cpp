#include "StdAfx.h"
#include "Card.h"

Card::Card(void)
{
}
void Card::setCard(int s,int r)
{
	setSuit(s);
	setRank(r);
}
void Card::setSuit(int s){ suit = s; }
void Card::setRank(int r){ rank = r; }

int Card::getSuit(){ return suit; }
int Card::getRank(){ return rank; }