#include <iostream>
#include <iomanip>
#include <ctime>
#include "DateTime.h"

int mdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

bool DateTime::isLeap()
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}
void DateTime::isCorrect()
{
	if (year < 0)
		throw Exception();
	if (month < 1 || month > 12)
		throw Exception();
	if (isLeap() && month == 2)
	{
		if (day < 1 || day>29)
			throw Exception();
		return;
	}
	if (day < 1 || day > mdays[month-1])
		throw Exception();
	if (hour < 0 || hour > 23)
		throw Exception();
	if (minute < 0 || minute > 59)
		throw Exception();
	if (second < 0 || second > 59)
		throw Exception();
}
void DateTime::CheckNewValue()
{
	if (isLeap() && month == 2)
	{
		if (day > 29)
		{
			month += 1;
			day = 1;
		}
	}
	else if (day > mdays[month-1])
	{
		month += 1;
		day = 1;
	}
	if (month > 12)
	{
		year += 1;
		month = 1;
	}

	if (isLeap() && month == 3)
	{
		if (day < 1)
		{
			month -= 1;
			day = 29;
		}
	}
	else if (day < 1)
	{
		month -= 1;
		day = mdays[(month - 1 +12)%12];
	}
	if (month < 1)
	{
		year -= 1;
		month = 12;
	}
	if (year < 0)
		throw Exception();
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

DateTime DateTime::Easter()
{
	int a = year % 19;
	int b = year % 4;
	int c = year % 7;
	int d = (19*a + 15) % 30;
	int e = (2*b + 4*c + 6*d + 6) % 7;
	int f = d + e;
	if (f <= 26)
	{
		DateTime EasterDay(year, 4, 4 + f);
		return EasterDay;
	}
	else
	{
		DateTime EasterDay(year, 5, f-26);
		return EasterDay;
	}
}

void DateTime::now()
{
	time_t t = time(nullptr);
	tm timeinfo;
	localtime_s(&timeinfo, &t);

	year = timeinfo.tm_year + 1900;
	month = timeinfo.tm_mon + 1;
	day = timeinfo.tm_mday;
	hour = timeinfo.tm_hour;
	minute = timeinfo.tm_min;
	second = timeinfo.tm_sec;
}
void DateTime::unix()
{
	year = 1970;
	month = 1;
	day = 1;
}

DateTime::DateTime()
{
	year = 1970;
	month = 1;
	day = 1;
}
DateTime::DateTime(int y)
{
	year = y;
	month = 1;
	day = 1;
	isCorrect();
}
DateTime::DateTime(int y, int M)
{
	year = y;
	month = M;
	day = 1;
	isCorrect();
}
DateTime::DateTime(int y, int M, int d)
{
	year = y;
	month = M;
	day = d;
	isCorrect();
}
DateTime::DateTime(int y, int M, int d, int h)
{
	year = y;
	month = M;
	day = d;
	hour = h;
	isCorrect();
}
DateTime::DateTime(int y, int M, int d, int h, int m)
{
	year = y;
	month = M;
	day = d;
	hour = h;
	minute = m;
	isCorrect();
}
DateTime::DateTime(int y, int M, int d, int h, int m, int s)
{
	year = y;
	month = M;
	day = d;
	hour = h;
	minute = m;
	second = s;
	isCorrect();
}

istream& operator >> (istream& in, DateTime& dt)
{
	char ENTER[20];
	in >> ENTER;

	int V=0;
	for (int i = 0; i < 20; i++)
	{
		if (ENTER[i] == 'T' || ENTER[i] == 't')
		{
			V = 1;
			break;
		}
		if (ENTER[i] == ':')
		{
			V = 2;
			break;
		}
	}

	int i = 0;
	switch (V)
	{
		case 0:
		{
			dt.year = 0, dt.month = 0, dt.day = 0;

			for (; ENTER[i] != '-' && ENTER[i] != '.'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.year *= 10;
				dt.year += (int)ENTER[i]-48;
			}
			i++;
			for (; ENTER[i] != '-' && ENTER[i] != '.'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.month *= 10;
				dt.month += (int)ENTER[i]-48;
			}
			i++;
			for (; ENTER[i] != '\0'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.day *= 10;
				dt.day += (int)ENTER[i]-48;
			}
			break;
		}
		case 1:
		{
			dt.year = 0, dt.month = 0, dt.day = 0;

			for (; ENTER[i] != '-' && ENTER[i] != '.'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.year *= 10;
				dt.year += (int)ENTER[i] - 48;
			}
			i++;
			for (; ENTER[i] != '-' && ENTER[i] != '.'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.month *= 10;
				dt.month += (int)ENTER[i] - 48;
			}
			i++;
			for (; ENTER[i] != 'T' && ENTER[i] != 't'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.day *= 10;
				dt.day += (int)ENTER[i] - 48;
			}
			i++;
			for (; ENTER[i] != ':'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.hour *= 10;
				dt.hour += (int)ENTER[i] - 48;
			}
			i++;
			for (; ENTER[i] != ':'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.minute *= 10;
				dt.minute += (int)ENTER[i] - 48;
			}
			i++;
			for (; ENTER[i] != '\0'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.second *= 10;
				dt.second += (int)ENTER[i] - 48;
			}
			break;
		}
		case 2:
		{
			dt.unix();

			for (; ENTER[i] != ':'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.hour *= 10;
				dt.hour += (int)ENTER[i] - 48;
			}
			i++;
			for (; ENTER[i] != ':'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.minute *= 10;
				dt.minute += (int)ENTER[i] - 48;
			}
			i++;
			for (; ENTER[i] != '\0'; i++)
			{
				if (ENTER[i] < 48 || ENTER[i]>57)
					throw Exception();
				dt.second *= 10;
				dt.second += (int)ENTER[i] - 48;
			}
			break;
		}
	}
	dt.isCorrect();
	return in;
}
ostream& operator << (ostream& out, const DateTime& dt)
{
	if (dt.hour == 0 && dt.minute == 0 && dt.second == 0)
	{
		out << dt.year << "-" << setfill('0') << setw(2) << dt.month << "-" << setfill('0') << setw(2) << dt.day;
		return out;
	}
	else
	{
		out << dt.year << "-" << setfill('0') << setw(2) << dt.month << "-" << setfill('0') << setw(2) << dt.day << " "
			<< setfill('0') << setw(2) << dt.hour << ":" << setfill('0') << setw(2) << dt.minute << ":" << setfill('0') << setw(2) << dt.second;
		return out;
	}
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
DateTime DateTime::operator + (const int& days) const
{
	DateTime dt = *this;
	for (int k = days; k > 0; k--)
	{
		dt.day++;
		dt.CheckNewValue();
	}
	return dt;
}
DateTime DateTime::operator - (const int& days) const
{
	DateTime dt = *this;
	for (int k = days; k > 0; k--)
	{
		dt.day--;
		dt.CheckNewValue();
	}
	return dt;
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
	return (year == dt.year) && (month == dt.month) && (day == dt.day) && (hour == dt.hour) && (minute == dt.minute) && (second == dt.second);
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
	else if (year == dt.year && month == dt.month && day == dt.day && hour > dt.hour)
		return true;
	else if (year == dt.year && month == dt.month && day == dt.day && hour == dt.hour && minute > dt.minute)
		return true;
	else if (year == dt.year && month == dt.month && day == dt.day && hour == dt.hour && minute == dt.minute && second > dt.second)
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

void DateTime::setYear(int y)
{
	year = y;
	isCorrect();
}
void DateTime::setMonth(int M)
{
	month = M;
	isCorrect();
}
void DateTime::setDay(int d)
{
	day = d;
	isCorrect();
}
void DateTime::setHour(int h)
{
	hour = h;
	isCorrect();
}
void DateTime::setMinute(int m)
{
	minute = m;
	isCorrect();
}
void DateTime::setSecond(int s)
{
	second = s;
	isCorrect();
}

int DateTime::getYear() const
{
	return year;
}
int DateTime::getMonth() const
{
	return month;
}
int DateTime::getDay() const
{
	return day;
}
int DateTime::getHour() const
{
	return hour;
}
int DateTime::getMinute() const
{
	return minute;
}
int DateTime::getSecond() const
{
	return second;
}

int DateTime::TimeToSeconds() const
{
	return hour*3600 + minute*60 + second;
}

int DateTime::DateToInt()
{
	int d = 0;
	d += year * 10000;
	d += month * 100;
	d += day;
	return d;
}
int DateTime::TimeToInt()
{
	int t = 0;
	t += hour * 10000;
	t += minute * 100;
	t += second;
	return t;
}

DateTime DateTime::IntToDate(int dateInt)
{
	if (dateInt < 0)
		throw Exception();
	int y = dateInt / 10000;
	int m = (dateInt % 10000) / 100;
	int d = dateInt % 100;

	return DateTime(y, m, d);
}
DateTime DateTime::IntToTime(int timeInt)
{
	if (timeInt < 0)
		throw Exception();
	int h = timeInt / 10000;
	int m = (timeInt % 10000) / 100;
	int s = timeInt % 100;

	return DateTime(1970, 1, 1, h, m, s);
}

DateTime DateTime::SetIntToDateTime(int dateInt, int timeInt)
{
	if (dateInt < 0)
		throw Exception();
	int year = dateInt / 10000;
	int month = (dateInt % 10000) / 100;
	int day = dateInt % 100;

	if (timeInt < 0)
		throw Exception();
	int h = timeInt / 10000;
	int m = (timeInt % 10000) / 100;
	int s = timeInt % 100;

	return DateTime(year, month, day, h, m, s);
}

DateTimeReversedOutput ReversedOutput(const DateTime& dt)
{
	return { dt };
}

ostream& operator << (ostream& out, const DateTimeReversedOutput& r)
{
	out << setfill('0') << setw(2) << r.dt.getDay() << "-" << setfill('0') << setw(2) << r.dt.getMonth() << "-" << r.dt.getYear();
	return out;
}

DateTimeReversedInput ReversedInput(DateTime& dt)
{
	return { dt };
}

istream& operator >> (istream& in, const DateTimeReversedInput& r)
{
	int d, m, y;
	char c1, c2;

	if (!(in >> d >> c1 >> m >> c2 >> y))
		throw Exception();

	if (c1 != '-' && c1 != '.' || c2 != '-' && c2 != '.')
		throw Exception();

	r.dt = DateTime(y, m, d);
	return in;
}

DateTimeOnlyTime Time(const DateTime& dt)
{
	return { dt };
}

ostream& operator << (ostream& out, const DateTimeOnlyTime& t) {
	out << setfill('0') << setw(2) << t.dt.getHour() << ":"<< setfill('0') << setw(2) << t.dt.getMinute() << ":" << setfill('0') << setw(2) << t.dt.getSecond();
	return out;
}
