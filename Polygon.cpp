#include <iostream>
#include "Polygon.h"
using namespace std;


void Polygons::SetPoint1(Point3D point1)
{
	this->_point1 = point1;
}

void Polygons::SetPoint2(Point3D point2)
{
	this->_point2 = point2;
}

void Polygons::SetPoint3(Point3D point3)
{
	this->_point3 = point3;
}

Point3D Polygons::GetPoint1()
{
	return this->_point1;
}

Point3D Polygons::GetPoint2()
{
	return this->_point2;
}

Point3D Polygons::GetPoint3()
{
	return this->_point3;
}

Polygons::Polygons()
{
}

Polygons::Polygons(Point3D point1, Point3D point2, Point3D point3)
{
	SetPoint1(point1);
	SetPoint2(point2);
	SetPoint3(point3);
}
