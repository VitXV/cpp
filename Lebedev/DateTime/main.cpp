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
	
	DateTime dt10 = dt1;
	DateTime dt11(dt2);
	cout << dt10 << endl;
	cout << dt11 << endl;

	try
	{
		DateTime WRONG1(-1995, 2, 1);
		cout << WRONG1 << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}
	try
	{
		DateTime WRONG2(2015, 13, 1);
		cout << WRONG2 << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}
	try
	{
		DateTime WRONG3(2020, 6, 100);
		cout << WRONG3 << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}
	try
	{
		DateTime WRONG4(2025, 2, 29);
		cout << WRONG4 << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}

	cout << endl << endl;

	dt1 = DateTime(2000, 1, 1);
	dt2 = DateTime(2001, 1, 1);

	cout << dt2 - dt1 << endl;
	cout << dt1 - dt2 << endl;

	cout << endl;

	while (true)
	{
		try
		{
			cout << "Enter Date(YYYY-MM-DD): ";
			cin >> dt3;
			cout << dt3;
			break;
		}
		catch (const Exception& e)
		{
			cout << endl << "Wrong Input" << endl;
		}
	}

	cout << endl;

	dt3 = DateTime(2000, 1, 1);
	dt3 = dt3 + 365 + 31;
	cout << endl<<dt3+7 << endl;

	cout << endl;

	DateTime t(2026, 04, 19);
	int j = t.DayOfTheWeek();
	cout << j;

	try
	{
		t.setYear(-1);
		cout << endl << endl << t << endl << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}

	while (true)
	{
		try
		{
			DateTime E1;
			cout << endl;
			cout << "Enter DateTime format yyyy-MM-ddThh:mm:ss, example: 2021-12-21T07:54:34 " << endl;
			cin >> E1;
			cout << E1 << endl;
			break;
		}
		catch (const Exception& e)
		{
			cout << endl << "Wrong Input";
		}
	}
	while (true)
	{
		try
		{
			DateTime E2;
			cout << endl;
			cout << "Enter DateTime format yyyy-MM-dd, example: 2021-12-21 " << endl;
			cin >> E2;
			cout << E2 << endl;
			break;
		}
		catch (const Exception& e)
		{
			cout << endl << "Wrong Input";
		}
	}
	while (true)
	{
		try
		{
			DateTime E3;
			cout << endl;
			cout << "Enter DateTime format hh:mm:ss, example: 07:54:34 " << endl;
			cin >> E3;
			cout << E3 << endl;
			break;
		}
		catch (const Exception& e)
		{
			cout << endl << "Wrong Input";
		}
	}

	DateTime ASD(2026, 4, 5, 1, 30, 45);
	DateTime DFG(2026, 4, 5, 0, 45, 30);

	cout << endl << ASD;
	cout << endl << (ASD < DFG);

	DateTime NOW;
	NOW.now();
	cout << endl << endl << "NOW: " << NOW;

	DateTime estr(2026);
	cout << endl << "Easter 2026: " << estr.Easter();

	cout << endl;

	DateTime dt;
	dt.now();
	cout << "Julian today: " << dt.Julian();

	cout << endl;

	/*
    DateTime test(1995, 12, 12);
    cout << ReversedOutput(test)<<endl;

    DateTime testInput;
    cin >> ReversedInput(testInput); 

    cout << endl << testInput;
	*/

	return 0;
}
