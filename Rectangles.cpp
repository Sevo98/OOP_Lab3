#include <iostream>
#include "Point.h"
#include "Rectangles.h"
#include "CheckInputDouble.h"
using namespace std;

void ReadRectanglesFromConsole(Rectangles& rectangle)
{
	cout << "������ �������� �������������� ��� ����������? \n1. ��������������\n2.����������" << endl;
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
	Rectangles rectangle;
	ReadRectanglesFromConsole(rectangle);
	WriteRectanglesFromConsole(rectangle);
}
