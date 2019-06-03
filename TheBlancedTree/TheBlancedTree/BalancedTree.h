#pragma once
#include "Template.h"

namespace BalancedTree
{
	ref struct Node
	{
		int no;

		Node(){}

		virtual bool equal(Node^ node)
		{
			if( node == nullptr)          return false;
			else if(this->no == node->no) return true;
			else						  return false;
		}
	};
	/*===BlancedTree========================================================================*/
	ref class BlancedTree : public Subject
	{
	protected:
		List<Observer^>^ observerList;
	
	public:
		BlancedTree()
		{
			observerList = gcnew List<Observer^>();
			//繼承後會再加入定位,畫圖的observer(AVL樹 ,2-3-4樹)
			//registerObserver(location);
			//registerObserver(drawing);
			//在Form register
		}
		virtual bool insert(int){return false; }
		virtual bool remove(int){return false; }

		virtual void registerObserver(Observer^ observer) override
		{
			observerList->Add(observer);
		}
		virtual void removeObserver(Observer^ observer) override
		{
			observerList->Remove(observer);
		}
		virtual void notifyObservers() override
		{
			for each(Observer^ observer in observerList)
			{
				observer->update();
			}
		}
	};

	/*====Entity============================================================================*/
	ref struct Position
	{
		float x;
		float y;

		Position(){}
		Position(float x ,float y)
		{
			this->x = x;
			this->y = y;
		}
		virtual bool equal(Position^ pos)
		{
			if( pos == nullptr) return false;
			else if(this->x == pos->x && this->y == pos->y)
			{
				return true;
			}
			else return false;
		}
	};

	/*===memo===============================================================================*/
	ref struct Backup
	{
		List<String^>^ des;
	};
	ref class  Recovery
	{
	private:
		List<Backup^>^ backups;
	public:
		Recovery() 
		{
			backups = gcnew List<Backup^>();
		}
		void add(Backup^ backup)
		{
			backups->Add(backup);
		}
		virtual Backup^ retrieve(int actionCount)
		{
			return backups[actionCount];
		}
		int getBackUpNum(){ return backups->Count; }
	};

	/*===Observer===========================================================================*/
	ref class Display : public Observer
	{	
	protected:
		Panel^ treeEntityDisplay;
		Panel^ eventDisplay;
		ComboBox^ eventTitle;

		Graphics^   graphic;
		SolidBrush^ myBrush;
		Pen^        myPen;
		static array<Color>^ colors = {Color::FromArgb(188, 255, 133) ,Color::FromArgb(255, 133, 133) 
									  ,Color::FromArgb(251, 255, 133) ,Color::FromArgb(255, 0, 255)	};

		int desWidth			= 197;
		int desTitleNum         = 0;
		int desProcessDetailNum = 0;

		Recovery^ recovery;
		int currentProcessDetailNum = 0;
		int currentBackUpNum		= 0;

		int   offset     = 40;
		float squareSize = 30;

		int eventTitleh;
		int eventDesh;

		double staticPanelWidth;
	public:
		Display(Panel^ treeEntityDisplay ,Panel^ eventDisplay ,ComboBox^ eventTitle)
		{
			this->treeEntityDisplay = treeEntityDisplay;		
			this->eventDisplay	    = eventDisplay;		
			this->eventTitle		= eventTitle;

			treeEntityDisplay->Controls->Clear();
			eventDisplay->Controls->Clear();
			eventTitle->Items->Clear();

			eventTitle->SelectedIndexChanged += gcnew System::EventHandler(this, &Display::comboBox_SelectedIndexChanged);

			graphic  = treeEntityDisplay->CreateGraphics();
			myBrush  = gcnew SolidBrush(colors[0]);
			myPen	 = gcnew Pen(Color::Black ,2);
		
			recovery = gcnew Recovery();

			staticPanelWidth   = treeEntityDisplay->Width;
		}

	protected:
		virtual void paint(){}
		virtual void createAllDisplay(Backup^ backup)
		{
			List<String^>^ strs = backup->des;
			desTitleNum	        = 0;
			desProcessDetailNum = 0;

			eventDisplay->Controls->Clear();

			if(strs->Count * eventDesh + eventDesh >= eventDisplay->Height)
			{
				desWidth  = 179;
			}
			else desWidth = 197;

			for(int i = 0 ; i < strs->Count ; i++)
			{
				if( strs[i]->StartsWith("節點"))
				{
					createTitleLabel( strs[i] );
					desTitleNum++;
				}
				else
				{
					createProcessDetailLabel( strs[i] );
					desProcessDetailNum++;

					if( strs[i]->Contains("完成!!!"))
					{
						currentProcessDetailNum = desProcessDetailNum-1;
						paint();
					}
				}
			}
		}

		void createTitleLabel(String^ des)
		{
			Label^ titleLabel		= gcnew Label();
			titleLabel->BackColor   = Color::Silver;
			titleLabel->BorderStyle = BorderStyle::FixedSingle;
			titleLabel->Font		= gcnew Font("新細明體", 12, FontStyle::Bold, GraphicsUnit::Point,static_cast<System::Byte>(136));
			titleLabel->Location	= Point(0 ,eventTitleh * desTitleNum + eventDesh * desProcessDetailNum);
			titleLabel->Name		= "titleLabel" + desTitleNum;
			titleLabel->Size		= Size(desWidth ,eventTitleh);
			titleLabel->Text		= des;
			titleLabel->TextAlign	= ContentAlignment::MiddleCenter;

			eventDisplay->Controls->Add(titleLabel);
		}
		void createProcessDetailLabel(String^ des)
		{
			Label^ processLabel		  = gcnew Label();
			processLabel->BackColor   = ( des->Contains("完成") ) ? Color::FromArgb(255, 255, 128) : Color::White;
			processLabel->BorderStyle = BorderStyle::FixedSingle;
			processLabel->Font		  = gcnew Font("新細明體", 12, FontStyle::Bold, GraphicsUnit::Point,static_cast<System::Byte>(136));
			processLabel->Location	  = Point(0 ,eventTitleh * desTitleNum + eventDesh * desProcessDetailNum);
			processLabel->Name		  = "processLabel" + desProcessDetailNum;
			processLabel->Size		  = Size(desWidth ,eventDesh);
			processLabel->Text		  = des;
			processLabel->TextAlign	  = ContentAlignment::MiddleCenter;
			processLabel->Click		 += gcnew System::EventHandler(this, &Display::desLabel_Click);
			processLabel->MouseEnter += gcnew System::EventHandler(this, &Display::desLabel_MouseEnter);
			processLabel->MouseLeave += gcnew System::EventHandler(this, &Display::desLabel_MouseLeave);

			eventDisplay->Controls->Add(processLabel);
		}

	private:
		System::Void desLabel_MouseEnter(System::Object^  sender, System::EventArgs^  e) 
		{
			((Label^)sender)->BackColor = Color::FromArgb(133, 194, 255);
		}
		System::Void desLabel_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
		{
			((Label^)sender)->BackColor = ( ((Label^)sender)->Text->Contains("完成") ) ? Color::FromArgb(255, 255, 128) : Color::White;;
		}
		System::Void desLabel_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			currentProcessDetailNum = Convert::ToInt32( ((Label^)sender)->Name->Substring(12) );
			paint();
		}
		System::Void comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			currentBackUpNum = ((ComboBox^)sender)->SelectedIndex;

			//if( recovery->getBackUpNum() >= currentBackUpNum )
			//{
				createAllDisplay( recovery->retrieve(currentBackUpNum) );
			//}
		}
	};
}