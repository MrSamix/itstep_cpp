#pragma once
#include "ArcherTower.h"
#include "Catapult.h"

class Fortress {
private:
    ArcherTower tower;
    Catapult catapult;
    int wallThickness;
    int gateCondition; 

public:
    Fortress(int arrows, int stones, int wallThickness, int gateCondition);
    void defend();
};

