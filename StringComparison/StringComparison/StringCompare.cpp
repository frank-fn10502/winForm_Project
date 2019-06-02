#include "StdAfx.h"
#include "StringCompare.h"

StringCompare::StringCompare(String^% s)
{
	setKeywords( s );
}
/*======================setter==============================*/
bool StringCompare::setArticleByTxt(String^% fileNAME)
{
	StreamReader ^ sr = gcnew StreamReader( fileNAME ,System::Text::Encoding::Default);
	String^ tempS;
	String^ str = "";
	while( (tempS = sr->ReadLine()) != nullptr )
	{ 
		tempS += "\n";
		str += tempS; 
	}
	sr->Close();

	if( str->Trim() == "") return false;
	else
	{
		setArticle(str);
		return true;
	}
}
void StringCompare::setArticle(String^% tempStr)
{
	article = tempStr;
}
void StringCompare::setKeywords(String^% tempStr)
{
	keywords = tempStr;
}
/*=====================getter=============================*/

String^% StringCompare::getArticle()
{
	return article;
}
String^% StringCompare::getKeywords()
{
	return keywords;
}
int StringCompare::getArticleLength()
{
	return article->Length;
}
int StringCompare::getKeywordsLength()
{
	return keywords->Length;
}
int StringCompare::getSearchNum()
{
	return searchNum;
}
/*=======================================================*/

array<int>^ StringCompare::UseKMP()
{
	FailFunction();
	array<int>^ startsTemp = gcnew array<int>(10000);
	int n = 0;
	searchNum = 0;

	for(int i = 0 ,j = 0 ; i < article->Length ; )
	{
		searchNum++;//
		if( article[i] == keywords[j] )
		{
			if( j == (keywords->Length - 1) )
			{
				startsTemp[n] = i - (keywords->Length-1);
				n++;
			}
			i++;
			j = ( j+1 ) % keywords->Length;
		}
		else 
		{
			if( j > 0 ) j = failFun[j-1] + 1;
			else
			{
				i++;
				j=0;
			}
		}
	}
	if( n == 0 ) return nullptr;
	else
	{
		array<int>^ starts = gcnew array<int>(n);
		for(int i = 0 ; i < n ; i++)
		{
			starts[i] = startsTemp[i];
		}
		return starts;
	}
}
void StringCompare::FailFunction()
{
	failFun = gcnew array<int>( keywords->Length );

	String^ S1;
	String^ S2;
	int failNum;

	for(int i = 0 ; i < keywords->Length ; i++ )
	{
		if( i == 0 ) failFun[0] = -1;
		else
		{
			failNum = -1;
			for(int j = i ,k = 0 ; j > 0 ; j-- ,k++ )
			{
				S1 = keywords->Substring(0 , (k-0)+1);
				S2 = keywords->Substring(j , (i-j)+1);
				if( S1->Equals(S2) )
				{
					failNum = k;
				}
			}
			failFun[i] = failNum;
		}
	}
}