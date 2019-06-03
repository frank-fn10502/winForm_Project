#pragma once


generic <class T>
ref class Stack
{
private:
	ref struct Node
	{
		T data;
		Node^ next;

		Node()
		{
			next = nullptr;
		}
		Node(T data)
		{
			this->data = data;
			next = nullptr;
		}
	};

	Node^ base;
	Node^ top;

public:
	Stack()
	{
		base = gcnew Node();
		top  = base;
	}

	void Push(T data)
	{
		Node^ newNode = gcnew Node(data);

		newNode->next = top;
		top = newNode;
	}
	T pop()
	{
		if( top == base ) return T();
		else
		{
			Node^ popNode = top;
			top = top->next;

			return popNode->data;
		}
	}
	bool isEmpty() 
	{
		 return  (top == base)? true : false ;
	}
};