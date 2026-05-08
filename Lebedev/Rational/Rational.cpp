#include <iostream>
#include "Rational.h"
using namespace std;

void Rational::simplify()
{
	if (den == 0)
		throw Exception();

	if (den < 0)
	{
		num = -num;
		den = -den;
	}

	int ns = abs(num);
	int ds = abs(den);
	while (ns != 0 && ds != 0)
	{
		if (ns > ds)
			ns = ns % ds;
		else
			ds = ds % ns;
	}
	num = num / (ns + ds);
	den = den / (ns + ds);
}

Rational::Rational()
{
	num = 0;
	den = 1;
}
Rational::Rational(int n)
{
	num = n;
	den = 1;
}
Rational::Rational(int n, int d)
{
	if (d == 0)
		throw Exception();
	num = n;
	den = d;
	simplify();
}

Rational Rational::operator -() const
{
	Rational r(-num, den);
	return r;
}

Rational& Rational::operator ++()
{
	num += den;
	return *this;
}
Rational Rational::operator ++(int)
{
	Rational r(*this);
	num += den;
	return r;
}

Rational& Rational::operator --()
{
	num -= den;
	return *this;
}
Rational Rational::operator --(int)
{
	Rational r(*this);
	num -= den;
	return r;
}

Rational::operator int() const
{
	return num / den;
}
Rational::operator float() const
{
	return ((float)num) / den;
}
Rational::operator double() const
{
	return ((double)num) / den;
}

Rational::Rational(double number)
{
	num = number * 100000;
	den = 100000;
	simplify();
}

istream& operator >> (istream& in, Rational& r)
{
	in >> r.num >> r.den;
	if (r.den == 0)
		throw Exception();
	r.simplify();
	return in;
}
ostream& operator << (ostream& out, const Rational& r)
{
	if (r.den == 1)
		out << r.num;
	else
		out << r.num << "/" << r.den;
	return out;
}

int Rational::Find_X0(int n)
{
	int a = 0;
	for (int i = 1;; i++)
	{
		if (i > n/i)
		{
			a = i - 1;
			break;
		}
	}
	return a;
}

Rational Rational::SQRT()
{
	if (*this == 0)
		return 0;
	if (*this < 0)
		throw Exception();

	int An = Find_X0(num);
	int Ad = Find_X0(den);

	int Xn = An;
	for (;;)
	{
		if (Xn > INT_MAX - (num / Xn))
			break;
		if ((Xn + (num / Xn)) / 2 >= Xn)
			break;
		Xn = (Xn + (num / Xn)) / 2;
	}

	int Xd = Ad;
	for (;;)
	{
		if (Xd > INT_MAX - (den / Xd))
			break;
		if ((Xd + (den / Xd)) / 2 >= Xd)
			break;
		Xd = (Xd + (den / Xd)) / 2;
	}

	Rational R(Xn, Xd);
	return R;
}
