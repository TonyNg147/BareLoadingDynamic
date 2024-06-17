#pragma once
#include <string>
#include <algorithm>
inline std::string getParentDirectory(const char* path)
{
    std::string currentPath{path};
    std::size_t lastIndexOfSeparator = currentPath.find_last_of("\\");
    std::string fileName = currentPath.substr(lastIndexOfSeparator+1);
    std::string folder = currentPath.substr(0, lastIndexOfSeparator);
    return folder;
}