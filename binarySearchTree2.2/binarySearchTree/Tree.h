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

	int key;//�ΨӽT�w������O���@�Ӹ��
public:
	Tree(int );
	~Tree(void);

	int getNodeNumber() { return number;	}
	int getSearchNum()  { return searchNum; }

	bool   insertNode(DictionaryData* ); //�s�W //�P�ɽվ�𪺰��� //�J��ۦP�r �N�s�W����
	bool   deleteNode(Node * );			//�R�� //�P�ɽվ�𪺰��� //�J��ۦP�r �R���~�|���\
	System::String^ query(string );		//�^�� ex: apple --> ī�G
	System::String^  inorder();			//���Ǫk �ǥX�r��

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
