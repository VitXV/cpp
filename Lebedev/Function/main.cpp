#include <iostream>
#include "Function.h"

using namespace std;

int main()
{
	cout << Hyperbola(5).value(2) << endl;

	cout << Parabola(1, 1, 1).value(5) << endl;

	cout << Exponent().value(1) << endl;

	cout << Hyperbola(1).min(3, 5) << endl;
	cout << Hyperbola(10).max(-3, -1) << endl;

	cout << Parabola(1, 0, 0).min(2, 16) << endl;
	cout << Parabola(-1, 0, 0).max(-2, 4) << endl;

	cout << Exponent().min(4, 10) << endl;
	cout << Exponent().max(-5, 0) << endl;

	cout << endl;

	std::cout << Hyperbola(1).integration(1) << std::endl;
	std::cout << Hyperbola(1).differentiation(1) << std::endl;

	cout << endl;

	std::cout << Parabola(3, 2, 0).integration(1) << std::endl;
	std::cout << Parabola(1, 1, 1).differentiation(1) << std::endl;

	cout << endl;
	std::cout << Exponent().integration(1) << std::endl;
	std::cout << Exponent().differentiation(1) << std::endl;

	cout << endl;

	return 0;
}
