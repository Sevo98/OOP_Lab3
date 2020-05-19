#include <iostream>
#include "RectangleClass.h"
#include "PointClass.h"
#include "CheckInputDouble.h"
using namespace std;


void RectangleClass::ReadRectanglesFromConsole()
{
	cout << "������ �������� �������������� ��� ����������? \n1. ��������������\n2. ����������" << endl;
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
				this->Length = Length;
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
				this->Width = Width;
				CheckWidth = true;
			}
			catch (const exception&)
			{
				cout << "������ �� ����� ���� ������ 0 ��� ����� 0! ��������� ����." << endl;
			}
		}

		cout << "������� ���������� ������ ��������������:" << endl;
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
