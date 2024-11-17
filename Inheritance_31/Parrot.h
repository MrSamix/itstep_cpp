#pragma once
#include "Pet.h"
class Parrot :
    public Pet
{
public:
    Parrot(const string& name, const size_t& age, const string& food = "Carrot")
        :Pet(name,age), food(food)
    {}
    void print() const
    {
        cout << type << " print: " << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Food: " << food << endl;
        cout << "Type: " << type << endl;
    }
    void eat() const
    {
        cout << name << " has eat " << food << endl;
    }
protected:
    string food;
    string type = "Parrot";
};

