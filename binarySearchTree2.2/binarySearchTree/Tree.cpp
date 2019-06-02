#include "StdAfx.h"
#include "Tree.h"
#include "Node.h"

Tree::Tree(int key)
{
	number = 0;
	head = NULL;
	this->key = key;
}
Tree::~Tree(void)
{
	//清理記憶體(未完成)
}
bool Tree::insertNode(DictionaryData* inputData )//searchBinaryTree中,新增的點都在最後面
{
	string* inputStr;
	if( key == 0 ) inputStr = inputData->getPEnglish();
	else		   inputStr = inputData->getPChinese();

	Node* parent = NULL;
	if( !head ) head = new Node(inputData ,key);//樹是空的話
	else
	{
		parent = head;
		int compare  = 0;
		while(true)
		{
			compare = (*inputStr).compare(*(parent->compareStr));//輸入的單字 ,這一節點的單字

			if( compare > 0)	   
			{
				if( parent->rightThread ) break;
				else					  parent = parent->right;
			}
			else if( compare < 0)  
			{
				if( parent->leftThread ) break;
				else					 parent = parent->left;
			}
			else if( compare == 0) 
			{
				if( key == 0 ) return false;//英文不可以有相同
				else		   
				{
					if( parent->leftThread ) break;
					else					 parent = parent->left;//擺在左邊(暫時)	
				}
			}
		}
		Node* newNode = new Node(inputData ,key );
		newNode->parent = parent;//指定newNode的父親

		if( compare > 0 )//要繼承上一個節點所指向的地方 
		{
			newNode->right		= parent->right;
			newNode->rightThread= parent->rightThread;
			newNode->left		= parent;
			newNode->leftThread = true;

			parent->right		= newNode;
			parent->rightThread = false;
		}
		else if( compare <= 0 ) //中文 =
		{
			newNode->left		= parent->left;
			newNode->leftThread = parent->leftThread;
			newNode->right	    = parent;
			newNode->rightThread= true;

			parent->left	    = newNode;
			parent->leftThread  = false;
		}
	}
	number++;
	//在這裡調整樹的形狀//
	Node* node = parent;
	int compare = 0;
	int bf = 0;//balance factors
	while( node != NULL )
	{
		bf = getHeight(node ,node->left) - getHeight(node ,node->right);
		if(  bf < -1 || bf > 1 )//查詢這一點的左右子樹是否是平衡的
		{
			//compare = en.compare(node->english);
			compare = (*inputStr).compare(*(node->compareStr));
			if( compare <= 0 )
			{
				//compare = en.compare(node->left->english);
				compare = (*inputStr).compare(*(node->left->compareStr));
				if( compare <= 0 )//LL 解決: 右旋
				{
					rotateR(node);
				}
				else if( compare > 0 )//LR
				{
					rotateLR(node);
				}
			}
			else if( compare > 0 )
			{
				//compare = en.compare(node->right->english);
				compare = (*inputStr).compare(*(node->right->compareStr));
				if( compare > 0 )//RR
				{
					rotateL(node);
				}
				else if( compare <= 0 )//RL
				{
					rotateRL(node);
				}
			}
		}
		else node->height = getMax( getHeight(node,node->left) ,getHeight(node ,node->right) ) + 1;
		node = node->parent;
	}
	//
	return true;
}
bool Tree::deleteNode(Node* findNode)//只能用英文單字去刪除
{
	//Node* deleteNode = find(str );//找到要刪除的點
	Node* deleteNode = findNode;
	if( deleteNode == NULL ) return false;
	else
	{
		if(deleteNode->leftThread )
		{
			if(deleteNode->rightThread )  replace(deleteNode ,NULL);			  //沒有child
			else						  replace(deleteNode ,deleteNode->right );//只有right child
		}
		else if(deleteNode->rightThread ) replace(deleteNode ,deleteNode->left ); //只有left child
		else																	  //有兩個 child
		{
			/*-------------------------------------*/ //找左邊最大的
			Node* subL_biggest = deleteNode->left;
			while(true)
			{
				if( subL_biggest->rightThread ) break;
				else						    subL_biggest = subL_biggest->right;
			}		
			subL_biggest->right = subL_biggest;//先將right指向自己(讓自己先變成要交換的那一點) 
											   //讓前一個node的right 繼承這一node時不會指向"被刪除的點"
			//只有兩種可能 1.無child 2.只有left child
			if( subL_biggest->leftThread && subL_biggest->rightThread ) replace(subL_biggest ,NULL );
			else														replace(subL_biggest ,subL_biggest->left );
			/*-------------------------------------*/
			replace(deleteNode ,subL_biggest);

			subL_biggest->left		  = deleteNode->left;
			subL_biggest->leftThread  = deleteNode->leftThread;
			subL_biggest->right	      = deleteNode->right;
			subL_biggest->rightThread = deleteNode->rightThread;//讓"左邊最大的node" 繼承deleteNode的左右child or thread

			if( !deleteNode->leftThread ) deleteNode->left->parent = subL_biggest;	//如果左右child存在 則重新指定parent
			if( !deleteNode->rightThread) deleteNode->right->parent= subL_biggest;
				
		}
		//在這裡調整樹的形狀(未完成)
		//
		delete deleteNode;
		number--;
		return true;
	}
}
System::String^ Tree::query(string str)
{
	System::String^ MyString = "";
	string tempStr = "";
	if( key == 0 )
	{
		DictionaryData* data = find(str);

		if( data == NULL ) return  "找不到: " + gcnew System::String( str.c_str() );
		else			   
		{
			tempStr = data->getEnglish() + " --> " + data->getChinese();
			MyString += gcnew System::String(tempStr.c_str());
			
			return MyString;
		}
	}
	else 
	{
		Node* temp = head;
		int compare = 0;
		searchNum = 0;
		while( true )
		{
			searchNum++;

			compare = str.compare(temp->data->chinese);//輸入的單字 ,這一節點的單字	
			if( compare > 0)	   
			{
				if( temp->rightThread ) return "找不到: " + gcnew System::String( str.c_str() );
				else					temp = temp->right;
			}
			else if( compare < 0)  
			{
				if( temp->leftThread ) return "找不到: " + gcnew System::String( str.c_str() );
				else				   temp = temp->left;
			}
			else if( compare == 0)	   
			{
				tempStr = temp->data->chinese + " --> " + temp->data->english;
				MyString += gcnew System::String(tempStr.c_str());
				break;
			}
		}
		Node* preInorder = temp;
		Node* postInorder = temp;
		Node* cur;
		while(true)//中序的前面
		{
			cur = preInorder;
			preInorder = cur->left;
			if( !cur->leftThread )
			{
				while( !preInorder->rightThread )
				{
					preInorder = preInorder->right;
				}
			}
			if( preInorder == NULL ) break;
			else
			{
				searchNum++;

				compare =  str.compare(preInorder->data->chinese);
				if( compare == 0 )
				{
					tempStr = "\n" + preInorder->data->chinese + " --> " + preInorder->data->english;
					MyString += gcnew System::String(tempStr.c_str());
				}
				else break;
			}
		}
		while(true)//中序的後面
		{
			cur = postInorder;
			postInorder = postInorder->right;
			if( !cur->rightThread )
			{
				while( !postInorder->leftThread )
				{
					postInorder = postInorder->left;
				}
			}
			if( postInorder == NULL ) break;
			else
			{
				searchNum++;

				compare =  str.compare(postInorder->data->chinese);
				if( compare == 0 )
				{
					tempStr = "\n" + postInorder->data->chinese + " --> " + postInorder->data->english;
					MyString += gcnew System::String(tempStr.c_str());
				}
				else break;
			}	
		}
		return MyString;
	}
}
System::String^ Tree::inorder()
{
	if( head )//至少有一個
	{
		bool  goLeft = true;
		Node* node   = head;
		System::String^ str = "";
		
		for(int i = 1 ; i <= number ; )
		{
			if( goLeft )
			{
				if( node->leftThread ) goLeft = false;
				else				   node = node->left;
			}
			else
			{
				 string data;
				if( key == 0) data = node->data->getEnglish() + " --> " + node->data->getChinese();
				else		  data = node->data->getChinese() + " --> " + node->data->getEnglish();
				
				if( i > 1 ) str += "\n";

				str += i.ToString() + ". " + gcnew System::String(data.c_str());

				if( !node->rightThread ) goLeft = true;

				node = node->right;
				i++;
			}
		}
		return str;
	}
	else return "沒有任何單字";
}
/*==============================private function=======================================*/

DictionaryData* Tree::find(string str)//暫時只能找到一個
{
	searchNum = 0;
	if( number == 0) 
	{
		searchNum++;
		return NULL;//沒有任何節點
	}
	else
	{
		Node* temp = head;
		int compare;
		while(true)
		{
			searchNum++;	
			compare = str.compare(*(temp->compareStr));		//輸入的單字 ,這一節點的單字	

			if( compare > 0)	   
			{
				if( temp->rightThread ) return NULL;
				else					temp = temp->right;
			}
			else if( compare < 0)  
			{
				if( temp->leftThread ) return NULL;
				else				   temp = temp->left;
			}
			else if( compare == 0)	   return temp->data;//找到(暫時只找一個)
		}
	}	
}
void Tree::replace(Node* node,Node* newNode)//只將node取代
{
	Node* parent = node->parent;
	if(parent != NULL)
	{
		if( newNode != NULL )
		{
			if( node == parent->left )		 parent->left  = newNode;
			else if( node == parent->right ) parent->right = newNode;
		}
	}
	else head = newNode;//NULL; 

	if( newNode != NULL ) newNode->parent = parent;	

	reThread(node ,newNode );

	Node* tempNode = node->parent;
	int compare;
	int bf = 0;//balance factors
	while( tempNode )//tempNode != NULL
	{
		bf = getHeight(tempNode ,tempNode->left) - getHeight(tempNode ,tempNode->right);
		if(  bf < -1 || bf > 1 )//查詢這一點的左右子樹是否是平衡的
		{
			//compare = node->english.compare(tempNode->english);
			compare = (*node->compareStr).compare(*(tempNode->compareStr));
			if( compare <= 0 )
			{
				if( getHeight(tempNode->right ,tempNode->right->left) > getHeight(tempNode->right ,tempNode->right->right))//!tempNode->right->left->leftThread && 
				{//RL
					rotateRL(tempNode);
				}
				else
				{//RR
					rotateL(tempNode);
				}
			}
			else if( compare > 0)
			{
				if( getHeight(tempNode->left ,tempNode->left->right) > getHeight(tempNode->left ,tempNode->left->left))//!tempNode->left->right->rightThread && 
				{//LR
					rotateLR(tempNode);
				}
				else
				{//LL
					rotateR(tempNode);
				}
			}
		}
		else tempNode->height = getMax(getHeight(tempNode,tempNode->left) ,getHeight(tempNode ,tempNode->right)) + 1;
		tempNode = tempNode->parent;
	}
}
void Tree::reThread(Node* node ,Node* newNode)//只處理thread
{
	Node* parent = node->parent;

	if( newNode == NULL )//沒有替代的Node
	{
		if( parent != NULL )//刪除的Node不是第一個
		{
			if( node == parent->left )  
			{
				parent->left	   = node->left;
				parent->leftThread = node->leftThread;
			}
			else if( node == parent->right )
			{
				parent->right		= node->right;
				parent->rightThread = node->rightThread;
			}
		}
	}
	else if( newNode != NULL )//node只有一個child
	{
		if( newNode == node->left )//繼承的Node再刪除Node的左邊
		{
			Node* mostRight = node->left;
			while(true)//找到最右邊
			{
				if( mostRight->rightThread ) break;
				else						mostRight = mostRight->right;
			}
			mostRight->right       = node->right;//讓最右邊的右手 繼承刪除的node的右手
			mostRight->rightThread = node->rightThread;
		}
		else if( newNode == node->right )
		{
			Node* mostLeft = node->right;
			while(true)//找到最左邊
			{
				if( mostLeft->leftThread ) break;
				else					   mostLeft = mostLeft->left;
			}
			mostLeft->left		 = node->left;//讓最左邊的左手 繼承刪除的node的左手	
			mostLeft->leftThread = node->leftThread;
		}
	}
}
int Tree::getHeight(Node* parent ,Node* sub )
{
	if( sub == parent->left )
	{
		if(parent->leftThread ) return 0;
		else					return sub->height;
	}
	else if( sub == parent->right )
	{
		if(parent->rightThread) return 0;
		else					return sub->height;
	}
	else if( sub == NULL ) return 0;
}
int Tree::getMax(int a,int b)
{
	return (a > b) ? a : b;
}
/*=================================旋轉================================================*/

void Tree::rotateR(Node* UBNode)//unbanlance node
{
	Node* parent = UBNode->parent;
	Node* subL   = UBNode->left;
	Node* subLR  = subL->right;

	if( subL->rightThread ) 
	{
		UBNode->leftThread = true;
	}
	else
	{
		UBNode->left = subLR;
		subLR->parent = UBNode;
	}
	subL->right = UBNode;
	subL->rightThread = false;
	UBNode->parent = subL;

	if( parent == NULL )			  head = subL;
	else if( UBNode == parent->left ) parent->left = subL;
	else if( UBNode == parent->right) parent->right = subL;

	subL->parent = parent;
	UBNode->height = getMax( getHeight(UBNode,UBNode->left) ,getHeight(UBNode ,UBNode->right) ) + 1;
}
void Tree::rotateL(Node* UBNode)//unbanlance node
{
	Node* parent = UBNode->parent;
	Node* subR = UBNode->right;
	Node* subRL = subR->left;

	if( subR->leftThread ) 
	{
		UBNode->rightThread = true;
	}
	else
	{
		UBNode->right = subRL;
		subRL->parent = UBNode;
	}
	subR->left = UBNode;
	subR->leftThread = false;
	UBNode->parent = subR;

	if( parent == NULL )
	{
		head = subR;		
	}
	else if( UBNode == parent->left )
	{
		parent->left = subR;
	}
	else if( UBNode == parent->right )
	{
		parent->right = subR;
	}
	subR->parent = parent;	
	UBNode->height = getMax( getHeight(UBNode,UBNode->left) ,getHeight(UBNode ,UBNode->right) ) + 1;
}
void Tree::rotateRL(Node* UBNode)
{
	rotateR(UBNode->right);
	rotateL(UBNode);
}
void Tree::rotateLR(Node* UBNode)
{
	rotateL(UBNode->left);
	rotateR(UBNode);
}