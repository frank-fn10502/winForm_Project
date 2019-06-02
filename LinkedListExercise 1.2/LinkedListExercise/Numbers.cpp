#include "StdAfx.h"
#include "Numbers.h"

Numbers::Numbers(void)
{
	count = 0;
	head  = new Number();
	forward = true;
}
Numbers::~Numbers(void)//將所有 new 都 delete
{
	Number* temp = head;
	Number* current;
	for(int i = 0 ; i < this->count ; i++ )
	{
		current = temp;
		temp	= temp->nextNum;

		delete current;
	}
	delete temp;
}
Numbers::Number::Number(void)
{
	preNum  = this;
	nextNum = this;
	num		= 0;
}
void Numbers::insertLink(int pos ,int content)
{
	this->count++;
	Number* temp = head;
	Number* newNumber = new Number();
	newNumber->num = content;

	for(int i = 1 ; i < pos ; i++ )//找到要放置位置的前一個link
	{
		if( this->forward ) temp = temp->nextNum;
		else				temp = temp->preNum;
	}
	if( this->forward )
	{
		newNumber->nextNum = temp->nextNum ;
		newNumber->preNum  = temp;

		temp->nextNum->preNum = newNumber;
		temp->nextNum = newNumber;
	}
	else
	{
		newNumber->nextNum = temp;
		newNumber->preNum  = temp->preNum;

		temp->preNum->nextNum = newNumber;
		temp->preNum = newNumber;
	}
}
void Numbers::deleteLink(int pos )
{
	this->count--;
	Number* temp = head;

	for(int i = 1 ; i <= pos ; i++ )//找到要刪除的位置
	{
		if( this->forward ) temp = temp->nextNum;
		else				temp = temp->preNum;
	}
	temp->nextNum->preNum = temp->preNum;
	temp->preNum->nextNum = temp->nextNum;

	delete temp;
}
void Numbers::editLinkByPos(int pos ,int content)
{
	Number* temp = head;	

	for(int i = 1 ; i <= pos ; i++ )//找到要編輯的位置
	{
		if( this->forward ) temp = temp->nextNum;
		else				temp = temp->preNum;
	}
	temp->num = content;
}
bool Numbers::editLinkByContent(int content ,int change)
{
	Number* temp = head;

	bool modifier = false;
	for(int i = 1 ; i <= count ; i++ )//找到要編輯的所有位置
	{
		if( this->forward ) temp = temp->nextNum;
		else				temp = temp->preNum;

		if( temp->num == content )
		{
			temp->num = change;
			modifier = true;
		}
	}
	return modifier;
}
int Numbers::queryLinkByPos(int pos)
{
	Number* temp = head;

	for(int i = 1 ; i <= pos ; i++ )//找到要的位置
	{
		if( this->forward ) temp = temp->nextNum;
		else				temp = temp->preNum;
	}
	return temp->num;
}
array<int>^ Numbers::queryLinkByContent(int content)
{
	array<int>^ temp_positions = gcnew array<int>(count);
	int pos = 0;

	Number* temp = head;
	for(int i = 1 ; i <= count ; i++ )//找到所有相同內容的所在位置
	{
		if( this->forward ) temp = temp->nextNum;
		else				temp = temp->preNum;

		if( temp->num == content )
		{
			temp_positions[pos++] = i;
		}
	}

	if( pos > 0 )//至少找到一個
	{
		array<int>^ positions = gcnew array<int>(pos);
		for(int i = 0 ; i < pos ; i++ )
		{
			positions[i] = temp_positions[i];
		}
		return positions;
	}
	else return nullptr;
}
array<int>^ Numbers::forwardList()
{
	array<int>^ num = gcnew array<int>(count);

	Number* temp = head;
	for(int i = 0 ; i < count ; i++)
	{
		temp   = temp->nextNum;
		num[i] = temp->num;
	}
	return num;
}
array<int>^ Numbers::backwardList()
{
	array<int>^ num = gcnew array<int>(count);

	Number* temp = head;
	for(int i = 0 ; i < count ; i++)
	{
		temp   = temp->preNum;
		num[i] = temp->num;
	}
	return num;
}