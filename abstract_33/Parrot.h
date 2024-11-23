#pragma once
#include "Animal.h"

class Parrot : public Animal {
public:
    Parrot(const string& name, size_t age) : Animal(name, age) {}
    void sound() const override {
        cout << name << " says: Kykareky!" << endl;
    }
    void type() const override {
        cout << "Type: Parrot" << endl;
    }
    void show() const override {
        cout << "Name: " << name << ", Age: " << age << endl;
        type();
        sound();
    }
};
