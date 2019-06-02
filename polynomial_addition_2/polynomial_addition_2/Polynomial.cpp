#include "StdAfx.h"
#include "Polynomial.h"

Polynomial::Polynomial(int n)
{
	num = n;
	polynomial = gcnew array<int,2>(n,2);
}
Polynomial::Polynomial(String^% str)
{
	setData( str );
}
/*--------------------------------------------------------------------*/

void Polynomial::setData(String^% str)
{
	array<int,2>^ temp_poly = gcnew array<int,2>((str->Length+1)/2,2);
	String^ temp_str = "";
	int j = 0;
	for(int i = 0 ; i < str->Length ; i++ )
	{
		if( str[i]== '-' || Char::IsDigit(str[i]) )
		{
			temp_str += str[i];
			if( i == str->Length-1 )//程计⊿Τフ
			{
				temp_poly[ j/2 ,j%2 ] = Convert::ToInt32( temp_str );
				j++;
			}
		}
		else if(temp_str != "")//璽腹 ,计 フ 
		{
			temp_poly[ j/2 ,j%2 ] = Convert::ToInt32( temp_str );
			j++;
			temp_str = "";
		}
	}
	/*-------------------------------------------------------*/
	this->num = j/2;
	this->polynomial = gcnew array<int,2>(j/2,2);

	for(int i = 0 ; i < j/2 ; i++ )
	{
		polynomial[ i ,0 ] = temp_poly[ i ,0 ];
		polynomial[ i ,1 ] = temp_poly[ i ,1 ];
	}
}
//void Polynomial::setNum(int i)		   { num = i; }
void Polynomial::setCoef(int i,int num){polynomial[ i ,0 ] = num;}
void Polynomial::setExp (int i,int num){polynomial[ i ,1 ] = num;}
/*--------------------------------------------------------------------*/

int Polynomial::getNum(){ return num; }
int Polynomial::getCoef(int i){return polynomial[i ,0 ]; }
int Polynomial::getExp(int i) {return polynomial[i ,1 ]; }
/*--------------------------------------------------------------------*/

Polynomial^ Polynomial::operator+(Polynomial^% poly)
{
	int k = 0, i = 0 ,j = 0;
	int temp_Coef;

	array<int,2>^ temp = gcnew array<int,2>( num + poly->getNum() ,2 );//程兜计

	for( ; k < temp->Length/2 ;  )//Length: ┮Τじ羆㎝
	{
		if( i >= this->num )
		{
			for( ; j < poly->getNum() ; j++ ,k++ )
			{
				temp[ k ,0 ] = poly->getCoef(j) ;
				temp[ k ,1 ] = poly->getExp(j)  ;
			}
			break;
		}
		else if( j >= poly->getNum() )
		{
			for( ; i < num ; i++ ,k++ )
			{
				temp[ k ,0 ] = polynomial[i ,0 ];
				temp[ k ,1 ] = polynomial[i ,1 ];	
			}
			break;
		}
		else if( polynomial[i ,1 ] > poly->getExp(j)  )
		{
			temp[ k ,0 ] = polynomial[i ,0 ];
			temp[ k ,1 ] = polynomial[i ,1 ];

			i++;
			k++;
		}
		else if( polynomial[i ,1 ] < poly->getExp(j) )
		{
			temp[ k ,0 ] = poly->getCoef(j);
			temp[ k ,1 ] = poly->getExp(j) ;

			j++;
			k++;
		}
		else if( polynomial[i ,1 ] == poly->getExp(j) )
		{

			temp_Coef = polynomial[i ,0 ] + poly->getCoef(j);
			if( temp_Coef != 0 )
			{
				temp[ k ,0 ] = polynomial[i ,0 ] + poly->getCoef(j);
				temp[ k ,1 ] = polynomial[i ,1 ];
				k++;
			}
			i++;
			j++;
		}
	}
	Polynomial^ answer = gcnew Polynomial( k );
	for(int i = 0 ; i < answer->getNum() ; i++ )
	{
		answer->setCoef(i ,temp[ i ,0 ] );
		answer->setExp (i ,temp[ i ,1 ] );
	}
	return answer;
}
String^ Polynomial::polynomial_form()
{
	String^ str_temp =  "";
	for(int i = 0 ; i < this->num ; i++ )
	{
		str_temp += items(polynomial[i ,0 ] ,polynomial[i ,1 ] ,i );
	}
	return str_temp;
}
String^ Polynomial::items(int coef ,int exp ,int i)
{
	String^ sign = "";
	String^ str_coef = "";
	String^ str_exp = "";

	if( coef < 0 && i == 0)		 sign = "-" ;	
	else if( coef > 0 && i != 0) sign = "+ ";
	else if( coef < 0 && i != 0) sign = "- ";
	else if( coef == 0 )		 return ""  ;//砛穦Τ玒计0 砛..

	coef = ( coef < 0 )? coef * -1 : coef;///埃才腹紇臫
	
	if( coef == 1 ) str_coef = "x";
	else			str_coef = coef.ToString() + "x";

	if( exp == 0 )	   return sign + coef.ToString();
	else if( exp == 1) str_exp = "";
	else               str_exp = "^" + exp;

	return sign + str_coef + str_exp + " ";
}