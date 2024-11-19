#pragma once
#include "Shooter.h"

class Archer : public Shooter {
public:
    Archer(const string& name = "Arrows", int count = 0);
    void shot() override;
};
