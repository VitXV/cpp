#pragma once
#include "Geometry.h"

class Triangle : public Figure
{
	Point pts[3];
	BoundingBox bbox();
	void isCorrect();
public:
	void print_name();
	Triangle(Point P1, Point P2, Point P3); // Points
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3); // Points
	Triangle(double side1, double side2, double side3); // Sides. Default pts[0] = (0,0)

	double calc_area();
	double calc_perimeter();
};