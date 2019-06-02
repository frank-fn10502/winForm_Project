#include "StdAfx.h"
#include "Forest.h"

Forest::Forest(void)
{
	mode = 0;
	EnglishTree = new Tree(0);
	ChineseTree = new Tree(1);
}
bool Forest::insertNode(string en,string ch)
{
	DictionaryData* data = new DictionaryData(en ,ch);

	if( EnglishTree->insertNode(data) )
	{
		ChineseTree->insertNode(data);
		return true;
	}
	return false;
}
bool Forest::deleteNode(string str)//只能用英文單字去刪除
{
	DictionaryData* data = EnglishTree->find(str);

	if( data != NULL )
	{
		Tree::Node* en = data->enNode;
		Tree::Node* ch = data->chNode;

		EnglishTree->deleteNode(en);
		ChineseTree->deleteNode(ch);
		delete data;
		return true;
	}
	return false;
}
System::String^ Forest::query(string str ,int modeQ)//只能找到一個
{
	if( modeQ == 0 )		return EnglishTree->query(str);
	else if( modeQ == 1 )   return ChineseTree->query(str);

	return "我找不到任何可能性";
}
System::String^ Forest::inorder()
{
	if( mode == 0 )		return EnglishTree->inorder();
	else if( mode == 1 )return ChineseTree->inorder();

	return "我找不到任何可能性";
}