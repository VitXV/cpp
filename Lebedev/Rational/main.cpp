#include <iostream>
#include "Rational.h"
using namespace std;

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

	if (a == 0)
	{
		cout << "x = " << Rational(-c, b);
		return 0;
	}

	Rational D;
	D = b * b - (Rational)4 * a * c;

	if (D < 0)
	{
		cout << endl <<	"D < 0" << endl;
		return 1;
	}

	Rational x1, x2;
	x1 = (-b - D.SQRT()) / ((Rational)2 * a);
	x2 = (-b + D.SQRT()) / ((Rational)2 * a);

	cout << "x1 = " << x1;
	cout << endl;
	cout << "x2 = " << x2;

	return 0;
}
