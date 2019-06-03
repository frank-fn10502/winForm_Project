#pragma once
#include "SMSortBehavior.h"

using namespace System;
using namespace System::Windows::Forms;

ref class State
{
public:
	static const int LASTSTATE = 8;
	virtual void setStartStatus() {}

	virtual System::Void Sort(Object^ sender, EventArgs^ e) {}
	virtual void skip() {}
	virtual void forward() {}
};
ref struct SpaceMergeStepMember 
{
	SMSortBehavior^ numbersEntity;

	int posA, posB;
	int largestStartPos, largestEndPos;
	int stepNum;

	SpaceMergeStepMember()
	{
		numbersEntity = gcnew SMSortBehavior();
	}
};
ref class Backup
{
private:
	SpaceMergeStepMember^ member;
	State^ current;
public:
	Backup(SpaceMergeStepMember^ member ,State^ current)
	{
		this->member = gcnew SpaceMergeStepMember();

		this->member->numbersEntity->copyData( member->numbersEntity );
		this->member->posA = member->posA;
		this->member->posB = member->posB;
		this->member->largestStartPos = member->largestStartPos;
		this->member->largestEndPos   = member->largestEndPos;
		this->member->stepNum		  = member->stepNum;

		this->current = current;
	}

	SpaceMergeStepMember^ getMember() { return member; }
	State^ getCurrentState()		  { return current;}
};
ref class Recovery
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
	Backup^ retrieve(int stateNum)//1~7
	{
		for each(Backup^ backup in backups)
		{
			if (backup->getMember()->stepNum == stateNum)
			{
				int backupNum	   = backups->IndexOf(backup);
				int backupToEndNum = backups->Count - backupNum;
				backups->RemoveRange(backupNum ,backupToEndNum);

				return backup;
			}
		}
	}
};

ref class SpaceMergeStep
{
protected:
	Recovery^ recovery;
	SpaceMergeStepMember^ member;
	
public:
	SpaceMergeStep(NumbersEntity^ numbersEntity)
	{
		recovery = gcnew Recovery();
		member   = gcnew SpaceMergeStepMember();	
		member->numbersEntity = gcnew SMSortBehavior();
		member->numbersEntity->copyData(numbersEntity);

		member->posA = 0;
		member->posB = 0;
		member->largestStartPos = 0;
		member->largestEndPos = 0;
		member->stepNum = 1;
	}
	State^ findLargestStep;
	State^ shiftToMidStep;
	State^ sortLastSegStep;
	State^ shiftToFirstStep;
	State^ sortAllSegStep;
	State^ findABposStep;
	State^ sortABStep;

	void setPosA(int a) { member->posA = a; }
	int  getPosA()		{ return member->posA; }
	void setPosB(int b) { member->posB = b; }
	int  getPosB()		{ return member->posB; }
	void setLargestStartPos(int pos)   { member->largestStartPos = pos; }
	int  getLargestStartPos()		   { return member->largestStartPos; }
	void setLargestEndPos(int pos)     { member->largestEndPos = pos; }
	int  getLargestEndPos()			   { return member->largestEndPos; }
	void setStepNum(int num)		   { member->stepNum = num; }/////
	int getStepNum()				   { return member->stepNum;}/////
	SMSortBehavior^ getNumbersEntity() { return member->numbersEntity; }
	Recovery^ getRecovery()			   { return recovery; }

	virtual Backup^ backup() = 0;
	virtual void setState(State^ state){};
	virtual void nextStep(){};
	virtual void theEnd(){};
};

/*--------------------------------排序的步驟----------------------------------------------*/
ref class FindLargest : public State
{
private:
	SpaceMergeStep^ smSort;
	SMSortBehavior^ numbersEntity;

	int limitedFindNum;
	int findNum;
	int posA, posB;
public:
	FindLargest(SpaceMergeStep^ smSort)
	{		
		this->smSort = smSort;
	}
	virtual void setStartStatus() override
	{
		this->numbersEntity = smSort->getNumbersEntity();

		numbersEntity->changeStateInfo("找到最大的8個數字" , smSort->getStepNum(), LASTSTATE);
		smSort->getRecovery()->add(smSort->backup());

		findNum = 0;
		limitedFindNum = (int)Math::Sqrt(numbersEntity->getQuantity());
		posA = numbersEntity->getQuantity() / 2 - 1;//31;	//假設有64個數字
		posB = numbersEntity->getQuantity() - 1;//63;
	}

	virtual void skip() override
	{
		while(true)
		{
			if (sortMethod()) break;
		}
	}
	virtual System::Void Sort(Object^  sender, EventArgs^  e) override//將八個最大值找出來
	{	
		sortMethod();
	}

	virtual void forward() override
	{
		smSort->setStepNum( smSort->getStepNum()+1 );
		smSort->setState(smSort->shiftToMidStep);
	}
private:
	bool sortMethod()
	{
		if (numbersEntity->getNumber(posA) > numbersEntity->getNumber(posB))
		{
			numbersEntity->addLargestPos(posA);
			posA--;
			findNum++;
		}
		else if (numbersEntity->getNumber(posA) == numbersEntity->getNumber(posB))
		{
			numbersEntity->addLargestPos(posA);
			posA--;
			findNum++;
			if (findNum < limitedFindNum)
			{
				numbersEntity->addLargestPos(posB);
				posB--;
				findNum++;
			}
		}
		else
		{
			numbersEntity->addLargestPos(posB);
			posB--;
			findNum++;
		}

		if (findNum == limitedFindNum)
		{
			smSort->setPosA(++posA);
			smSort->setPosB(++posB);
			smSort->nextStep();

			return true;
		}
		return false;
	}
};
ref class ShiftToMid : public State
{
private:
	SpaceMergeStep^ smSort;
	SMSortBehavior^ numbersEntity;

	int count;
	int switchPos;
	int posA, posB;
public:
	ShiftToMid(SpaceMergeStep^ smSort)
	{
		this->smSort = smSort;
	}
	virtual void setStartStatus() override
	{
		this->numbersEntity = smSort->getNumbersEntity();

		numbersEntity->changeStateInfo("把8個最大值移到中間", smSort->getStepNum() , LASTSTATE);
		smSort->getRecovery()->add(smSort->backup());//recovery

		posA = smSort->getPosA();
		posB = smSort->getPosB();
		count = numbersEntity->getQuantity() - posB;

		int halfPos = numbersEntity->getQuantity() / 2 - 1;
		int sqrtNum = (int)Math::Sqrt(numbersEntity->getQuantity());
		switchPos = halfPos - sqrtNum + 1;//只要往後n-1格就好 因為有包跨自己 //24
	}

	virtual void skip() override
	{
		while(true)
		{
			if (sortMethod()) break;
		}
	}
	virtual System::Void Sort(Object^  sender, EventArgs^  e) override
	{
		sortMethod();
	}

	virtual void forward() override
	{
		smSort->setStepNum(smSort->getStepNum() + 1);
		smSort->setState(smSort->sortLastSegStep);
	}
private:
	bool sortMethod()
	{
		if (count > 0)
		{
			numbersEntity->switchDataL(posB, switchPos);

			posB++;
			switchPos++;
			count--;
			return false;
		}
		else
		{
			smSort->nextStep();
			return true;
		}
	}
};
ref class SortLastSeg : public State
{
private:
	SpaceMergeStep^ smSort;
	SMSortBehavior^ numbersEntity;
	int startPos;
	int endPos;
public:
	SortLastSeg(SpaceMergeStep^ smSort)
	{
		this->smSort = smSort;
	}
	virtual void setStartStatus() override
	{
		numbersEntity = smSort->getNumbersEntity();

		if (smSort->getStepNum() == 7)
		{
			numbersEntity->changeStateInfo("排續最後的八個(Bubble Sort)", smSort->getStepNum(), LASTSTATE);
		}
		else
		{
			numbersEntity->changeStateInfo("排續最後的八個(Bubble Sort)", smSort->getStepNum(), LASTSTATE);		
		}	
		smSort->getRecovery()->add(smSort->backup());//recovery

		int sqrtNum = (int)Math::Sqrt(numbersEntity->getQuantity());
		startPos = numbersEntity->getQuantity() - sqrtNum; //56;
		endPos = numbersEntity->getQuantity() - 1; //63;
		setMark(startPos ,endPos);
	}

	virtual void skip() override
	{
		while (true)
		{
			if (sortMethod())break;
		}
	}
	virtual System::Void Sort(Object^  sender, EventArgs^  e) override
	{
		//bubble sort(暫時)
		sortMethod();
	}

	virtual void forward() override
	{
		if ( smSort->getStepNum() == 7 )
		{
			smSort->setStepNum(smSort->getStepNum() + 1);
			smSort->theEnd();
		}
		else
		{
			smSort->setStepNum(smSort->getStepNum() + 1);
			smSort->setState(smSort->shiftToFirstStep);
		}
	}
private:
	bool sortMethod()
	{		
		bool change = false;
		for (int i = startPos; i < endPos; i++)
		{
			if (numbersEntity->getNumber(i) > numbersEntity->getNumber(i + 1))
			{
				numbersEntity->switchDataWithoutNotify(i, i + 1);
				change = true;
			}
		}
		endPos--;
		numbersEntity->notifyStatusChange();
		
		if ( !change || endPos == startPos)
		{
			numbersEntity->clearSelectPos();/////
			numbersEntity->notifyStatusChange();

			smSort->nextStep();
			return true;
		}
		return false;
	}
	void setMark(int start ,int end)
	{
		for (int i = start ; i <= end ; i++)
		{
			numbersEntity->addSelectPos(i, 3);
		}
		numbersEntity->notifyStatusChange();
	}
};
ref class ShiftToFirst : public State
{
private:
	SpaceMergeStep^ smSort;
	SMSortBehavior^ numbersEntity;
	int firstPos;
	int secondPos;
public:
	ShiftToFirst(SpaceMergeStep^ smSort)
	{
		this->smSort = smSort;
	}
	virtual void setStartStatus() override
	{
		this->numbersEntity = smSort->getNumbersEntity();

		numbersEntity->changeStateInfo("最大的八個移到最前面", smSort->getStepNum(), LASTSTATE);
		smSort->getRecovery()->add(smSort->backup());//recovery

		firstPos  = 0;
		secondPos = 24;
	}

	virtual void skip() override
	{
		while (true)
		{
			if (sortMethod())break;
		}
	}
	virtual System::Void Sort(Object^  sender, EventArgs^  e) override
	{
		sortMethod();
	}

	virtual void forward() override
	{
		smSort->setStepNum(smSort->getStepNum() + 1);
		smSort->setState(smSort->sortAllSegStep);
	}
private:
	bool sortMethod()
	{
		if (firstPos < 8)
		{
			numbersEntity->switchDataL(secondPos, firstPos);

			firstPos++;
			secondPos++;
			return false;
		}
		else
		{
			smSort->setLargestStartPos(0);
			smSort->setLargestEndPos(7);
			smSort->nextStep();
			return true;
		}
	}
};
ref class SortAllSeg : public State
{
private:
	SpaceMergeStep^ smSort;
	SMSortBehavior^ numbersEntity;
	array<int>^ numbersSegLast;
	int i;
public:
	SortAllSeg(SpaceMergeStep^ smSort)
	{
		this->smSort = smSort;
	}
	virtual void setStartStatus() override
	{
		this->numbersEntity = smSort->getNumbersEntity();

		numbersEntity->changeStateInfo("後面7段按照順序排好", smSort->getStepNum(), LASTSTATE);
		smSort->getRecovery()->add(smSort->backup());//recovery

		numbersSegLast = gcnew array<int>(7); //第一段都是最大的 (8-1)
		for (int i = 7 + 8 ,j = 0 ; i < 64 ; i += 8, j++)
		{
			numbersSegLast[j] = i;
		}
		i = 8 - 1;
	}

	virtual void skip() override
	{
		while (true)
		{
			if (sortMethod())break;
		}
	}
	virtual System::Void Sort(Object^  sender, EventArgs^  e) override
	{
		sortMethod();
	}

	virtual void forward() override
	{
		smSort->setStepNum(smSort->getStepNum() + 1);
		smSort->setState(smSort->findABposStep);
	}

private:
	bool sortMethod()
	{
		int change = 1;
		for (int j = 0; j < i - 1; j++)
		{
			if (numbersEntity->getNumber(numbersSegLast[j]) >
				numbersEntity->getNumber(numbersSegLast[j + 1]))
			{
				switchSeg(numbersSegLast[j], numbersSegLast[j + 1], numbersEntity);
				change = 0;
			}
		}
		i--;
		numbersEntity->notifyStatusChange();//////////

		if (change == 1 || i <= 0)
		{
			smSort->nextStep();
			return true;
		}
		return false;
	}
	void switchSeg(int segLastPA , int segLastPB , NumbersEntity^ numbersEntity)
	{
		int segFirstPA = segLastPA - 7;
		int segFirstPB = segLastPB - 7;
		for (int i = 0; i < 8; i++)
		{
			numbersEntity->switchDataWithoutNotify(segFirstPA ,segFirstPB);

			segFirstPA++;
			segFirstPB++;
		}
	}
};
ref class FindABpos : public State
{
private:
	SpaceMergeStep^ smSort;
	SMSortBehavior^ numbersEntity;
	int posA ,posB;

	int index, num;
	bool segADone, segBDone;/////
public:
	FindABpos(SpaceMergeStep^ smSort)
	{
		this->smSort  = smSort;
	}
	virtual void setStartStatus() override
	{
		this->numbersEntity = smSort->getNumbersEntity();

		numbersEntity->changeStateInfo("找到A,B兩段", smSort->getStepNum(), LASTSTATE);
		smSort->getRecovery()->add(smSort->backup());

		posA = smSort->getLargestEndPos() + 1;
		//setBPos();/////
		index = posA;/////
		num = numbersEntity->getNumber(index);/////
		segADone = segBDone = false;/////
	}

	virtual void skip() override
	{
		while (true)
		{
			if (sortMethod())break;
		}
	}
	virtual System::Void Sort(Object^ sender, EventArgs^ e) override
	{	
		sortMethod();
	}

	virtual void forward() override
	{
		smSort->setState(smSort->sortABStep);
	}
private:
	bool sortMethod()/////
	{
		if (!segADone)
		{
			if (index < 64 && numbersEntity->getNumber(index) >= num)
			{
				numbersEntity->addSelectPos(index, 1);
				num = numbersEntity->getNumber(index);
				index++;
			}
			else
			{
				segADone = true;
				if (index < 64)
				{
					num = numbersEntity->getNumber(index);
					posB = index;
				}				
				else
				{
					posB = -1;//代表沒有b位置
					segBDone = true;
				}
			}
		}
		else if ( !segBDone )
		{					
			if(index < 64 && numbersEntity->getNumber(index) >= num)
			{
				numbersEntity->addSelectPos(index, 2);
				num = numbersEntity->getNumber(index);
				index++;
			}
			else segBDone = true;
		}
		else
		{
			smSort->setPosA(posA);
			smSort->setPosB(posB);
			smSort->nextStep();
			return true;
		}
		return false;
	}
};
ref class SortAB : public State
{
private:
	SpaceMergeStep^ smSort;
	SMSortBehavior^ numbersEntity;
	int posA, posB;
	int largestStartPos;
public:
	SortAB(SpaceMergeStep^ smSort)
	{
		this->smSort = smSort;
	}
	virtual void setStartStatus() override
	{
		this->numbersEntity = smSort->getNumbersEntity();

		numbersEntity->changeStateInfo("A,B兩段比較,較小的換到前面", smSort->getStepNum(), LASTSTATE);
		posA = smSort->getPosA();
		posB = smSort->getPosB();
		largestStartPos = smSort->getLargestStartPos();
	}

	virtual void skip() override
	{
		while (true)
		{
			if (sortMethod())break;
		}
	}
	virtual System::Void Sort(Object^  sender, EventArgs^  e) override
	{
		sortMethod();
	}

	virtual void forward() override
	{
		numbersEntity->clearSelectPos();
		numbersEntity->notifyStatusChange();

		if ( smSort->getLargestEndPos() >= 63 )
		{
			smSort->setStepNum(smSort->getStepNum() + 1);
			smSort->setState(smSort->sortLastSegStep);
		}
		else
		{
			smSort->setState(smSort->findABposStep);
		}
	}
private:
	bool sortMethod()
	{
		if (posB != -1)
		{
			if (posA < smSort->getPosB())
			{
				if (numbersEntity->getNumber(posA) <= numbersEntity->getNumber(posB))
				{
					numbersEntity->switchDataLS(largestStartPos, posA, 1);
					posA++;
				}
				else
				{
					numbersEntity->switchDataLS(largestStartPos, posB, 2);
					smSort->setLargestEndPos(posB);
					posB++;
				}
				largestStartPos++;
				return false;
			}
			else
			{
				smSort->setLargestStartPos(largestStartPos);
				smSort->nextStep();
				return true;
			}
		}
		else
		{
			if (posA < 64)
			{
				numbersEntity->switchDataLS(largestStartPos, posA, 1);
				posA++;
				largestStartPos++;
				smSort->setLargestEndPos(posA);
				return false;
			}
			else
			{
				smSort->setLargestStartPos(largestStartPos);
				smSort->nextStep();
				return true;
			}
		}
	}
};
/*------------------------------------------------------------------------------------*/

ref class SpaceMergeSort : public SpaceMergeStep
{
private:
	Timer^ timer;
	State^ current;

public:
	SpaceMergeSort(NumbersEntity^ numbersEntity) : SpaceMergeStep(numbersEntity)
	{
		findLargestStep  = gcnew FindLargest(this);
		shiftToMidStep   = gcnew ShiftToMid(this);
		sortLastSegStep  = gcnew SortLastSeg(this);
		shiftToFirstStep = gcnew ShiftToFirst(this);
		sortAllSegStep   = gcnew SortAllSeg(this);

		findABposStep	 = gcnew FindABpos(this);
		sortABStep		 = gcnew SortAB(this);

		timer = gcnew Timer();
		current = findLargestStep;	
		findLargestStep->setStartStatus();
		timer->Tick += gcnew EventHandler(current, &State::Sort);
	}
	Timer^ getSortTimer() { return timer; }
	void skipTheState()//往前
	{
		bool switchUp = timer->Enabled;
		timer->Enabled = false;

		if (current->Equals(findABposStep) || current->Equals(sortABStep))
		{
			while (current->Equals(findABposStep) || current->Equals(sortABStep))
			{
				current->skip();
			}
		}
		else	current->skip();

		if( member->stepNum != State::LASTSTATE)
			timer->Enabled = switchUp;
	}
	void backTheState()
	{
		bool switchUp = timer->Enabled;
		timer->Enabled = false;
		timer->Tick -= gcnew EventHandler(current, &State::Sort);

		recover(recovery->retrieve(member->stepNum - 1));//前一個區段的資料
		if (member->stepNum == State::LASTSTATE - 1)
		{
			member->numbersEntity->notifyChangeSortStatus(false, true);
		}

		member->numbersEntity->notifyStatusChange();
		timer->Tick += gcnew EventHandler(current, &State::Sort);
		timer->Enabled = switchUp;
	}
	void recover(Backup^ backup) 
	{
		this->member = backup->getMember();
		setState( backup->getCurrentState() );
	}

	virtual Backup^ backup() override
	{
		return gcnew Backup(member ,current);
	}
	virtual void setState(State^ next) override
	{
		this->current = next;
		current->setStartStatus();		
	}
	virtual void nextStep() override
	{
		timer->Tick -= gcnew EventHandler(current, &State::Sort);

		current->forward();

		timer->Tick += gcnew EventHandler(current, &State::Sort);
	}
	virtual void theEnd() override
	{
		timer->Enabled = false;
		member->numbersEntity->changeStateInfo("排序完成!!!" , member->stepNum ,State::LASTSTATE);
		member->numbersEntity->notifyChangeSortStatus(false, false);
	}
};