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

	void printUsers() const;
	void printLessons() const;
	void printMarks() const;
	
	void printInfo();


	void saveUsers(string pthfileUsers);
	void saveMarks(string pthfileMarks);
	void saveLessons(string pthfileLessons);
	
	bool isValidPth(string pthFile);

	void countAvg();
	void countAvg(int user_id, int lesson_id);

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

