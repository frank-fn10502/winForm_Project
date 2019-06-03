#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class Observer
{
public:
	virtual void update() {}
};
ref class Subject
{
public:
	virtual void registerObserver(Observer^) {}
	virtual void removeObserver(Observer^) {}
	virtual void notifyObservers() {}
};