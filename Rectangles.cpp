#include <iostream>
#include "Point.h"
#include "Rectangles.h"
#include "CheckInputDouble.h"
using namespace std;

void ReadRectanglesFromConsole(Rectangles& rectangle)
{
	cout << "Задать значения самостоятельно или программно?" << endl;
	cout << "1. Самостоятельно" << endl;
	cout << "2. Программно" << endl;
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
					rectangle.Length = Length;
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
					rectangle.Width = Width;
					CheckWidth = true;
				}
				catch (const exception&)
				{
					cout << "Ширина не может быть меньше 0 или равна 0! Повторите ввод." << endl;
				}
			}

			cout << "Введите координаты центра прямоугольника:" << endl;
			ReadPointFromConsole(rectangle.point);
	} break;

	case 2:
		{
			double max = 1000.45654;
			double min = -1000.45654;
			rectangle.Length = (double)(rand()) / RAND_MAX * max;
			rectangle.Width = (double)(rand()) / RAND_MAX * max;
			rectangle.point.X = (double)(rand()) / RAND_MAX * (max - min);
			rectangle.point.Y = (double)(rand()) / RAND_MAX * (max - min);
		} break;

	}
}

void WriteRectanglesFromConsole(Rectangles& rectangle)
{
	cout << "X = " << rectangle.point.X << "; Y = " << rectangle.point.Y << "; Length = " << rectangle.Length << "; Width = " << rectangle.Width << endl;
}

void DemoRectangleWithPoint()
{
	const int RectanglesCount = 5;
	Rectangles rectangle[RectanglesCount];
	for (int i = 0; i < RectanglesCount; i++)
	{
		cout << "Задайте значения прямоугольника №" << i + 1 << endl;
		ReadRectanglesFromConsole(rectangle[i]);
	}
	for (int i = 0; i < RectanglesCount; i++)
	{
		cout << "Прямоугольник №" << i + 1 << endl;
		WriteRectanglesFromConsole(rectangle[i]);
	}

	cout << "Среднее значение всех центров прямоугольников:" << endl;
	double Xcenter = 0, Ycenter = 0;

	for (int i = 0; i < RectanglesCount; i++)
	{
		Xcenter += rectangle[i].point.X;
	}
	Xcenter = Xcenter / RectanglesCount;
	
	for (int i = 0; i < RectanglesCount; i++)
	{
		Ycenter += rectangle[i].point.Y;
	}
	Ycenter = Ycenter / RectanglesCount;

	cout << "Xcenter = " << Xcenter << "; Ycenter = " << Ycenter << endl;

	/*Rectangles rectangle;
	ReadRectanglesFromConsole(rectangle);
	WriteRectanglesFromConsole(rectangle);*/
}
