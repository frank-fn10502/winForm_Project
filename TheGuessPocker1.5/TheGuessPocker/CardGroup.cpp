#include "StdAfx.h"
#include "CardGroup.h"

CardGroup::CardGroup(int n) : SpecialEffects(n)
{	
	card = gcnew array<Card^>(n);
	dealCard();

	TheOne  = 0;
	ThePair = gcnew array<int>(n);///
	for(int i = 0 ; i < n ; i++ ) ThePair[i] = -1;
}
void CardGroup::dealCard()
{
	Deck^ myDeck = gcnew Deck();

	for(int i = 0 ; i < card->Length ; i ++)
	{
		card[i] = gcnew Card();
		card[i] = myDeck->dealCard();
	}
}
int CardGroup::getCard(int i)
{
	int s = card[i]->getSuit();
	int p = card[i]->getRank();

	return (s - 1) * 13 + p;
}
void CardGroup::setCard(int i,int num)
{
	card[i]->setSuit( (num-1) / 13  + 1);

	//int point = num - (card[i]->getSuit() -1 ) * 13 ;
	//card[i]->setRank( point );
	card[i]->setRank( (num-1) % 13 + 1);
}
int  CardGroup::getCardNum(){ return card->Length; }

int  CardGroup::getThePair(int i)		{ return ThePair[i];   }
void CardGroup::setThePair(int i ,int n){ ThePair[i] = n;      }
int  CardGroup::getTheOne()			    { return TheOne;       }
void CardGroup::setTheOne(int n)		{ TheOne = n;          }

int  CardGroup::ISPair(int A ,int B)
{
	Card^ cardA = card[A];
	Card^ cardB = card[B];

	setSecond( A ,-1 );
	setSecond( B ,-1 );

	setThePair( A ,-1 );
	setThePair( B ,-1 );

	if( cardA->getRank() == cardB->getRank() )
	{
		setOpen(A ,true);
		setOpen(B ,true);
		return 3;
	}
	else if( cardA->getSuit() == cardB->getSuit() )
	{
		setOpen(A ,true);
		setOpen(B ,true);
		return 1;
	}
	else
	{
		return -2;
	}
}
bool CardGroup::IsNoPair()
{
	for(int i = 0 ; i < card->Length ; i++ )
	{
		if( !getOpen(i) )
		{
			for(int j = i+1 ; j < card->Length; j++ )
			{
				if( !getOpen(j) )
				{
					if( card[i]->getRank() == card[j]->getRank() || 
						card[i]->getSuit() == card[j]->getSuit()  )
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}