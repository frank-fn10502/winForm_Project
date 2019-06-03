#pragma once
#include "BalancedTree.h"
using namespace BalancedTree;


namespace AVLTree
{
	ref struct Node : public BalancedTree::Node
	{				
		Node^ parent;
		Node^ left;
		Node^ right;
		bool leftTheard;
		bool rightTheard;

		int height;
		int data;
		static int count = 0;

		Node(int data) : BalancedTree::Node()
		{
			this->height = 1;
			this->data   = data;

			this->parent = nullptr;
			this->left   = this;
			this->right  = this;
			leftTheard	 = true;
			rightTheard  = true;
			no = count++;
		}
		Node(int data, Node^ parent) : Node(data)
		{			
			if( parent != nullptr)
			{
				this->parent = parent;
				if (data < parent->data)
				{
					this->left		  = parent->left;
					this->leftTheard  = parent->leftTheard;
					this->right		  = parent;
					this->rightTheard = true;

					parent->left	   = this;
					parent->leftTheard = false;
				}
				else
				{
					this->right		  = parent->right;
					this->rightTheard = parent->rightTheard;
					this->left		  = parent;
					this->leftTheard  = true;

					parent->right		= this;
					parent->rightTheard = false;
				}
			}
		}
		Node(Node^ originalNode)
		{
			this->data = originalNode->data;
			this->no   = originalNode->no;
		}
	};
	ref class AVLTree : public BlancedTree
	{
	protected:
		Node^ root;

	public:
		AVLTree() : BlancedTree()
		{
			root = getNewNode(Int32::MaxValue ,nullptr);
		}

		virtual bool insert(int data) override
		{
			Node^ current = root;
			while (true)
			{
				if (data < current->data) 
				{
					if( current->leftTheard ) break;
					else                      current = current->left;
				}
				else if (data > current->data) 					   
				{
					if( current->rightTheard ) break;
					else					   current = current->right;
				}
				else return false;
			}
			Node^ node = getNewNode(data ,current);//gcnew Node(data ,parent);			
			balance(node ,false);//AVL 平衡

			return true;
		}
		virtual bool remove(int data) override 
		{
			Node^ current = root;
			while (true)
			{
				if (data < current->data)      
				{
					if( current->leftTheard ) return false;
					else                      current = current->left;
				}
				else if (data > current->data) 
				{
					if( current->rightTheard ) return false;
					else                       current = current->right;
				}
				else //找到要刪除的點
				{
					Node^ parent = current->parent;
					if (current->leftTheard && current->rightTheard)//刪除的是葉子
					{
						if (data < parent->data) 
						{
							parent->left	   = current->left;
							parent->leftTheard = current->leftTheard;
						}
						else					 
						{
							parent->right	    = current->right;
							parent->rightTheard = current->rightTheard;
						}
					}
					else if (current->leftTheard)//刪除的節點只有"右子樹"*
					{
						if (data < parent->data) parent->left  = current->right;
						else					 parent->right = current->right;				 

						Node^ newNod	   = getLowerLeftHandCorner(current->right);//右子樹繼承刪除節點的左邊
						newNod->left	   = current->left;
						newNod->leftTheard = current->leftTheard;

						current->right->parent = parent;
					}
					else if (current->rightTheard)//刪除的節點只有"左子樹"*
					{
						if (data < parent->data) parent->left  = current->left;
						else					 parent->right = current->left;

						Node^ newNod	    = getLowerRightHandCorner(current->left);//左子樹繼承"刪除節點的右邊"
						newNod->right	    = current->right;
						newNod->rightTheard = current->rightTheard;

						current->left->parent = parent;
					}
					else//刪除的節點"兩邊都有子樹"
					{
						Node^ newNode       = getLowerLeftHandCorner(current->right);//找到最右邊的最小值
						Node^ newNodeParent = newNode->parent;

						int temp = current->data;		//交換之後會刪除 ,所以不用換?
						current->data = newNode->data;
						newNode->data = temp;			//交換之後會刪除 ,所以不用換?
						current = newNode;/////

						if(newNode->rightTheard)//右邊沒有節點
						{
							if( newNode == newNodeParent->left)
							{
								newNodeParent->left       = newNode->left;
								newNodeParent->leftTheard = newNode->leftTheard;
							}
							else
							{
								newNodeParent->right       = newNode->right;
								newNodeParent->rightTheard = newNode->rightTheard;
							}
						}
						else
						{
							if( newNode == newNodeParent->left) newNodeParent->left  = newNode->right;
							else                                newNodeParent->right = newNode->right;
						

							Node^ newNodeLeftCorner		  = getLowerLeftHandCorner(newNode->right);
							newNodeLeftCorner->left		  = newNode->left;
							newNodeLeftCorner->leftTheard = newNode->leftTheard;

							newNode->right->parent		  = newNodeParent;
						}
					}
										
					balance(current ,true);//AVL 平衡
					return true;
				}

				if (current == root) return false;//找不到
			}		
		}
		virtual List<Node^>^ LVR()
		{		
			Node^ current = getLowerLeftHandCorner(root->left);

			List<Node^>^ nodes = gcnew List<Node^>();
			bool threadIn = false;

			while(current != root)
			{
				if( current->leftTheard || threadIn )
				{
					threadIn  = current->rightTheard;
					addAnotherNode(nodes ,current);

					current   = current->right;
				}
				else current  = current->left;
			}
			return nodes;
		}

	protected:
		virtual Node^ getNewNode(int data, Node^ parent)
		{
			return gcnew Node(data ,parent);
		}
		virtual void addAnotherNode(List<Node^>^ nodes ,Node^ node)
		{
			nodes->Add(node);
		}
		virtual void notifyObservers(String^ str){}

	protected:
		virtual void balance(Node^ node ,bool isDelete)
		{
			Node^ current = node->parent;

			while(current != root)
			{
				int blancedFactor = getBlancedFactor(current);

				if( blancedFactor <= -2 )
				{
					if( node->data <= current->right->data)
					{
						//RL(高度有可能有問題)					
						RLRotation(current);
					}
					else
					{
						//RR
						RRRotation(current);					
					}
				}
				else if( blancedFactor >= 2 )
				{
					if( node->data <= current->left->data)
					{
						//LL
						LLRotation(current);					
					}
					else
					{
						//LR(高度有可能有問題)
						LRRotation(current);				
					}
				}

				current->height = getHeight(current);
				current = current->parent;
			}
		}
		void LLRotation(Node^ node)
		{
			Node^ parent = node->parent;
			Node^ pivot  = node->left;

			if( node == parent->left) parent->left  = pivot;
			else                      parent->right = pivot;		
			pivot->parent = parent;

			if(pivot->rightTheard)
			{
				//node->left = node->left;
				node->leftTheard = true;
			}
			else
			{
				node->left = pivot->right;
				pivot->right->parent = node;
			}

			node->parent = pivot;
			pivot->right = node;
			pivot->rightTheard = false;
		}
		void RRRotation(Node^ node)
		{
			Node^ parent = node->parent;
			Node^ pivot  = node->right;

			if( node == parent->left) parent->left  = pivot;
			else                      parent->right = pivot;			
			pivot->parent = parent;

			if(pivot->leftTheard)
			{
				//node->right = node->right;
				node->rightTheard = true;
			}
			else
			{
				node->right = pivot->left;
				pivot->left->parent = node;
			}

			node->parent	  = pivot;
			pivot->left		  = node;
			pivot->leftTheard = false;
		}
		void RLRotation(Node^ node)
		{
			Node^ parent	 = node->parent;
			Node^ pivot		 = node->right->left;
			Node^ pivotRight = node->right;

			if( node == parent->left) parent->left  = pivot;
			else                      parent->right = pivot;
			pivot->parent = parent;

			if(pivot->leftTheard)
			{
				node->right       = pivot;
				node->rightTheard = true;
			}
			else
			{
				node->right			= pivot->left;
				pivot->left->parent = node;
			}
			if(pivot->rightTheard)
			{
				pivotRight->left	   = pivot;
				pivotRight->leftTheard = true;
			}
			else
			{
				pivotRight->left     = pivot->right;
				pivot->right->parent = pivotRight;
			}

			node->parent	  = pivot;
			pivot->left		  = node;
			pivot->leftTheard = false;

			pivotRight->parent = pivot;
			pivot->right	   = pivotRight;
			pivot->rightTheard = false;

			//重新計算高度
			pivotRight->height = getHeight(pivotRight);
		}
		void LRRotation(Node^ node)
		{
			Node^ parent	= node->parent;
			Node^ pivot		= node->left->right;
			Node^ pivotLeft = node->left;

			if( node == parent->left) parent->left  = pivot;
			else                      parent->right = pivot;
			pivot->parent = parent;

			if(pivot->leftTheard)
			{
				pivotLeft->right       = pivot;
				pivotLeft->rightTheard = true;
			}
			else
			{
				pivotLeft->right	= pivot->left;
				pivot->left->parent = pivotLeft;
			}
			if(pivot->rightTheard)
			{
				node->left		 = pivot;
				node->leftTheard = true;
			}
			else
			{
				node->left		     = pivot->right;
				pivot->right->parent = node;
			}

			node->parent	   = pivot;
			pivot->right	   = node;
			pivot->rightTheard = false;

			pivotLeft->parent  = pivot;
			pivot->left	       = pivotLeft;
			pivot->leftTheard  = false;

			//重新計算高度
			pivotLeft->height = getHeight(pivotLeft);
		}

	/*====通用============================================================*/
		Node^ getLowerLeftHandCorner(Node^ node)
		{
			Node^ newNode = node;
			while(!newNode->leftTheard)
			{
				newNode = newNode->left;
			}
			return newNode;
		}
		Node^ getLowerRightHandCorner(Node^ node)
		{
			Node^ newNode = node;
			while(!newNode->rightTheard)
			{
				newNode = newNode->right;
			}
			return newNode;
		}
		int getHeight(Node^ node)
		{
			int leftHeight ,rightHeight;
			if( node->leftTheard ) leftHeight = 0;
			else                   leftHeight = node->left->height;

			if( node->rightTheard ) rightHeight = 0;
			else                    rightHeight = node->right->height;

			leftHeight++;
			rightHeight++;

			return (leftHeight >= rightHeight) ? leftHeight : rightHeight;
		}
		int getBlancedFactor(Node^ node)
		{
			int leftHeight ,rightHeight;
			if( node->leftTheard ) leftHeight = 0;
			else                   leftHeight = node->left->height;

			if( node->rightTheard ) rightHeight = 0;
			else                    rightHeight = node->right->height;

			return (leftHeight - rightHeight);
		}
	};

	/*====Entity============================================================================*/
	ref struct NodeEntity : public Node
	{
		Position^ position;
		static int pos_x = 0;
		
		NodeEntity(int data, Node^ parent) : Node(data ,parent)
		{
			position = gcnew Position(0 ,0);
		}
		NodeEntity(NodeEntity^ originalNodeEntity) : Node(originalNodeEntity)
		{
			position = gcnew Position(originalNodeEntity->position->x 
									 ,originalNodeEntity->position->y);
		}
	};
	ref class AVLTreeEntity : public AVLTree //真正在 From 呼叫的class
	{
	private:
		String^ des;
		Node^ focusNode;
		Node^ selectNode;
		int blancedFactor;
		int currentData;

	public:
		double maxPanelWidth;

	public:
		AVLTreeEntity() : AVLTree(){}

		NodeEntity^ getFocusNode()    { return (NodeEntity^)focusNode;  }
		NodeEntity^ getSelecteNode()  { return (NodeEntity^)selectNode; }
		String^     getStatusDes()	  { return des; }
		int			getBlancedFactor(){ return blancedFactor; }

		//針對AVL樹的操作
		virtual bool insert(int data) override
		{
			this->currentData = data;
			return AVLTree::insert(data);
		}
		virtual bool remove(int data) override
		{
			this->currentData = data;
			return AVLTree::remove(data);
		}

		virtual List<Node^>^ LVR() override
		{
			if( !root->leftTheard ) BFS();//BFS(計算y)				

			NodeEntity::pos_x = 0;//計算x
			return AVLTree::LVR();
		}
		List<Position^>^ getPositions()
		{
			Collections::Generic::Queue<Node^>^ que = gcnew Collections::Generic::Queue<Node^>();
			List<Position^>^ positions = gcnew List<Position^>();
		
			NodeEntity ^current ,^currentLeft ,^currentRight;
			maxPanelWidth = 0;
			que->Enqueue(root->left);			

			while(que->Count != 0)
			{
				current = (NodeEntity^)que->Dequeue();

				if(!current->leftTheard)  
				{
					currentLeft = (NodeEntity^)current->left;

					que->Enqueue(currentLeft);
					positions->Add( gcnew Position( current->position->x ,current->position->y ) );
					positions->Add( gcnew Position( currentLeft->position->x ,currentLeft->position->y ) );
				}
				if(!current->rightTheard) 
				{
					currentRight = (NodeEntity^)current->right;

					que->Enqueue(current->right);
					positions->Add( gcnew Position( current->position->x ,current->position->y ) );
					positions->Add( gcnew Position( currentRight->position->x ,currentRight->position->y ) );
				}
				maxPanelWidth = (maxPanelWidth >= current->position->x) ? maxPanelWidth : current->position->x;
			}
			return positions;
		}

	protected:
		virtual void  balance(Node^ node ,bool isDelete) override
		{
			focusNode = node;
			Node^ current;
			
			if( isDelete )
			{
				current = node->parent;
				focusNode = nullptr;
				notifyObservers( "刪除: " + currentData );
			}
			else 
			{
				current   = node;
				focusNode = node;
				notifyObservers( "加入: " + currentData );
			}

			while( current != root )
			{
				this->blancedFactor = getBlancedFactor(current);
				selectNode			= current;
				notifyObservers("節點: " + current->data + "平衡因子: " + blancedFactor);

				if( blancedFactor <= -2 )
				{
					if(isDelete)
					{
						if( getBlancedFactor(current->right) <= -1)
						{
							notifyObservers("狀況: RR");
							RRRotation(current);
						}
						else
						{
							notifyObservers("狀況: RL");							
							RLRotation(current);
						}
					}
					else
					{
						if( node->data <= current->right->data)
						{
							//RL				
							notifyObservers("狀況: RL");
							RLRotation(current);
						}
						else
						{
							//RR
							notifyObservers("狀況: RR");
							RRRotation(current);					
						}
					}
					notifyObservers("平衡完成");
				}
				else if( blancedFactor >= 2 )
				{
					if(isDelete)
					{
						if( getBlancedFactor(current->left) <= -1)
						{
							notifyObservers("狀況: LR");
							LRRotation(current);
						}
						else
						{
							notifyObservers("狀況: LL");						
							LLRotation(current);
						}
					}
					else
					{
						if( node->data <= current->left->data)
						{
							//LL
							notifyObservers("狀況: LL");
							LLRotation(current);					
						}
						else
						{
							//LR
							notifyObservers("狀況: LR");
							LRRotation(current);				
						}
					}
					notifyObservers("平衡完成");
				}
				else notifyObservers("不需要平衡");

				current->height = getHeight(current);
				current			= current->parent;
			}
			this->focusNode  = nullptr;
			this->selectNode = nullptr;
			notifyObservers("完成!!!");
		}
		virtual Node^ getNewNode(int data, Node^ parent) override
		{
			return gcnew NodeEntity(data ,parent);
		}
		virtual void  addAnotherNode(List<Node^>^ nodes ,Node^ node) override
		{
			((NodeEntity^)node)->position->x = NodeEntity::pos_x++;
			nodes->Add( gcnew NodeEntity( (NodeEntity^)node ) );
		}
		virtual void  notifyObservers(String^ str) override
		{
			des = str;
			BlancedTree::notifyObservers();
		}

	private:		
		void BFS()
		{
			Node^ current;
			Collections::Generic::Queue<Node^>^ que = gcnew Collections::Generic::Queue<Node^>();
			que->Enqueue(root->left);

			while(que->Count != 0)
			{
				current = que->Dequeue();

				if(!current->leftTheard)  que->Enqueue(current->left);
				if(!current->rightTheard) que->Enqueue(current->right);

				((NodeEntity^)current)->position->y = ((NodeEntity^)current->parent)->position->y + 1;
			}
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
	ref struct AVLBackup : public Backup
	{
		List<NodeEntity^>^ selectNode;	
		List<ProcessDetail^>^ processDetails;	
		List<NodeEntity^>^ focusNodes;
		List<double>^ inPanelPercentages;

		List<int>^ blancedFactor;		

		AVLBackup()
		{
			focusNodes	   = gcnew List<NodeEntity^>();
			des			   = gcnew List<String^>();
			selectNode	   = gcnew List<NodeEntity^>();
			blancedFactor  = gcnew List<int>();
			processDetails = gcnew List<ProcessDetail^>();
			inPanelPercentages = gcnew List<double>();
		}
	};

	/*===Observer===========================================================================*/
	ref class AVLTreeDisplay : public Display
	{
	private:
		AVLTreeEntity^ treeEntity;
		const int multiply = 40;

		AVLBackup^ backup;
		
	public:
		AVLTreeDisplay(AVLTreeEntity^ treeEntity ,Panel^ treeEntityDisplay ,Panel^ eventDisplay ,ComboBox^ eventTitle) 
		: Display(treeEntityDisplay ,eventDisplay ,eventTitle)
		{
			this->treeEntity   = treeEntity;

			this->eventTitleh  = 30;
			this->eventDesh    = 30;
			this->offset       = 40;
			this->squareSize   = 30;			
		}

		virtual void update() override
		{
			if( treeEntity->getStatusDes()->StartsWith("加入:") || treeEntity->getStatusDes()->StartsWith("刪除:") )
			{
				backup = gcnew AVLBackup();
			
				eventTitle->Items->Add( treeEntity->getStatusDes() );
			}
			else if( treeEntity->getStatusDes()->StartsWith("節點"))
			{
				backup->des->Add(treeEntity->getStatusDes());
			}
			else
			{
				backup->des->Add(treeEntity->getStatusDes());
				backup->focusNodes->Add(treeEntity->getFocusNode());			
				backup->selectNode->Add(treeEntity->getSelecteNode());
				backup->blancedFactor->Add(treeEntity->getBlancedFactor());

				List<Node^>^ nodes         = treeEntity->LVR();
				List<Position^>^ positions = treeEntity->getPositions();
				backup->processDetails->Add( gcnew ProcessDetail(nodes ,positions) );

				treeEntity->maxPanelWidth = treeEntity->maxPanelWidth * multiply + offset + squareSize;
				treeEntity->maxPanelWidth = ( treeEntity->maxPanelWidth >= staticPanelWidth ) ? treeEntity->maxPanelWidth : staticPanelWidth;
				double inPanelPercentage = staticPanelWidth / treeEntity->maxPanelWidth;
				backup->inPanelPercentages->Add(inPanelPercentage);

				if( treeEntity->getStatusDes()->Contains("完成!!!") )
				{
					recovery->add( backup );	
					eventTitle->SelectedIndex = eventTitle->Items->Count - 1;//會同時顯示"樹"
				}
			}
		}
		virtual void paint() override
		{
			if (recovery->getBackUpNum() > 0)
			{
				createTreeEntity((AVLBackup^)recovery->retrieve(currentBackUpNum)  ,currentProcessDetailNum);
			}
		}

	private:
		void createTreeEntity(AVLBackup^ backup ,int backupNo)
		{		
			graphic->Clear(Color::White);

			drawLine(backup->processDetails[backupNo]->positionOrders 
					,backup->inPanelPercentages[backupNo] );
			createNodeEntities(backup ,backupNo);
		}

		void drawLine(List<Position^>^ positionOrders ,double inPanelPercentage)
		{
			float ax ,ay ,bx ,by;
			myPen->Color = Color::Black;
			myPen->Width = 1;

			for(int i = 0 ; i < positionOrders->Count && (i+1) < positionOrders->Count; i+=2)
			{
				ax = (offset + positionOrders[i]->x    * multiply )* inPanelPercentage;
				ay = (offset + positionOrders[i]->y    * multiply )* inPanelPercentage;
				bx = (offset + positionOrders[i+1]->x  * multiply )* inPanelPercentage;;
				by = (offset + positionOrders[i+1]->y  * multiply )* inPanelPercentage;;
				graphic->DrawLine(myPen ,ax ,ay ,bx ,by);
			}		
		}

		void createNodeEntities(AVLBackup^ backup ,int backupNo)
		{		
			for(int i = 0 ; i < backup->processDetails[backupNo]->nodes->Count ; i++)
			{
				drawNode((NodeEntity^)backup->processDetails[backupNo]->nodes[i] 
						 ,backup->focusNodes[backupNo] 
						 ,backup->selectNode[backupNo] 
						 ,backup->blancedFactor[backupNo] 
						 ,backup->inPanelPercentages[backupNo]);

				drawString( (NodeEntity^)backup->processDetails[backupNo]->nodes[i] 
							,backup->inPanelPercentages[backupNo]);
			}
		}
		void drawNode(NodeEntity^ nodeEntity ,Node^ focusNode ,Node^ selectNode ,int blancedFactor ,double inPanelPercentage)
		{ 
			if( nodeEntity->equal(selectNode) )
			{
				myPen->Color = colors[3];
				myPen->Width = 1;
				int ringOffset = 10;
				graphic->DrawEllipse(myPen ,(offset + nodeEntity->position->x * multiply - squareSize/2 - ringOffset/2) * inPanelPercentage
										   ,(offset + nodeEntity->position->y * multiply - squareSize/2 - ringOffset/2) * inPanelPercentage
										   ,squareSize + ringOffset,squareSize + ringOffset);
			}

			if( nodeEntity->equal(focusNode) ) myBrush->Color = colors[2];
			else if( nodeEntity->equal(selectNode) && (blancedFactor >= 2 || blancedFactor <= -2) )
			{
				myBrush->Color = colors[1];
			}
			else myBrush->Color = colors[0];
		
			graphic->FillEllipse(myBrush ,(offset + nodeEntity->position->x * multiply - squareSize/2) * inPanelPercentage
										 ,(offset + nodeEntity->position->y * multiply - squareSize/2) * inPanelPercentage
										 ,squareSize ,squareSize);
		}
		void drawString(NodeEntity^ nodeEntity ,double inPanelPercentage)
		{
			myBrush->Color = Color::Black;
			Font^ drawFont            = gcnew Font("新細明體", 12,FontStyle::Bold);	
			StringFormat^ drawFormat  = gcnew StringFormat();
			drawFormat->Alignment     = StringAlignment::Center;
			drawFormat->LineAlignment = StringAlignment::Center;
			
			Rectangle rectangle = Rectangle((offset  + nodeEntity->position->x * multiply - squareSize/2) * inPanelPercentage
										   ,(offset  + nodeEntity->position->y * multiply - squareSize/2) * inPanelPercentage
										   ,squareSize ,squareSize);

			graphic->DrawString(nodeEntity->data.ToString() ,drawFont ,myBrush ,rectangle ,drawFormat);
		}		
	};
}