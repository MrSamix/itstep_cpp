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
	
	void printInfo() const;


	void saveUsers(string pthfileUsers);
	void saveMarks(string pthfileMarks);
	void saveLessons(string pthfileLessons);


	void importUsers(string pthfileUsers);
	void importMarks(string pthfileMarks);
	void importLessons(string pthfileLessons);
	
	
	bool isValidPth(string pthFile);

	void countAvg(int user_id, int lesson_id) const;

	void addUser();
	void editUser(int user_id);
	void deleteUser(int user_id);

	void addLesson();
	void editLesson(int lesson_id);
	void deleteLesson(int lesson_id);

	void newMark();
	void deleteMark(int mark_id);
	void editMark(int mark_id);

	void printMarks(int user_id, int lesson_id) const;

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

