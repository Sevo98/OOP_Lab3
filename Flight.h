#pragma once
#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

struct Flight
{
	string Number = "";
	string DeparturePoint = "";
	string DestinationPoint = "";
	Time DepartureTime;
	Time DestinationTime;
};

void ReadFlightFromConsole(Flight& flight);
void WriteFlightFromConsole(Flight& flight);

void DemoFlightWithTime();