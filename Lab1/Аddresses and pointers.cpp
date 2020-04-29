#include <iostream>
#include "Аddresses and pointers.h"

using namespace std;

void FirstTaskAdress()
{
	int a = 5, b = 4;
	cout << "Адрес а: " << &a << endl;
	cout << "Адрес b: " << &b << endl;

	double c = 13.5;
	cout << "Адрес c: " << &c << endl;
	bool d = true;
	cout << "Адрес d:" << &d << endl;
}

void SecondTaskAdress()
{
	int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
	cout << "Размер int'ового типа: " << sizeof(int) << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Адрес элемента массива а[" << i << "]: " << &a[i] << endl << endl;
	}
	double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
	for (int i = 0; i < 10; i++)
	{
		cout << "Адрес элемента массива b[" << i << "]: " << &b[i] << endl;
	}
}

void ThirdTaskAdress()
{
	int a = 5;
	int& b = a;

	cout << "Адрес a: " << &a << endl;
	cout << "Адрес b: " << &b << endl << endl;

	b = 7;
	cout << "Значение a: " << a << endl;
}

void FourthTaskAdress()
{
	double a = 5.0;
	cout << "Адрес в основной функции: " << &a << endl;
	cout << "Значение в основной функции: " << a << endl << endl;

	Foo4(a);
	
	cout << "Значение в основной функции: " << a << endl;
}

void Foo4(double a)
{
	cout << "Адрес в функции Foo: " << &a << endl;
	cout << "Значение в функции Foo:" << a << endl;
	a = 15.0;
	cout << "Новое значение в функции Foo: " << a << endl;
}

void FiveTaskAdress()
{
	double a = 5.0;
	cout << "Адрес в основной функции: " << &a << endl;
	cout << "Значение в основной функции: " << a << endl << endl;
	
	Foo5(a);
	cout << "Значение в основной функции: " << a << endl;
}

void Foo5(double& a)
{
	cout << "Адрес в функции Foo: " << &a << endl;
	cout << "Значение в функции Foo: " << a << endl;
	a = 15.00;
	cout << "Новое значение в функции Foo: " << a << endl;
}

void SixTaskAdress()
{
	int a = 5;
	int* pointer = &a;

	cout << "Адрес a: " << &a << endl;
	cout << "Адpес в указателе: " << pointer << endl;
	cout << "Адрес указателя: " << &pointer << endl << endl;
	*pointer = 7;
	cout << "Значение в a: " << a << endl;
	cout << "Значение через указатель адреса: " << *pointer<< endl;
}

void SevenTaskAdress()
{
	cout << "* после типа данных это объявление указателя\n * без типа данных перед именем переменной это разыменование\n * между двумя численными переменными это умножение" << endl;
}

void EightTaksAdress()
{
	double value = 5.0;
	double* pointer = &value;
	cout << "Адрес значения в основной функции: " << &value << endl;
	cout << "Адрес в указателе в основной функции: " << pointer << endl;
	cout << "Адрес указателя в основной функции: " << &pointer << endl;
	cout << "Значение а в основной функции: " << value << endl << endl;

	Foo8(pointer);

	cout << endl << "Значение а в основной функции: " << value << endl;
}

void Foo8(double* a)
{
	cout << "Адрес в указателе: " << a << endl;
	cout << "Адрес указателя: " << &a << endl;
	cout << "Значение адреса в указателе: " << *a << endl;
	*a = 15.0;
	cout << "Новое значение в указателе адреса: " << *a << endl;
}