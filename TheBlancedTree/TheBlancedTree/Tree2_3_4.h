#pragma once
#include "BalancedTree.h"
using namespace BalancedTree;

namespace Tree2_3_4
{
	ref struct Node : public BalancedTree::Node
	{			
	protected:
		array<Node^>^ nodes;
		Node^ left;
		Node^ leftMiddle;
		Node^ rightMiddle;
		Node^ right;

	public:
		Node^ parent;
		List<int>^ datas;
		Node^ getLeft()			{ return left; }
		Node^ getLeftMiddle()	{ return leftMiddle; }
		Node^ getRightMiddle()	{ return rightMiddle; }
		Node^ getRight()		{ return right; }
		Node^ getNextNode(int n){ return nodes[n]; }

		void setLeft(Node^ node)       {nodes[0] = left = node;}
		void setLeftMiddle(Node^ node) {nodes[1] = leftMiddle = node;}
		void setRightMiddle(Node^ node){nodes[2] = rightMiddle = node;}
		void setRight(Node^ node)	   {nodes[3] = right = node;}

		void setNextNode(int n ,Node^ node)
		{ 
			switch(n)
			{
			case 0:
				setLeft(node);
				break;
			case 1:
				setLeftMiddle(node);
				break;
			case 2:
				setRightMiddle(node);
				break;
			case 3:
				setRight(node);
				break;
			}
		}

		Node() : BalancedTree::Node()
		{
			nodes  = gcnew array<Node^>(4);
			datas  = gcnew List<int>();
			parent = nullptr;
			setLeft(nullptr);
			setLeftMiddle(nullptr);
			setRightMiddle(nullptr);
			setRight(nullptr);
		}
		Node(int data) :Node()
		{
			datas->Add(data);
		}

		bool isLeaf()
		{
			return (left == nullptr && leftMiddle == nullptr && rightMiddle == nullptr && right == nullptr);
		}
		int insertLeaf(int data)
		{
			for(int i = 0 ; i < datas->Count ; i++)
			{
				if(data <= datas[i])
				{
					datas->Insert(i ,data);
					return i;
				}
				else if( i == datas->Count-1)
				{
					int pos = datas->Count;
					datas->Insert(pos ,data);
					return pos;
				}
			}
		}
		void insertParent(int data ,Node^ node)
		{
			int insertPos = insertLeaf(data);

			Node^ rNode = node;
			Node^ temp;
			for(int i = insertPos+1 ; i < 4 ; i++)
			{
				temp = getNextNode(i);
				setNextNode(i, rNode);
				rNode = temp;
			}
		}

		int isInNode(int data)
		{			
			for(int i = 0 ; i < datas->Count ; i++)
			{
				if(data == datas[i]) return i;
			}
			return -1;			
		}
	};
	ref class Tree2_3_4 : public BlancedTree
	{
	protected:
		Node^ root;

	public:
		Tree2_3_4()
		{
			root = nullptr;
		}

		virtual bool insert(int data) override
		{
			Node^ next	  = root;
			Node^ current;
			while(true)
			{
				if(root == nullptr)
				{
					root = getNewNode(data);
					return true;
				}
				else
				{
					if( next->datas->Count == 3)
					{
						splitNode(next);//����
					}
					else
					{
						current = next;
						if( current->datas->Contains(data) ){ return false; }

						if(current->isLeaf())	   //���l ,��data�[�i�o�@��node
						{
							current->insertLeaf(data); //��data�[�i�o�@��node
							return true;
						}
						else					   //���O���l ,���U�@��"�`�I"				
						{
							next = findNextNode(current ,data);
						}
					}
				}
			}
		}
		virtual bool remove(int data) override
		{
			Node^ next = root;
			Node^ current;
			while(true)
			{
				if(root == nullptr) return false;
				else
				{
					if( next->datas->Count == 1 && next != root )
					{
						//�����X��,����
						List<Node^>^ neighborNode = findNeighborNode(next);
						int nodeNo				  = findPointerNo(next);
						

						if( neighborNode->Count >= 2)
						{
							if( neighborNode[1]->datas->Count > 1 )
							{
								//�����k���
								countercolockwise_Rotation(neighborNode[1] ,next ,nodeNo);
							}
							else if( neighborNode[0]->datas->Count > 1 )
							{
								//�������
								colockwise_Rotation(neighborNode[0] ,next ,nodeNo);
							}
							else
							{
								//�X��
								combine(neighborNode[0] ,next ,nodeNo);
							}
						}
						else
						{							
							if( nodeNo == 0)
							{
								if( neighborNode[0]->datas->Count > 1 )
								{
									//�u���k��
									countercolockwise_Rotation(neighborNode[0] ,next ,0);
								}	
								else
								{
									//�X��
									combine(neighborNode[0] ,next ,0);
								}
							}
							else if( nodeNo == 3)
							{
								if( neighborNode[0]->datas->Count > 1 )
								{
									//�u������
									colockwise_Rotation(neighborNode[0] ,next ,2);
								}
								else
								{
									//�X��
									combine(neighborNode[0] ,next ,2);
								}
							}
						}
					}
					else
					{
						current = next;
						int dataPos = current->isInNode(data);
						if( dataPos != -1)		  //�j���O�_�b�o�@��node
						{
							if( current->isLeaf() )
							{
								current->datas->Remove(data);//�����X�� ,�i�H�����R��
								return true;
							}
							else
							{
								Node^ inoderLeafNode     = fingNextInorder(current ,dataPos);//���"����"�U�@��

								int temp				 = current->datas[dataPos]; //��줧��洫(���ݤU�@���b�𸭧��o�@��node)
								current->datas[dataPos]  = inoderLeafNode->datas[0];
								inoderLeafNode->datas[0] = temp;

								next = findNextNode(current ,data);//next�����e���U�@��node
							}
						}
						else					//�_�hnext�e���U�@��node					   				
						{
							next = findNextNode(current ,data);

							if(next == nullptr) return false;	//�䤣��
						}
					}
				}
			}
		}

	protected:
		Node^ findNextNode(Node^ current ,int data)
		{
			for(int i = 0 ; i < current->datas->Count ; i++)
			{
				if(data < current->datas[i]) 
				{
					return current->getNextNode(i);
				}
				else if(i == current->datas->Count - 1)
				{
					return current->getNextNode(current->datas->Count);
				}
			}
		}
		Node^ fingNextInorder(Node^ current ,int dataPos)
		{
			Node^ pNode = current->getNextNode(dataPos+1);

			while(true)
			{
				if(pNode->getLeft() == nullptr)
				{
					return pNode;
				}
				else
				{
					pNode = pNode->getLeft();
				}
			}
		}

		List<Node^>^ findNeighborNode(Node^ node)
		{
			List<Node^>^ nodes = gcnew List<Node^>();

			Node^ parent = node->parent;
			for(int i = 0 ; i < 4 ; i++)
			{
				if( node == parent->getNextNode(i))
				{
					if(i-1 >= 0  && parent->getNextNode(i-1) != nullptr) 
					{
						nodes->Add(parent->getNextNode(i-1));
					}
					else nodes->Add(nullptr);
					if(i+1 <= 3 && parent->getNextNode(i+1) != nullptr) 
					{
						nodes->Add(parent->getNextNode(i+1));
					}
					else nodes->Add(nullptr);

					return nodes;//���k
				}
			}
		}
		int findPointerNo(Node^ node)
		{
			Node^ parent = node->parent;
			for(int i = 0 ; i < 4 ; i++)
			{
				if( node == parent->getNextNode(i))
				{
					return i;
				}
			}
			return -1;
		}

	protected:		
		virtual void  countercolockwise_Rotation(Node^ sourceNode ,Node^ targetNode ,int dataPos)
		{
			Node^ parent			= sourceNode->parent;
			targetNode->datas->Add(parent->datas[dataPos]);

			parent->datas[dataPos]  = sourceNode->datas[0];
			sourceNode->datas->RemoveAt(0);

			targetNode->setRightMiddle(sourceNode->getLeft());//�l��n�H��node����...
			if( sourceNode->getLeft() != nullptr )
				sourceNode->getLeft()->parent = targetNode;
			
			for(int i = 0 ; i < 3 ; i++)//node��pointer �n���s��z
			{
				sourceNode->setNextNode(i ,sourceNode->getNextNode(i+1));
			}
			sourceNode->setNextNode(3 ,nullptr);
		}
		virtual void  colockwise_Rotation(Node^ sourceNode ,Node^ targetNode ,int dataPos)
		{
			Node^ parent		   = sourceNode->parent;
			int largestPos		   = sourceNode->datas->Count-1;

			int temp			   = targetNode->datas[0];
			targetNode->datas[0]   = parent->datas[dataPos];
			targetNode->datas->Add(temp);
			parent->datas[dataPos] = sourceNode->datas[largestPos];
			sourceNode->datas->RemoveAt(largestPos);

			Node^ rNode = sourceNode->getNextNode(largestPos + 1);
			Node^ tempNode;
			for(int i = 0 ; i < 4 ; i++)//�l��n�H��node����...
			{
				tempNode = targetNode->getNextNode(i);
				targetNode->setNextNode(i ,rNode);
				rNode	 = tempNode;
			}
			if( sourceNode->getNextNode(largestPos + 1) != nullptr)
				sourceNode->getNextNode(largestPos + 1)->parent = targetNode;

			sourceNode->setNextNode(largestPos + 1 ,nullptr );//node��pointer �n���s��z
		}
		virtual Node^ combine(Node^ sourceNode ,Node^ targetNode ,int dataPos)
		{
			Node^ parent = sourceNode->parent;
			int sourceNo = findPointerNo(sourceNode);
			int targetNo = findPointerNo(targetNode);

			Node^ firstNode ,^secondNode;
			if(sourceNo < targetNo)
			{
				firstNode  = sourceNode;
				secondNode = targetNode;
			}
			else
			{
				firstNode  = targetNode;
				secondNode = sourceNode;
			}
			firstNode->datas->Add(parent->datas[dataPos]);
			firstNode->datas->Add(secondNode->datas[0]);

			firstNode->setRightMiddle(secondNode->getLeft());
			if( secondNode->getLeft() != nullptr)
				secondNode->getLeft()->parent = firstNode;

			firstNode->setRight(secondNode->getLeftMiddle());
			if( secondNode->getLeftMiddle() != nullptr)
				secondNode->getLeftMiddle()->parent = firstNode;
				
			parent->datas->RemoveAt(dataPos);//�R�����		
			if(parent->datas->Count == 0)
			{
				firstNode->parent = nullptr;
				root = firstNode;
			}
			else
			{
				firstNode->parent = parent;
				for(int i = dataPos+1 ; i < 3 ; i++)//�᭱�ɤW
				{
					parent->setNextNode(i ,parent->getNextNode(i+1));
				}
				parent->setNextNode(3 ,nullptr);
			}

			return firstNode;
		}

		virtual Node^ splitNode(Node^ node)
		{
			if( node->parent == nullptr )
			{
				root = getNewNode(node->datas[1]);
				root->setLeft(node);
				node->parent = root;

				Node^ rightNode = getNewNode(node->datas[2]);
				root->setLeftMiddle(rightNode);
				rightNode->parent = root;

				rightNode->setLeft( node->getRightMiddle() );
				rightNode->setLeftMiddle( node->getRight() );
				if( node->getRightMiddle() != nullptr )
					node->getRightMiddle()->parent = rightNode;
				if( node->getRight() != nullptr )
					node->getRight()->parent = rightNode;

				node->setRightMiddle(nullptr);
				node->setRight(nullptr);
				node->datas->RemoveRange(1 ,2);

				return root;
			}
			else
			{
				Node^ rightNode = getNewNode(node->datas[2]);
				node->parent->insertParent( node->datas[1] ,rightNode );
				rightNode->parent = node->parent;

				rightNode->setLeft( node->getRightMiddle() );
				rightNode->setLeftMiddle( node->getRight() );
				if( node->getRightMiddle() != nullptr )
					node->getRightMiddle()->parent = rightNode;
				if( node->getRight() != nullptr )
					node->getRight()->parent = rightNode;

				node->setRightMiddle(nullptr);
				node->setRight(nullptr);
				node->datas->RemoveRange(1 ,2);

				return node->parent;
			}
		}

		virtual Node^ getNewNode(int data){ return gcnew Node(data); }

		/*----�q��------------------------------------------------------------*/
		Node^ getLowerLeftHandCorner(Node^ node)
		{
			Node^ newNode = node;
			while(newNode->getLeft() != nullptr)
			{
				newNode = newNode->getLeft();
			}
			return newNode;
		}
	};

	/*====Entity============================================================================*/
	ref struct NodeEntity : public Node
	{		
		Position^ position;
		array<bool>^ dir;
		bool isPop;
		static int count = 0;

		NodeEntity(int data) : Node(data)
		{
			isPop = false;
			no    = count++;
			dir      = gcnew array<bool>(4);
			position = gcnew Position(0 ,0);
		}
		NodeEntity(List<int>^ datas ,bool isNew) :Node()
		{
			isPop = false;
			if( isNew ) no = count++;

			dir = gcnew array<bool>(4);
			this->datas =gcnew List<int>();
			for(int i = 0 ; i < datas->Count ; i++)
			{
				this->datas->Add(datas[i]);
			}
			position = gcnew Position(0 ,0);
		}
		void initDir()
		{		
			for(int i = 0 ; i < 4 ; i++)
			{
				dir[i] = true;
			}
		}
	};
	ref class Tree2_3_4Entity : public Tree2_3_4 //�u���b From �I�s��class
	{
	private:
		int focusData;
		List<Node^>^ focusNodes;
		NodeEntity^ selectNode;
		String^ des;	

	public:
		Tree2_3_4Entity() : Tree2_3_4()
		{
			focusNodes = gcnew List<Node^>();
		}


		int getFocusData()			  { return focusData;  }
		List<Node^>^ getfocusNodes()  { return getNewNodes(focusNodes); }
		NodeEntity^ getSelecteNode()  { return selectNode; }
		String^ getStatusDes()		  { return des; }

		//2-3-4����� �ާ@
		virtual bool insert(int data) override
		{
			Node^ next = root;
			Node^ current;

			this->focusData = data;
			notifyObservers("�[�J: " + data);			

			while(true)
			{
				this->focusNodes->Clear();
				if(root == nullptr)
				{
					notifyObservers("�`�I: root ����");
					root = getNewNode(data);
					
					this->selectNode = nullptr;
					notifyObservers("����!!!");
					return true;
				}
				else
				{
					String^ titleStr = "�`�I: ";
					for(int i = 0 ; i < next->datas->Count ; i++)
					{
						titleStr += next->datas[i];
						if( i != next->datas->Count-1 )
						{
							titleStr += " ,";
						}
					}
					titleStr += "\n �ݩ�: " + (next->datas->Count+1) + "-node";
					if(next == root) titleStr += "(root�`�I)";

					notifyObservers(titleStr);

					this->selectNode = (NodeEntity^)next;
					if( next->datas->Count == 3)				 //4-node�ݭn�ƥ�����
					{	
						this->focusNodes->Add((NodeEntity^)next);
						notifyObservers("���p: 4-node");

						Node^ newSplitNode = splitNode(next);	//����

						this->focusNodes->Add((NodeEntity^)newSplitNode);
						for(int i = 0 ; i < 3 ; i++)
						{
							if(newSplitNode->getNextNode(i) == next)
							{
								NodeEntity^ nodeEntity = ((NodeEntity^)newSplitNode->getNextNode(i+1) != nullptr ) 
														? (NodeEntity^)newSplitNode->getNextNode(i+1) 
														: (NodeEntity^)newSplitNode->getNextNode(i-1);
								this->focusNodes->Add(nodeEntity);
								break;
							}
						}
						next = findNextNode(newSplitNode ,data);

						this->selectNode = (NodeEntity^)next;
						notifyObservers("��������");
					}
					else
					{
						current = next;
						if(current->isLeaf())					 //���l ,��data�[�i�o�@��node
						{
							notifyObservers("���ؼи`�I");
							current->insertLeaf(data);			 //��data�[�i�o�@��node

							this->selectNode = nullptr;
							notifyObservers("����!!!");
							return true;
						}
						else 
						{
							notifyObservers("���ݤ���");
							next = findNextNode(current ,data); //���O���l ,���U�@��"�`�I"
						}
					}
				}
			}
			
		}
		virtual bool remove(int data) override
		{
			bool isAction = false;
			Node^ next = root;
			Node^ current;

			this->focusData = data;
			notifyObservers("�R��: " + data);

			while(true)
			{
				this->focusNodes->Clear();
				if(root == nullptr) 
				{
					this->selectNode = nullptr;
					notifyObservers("����!!! �䤣����");
					return false;
				}
				else
				{					
					String^ titleStr = "�`�I: ";
					for(int i = 0 ; i < next->datas->Count ; i++)
					{
						titleStr += next->datas[i];
						if( i != next->datas->Count-1 ) titleStr += " ,";
					}
					titleStr += "\n �ݩ�: " + (next->datas->Count+1) + "-node";
					if(next == root) titleStr += "(root�`�I)";

					notifyObservers(titleStr);

					this->selectNode = (NodeEntity^)next;
					if( next->datas->Count == 1 && next != root )
					{
						isAction = true;
						//���� �X��,����
						List<Node^>^ neighborNode = findNeighborNode(next);

						this->focusNodes->Add((NodeEntity^)next);
						this->focusNodes->Add((NodeEntity^)next->parent);
						String^ desProblem = "���p: 2-node ";
												
						if( neighborNode[0] == nullptr)
						{
							this->focusNodes->Add(neighborNode[1]);
							if( neighborNode[1]->datas->Count > 1 )
							{
								//�u���k��
								notifyObservers(desProblem + "�V�k�S�̭�");
								countercolockwise_Rotation(neighborNode[1] ,next ,findPointerNo(next));

								notifyObservers("���৹��");
							}	
							else
							{
								//�X��
								notifyObservers(desProblem + "�X��");

								next = combine(neighborNode[1] ,next ,findPointerNo(next));

								this->focusNodes->Clear();
								this->focusNodes->Add(next);
								notifyObservers("�X�֧���");
							}
						}
						else if(neighborNode[1] == nullptr )
						{
							this->focusNodes->Add(neighborNode[0]);
							if( neighborNode[0]->datas->Count > 1 )
							{
								//�u������
								notifyObservers(desProblem + "�V���S�̭�");
								colockwise_Rotation(neighborNode[0] ,next ,findPointerNo(neighborNode[0]));

								notifyObservers("���৹��");
							}
							else
							{
								//�X��
								notifyObservers(desProblem + "�X��");

								next = combine(neighborNode[0] ,next ,findPointerNo(neighborNode[0]));

								this->focusNodes->Clear();
								this->focusNodes->Add(next);
								this->selectNode = (NodeEntity^)next;
								notifyObservers("�X�֧���");
							}
						}
						else if( neighborNode[1]->datas->Count > 1 )
						{
							//�����k���
							this->focusNodes->Add(neighborNode[1]);
							notifyObservers(desProblem + "�V�k�S�̭�");	

							countercolockwise_Rotation(neighborNode[1] ,next ,findPointerNo(next));
							notifyObservers("���৹��");
						}
						else if( neighborNode[0]->datas->Count > 1 )
						{
							//�������
							this->focusNodes->Add(neighborNode[0]);
							notifyObservers(desProblem + "�V���S�̭�");

							colockwise_Rotation(neighborNode[0] ,next ,findPointerNo(neighborNode[0]));
							notifyObservers("���৹��");
						}
						else
						{
							//�X��
							this->focusNodes->Add(neighborNode[1]);
							notifyObservers(desProblem + "�X��");

							next = combine(neighborNode[1] ,next ,findPointerNo(next));

							this->focusNodes->Clear();
							this->focusNodes->Add(next);
							notifyObservers("�X�֧���");
						}
					}
					else
					{
						current = next;
						int dataPos = current->isInNode(data);
						if( dataPos != -1)					 //�j���O�_�b�o�@��node
						{
							if( current->isLeaf() )
							{
								notifyObservers("���ؼи`�I");
								current->datas->Remove(data);//�����X�� ,�i�H�����R��
								if( current->datas->Count == 0 && current == root )
								{
									root = nullptr;
								}

								this->selectNode = nullptr;
								notifyObservers("�R�� ����!!!");
								return true;
							}
							else
							{
								notifyObservers("���O�� \n��줤�ǤU�@�ӥ洫");
								Node^ inoderLeafNode = fingNextInorder(current ,dataPos);//���"����"�U�@��
								next = findNextNode(current ,inoderLeafNode->datas[0]);//next�����e���U�@��node

								int temp				 = current->datas[dataPos]; //��줧��洫(���ݤU�@���b�𸭧��o�@��node)
								current->datas[dataPos]  = inoderLeafNode->datas[0];
								inoderLeafNode->datas[0] = temp;

								notifyObservers("�洫����");						
							}
						}
						else					//�_�hnext�e���U�@��node					   				
						{
							if(!isAction) notifyObservers("���ݦX��or����");
							else         
							{
								isAction = false;
								notifyObservers("���b���`�I");
							}

							next = findNextNode(current ,data);

							if(next == nullptr) 
							{
								this->selectNode = nullptr;
								notifyObservers("����!!!\n�䤣����");
								return false;	//�䤣��
							}
						}
					}
				}
			}
		}
		virtual List<Node^>^ LVR()
		{				
			if( root != nullptr )
				BFS();//BFS(�p��y)

			double parentPos_x = 0;
			int leafPos_x      = 0;

			List<Node^>^ nodes      = gcnew List<Node^>();
			Collections::Generic::Stack<Node^>^ nodeStack = gcnew Collections::Generic::Stack<Node^>();

			Node^ current = root;
			Node^ temp;
			int nodeNo = 0;

			while(true)
			{
				if( current != nullptr)
				{
					temp = getNextDirNode(current);

					if( temp == nullptr) nodeNo = getNextPath(current);
					else                 nodeNo = findPointerNo(temp);					

					if( nodeNo == 0 || (temp != nullptr && nodeNo != 3) )
					{
						nodeStack->Push(current);
						if( ((NodeEntity^)current)->isPop )
						{
							if( ((NodeEntity^)current)->position->x == 0)
							{
								parentPos_x = leafPos_x-1;
							}
							parentPos_x += 0.5;

							((NodeEntity^)current)->position->x = parentPos_x;
							((NodeEntity^)current)->isPop = false;
						}
					}
					else if( temp != nullptr && nodeNo == 3 && current->getLeft()->isLeaf() )
					{
						parentPos_x += 0.5;
						((NodeEntity^)current)->position->x = parentPos_x;
					}
					
					if( nodeNo < 4 && nodeNo > -1 )
					{
						((NodeEntity^)current)->dir[nodeNo] = false;
					}
					else
					{
						MessageBox::Show("�����~!!" + nodeNo);
					}
					
					current = temp;
				}
				else
				{
					if( nodeStack->Count != 0)
					{				
						current = nodeStack->Pop();
						if(current->isLeaf()) 
						{
							((NodeEntity^)current)->position->x = leafPos_x++;
						}
						else                  
						{
							((NodeEntity^)current)->isPop = true;
						}
						if( !nodes->Contains(current) )
						{
							nodes->Add(current);
						}	
					}
					else break;
				}
			}
			List<Node^>^ newNodes = getNewNodes(nodes);//�s�إ�
			return newNodes;
		}
		List<Position^>^ getPositions()
		{
			List<Position^>^ positions = gcnew List<Position^>();
			if( root != nullptr)
			{		
				Node^ current;
				Collections::Generic::Queue<Node^>^ que = gcnew Collections::Generic::Queue<Node^>();
				que->Enqueue(root);

				const int multiply_x = 120;
				const int multiply_y = 80;					
				const int squareSize  = 30;
				const double offset_x = 0 - squareSize - squareSize/2;

				while(que->Count != 0)
				{
					current = que->Dequeue();
					for(int i = 0 ; i < 4 ; i++)
					{
						if(current->getNextNode(i) != nullptr )		   
						{
							que->Enqueue( current->getNextNode(i) );
							positions->Add( gcnew Position(((NodeEntity^)current)->position->x * multiply_x + offset_x + squareSize * i
														  ,((NodeEntity^)current)->position->y * multiply_y + squareSize/2) );
							positions->Add( gcnew Position(((NodeEntity^)current->getNextNode(i))->position->x * multiply_x 
														  ,((NodeEntity^)current->getNextNode(i))->position->y * multiply_y) );
						}
					}
					/*
					if(current->getLeft() != nullptr )		   
					{
						que->Enqueue( current->getLeft() );
						positions->Add( gcnew Position(((NodeEntity^)current)->position->x + offset_x,((NodeEntity^)current)->position->y + squareSize /2) );
						positions->Add( gcnew Position(((NodeEntity^)current->getLeft())->position->x + offset_x ,((NodeEntity^)current->getLeft())->position->y - squareSize /2 ) );
					}
					if(current->getLeftMiddle() != nullptr )	   
					{
						que->Enqueue( current->getLeftMiddle() );
						positions->Add( gcnew Position(((NodeEntity^)current)->position->x + offset_x + squareSize,((NodeEntity^)current)->position->y ) );
						positions->Add( gcnew Position(((NodeEntity^)current->getLeftMiddle())->position->x 
													  ,((NodeEntity^)current->getLeftMiddle())->position->y ) );
					}
					if(current->getRightMiddle() != nullptr )  
					{
						que->Enqueue( current->getRightMiddle() );
						positions->Add( gcnew Position(((NodeEntity^)current)->position->x ,((NodeEntity^)current)->position->y ) );
						positions->Add( gcnew Position(((NodeEntity^)current->getRightMiddle())->position->x 
													  ,((NodeEntity^)current->getRightMiddle())->position->y ) );				
					}
					if(current->getRight() != nullptr )		   
					{
						que->Enqueue( current->getRight() );
						positions->Add( gcnew Position(((NodeEntity^)current)->position->x ,((NodeEntity^)current)->position->y ) );
						positions->Add( gcnew Position(((NodeEntity^)current->getRight())->position->x 
													  ,((NodeEntity^)current->getRight())->position->y ) );	
					}
					*/
				}
			}
			return positions;
		}
	protected:
		virtual Node^ getNewNode(int data) override
		{ 
			return gcnew NodeEntity(data); 
		}

	private:
		Node^ getNextDirNode(Node^ node)
		{
			for(int i = 0 ; i < 4 ; i++)
			{
				if( ((NodeEntity^)node)->dir[i] )
				{
					return node->getNextNode(i);
				}
			}
			return nullptr;
		}
		int getNextPath(Node^ node)
		{
			for(int i = 0 ; i < 4 ; i++)
			{
				if( ((NodeEntity^)node)->dir[i] )
				{
					return i;
				}
			}
			return 4;///??
		}

		void BFS()
		{
			Node^ current;
			Collections::Generic::Queue<Node^>^ que = gcnew Collections::Generic::Queue<Node^>();
			que->Enqueue(root);

			while(que->Count != 0)
			{
				current = que->Dequeue();

				if(current->getLeft() != nullptr )		   que->Enqueue( current->getLeft() );
				if(current->getLeftMiddle() != nullptr )   que->Enqueue( current->getLeftMiddle() );
				if(current->getRightMiddle() != nullptr )  que->Enqueue( current->getRightMiddle() );
				if(current->getRight() != nullptr )		   que->Enqueue( current->getRight() );

				((NodeEntity^)current)->position->y = getPosY(current);

				//���K��l��///////////////////////
				((NodeEntity^)current)->initDir();
				((NodeEntity^)current)->isPop = false;
				((NodeEntity^)current)->position->x = 0;
			}
		}
		int getPosY(Node^ node)
		{
			if( node == root)
			{
				return 0;
			}
			else return ((NodeEntity^)node->parent)->position->y + 1;
		}

		void notifyObservers(String^ str)
		{
			des = str;
			BlancedTree::notifyObservers();
		}
		List<Node^>^ getNewNodes(List<Node^>^ nodes)
		{
			List<Node^>^ newNodes = gcnew List<Node^>();
			for(int i = 0 ; i < nodes->Count ; i++)
			{
				addAnotherNode(newNodes ,nodes[i]);
			}
			return newNodes;
		}
		void addAnotherNode(List<Node^>^ nodes ,Node^ node)
		{
			NodeEntity^ nodeEntity  = gcnew NodeEntity(node->datas ,false);
			nodeEntity->position->x = ((NodeEntity^)node)->position->x;
			nodeEntity->position->y = ((NodeEntity^)node)->position->y;
			nodeEntity->no			= ((NodeEntity^)node)->no;

			nodes->Add(nodeEntity);
		}
	};

	/*===memo===============================================================================*/
	ref struct ProcessDetail
	{
		List<Node^>^ nodes;
		List<Position^>^ positionOrders;

		ProcessDetail(List<Node^>^ nodes ,List<Position^>^ positionOrders)
		{
			this->nodes     = nodes;
			this->positionOrders = positionOrders;
		}
	};
	ref struct Tree2_3_4Backup : public Backup
	{
		List<Node^>^ selectNode;
		
		List<ProcessDetail^>^ processDetails;	
		List<List<Node^>^>^ focusNodes;
		int focusData;

		Tree2_3_4Backup()
		{			
			focusNodes     = gcnew List<List<Node^>^>();
			des			   = gcnew List<String^>();
			selectNode	   = gcnew List<Node^>();
			processDetails = gcnew List<ProcessDetail^>();
		}
		Tree2_3_4Backup(int no) : Tree2_3_4Backup()
		{
			focusData = no;
		}
	};

	/*===Observer===========================================================================*/
	ref class Tree2_3_4Display : public Display
	{
	private:
		static int multiply_x = 120;
		static int multiply_y = 80;		

	private:
		Tree2_3_4Entity^ treeEntity;
		Tree2_3_4Backup^ backup;

	public:
		Tree2_3_4Display(Tree2_3_4Entity^ treeEntity ,Panel^ treeEntityDisplay ,Panel^ eventDisplay ,ComboBox^ eventTitle)
		: Display(treeEntityDisplay ,eventDisplay ,eventTitle)
		{
			this->treeEntity   = treeEntity;

			this->eventTitleh  = 40;
			this->eventDesh    = 40;
			this->offset       = 70;
			this->squareSize   = 30;
		}
		virtual void update() override
		{
			if( treeEntity->getStatusDes()->StartsWith("�[�J:") || treeEntity->getStatusDes()->StartsWith("�R��:") )
			{
				backup = gcnew Tree2_3_4Backup( treeEntity->getFocusData() );
				eventTitle->Items->Add(treeEntity->getStatusDes());
			}
			else if( treeEntity->getStatusDes()->StartsWith("�`�I"))
			{
				backup->des->Add(treeEntity->getStatusDes());
			}
			else
			{			
				backup->focusNodes->Add( treeEntity->getfocusNodes() );
				backup->des->Add(treeEntity->getStatusDes());
				backup->selectNode->Add(treeEntity->getSelecteNode());

				List<Node^>^ nodes		   = treeEntity->LVR();
				List<Position^>^ positions = treeEntity->getPositions();
				backup->processDetails->Add( gcnew ProcessDetail(nodes ,positions) );

				if( treeEntity->getStatusDes()->Contains("����!!!"))
				{
					recovery->add( backup );
					eventTitle->SelectedIndex = eventTitle->Items->Count - 1;
				}
			}
		}
		virtual void paint() override
		{
			if (recovery->getBackUpNum() > 0)
			{
				createTreeEntity((Tree2_3_4Backup^)recovery->retrieve( currentBackUpNum ) ,currentProcessDetailNum );
			}
		}

	private:
		void createTreeEntity(Tree2_3_4Backup^ backup ,int backupNo)
		{
			graphic->Clear(Color::White);

			drawLine( backup->processDetails[backupNo]->positionOrders );
			createNodeEntities(backup ,backupNo);	
		}

		void drawLine(List<Position^>^ positionOrders)
		{
			double ax ,ay ,bx ,by;
			myPen->Color = Color::Black;
			myPen->Width = 2;

			for(int i = 0 ; i < positionOrders->Count && (i+1) < positionOrders->Count; i+=2)
			{
				/*
				ax = offset + positionOrders[i]->x   * multiply_x;
				ay = offset + positionOrders[i]->y   * multiply_y;
				bx = offset + positionOrders[i+1]->x * multiply_x;
				by = offset + positionOrders[i+1]->y * multiply_y;
				*/
				ax = offset + positionOrders[i]->x;
				ay = offset + positionOrders[i]->y;
				bx = offset + positionOrders[i+1]->x;
				by = offset + positionOrders[i+1]->y;

				PointF point1 = PointF(ax, ay);
				PointF point2 = PointF(bx, by);
				graphic->DrawLine(myPen ,point1 ,point2);
			}		
		}

		void createNodeEntities(Tree2_3_4Backup^ backup ,int backupNo)
		{
			for(int i = 0 ; i < backup->processDetails[backupNo]->nodes->Count ; i++)
			{
				drawNode((NodeEntity^)backup->processDetails[backupNo]->nodes[i] 
						 ,backup->focusNodes[backupNo] 
						 ,backup->selectNode[backupNo] 
						 ,backup->focusData );
				drawString((NodeEntity^)backup->processDetails[backupNo]->nodes[i]);
			}
		}
		void drawNode(NodeEntity^ nodeEntity ,List<Node^>^ focusNodes ,Node^ selectNode ,int focusData)
		{
			myBrush->Color = Color::White;
			
			graphic->FillRectangle(myBrush
								  ,offset + nodeEntity->position->x * multiply_x - squareSize*3/2
								  ,offset + nodeEntity->position->y * multiply_y - squareSize/2
								  ,squareSize*3,squareSize );//�\��u


			if( nodeEntity->equal((NodeEntity^)selectNode) )//��ܪ��~��
			{
				myPen->Color = ( isFocusNode(nodeEntity ,focusNodes) ) ? Color::FromArgb(0, 255, 238) : colors[3];
				myPen->Width = 2;
				int ringOffset = 10;

				graphic->DrawRectangle(myPen 
									  ,offset + nodeEntity->position->x * multiply_x - squareSize*3/2.0 - ringOffset/2.0
									  ,offset + nodeEntity->position->y * multiply_y - squareSize/2.0   - ringOffset/2.0
									  ,squareSize*3 + ringOffset ,squareSize + ringOffset);
			}
			
			if( isFocusNode(nodeEntity ,focusNodes) )
			{
				myPen->Color = colors[1];
				myPen->Width = 3;
			}
			else 
			{
				myPen->Color = colors[0];
				myPen->Width = 2;
			}
			myBrush->Color = colors[2];

			for(int i = 0 ; i < 3 ; i++)
			{
				if( i <= nodeEntity->datas->Count-1 && nodeEntity->datas[i] == focusData)
				{
					graphic->FillRectangle(myBrush
										  ,offset + nodeEntity->position->x * multiply_x - squareSize/2 + (i-1) * squareSize
										  ,offset + nodeEntity->position->y * multiply_y - squareSize/2
										  ,squareSize ,squareSize);					
				}
				graphic->DrawRectangle(myPen 
									  ,offset + nodeEntity->position->x * multiply_x - squareSize/2 + (i-1) * squareSize
									  ,offset + nodeEntity->position->y * multiply_y - squareSize/2
									  ,squareSize ,squareSize);
			}
		}
		void drawString(NodeEntity^ nodeEntity)
		{
			myBrush->Color = Color::Black;
			Font^ drawFont            = gcnew Font("�s�ө���", 12,FontStyle::Bold);	
			StringFormat^ drawFormat  = gcnew StringFormat();
			drawFormat->Alignment     = StringAlignment::Center;
			drawFormat->LineAlignment = StringAlignment::Center;

			for(int i = 0 ; i < nodeEntity->datas->Count ; i++)
			{				
				Rectangle rectangle = Rectangle(offset  + nodeEntity->position->x * multiply_x - squareSize/2 + (i-1) * squareSize
												,offset + nodeEntity->position->y * multiply_y - squareSize/2
												,squareSize ,squareSize);

				graphic->DrawString(nodeEntity->datas[i].ToString() ,drawFont ,myBrush ,rectangle ,drawFormat);
			}
		}
		
		bool isFocusNode(NodeEntity^ nodeEntity ,List<Node^>^ focusNodes)
		{
			for(int i = 0; i < focusNodes->Count ; i++)
			{
				if( nodeEntity->equal((NodeEntity^)focusNodes[i])) return true;
			}
			return false;
		}
	};
}