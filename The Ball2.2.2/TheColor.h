#pragma once

using namespace System::Drawing;

ref class TheColor
{
private:
   static array<System::Drawing::Color>^ color_select = 	
   { Color::Aqua ,Color::Blue ,Color::Red ,Color::Purple,Color::Green ,Color::Brown ,Color::RosyBrown ,Color::LightBlue, 
	 Color::Chocolate ,Color::Aquamarine ,Color::DimGray ,Color::DarkGreen ,Color::DarkOrange ,Color::Coral ,Color::LavenderBlush, 
	 Color::Beige ,Color::DarkKhaki ,Color::CornflowerBlue ,Color::DeepSkyBlue ,Color::DarkOliveGreen ,Color::BurlyWood ,
	 Color::BlueViolet ,Color::Cornsilk ,Color::DarkMagenta };

   System::Drawing::Color color;

public:
	TheColor(void);

	void setColor(int );
	Color getColor();
	
	System::String^ getColorString();
	static System::String^ getOneOfArray(int );
	static int getArrayNum();
};
