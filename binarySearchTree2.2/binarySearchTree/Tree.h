#pragma once
#include "DictionaryData.h"

using namespace std;

class Tree
{
private:
	friend class DictionaryData;
	friend class Forest;

	class Node;
	
	Node* head;
	int number;
	int searchNum;

	int key;//用來確定比較的是哪一個資料
public:
	Tree(int );
	~Tree(void);

	int getNodeNumber() { return number;	}
	int getSearchNum()  { return searchNum; }

	bool   insertNode(DictionaryData* ); //新增 //同時調整樹的高度 //遇到相同字 就新增失敗
	bool   deleteNode(Node * );			//刪除 //同時調整樹的高度 //遇到相同字 刪除才會成功
	System::String^ query(string );		//回傳 ex: apple --> 蘋果
	System::String^  inorder();			//中序法 傳出字串

private:
	DictionaryData* find(string);
	void  replace(Node* ,Node*);
	void  reThread(Node*,Node*);

	int	  getHeight(Node* ,Node*);
	int	  getMax(int ,int );

private:
	void rotateR(Node*);
	void rotateL(Node*);
	void rotateRL(Node*);
	void rotateLR(Node*);
};
