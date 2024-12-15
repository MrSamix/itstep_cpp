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
	//void menu();


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

	void printMarks() const
	{
		if (marks.size() == 0)
		{
			cout << "List of marks is empty!" << endl;
			return;
		}
		for (auto& i : marks)
		{
			bool Flag = false;
			i.print();
			for (auto& j : lessons)
			{
				if (j.getIDLesson() == i.getIDLesson())
				{
					cout << "Lesson: " << j.getLesson() << endl;
					Flag = true;
					break;
				}
			}
			if (!Flag)
			{
				cout << "Lesson: " << i.getIDLesson() << endl;
			}
		}
	}

	void saveUsers(string pthfileUsers);
	void saveMarks(string pthfileMarks);
	void saveLessons(string pthfileLessons);
	void printInfo();

private:
	vector<User> users;
	vector<Lesson> lessons;
	vector<Mark> marks;
	char* group = nullptr;
	static int lastIdUser;
	static int lastIdLesson;
	static int lastIdMark;
	// string filename's
};

