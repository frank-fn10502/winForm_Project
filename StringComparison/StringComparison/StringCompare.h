#pragma once


using namespace System;
using namespace System::IO;

ref class StringCompare
{
private:
	static String^  article;
	String^ keywords;

	array<int>^ failFun;
	int searchNum;

public:
	StringCompare(String^%);

	static bool setArticleByTxt(String^% );
	static void setArticle(String^% );
	void setKeywords(String^% );

	static String^% getArticle();
	String^% getKeywords();
	int getArticleLength();
	int getKeywordsLength();	
	int getSearchNum();
	
	array<int>^ UseKMP();

private:
	void FailFunction();
};
