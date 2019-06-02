#pragma once
#include "Tree.h"

using namespace std;

class DictionaryData
{
private:
	friend class Tree;
	friend class Forest;

	string english;
	string chinese;

	Tree::Node* enNode;
	Tree::Node* chNode;

public:
	DictionaryData(string ,string);

	string getEnglish() { return english; }
	string getChinese() { return chinese; }

	string* getPEnglish() { return &english; }
	string* getPChinese() { return &chinese; }
};
