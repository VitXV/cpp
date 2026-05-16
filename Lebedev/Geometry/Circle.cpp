#include "Circle.h"

void Circle::print_name()
{
	std::cout << "Circle";
}

Circle::Circle(Point CENTER, double RADIUS)
{
	center = CENTER;
	radius = RADIUS;
}

Circle::Circle(double RADIUS)
{
	center = Point(RADIUS, RADIUS);
	radius = RADIUS;
}


BoundingBox Circle::bbox()
{
	Point MN(center.x - radius, center.y - radius);
	Point MX(center.x + radius, center.y + radius);
	return BoundingBox(MN, MX);
}

double Circle::calc_area()
{
	return M_PI * radius * radius;
}

double Circle::calc_perimeter()
{
	return 2 * M_PI * radius;
}