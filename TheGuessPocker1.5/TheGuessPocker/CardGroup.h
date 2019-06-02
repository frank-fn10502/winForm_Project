#pragma once
#include "Deck.h"
#include "SpecialEffects.h"

ref class CardGroup : public SpecialEffects
{
private:
	array<Card^>^ card;

	array<int>^ ThePair; //TheOne �� �t�� 
	int	TheOne;			 //�bform1�C�⦸�I�����Ĥ@�ӵP

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
