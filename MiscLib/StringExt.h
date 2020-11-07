#pragma once
#include <string>

namespace Misc
{
	namespace Str
	{
		/// <summary>
		/// Split strings to substrings by delimiter
		/// </summary>
		/// <param name="str">String to split</param>
		/// <param name="delimiter">Delimiter to split string by</param>
		/// <param name="subStrings">Pointer address of sub-strings array</param>
		/// <returns>Size of sub-strings array</returns>
		size_t Split(const std::string& str, const char delimiter, std::string*& subStrings);

		/// <summary>
		/// Join substrings into one string
		/// </summary>
		/// <param name="subStrings">Array of substrings to join</param>
		/// <param name="size">Size of array of substrings</param>
		/// <param name="delimiter">Delimiter between substrings</param>
		/// <returns>Joined string</returns>
		std::string Join(const std::string* subStrings, const size_t size, const char delimiter);
	}
}
