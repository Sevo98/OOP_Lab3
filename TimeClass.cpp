#include <iostream>
#include "TimeClass.h"
#include "CheckInputInt.h"

using namespace std;

void TimeClass::ReadTimeFromConsole()
{
	bool CheckYear = false;
	while (CheckYear == false)
	{
		try
		{
			cout << "������� ���: ";
			int year;
			CheckInputInt(&year);
			if (year < 2020)
			{
				throw exception("������������ ���! ��������� ����.");
			}
			this->Year = year;
			CheckYear = true;
		}
		catch (const std::exception&)
		{
			cout << "������������ ���! ��������� ����." << endl;
		}
	}

	bool CheckMonth = false;
	while (CheckMonth == false)
	{
		try
		{
			cout << "������� ����� ������: ";
			int month;
			CheckInputInt(&month);
			if (month <= 0 || month > 12)
			{
				throw exception("������������ �����! ��������� ����.");
			}
			this->Month = month;
			CheckMonth = true;
		}
		catch (const std::exception&)
		{
			cout << "������������ �����! ��������� ����." << endl;
		}
	}

	bool CheckDay = false;
	while (CheckDay == false)
	{
		try
		{
			cout << "������� ����: ";
			int day;
			CheckInputInt(&day);
			if (day <= 0 || day > 30)
			{
				throw exception("������������ ����! ��������� ����.");
			}
			this->Day = day;
			CheckDay = true;
		}
		catch (const std::exception&)
		{
			cout << "������������ ����! ��������� ����." << endl;
		}
	}

	bool CheckHour = false;
	while (CheckHour == false)
	{
		try
		{
			cout << "������� ���: ";
			int hour;
			CheckInputInt(&hour);
			if (hour < 0 || hour > 24)
			{
				throw exception("������������ ���! ��������� ����.");
			}
			this->Hour = hour;
			CheckHour = true;
		}
		catch (const std::exception&)
		{
			cout << "������������ ���! ��������� ����." << endl;
		}
	}

	bool CheckMinute = false;
	while (CheckMinute == false)
	{
		try
		{
			cout << "������� ������: ";
			int minute;
			CheckInputInt(&minute);
			if (minute < 0 || minute > 60)
			{
				throw exception("������������ ������! ��������� ����.");
			}
			this->Minute = minute;
			CheckMinute = true;
		}
		catch (const std::exception&)
		{
			cout << "������������ ������! ��������� ����." << endl;
		}
	}
}

void TimeClass::WriteTimeFromConsole()
{
	cout << this->Day << "." << this->Month << "." << this->Year << " " << this->Hour << ":" << this->Minute;
}
