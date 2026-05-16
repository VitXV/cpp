#include "Triangle.h"

void Triangle::print_name()
{
	std::cout << "Triangle";
}

Triangle::Triangle(Point P1, Point P2, Point P3)
{
	pts[0] = P1;
	pts[1] = P2;
	pts[2] = P3;
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	pts[0] = Point(x1, y1);
	pts[1] = Point(x2, y2);
	pts[2] = Point(x3, y3);
}

Triangle::Triangle(double side1, double side2, double side3)
{
	pts[0] = Point(0, 0);

	pts[1] = Point(side3,0);

	pts[2].x = (pow(side2,2) + pow(side3,2) - pow(side1,2)) / (2*side3);
	pts[2].y = sqrt( pow(side2,2) - pow(pts[2].x,2) );
}

BoundingBox Triangle::bbox()
{
	Point MN = pts[0]; // Minimum point, init
	Point MX = pts[0]; // Maximum point, init

	for (int i = 0; i < 3; i++)
	{
		if (pts[i].x < MN.x)
			MN.x = pts[i].x;
		if (pts[i].y < MN.y)
			MN.y = pts[i].y;
		if (pts[i].x > MX.x)
			MX.x = pts[i].x;
		if (pts[i].y > MX.y)
			MX.y = pts[i].y;
	}
	return BoundingBox(MN, MX);
}

double Triangle::calc_area()
{
	// Calculate bounding box of triangle, and then divide it
	BoundingBox box = this->bbox();
	return (box.mx.x - box.mn.x) * (box.mx.y - box.mn.y) / 2;
}

double Triangle::calc_perimeter()
{
	return distance(pts[0], pts[1]) + distance(pts[1], pts[2]) + distance(pts[2], pts[0]);
}