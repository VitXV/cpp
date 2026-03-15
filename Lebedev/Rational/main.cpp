#include <iostream>
#include "Rational.h"
using namespace std;

int Find_X0(int n) {
	int a = 0;
	for (int i=0;; i++)
	{
		if (n < i*i)
		{
			a = i - 1;
			break;
		}
	}
	return a;
}
Rational SQRT_Algorithm(Rational r)
{
	if (r == 0)
		return 0;
	if (r < 0)
		throw Exception();
	
	int An = Find_X0(r.num);
	int Ad = Find_X0(r.den);

	int Xn = An;
	for (int n = 0; n < 4; n++)
		Xn = (Xn + r.num / Xn) / 2;
	
	int Xd = Ad;
	for (int n = 0; n < 4; n++)
		Xd = (Xd + r.den / Xd) / 2;

	Rational R(Xn, Xd);
	return R;
}

int main()
{
	Rational a, b, c;
	cout << "a * x^2 + b*x + c = 0" << endl;
	cout << "Enter a: ";
	cin >> a;

	cout << "Enter b: ";
	cin >> b;

	cout << "Enter c: ";
	cin >> c;

	Rational D;
	D = b * b - (Rational)4 * a * c;

	if (D < 0)
	{
		cout << endl <<	"D < 0" << endl;
		return 1;
	}

	Rational x1, x2;

	Rational SQRT_D = SQRT_Algorithm(D);
	x1 = (-b - SQRT_D) / ((Rational)2 * a);
	x2 = (-b + SQRT_D) / ((Rational)2 * a);

	cout << "x1 = " << x1;
	cout << endl;
	cout << "x2 = " << x2;
	
	return 0;
}