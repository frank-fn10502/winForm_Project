#pragma once

ref class GridStack
{
private:
	array<Grid^>^ stack;
	int top;
	int base; 

public:
	GridStack(int);

	int getTop();

	Grid^ pop();
	bool  push(Grid^% );
};
