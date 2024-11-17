#pragma once
#include "Lib.h"
class Pet
{
public:
	Pet(const string& name = "None", const size_t& age = 0)
		:name(name), age(age)
	{}
	void print() const
	{
		cout << "Pet print: " << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
	void eat() const
	{
		cout << name << " has eat some food" << endl;
	}
protected:
	string name;
	size_t age;
};

