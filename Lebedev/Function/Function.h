#pragma once

class Exception {};

class Function
{
public:
	virtual double value(double x) = 0;
	virtual double min(double start, double end) = 0;
	virtual double max(double start, double end) = 0;
};

class Hyperbola : public Function
{
	double k;
public:
	Hyperbola(double K);
	double value(double x);
	double min(double start, double end);
	double max(double start, double end);
	double integration(double x);
	double differentiation(double x);
};

class Parabola : public Function
{
	double a, b, c;
public:
	Parabola(double A, double B, double C);
	double value(double x);
	double min(double start, double end);
	double max(double start, double end);
	double integration(double x);
	double differentiation(double x);
};

class Exponent : public Function
{
public:
	double value(double x);
	double min(double start, double end);
	double max(double start, double end);
	double integration(double x);
	double differentiation(double x);
};
