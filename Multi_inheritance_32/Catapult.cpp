#include "Connections.h"
#include "Library.h"

Catapult::Catapult(const std::string& name, int count) : Shooter(name, count) {}

void Catapult::shot() {
    if (ammunitionCount > 0) {
        cout << "Catapult fired a stone using " << ammunitionName << "." <<endl;
        --ammunitionCount;
    }
    else {
        cout << "No stones left to fire!" <<endl;
    }
}
