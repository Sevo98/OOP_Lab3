#include <iostream>
#include "Arrays.h"
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void InputArr(int *arr, int i);

void Array1()
{
	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand()%100;
	}
	
	InputArr(arr, 10);

	sort(arr, arr + 10);
	
	cout << "\n ќтсортированный массив:" << endl;
	InputArr(arr, 10);
	
	system("pause");
	system("cls");
}


void Array2()
{
	double arr[12];
	
	srand(time(NULL));
	for (int i = 0; i < 12; i++)
	{
		arr[i] = static_cast<double>(rand() % 901 + 100) / 100.0;
	}

	
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ", ";
	}

	system("pause");

	double searchingValue;
	cout << "¬ведите элемент поиска: ";
	cin >> searchingValue;
	
	for (int i = 0; i < 12; i++)
	{
		if (searchingValue == arr[i])
		{
			cout << "„исло " << searchingValue << " находитс€ в €чейке " << i << endl;
		}
		else cout << "¬ €чейке " << i << " число не найдено" << endl;
	}

	system("pause");
	system("cls");
}

void Array3()
{
	char arr[8];
	for (int i = 0; i < 3; i++)
	{
		cout << "¬ведите символ в массив" << endl;
		cin >> arr[i];
	}

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << ", ";
	} cout << endl;
	
	system("pause");
	system("cls");

	for (int i = 0; i < 3; i++)
	{
		if (((int)arr[i] >= 97 && (int)arr[i] <= 122) || ((int)arr[i] >= 65 && (int)arr[i] <= 90) )
		{
			cout << arr[i] << ", ";
		}
		else cout << "";
	}

	system("pause");
	system("cls");
}


void InputArr(int *arr, int i)
{
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ", ";
	}
}
