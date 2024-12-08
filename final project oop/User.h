#pragma once
#include "Connections.h"
#include "Date.h"

class User
{
public:
	User(const char* surname, const char* name, Date birthdayDate, const char* group)
		:birthdayDate(birthdayDate)
	{
		this->surname = new char[SIZE];
		this->name = new char[SIZE];
		this->group = new char[SIZE];

		strcpy_s(this->surname, SIZE, surname);
		strcpy_s(this->name, SIZE, name);
		strcpy_s(this->group, SIZE, group);
	}
	~User()
	{
		delete[] surname;
		delete[] name;
		delete[] group;
	}
	void print() const
	{
		cout << "User #" << id << endl;
		cout << "Surname: " << surname << endl;
		cout << "Name: " << name << endl;
		cout << "Birthday date: "; birthdayDate.print();
		cout << "Group: " << group << endl;
	}

    User(const User& other)
		:birthdayDate(other.birthdayDate)
    {
		this->surname = new char[SIZE];
		this->name = new char[SIZE];
		this->group = new char[SIZE];

		strcpy_s(this->surname, SIZE, other.surname);
		strcpy_s(this->name, SIZE, other.name);
		strcpy_s(this->group, SIZE, other.group);
    }


	int getIDUser() // geter
	{
		return id;
	}
	void edit()
	{
		cout << "Edititng User #" << id << endl;
		print();
		char newSurname[SIZE];
		char newName[SIZE];
		char newGroup[SIZE];
		cout << "\nEnter new surname(enter -1 if you don't change): "; cin >> newSurname;
		cout << "\nEnter new name(enter -1 if you don't change): "; cin >> newName;
		cout << "\nEnter new group(enter -1 if you don't change): "; cin >> newGroup;

		if (strcmp(newSurname, "-1"))
		{
			delete[] surname;
			surname = new char[SIZE];
			strcpy_s(surname, SIZE, newSurname);
		}
		if (strcmp(newName, "-1"))
		{
			delete[] name;
			name = new char[SIZE];
			strcpy_s(name, SIZE, newName);
		}
		if (strcmp(newGroup, "-1"))
		{
			delete[] group;
			group = new char[SIZE];
			strcpy_s(group, SIZE, newGroup);
		}

		char choice;
		cout << "Do you have to change date?(y/n): "; cin >> choice;
		switch (choice)
		{
		case 'y':
		{
			birthdayDate.edit();
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
	const int id = last_id++;
	static int last_id;
	char* surname = nullptr;
	char* name = nullptr;
	Date birthdayDate;
	char* group = nullptr;
};

//int User::last_id = 0;

