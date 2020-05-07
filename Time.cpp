#include <iostream>
#include "Time.h"
#include "CheckInputInt.h"

using namespace std;

void ReadTimeFromConsole(Time& time)
{
	bool CheckYear = false;
	while (CheckYear == false)
	{
		try
		{
			cout << "Введите год: ";
			int year;
			CheckInputInt(&year);
			if (year < 2020)
			{
				throw exception("Неправильный год! Повторите ввод.");
			}
			time.Year = year;
			CheckYear = true;
		}
		catch (const std::exception&)
		{
			cout << "Неправильный год! Повторите ввод." << endl;
		}
	}

	bool CheckMonth = false;
	while (CheckMonth == false)
	{
		try
		{
			cout << "Введите номер месяца: ";
			int month;
			CheckInputInt(&month);
			if (month <= 0 || month > 12)
			{
				throw exception("Неправильный месяц! Повторите ввод.");
			}
			time.Month = month;
			CheckMonth = true;
		}
		catch (const std::exception&)
		{
			cout << "Неправильный месяц! Повторите ввод." << endl;
		}
	}

	bool CheckDay = false;
	while (CheckDay == false)
	{
		try
		{
			cout << "Введите день: ";
			int day;
			CheckInputInt(&day);
			if (day <= 0 || day > 30)
			{
				throw exception("Неправильный день! Повторите ввод.");
			}
			time.Day = day;
			CheckDay = true;
		}
		catch (const std::exception&)
		{
			cout << "Неправильный день! Повторите ввод." << endl;
		}
	}

	bool CheckHour = false;
	while (CheckHour == false)
	{
		try
		{
			cout << "Введите час: ";
			int hour;
			CheckInputInt(&hour);
			if (hour < 0 || hour > 24)
			{
				throw exception("Неправильный час! Повторите ввод.");
			}
			time.Hour = hour;
			CheckHour = true;
		}
		catch (const std::exception&)
		{
			cout << "Неправильный час! Повторите ввод." << endl;
		}
	}

	bool CheckMinute = false;
	while (CheckMinute == false)
	{
		try
		{
			cout << "Введите минуты: ";
			int minute;
			CheckInputInt(&minute);
			if (minute < 0 || minute > 60)
			{
				throw exception("Неправильные минуты! Повторите ввод.");
			}
			time.Minute = minute;
			CheckMinute = true;
		}
		catch (const std::exception&)
		{
			cout << "Неправильные минуты! Повторите ввод." << endl;
		}
	}
}

void WriteTimeFromConsole(Time& time)
{
	cout << time.Day << "." << time.Month << "." << time.Year << " " << time.Hour << ":" << time.Minute;
}
