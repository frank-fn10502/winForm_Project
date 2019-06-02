#pragma once

using namespace System;

ref class Polynomial
{
private:
	int num;
	array<int,2>^ polynomial;
public:
	Polynomial(int);
	Polynomial(String^%);

	void setData(String^%);
	//void setNum(int );
	void setCoef(int ,int );
	void setExp(int ,int );

	int  getNum();
	int  getCoef(int );
	int  getExp(int );

	Polynomial^ operator+(Polynomial^% );

	String^ polynomial_form();
private:
	String^ items(int ,int ,int );
};
