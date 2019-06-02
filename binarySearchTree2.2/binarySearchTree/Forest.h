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
	
	bool   insertNode(string ,string ); //新增 //同時調整樹的高度 //遇到相同字 就新增失敗
	bool   deleteNode(string );			//刪除 //同時調整樹的高度 //遇到相同字 刪除才會成功
	System::String^ query(string ,int);		//回傳 ex: apple --> 蘋果
	System::String^ inorder();			//中序法 傳出字串

	int getNodeNumber() { return (mode == 0) ? EnglishTree->getNodeNumber() : ChineseTree->getNodeNumber();	}
	int getSearchNum()  { return (mode == 0) ? EnglishTree->getSearchNum() : ChineseTree->getSearchNum();   }
};
