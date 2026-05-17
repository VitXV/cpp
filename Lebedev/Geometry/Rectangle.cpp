#include "Rectangle.h"

void Rectangle::isCorrect()
{
	return;
}

void Rectangle::print_name()
{
	std::cout << "Rectangle";
}

Rectangle::Rectangle(Point P1, Point P2, Point P3, Point P4)
{
	pts[0] = P1;
	pts[1] = P2;
	pts[2] = P3;
	pts[3] = P4;
	isCorrect();
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	pts[0] = Point(x1, y1);
	pts[1] = Point(x2, y2);
	pts[2] = Point(x3, y3);
	pts[3] = Point(x4, y4);
	isCorrect();
}

Rectangle::Rectangle(double side1, double side2)
{
	pts[0] = Point(0, 0);
	pts[1] = Point(side1, 0);
	pts[2] = Point(side1, side2);
	pts[3] = Point(0, side2);
	isCorrect();
}

BoundingBox Rectangle::bbox()
{
	Point MN = pts[0]; // Minimum point, init
	Point MX = pts[0]; // Maximum point, init

	for (int i = 0; i < 4; i++)
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

double Rectangle::calc_area()
{
	BoundingBox box = this->bbox();
	return (box.mx.x - box.mn.x) * (box.mx.y - box.mn.y);
}

double Rectangle::calc_perimeter()
{
	BoundingBox box = this->bbox();
	return (box.mx.x - box.mn.x)*2 + (box.mx.y - box.mn.y)*2;
}