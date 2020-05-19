#pragma once
#include"PointClass.h"
class RectangleClass
{
	double Length;
	double Width;
	PointClass point;
public:
	void ReadRectanglesFromConsole();
	void WriteRectanglesFromConsole();
	void DemoRectangleWithPoint();
};

