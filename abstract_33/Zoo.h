#pragma once
#include <vector>
#include <iostream>
#include "Animal.h"

using namespace std;

class Zoo {
private:
    vector<Animal*> zoo;

public:
    Zoo() = default;

    ~Zoo() {
        clearZoo();
    }

    void addAnimal(Animal* animal) {
        zoo.push_back(animal);
        cout << "Animal added to the zoo: " << animal->getName() << endl;
    }

    void showAnimals() const {
        if (zoo.empty()) {
            cout << "Zoo is empty!" << endl;
            return;
        }
        for (const auto& animal : zoo) {
            animal->show();
            cout << "-------------------" << endl;
        }
    }

    void editAnimal(size_t index, const string& newName, size_t newAge) {
        if (index >= zoo.size()) {
            cout << "Invalid index! No such animal in the zoo." << endl;
            return;
        }
        zoo[index]->setName(newName);
        zoo[index]->setAge(newAge);
        cout << "Animal at index " << index << " updated!" << endl;
    }

    void removeAnimal(size_t index) {
        if (index >= zoo.size()) {
            cout << "Invalid index! No such animal in the zoo." << endl;
            return;
        }
        delete zoo[index];
        zoo.erase(zoo.begin() + index);
        cout << "Animal at index " << index << " removed!" << endl;
    }

    void clearZoo() {
        for (auto animal : zoo) {
            delete animal;
        }
        zoo.clear();
        cout << "Func: Zoo cleared!" << endl;
    }
};
