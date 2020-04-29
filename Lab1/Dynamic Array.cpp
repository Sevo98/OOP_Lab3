#include <iostream>
#include "Dynamic Array.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int GetSizeArr()
{
	cout << "Введите размер динамического массива: " << endl;
	int size;
	cin >> size;
	return size;
}

void DArr1()
{
	int size = GetSizeArr();
	
	double* arr = new double[size];

	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = static_cast<double>(rand() % 901 + 100) / 100.0;
	}
	cout << "Динамический массив вещественных чисел: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] <<" ";
	}

	delete[] arr;
}

void DArr2()
{
	int i;
	
	 bool* arr = new bool[10];
	 arr[0] = 11;
	 arr[1] = 2;
	 arr[2] = 21;
	 arr[3] = 43;
	 arr[4] = 51;
	 arr[5] = 0;
	 arr[6] = 124;
	 arr[7] = 90;
	 arr[8] = 101;
	 arr[9] = 0;
	
	 cout << "Массив булевых чисел: " << endl;
	
	 for (int i = 0; i < 10;i++)
	 {
		 if (arr[i] != 0)
		 cout << "true ";
		 else
		 cout << "false ";	
	 }
	 cout << endl;
	 delete[] arr;

	/*srand(time(NULL));
	int size = GetSizeArr();
	bool* arr = new bool[size];
	for (int i = 0; i < size; i++)
	{
		int randomNum;
		randomNum = rand()% 1;
		if (randomNum == 1)
		{
			arr[i] = true;
		}
		else arr[i] = false;
	}
	cout << "Массив булевых значений: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;*/
}

void DArr3()
{
	int size = GetSizeArr();

	char* arr = new char[size];

	cout << "Введите элементы в массив: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << "Массив Char:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i << "]: " << arr[i] << endl;
	}
	delete[] arr;
}

void DArr4()
{
	int size = GetSizeArr();

	double* arr = new double[size];

	cout << "Введите элементы в массив: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << "Динамический массив вещественных чисел: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	delete[] arr;
}

void DArr5()
{
	int size = GetSizeArr();

	int* arr = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}

	cout << "Динамический массив: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "Введите число поиска: ";
	int searchValue;
	cin >> searchValue;
	for (int i = 0; i < size; i++)
	{
		if (searchValue == arr[i])
		{
			cout << "Число " << searchValue << " находится под номером " << i << endl;
		}
		else
		{
			cout << "Число " << searchValue << " не найдено"<< endl;
		}
	}

	delete[] arr;
}

void DArr6()
{
	int size = GetSizeArr();

	char* arr = new char[size];

	cout << "Введите символ в массив" << endl;
	for (int i = 0; i < size; i++)
	{
		
		cin >> arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	} cout << endl;

	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (((int)arr[i] >= 97 && (int)arr[i] <= 122) || ((int)arr[i] >= 65 && (int)arr[i] <= 90))
		{
			counter++;
		}
	}
	cout << "В массиве " << counter << " букв" << endl;
	
	delete[] arr;
}

void DArr7()
{
	int size = GetSizeArr();
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i++ << "]: " << arr[i] << endl;
	}
	
	delete[] arr;
}

void DArr8()
{
	int count = 15;    
	int* values = ReadArray(count);    
	cout << "Count is: " << CountPositiveValues(values, count) << endl;   
	delete[] values;
	count = 20;    values = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(values, count) << endl;        
	delete[] values;
}

int* ReadArray(int count) 
{
	int* values = new int[count];    
	for (int i = 0; i < count; i++) 
	{ 
		cin >> values[i]; 
	}    
	return values; 
}

int CountPositiveValues(int* values, int count)
{
	int result = 0;    
	for (int i = 0; i < count; i++)
	{
		if (values[i] > 0) 
		{
			result++; 
		}
	}    
	return result;
}