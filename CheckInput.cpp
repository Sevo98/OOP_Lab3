#include <iostream>
#include "CheckInput.h"
using namespace std;

void CheckInput(int* number)
{
	int index;
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
			*number = index;
			correct = true;
		}
	}
}