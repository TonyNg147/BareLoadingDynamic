#pragma once
#include <windows.h>
#include <string.h>
#include <stdio.h>
static void getErrorStr(const char* action)
{
    LPTSTR errText = nullptr;
    DWORD errCode = GetLastError();
    int errorQueryStatus = FormatMessage(
        // use system message tables to retrieve error text
        FORMAT_MESSAGE_FROM_SYSTEM
           // allocate buffer on local heap for error text
        |FORMAT_MESSAGE_ALLOCATE_BUFFER
        // Important! will fail otherwise, since we're not 
        // (and CANNOT) pass insertion parameters
        |FORMAT_MESSAGE_IGNORE_INSERTS,  // unused with FORMAT_MESSAGE_FROM_SYSTEM
        NULL,
        errCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&errText,  //output
        0, //minimum size for the output buffer
        NULL); // argument

    if (errorQueryStatus)                                                                                                                                                                                
    {
        static char buffer[1024];

        snprintf(buffer, sizeof(buffer), "Error when doing %s is %s", action, errText);

        fprintf(stderr, "%s\n", buffer);

        LocalFree(errText);
    }
    else
    {
        fprintf(stderr, "Cannot get the error status\n");
    }

}