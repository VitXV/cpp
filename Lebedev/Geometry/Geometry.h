#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Exception {}; // Under contruction

class Point
{
	double x, y;
	Point(); // private! that's how it was intended
public:
	Point(double X, double Y);
	double getX();
	double getY();

	friend class BoundingBox;
	friend class Triangle;
	friend class Rectangle;
	friend class Circle;
};

double distance(Point p1, Point p2);

class BoundingBox
{
	Point mn, mx;
public:
	BoundingBox(Point mn, Point mx);
	friend class Triangle;
	friend class Rectangle;
	friend class Circle;
};

class Figure
{
	virtual BoundingBox bbox() = 0;
public:
	virtual void print_name() = 0;
	
	virtual double calc_area() = 0;
	virtual double calc_perimeter() = 0;
};

#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"