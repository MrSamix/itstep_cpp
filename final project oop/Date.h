#pragma once
#include "Connections.h"
struct Date
{
	int day;
	int month;
	int year;
	Date(int day, int month, int year)
	{
		if (day > 0 && day <= 31 && month > 0 && month <= 12 && year > 0)
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else
		{
			throw invalid_argument("Invalid date");
		}
	}
	void print() const
	{
		cout << (day < 10 ? "0" : "") << day << "." << (month < 10 ? "0" : "") << month << "." << year << endl;
	}

	void edit()
	{
		int newDay, newMonth, newYear;
		cout << "Enter new date(Format: DD MM YYYY): "; cin >> newDay >> newMonth >> newYear;
		
		if (newDay > 0 && newDay <= 31 && newMonth > 0 && newMonth <= 12 && newYear > 0)
		{
			this->day = newDay;
			this->month = newMonth;
			this->year = newYear;
		}
		else
		{
			throw invalid_argument("Invalid date");
		}
	}
};