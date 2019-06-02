#pragma once
#include "Card.h"

ref class Deck
{
private:
	array<Card^>^ deck;
	int cardDealed;
public:
	Deck(void);

	int getCardDealed();
	Card^ dealCard();
	void shuffle();
};
