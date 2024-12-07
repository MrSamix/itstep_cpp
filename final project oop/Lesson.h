#pragma once
#include "Connections.h"
#include "Date.h"

class Lesson
{
public:
	Lesson(const char* name, const char* group, Date date)
		:date(date)
	{
		this->name = new char[SIZE];
		this->group = new char[SIZE];

		/*strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->group, strlen(group) + 1, group);*/

		strcpy_s(this->name, SIZE, name);
		strcpy_s(this->group, SIZE, group);
	}
	~Lesson()
	{
		delete[] name;
		delete[] group;
	}
	void print() const
	{
		cout << "Lesson #" << id << endl;
		cout << "Name: " << name << endl;
		cout << "Group: " << group << endl;
		cout << "Date: "; date.print();
	}
	void edit()
	{
		cout << "Editing lesson #" << id << endl;
		cout << "Current: " << endl;
		print();
		char newName[SIZE]{};
		char newGroup[SIZE]{};
		cout << "\nEnter new name(enter -1 if you don't change): " << endl;
		cin >> newName;
		cout << "\nEnter new group(enter -1 if you don't change): " << endl;
		cin >> newGroup;
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
		if (strcmp(newName, "-1"))
		{
			delete[] name;
			name = new char[SIZE];
			//strcpy_s(this->name, strlen(newName) + 1, newName);
			strcpy_s(this->name, SIZE, newName);
		}
		if (strcmp(newGroup, "-1"))
		{
			delete[] group;
			group = new char[SIZE];
			//strcpy_s(this->group, strlen(newGroup) + 1, newGroup);
			strcpy_s(this->group, SIZE, newGroup);
		}

		cout << "Edited: " << endl;
		print();
	}
private:
	const int id = last_id++;
	static int last_id;
	char* name = nullptr;
	char* group = nullptr;
	Date date;
};


int Lesson::last_id = 0;