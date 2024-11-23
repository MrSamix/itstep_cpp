#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    size_t age;

public:
    Animal(const string& name, size_t age) : name(name), age(age) {}
    virtual ~Animal() {}

    virtual void sound() const = 0;
    virtual void type() const = 0;
    virtual void show() const = 0;

    const string& getName() const { return name; }
    size_t getAge() const { return age; }
    void setName(const string& newName) { name = newName; }
    void setAge(size_t newAge) { age = newAge; }
};
