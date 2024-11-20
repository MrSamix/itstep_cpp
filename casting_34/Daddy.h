#pragma once
#include "Grandpa.h"
class Daddy :
    public Grandpa
{
public:
    Daddy(const string& name)
        :Grandpa(name)
    {}
    virtual void Walk() const
    {
        cout << typeid(*this).name() << " " << name << " is walking." << endl;
    }
};

