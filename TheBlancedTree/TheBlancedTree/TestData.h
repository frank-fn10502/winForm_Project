#pragma once
#include "AVLTree.h"
#include "Tree2_3_4.h"
#include "RedBlackTree.h"

using namespace System;
using namespace System::IO;

ref class TestData
{
private:
	AVLTree::AVLTree^           avlTree;
	Tree2_3_4::Tree2_3_4^       tree2_3_4;
	RedBlackTree::RedBlackTree^ redBlackTree;

	String^ path  = "C:\\Users\\Frank\\Desktop\\for_test\\test.txt";
	String^ path2 = "C:\\Users\\Frank\\Desktop\\for_test\\test2.txt";

public:
	TestData(AVLTree::AVLTree^ avlTree ,Tree2_3_4::Tree2_3_4^ tree2_3_4 ,RedBlackTree::RedBlackTree^ redBlackTree)
	{
		this->avlTree      = avlTree;
		this->tree2_3_4    = tree2_3_4;
		this->redBlackTree = redBlackTree;
	}

	void insertData(int count)
	{
		Random^ random = gcnew Random();
		int num;
		File::Delete(path);

		for(int k = 0 ; k < 100 ; k++)
		{
			for(int i = 0 ; i < 50 ; i ++)
			{
				num = random->Next(0 ,500);
			
				if( redBlackTree->insert(num) )
				{
					File::AppendAllText(path, "新增: " + num + "\r\n" );
				}
			}
			for(int i = 0 ; i < 400 ; i ++)
			{
				num = random->Next(0 ,500);
				File::AppendAllText(path, "刪除after: " + num + "\r\n");

				if( redBlackTree->remove(num) )
				{
					File::AppendAllText(path, "刪除before: " + num + "\r\n");
				}
			}
			/*
			File::Delete(path);
			List<Tree2_3_4::Node^>^ nodes = ((Tree2_3_4::Tree2_3_4Entity^)tree2_3_4)->LVR();
			for each (Tree2_3_4::Node^ node in nodes)
			{
				for each (Tree2_3_4::Node^ node in nodes)
				{
					File::AppendAllText(path ,"新增: " + node->datas + "\r\n" );
				}				
			}
			*/
		}
	}
	void deleteData(int count)
	{
		String^ strDelete = "刪除after: ";
		array<String^>^ readText = File::ReadAllLines(path);
		for each (String^ str in readText)
		{
			if( str->StartsWith("新增:") )
			{
				redBlackTree->insert( Convert::ToInt32( str->Substring(4) ) );
			}
			else if( str->StartsWith("刪除after: ") )
			{
				redBlackTree->remove( Convert::ToInt32( str->Substring(strDelete->Length) ) );
			}
		}
		/*
		File::Delete(path2);
		List<AVLTree::Node^>^ nodes = avlTree->LVR();
		for each (AVLTree::Node^ node in nodes)
		{
			File::AppendAllText(path2, "新增: " + node->data + "\r\n" );
		}
		*/
	}
};

