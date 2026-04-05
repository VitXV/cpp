#include <iostream>
#include <algorithm>
#include "DateTime.h"
using namespace std;

int main() {
	//test

	DateTime dt1(2000);
	DateTime dt2(2005,8);
	DateTime dt3(2010,4,2);

	cout << dt1 << endl;
	cout << dt2 << endl;
	cout << dt3 << endl;

	/*
	DateTime dt10 = dt1;
	DateTime dt11(dt2);
	cout << dt10 << endl;
	cout << dt11 << endl;
	*/

	/*
	DateTime WRONG1(-1995, 2, 1);
	DateTime WRONG2(2015, 13, 1);
	DateTime WRONG3(2020, 6, 100);
	DateTime WRONG4(2025, 2, 29);

	cout << WRONG1 << endl;
	cout << WRONG2 << endl;
	cout << WRONG3 << endl;
	cout << WRONG4 << endl;
	*/

	cout << endl;

	dt1 = DateTime(2000, 1, 1);
	dt2 = DateTime(2001, 1, 1);

	cout << dt2 - dt1 << endl;
	cout << dt1 - dt2 << endl;

	/*
	cout << endl;
	cout << "Enter Date(YYYY-MM-DD): ";
	cin >> dt3;

	cout << endl << dt3;
	*/

	dt3 = DateTime(2000, 1, 1);
	dt3 = dt3 + 365 + 31;
	cout << dt3+7 << endl;

	cout << endl;

	DateTime t(2026, 04, 19);
	int j = t.DayOfTheWeek();
	cout << j;

	/*
	DateTime E1;
	cout << endl;
	cout << "Enter DateTime format yyyy-MM-ddThh:mm:ss, example: 2021-12-21T07:54:34 " << endl;
	cin >> E1;
	cout << E1 << endl;

	DateTime E2;
	cout << endl;
	cout << "Enter DateTime format yyyy-MM-dd, example: 2021-12-21 " << endl;
	cin >> E2;
	cout << E2 << endl;

	DateTime E3;
	cout << endl;
	cout << "Enter DateTime format hh:mm:ss, example: 07:54:34 " << endl;
	cin >> E3;
	cout << E3 << endl;
	*/


	DateTime ASD(2026, 4, 5, 1, 30, 45);
	DateTime DFG(2026, 4, 5, 0, 45, 30);

	cout << endl << ASD;
	cout << endl << (ASD < DFG);

	DateTime NOW;
	NOW.now();
	cout << endl << endl << "NOW: " << NOW;

	DateTime estr(2026);
	cout << endl << "Easter 2026: " << estr.Easter();


	//приложение 1
	/*
	DateTime datas[26] =
	{
		(1995,  1,  1),
		(1994,  4, 26),
		(1992, 12,  5),
		(1994,  7, 12),
		(1993,  9, 11),
		(1992,  7, 21),
		(1997,  6, 29),
		(1997,  2,  6),
		(1995, 10, 31),
		(1993,  8, 18),
		(1995,  3,  2),
		(1996,  8, 12),
		(1997,  1, 28),
		(1995, 12, 15),
		(1997,  6,  9),
		(1993, 11, 10),
		(1994,  7,  5),
		(1993,  6,  6),
		(1997,  8, 21),
		(1996,  9, 28),
		(1993,  1, 14),
		(1992, 10,  2),
		(1997,  6, 13),
		(1996,  8, 18),
		(1994,  6,  8),
		(1993,  5,  4)
	};
	*/

	return 0;
}