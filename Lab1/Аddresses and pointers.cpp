#include <iostream>
#include "�ddresses and pointers.h"

using namespace std;

void FirstTaskAdress()
{
	int a = 5, b = 4;
	cout << "����� �: " << &a << endl;
	cout << "����� b: " << &b << endl;

	double c = 13.5;
	cout << "����� c: " << &c << endl;
	bool d = true;
	cout << "����� d:" << &d << endl;
}

void SecondTaskAdress()
{
	int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
	cout << "������ int'����� ����: " << sizeof(int) << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "����� �������� ������� �[" << i << "]: " << &a[i] << endl << endl;
	}
	double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
	for (int i = 0; i < 10; i++)
	{
		cout << "����� �������� ������� b[" << i << "]: " << &b[i] << endl;
	}
}

void ThirdTaskAdress()
{
	int a = 5;
	int& b = a;

	cout << "����� a: " << &a << endl;
	cout << "����� b: " << &b << endl << endl;

	b = 7;
	cout << "�������� a: " << a << endl;
}

void FourthTaskAdress()
{
	double a = 5.0;
	cout << "����� � �������� �������: " << &a << endl;
	cout << "�������� � �������� �������: " << a << endl << endl;

	Foo4(a);
	
	cout << "�������� � �������� �������: " << a << endl;
}

void Foo4(double a)
{
	cout << "����� � ������� Foo: " << &a << endl;
	cout << "�������� � ������� Foo:" << a << endl;
	a = 15.0;
	cout << "����� �������� � ������� Foo: " << a << endl;
}

void FiveTaskAdress()
{
	double a = 5.0;
	cout << "����� � �������� �������: " << &a << endl;
	cout << "�������� � �������� �������: " << a << endl << endl;
	
	Foo5(a);
	cout << "�������� � �������� �������: " << a << endl;
}

void Foo5(double& a)
{
	cout << "����� � ������� Foo: " << &a << endl;
	cout << "�������� � ������� Foo: " << a << endl;
	a = 15.00;
	cout << "����� �������� � ������� Foo: " << a << endl;
}

void SixTaskAdress()
{
	int a = 5;
	int* pointer = &a;

	cout << "����� a: " << &a << endl;
	cout << "��p�� � ���������: " << pointer << endl;
	cout << "����� ���������: " << &pointer << endl << endl;
	*pointer = 7;
	cout << "�������� � a: " << a << endl;
	cout << "�������� ����� ��������� ������: " << *pointer<< endl;
}

void SevenTaskAdress()
{
	cout << "* ����� ���� ������ ��� ���������� ���������\n * ��� ���� ������ ����� ������ ���������� ��� �������������\n * ����� ����� ���������� ����������� ��� ���������" << endl;
}

void EightTaksAdress()
{
	double value = 5.0;
	double* pointer = &value;
	cout << "����� �������� � �������� �������: " << &value << endl;
	cout << "����� � ��������� � �������� �������: " << pointer << endl;
	cout << "����� ��������� � �������� �������: " << &pointer << endl;
	cout << "�������� � � �������� �������: " << value << endl << endl;

	Foo8(pointer);

	cout << endl << "�������� � � �������� �������: " << value << endl;
}

void Foo8(double* a)
{
	cout << "����� � ���������: " << a << endl;
	cout << "����� ���������: " << &a << endl;
	cout << "�������� ������ � ���������: " << *a << endl;
	*a = 15.0;
	cout << "����� �������� � ��������� ������: " << *a << endl;
}