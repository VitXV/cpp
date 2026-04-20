#pragma once
#include <iostream>
using namespace std;

class Exception {};

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

	friend void ReversedDataOut(ostream& out, const DateTime& dt);

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

	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	int DateToInt();
	int TimeToInt();
};

// Всё что дальше я подсмотрел в интернете, чтобы можно было проще приводить к нужному формату

struct DateTimeReversedOutput
{
	const DateTime& dt;
};

DateTimeReversedOutput ReversedOutput(const DateTime& dt);
ostream& operator << (ostream& out, const DateTimeReversedOutput& r);

struct DateTimeReversedInput
{
	DateTime& dt;
};

DateTimeReversedInput ReversedInput(DateTime& dt);
istream& operator >> (istream& in, const DateTimeReversedInput& r);
