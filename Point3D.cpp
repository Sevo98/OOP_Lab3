#include <iostream>
#include "Point3D.h"
using namespace std;

void Point3D::SetX(double X)
{
	if (X < -1000 || X > 1000)
	{
		throw exception("Координаты должны быть в диапазоне (-1000, 1000)");
	}
	this->_x = X;
}

void Point3D::SetY(double Y)
{
	if (Y < -1000 || Y > 1000)
	{
		throw exception("Координаты должны быть в диапазоне (-1000, 1000)");
	}
	this->_y = Y;
}

void Point3D::SetZ(double Z)
{
	if (Z < -1000 || Z > 1000)
	{
		throw exception("Координаты должны быть в диапазоне (-1000, 1000)");
	}
	this->_z = Z;
}

double Point3D::GetX()
{
	return this->_x;
}

double Point3D::GetY()
{
	return this->_y;
}

double Point3D::GetZ()
{
	return this->_z;
}

Point3D::Point3D(){}

Point3D::Point3D(double X, double Y, double Z)
{
	SetX(X);
	SetY(Y);
	SetZ(Z);
}
