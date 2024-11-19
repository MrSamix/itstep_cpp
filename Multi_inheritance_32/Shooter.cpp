#include "Connections.h"
#include "Library.h"

Shooter::Shooter(const string& name, int count)
    : ammunitionName(name), ammunitionCount(count) {}

Shooter::~Shooter() {}

void Shooter::shot() {
    if (ammunitionCount > 0) {
        cout << "Shooter fired using " << ammunitionName << "." << endl;
        --ammunitionCount;
    }
    else {
        cout << "No ammunition left to fire!" <<endl;
    }
}

void Shooter::loadAmmunition(const string& name, int count) {
    ammunitionName = name;
    ammunitionCount = count;
}
