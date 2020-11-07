#include "pch.h"
#include "StringExt.h"
#include <iostream>

namespace Misc
{
    size_t StrExt::Split(const std::string& str, const char delimiter, std::string*& subStrings)
    {
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

    std::string StrExt::Join(const std::string* subStrings, const size_t size, const char delimiter)
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

    bool StrExt::Replace(std::string& str, const std::string search, const std::string to, const bool fromLast)
    {
        size_t pos = fromLast ? str.rfind(search) : str.find(search);

        if (pos == std::string::npos)
            return false;

        str.replace(pos, search.length(), to);
        return true;
    }

    size_t StrExt::ReplaceAll(std::string& str, const std::string subString, const std::string to)
    {
        size_t occs = 0;

        while (StrExt::Replace(str, subString, to))
            occs++;

        return occs;
    }
}
