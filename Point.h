#pragma once
#include <iostream>
#include <string>

struct Point
{
	double X;
	double Y;
};

void ReadPointFromConsole(Point& point);
void WritePointFromConsole(Point& point);