#include <iostream>
#include "Cat.h"
#include "Pet.h"
#include "Parrot.h"
#include "Dog.h"

using namespace std;


int main()
{
    Pet pet("Vasya", 15);
    pet.print();
    pet.eat();

    cout << "\n\n";

    Dog dog("Petya", 12);
    dog.print();
    dog.eat();

    cout << "\n\n";

    Cat cat("Stepan", 10);
    cat.print();
    cat.eat();

    cout << "\n\n";

    Parrot parrot("Gosha", 5);
    parrot.print();
    parrot.eat();
}