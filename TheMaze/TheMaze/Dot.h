#pragma once

using namespace System;

ref class Dot
{
private:
	int i;
	int j;

public:
	Dot(int ,int);
	Dot(Dot^%);

	void setDot(int ,int);
	void setI(int);
	void setJ(int);

	int getI();
	int getJ();

	bool operator==(Dot^%);
	virtual String^ ToString() override;
};
