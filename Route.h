#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Route
{
	int Number;
	int TimeMin;
	int IntervalMin;
	int RouteStopCount;
	string RouteStop[20];
};

void DemoRoute();

void ReadRouteFromConsole(Route& route);
void WriteRouteFromConsole(Route& route);
int FindRouteTo(Route* routes, int routesCount, string findStop);