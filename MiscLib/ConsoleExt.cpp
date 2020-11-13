#include "pch.h"
#include "ConsoleExt.h"
#include <iostream>

namespace Misc
{
    std::string Console::ReadLine()
    {
        std::string str;
        std::getline(std::cin, str);

        return str;
    }
}