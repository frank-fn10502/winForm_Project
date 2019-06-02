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
bool Forest::deleteNode(string str)//�u��έ^���r�h�R��
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
System::String^ Forest::query(string str ,int modeQ)//�u����@��
{
	if( modeQ == 0 )		return EnglishTree->query(str);
	else if( modeQ == 1 )   return ChineseTree->query(str);

	return "�ڧ䤣�����i���";
}
System::String^ Forest::inorder()
{
	if( mode == 0 )		return EnglishTree->inorder();
	else if( mode == 1 )return ChineseTree->inorder();

	return "�ڧ䤣�����i���";
}