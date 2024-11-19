#pragma once
#include "Shooter.h"

class Range : public Shooter {
public:
    Range(const string& name = "Arrows", int count = 0);
    void shot() override;
};
