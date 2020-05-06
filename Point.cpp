#include <iostream>
#include "Point.h"
#include "CheckInputDouble.h"
using namespace std;

void ReadPointFromConsole(Point& point)
{
	cout << "Введите Х: ";
	CheckInputDouble(&point.X);

	cout << "\nВведите Y: ";
	CheckInputDouble(&point.Y);
}

void WritePointFromConsole(Point& point)
{
	cout << "X: " << point.X << endl;
	cout << "Y: " << point.Y << endl;
}