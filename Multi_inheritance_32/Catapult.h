#pragma once
#include "Shooter.h"

class Catapult : public Shooter {
public:
    Catapult(const string& name = "Stones", int count = 0);
    void shot() override;
};
