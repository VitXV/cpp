#include <iostream>
#include "Function.h"

int main()
{
	std::cout << Hyperbola(5).value(2) << std::endl;

	std::cout << Parabola(1, 1, 1).value(5) << std::endl;

	std::cout << Exponent().value(1) << std::endl;

	std::cout << Hyperbola(1).min(3, 5) << std::endl;
	std::cout << Hyperbola(10).max(-3, -1) << std::endl;

	std::cout << Parabola(1, 0, 0).min(2, 16) << std::endl;
	std::cout << Parabola(-1, 0, 0).max(-2, 4) << std::endl;

	std::cout << Exponent().min(4, 10) << std::endl;
	std::cout << Exponent().max(-5, 0) << std::endl;

	return 0;
}
