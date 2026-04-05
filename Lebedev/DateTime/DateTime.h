#pragma once
#include <iostream>
using namespace std;

class DateTime {
	int year, month, day;
	int hour = 0, minute = 0, second = 0;
	void isCorrect();
	void CheckNewValue();
	bool isLeap();
public:
	DateTime();
	DateTime(int y);
	DateTime(int y, int M);
	DateTime(int y, int M, int d);
	DateTime(int y, int M, int d, int h);
	DateTime(int y, int M, int d, int h, int m);
	DateTime(int y, int M, int d, int h, int m, int s);

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

	DateTime Easter();
	 
	void now();

	void setYear(int y);
	void setMonth(int M);
	void setDay(int d);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();
	int getSecond();
};