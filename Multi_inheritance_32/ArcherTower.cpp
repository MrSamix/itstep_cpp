#include "Connections.h"
#include "Library.h"

ArcherTower::ArcherTower(const string& name, int count)
    : Archer(name, count), Range(name, count) {}

void ArcherTower::shotFromArcher() {
    Archer::shot();
}

void ArcherTower::shotFromRange() {
    Range::shot();
}
