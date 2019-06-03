#pragma once

using namespace System;

ref class RandomNumbers
{
private:
	array<int>^ numbers;

public:
	RandomNumbers(int quantity,int start ,int end ,bool noRepeat)
	{
		numbers = gcnew array<int>(quantity);
		if ( noRepeat) setWithoutRepeat(quantity, start, end); 
		else           setWithRepeat(quantity, start, end);

		/////�����]MergeSort����̫�@�B(64�ӼƦr: �̫�@�B�O 32 32 �X��)/////
		sortNumbers(0, 31);
		sortNumbers(32, 63);
		//////////
	}
	array<int>^ getNumbers() { return numbers; }
private:
	void setWithRepeat(int quantity, int start, int end)
	{
		Random^ randomNum = gcnew Random();

		for (int i = 0; i < quantity; i++)
		{
			numbers[i] = randomNum->Next(start ,end);
		}
	}
	void setWithoutRepeat(int quantity, int start, int end)
	{
		Random^ randomNum = gcnew Random();
		//�إߵP��
		int size = end - start + 1;
		array<int>^ deck = gcnew array<int>(size);
		for (int i = 0 ; i < deck->Length ; i++)
		{
			deck[i] = start + i;
		}
		/////
		//��P
		for (int i = 0 ,j; i < quantity; i++)
		{
			j = randomNum->Next(size);
			numbers[i] = deck[j];
			deck[j]    = deck[--size]; //�P�ճ̫�@�i���Q��������m
		}
	}
	void sortNumbers(int start ,int end)
	{
		int temp;
		bool change = false;
		for (int i = end; i > 0; i--)
		{
			change = false;
			for (int j = start; j < i; j++)
			{
				if (numbers[j] > numbers[j+1])
				{
					temp = numbers[j];
					numbers[j] = numbers[j+1];
					numbers[j + 1] = temp;

					change = true;
				}
			}
			if (!change) break;
		}
	}
};

