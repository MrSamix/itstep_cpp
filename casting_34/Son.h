#pragma once
#include "Daddy.h"
class Son :
    public Daddy, public Grandpa
{
    Son(const string& name)
        :Grandpa(name)
    {}
};

