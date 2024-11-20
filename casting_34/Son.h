#pragma once
#include "Daddy.h"
class Son :
    public Daddy
{
public:
    Son(const string& name)
        :Daddy(name)
    {}
    virtual void Play() const
    {
        cout << typeid(*this).name() << " " << name << " is playing." << endl;
    }
};

