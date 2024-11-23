#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"
#include "Zoo.h"

using namespace std;

int main()
{
    Zoo zoo;

    zoo.addAnimal(new Cat("Barsik", 5));
    zoo.addAnimal(new Dog("Stepan", 2));
    zoo.addAnimal(new Parrot("Gosha", 1));

    cout << "\nAnimals in the zoo:" << endl;
    zoo.showAnimals();

    zoo.editAnimal(1, "Max", 4);

    cout << "\nEdited the second animal:" << endl;
    zoo.showAnimals();


    zoo.removeAnimal(2);

    cout << "\nRemove the animal of index 2:" << endl << endl;
    zoo.showAnimals();


    zoo.clearZoo();
    cout << "\nMain: Zoo cleared." << endl;
}