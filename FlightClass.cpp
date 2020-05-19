#include <iostream>
#include "FlightClass.h"
#include "CheckInputInt.h"
#include <string>

using namespace std;

void FlightClass::ReadFlightFromConsole()
{
	setlocale(LC_ALL, "ru");
	cout << "������� ����� �����: ";

	getline(cin, this->Number);
	//this->Number = "55x55";
	cout << "\n������� ����� �����������: ";
	getline(cin, this->DeparturePoint);
	//this->DeparturePoint = "�����";
	cout << "\n������� ����� ����������: ";
	getline(cin, this->DestinationPoint);
	//this->DestinationPoint = "������";
	cout << "\n������� ���� ������: " << endl;
	this->DepartureTime.ReadTimeFromConsole();
	bool CheckTime = false;
	while (CheckTime == false)
	{
		try
		{
			cout << "������� ���� ��������: ";
			this->DestinationTime.ReadTimeFromConsole();

			//��������� ������� � ����� "�������.png"
			if (this->DestinationTime.Year < this->DepartureTime.Year)
			{
				throw exception("������������ ���� ������!. ��������� ����.");
			}
			//���� ��� ����������, �� ��������� ������
			else if (this->DestinationTime.Year == this->DepartureTime.Year)
			{
				if (this->DestinationTime.Month < this->DepartureTime.Month)
				{
					throw exception("������������ ���� ������!. ��������� ����.");
				}
				//���� ������ ����������, �� ��������� ���
				else if (this->DestinationTime.Month == this->DepartureTime.Month)
				{
					if (this->DestinationTime.Day < this->DepartureTime.Day)
					{
						throw exception("������������ ���� ������!. ��������� ����.");
					}
					//���� ��� ����������, �� ��������� ����
					else if (this->DestinationTime.Day == this->DepartureTime.Day)
					{
						if (this->DestinationTime.Hour < this->DepartureTime.Hour)
						{
							throw exception("������������ ����� ������!. ��������� ����.");
						}
						//���� ���� ����������, �� ��������� ������
						else if (this->DestinationTime.Hour == this->DepartureTime.Hour)
						{
							if (this->DestinationTime.Minute <= this->DepartureTime.Minute)
							{
								throw exception("������������ ����� ������!. ��������� ����.");
							}
						}
					}
				}
			}
			CheckTime = true;
		}
		catch (const exception&)
		{
			cout << "������������ ���� ������! ��������� ����." << endl;
		}
	}
}

void FlightClass::WriteFlightFromConsole()
{
	cout << "���� �" << this->Number << " " << this->DeparturePoint << "-" << this->DestinationPoint << " �����: ";
	this->DepartureTime.WriteTimeFromConsole();
	cout << " ��������: ";
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
			throw exception("����������� ������� ����!");
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
			//��� �� ��� ��� � daycount == 0
			if (hourCount < 0)
			{
				throw exception("����������� ������� ����!");
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

			//��� �� ��� ��� � daycount == 0
			if (hourCount < 0)
			{
				throw exception("����������� ������� ����!");
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

	cout << "\n���� � " << this->Number << " " << this->DeparturePoint << " - " << this->DestinationPoint << " ����� ������: ";
	if (dayCount > 0)
	{
		cout << dayCount << "�. ";
	}
	if (hourCount > 0)
	{
		cout << hourCount << "�. ";
	}

	cout << minuteCount << "�����." << endl;
}

void FlightClass::DemoFlightWithTime()
{
	this->ReadFlightFromConsole();
	this->WriteFlightFromConsole();
	this->GetFlightTimeMinutes();
}
