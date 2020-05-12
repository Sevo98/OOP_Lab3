#include <iostream>
#include "Time.h"
#include "CheckInputInt.h"
#include "Flight.h"
#include <string>
using namespace std;

void ReadFlightFromConsole(Flight& flight)
{
	setlocale(LC_ALL, "ru");
	cout << "������� ����� �����: ";
	
	getline(cin, flight.Number);
	//flight.Number = "55x55";
	cout << "\n������� ����� �����������: ";
	getline(cin, flight.DeparturePoint);
	//flight.DeparturePoint = "�����";
	cout << "\n������� ����� ����������: ";
	getline(cin, flight.DestinationPoint);
	//flight.DestinationPoint = "������";
	cout << "\n������� ���� ������: " << endl;
	ReadTimeFromConsole(flight.DepartureTime);
	bool CheckTime = false;
	while (CheckTime == false)
	{
		try
		{
			cout << "������� ���� ��������: ";
			ReadTimeFromConsole(flight.DestinationTime);

			//��������� ������� � ����� "�������.png"
			if (flight.DestinationTime.Year < flight.DepartureTime.Year)
			{
				throw exception("������������ ���� ������!. ��������� ����.");
			}
			//���� ��� ����������, �� ��������� ������
			else if (flight.DestinationTime.Year == flight.DepartureTime.Year)
			{
				if (flight.DestinationTime.Month < flight.DepartureTime.Month)
				{
					throw exception("������������ ���� ������!. ��������� ����.");
				}
				//���� ������ ����������, �� ��������� ���
				else if (flight.DestinationTime.Month == flight.DepartureTime.Month)
				{
					if (flight.DestinationTime.Day < flight.DepartureTime.Day)
					{
						throw exception("������������ ���� ������!. ��������� ����.");
					}
					//���� ��� ����������, �� ��������� ����
					else if (flight.DestinationTime.Day == flight.DepartureTime.Day)
					{
						if (flight.DestinationTime.Hour < flight.DepartureTime.Hour)
						{
							throw exception("������������ ����� ������!. ��������� ����.");
						}
						//���� ���� ����������, �� ��������� ������
						else if (flight.DestinationTime.Hour == flight.DepartureTime.Hour)
						{
							if (flight.DestinationTime.Minute <= flight.DepartureTime.Minute)
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

void WriteFlightFromConsole(Flight& flight)
{
	cout << "���� �" << flight.Number << " " << flight.DeparturePoint << "-" << flight.DestinationPoint << " �����: ";
	WriteTimeFromConsole(flight.DepartureTime);
	cout << " ��������: ";
	WriteTimeFromConsole(flight.DestinationTime);
}

void DemoFlightWithTime()
{
	const int flightCount = 2;
	Flight flight[flightCount];
	for (int i = 0; i < flightCount; i++)
	{
		ReadFlightFromConsole(flight[i]);
	}
	for (int i = 0; i < flightCount; i++)
	{
		WriteFlightFromConsole(flight[i]);
	}
	
}
