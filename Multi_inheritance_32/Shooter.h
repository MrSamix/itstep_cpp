#pragma once
#include "Library.h"
class Shooter {
protected:
    string ammunitionName;
    int ammunitionCount;

public:
    Shooter(const string& name = "", int count = 0);
    virtual ~Shooter();
    virtual void shot();  
    void loadAmmunition(const string& name, int count);  
};
