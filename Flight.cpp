#include <iostream>
#include "Time.h"
#include "CheckInputInt.h"
#include "Flight.h"
#include <string>
using namespace std;

void ReadFlightFromConsole(Flight& flight)
{
	setlocale(LC_ALL, "ru");
	cout << "Введите номер рейса: ";
	
	getline(cin, flight.Number);
	//flight.Number = "55x55";
	cout << "\nВведите пункт отправления: ";
	getline(cin, flight.DeparturePoint);
	//flight.DeparturePoint = "Томск";
	cout << "\nВведите пункт назначения: ";
	getline(cin, flight.DestinationPoint);
	//flight.DestinationPoint = "Алматы";
	cout << "\nВведите дату вылета: " << endl;
	ReadTimeFromConsole(flight.DepartureTime);
	bool CheckTime = false;
	while (CheckTime == false)
	{
		try
		{
			cout << "Введите дату прибытия: ";
			ReadTimeFromConsole(flight.DestinationTime);

			//Диаграмма условий в файле "Условия.png"
			if (flight.DestinationTime.Year < flight.DepartureTime.Year)
			{
				throw exception("Неправильная дата вылета!. Повторите ввод.");
			}
			//если год одинаковый, то проверяем месяца
			else if (flight.DestinationTime.Year == flight.DepartureTime.Year)
			{
				if (flight.DestinationTime.Month < flight.DepartureTime.Month)
				{
					throw exception("Неправильная дата вылета!. Повторите ввод.");
				}
				//если месяца одинаковые, то проверяем дни
				else if (flight.DestinationTime.Month == flight.DepartureTime.Month)
				{
					if (flight.DestinationTime.Day < flight.DepartureTime.Day)
					{
						throw exception("Неправильная дата вылета!. Повторите ввод.");
					}
					//если дни одинаковые, то проверяем часы
					else if (flight.DestinationTime.Day == flight.DepartureTime.Day)
					{
						if (flight.DestinationTime.Hour < flight.DepartureTime.Hour)
						{
							throw exception("Неправильное время вылета!. Повторите ввод.");
						}
						//если часы одинаковые, то проверяем минуты
						else if (flight.DestinationTime.Hour == flight.DepartureTime.Hour)
						{
							if (flight.DestinationTime.Minute <= flight.DepartureTime.Minute)
							{
								throw exception("Неправильное время вылета!. Повторите ввод.");
							}
						}
					}
				}
			}
			CheckTime = true;
		}
		catch (const exception&)
		{
			cout << "Неправильная дата вылета! Повторите ввод." << endl;
		}
	}
}

void WriteFlightFromConsole(Flight& flight)
{
	cout << "Рейс №" << flight.Number << " " << flight.DeparturePoint << "-" << flight.DestinationPoint << " Вылет: ";
	WriteTimeFromConsole(flight.DepartureTime);
	cout << " Прибытие: ";
	WriteTimeFromConsole(flight.DestinationTime);
}

void DemoFlightWithTime()
{
	const int flightCount = 5;
	Flight flight[flightCount];
	for (int i = 0; i < flightCount; i++)
	{
		ReadFlightFromConsole(flight[i]);
	}
	for (int i = 0; i < flightCount; i++)
	{
		WriteFlightFromConsole(flight[i]);
	}
	
	for (int i = 0; i < flightCount; i++)
	{
		GetFlightTimeMinutes(flight[i]);
	}
}

void GetFlightTimeMinutes(Flight& flight)
{
	int dayCount, hourCount, minuteCount;

	dayCount = flight.DestinationTime.Day - flight.DepartureTime.Day;
	hourCount = flight.DestinationTime.Hour - flight.DepartureTime.Hour;
	minuteCount = flight.DestinationTime.Minute - flight.DepartureTime.Minute;

	if (dayCount == 0)
	{
		if (hourCount < 0)
		{
			throw exception("Неправильно введены часы!");
		}

		if (minuteCount < 0)
		{
			minuteCount = flight.DestinationTime.Minute + flight.DepartureTime.Minute;
			if (minuteCount >= 60)
			{
				minuteCount = minuteCount - 60;
				hourCount = hourCount + 1;
			}
		}
	}
	else if (dayCount > 0)
	{
		if (hourCount > 0 || hourCount == 0)
		{
			//тот же код что и daycount == 0
			if (hourCount < 0)
			{
				throw exception("Неправильно введены часы!");
			}

			if (minuteCount < 0)
			{
				minuteCount = flight.DestinationTime.Minute + flight.DepartureTime.Minute;
				if (minuteCount >= 60)
				{
					minuteCount = minuteCount - 60;
					hourCount = hourCount + 1;
				}
			}
		}

		else if (hourCount < 0)
		{
			dayCount = dayCount - 1;
			hourCount = flight.DestinationTime.Hour - flight.DepartureTime.Hour + 24;
			if (hourCount >= 24)
			{
				hourCount = hourCount - 24;
				dayCount = dayCount + 1;
			}

			//тот же код что и daycount == 0
			if (hourCount < 0)
			{
				throw exception("Неправильно введены часы!");
			}

			if (minuteCount < 0)
			{
				minuteCount = flight.DestinationTime.Minute + flight.DepartureTime.Minute;
				if (minuteCount >= 60)
				{
					minuteCount = minuteCount - 60;
					hourCount = hourCount + 1;
				}
			}
		}
	}
	
	cout << "\nРейс № " << flight.Number << " " << flight.DeparturePoint << " - " << flight.DestinationPoint << " Время полета: ";
	if (dayCount > 0)
	{
		cout << dayCount << "д. ";
	}
	if (hourCount > 0)
	{
		cout << hourCount << "ч. ";
	}

	cout << minuteCount << "минут." << endl;
}