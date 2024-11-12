#pragma once
#include "TV.h"

class Remote {
    TV* tv;

public:

    Remote(TV* tv = nullptr);

    void chooseTV(TV* tv);
    void power();

    void operator++();
    void operator--();
    void operator+() const;
    void operator-() const;
};
