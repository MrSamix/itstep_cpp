#pragma once
#include "Archer.h"
#include "Range.h"

class ArcherTower : public Archer, public Range {
public:
    ArcherTower(const string& name = "Arrows", int count = 0);
    void shotFromArcher();
    void shotFromRange();
};



