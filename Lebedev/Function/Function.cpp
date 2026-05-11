#include "Function.h"
#include <cmath>

Hyperbola::Hyperbola(double K)
{
	k = K;
}

double Hyperbola::value(double x)
{
	if (x == 0)  // Zero division
		throw Exception();
	return k / x;
}

double Hyperbola::min(double start, double end)
{
	if (start > end)
		throw Exception();

	if (start >= 0 && end <= 0) // undefined
		throw Exception();
	if (start <= 0 && end >= 0) // undefined
		throw Exception();

	if (k < 0)
		return start;
	if (k > 0)
		return end;
}
double Hyperbola::max(double start, double end)
{
	if (start > end)
		throw Exception();

	if (start >= 0 && end <= 0) // undefined
		throw Exception();
	if (start <= 0 && end >= 0) // undefined
		throw Exception();

	if (k < 0)
		return end;
	if (k > 0)
		return start;
}

Parabola::Parabola(double A, double B, double C)
{
	if (A == 0) // not a Parabola
		throw Exception();
	a = A;
	b = B;
	c = C;
}

double Parabola::value(double x)
{
	return (a*x*x + b*x + c);
}

double Parabola::min(double start, double end)
{
	if (start > end)
		throw Exception();
	double xv = -b / (2*a);

	if (a > 0)
	{
		if (start >= xv)
			return start;
		else
		{
			if (end <= xv)
				return end;
			else
				return xv;
		}
	}
	else
	{
		if (start >= xv)
			return end;
		else
		{
			if (end <= xv)
				return start;
			else
			{
				if (abs(xv - start) >= abs(end - xv))
					return start;
				else
					return end;
			}
		}
	}
}
double Parabola::max(double start, double end)
{
	if (start > end)
		throw Exception();
	double xv = -b / (2 * a);

	if (a > 0)
	{
		if (start >= xv)
			return end;
		else
		{
			if (end <= xv)
				return start;
			else
			{
				if (abs(xv - start) > abs(end - xv))
					return start;
				else
					return end;
			}
		}
	}
	else
	{
		if (start >= xv)
			return start;
		else
		{
			if (end <= xv)
				return end;
			else
				return xv;
		}
	}
}

double Exponent::value(double x)
{
	return exp(x);
}

double Exponent::min(double start, double end)
{
	if (start > end)
		throw Exception();
	return start;
}
double Exponent::max(double start, double end)
{
	if (start > end)
		throw Exception();
	return end;
}

