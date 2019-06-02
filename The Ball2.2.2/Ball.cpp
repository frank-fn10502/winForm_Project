#include "StdAfx.h"
#include "Ball.h"


Ball::Ball(void)
{
  setBallsize(70);
  setBalldirection(1.0 ,1.0);
  setBallsp(1);
  setBallposition(100 ,100);

  setComplete(false);
}
void Ball::setBallsize(double si)//////////////////////////////
{ 
	size = si; 
	setRadius(size / 2);
}
void Ball::setBalldirection(double dx,double dy)
{
  setBalldir_x(dx);
  setBalldir_y(dy);
}
void Ball::setBalldir_x(double dx){ dir_x = dx; }
void Ball::setBalldir_y(double dy){ dir_y = dy; }
void Ball::setBallsp(double sx)   { speed = sx; }
void Ball::setBallposition(double px,double py)
{
  setBallpos_x(px);
  setBallpos_y(py);
}
void Ball::setBallpos_x(double px)
{ 
	x = px;   
	setCenterX(x);
}
void Ball::setBallpos_y(double py)
{ 
	y = py;  
	setCenterY(y);
}

double  Ball::getBallsize()		   { return size; }
double  Ball::getBalldirection_x() { return dir_x;}
double  Ball::getBalldirection_y() { return dir_y;}
double  Ball::getBallspeed()	   { return speed;}
double  Ball::getBallposition_x()  { return x;    }
double  Ball::getBallposition_y()  { return y;	  }

/*--------------------------------------------------------*/
void Ball::setRadius(double r)  { radius = r;    }
void Ball::setCenterX(double cx){ center_x = cx + radius; }
void Ball::setCenterY(double cy){ center_y = cy + radius; }
double  Ball::getRadius()		{ return radius;   }
double  Ball::getCenterX()		{ return center_x; }
double  Ball::getCenterY()		{ return center_y; }

void Ball::setComplete(bool com){ complete = com; }
bool Ball::getComplete()		{ return complete; }
/*--------------------------------------------------------*/

static int PanelBound_x = 510;
static int PanelBound_y = 450;

void UnitVector(array<double>^% vector)//單位向量
{
	array<double>^ unitvector = gcnew array<double>(2);
	double temp = vector[0] * vector[0] + vector[1] * vector[1];
	double vector_long = Math::Sqrt(temp);
	
	vector[0] /= vector_long;
	vector[1] /= vector_long;
}
double Projection_number(array<double>^ vector1 ,array<double>^ vector2)
{
	double dot = vector1[0] * vector2[0] + vector1[1] * vector2[1];
	double temp = vector2[0] * vector2[0] + vector2[1] * vector2[1];
	double vector2_long = Math::Sqrt(temp);

	return dot / vector2_long ;
}
array<double>^ VectorWithSpeed(array<double>^% vector ,double sp)
{
	array<double>^ vectorSpeed = gcnew array<double>(2);

	vectorSpeed[0] = vector[0] * sp;
	vectorSpeed[1] = vector[1] * sp;

	return vectorSpeed;
}
int ComputeSpeed(int a ,int b)
{
	if(a == 0 || b == 0 ) return 1;

	int t;

	while( b!=0 )
    {
      t = b;
      b = a%b;
      a = t;
    }
	return (a > 0) ? a : -1 * a;
}
void Ball::changeMove(Ball^% a ,Ball^% b)
{
	array<double>^ vectorA_original = {a->getBalldirection_x() * a->getBallspeed() ,
									   a->getBalldirection_y() * a->getBallspeed() }; 
	array<double>^ vectorB_original = {b->getBalldirection_x() * b->getBallspeed() ,
									   b->getBalldirection_y() * b->getBallspeed() };
/*-----------------------------------撞擊後真正產生的兩個 投影量(速度) & 法,切線的(單位)向量---------------------------*/
	array<double>^ vector_Nomal   = { b->getCenterX() - a->getCenterX() ,b->getCenterY() - a->getCenterY() };//法線
	array<double>^ vector_tangent = { vector_Nomal[1] ,0- vector_Nomal[0] };//切線

	double speedA_Normal = Projection_number(vectorA_original ,vector_Nomal);  //A法線投影量(算法有待確認)
	double speedA_tangent= Projection_number(vectorA_original ,vector_tangent);//A切線投影量

	double speedB_Normal = Projection_number(vectorB_original ,vector_Nomal);  //B法線投影量	
	double speedB_tangent= Projection_number(vectorB_original ,vector_tangent);//B切線投影量

	UnitVector(vector_Nomal   );	
	UnitVector(vector_tangent );

/*--------------------------------向量1經由"彈性碰撞"公式得到新的(法線)向量1的速度 & (切線)向量2的速度------------------*/
	double speedA_Normalafter = (a->getBallsize() - b->getBallsize() ) / (a->getBallsize() + b->getBallsize()) * speedA_Normal
								+ (2 * b->getBallsize() )			   / (a->getBallsize() + b->getBallsize()) * speedB_Normal;//連心線向量速度會變

	double speedB_Normalafter = (2 * a->getBallsize() )                  / (a->getBallsize() + b->getBallsize()) * speedA_Normal
								+ (b->getBallsize() - a->getBallsize() ) / (a->getBallsize() + b->getBallsize()) * speedB_Normal;

	
	array<double>^ vectorA1 = VectorWithSpeed(vector_Nomal   ,speedA_Normalafter);
	array<double>^ vectorA2 = VectorWithSpeed(vector_tangent ,speedA_tangent    );//切線向量不變,直接用

	array<double>^ vectorB1 = VectorWithSpeed(vector_Nomal   ,speedB_Normalafter);
	array<double>^ vectorB2 = VectorWithSpeed(vector_tangent ,speedB_tangent    );

/*--------------------------------向量1 + 向量2 = 新的球方向----------------------------*///更改方向的移動方法(未完成)
	int newSpeedA = ComputeSpeed(vectorA1[0] + vectorA2[0] ,
							  vectorA1[1] + vectorA2[1] );
	int newSpeedB = ComputeSpeed(vectorB1[0] + vectorB2[0] ,
							  vectorB1[1] + vectorB2[1] );

	a->setBallsp( newSpeedA );
	b->setBallsp( newSpeedB );
	a->setBalldirection((vectorA1[0] + vectorA2[0]) / newSpeedA ,
					    (vectorA1[1] + vectorA2[1]) / newSpeedA );
	b->setBalldirection((vectorB1[0] + vectorB2[0]) / newSpeedB ,
						(vectorB1[1] + vectorB2[1]) / newSpeedB );

/*--------------------------------------------------------------------------------------*/
	
}
/*========================================================================*/
void Ball::Moving(array<Ball^> ^%b )///////////////////
{	
	array<double>^ vector = gcnew  array<double>(2);

	for(int i = 0 ; i < b->Length; i++ )
	{
		b[i]->setComplete(false);
	}
   /*---------------------------------------------------------------------*/
	for(int i = 0 ; i < 20; i++ )
	{
		for(int j = 0 ; j < b->Length ; j++ )
		{
			if( b[j]->getComplete() ) continue;

			vector[0] = b[j]->getBalldirection_x() * b[j]->getBallspeed() / 20; 
			vector[1] = b[j]->getBalldirection_y() * b[j]->getBallspeed() / 20;

			b[j]->setBallpos_x( b[j]->getBallposition_x() + vector[0] );
			b[j]->setBallpos_y( b[j]->getBallposition_y() + vector[1] );

		}
		for(int j = 0 ; j < b->Length ; j++ )
		{
			if( b[j]->getComplete() ) continue;

			if( HitWall(b[j]) ) 
			{
				b[j]->setComplete(true);
			}			
			if( HitBall(b ,j) ) 
			{
				b[j]->setComplete(true);
			}
			
		}
	}
}

double distance(int Ax ,int Ay ,int Bx ,int By )
{
	double dis_x = (Bx - Ax);
	double dis_y = (By - Ay);
	
	return Math::Sqrt( (dis_x * dis_x + dis_y * dis_y) );
}
bool Ball::HitBall(array<Ball^> ^%b , int current)
{	
	array<double>^ vector_Nomal  = gcnew array<double>(2);
    array<double>^ vector_tangent= gcnew array<double>(2);

	double dis;
	int bound ;

	for(int i = 0 ; i < b->Length ; i++ )
	{
		if( i == current  ) continue;

		dis    = distance(b[current]->getCenterX() ,b[current]->getCenterY() ,
						  b[i]->getCenterX() ,b[i]->getCenterY());
		bound  = b[current]->getRadius() + b[i]->getRadius();

		if( dis <  bound )
		{
			vector_Nomal[0] = b[i]->getCenterX() - b[current]->getCenterX(); 
			vector_Nomal[1] = b[i]->getCenterY() - b[current]->getCenterY();

			UnitVector( vector_Nomal );

			b[current]->setBallpos_x( b[current]->getBallposition_x() 
									- (bound - dis+2) * vector_Nomal[0] );
			b[current]->setBallpos_y(  b[current]->getBallposition_y()  
									- (bound - dis+2) * vector_Nomal[1] );

			changeMove(b[current] ,b[i] );
			return true;
		}	
	}
	return false;
}

bool Ball::HitWall(Ball^% b )
{
	bool hit = false;
	double d_x = 1,d_y = 1;

	if( (b->getBallposition_x() + b->getBallsize()) >= PanelBound_x)
	{
		d_x = (b->getBalldirection_x() > 0) ? 0 - b->getBalldirection_x() : b->getBalldirection_x() ;
		b->setBalldir_x(d_x);
		return true;
	}
	else if( b->getBallposition_x() <= 0)
	{
		d_x = (b->getBalldirection_x() < 0) ? 0 - b->getBalldirection_x() : b->getBalldirection_x() ;
		b->setBalldir_x(d_x);
		hit = true;
	}
	else if( (b->getBallposition_y() + b->getBallsize()) >= PanelBound_y )
	{
		d_y = (b->getBalldirection_y() > 0) ? 0 - b->getBalldirection_y() : b->getBalldirection_y() ;
		b->setBalldir_y(d_y);
		hit = true;
	}
	else if( b->getBallposition_y() <= 0 )
	{
		d_y = (b->getBalldirection_y() < 0) ? 0 - b->getBalldirection_y() : b->getBalldirection_y() ;
		b->setBalldir_y(d_y);
		hit = true;
	}
	return hit;
}

