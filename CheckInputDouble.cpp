#include <iostream>
#include "CheckInputDouble.h"
using namespace std;

void CheckInputDouble(double* ChechDouble)
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
			*ChechDouble = index;
			correct = true;
		}
	}
}
