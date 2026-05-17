#pragma once
#include "Geometry.h"

class Ellipse : public Figure
{
	Point center;
	double a, b;
	BoundingBox bbox();
	//isCorrect();
public:
	void print_name();

	Ellipse(Point CENTER, double A, double B);
	Ellipse(Point CENTER, double RADIUS); // Circle
	Ellipse(double A, double B);
	Ellipse(double RADIUS); // Circle

	double calc_area();
	double calc_perimeter();
};