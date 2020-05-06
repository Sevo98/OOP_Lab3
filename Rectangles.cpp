#include <iostream>
#include "Point.h"
#include "Rectangles.h"
#include "CheckInputDouble.h"
using namespace std;

void ReadRectanglesFromConsole(Rectangles& rectangle)
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
}

void WriteRectanglesFromConsole(Rectangles& rectangle)
{
	cout << "X = " << rectangle.point.X << "; Y = " << rectangle.point.Y << "; Length = " << rectangle.Length << "; Width = " << rectangle.Width << endl;
}

void DemoRectangleWithPoint()
{
	Rectangles rectangle;
	ReadRectanglesFromConsole(rectangle);
	WriteRectanglesFromConsole(rectangle);
}
