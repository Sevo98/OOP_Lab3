#include <iostream>
#include "Exception Handling.h"
#include <exception>

using namespace std;

void OutputStorage(double* values, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << values[i] << ", ";
	}
}

void Sort(double* values, int count)
{
	if (count <= 0)
		throw "Exception catched!";
	double swap;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (values[i] < values[j])
			{
				swap = values[i];
				values[i] = values[j];
				values[j] = swap;
			}
		}
	}
	
}

void DemoSort()
{
	int count = 5;
	double* values = new double[count] {100.0, 249.0, 12.0, 45.0, 23.5};
	
	OutputStorage(values, count);
	
	try
	{
		Sort(values, count);
		cout << "\nОтсортированный массив: " << endl;
		OutputStorage(values, count);
	}
	catch (...)
	{
		cout << "Exception catched!" << endl;
	}

	cout << "Присваеваем count значение -1" << endl;
	count = -1;

	try
	{
		Sort(values, count);
		cout << "\nОтсортированный массив: " << endl;
		OutputStorage(values, count);
	}
	catch (...)
	{
		cout << "Exception catched!" << endl;
	}
}
