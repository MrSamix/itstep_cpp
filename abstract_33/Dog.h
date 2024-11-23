#pragma once
#include "Animal.h"

class Dog : public Animal {
public:
    Dog(const string& name, size_t age) : Animal(name, age) {}
    void sound() const override {
        cout << name << " says: Gav!" << endl;
    }
    void type() const override {
        cout << "Type: Dog" << endl;
    }
    void show() const override {
        cout << "Name: " << name << ", Age: " << age << endl;
        type();
        sound();
    }
};
