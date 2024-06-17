#pragma once
#include "../Interface.h"

class Impl: public Interface
{
    public:
        virtual void printFunction() override;
        
};

IMPL(Interface, Impl);