#pragma once
#include "Polygon.h"
class Models3D
{
	Polygons* polygons;
	int PolygonsCount;
public:
	void SetPolygons(Polygons* polygons);
	void SetPolygonsCount(int count);

	Polygons* GetPolygons();
	int GetPolygonsCount();
	Models3D();
	Models3D(Polygons* polygons, int count);
};

