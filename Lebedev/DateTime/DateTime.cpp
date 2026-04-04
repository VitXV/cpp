#include <iostream>
#include <iomanip>
#include "DateTime.h"
using namespace std;

class Exception {};

int mdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

void DateTime::isCorrect()
{
	if (year < 0)
		throw Exception();
	if (month < 1 || month > 12)
		throw Exception();
	if (year % 4 == 0 && month == 2)
	{
		if (day < 1 || day>29)
			throw Exception();
		return;
	}
	if (day < 1 || day > mdays[month-1])
		throw Exception();
}
void DateTime::CheckNewValue()
{
	if (year % 4 == 0 && month == 2)
	{
		if (day > 29)
		{
			month += 1;
			day = 1;
		}
	}
	if (day > mdays[month-1])
	{
		month += 1;
		day = 1;
	}
	if (month > 12)
	{
		year += 1;
		month = 1;
	}
}
int DateTime::Julian()
{
	int a = (14 - month) / 12;
	int y = year + 4800 - a;
	int m = month + 12*a - 3;

	return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}
int DateTime::DayOfTheWeek()
{
	return Julian() % 7;
}

DateTime::DateTime() {
	year = 1970;
	month = 1;
	day = 1;
}
DateTime::DateTime(int y) {
	year = y;
	month = 1;
	day = 1;
	isCorrect();
}
DateTime::DateTime(int y, int m) {
	year = y;
	month = m;
	day = 1;
	isCorrect();
}
DateTime::DateTime(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
	isCorrect();
}

istream& operator >> (istream& in, DateTime& dt)
{
	in >> dt.year >> dt.month >> dt.day;
	dt.isCorrect();
	return in;
}
ostream& operator << (ostream& out, const DateTime& dt)
{
	out << dt.year << "-" << setfill('0') << setw(2) << dt.month << "-" << setfill('0') << setw(2) << dt.day;
	return out;
}

int DateTime::operator - (const DateTime& dt) const
{
	int days = 0;
	if (*this == dt)
		return 0;

	// Подразумевается, что вычитать будут меньшее от большего, но если это не так, то приходится менять переменные местами
	DateTime cp1 = dt; 
	DateTime cp2 = *this;
	if (*this < dt)
	{
		cp1 = *this;
		cp2 = dt;
	}

	while (cp1 != cp2)
	{
		cp1++;
		days++;
	}
	return days;
}
DateTime DateTime::operator + (const int& days)
{
	for (int k = days; k > 0; k--)
	{
		day++;
		CheckNewValue();
	}
	return *this;
}

DateTime DateTime::operator ++()
{
	day += 1;
	CheckNewValue();
	return *this;
}
DateTime DateTime::operator ++(int)
{
	DateTime dt(*this);
	day += 1;
	CheckNewValue();
	return dt;
}

bool DateTime::operator == (const DateTime& dt) const
{
	return (year == dt.year) && (month == dt.month) && (day == dt.day);
}
bool DateTime::operator != (const DateTime& dt) const
{
	return !(*this == dt);
}
bool DateTime::operator > (const DateTime & dt) const
{
	if (year > dt.year)
		return true;
	else if (year == dt.year && month > dt.month)
		return true;
	else if (year == dt.year && month == dt.month && day > dt.day)
		return true;
	else
		return false;
}
bool DateTime::operator >= (const DateTime & dt) const
{
	return (*this > dt) || (*this == dt);
}
bool DateTime::operator < (const DateTime & dt) const
{
	return !(*this >= dt);
}
bool DateTime::operator <= (const DateTime & dt) const
{
	return !(*this < dt);
}
