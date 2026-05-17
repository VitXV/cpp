#include "Geometry.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream file("polygon.txt");
	
	int k;
	file >> k;

	double x, y;
	Point* points = new Point[k];
	for (int i = 0; i < k; i++)
	{
		file >> x >> y;
		points[i].setX(x);
		points[i].setY(y);
	}

	Polygon Field(k, points);
	cout << "Area = " << setprecision(2) <<  fixed << Field.calc_area();


	/*
	// Testing classes

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
	Point M(14, 15);
	Point N(10, 15);

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

	Point c_e(5, 5);
	Ellipse E(c_e, 5, 3);
	std::cout << std::endl;
	E.print_name();
	std::cout << std::endl;

	std::cout << "Area = " << E.calc_area() << std::endl;

	std::cout << "Perimeter = " << E.calc_perimeter() << std::endl;

	Point points1[] = { Point(1,2),
					   Point(3,4),
					   Point(6,4),
					   Point(8,6),
					   Point(10,6),
					   Point(10,4),
					   Point(8,2),
					   Point(6,2),
					   Point(5,1),
					   Point(4,2) };
	Polygon POLYGON(10, points1);
	std::cout << std::endl;
	POLYGON.print_name();
	std::cout << std::endl;

	std::cout << "Area = " << POLYGON.calc_area() << std::endl;

	std::cout << "Perimeter = " << POLYGON.calc_perimeter() << std::endl;

	*/
	
	return 0;
}