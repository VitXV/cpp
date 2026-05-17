#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Exception {}; // Under contruction

class Point
{
	double x, y;
public:
	Point();
	Point(double X, double Y);
	double getX();
	double getY();
	void setX(double X);
	void setY(double Y);

	bool operator == (const Point& p) const;

	friend class Triangle;
	friend class Rectangle;
	friend class Circle;
	friend class Ellipse;
	friend class Polygon;
};

double distance(Point p1, Point p2);

class BoundingBox
{
	Point mn, mx;
public:
	BoundingBox(Point mn, Point mx);
	friend class Triangle;
	friend class Rectangle;
};

class Figure
{
	virtual BoundingBox bbox() = 0;
	virtual void isCorrect() = 0;
public:
	virtual void print_name() = 0;
	
	virtual double calc_area() = 0;
	virtual double calc_perimeter() = 0;
};
	
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Polygon.h"