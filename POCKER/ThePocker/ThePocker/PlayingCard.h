#pragma once
//#include "Card.h"
#include "Deck.h"

using namespace System::Windows::Forms;

ref class PlayingCard
{
private:
	array<Card^>^ playCard;

	array<int>^ CardGroup(int ,int );
	void sort(int ,int);
public:
	PlayingCard(int);

	void dealCard();
	int getHandCard(int );

	int Compare(Label^% A ,Label^% B );
};
