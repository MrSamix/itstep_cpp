#include "Connections.h"
#include "Library.h"

Range::Range(const string& name, int count) : Shooter(name, count) {}

void Range::shot() {
    if (ammunitionCount > 0) {
        cout << "Range fired an arrow using " << ammunitionName << "." << endl;
        --ammunitionCount;
    }
    else {
        cout << "No arrows left to fire!" <<endl;
    }
}
