#include <iostream>
#include "Functions.h"
#include <cmath>

using namespace std;

double GetPower(double base, int exponent)
{
	double value;
	value = pow(base, exponent);

	return value;
}

void DemoGetPower(double base, int exponent)
{
	double getValue;
	getValue = GetPower(base, exponent);
	cout << base << " ^ " << exponent << " = " << getValue << endl;
}

void RoundToTens(int& value)
{
	int num, tempNum;
	tempNum = value % 10;
	if (tempNum < 5)
	{
		num = floor(value/10)*10;
	}
	else 
	{
		num = ceil((value/10)+1)*10; 
	}
	
	cout << "Для " << value << " остаток равен " << num <<endl;

}
