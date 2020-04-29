#include <iostream>
#include <string>

using namespace std;
//2.2.7.1
struct Circle
{
	double X, Y, Radius;
	string Color;
};

Circle* MakeCircle(double X, double Y, double Radius, string Color)
{
	Circle* circle = new Circle();
	circle->X = X;
	circle->Y = Y;
	circle->Radius = Radius;
	circle->Color = Color;
	return circle;
}

Circle* CopyCircle(Circle circle)
{
	Circle* copiedCircle = new Circle();
	copiedCircle->X = circle.X;
	copiedCircle->Y = circle.Y;
	copiedCircle->Radius = circle.Radius;
	copiedCircle->Color = circle.Color;
	return copiedCircle;
}

void DemoCircle()
{
	Circle* circle1 = MakeCircle(5, 7.5, 15, "Blue");
	Circle* circle2 = MakeCircle(4.4, 9.6, 14, "Grey");
	Circle* circle3 = MakeCircle(3.4, 8.7, 13, "Red");

	Circle* copyCircle1 = CopyCircle(*circle1);
	Circle* copyCircle2 = CopyCircle(*circle2);
	Circle* copyCircle3 = CopyCircle(*circle3);

	delete circle1, circle2, circle3;
	delete copyCircle1, copyCircle2, copyCircle3;
}