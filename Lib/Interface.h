#pragma once

class Interface
{
    public:
        virtual void printFunction() = 0;
};

#ifdef DEFINE_LIB 
    #define LIBRARY_EXPORTS __declspec(dllexport)
#else
    #define LIBRARY_EXPORTS __declspec(dllimport)
#endif

#define IMPL(IF, IMPL) \
extern "C" LIBRARY_EXPORTS IF* getInterface(){ return new IMPL;}

