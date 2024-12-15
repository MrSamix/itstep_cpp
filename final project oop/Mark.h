#pragma once
#include "Connections.h"
#include "Date.h"
class Mark
{
public:
	Mark(int user_id, int lesson_id, Date date, bool absent = false, int mark = -1)
		:date(date), user_id(user_id), lesson_id(lesson_id)
	{
		id = last_id++;
		if (absent == true)
		{
			this->absent = true;
		}
		else
		{
			validation(mark);
		}
	}
	Mark(int id, int user_id, int lesson_id, Date date, bool absent = false, int mark = -1)
		:date(date), user_id(user_id), lesson_id(lesson_id), id(id)
	{
		if (absent == true)
		{
			this->absent = true;
		}
		else
		{
			validation(mark);
		}
	}
	Mark()
		:date(1, 1, 2001)
	{}
	/*void input()*/
	void print() const
	{
		cout << "Mark #" << id << endl;
		cout << "User: " << user_id << endl;
		//cout << "Lesson: " << lesson_id << endl;
		cout << "Date: "; date.print();
		absent == true ? cout << "Mark: " << "Absent" << endl : cout << "Mark: " << mark << endl;
	}

	int getIDMark() const
	{
		return id;
	}

	int getIDLesson() const
	{
		return lesson_id;
	}

	int getIDUser() const
	{
		return user_id;
	}

	bool isAbsent() const
	{
		return absent;
	}

	int getMark() const
	{
		return mark;
	}


	friend ostream& operator<<(std::ostream& os, const Mark& mark)
	{
		os << mark.id << ' ' << mark.user_id << ' ' << mark.lesson_id << ' ' << mark.date.day << ' ' << mark.date.month << ' ' << mark.date.year << ' ' << mark.absent << ' ' << mark.mark;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Mark& mark)
	{
		int id;
		int user_id;
		int lesson_id;
		int day, month, year;
		bool absent;
		int mark_value;

		is >> id >> user_id >> lesson_id >> day >> month >> year >> absent >> mark_value;

		mark.id = id;
		mark.user_id = user_id;
		mark.lesson_id = lesson_id;
		mark.date = Date(day, month, year);
		mark.absent = absent;
		mark.mark = mark_value;

		return is;
	}

	void edit()
	{
		cout << "Editing mark #" << id << endl;
		cout << "Current: " << endl;
		print();
		int newMark;
		cout << "\nEnter new mark(enter -1 if you enter absent mark): "; cin >> newMark;
		if (newMark == -1)
		{
			absent = true;
		}
		else
		{
			if (absent == true)
			{
				absent = false;
			}
			validation(newMark);
		}
		char choice;
		cout << "Do you have to change date?(y/n): "; cin >> choice;
		switch (choice)
		{
		case 'y':
		{
			date.edit();
		}
		case 'n':
		{
			break;
		}
		default:
			throw invalid_argument("Incorrect choice");
			break;
		}

		cout << "Edited: " << endl;
		print();
	}
private:
	int id;
	static int last_id;
	int mark;
	bool absent = false;
	int user_id;
	int lesson_id;
	Date date;

	void validation(int mark)
	{
		if (mark > 0 && mark <= 12)
		{
			this->mark = mark;
		}
		else
		{
			throw invalid_argument("Invalid mark");
		}
	}
};

//int Mark::last_id = 0;