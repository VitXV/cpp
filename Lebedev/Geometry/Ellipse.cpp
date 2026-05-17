#include "Ellipse.h"

void Ellipse::isCorrect()
{
	return; // Under contruction
}

void Ellipse::print_name()
{
	std::cout << "Ellipse";
}

Ellipse::Ellipse(Point CENTER, double A, double B)
{
	center = CENTER;
	a = A;
	b = B;
}

Ellipse::Ellipse(Point CENTER, double RADIUS)
{
	center = CENTER;
	a = RADIUS;
	b = RADIUS;
}

Ellipse::Ellipse(double A, double B)
{
	center = Point(A,B);
	a = A;
	b = B;
}

Ellipse::Ellipse(double RADIUS)
{
	center = Point(RADIUS,RADIUS);
	a = RADIUS;
	b = RADIUS;
}

BoundingBox Ellipse::bbox()
{
	Point MN(center.x - a, center.y - b);
	Point MX(center.x + a, center.y + b);
	return BoundingBox(MN, MX);
}

double Ellipse::calc_area()
{
	return M_PI * a * b;
}

double Ellipse::calc_perimeter()
{
	return M_PI * (3 * (a+b) - sqrt( (3*a + b) * (a + 3*b) ));
}