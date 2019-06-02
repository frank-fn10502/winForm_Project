#include "StdAfx.h"
#include "PlayingCard.h"



PlayingCard::PlayingCard(int n)
{
	playCard = gcnew array<Card^>(5 * n);
	dealCard();
}
void change(Card^% a ,Card^% b )
{
	Card^ temp = gcnew Card();
	temp->setRank(a->getRank() );
	temp->setSuit(a->getSuit() );

	a->setRank(b->getRank() );
	a->setSuit(b->getSuit() );
	b->setRank(temp->getRank() );
	b->setSuit(temp->getSuit() );
}

void PlayingCard::sort(int start ,int end)///////////////大 -- 小
{
	for (int i= end ; i>start ; i-- )
	{
       for (int j =start ; j <=end - 2 ; j++)
	   { 
		  if( playCard[j]->getRank() > playCard[j+1]->getRank() )
		  {
				    change( playCard[j] ,playCard[j+1] );
		  }
		  else if( playCard[j]->getRank() == playCard[j+1]->getRank() )
		  {
			   if( playCard[j]->getSuit() > playCard[j+1]->getSuit() )
			   {
					change( playCard[j] ,playCard[j+1] );
			   }
		  }
       }
	}
}
void PlayingCard::dealCard()
{
	Deck^ myDeck = gcnew Deck();

	for(int i = 0 ; i < playCard->Length ; i ++)
	{
		playCard[i] = gcnew Card();
		playCard[i] = myDeck->dealCard();
	}
	sort(0 ,5);
	sort(5 ,10);
}
int PlayingCard::getHandCard(int i)
{
	int s = playCard[i]->getSuit();
	int p = playCard[i]->getRank();

	return (s - 1) * 13 + p;
}
array<int>^ PlayingCard::CardGroup(int start ,int end )//總共9 種等級
{	
	array<int>^ point = gcnew array<int>(5);
	for(int i = 0 ; i < 5 ; i++ ) point[i] = true;

	array<int>^ repeat  = gcnew array<int>{ 0,0 };
	array<int>^ repeat2 = gcnew array<int>{ 0,0 };

	for(int i = start ; i < end ; i++ )
	{
		if( !point[i - start] ) continue;

		for (int j = i+1 ; j < end  ; j++)
		{
			if ( playCard[i]->getRank() == playCard[j]->getRank() )
			{
				point[i-start] = false;
				point[j-start] = false;

				if( playCard[i]->getRank() > repeat[0]  ||
					playCard[i]->getRank() == 1 && repeat[0] != 1 ) /////1最大
				{
					repeat2[0] = repeat[0];
					repeat2[1] = repeat[1];

					repeat[0] = playCard[i]->getRank();
					repeat[1] = 2;
				}
				else if( playCard[i]->getRank() == repeat[0] )
				{
					repeat[1]++;
				}
				else if( playCard[i]->getRank() < repeat[0]  )
				{
					repeat2[0] = playCard[i]->getRank();
					if( repeat2[1] == 0 ) repeat2[1] = 2;
					else				  repeat2[1] ++;
				}
			}
		}
	}
	if( repeat2[1] > repeat[1] )
	{
		int temp;

		temp       = repeat[0];
		repeat [0] = repeat2[0];
		repeat2[0] = temp;

		temp       = repeat[1];
		repeat [1] = repeat2[1];
		repeat2[1] = temp;
	}
/*-------------------------------------------------------------*/
	if( repeat[1] == 0 ) //單張 or 順 or 同花 or 同花順
	{
		bool same_color = true;
		bool shun = true;
		int num;
		array<int>^ level = gcnew array<int>(6);
		
		for(int i = 0 ; i < 5 ; i++ )
		{
			if( i!=4 && playCard[i]->getSuit() != playCard[i+1]->getSuit() )
			{
				same_color = false;///////////
			}
			if(i == 0 ) num = getHandCard(start + i);
			else		
			{
				num -= getHandCard(start + i);
				if( num != 1 ) shun = false;//////////////1
			}

			level[i+1] = getHandCard(start + i);
		}	
		if( same_color && shun  )      level[0] = 8;
		else if( same_color && !shun ) level[0] = 5;
		else if( shun && !same_color ) level[0] = 4;
		else					       level[0] = 0;

		return level;
	}
	else if( repeat[1] == 2 && repeat2[1] == 0)//一對
	{
		array<int>^ level = gcnew array<int>(5);
		level[0] = 1;
		level[1] = repeat[0];

		int j = 2;
		for(int i = 0 ; i < 5 ; i++ )
		{
			if( point[i] ) 
			{
				level[j] = getHandCard(start + i);	
				j++;
			}
		}	
		return level;		
	}
	else if( repeat[1] == 2 && repeat2[1] == 2 )//兩對
	{
		array<int>^ level = gcnew array<int>(4);
		level[0] = 2;
		level[1] = repeat[0];
		level[2] = repeat2[0];

		int j = 3;
		for(int i = 0 ; i < 5 ; i++ )
		{
			if( point[i] ) 
			{
				level[j] = getHandCard(start + i);	
				j++;
			}
		}	
		return level;
	}
	else if(  repeat[1] == 3 && repeat2[1] == 0  )//三條
	{
		array<int>^ level = gcnew array<int>(4);
		level[0] = 3;
		level[1] = repeat[0];

		int j = 2;
		for(int i = 0 ; i < 5 ; i++ )
		{
			if( point[i] ) 
			{
				level[j] = getHandCard(start + i);	
				j++;
			}
		}	
		return level;
	}
	else if(  repeat[1] == 3 && repeat2[1] == 2  )//葫蘆
	{
		array<int>^ level = gcnew array<int>(3);
		level[0] = 6;
		level[1] = repeat[0];
		level[2] = repeat2[0];

		return level;
	}
	else if(  repeat[1] == 4 && repeat2[1] == 0  )//四條
	{
		array<int>^ level = gcnew array<int>(3);
		level[0] = 7;
		level[1] = repeat[0];

		int j = 2;
		for(int i = 0 ; i < 5 ; i++ )
		{
			if( point[i] ) 
			{
				level[j] = getHandCard(start + i);	
				j++;
			}
		}	
		return level;
	}
}
System::String^ CardType(int t)
{
	switch(t)
	{
	case 0:
		return "單張";
		break;
	case 1:
		return "一對";
		break;
	case 2:
		return "兩對";
		break;
	case 3:
		return "三條";
		break;
	case 4:
		return "順子";
		break;
	case 5:
		return "同花";
		break;
	case 6:
		return "葫蘆";
		break;
	case 7:
		return "四條";
		break;
	case 8:
		return "同花順";
		break;
	}
}
Card^ BackTOCard(int num)
{
	Card^ c = gcnew Card();

	c->setSuit( num / 13 + 1);
	c->setRank(num %13);

	return c;
}
int PlayingCard::Compare(Label^% A ,Label^% B )
{
	array<int>^ player   = CardGroup(5 ,10 );
	array<int>^ computer = CardGroup(0 ,5  );

	A->Text = CardType( player[0]  );
	B->Text = CardType( computer[0]);

	if( computer[0] > player[0] )
	{
		return 0;
	}
	else if(  computer[0] < player[0] )
	{
		return 1;
	}
	else if(  computer[0] == player[0] )
	{
		for(int i = 1 ; i < player->Length ; i++ )
		{
			Card^ com = BackTOCard(computer[i]);
			Card^ pla = BackTOCard(player[i]);

			/*----------------------1是最大的-------------------------------*/
			if(com->getRank() == 1 && pla->getRank() != 1 )      return 0;
			else if(pla->getRank() == 1 && com->getRank() != 1 ) return 1;
			else if(pla->getRank() == 1 && com->getRank() == 1)
			{
				if( com->getSuit() > pla->getSuit() )      return 0;
				else if( com->getSuit() > pla->getSuit() ) return 1;
			}
			/*-----------------------------------------------------------*/
			if( com->getRank() > pla->getRank() )			return 0; 
			else if( com->getRank() < pla->getRank() )		return 1;
			else if( com->getRank() == pla->getRank() )
			{
				if( com->getSuit() > pla->getSuit() )      return 0;
				else if( com->getSuit() > pla->getSuit() ) return 1;
			}
		}
		return -1; //到最後都一樣 就平手
	}
}
