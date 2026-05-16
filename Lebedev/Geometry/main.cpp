#include "Geometry.h"
#include <iostream>

int main()
{
	Point A(4, 3);
	Point B(4, 0);
	Point C(0, 3);
	Triangle ABC(A, B, C);

	ABC.print_name(); std::cout << std::endl;

	std::cout << "Area = " << ABC.calc_area() << std::endl;

	std::cout << "Perimeter = " << ABC.calc_perimeter() << std::endl;



	Triangle abc(5, 12, 13); // Sides
	std::cout << std::endl;
	abc.print_name();
	std::cout << std::endl;

	std::cout << "Area = " << abc.calc_area() << std::endl;

	std::cout << "Perimeter = " << abc.calc_perimeter() << std::endl;



	Rectangle r2x5(2, 5);
	std::cout << std::endl;
	r2x5.print_name(); 
	std::cout << std::endl;

	std::cout << "Area = " << r2x5.calc_area() << std::endl;

	std::cout << "Perimeter = " << r2x5.calc_perimeter() << std::endl;



	Point K(10, 10);
	Point L(14, 10);
	Point M(10, 15);
	Point N(14, 15);

	Rectangle KLMN(K, L, M, N);

	std::cout << std::endl;
	KLMN.print_name();
	std::cout << std::endl;

	std::cout << "Area = " << KLMN.calc_area() << std::endl;

	std::cout << "Perimeter = " << KLMN.calc_perimeter() << std::endl;



	Circle O(1);
	std::cout << std::endl;
	O.print_name();
	std::cout << std::endl;

	std::cout << "Area = " << O.calc_area() << std::endl;

	std::cout << "Perimeter = " << O.calc_perimeter() << std::endl;



	Point c(7, 4);
	Circle O1(c,1);
	std::cout << std::endl;
	O1.print_name();
	std::cout << std::endl;

	std::cout << "Area = " << O1.calc_area() << std::endl;

	std::cout << "Perimeter = " << O1.calc_perimeter() << std::endl;
}