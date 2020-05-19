#include <iostream>
#include "PointClass.h"
#include "CheckInputDouble.h"
using namespace std;

void PointClass::ReadPointFromConsole()
{
	cout << "Введите Х: ";
	CheckInputDouble(&this->X);

	cout << "\nВведите Y: ";
	CheckInputDouble(&this->Y);
}

void PointClass::WritePointFromConsole()
{
	cout << "X: " << this->X << endl;
	cout << "Y: " << this->Y << endl;
}

void PointClass::AutoReadPointFromConsole(double X, double Y)
{
	this->X = X;
	this->Y = Y;
}
