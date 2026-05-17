#pragma once
#include "Geometry.h"

class Circle : public Figure
{
	Point center;
	double radius;
	BoundingBox bbox();
	//isCorrect();
public:
	void print_name();
	Circle(Point CENTER, double RADIUS);   
	Circle(double RADIUS);

	double calc_area();
	double calc_perimeter();
};