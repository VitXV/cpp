#pragma once
#include "Geometry.h"

class Polygon : public Figure
{
	int k;
	Point* pts;
	BoundingBox bbox();
	void isCorrect();
	// if pts[o] == pts[k] => delete last
public:
	void print_name();
	
	Polygon(int K, Point* PTS);
	
	double calc_area();
	double calc_perimeter();

	~Polygon();
};