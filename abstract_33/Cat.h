#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
    Cat(const string& name, size_t age) : Animal(name, age) {}
    void sound() const override {
        cout << name << " says: Meow!" << endl;
    }
    void type() const override {
        cout << "Type: Cat" << endl;
    }
    void show() const override {
        cout << "Name: " << name << ", Age: " << age << endl;
        type();
        sound();
    }
};
