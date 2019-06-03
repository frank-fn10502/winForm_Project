#pragma once
using namespace System;
using namespace System::Collections::Generic;

ref class EntityObserver
{
public:
	virtual void updateData(array<int>^ numbers ,int largestNum){}
};
ref class Entity
{
protected:
	List<EntityObserver^>^ observer;

public:
	Entity()
	{
		observer = gcnew List<EntityObserver^>();
	}
	void addEntityBehavior(EntityObserver^ entities)
	{
		this->observer->Add(entities);
	}
	void removeEntityBehavior(EntityObserver^ entities)
	{
		this->observer->Remove(entities);
	}

	List<EntityObserver^>^ getEntityObserver(){ return observer;  }
};

ref class NumbersEntity : public Entity
{
protected:
	int largestNum;
	int quantity;
	array<int>^ numbers;

public:
	NumbersEntity() {}
	NumbersEntity(array<int>^% numbers)
	{
		this->numbers = numbers;
		this->quantity = numbers->Length;
		this->largestNum = getLN();
	}

	int			getQuantity()	  { return quantity; }
	int			getLargestNum()	  { return largestNum; }
	array<int>^ getNumbers()	  { return numbers; }
	int		    getNumber(int pos){ return numbers[pos]; }

	void switchData(int posA, int posB)
	{
		switchDataWithoutNotify(posA, posB);

		NumbersEntity::notifyStatusChange();
	}
	void switchDataWithoutNotify(int posA, int posB)
	{
		int temp;
		temp = numbers[posA];
		numbers[posA] = numbers[posB];
		numbers[posB] = temp;
	}
/*--------------------------------------------------------------------------------------*/

	virtual void notifyStatusChange()
	{
		for each(EntityObserver^ eo in observer)
		{
			eo->updateData(numbers, largestNum);
		}
	}
	void copyData(NumbersEntity^ ne)
	{
		this->observer = ne->getEntityObserver();

		//this->numbers = ne->getNumbers();
		numbers = gcnew array<int>(ne->getNumbers()->Length);
		for (int i = 0; i < numbers->Length; i++)
		{
			this->numbers[i] = ne->getNumber(i);
		}
		this->quantity   = ne->getQuantity();
		this->largestNum = ne->getLargestNum();
	}

private:
	int getLN()
	{
		int largest = 0;
		for (int i = 0 ; i < numbers->Length ; i++)
		{
			if (numbers[i] > largest)
			{
				largest = numbers[i];
			}
		}
		return largest;
	}
};