#include <iostream>
#include "Models3D.h"
using namespace std;

void Models3D::SetPolygons(Polygons* polygons)
{
	this->polygons = polygons;
}

void Models3D::SetPolygonsCount(int count)
{
	if (count <= 0)
	{
		throw exception("Количество полигонов не может быть отрицательным или равно 0");
	}
	this->PolygonsCount = count;
}

Polygons* Models3D::GetPolygons()
{
	return this->polygons;
}

int Models3D::GetPolygonsCount()
{
	return this->PolygonsCount;
}

Models3D::Models3D()
{
}

Models3D::Models3D(Polygons* polygons, int count)
{
	SetPolygons(polygons);
	SetPolygonsCount(count);
}
