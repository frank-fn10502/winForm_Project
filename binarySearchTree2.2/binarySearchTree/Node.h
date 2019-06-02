#pragma once

using namespace std;

class Tree::Node
{
public:
	string* compareStr;
	DictionaryData* data;
	//string english;
	//string chinese;

	Node* parent;
	Node* left;
	Node* right;

	bool leftThread;
	bool rightThread;

	int height;

public:
	Node(void);
	~Node(void);
	Node(/*string ,string ,*/DictionaryData* ,int );
};
