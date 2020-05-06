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
			cout << "������� ����� ��������������: ";
			double Length;
			CheckInputDouble(&Length);
			if (Length <= 0)
			{
				throw exception("����� �� ����� ���� ������ 0 ��� ����� 0! ��������� ����.");
			}
			rectangle.Length = Length;
			CheckLength = true;
		}
		catch (const exception&)
		{
			cout << "����� �� ����� ���� ������ 0 ��� ����� 0! ��������� ����." << endl;
		}
	}

	bool CheckWidth = false;
	while (CheckWidth == false)
	{
		try
		{
			cout << "\n������� ������ ��������������: ";
			double Width;
			CheckInputDouble(&Width);
			if (Width <= 0)
			{
				throw exception("������ �� ����� ���� ������ 0 ��� ����� 0! ��������� ����.");
			}
			rectangle.Width = Width;
			CheckWidth = true;
		}
		catch (const exception&)
		{
			cout << "������ �� ����� ���� ������ 0 ��� ����� 0! ��������� ����." << endl;
		}
	}

	cout << "������� ���������� ������ ��������������:" << endl;
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
