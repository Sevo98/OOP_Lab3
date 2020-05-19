#pragma once
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;
//имя структуры "Rectangle" вызывает конфликт имен с функцией rectangle, поэтому стуктуру пришлось назвать Rectangles
struct Rectangles 
{
	double Length;
	double Width;
	Point point;
};

void ReadRectanglesFromConsole(Rectangles& rectangle);
void WriteRectanglesFromConsole(Rectangles& rectangle);
void DemoRectangleWithPoint();