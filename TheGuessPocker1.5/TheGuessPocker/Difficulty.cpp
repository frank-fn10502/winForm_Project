#include "StdAfx.h"
#include "Difficulty.h"

Difficulty::Difficulty(void)
{
}
Difficulty::Difficulty(int dif)
{
	//setDifNum( dif );
	switch(dif)
	{
	  case 0:
		  setDifficulty("Â²³æ");
		  setCardNum(10);//20
		  setUseTime(false);
		  break;
	  case 1:
		  setDifficulty("´¶³q");
		  setCardNum(32);//32
		  setUseTime(false);
		  break;
	  case 2:
		  setDifficulty("§xÃø");
		  setCardNum(52);//52
		  setUseTime(true);
		  break;
	}
}
void Difficulty::setCardNum(int n){ CardNum = n;    }
int  Difficulty::getCardNum()	  { return CardNum; }
void    Difficulty::setDifficulty(String^ str){ difficulty = str;  }
String^ Difficulty::getDifficulty()			  { return difficulty; }

void Difficulty::setUseRT(bool use)  { UseRT = use;  }
bool Difficulty::getUseRT()		     { return UseRT; }
void Difficulty::setUseTime(bool use){ UseTime = use;  }
bool Difficulty::getUseTime()		 { return UseTime; }

void    Difficulty::setRT(String^ str)  { RT = str;  }//remember time
String^ Difficulty::getRT()			    { return RT; }
void    Difficulty::setTime(String^ str){ Time = str;  }
String^ Difficulty::getTime()		    { return Time; }