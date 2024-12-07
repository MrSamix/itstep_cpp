#pragma once
#include "Date.h"
#include "User.h"
#include "Lesson.h"
#include "Mark.h"
#include "Connections.h"

class SchoolJournal
{
public:
	SchoolJournal()
private:
	vector<User> users;
	vector<Lesson> lessons;
	vector<Mark> marks;
	char* group = nullptr;
};

