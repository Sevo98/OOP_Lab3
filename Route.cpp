#include <iostream>
#include "Route.h"
#include "CheckInput.h"

using namespace std;

void DemoRoute()
{
	int routesCount = 3;
	Route routes[3];

	for (int i = 0; i < routesCount; i++)
	{
		ReadRouteFromConsole(routes[i]);
	}

	for (int i = 0; i < routesCount; i++)
	{
		WriteRouteFromConsole(routes[i]);
	}

	cout << "������� ��������� ��� ������: ";
	string findStop;
	getline(cin, findStop);
	int findRoute = FindRouteTo(routes, routesCount, findStop);
	if (findRoute != -1)
	{
		cout << "��������� " << findStop << " ���� � ����� �" << routes[findRoute].Number << endl;
	}
	else cout << "���� �� ������" << endl;
}

void ReadRouteFromConsole(Route& route)
{
	setlocale(LC_ALL, "ru");
	
	bool CheckRouteNumber = false;
	while (CheckRouteNumber == false)
	{
		try
		{
			cout << "������� ����� �����: ";
			int Number;
			CheckInput(&Number);
			if (Number < 0)
			{
				throw exception("������������ ����� �����! ��������� ����.");
			}
			route.Number = Number;
			CheckRouteNumber = true;
		}
		catch (const exception&)
		{
			cout << "������������ ����� �����! ��������� ����." << endl;
		}
	}

	bool CheckTimeMin = false;
	while (CheckTimeMin == false)
	{
		try
		{
			cout << "������� ������� ����������������� ����� � �������: ";
			int TimeMin;
			CheckInput(&TimeMin);
			//route cannot be under 10 minutes
			if (TimeMin < 10)
			{
				throw exception("������������ �����������������! ��������� ����.");
			}
			route.TimeMin = TimeMin;
			CheckTimeMin = true;
		}
		catch (const exception&)
		{
			cout << "������������ �����������������! ��������� ����." << endl;
		}
	}

	bool CheckIntervalMin = false;
	while (CheckIntervalMin == false)
	{
		try
		{
			cout << "������� ������� �������� ����� ������� � �������: ";
			int IntervalMin;
			CheckInput(&IntervalMin);
			if (IntervalMin < 5)
			{
				throw exception("������������ ��������! ��������� ����.");
			}
			route.IntervalMin = IntervalMin;
			CheckIntervalMin = true;
		}
		catch (const exception&)
		{
			cout << "������������ ��������! ��������� ����." << endl;
		}
	}

	bool CheckRouteStopCount = false;
	while (CheckRouteStopCount == false)
	{
		try
		{
			cout << "������� ���������� ���������: ";
			int RouteStopCount;
			CheckInput(&RouteStopCount);
			if (RouteStopCount < 1 || RouteStopCount > 20)
			{
				throw exception("���������� ��������� ������ ���� �� 2 �� 20. ��������� ����.");
			}
			route.RouteStopCount = RouteStopCount;
			CheckRouteStopCount = true;
		}
		catch (const exception&)
		{
			cout << "���������� ��������� ������ ���� �� 2 �� 20. ��������� ����." << endl;
		}
	}

	cin.ignore(32767, '\n');
	for (int i = 0; i < route.RouteStopCount; i++)
	{
		int j = i;
		cout << "\n������� ��������� �" << j + 1 << ": ";
		getline(cin, route.RouteStop[i]);
	}
}

void WriteRouteFromConsole(Route& route)
{
	setlocale(LC_ALL, "ru");

	cout << "���� �" << route.Number << ". ���� ����������: ";

	for (int i = 0; i < route.RouteStopCount; i++)
	{
		cout << route.RouteStop[i];
		if (i < route.RouteStopCount - 1)
		{
			cout << " - ";
		}
		else if (i == route.RouteStopCount - 1)
		{
			cout << ". " << endl;
		}
	}


	cout << "����� ����������: " << route.TimeMin << "\n�������� ����� ����������: " << route.IntervalMin << endl;
}

int FindRouteTo(Route* routes, int routesCount, string findStop)
{
	for (int i = 0; i < routesCount; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (findStop == routes[i].RouteStop[j])
			{
				return i;
			}
		}
	}
	return -1;
}
