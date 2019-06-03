#pragma once
#include "BalancedTree.h"
using namespace BalancedTree;

namespace RedBlackTree
{
	enum State {red = 1 ,black ,doubleBlack};
	enum Action : bool{insert = true ,remove = false};

	ref struct PositionWithColor : public Position
	{
		State color;

		PositionWithColor(float x ,float y ,State color) : Position(x ,y)
		{
			this->color = color;
		}
	};

	ref struct Node : public BalancedTree::Node
	{
		static int count = 0;
		State status;
		int data;

		Node^ parent;
		Node^ left;
		Node^ right;

		Node(){};
		Node(int data ,bool isNew) : Node(data ,nullptr ,isNew){}
		Node(int data, Node^ parent ,bool isNew) : BalancedTree::Node()
		{
			this->status = red;
			this->data   = data;
			if( parent != nullptr )
			{
				this->parent = parent;

				if (data <= parent->data) parent->left  = this;
				else                      parent->right = this;
			}
			if(isNew) no = count++;			
		}
		bool isLeaf()
		{
			return ( !this->left && !this->right );
		}
	};
	ref class RedBlackTree : public BlancedTree
	{
	protected:
		Node^ root;

	public:
		RedBlackTree() : BlancedTree()
		{
			root = getNewNode(Int32::MaxValue ,nullptr ,true);
		}

		virtual bool insert(int data) override
		{			
			Node^ next = root->left;
			Node^ current;
			while (true)
			{
				if( isHaveTwoRed(next) )
				{
					splitNode(next);//�۷�� 2-3-4�𪺤���
				}
				else
				{
					current = next;
					if (data < current->data) 
					{
						if( !current->left )break;
						else                next = current->left;
					}
					else if (data > current->data) 					   
					{
						if( !current->right )break;
						else				 next = current->right;
					}	
					else return false;
				}				
			}
			Node^ node = getNewNode(data ,current ,true);

			//���¾� ����
			balance(node ,Action::insert);
			///
			return true;
		}
		virtual bool remove(int data) override
		{
			Node^ next = root->left;
			Node^ current;
			while(true)
			{
				if(next == nullptr) 
				{
					return false;
				}
				else
				{
					if(is_2_Node(next) && next != root->left)//2-node
					{
						//���� �X��,����
						Node^ neighborNode = findNeighborNode(next);
						if( is_2_Node(neighborNode) )
						{
							//�X��
							combine(neighborNode ,next);
						}
						else
						{
							//����
							rotation(neighborNode ,next);
						}
					}
					else						   //3-node or 4-node 
					{
						current = next;
						if(current->data == data)
						{
							if( current->isLeaf() ) //�����R��
							{								
								if(current = current->left) current->left  = nullptr;
								else                        current->right = nullptr;
							}
							else					//�M�U�@�ӥ洫
							{
								Node^ inoderLeafNode     = findInorderNode(next);
								next = ( inoderLeafNode->data > current->data ) ? current->right : current->left;//next = �U�@��

								int temp				 = current->data; //��줧��洫(���ݤU�@���b�𸭧��o�@��node)
								current->data            = inoderLeafNode->data;
								inoderLeafNode->data     = temp;								
							}
						}
						else
						{
							next = ( data > current->data ) ? current->right : current->left;//next = �U�@��
							if(next == nullptr) return false;//�䤣��
						}
					}
				}
			}
		}
		virtual List<Node^>^ LVR()
		{
			List<Node^>^ nodes = gcnew List<Node^>();
			Collections::Generic::Stack<Node^>^ nodeStack = gcnew Collections::Generic::Stack<Node^>();
			Node^ current = root->left;
			while(true)
			{
				if( current != nullptr)
				{
					nodeStack->Push(current);
					current = current->left;
				}
				else
				{
					if( nodeStack->Count != 0)
					{
						current = nodeStack->Pop();
						current = current->right;
						nodes->Add(current);
					}
					else break;					
				}
			}
			return nodes;
		}

	protected:
		virtual Node^ getNewNode(int data, Node^ parent ,bool isNewNode)
		{
			return gcnew Node(data ,parent ,isNewNode);
		}
		virtual void splitNode(Node^ node)//�۷�� 2-3-4�𪺤���
		{
			node->left->status  = black;
			node->right->status = black;
			if( node != root->left )
				node->status = red;
		}
		virtual void balance(Node^ node ,Action action)
		{
			Node^ parent;
			Node^ current = node->parent;
			Node^ PassedNode = current;

			while(current != root)
			{
				if( current->status == State::red)
				{
					if(PassedNode)
					{
						parent = current->parent;
						if( current == parent->left )
						{
							if( current->data > PassedNode->data ) LLRotation(parent ,Action::insert);//LL
							else                                   LRRotation(parent ,Action::insert);//LR
						}
						else
						{
							if( current->data > PassedNode->data ) RLRotation(parent ,Action::insert);//RL
							else                                   RRRotation(parent ,Action::insert);//RR
						}
						PassedNode = nullptr;
					}
					else PassedNode = current;
				}
				else PassedNode = nullptr;

				current = current->parent;
				//root->left->status = State::black;
			}
			root->left->status = State::black;
		}
		Node^ LLRotation(Node^ node ,Action action)
		{
			Node^ parent = node->parent;
			Node^ pivot  = node->left;

			if( node == parent->left) parent->left  = pivot;
			else                      parent->right = pivot;		
			pivot->parent = parent;

			node->left = pivot->right;
			if( pivot->right )
				pivot->right->parent = node;

			node->parent = pivot;
			pivot->right = node;

			if( action != Action::remove )
			{
				//node->status		 = red;
				pivot->status        = black;
				pivot->right->status = red;
				pivot->left->status  = red;
			}
			return pivot;
		}
		Node^ RRRotation(Node^ node ,Action action)
		{
			Node^ parent = node->parent;
			Node^ pivot  = node->right;

			if( node == parent->left) parent->left  = pivot;
			else                      parent->right = pivot;			
			pivot->parent = parent;

			node->right = pivot->left;
			if( pivot->left )
				pivot->left->parent = node;

			node->parent = pivot;
			pivot->left  = node;

			if( action != Action::remove )
			{
				//node->status		= red;
				pivot->status        = black;
				pivot->left->status  = red;	
				pivot->right->status = red;
			}
			return pivot;
		}
		Node^ RLRotation(Node^ node ,Action action)
		{
			Node^ parent	 = node->parent;
			Node^ pivot		 = node->right->left;
			Node^ pivotRight = node->right;

			if( node == parent->left ) parent->left  = pivot;
			else                       parent->right = pivot;
			pivot->parent = parent;

			node->right = pivot->left;
			if( pivot->left )
				pivot->left->parent = node;

			pivotRight->left = pivot->right;
			if( pivot->right )
				pivot->right->parent = pivotRight;

			node->parent = pivot;
			pivot->left  = node;

			pivotRight->parent = pivot;
			pivot->right	   = pivotRight;

			if( action != Action::remove )
			{
				node->status       = red;
				pivot->status      = black;
				pivotRight->status = red;
			}
			return pivot;
		}
		Node^ LRRotation(Node^ node ,Action action)
		{
			Node^ parent	= node->parent;
			Node^ pivot		= node->left->right;
			Node^ pivotLeft = node->left;

			if( node == parent->left) parent->left  = pivot;
			else                      parent->right = pivot;
			pivot->parent = parent;

			pivotLeft->right = pivot->left;
			if( pivot->left )
				pivot->left->parent = pivotLeft;

			node->left = pivot->right;
			if( pivot->right )
				pivot->right->parent = node;

			node->parent	   = pivot;
			pivot->right	   = node;

			pivotLeft->parent  = pivot;
			pivot->left	       = pivotLeft;

			if( action != Action::remove )
			{
				node->status      = red;
				pivot->status     = black;
				pivotLeft->status = red;
			}
			return pivot;
		}

	protected:
		bool isHaveTwoRed(Node^ node)
		{
			if( !node->left || !node->right ) return false;
			else
			{
				return ( node->left->status  == red && 
						 node->right->status == red );
			}
		}
		bool is_2_Node(Node^ node)
		{
			return    node->status != State::red && 
				   ( !node->left  || node->left->status  == State::black ) && 
				   ( !node->right || node->right->status == State::black );
		}
		Node^ findNeighborNode(Node^ node)
		{
			Node^ parent = node->parent;
			if( node == parent->right )
			{
				if( parent->left->status != State::red ) 
					return parent->left;
				else									 
					return parent->left->right;
			}
			else
			{
				if( parent->right->status != State::red ) 
					return parent->right;
				else                                      
					return parent->right->left;
			}
		}
		int nodePointerRedNum(Node^ node)
		{
			int i= 0;
			if(node->right->status == State::red) i++;
			if(node->left->status  == State::red) i++;

			return i;
		}
		Node^ findInorderNode(Node^ node)
		{
			Node^ pNode;
			if( node->right )
			{
				pNode = node->right;
				while(true)
				{
					if( pNode->left == nullptr )return pNode;
					else						pNode = pNode->left;
				}
			}
			else
			{
				pNode = node->left;
				while(true)
				{
					if( pNode->right == nullptr )return pNode;
					else						 pNode = pNode->right;
				}
			}
		}
		virtual void combine(Node^ sourceNode ,Node^ targetNode)//��,�k���O2-node
		{
			Node^ parent = targetNode->parent;
			/*
			if( sourceNode == parent->left || sourceNode == parent->right )
			{
					sourceNode->status  = State::red;
					targetNode->status  = State::red;
					parent->status      = State::black;
			}
			else
			*/
			if( !(sourceNode == parent->left || sourceNode == parent->right) )
			{
				if( targetNode == parent->right )
				{
					parent = LLRotation(parent ,Action::remove);
					//parent->status     = State::black;
					//sourceNode->status = State::red;
					//targetNode->status = State::red;
				}
				else
				{
					parent = RRRotation(parent ,Action::remove);
					//parent->status     = State::black;
					//sourceNode->status = State::red;
					//targetNode->status = State::red;
				}
			}
			parent->status     = State::black;
			sourceNode->status = State::red;
			targetNode->status = State::red;
		}
		virtual void rotation(Node^ sourceNode ,Node^ targetNode)
		{
			Node^ parent = targetNode->parent;
			Node^ newParent;
			if( sourceNode == parent->left || sourceNode == parent->right )
			{				
				if( targetNode == parent->right )
				{					
					if( sourceNode->right != nullptr )
					{
						Node^ temp = RRRotation(sourceNode ,Action::remove);
						temp->status       = State::black;
						temp->left->status = State::black;
					}
					else sourceNode->left->status = State::black;
					newParent = LLRotation(parent ,Action::remove);
				}
				else
				{
					if( sourceNode->left != nullptr )
					{
						Node^ temp = LLRotation(sourceNode ,Action::remove);
						temp->status        = State::black;
						temp->right->status = State::black;
					}
					else sourceNode->right->status = State::black;
					newParent = RRRotation(parent ,Action::remove);
				}
				newParent->status  = parent->status;//State::red;
				parent->status     = State::black;
				targetNode->status = State::red;
			}
			else
			{
				if( targetNode == parent->right )
				{
					if( sourceNode->right != nullptr )
					{
						Node^ temp = RRRotation(sourceNode ,Action::remove);
						temp->status       = State::black;
						temp->left->status = State::black;
					}
					else sourceNode->left->status = State::black;
					newParent = LRRotation(parent ,Action::remove);
					//newParent->status  = State::black;
					//parent->status     = State::black;
					//targetNode->status = State::red;
				}
				else
				{
					if( sourceNode->left != nullptr )
					{
						Node^ temp = LLRotation(sourceNode ,Action::remove);
						temp->status        = State::black;
						temp->right->status = State::black;
					}
					else sourceNode->right->status = State::black;
					newParent = RLRotation(parent ,Action::remove);			
				}
				targetNode->status = State::red;
			}		
		}
	};

	/*====Entity============================================================================*/
	ref struct NodeEntity : public Node
	{
		Position^ position;
		static int pos_x = 0;

		NodeEntity(int data ,bool isNew) : Node(data ,isNew)
		{
			position = gcnew Position(-1 ,-1);
		}
		NodeEntity(int data, Node^ parent ,bool isNew) : Node(data ,parent ,isNew)
		{
			position = gcnew Position(0 ,0);
		}
		NodeEntity(NodeEntity^ originalNodeEntity) : Node()
		{
			position = gcnew Position(originalNodeEntity->position->x 
									 ,originalNodeEntity->position->y);
			this->status = originalNodeEntity->status;
			this->no     = originalNodeEntity->no;
			this->data   = originalNodeEntity->data;
		}
	};
	ref class RedBlackTreeEntity : public RedBlackTree
	{
	private:
		String^ des;
		Node^ selectNode;

	public:
		double maxPanelWidth;

	public:
		RedBlackTreeEntity() : RedBlackTree()
		{
			maxPanelWidth = 0;
		}
		
		NodeEntity^ getSelecteNode()  { return ((NodeEntity^)selectNode); }
		String^     getStatusDes()	  { return des; }

		virtual bool insert(int data) override
		{			
			Node^ next = root;
			Node^ current;
			
			notifyObservers("�[�J: " + data);	

			while (true)
			{
				if( root->left == nullptr ) notifyObservers("�`�I: root ����");
				else if( next != root )     notifyObservers("�`�I: " + next->data.ToString() );

				if( next == root ) this->selectNode = nullptr;
				else			   this->selectNode = (NodeEntity^)next;

				if( isHaveTwoRed(next) )
				{
					notifyObservers("���p: ��Ӭ���l�`�I\n�۷�(4-node)");
					
					splitNode(next);//�۷�� 2-3-4�𪺤���
					
					notifyObservers("�C���令�\\n(��������)");
				}
				else 
				{
					if( next != root )
						notifyObservers("���ݧ���C��\n(���ݤ���)");
				}
				current = next;
				if (data < current->data) 
				{
					if( !current->left )
					{
						notifyObservers("���ؼи`�I");
						current->left = getNewNode(data ,current ,true);
						current = current->left;

						this->selectNode = current;
						break;
					}
					else next = current->left;
				}
				else if (data > current->data) 					   
				{
					if( !current->right )
					{
						notifyObservers("���ؼи`�I");
						current->right = getNewNode(data ,current ,true);
						current = current->right;

						this->selectNode = current;
						break;
					}							
					else next = current->right;
				}	
				else 
				{
					notifyObservers("����!!!");
					return false;
				}
			}		
			this->selectNode = nullptr;
			notifyObservers("�s�W����");
			

			//���¾� ����
			balance(current ,Action::insert);
			///
			return true;
		}
		virtual bool remove(int data) override
		{
			Node^ next = root->left;
			Node^ current;

			notifyObservers("�R��: " + data);	

			while(true)
			{
				if(next == nullptr) 
				{
					notifyObservers("����!!! �䤣����");
					return false;
				}
				else
				{
					this->selectNode = next;
					notifyObservers("�`�I: " + next->data);	

					if(is_2_Node(next) && next != root->left)//2-node
					{
						//���� �X��,����
						String^ decProblem = "���p: �۷�(2-node) \n";
						Node^ neighborNode = findNeighborNode(next);
						if( is_2_Node(neighborNode) )
						{
							//�X��
							notifyObservers( decProblem + "�X��");	
							combine(neighborNode ,next);
							notifyObservers("�X�֧���");
						}
						else
						{
							//����
							notifyObservers( decProblem + "����");
							rotation(neighborNode ,next);
							notifyObservers("���৹��");
						}
					}
					else						     //3-node or 4-node 
					{
						current = next;
						if(current->data == data)
						{
							if( current->isLeaf() ) //�����R��
							{								
								if(current == current->parent->left) 
								{
									notifyObservers("���ؼи`�I");
									current->parent->left  = nullptr;

									notifyObservers("����!!!");
									return true;
								}	
								else  
								{
									notifyObservers("���ؼи`�I");
									current->parent->right = nullptr;

									notifyObservers("����!!!");
									return true;
								}									
							}
							else					//�M�U�@�ӥ洫
							{
								notifyObservers("���O�� \n��줤�ǤU�@�ӥ洫");

								Node^ inoderLeafNode     = findInorderNode(next);
								next = ( inoderLeafNode->data > current->data ) ? current->right : current->left;//next = �U�@��

								int temp				 = current->data; //��줧��洫(���ݤU�@���b�𸭧��o�@��node)
								current->data            = inoderLeafNode->data;
								inoderLeafNode->data     = temp;

								notifyObservers("�洫����");	
							}
						}
						else
						{
							notifyObservers("���ݦX��or����");
							next = ( data > current->data ) ? current->right : current->left;//next = �U�@��
							
							if(next == nullptr) 
							{
								this->selectNode = nullptr;
								notifyObservers("����!!! �䤣����");
								return false;//�䤣��
							}
						}
					}
				}
			}
		}
		virtual List<Node^>^ LVR() override
		{
			if( root->left )
				BFS();

			List<Node^>^ nodes = gcnew List<Node^>();
			if( root->left )
			{			
				int pos_x = 0;

				Collections::Generic::Stack<Node^>^ nodeStack = gcnew Collections::Generic::Stack<Node^>();
				Node^ current = root->left;
				while(true)
				{
					if( current != nullptr)
					{
						nodeStack->Push(current);
						current = current->left;
					}
					else
					{
						if( nodeStack->Count != 0)
						{
							current = nodeStack->Pop();							
							((NodeEntity^)current)->position->x = pos_x++;

							nodes->Add( gcnew NodeEntity((NodeEntity^)current) );
							current = current->right;
						}
						else break;					
					}
				}
			}
			return nodes;
		}
		List<PositionWithColor^>^ getPositions()
		{
			List<PositionWithColor^>^ positions = gcnew List<PositionWithColor^>();
			if( root->left )
			{
				Node^ current;
				Collections::Generic::Queue<Node^>^ que = gcnew Collections::Generic::Queue<Node^>();
				que->Enqueue(root->left);
				maxPanelWidth = 0;

				while(que->Count != 0)
				{
					current = que->Dequeue();

					if( current->left )  
					{
						que->Enqueue(current->left);
						positions->Add( gcnew PositionWithColor(((NodeEntity^)current)->position->x 
															   ,((NodeEntity^)current)->position->y ,current->left->status ) );
						positions->Add( gcnew PositionWithColor(((NodeEntity^)current->left)->position->x 
															   ,((NodeEntity^)current->left)->position->y ,current->left->status ) );
					}
					if( current->right ) 
					{
						que->Enqueue(current->right);
						positions->Add( gcnew PositionWithColor(((NodeEntity^)current)->position->x 
															   ,((NodeEntity^)current)->position->y ,current->right->status ) );
						positions->Add( gcnew PositionWithColor(((NodeEntity^)current->right)->position->x 
															   ,((NodeEntity^)current->right)->position->y ,current->right->status ) );
					}
					maxPanelWidth = ( maxPanelWidth >= ((NodeEntity^)current)->position->x ) ? maxPanelWidth : ((NodeEntity^)current)->position->x;
				}
			}
			return positions;
		}

	protected:
		virtual Node^ getNewNode(int data, Node^ parent ,bool isNewNode) override
		{
			Node^ node =  gcnew NodeEntity(data ,parent ,isNewNode);
			if( parent == root) node->status = State::black;

			return node;
		}
		virtual void balance(Node^ node ,Action action) override
		{
			Node^ parent;
			Node^ current = node->parent;
			Node^ PassedNode = node;

			while(current != root)
			{
				this->selectNode = (NodeEntity^)current;
				notifyObservers("�`�I: " + current->data);
				if( current->status == State::red)
				{
					if(PassedNode)
					{
						parent = current->parent;
						if( current == parent->left )
						{
							if( current->data > PassedNode->data ) 
							{
								notifyObservers("���p: LL");
								LLRotation(current->parent ,Action::insert);//LL								
							}
							else                                   
							{
								notifyObservers("���p: LR");
								LRRotation(current->parent ,Action::insert);//LR
							}
							notifyObservers("���৹��");
						}
						else
						{
							if( current->data > PassedNode->data ) 
							{
								notifyObservers("���p: RL");
								RLRotation(current->parent ,Action::insert);//RL
							}
							else                                   
							{
								notifyObservers("���p: RR");
								RRRotation(current->parent ,Action::insert);//RR
							}
							notifyObservers("���৹��");
						}
						PassedNode = nullptr;
					}
					else 
					{
						notifyObservers("���ݱ���");
						PassedNode = current;
					}
				}
				else
				{
					notifyObservers("���ݱ���");
					PassedNode = nullptr;
				}
				current = current->parent;			
			}
			root->left->status = State::black;
			this->selectNode = nullptr;
			notifyObservers("����!!!");
		}
		virtual void combine(Node^ sourceNode ,Node^ targetNode) override//��,�k���O2-node
		{
			Node^ parent = targetNode->parent;
			if( !(sourceNode == parent->left || sourceNode == parent->right) )
			{
				if( targetNode == parent->right )
				{
					parent = LLRotation(parent ,Action::remove);
				}
				else
				{
					parent = RRRotation(parent ,Action::remove);
				}
			}
			parent->status     = State::black;
				
			targetNode->parent->status = State::black;
			sourceNode->status = State::red;			
			targetNode->status = State::red;
		}
		virtual void rotation(Node^ sourceNode ,Node^ targetNode) override
		{
			Node^ parent = targetNode->parent;
			Node^ newParent;
			if( sourceNode == parent->left || sourceNode == parent->right )
			{				
				if( targetNode == parent->right )
				{					
					if(sourceNode->right != nullptr && sourceNode->right->status == State::red)
					{
						Node^ temp = RRRotation(sourceNode ,Action::remove);
						temp->status       = State::black;
						temp->left->status = State::black;
					}
					else sourceNode->left->status = State::black;
					newParent = LLRotation(parent ,Action::remove);
				}
				else
				{
					if(sourceNode->left != nullptr && sourceNode->left->status == State::red)
					{
						Node^ temp = LLRotation(sourceNode ,Action::remove);
						temp->status        = State::black;
						temp->right->status = State::black;
					}
					else sourceNode->right->status = State::black;
					newParent = RRRotation(parent ,Action::remove);
				}
				newParent->status  = parent->status;//State::red;
				parent->status     = State::black;
				targetNode->status = State::red;
			}
			else
			{
				if( targetNode == parent->right )
				{
					if( sourceNode->right != nullptr && sourceNode->right->status == State::red )
					{
						Node^ temp = RRRotation(sourceNode ,Action::remove);
						temp->status       = State::black;
						temp->left->status = State::black;
					}
					else 
					{
						if(sourceNode->left)
						   sourceNode->left->status = State::black;
					}
					newParent = LRRotation(parent ,Action::remove);
				}
				else
				{
					if( sourceNode->left != nullptr && sourceNode->left->status == State::red )
					{
						Node^ temp = LLRotation(sourceNode ,Action::remove);
						temp->status        = State::black;
						temp->right->status = State::black;
					}
					else 
					{
						if(sourceNode->right)
						   sourceNode->right->status = State::black;
					}
					newParent = RLRotation(parent ,Action::remove);			
				}
				newParent->status  = parent->status;//State::red;
				parent->status     = State::black;
				targetNode->status = State::red;
			}		
		}

	private:
		void notifyObservers(String^ str)
		{
			des = str;
			BlancedTree::notifyObservers();
		}
		void BFS()
		{
			Node^ current;
			Collections::Generic::Queue<Node^>^ que = gcnew Collections::Generic::Queue<Node^>();
			que->Enqueue(root->left);

			while(que->Count != 0)
			{
				current = que->Dequeue();

				if( current->left )  que->Enqueue(current->left);
				if( current->right ) que->Enqueue(current->right);

				((NodeEntity^)current)->position->y = ((NodeEntity^)current->parent)->position->y + 1;
			}
		}
		
	};

	/*===memo===============================================================================*/
	ref struct ProcessDetail
	{
		List<Node^>^ nodes;
		List<PositionWithColor^>^ posAndColorOrders;

		ProcessDetail(List<Node^>^ nodes ,List<PositionWithColor^>^ posAndColorOrders )
		{
			this->nodes             = nodes;
			this->posAndColorOrders = posAndColorOrders;
		}
	};
	ref struct RedBlackBackup : public Backup
	{			
		List<ProcessDetail^>^ processDetails;
		List<Node^>^ selectNode;
		List<Node^>^ focusNodes;
		List<double>^ inPanelPercentages;

		RedBlackBackup()
		{
			focusNodes		   = gcnew List<Node^>();
			des				   = gcnew List<String^>();
			selectNode		   = gcnew List<Node^>();
			processDetails     = gcnew List<ProcessDetail^>();
			inPanelPercentages = gcnew List<double>();
		}
	};

	/*===Observer===========================================================================*/
	ref class RedBlackTreeDisplay : public Display
	{
	private:
		RedBlackTreeEntity^ treeEntity;
		const int multiply = 40;

		RedBlackBackup^ backup;
		
	public:
		RedBlackTreeDisplay(RedBlackTreeEntity^ treeEntity ,Panel^ treeEntityDisplay ,Panel^ eventDisplay ,ComboBox^ eventTitle) 
		: Display(treeEntityDisplay ,eventDisplay ,eventTitle)
		{
			this->treeEntity   = treeEntity;
			
			this->eventTitleh  = 40;
			this->eventDesh    = 40;
			this->offset       = 40;
			this->squareSize   = 30;
		}
		virtual void update() override
		{
			if( treeEntity->getStatusDes()->StartsWith("�[�J:") || treeEntity->getStatusDes()->StartsWith("�R��:") )
			{
				backup = gcnew RedBlackBackup();
			
				eventTitle->Items->Add( treeEntity->getStatusDes() );
			}
			else if( treeEntity->getStatusDes()->StartsWith("�`�I"))
			{
				backup->des->Add(treeEntity->getStatusDes());
			}
			else
			{
				backup->des->Add(treeEntity->getStatusDes());						
				backup->selectNode->Add(treeEntity->getSelecteNode());

				List<Node^>^ nodes = treeEntity->LVR();
				List<PositionWithColor^>^ positions = treeEntity->getPositions();
				backup->processDetails->Add( gcnew ProcessDetail( nodes,positions) );

				treeEntity->maxPanelWidth = treeEntity->maxPanelWidth * multiply + offset + squareSize;
				treeEntity->maxPanelWidth = ( treeEntity->maxPanelWidth >= staticPanelWidth ) ? treeEntity->maxPanelWidth : staticPanelWidth;
				double inPanelPercentage = staticPanelWidth / treeEntity->maxPanelWidth;
				backup->inPanelPercentages->Add(inPanelPercentage);

				if( treeEntity->getStatusDes()->Contains("����!!!"))
				{
					recovery->add( backup );	
					eventTitle->SelectedIndex = eventTitle->Items->Count-1;//���K���s�i��
				}
			}
		}
		virtual void paint() override
		{
			if (recovery->getBackUpNum() > 0)
			{
				createTreeEntity((RedBlackBackup^)recovery->retrieve(currentBackUpNum)  ,currentProcessDetailNum);
			}
		}

	private:
		void createTreeEntity(RedBlackBackup^ backup ,int backupNo)
		{		
			graphic->Clear(Color::White);

			drawLine(backup->processDetails[backupNo]->posAndColorOrders 
					,backup->inPanelPercentages[backupNo] );
			createNodeEntities(backup ,backupNo);	
		}

		void createNodeEntities(RedBlackBackup^ backup ,int backupNo)
		{		
			for(int i = 0 ; i < backup->processDetails[backupNo]->nodes->Count ; i++)
			{
				drawNode((NodeEntity^)backup->processDetails[backupNo]->nodes[i] 
						 ,backup->selectNode[backupNo]  
						 ,backup->inPanelPercentages[backupNo]);

				drawString((NodeEntity^)backup->processDetails[backupNo]->nodes[i] 
						   ,backup->inPanelPercentages[backupNo]);
			}
		}
		void drawNode(NodeEntity^ nodeEntity ,Node^ selectNode ,double inPanelPercentage)
		{ 
			if( nodeEntity->equal(selectNode) )
			{
				if( nodeEntity->status == State::red )  myPen->Color = Color::FromArgb(0, 255, 238);
				else if( nodeEntity->equal(selectNode)) myPen->Color = colors[3];			
				myPen->Width = 2;

				int ringOffset = 10;
				graphic->DrawEllipse(myPen ,(offset + nodeEntity->position->x * multiply - squareSize/2 - ringOffset/2) * inPanelPercentage
										   ,(offset + nodeEntity->position->y * multiply - squareSize/2 - ringOffset/2) * inPanelPercentage
										   ,squareSize + ringOffset,squareSize + ringOffset);
			}

			if( nodeEntity->status == State::red ) myBrush->Color = Color::FromArgb(205,92,92);
			else                                   myBrush->Color = Color::FromArgb(105,105,105);
		
			graphic->FillEllipse(myBrush ,(offset + nodeEntity->position->x * multiply - squareSize/2) * inPanelPercentage
										 ,(offset + nodeEntity->position->y * multiply - squareSize/2) * inPanelPercentage
										 ,squareSize ,squareSize);
		}
		void drawString(NodeEntity^ nodeEntity ,double inPanelPercentage)
		{
			if( nodeEntity->status == State::red ) myBrush->Color = Color::Black;
			else                                   myBrush->Color = Color::White;
			

			Font^ drawFont            = gcnew Font("�s�ө���", 12,FontStyle::Bold);	
			StringFormat^ drawFormat  = gcnew StringFormat();
			drawFormat->Alignment     = StringAlignment::Center;
			drawFormat->LineAlignment = StringAlignment::Center;
			
			Rectangle rectangle = Rectangle((offset  + nodeEntity->position->x * multiply - squareSize/2) * inPanelPercentage
										   ,(offset  + nodeEntity->position->y * multiply - squareSize/2) * inPanelPercentage
										   ,squareSize ,squareSize);

			graphic->DrawString(nodeEntity->data.ToString() ,drawFont ,myBrush ,rectangle ,drawFormat);
		}
		void drawLine(List<PositionWithColor^>^ positionOrders ,double inPanelPercentage)
		{
			float ax ,ay ,bx ,by;
			//myPen->Color = Color::Black;
			myPen->Width = 2;

			for(int i = 0 ; i < positionOrders->Count && (i+1) < positionOrders->Count; i+=2)
			{
				if( positionOrders[i]->color == State::red) myPen->Color = Color::Red;
				else                                        myPen->Color = Color::Black;

				ax = (offset + positionOrders[i]->x    * multiply )* inPanelPercentage;
				ay = (offset + positionOrders[i]->y    * multiply )* inPanelPercentage;
				bx = (offset + positionOrders[i+1]->x  * multiply )* inPanelPercentage;;
				by = (offset + positionOrders[i+1]->y  * multiply )* inPanelPercentage;;
				graphic->DrawLine(myPen ,ax ,ay ,bx ,by);
			}		
		}
	};
}

