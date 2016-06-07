#pragma once

#include<iostream>
using namespace std;

int m2 = 0;
int d[] = { 31, m2, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date
{
public:
	Date(int year = 1995, int month = 9, int day = 14)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date &d)
	{
		_year = this->_year;
		_month = this->_month;
		_day = this->_day;
	}

	int check_m2()
	{
		bool  flag = true;
		flag = Isleapyear(this->_year);
		if (flag == true)
		{
			m2 = 29;
		}
		else
			m2 = 28;
		return m2;
	}

	Date& operator+(int days)
	{
		int yy = this->_year, mm = this->_month, dd = this->_day;
		int dtmp = days;
		int mtmp = 0;
		bool  flag;
		flag = Isleapyear(this->_year);
		while (dtmp >= 0)
		{
			if (Isleapyear(yy))
			{
				dtmp = dtmp - 366;
				flag = true;
			}
			else
			{
				dtmp = dtmp - 365;
				flag = false;
			}
			yy++;
		}
		if (flag)
		{
			dtmp = dtmp + 366;
		}
		else
			dtmp = dtmp + 365;
		yy--;
		mtmp = dd + dtmp;
		m2 = check_m2();
		while (mtmp >= d[mm - 1])
		{
			if (mm == 11)
			{
				mm = 0;
				yy++;
			}
			mtmp = mtmp - d[mm - 1];
			mm++;
		}
		dd = mtmp;
		Date ret(yy, mm, dd);
		return ret;

	}
	Date& operator-(int days)
	{
		int yy = this->_year, mm = this->_month, dd = this->_day;
		int dtmp = days;
		int mtmp = 0;
		int count = 0;
		int i = 0;
		for (i = 0; i < mm; i++)
		{
			count = count + d[i];
		}
		count = count + dd;
		if (dtmp > count)
		{
			yy--;
		}
		while (dtmp < count)
		{
			mtmp = count - dtmp;
			if (mm == 1)
			{
				mm = 0;
				yy--;
			}
			mtmp = mtmp + d[mm - 1];
			mm++;
		}

		Date ret(yy, mm, dd);
		return ret;
	}
	Date& operator+(const Date &dx)
	{
		int yy, mm, dd;
		yy = this->_year + dx._year;
		int mtmp = 0;
		int dtmp = 0;
		mtmp = this->_month + dx._month;
		dtmp = this->_day + dx._day;
		while (mtmp >= 12)
		{
			yy++;
			mtmp = mtmp - 12;
		}
		mm = mtmp;
		while (dtmp > d[mtmp])
		{
			mm++;
			dtmp = dtmp - d[mtmp];
		}

		dd = dtmp;
		Date ret(yy, mm, dd);
		return ret;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool Isleapyear(int year)
	{
		if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))
			return true;
		else
			return false;
	}
private:
	int _year;
	int _month;
	int _day;
};



