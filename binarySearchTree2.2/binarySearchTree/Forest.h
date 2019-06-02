#pragma once
#include "DictionaryData.h"
#include "Tree.h"

using namespace std;

class Forest
{
private:
	Tree* EnglishTree;
	Tree* ChineseTree;

	int mode; //0: english ,1:chinese

public:
	Forest(void);

	void setSearchMode(int mode) { this->mode = mode; }
	int  getMode() { return mode; }
	
	bool   insertNode(string ,string ); //�s�W //�P�ɽվ�𪺰��� //�J��ۦP�r �N�s�W����
	bool   deleteNode(string );			//�R�� //�P�ɽվ�𪺰��� //�J��ۦP�r �R���~�|���\
	System::String^ query(string ,int);		//�^�� ex: apple --> ī�G
	System::String^ inorder();			//���Ǫk �ǥX�r��

	int getNodeNumber() { return (mode == 0) ? EnglishTree->getNodeNumber() : ChineseTree->getNodeNumber();	}
	int getSearchNum()  { return (mode == 0) ? EnglishTree->getSearchNum() : ChineseTree->getSearchNum();   }
};
