#pragma once
#include <iostream>
using namespace std;
class Grandpa
{
public:
	Grandpa(const string& name)
		:name(name)
	{}
	virtual void Sleep() const
	{
		cout << name << " is sleeping.";
	}
protected:
	string name;
};

