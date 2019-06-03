#pragma once
#include "SMSortBehavior.h"

using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class ButtonOnOff
{
public:
	static void setButtonStyle(Button^ button, bool on)
	{
		if (on)
		{
			button->Enabled = true;
			button->BackColor = Color::Gray;
		}
		else
		{
			button->Enabled = false;
			button->BackColor = Color::FromArgb(224, 224, 224);
		}
	}
};
ref class NumberBar 
{
private:
	static const int MaxHeight = 300;
	static const int MaxWidth  = 10;

	static const int SPACE = 13;
	static const int PANELHEIGHT = 350;
public:
	static Rectangle getRectangle(int pos ,int num ,int largestNum)
	{
		int width = MaxWidth;
		int height = MaxHeight * num / largestNum;
		int x = SPACE * pos;
		int y = PANELHEIGHT - height;

		return Rectangle(x ,y ,width , height);
	}
};

ref class NumbersImp : public EntityObserver
{
private:
	Graphics^ mygraphics;
	SolidBrush^ myBrush;
public:
	NumbersImp(Panel^ canvas)
	{
		mygraphics = canvas->CreateGraphics();
		myBrush    = gcnew SolidBrush(Color::FromArgb(0, 204, 153));
	}
	virtual void updateData(array<int>^ numbers, int largestNum) override
	{
		mygraphics->Clear(Color::White);
		for(int i = 0; i < numbers->Length; i++)
		{
			mygraphics->FillRectangle(myBrush ,NumberBar::getRectangle(i ,numbers[i] , largestNum) );
		}
	}
};
ref class LargestPosImp : public ObserverLargestPos
{
private:
	Graphics^ mygraphics;
	SolidBrush^ myBrush;
public:
	LargestPosImp(Panel^ canvas)
	{
		mygraphics = canvas->CreateGraphics();
		myBrush = gcnew SolidBrush(Color::FromArgb(255, 212, 128));
	}
	virtual void update(array<int>^ numbers, int largestNum ,List<int>^ allLargestPos) override
	{
		for each(int pos in allLargestPos)
		{
			mygraphics->FillRectangle(myBrush, NumberBar::getRectangle(pos, numbers[pos], largestNum));
		}
	}
	virtual void add(array<int>^ numbers, int largestNum, int addPos) override
	{
		mygraphics->FillRectangle(myBrush, NumberBar::getRectangle(addPos, numbers[addPos], largestNum));
	}
};
ref class SelectPosImp : public ObserverSelectPos
{
private:
	Graphics^ mygraphics;
	SolidBrush^ myBrush;
	array<Color>^ colors;
public:
	SelectPosImp(Panel^ canvas)
	{
		mygraphics = canvas->CreateGraphics();
		colors = gcnew array<Color>{ Color::FromArgb(255, 112, 77) ,Color::FromArgb(102, 140, 255) , Color::FromArgb(217, 140, 179) };
		myBrush= gcnew SolidBrush(colors[0]);
	}
	virtual void update(array<int>^ numbers, int largestNum, List<int>^ selectPos, int TypeN) override
	{
		for each(int pos in selectPos )
		{
			myBrush->Color = colors[TypeN-1];
			mygraphics->FillRectangle(myBrush, NumberBar::getRectangle(pos, numbers[pos], largestNum));
		}
	}
};
ref class StateDesImp : public ObserverStateInfo
{
private:
	Label^ stateDes_Label;
public:
	StateDesImp(Label^ stateDes_Label)
	{
		this->stateDes_Label = stateDes_Label;
	}
	virtual void update(String^ desStr, int currentState, int lastState) override
	{
		stateDes_Label->Text = desStr;
	}
};
ref class SortStateImp : public ObserverStateInfo
{
private:
	Label^ stateDes_Label;
	Button^ preButton;
	Button^ postButton;
public:
	SortStateImp(Label^ stateDes_Label ,Button^ preButton ,Button^ postButton)
	{
		this->stateDes_Label = stateDes_Label;
		this->preButton  = preButton;
		this->postButton = postButton;
	}
	virtual void update(String^ desStr, int currentState, int lastState) override
	{
		stateDes_Label->Text = desStr;

		if (currentState == 1)
		{
			ButtonOnOff::setButtonStyle(preButton, false);
			ButtonOnOff::setButtonStyle(postButton, true);
		}
		else if (currentState == lastState)
		{
			ButtonOnOff::setButtonStyle(preButton, true);
			ButtonOnOff::setButtonStyle(postButton, false);
		}
		else
		{
			ButtonOnOff::setButtonStyle(preButton, true);
			ButtonOnOff::setButtonStyle(postButton, true);
		}
	}
};

ref class SortStatusImp : public ObserverSortStartEnd
{
private:
	Button^ sortButton;
	Button^ createButton;
	Panel^ createPanel;
public:
	SortStatusImp(Button^ sortButton ,Button^ createButton , Panel^ createPanel)
	{
		this->sortButton   = sortButton;
		this->createButton = createButton;
		this->createPanel = createPanel;
	}
	virtual void update(bool nowStart ,bool notEnd) override
	{
		ButtonOnOff::setButtonStyle(sortButton ,notEnd);
		
		if (nowStart) sortButton->Text = "開始";
		if (!notEnd)//結束
		{
			ButtonOnOff::setButtonStyle(createButton, !notEnd);
			createPanel->Enabled = !notEnd;
			sortButton->Text = "開始";
		}
	}
};