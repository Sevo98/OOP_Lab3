#pragma once
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;
//��� ��������� "Rectangle" �������� �������� ���� � �������� rectangle, ������� �������� �������� ������� Rectangles
struct Rectangles 
{
	double Length;
	double Width;
	Point point;
};

void ReadRectanglesFromConsole(Rectangles& rectangle);
void WriteRectanglesFromConsole(Rectangles& rectangle);
void DemoRectangleWithPoint();