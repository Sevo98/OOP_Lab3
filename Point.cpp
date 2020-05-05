#include <iostream>
#include "Point.h"
using namespace std;

void CheckInputPoint(double* point)
{
	double index;
	bool correct = false;
	while (!correct) {
		cin >> index;
		if (cin.fail()) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "Пожалуйста, введите допустимое значение." << endl;
			correct = false;
		}
		else {
			cin.ignore();
			*point = index;
			correct = true;
		}
	}
}

void ReadPointFromConsole(Point& point)
{
	cout << "Введите Х: ";
	CheckInputPoint(&point.X);

	cout << "\nВведите Y: ";
	CheckInputPoint(&point.Y);
}

void WritePointFromConsole(Point& point)
{
	cout << "X: " << point.X << endl;
	cout << "Y: " << point.Y << endl;
}



