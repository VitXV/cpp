#include <iostream>
#include <algorithm>
#include "DateTime.h"
using namespace std;

int main() {
	// DateTime class demonstration

	//default contructor
	DateTime dt1; // without agruments = unix format (1970.01.01)
	cout << dt1 << endl;

	/* Exists 7 contructors:
	
	DateTime() 
	DateTime(year)
	DateTime(year, month)
	DateTime(year, month, day)
	DateTime(year, month, day, hour)
	DateTime(year, month, day, hour, minute)
	DateTime(year, month, day, hour, minute, second)

	if time is not specified, only the date will be displayed in std::cout
	*/

	DateTime dtDateOnly(2000, 6, 1);
	cout << dtDateOnly << endl;

	DateTime dtWithTime(2000, 6, 1, 12, 30);
	cout << dtWithTime << endl;

	// You can also display only the time

	cout << Time(dtWithTime) << endl;

	/* There are many different types of input:
	
	yyyy-mm-dd or yyyy.mm.dd
	yyyy-mm-ddThh-mm-ss or yyyy.mm.ddThh.mm.ss
	hh:mm:ss

	But if you want to enter a date in dd-mm-yyyy or dd.mm.yyy format, you need do the folliwing:

	std::cin >> ReversedInput(DateTime obj);

	This only works for dates

	*/

	// You can also use ReversedOutput() to display dd-mm-yyyy format

	DateTime r;
	cout << endl << r << " | " << ReversedOutput(r) << endl;

	DateTime UserInput;
	
	while (true)
	{
		try
		{
			cout << endl << "Now you can try to input DateTime: ";
			cin >> UserInput;
			break;
		}
		catch (const Exception& e)
		{
			cout << endl << "Wrong input, try again" << endl;
		}
	}
	cout << "You entered: " << UserInput;

	while (true)
	{
		try
		{
			cout << endl << "Now you can try to input REVERSED DateTime: ";
			cin >> ReversedInput(UserInput);
			break;
		}
		catch (const Exception& e)
		{
			cout << endl << "Wrong input, try again" << endl;
		}
	}
	cout << "You entered: " << UserInput << endl;
	cout << "You entered (reversed output): " << ReversedOutput(UserInput) << endl;

	// Some other demonstrations:

	/*
	DateTime dt1(2000);
	DateTime dt10 = dt1;
	DateTime dt100(dt1);
	cout << dt10 << endl;
	cout << dt11 << endl;

	try
	{
		DateTime WRONG1(-1995, 2, 1);    // year can not be less than 0
		cout << WRONG1 << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}
	try
	{
		DateTime WRONG2(2015, 13, 1); // month can not be less than 0, greater than 12
		cout << WRONG2 << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}
	try
	{
		DateTime WRONG3(2020, 6, 100); // day cannot be less than zero and greater than possible
		cout << WRONG3 << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}
	try
	{
		DateTime WRONG4(2025, 2, 29); // February 29th is not possible in a non-leap year
		cout << WRONG4 << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}

	// You can subtract the number of days from two dates.
	dt1 = DateTime(2000, 1, 1); 
	dt2 = DateTime(2001, 1, 1);

	cout << dt2 - dt1 << endl;
	cout << dt1 - dt2 << endl;

	// You can add a number of days to the date.
	dt3 = DateTime(2000, 1, 1);
	dt3 = dt3 + 365 + 31;
	cout << endl<< dt3+7 << endl;


	// You can find out the current day of the week
	DateTime t(2026, 04, 19);
	int j = t.DayOfTheWeek();
	cout << j;


	// Setters and getters
	try
	{
		t.setYear(-1);
		cout << endl << endl << t << endl << endl;
	}
	catch (const Exception& e)
	{
		cout << endl << "Exception!";
	}

	// You can compare DateTime objects
	DateTime ASD(2026, 4, 5, 1, 30, 45);
	DateTime DFG(2026, 4, 5, 0, 45, 30);

	cout << endl << ASD;
	cout << endl << (ASD < DFG);

	// Current DateTime
	DateTime NOW;
	NOW.now();
	cout << endl << endl << "NOW: " << NOW;

	// Easter :)
	DateTime estr(2026);
	cout << endl << "Easter 2026: " << estr.Easter();

	// Julian day format
	DateTime dtj;
	dtj.now();
	cout << "Julian today: " << dtj.Julian();
		*/

	// Post & prefix increments add one day
	DateTime dtIncsTest(2005);
	dtIncsTest++;
	++dtIncsTest;
	++dtIncsTest++;
	cout << endl << dtIncsTest++;
	cout << endl << dtIncsTest;

	// method .unix() sets year = 1970, month = 1, day = 1
	
	// .DateToInt() method represents your date as a number without separators.
	DateTime dti(1995, 10, 1);
	cout << endl << "DateToInt: " <<dti.DateToInt();
	
	// .TimeToInt()
	DateTime tti(1995, 10, 1, 12, 30, 34);
	cout << endl << "TimeToInt: " << tti.TimeToInt();

	cout << endl;

	// .IntToDate

	int itd= 20051111;
	DateTime dtitd;
	dtitd = dtitd.IntToDate(itd);
	cout << endl << "IntToDate: " << dtitd;

	// .IntToTime

	int itt= 53005;
	DateTime dtitt;
	dtitt = dtitt.IntToTime(itt);
	cout << endl << "IntToTime: " << Time(dtitt);

	// Setters and getters

	DateTime sng;
	sng.setYear(2020);
	cout << endl << "Setter demonstration: " << sng;

	sng.setDay(12);
	cout << endl << "Getter demonstration: day = " << sng.getDay();

	return 0;
}
