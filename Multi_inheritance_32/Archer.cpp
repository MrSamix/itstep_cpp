#include "Connections.h"
#include "Library.h"

Archer::Archer(const string& name, int count) : Shooter(name, count) {}

void Archer::shot() {
    if (ammunitionCount > 0) {
        cout << "Archer fired an arrow using " << ammunitionName << "." <<endl;
        --ammunitionCount;
    }
    else {
        cout << "No arrows left to fire!" << endl;
    }
}
