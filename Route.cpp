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

	cout << "Введите остановку для поиска: ";
	string findStop;
	getline(cin, findStop);
	int findRoute = FindRouteTo(routes, routesCount, findStop);
	if (findRoute != -1)
	{
		cout << "Остановка " << findStop << " есть в рейсе №" << routes[findRoute].Number << endl;
	}
	else cout << "Рейс не найден" << endl;
}

void ReadRouteFromConsole(Route& route)
{
	setlocale(LC_ALL, "ru");
	
	bool CheckRouteNumber = false;
	while (CheckRouteNumber == false)
	{
		try
		{
			cout << "Введите номер рейса: ";
			int Number;
			CheckInput(&Number);
			if (Number < 0)
			{
				throw exception("Неправильный номер рейса! Повторите ввод.");
			}
			route.Number = Number;
			CheckRouteNumber = true;
		}
		catch (const exception&)
		{
			cout << "Неправильный номер рейса! Повторите ввод." << endl;
		}
	}

	bool CheckTimeMin = false;
	while (CheckTimeMin == false)
	{
		try
		{
			cout << "Введите среднюю продолжительность рейса в минутах: ";
			int TimeMin;
			CheckInput(&TimeMin);
			//route cannot be under 10 minutes
			if (TimeMin < 10)
			{
				throw exception("Неправильная продолжительность! Повторите ввод.");
			}
			route.TimeMin = TimeMin;
			CheckTimeMin = true;
		}
		catch (const exception&)
		{
			cout << "Неправильная продолжительность! Повторите ввод." << endl;
		}
	}

	bool CheckIntervalMin = false;
	while (CheckIntervalMin == false)
	{
		try
		{
			cout << "Введите средний интервал между рейсами в минутах: ";
			int IntervalMin;
			CheckInput(&IntervalMin);
			if (IntervalMin < 5)
			{
				throw exception("Неправильный интервал! Повторите ввод.");
			}
			route.IntervalMin = IntervalMin;
			CheckIntervalMin = true;
		}
		catch (const exception&)
		{
			cout << "Неправильный интервал! Повторите ввод." << endl;
		}
	}

	bool CheckRouteStopCount = false;
	while (CheckRouteStopCount == false)
	{
		try
		{
			cout << "Введите количество остановок: ";
			int RouteStopCount;
			CheckInput(&RouteStopCount);
			if (RouteStopCount < 1 || RouteStopCount > 20)
			{
				throw exception("Количество остановок должно быть от 2 до 20. Повторите ввод.");
			}
			route.RouteStopCount = RouteStopCount;
			CheckRouteStopCount = true;
		}
		catch (const exception&)
		{
			cout << "Количество остановок должно быть от 2 до 20. Повторите ввод." << endl;
		}
	}

	cin.ignore(32767, '\n');
	for (int i = 0; i < route.RouteStopCount; i++)
	{
		int j = i;
		cout << "\nВведите остановку №" << j + 1 << ": ";
		getline(cin, route.RouteStop[i]);
	}
}

void WriteRouteFromConsole(Route& route)
{
	setlocale(LC_ALL, "ru");

	cout << "Рейс №" << route.Number << ". Путь следования: ";

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


	cout << "Время следования: " << route.TimeMin << "\nИнтервал между автобусами: " << route.IntervalMin << endl;
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
