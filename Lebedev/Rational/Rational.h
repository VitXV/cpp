#pragma once
#include <iostream>
using namespace std;

class Exception{};

class Rational
{
	void simplify();
	int Find_X0(int n);
public:
	int num;
	int den;
	Rational();
	Rational(int n);
	Rational(int n, int d);

	template <class T> Rational& operator +=(const T& t);
	template <class T> Rational operator + (const T& t) const;

	Rational operator -() const;

	template <class T> Rational& operator -= (const T& t);
	template <class T> Rational operator - (const T& t) const;

	Rational& operator ++(); // префикс
	Rational operator ++(int); // постфикс

	Rational& operator --();
	Rational operator --(int);

	template <class T> Rational& operator *= (const T& t);
	template <class T> Rational operator * (const T& t) const;

	template <class T> Rational& operator /= (const T& t);
	template <class T> Rational operator / (const T& t) const;

	template <class T> bool operator == (const T& t) const;
	template <class T> bool operator != (const T& t) const;
	template <class T> bool operator > (const T& t) const;
	template <class T> bool operator >= (const T& t) const;
	template <class T> bool operator < (const T& t) const;
	template <class T> bool operator <= (const T& t) const;

	explicit operator int() const;
	explicit operator float() const;
	operator double() const;

	Rational(double number);

	friend istream& operator >> (istream& in, Rational& r);
	friend ostream& operator << (ostream& out, const Rational& r);

	Rational SQRT();
};

template <class T> Rational& Rational::operator +=(const T& t)
{
	Rational r(t);
	num = (num * r.den + den * r.num);
	den = den * r.den;
	simplify();
	return *this;
}

template <class T> Rational Rational::operator + (const T& t) const
{
	Rational r(t);
	Rational res = *this;
	return res += r;
}

template <class T> Rational& Rational::operator -= (const T& t)
{
	Rational r(t);
	return (*this += (-r));
}

template <class T> Rational Rational::operator - (const T& t) const
{
	Rational r(t);
	return *this + (-r);
}

template <class T> Rational& Rational::operator *= (const T& t)
{
	Rational r(t);
	num = num * r.num;
	den = den * r.den;
	simplify();
	return *this;
}

template <class T> Rational Rational::operator * (const T& t) const
{
	Rational r(t);
	Rational res(*this);
	return res *= r;
}

template <class T> Rational& Rational::operator /= (const T& t)
{
	Rational r(t);
	num = num * r.den;
	den = den * r.num;
	simplify();
	return *this;
}

template <class T> Rational Rational::operator / (const T& t) const
{
	Rational r(t);
	Rational res(*this);
	return res /= r;
}

template <class T> bool Rational::operator == (const T& t) const
{
	Rational r(t);
	return (num == r.num) && (den == r.den);
}

template <class T> bool Rational::operator != (const T& t) const
{
	Rational r(t);
	return !(*this == r);
}

template <class T> bool Rational::operator > (const T& t) const
{
	Rational r(t);
	return (num * r.den) > (r.num * den);
}

template <class T> bool Rational::operator >= (const T& t) const
{
	Rational r(t);
	return (*this > r) || (*this == r);
}

template <class T> bool Rational::operator < (const T& t) const
{
	Rational r(t);
	return !(*this > r) && !(*this == r);
}

template <class T> bool Rational::operator <= (const T& t) const
{
	Rational r(t);
	return !(*this > r);
}
