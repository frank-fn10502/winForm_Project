#pragma once
#include "NumbersEntity.h"

ref class ObserverLargestPos
{
public:
	virtual void update(array<int>^ numbers, int largestNum , List<int>^ allLargestPos){}
	virtual void add(array<int>^ numbers, int largestNum,int addPos){}
};
ref class ObserverSelectPos
{
public:
	virtual void update(array<int>^ numbers, int largestNum, List<int>^ selectPos ,int TypeN){}
};
ref class ObserverStateInfo
{
public:
	virtual void update(String^ desStr ,int currentState ,int lastState) {}
};
ref class ObserverSortStartEnd
{
public:
	virtual void update(bool nowStart, bool notEnd) {}
};

ref class SMSortBehavior : public NumbersEntity
{
private:
	List<int>^  allLargestPos ;
	List<int>^  selectPosA	  ;
	List<int>^  selectPosB    ;
	List<int>^  selectPosOther;
	String^ stateDes;

	List<ObserverLargestPos^>^ oLargestPos ;
	List<ObserverSelectPos^>^  oSelectPos  ;
	List<ObserverStateInfo^>^  oStateDes   ;
	List<ObserverSortStartEnd^>^ oSortStartEnd;
	
public:
	SMSortBehavior() 
	{
		allLargestPos = gcnew List<int>;//¶Ç¦ì§} 0~63
		selectPosA	  = gcnew List<int>;//¶Ç¦ì§} 0~63
		selectPosB    = gcnew List<int>;//¶Ç¦ì§} 0~63
		selectPosOther= gcnew List<int>;//¶Ç¦ì§} 0~63

		oLargestPos = gcnew List<ObserverLargestPos^>();
		oSelectPos  = gcnew List<ObserverSelectPos^>();
		oStateDes   = gcnew List<ObserverStateInfo^>();
		oSortStartEnd = gcnew List<ObserverSortStartEnd^>();
	}

	void switchDataL(int oneLargestPos, int posA)
	{
		allLargestPos->Remove(oneLargestPos);
		allLargestPos->Add(posA);

		NumbersEntity::switchData(oneLargestPos, posA);
		notifyChangeLargestPos();
	}
	void switchDataLS(int oneLargestPos, int selectDataPos ,int TypeN)
	{
		NumbersEntity::switchData(oneLargestPos, selectDataPos);

		allLargestPos->Remove(oneLargestPos);
		allLargestPos->Add(selectDataPos);
		notifyChangeLargestPos();
		
		removeSelectPos(selectDataPos, TypeN);
		addSelectPos(oneLargestPos, TypeN);
		notifyChangeSelectPos();
	}

	void addLargestPos(int posN)
	{
		allLargestPos->Add(posN);
		notifyChangeLargestPos();
	}
	void removeLargestPos(int posN)
	{
		allLargestPos->Remove(posN);
	}

	void addSelectPos(int posN ,int TypeN)
	{
		if( TypeN == 1)
			selectPosA->Add(posN);
		else if (TypeN == 2)
			selectPosB->Add(posN);
		else if (TypeN == 3)
			selectPosOther->Add(posN);

		notifyStatusChange();//////////
	}
	void removeSelectPos(int posN, int TypeN)
	{
		if (TypeN == 1)
			selectPosA->Remove(posN);
		else if (TypeN == 2)
			selectPosB->Remove(posN);
		else if (TypeN == 3)
			selectPosOther->Remove(posN);
	}
	void clearSelectPos()
	{
		selectPosA->Clear();
		selectPosB->Clear();
		selectPosOther->Clear();
	}

	void changeStateInfo(String^ str ,int currentState, int lastState)
	{
		this->stateDes = str;
		notifyChangeStateInfo(currentState ,lastState);
	}

	//////////////////////////
	List<int>^ getAllLargestPos() { return allLargestPos; }
	List<int>^ getSelectPosA()    { return selectPosA; }
	List<int>^ getSelectPosB()	  { return selectPosB; }
	List<int>^ getSelectPosOther(){ return selectPosOther; }
	String^ getStateDes()		  { return stateDes;  }

	List<ObserverLargestPos^>^ getObserverLargestPos() { return oLargestPos; }
	List<ObserverSelectPos^>^ getObserverSelectPos()   { return oSelectPos; }
	List<ObserverStateInfo^>^ getObserverStateInfo()   { return oStateDes; }
	List<ObserverSortStartEnd^>^ getObserverSortStartEnd() { return oSortStartEnd; }
	//////////////////////////
	void copyData(SMSortBehavior^ sortBehavior)
	{
		NumbersEntity::copyData(sortBehavior);

		copyList(this->allLargestPos, sortBehavior->getAllLargestPos() );
		copyList(this->selectPosA, sortBehavior->getSelectPosA());
		copyList(this->selectPosB, sortBehavior->getSelectPosB());
		copyList(this->selectPosOther, sortBehavior->getSelectPosOther());
		this->stateDes = sortBehavior->getStateDes();

		this->oLargestPos   = sortBehavior->getObserverLargestPos();
		this->oSelectPos    = sortBehavior->getObserverSelectPos();
		this->oStateDes     = sortBehavior->getObserverStateInfo();
		this->oSortStartEnd = sortBehavior->getObserverSortStartEnd();
	}
/*--------------------------------------------------------------------------------------*/
	virtual void notifyStatusChange() override
	{
		for each(EntityObserver^ eo in observer)
		{
			eo->updateData(numbers, largestNum);
			/////
			notifyChangeLargestPos();
			notifyChangeSelectPos();
		}
	}

	void notifyChangeLargestPos()
	{
		for each(ObserverLargestPos^ observer in oLargestPos)
		{
			observer->update(numbers, largestNum, allLargestPos);
		}
	}
	void notifyAddedLargestPos(int addPos)
	{
		for each(ObserverLargestPos^ observer in oLargestPos)
		{
			observer->add(numbers, largestNum ,addPos);
		}
	}

	void notifyChangeSelectPos()
	{
		for each(ObserverSelectPos^ observer in oSelectPos)
		{
				observer->update(numbers, largestNum ,selectPosA ,1);
				observer->update(numbers, largestNum, selectPosB ,2);
				observer->update(numbers, largestNum, selectPosOther, 3);
		}
	}

	void notifyChangeStateInfo(int currentState, int lastState)
	{
		for each(ObserverStateInfo^ observer in oStateDes)
		{
			observer->update(stateDes ,currentState , lastState);
		}
	}

	void notifyChangeSortStatus(bool nowStart, bool notEnd)
	{
		for each(ObserverSortStartEnd^ observer in oSortStartEnd)
		{
			observer->update(nowStart ,notEnd);
		}
	}
/*--------------------------------------------------------------------------------------*/
	void addObserverLargestPos(ObserverLargestPos^ observerLargestPos)
	{
		this->oLargestPos->Add(observerLargestPos);
	}
	void removeObserverLargestPos(ObserverLargestPos^ observerLargestPos)
	{
		this->oLargestPos->Remove(observerLargestPos);
	}

	void addObserverSelectPos(ObserverSelectPos^ observerSelectPos)
	{
		this->oSelectPos->Add(observerSelectPos);
	}
	void removeObserverSelectPos(ObserverSelectPos^ observerSelectPos)
	{
		this->oSelectPos->Remove(observerSelectPos);
	}

	void addObserverStateInfo(ObserverStateInfo^ observerStateDes)
	{
		this->oStateDes->Add(observerStateDes);
	}
	void removeObserverStateInfo(ObserverStateInfo^ observerStateDes)
	{
		this->oStateDes->Remove(observerStateDes);
	}

	void addObserverSortStartEnd(ObserverSortStartEnd^ observerSortStartEnd)
	{
		this->oSortStartEnd->Add(observerSortStartEnd);
	}
	void removeObserverSortStartEnd(ObserverSortStartEnd^ observerSortStartEnd)
	{
		this->oSortStartEnd->Remove(observerSortStartEnd);
	}

private:
	void copyList(List<int>^ target ,List<int>^ source)
	{
		for each(int pos in source)
		{
			target->Add(pos);
		}
	}
};

