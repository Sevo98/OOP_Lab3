#include <iostream>
#include "RectangleClass.h"
#include "PointClass.h"
#include "CheckInputDouble.h"
using namespace std;


void RectangleClass::ReadRectanglesFromConsole()
{
	cout << "Задать значения самостоятельно или программно? \n1. Самостоятельно\n2. Программно" << endl;
	int Switch;
	cin >> Switch;
	switch (Switch)
	{
	case 1:
	{
		bool CheckLength = false;
		while (CheckLength == false)
		{
			try
			{
				cout << "Введите длину прямоугольника: ";
				double Length;
				CheckInputDouble(&Length);
				if (Length <= 0)
				{
					throw exception("Длина не может быть меньше 0 или равна 0! Повторите ввод.");
				}
				this->Length = Length;
				CheckLength = true;
			}
			catch (const exception&)
			{
				cout << "Длина не может быть меньше 0 или равна 0! Повторите ввод." << endl;
			}
		}

		bool CheckWidth = false;
		while (CheckWidth == false)
		{
			try
			{
				cout << "\nВведите ширину прямоугольника: ";
				double Width;
				CheckInputDouble(&Width);
				if (Width <= 0)
				{
					throw exception("Ширина не может быть меньше 0 или равна 0! Повторите ввод.");
				}
				this->Width = Width;
				CheckWidth = true;
			}
			catch (const exception&)
			{
				cout << "Ширина не может быть меньше 0 или равна 0! Повторите ввод." << endl;
			}
		}

		cout << "Введите координаты центра прямоугольника:" << endl;
		this->point.ReadPointFromConsole();
	} break;

	case 2:
	{
		double max = 1000.45654;
		double min = -1000.45654;
		double X, Y;
		this->Length = (double)(rand()) / RAND_MAX * max;
		this->Width = (double)(rand()) / RAND_MAX * max;
		X = (double)(rand()) / RAND_MAX * (max - min);
		Y = (double)(rand()) / RAND_MAX * (max - min);
		this->point.AutoReadPointFromConsole(X, Y);
	} break;

	}
}

void RectangleClass::WriteRectanglesFromConsole()
{
	this->point.WritePointFromConsole();
	cout << "\nLength = " << this->Length << "; Width = " << this->Width << endl;
}

void RectangleClass::DemoRectangleWithPoint()
{
	this->ReadRectanglesFromConsole();
	this->WriteRectanglesFromConsole();
}
