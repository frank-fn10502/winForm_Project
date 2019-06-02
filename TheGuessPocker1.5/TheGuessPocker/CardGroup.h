#pragma once
#include "Deck.h"
#include "SpecialEffects.h"

ref class CardGroup : public SpecialEffects
{
private:
	array<Card^>^ card;

	array<int>^ ThePair; //TheOne 的 配對 
	int	TheOne;			 //在form1每兩次點擊的第一個牌

public:
	CardGroup(int );

	void dealCard();
	int  getCard(int );
	void setCard(int ,int );
	int  getCardNum();

	int  getThePair(int );
	void setThePair(int ,int);
	int  getTheOne();
	void setTheOne(int  );

	int  ISPair(int ,int );
	bool IsNoPair();
};
