#include "Connections.h"
#include "Library.h"

Fortress::Fortress(int arrows, int stones, int wallThickness, int gateCondition)
    : tower("Arrows", arrows), catapult("Stones", stones),
    wallThickness(wallThickness), gateCondition(gateCondition) {}

void Fortress::defend() {
    cout << "Defending the fortress!" <<endl;
    for (int i = 0; i < 3; i++)
    {
        tower.shotFromArcher();
    }
    for (int i = 0; i < 2; i++)
    {
        tower.shotFromRange();
    }
    catapult.shot();
}
