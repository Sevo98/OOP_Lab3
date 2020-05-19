#include <iostream>
#include "FlightClass.h"
#include "CheckInputInt.h"
#include <string>

using namespace std;

void FlightClass::ReadFlightFromConsole()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите номер рейса: ";

	getline(cin, this->Number);
	//this->Number = "55x55";
	cout << "\nВведите пункт отправления: ";
	getline(cin, this->DeparturePoint);
	//this->DeparturePoint = "Томск";
	cout << "\nВведите пункт назначения: ";
	getline(cin, this->DestinationPoint);
	//this->DestinationPoint = "Алматы";
	cout << "\nВведите дату вылета: " << endl;
	this->DepartureTime.ReadTimeFromConsole();
	bool CheckTime = false;
	while (CheckTime == false)
	{
		try
		{
			cout << "Введите дату прибытия: ";
			this->DestinationTime.ReadTimeFromConsole();

			//Диаграмма условий в файле "Условия.png"
			if (this->DestinationTime.Year < this->DepartureTime.Year)
			{
				throw exception("Неправильная дата вылета!. Повторите ввод.");
			}
			//если год одинаковый, то проверяем месяца
			else if (this->DestinationTime.Year == this->DepartureTime.Year)
			{
				if (this->DestinationTime.Month < this->DepartureTime.Month)
				{
					throw exception("Неправильная дата вылета!. Повторите ввод.");
				}
				//если месяца одинаковые, то проверяем дни
				else if (this->DestinationTime.Month == this->DepartureTime.Month)
				{
					if (this->DestinationTime.Day < this->DepartureTime.Day)
					{
						throw exception("Неправильная дата вылета!. Повторите ввод.");
					}
					//если дни одинаковые, то проверяем часы
					else if (this->DestinationTime.Day == this->DepartureTime.Day)
					{
						if (this->DestinationTime.Hour < this->DepartureTime.Hour)
						{
							throw exception("Неправильное время вылета!. Повторите ввод.");
						}
						//если часы одинаковые, то проверяем минуты
						else if (this->DestinationTime.Hour == this->DepartureTime.Hour)
						{
							if (this->DestinationTime.Minute <= this->DepartureTime.Minute)
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

void FlightClass::WriteFlightFromConsole()
{
	cout << "Рейс №" << this->Number << " " << this->DeparturePoint << "-" << this->DestinationPoint << " Вылет: ";
	this->DepartureTime.WriteTimeFromConsole();
	cout << " Прибытие: ";
	this->DestinationTime.WriteTimeFromConsole();
}

void FlightClass::GetFlightTimeMinutes()
{
	int dayCount, hourCount, minuteCount;

	dayCount = this->DestinationTime.Day - this->DepartureTime.Day;
	hourCount = this->DestinationTime.Hour - this->DepartureTime.Hour;
	minuteCount = this->DestinationTime.Minute - this->DepartureTime.Minute;

	if (dayCount == 0)
	{
		if (hourCount < 0)
		{
			throw exception("Неправильно введены часы!");
		}

		if (minuteCount < 0)
		{
			minuteCount = this->DestinationTime.Minute + this->DepartureTime.Minute;
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
				minuteCount = this->DestinationTime.Minute + this->DepartureTime.Minute;
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
			hourCount = this->DestinationTime.Hour - this->DepartureTime.Hour + 24;
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
				minuteCount = this->DestinationTime.Minute + this->DepartureTime.Minute;
				if (minuteCount >= 60)
				{
					minuteCount = minuteCount - 60;
					hourCount = hourCount + 1;
				}
			}
		}
	}

	cout << "\nРейс № " << this->Number << " " << this->DeparturePoint << " - " << this->DestinationPoint << " Время полета: ";
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

void FlightClass::DemoFlightWithTime()
{
	this->ReadFlightFromConsole();
	this->WriteFlightFromConsole();
	this->GetFlightTimeMinutes();
}
