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
		cout << typeid(*this).name() << " " << name << " is sleeping." << endl;
	}
protected:
	string name;
};

