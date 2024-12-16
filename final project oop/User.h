#pragma once
#include "Connections.h"
#include "Date.h"

class User
{
public:
	User(const char* surname, const char* name, Date birthdayDate, const char* group)
		:birthdayDate(birthdayDate)
	{
		this->id = last_id++;
		this->surname = new char[SIZE];
		this->name = new char[SIZE];
		this->group = new char[SIZE];

		strcpy_s(this->surname, SIZE, surname);
		strcpy_s(this->name, SIZE, name);
		strcpy_s(this->group, SIZE, group);
	}
	User(int id, const char* surname, const char* name, Date birthdayDate, const char* group)
		:birthdayDate(birthdayDate), id(id)
	{
		this->surname = new char[SIZE];
		this->name = new char[SIZE];
		this->group = new char[SIZE];

		strcpy_s(this->surname, SIZE, surname);
		strcpy_s(this->name, SIZE, name);
		strcpy_s(this->group, SIZE, group);
	}
	User() : birthdayDate(1, 1, 2001)
	{
		this->surname = new char[SIZE] {};
		this->name = new char[SIZE] {};
		this->group = new char[SIZE] {};
	}

	~User()
	{
		delete[] surname;
		delete[] name;
		delete[] group;
	}

	User(const User& other) // copy ctor
		:birthdayDate(other.birthdayDate), id(other.id)
	{
		this->surname = new char[SIZE];
		this->name = new char[SIZE];
		this->group = new char[SIZE];

		strcpy_s(this->surname, SIZE, other.surname);
		strcpy_s(this->name, SIZE, other.name);
		strcpy_s(this->group, SIZE, other.group);
	}

	User& operator=(const User& other)
	{
		if (this == &other)
			return *this;

		delete[] surname;
		delete[] name;
		delete[] group;

		this->surname = new char[SIZE];
		this->name = new char[SIZE];
		this->group = new char[SIZE];

		strcpy_s(this->surname, SIZE, other.surname);
		strcpy_s(this->name, SIZE, other.name);
		strcpy_s(this->group, SIZE, other.group);

		birthdayDate = other.birthdayDate;

		return *this;
	}

    

	void print() const
	{
		cout << "User #" << id << endl;
		cout << "Surname: " << surname << endl;
		cout << "Name: " << name << endl;
		cout << "Birthday date: "; birthdayDate.print();
		cout << "Group: " << group << endl;
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
		//char newGroup[SIZE];
		cout << "\nEnter new surname(enter -1 if you don't change): "; cin >> newSurname;
		cout << "\nEnter new name(enter -1 if you don't change): "; cin >> newName;
		//cout << "\nEnter new group(enter -1 if you don't change): "; cin >> newGroup;

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
		//if (strcmp(newGroup, "-1"))
		//{
		//	delete[] group;
		//	group = new char[SIZE];
		//	strcpy_s(group, SIZE, newGroup);
		//}

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


	// saving and importing from file

	friend ostream& operator<<(std::ostream& os, const User& user)
	{
		os << user.id << ' ' << user.surname << ' ' << user.name << ' ' << user.birthdayDate.day << ' ' << user.birthdayDate.month << ' ' << user.birthdayDate.year << ' ' << user.group;
		return os;
	}
	friend istream& operator>>(std::istream& is, User& user)
	{
		int id;
		char surname[SIZE];
		char name[SIZE];
		int day, month, year;
		char group[SIZE];

		is >> id >> surname >> name >> day >> month >> year >> group;

		user.id = id;
		delete[] user.surname;
		delete[] user.name;
		delete[] user.group;
		user.surname = new char[SIZE];
		user.name = new char[SIZE];
		user.group = new char[SIZE];
		strcpy_s(user.surname, SIZE, surname);
		strcpy_s(user.name, SIZE, name);
		user.birthdayDate = Date(day, month, year);
		strcpy_s(user.group, SIZE, group);

		return is;
	}


private:
	//const int id = last_id++;
	int id;
	static int last_id;
	char* surname = nullptr;
	char* name = nullptr;
	Date birthdayDate;
	char* group = nullptr;
};

//int User::last_id = 0;

