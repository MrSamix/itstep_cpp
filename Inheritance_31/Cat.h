#pragma once
#include "Pet.h"
class Cat :
    public Pet
{
public:
    Cat(const string& name, const size_t& age, const string& food = "Fish")
        :Pet(name, age), food(food)
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
    string type = "Cat";
};

