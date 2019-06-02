#include "StdAfx.h"
#include "Tree.h"
#include "Node.h"

Tree::Node::Node(void)
{
	//Node("" ,"" );
}
Tree::Node::~Node(void)
{
	//if( data != NULL ) delete data;
}
Tree::Node::Node(DictionaryData* data ,int key)
{
	//english = en;
	//chinese = ch;

	parent = NULL;
	leftThread = true;
	left = NULL;
	rightThread = true;
	right = NULL;

	height = 1;

	this->data = data;

	if( key == 0 )		
	{
		compareStr = data->getPEnglish();//
		data->enNode = this;
	}
	else if( key == 1)	
	{
		compareStr = data->getPChinese();//
		data->chNode = this;
	}
}