#include "StdAfx.h"
#include "Deck.h"

#include "time.h"
#include "stdlib.h"
#include "stdio.h"

Deck::Deck(void)
{
	deck = gcnew array<Card^>(52);
	for(int i = 0 ; i < deck->Length ; i++ )
	{
		deck[i] = gcnew Card();
		deck[i]->setRank(i % 13 +1);
		deck[i]->setSuit(i / 13 +1);  
	}
	cardDealed = 0;
	shuffle();
}
int Deck::getCardDealed()
{
	return cardDealed;
}
Card^ Deck::dealCard()
{
	if( cardDealed >= 52)
	{
		
	}
	Card^ card = deck[cardDealed];
	cardDealed++;

	return card;
}
void  Deck::shuffle()
{
	srand( (unsigned)time( NULL ) );
	int num;

	Card^ temp = gcnew Card();
	for(int i = 0 ; i < 52 ; i++ )
	{
		num = rand() % 52;

		temp      = deck[i];
		deck[i]   = deck[num];
		deck[num] = temp;
	}
}