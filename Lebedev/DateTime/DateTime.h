#pragma once
#include <iostream>
using namespace std;

class DateTime {
	int year;
	int month;
	int day;
	void isCorrect();
	void CheckNewValue();
public:
	DateTime();
	DateTime(int y);
	DateTime(int y, int m);
	DateTime(int y, int m, int d);

	friend istream& operator >> (istream& in, DateTime& dt);
	friend ostream& operator << (ostream& out, const DateTime& dt);

	int operator - (const DateTime& dt) const;
	DateTime operator + (const int& days);

	DateTime operator ++();
	DateTime operator ++(int);

	bool operator == (const DateTime& dt) const;
	bool operator != (const DateTime& dt) const;
	bool operator > (const DateTime & dt) const;
	bool operator >= (const DateTime & dt) const;
	bool operator < (const DateTime & dt) const;
	bool operator <= (const DateTime & dt) const;

	int Julian();
	int DayOfTheWeek();

	//set day,month,year
	//get day,month,year
	//get Julian
};
