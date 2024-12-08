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
		for (auto& i : users)
		{
			i.print();
		}
	}

	void printLessons() const
	{
		for (auto& i : lessons)
		{
			i.print();
		}
	}

private:
	vector<User> users;
	vector<Lesson> lessons;
	vector<Mark> marks;
	char* group = nullptr;
	// string filename's
};

