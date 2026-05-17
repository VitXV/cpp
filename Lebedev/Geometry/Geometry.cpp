#include "Geometry.h"

double distance(Point p1, Point p2)
{
	return sqrt( pow(p2.getX() - p1.getX(),2) + pow(p2.getY() - p1.getY(),2) );
}

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double X, double Y)
{
	x = X;
	y = Y;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

bool Point::operator == (const Point& p) const
{
	return (x == p.x && y == p.y);
}

BoundingBox::BoundingBox(Point MN, Point MX)
{
	mn = MN;
	mx = MX;
}