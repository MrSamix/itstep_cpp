#pragma once
#include "Grandpa.h"
class Daddy :
    public Grandpa
{
    Daddy(const string& name)
        :Grandpa(name)
    {}
    virtual void Walk() const
    {
        cout << name << " is walking.";
    }
};

