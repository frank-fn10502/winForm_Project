#pragma once

using namespace System;

generic <class ItemType>  
public delegate void DisplayDataOnBord(int ,ItemType );

generic <class T> where T : IComparable<T>  
ref class LinkList
{
private:
	ref struct Node
	{
		T data;

		Node^ parent;
		Node^ next;

		Node()
		{
			parent = nullptr;
			next   = nullptr;
		}
		Node(T data)
		{
			this->data = data;
			parent = nullptr;
			next   = nullptr;
		}
			
	}^head ,^last;

	int createNum;
public:
	LinkList(void)
	{
		head = gcnew Node();
		last = head;

		createNum = 0;
	}

	int getNum(){ return createNum; }
	void insert(T data)
	{
		Node^ temp = gcnew Node(data);
		createNum++;

		temp->parent = last;
		last->next = temp;
		last = last->next;
	}
	bool isExist(T data)
	{
		Node^ current = head->next;
		while( current != nullptr)
		{
			if( data->CompareTo(current->data) == 0 ) return true;

			current = current->next;
		}
		return false;
	}
	/*
	String^ displayData()
	{
		String^ artPoint = "";
		int i = 1;
		Node^ current = head->next;
		do
		{
			artPoint += (i) + " . " + current->data + "\n";
			current = current->next;
			i++;
		}while(current != nullptr);

		return artPoint;
	}
	*/
	void displayData(DisplayDataOnBord<T>^ displayDataOnBord)
	{
		Node^ current = head->next;
		
		for(int num = 1 ; current != nullptr ; num++ )
		{
			displayDataOnBord(num ,current->data);

			current = current->next;
		}
	}
};
