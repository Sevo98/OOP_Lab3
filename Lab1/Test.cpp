#include <iostream>
#include "Test.h"
#include "Dynamic Array.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void GetMax()
{
	int size = GetSizeArr();
	double* arr = new double[size];

	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = static_cast<double>(rand() % 150 - 50) / 10;
	}
	cout << "Динамический массив вещественных чисел: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	double max = arr[0];
	for (int i = 0; i < 10; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	cout <<  "\nМаксимальное значение в массиве - " << max << endl;
	delete[] arr;
}