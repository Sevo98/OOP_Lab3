#pragma once
#include "Point3D.h"
class Polygons
{
	Point3D _point1;
	Point3D _point2;
	Point3D _point3;
public:
	void SetPoint1(Point3D point1);
	void SetPoint2(Point3D point2);
	void SetPoint3(Point3D point3);

	Point3D GetPoint1();
	Point3D GetPoint2();
	Point3D GetPoint3();

	Polygons();
	Polygons(Point3D point1, Point3D point2, Point3D point3);
};

