#include <iostream>
#include <Interface.h>
#include <windows.h>
#include "WorkingPath.h"
#include "ErrorTraits.h"

int main(int argc, char** argv)
{
    std::string workingDirectory = getParentDirectory(argv[0]);

    std::string libPath = workingDirectory + "\\Lib.dll";

    HINSTANCE hGetProcIDDLL = LoadLibrary(libPath.c_str());  // Returns a handler to a loaded module (a library)

    if (!hGetProcIDDLL)
    {
        std::cout << "Could not load the dynamic library\n";
        getErrorStr("Loading the dynamic");
        return EXIT_FAILURE;
    };

    typedef Interface*(*Prototype_GetInterface)();
    Prototype_GetInterface f_getInterface = (Prototype_GetInterface)GetProcAddress(hGetProcIDDLL, "getInterface");

    if (!f_getInterface)
    {
        std::cout << "Could not resolve the symbol \"getInterface\" under the DLL\n";
        getErrorStr("Resolve getInterface");
        return EXIT_FAILURE;
    }

    Interface* instance = f_getInterface();
    instance->printFunction();
}