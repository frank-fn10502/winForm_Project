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
	//�M�z�O����(������)
}
bool Tree::insertNode(DictionaryData* inputData )//searchBinaryTree��,�s�W���I���b�̫᭱
{
	string* inputStr;
	if( key == 0 ) inputStr = inputData->getPEnglish();
	else		   inputStr = inputData->getPChinese();

	Node* parent = NULL;
	if( !head ) head = new Node(inputData ,key);//��O�Ū���
	else
	{
		parent = head;
		int compare  = 0;
		while(true)
		{
			compare = (*inputStr).compare(*(parent->compareStr));//��J����r ,�o�@�`�I����r

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
				if( key == 0 ) return false;//�^�夣�i�H���ۦP
				else		   
				{
					if( parent->leftThread ) break;
					else					 parent = parent->left;//�\�b����(�Ȯ�)	
				}
			}
		}
		Node* newNode = new Node(inputData ,key );
		newNode->parent = parent;//���wnewNode������

		if( compare > 0 )//�n�~�ӤW�@�Ӹ`�I�ҫ��V���a�� 
		{
			newNode->right		= parent->right;
			newNode->rightThread= parent->rightThread;
			newNode->left		= parent;
			newNode->leftThread = true;

			parent->right		= newNode;
			parent->rightThread = false;
		}
		else if( compare <= 0 ) //���� =
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
	//�b�o�̽վ�𪺧Ϊ�//
	Node* node = parent;
	int compare = 0;
	int bf = 0;//balance factors
	while( node != NULL )
	{
		bf = getHeight(node ,node->left) - getHeight(node ,node->right);
		if(  bf < -1 || bf > 1 )//�d�߳o�@�I�����k�l��O�_�O���Ū�
		{
			//compare = en.compare(node->english);
			compare = (*inputStr).compare(*(node->compareStr));
			if( compare <= 0 )
			{
				//compare = en.compare(node->left->english);
				compare = (*inputStr).compare(*(node->left->compareStr));
				if( compare <= 0 )//LL �ѨM: �k��
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
bool Tree::deleteNode(Node* findNode)//�u��έ^���r�h�R��
{
	//Node* deleteNode = find(str );//���n�R�����I
	Node* deleteNode = findNode;
	if( deleteNode == NULL ) return false;
	else
	{
		if(deleteNode->leftThread )
		{
			if(deleteNode->rightThread )  replace(deleteNode ,NULL);			  //�S��child
			else						  replace(deleteNode ,deleteNode->right );//�u��right child
		}
		else if(deleteNode->rightThread ) replace(deleteNode ,deleteNode->left ); //�u��left child
		else																	  //����� child
		{
			/*-------------------------------------*/ //�䥪��̤j��
			Node* subL_biggest = deleteNode->left;
			while(true)
			{
				if( subL_biggest->rightThread ) break;
				else						    subL_biggest = subL_biggest->right;
			}		
			subL_biggest->right = subL_biggest;//���Nright���V�ۤv(���ۤv���ܦ��n�洫�����@�I) 
											   //���e�@��node��right �~�ӳo�@node�ɤ��|���V"�Q�R�����I"
			//�u����إi�� 1.�Lchild 2.�u��left child
			if( subL_biggest->leftThread && subL_biggest->rightThread ) replace(subL_biggest ,NULL );
			else														replace(subL_biggest ,subL_biggest->left );
			/*-------------------------------------*/
			replace(deleteNode ,subL_biggest);

			subL_biggest->left		  = deleteNode->left;
			subL_biggest->leftThread  = deleteNode->leftThread;
			subL_biggest->right	      = deleteNode->right;
			subL_biggest->rightThread = deleteNode->rightThread;//��"����̤j��node" �~��deleteNode�����kchild or thread

			if( !deleteNode->leftThread ) deleteNode->left->parent = subL_biggest;	//�p�G���kchild�s�b �h���s���wparent
			if( !deleteNode->rightThread) deleteNode->right->parent= subL_biggest;
				
		}
		//�b�o�̽վ�𪺧Ϊ�(������)
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

		if( data == NULL ) return  "�䤣��: " + gcnew System::String( str.c_str() );
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

			compare = str.compare(temp->data->chinese);//��J����r ,�o�@�`�I����r	
			if( compare > 0)	   
			{
				if( temp->rightThread ) return "�䤣��: " + gcnew System::String( str.c_str() );
				else					temp = temp->right;
			}
			else if( compare < 0)  
			{
				if( temp->leftThread ) return "�䤣��: " + gcnew System::String( str.c_str() );
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
		while(true)//���Ǫ��e��
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
		while(true)//���Ǫ��᭱
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
	if( head )//�ܤ֦��@��
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
	else return "�S�������r";
}
/*==============================private function=======================================*/

DictionaryData* Tree::find(string str)//�Ȯɥu����@��
{
	searchNum = 0;
	if( number == 0) 
	{
		searchNum++;
		return NULL;//�S������`�I
	}
	else
	{
		Node* temp = head;
		int compare;
		while(true)
		{
			searchNum++;	
			compare = str.compare(*(temp->compareStr));		//��J����r ,�o�@�`�I����r	

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
			else if( compare == 0)	   return temp->data;//���(�Ȯɥu��@��)
		}
	}	
}
void Tree::replace(Node* node,Node* newNode)//�u�Nnode���N
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
		if(  bf < -1 || bf > 1 )//�d�߳o�@�I�����k�l��O�_�O���Ū�
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
void Tree::reThread(Node* node ,Node* newNode)//�u�B�zthread
{
	Node* parent = node->parent;

	if( newNode == NULL )//�S�����N��Node
	{
		if( parent != NULL )//�R����Node���O�Ĥ@��
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
	else if( newNode != NULL )//node�u���@��child
	{
		if( newNode == node->left )//�~�Ӫ�Node�A�R��Node������
		{
			Node* mostRight = node->left;
			while(true)//���̥k��
			{
				if( mostRight->rightThread ) break;
				else						mostRight = mostRight->right;
			}
			mostRight->right       = node->right;//���̥k�䪺�k�� �~�ӧR����node���k��
			mostRight->rightThread = node->rightThread;
		}
		else if( newNode == node->right )
		{
			Node* mostLeft = node->right;
			while(true)//���̥���
			{
				if( mostLeft->leftThread ) break;
				else					   mostLeft = mostLeft->left;
			}
			mostLeft->left		 = node->left;//���̥��䪺���� �~�ӧR����node������	
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
/*=================================����================================================*/

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