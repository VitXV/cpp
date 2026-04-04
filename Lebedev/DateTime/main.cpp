#include <iostream>
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

	return 0;
}
