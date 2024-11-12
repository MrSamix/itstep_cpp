#include "Remote.h"

Remote::Remote(TV* tv) : tv(tv) {}

void Remote::chooseTV(TV* tv) {
    this->tv = tv;
}

void Remote::power() {
    if (tv) {
        tv->power();
    }
}

void Remote::operator++() {
    if (tv) {
        tv->nextChannel();
    }
}

void Remote::operator--() {
    if (tv) {
        tv->prevChannel();
    }
}

void Remote::operator+() const {
    if (tv) {
        tv->incVolume();
    }
}

void Remote::operator-() const {
    if (tv) {
        tv->decVolume();
    }
}