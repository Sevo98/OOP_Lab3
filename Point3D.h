#pragma once
class Point3D
{
	double _x, _y, _z;
public:
	void SetX(double X);
	void SetY(double Y);
	void SetZ(double Z);
	
	double GetX();
	double GetY();
	double GetZ();

	Point3D();
	Point3D(double X, double Y, double Z);
};

