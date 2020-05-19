#pragma once
#include <string>
#include "TimeClass.h"

using namespace std;

class FlightClass
{
	string Number = "";
	string DeparturePoint = "";
	string DestinationPoint = "";
	TimeClass DepartureTime;
	TimeClass DestinationTime;
public:
	void ReadFlightFromConsole();
	void WriteFlightFromConsole();

	void DemoFlightWithTime();
	void GetFlightTimeMinutes();
};

