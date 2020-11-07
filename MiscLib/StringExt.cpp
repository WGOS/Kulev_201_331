#include "pch.h"
#include "StringExt.h"
#include <iostream>

namespace Misc
{
    namespace Str
    {
        size_t Split(const std::string& str, const char delimiter, std::string*& subStrings)
        {
            std::cout << "keeek\n";
            size_t delimOcc = std::count(str.begin(), str.end(), delimiter);
            if (delimOcc <= 0)
                return 0;

            subStrings = new std::string[delimOcc + 1];

            for (size_t pos = 0, nPos, i = 0; i <= delimOcc; i++, pos = nPos + 1)
            {
                nPos = str.find(delimiter, pos);
                subStrings[i] = str.substr(pos, nPos - pos);
            }

            return delimOcc + 1;
        }

        std::string Join(const std::string* subStrings, const size_t size, const char delimiter)
        {
            if (size <= 0)
                return "";

            std::string jStr = subStrings[0];

            for (size_t i = 1; i < size; i++)
            {
                if (delimiter != NULL)
                    jStr += delimiter;

                jStr += subStrings[i];
            }

            return jStr;
        }
    }
}
