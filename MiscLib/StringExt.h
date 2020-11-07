#pragma once

#include <string>

namespace MiscLib
{
	class StringExt
	{
	public:
		/// <summary>
		/// Split strings to array of substrings by delimiter
		/// </summary>
		/// <param name="str">String to split</param>
		/// <param name="delimiter">Delimiter to split string by</param>
		/// <param name="subStrings">Pointer address of sub-strings array</param>
		/// <returns>Size of sub-strings array</returns>
		size_t split(const std::string& str, const char delimiter, std::string*& subStrings);
	};
}


