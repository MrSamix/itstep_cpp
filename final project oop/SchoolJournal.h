#pragma once
#include "Date.h"
#include "User.h"
#include "Lesson.h"
#include "Mark.h"
#include "Connections.h"

class SchoolJournal
{
public:
	SchoolJournal(const char* group)
	{
		this->group = new char[SIZE];
		strcpy_s(this->group, SIZE, group);
	}
	void menu();


	void printUsers() const
	{
		if (users.size() == 0)
		{
			cout << "List of users is empty!" << endl;
			return;
		}
		for (auto& i : users)
		{
			i.print();
		}
	}

	void printLessons() const
	{
		if (lessons.size() == 0)
		{
			cout << "List of lessons is empty!" << endl;
			return;
		}
		for (auto& i : lessons)
		{
			i.print();
		}
	}

	void saveUsers(string pthfileUsers);

private:
	vector<User> users;
	vector<Lesson> lessons;
	vector<Mark> marks;
	char* group = nullptr;
	// string filename's
};

