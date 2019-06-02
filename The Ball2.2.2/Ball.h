#pragma once
#include "TheColor.h"

using namespace System::Drawing;
using namespace System;

ref class Ball : public TheColor
{
private:
	double x;
	double y;
	double size;
	double dir_x;
	double dir_y;
	double speed;

/*==============================*/
private:

	double radius;
	double center_x;
	double center_y;

	static void changeMove(Ball^% ,Ball^% );
	static bool HitBall(array<Ball^> ^%b ,int);
	static bool HitWall(Ball^% );

	bool complete;

public:
	Ball(void);
	
	void setBallsize(double );
	void setBalldirection(double ,double);
	void setBalldir_x(double);
	void setBalldir_y(double);
	void setBallsp(double);
	void setBallposition(double ,double);
	void setBallpos_x(double);
	void setBallpos_y(double);

	double getBallsize();
	double getBalldirection_x();
	double getBalldirection_y();
	double getBallspeed();
	double getBallposition_x();
	double getBallposition_y();

	/*--------------------------*/
	void setRadius(double r);
	void setCenterX(double cx);
	void setCenterY(double cy);
	double getRadius();
	double getCenterX();
	double getCenterY();

	void setComplete(bool);
	bool getComplete();
	/*--------------------------*/
	
	static void Moving(array<Ball^> ^% );
};
