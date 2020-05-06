#include <iostream>
#include "Point.h"
#include "CheckInputDouble.h"
using namespace std;

void ReadPointFromConsole(Point& point)
{
	cout << "������� �: ";
	CheckInputDouble(&point.X);

	cout << "\n������� Y: ";
	CheckInputDouble(&point.Y);
}

void WritePointFromConsole(Point& point)
{
	cout << "X: " << point.X << endl;
	cout << "Y: " << point.Y << endl;
}