#include "Polygon.h"

void Polygon::isCorrect()
{
	return; // Under contruction
}

void Polygon::print_name()
{
	std::cout << "Polygon";
}

Polygon::Polygon(int K, Point* PTS)
{
	k = K;
	pts = new Point[K]; // delete[] pts;
	for (int i = 0; i < K; i++)
	{
		pts[i] = PTS[i];
	}
}

BoundingBox Polygon::bbox()
{
	Point MN = pts[0]; // Minimum point, init
	Point MX = pts[0]; // Maximum point, init

	for (int i = 0; i < k; i++)
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

double Polygon::calc_area()
{
	//Gauss's method
	double area=0;

	for (int i = 0; i < k; i++)
	{
		area += pts[i].x * pts[(i+1)%k].y;
		area -= pts[(i+1)%k].x * pts[i].y;
	}
	return abs(area)/2;
}

double Polygon::calc_perimeter()
{
	double perimeter = 0; //ordered points only
	for (int i = 0; i < k; i++)
		perimeter += distance(pts[i], pts[(i+1)%k]);

	return perimeter;
}

Polygon::~Polygon()
{
	delete[] pts;
}