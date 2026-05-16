#pragma once
#include "Geometry.h"

class Rectangle : public Figure
{
	Point pts[4];
	BoundingBox bbox();
	//isCorrect();
public:
	void print_name();
	Rectangle(Point P1, Point P2, Point P3, Point P4); // Points
	Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4); // Points
	Rectangle(double side1, double side2); // Sides. side1 = x length, side2 = y length

	double calc_area();
	double calc_perimeter();
};