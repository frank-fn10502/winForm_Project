#pragma once

using namespace System::Drawing;

ref class TheColor
{
private:
	static array<System::Drawing::Color>^ color_select = 
	{ Color::Aqua ,Color::Blue ,Color::Red ,Color::Purple,Color::Green ,Color::Brown ,Color::RosyBrown ,Color::LightBlue, 
	  Color::Chocolate ,Color::Aquamarine ,Color::DimGray ,Color::DarkGreen ,Color::DarkOrange ,Color::Coral ,Color::LavenderBlush, 
	  Color::Beige ,Color::DarkKhaki ,Color::CornflowerBlue ,Color::DeepSkyBlue ,Color::DarkOliveGreen ,Color::BurlyWood };

	System::Drawing::Color color;

public:
	TheColor(void);

	void setColor(int );
	
	System::Drawing::Color getColor();

//	static array<System::Drawing::Color>^% getColorArray();
	static System::String^ getOneOfArray(int );
	static int getArrayNum();
};
