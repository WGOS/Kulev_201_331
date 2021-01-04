#pragma once
#include <string>

namespace Misc
{
	class StrExt
	{
	public:
		/// <summary>
		/// Split strings to substrings by delimiter
		/// </summary>
		/// <param name="str">String to split</param>
		/// <param name="delimiter">Delimiter to split string by</param>
		/// <param name="subStrings">Pointer address of sub-strings array</param>
		/// <returns>Size of sub-strings array</returns>
		static size_t Split(const std::string& str, const char delimiter, std::string*& subStrings);

		/// <summary>
		/// Join substrings into one string
		/// </summary>
		/// <param name="subStrings">Array of substrings to join</param>
		/// <param name="size">Size of array of substrings</param>
		/// <param name="delimiter">Delimiter between substrings</param>
		/// <returns>Joined string</returns>
		static std::string Join(const std::string* subStrings, const size_t size, const char delimiter);

		/// <summary>
		/// Replace first occurrence of substring to another string
		/// </summary>
		/// <param name="str">String to replace in</param>
		/// <param name="subString">Substring to replace</param>
		/// <param name="to">Replacement string</param>
		/// <param name="fromLast">Replace last occurrence</param>
		/// <returns>Has substring been replaced</returns>
		static bool Replace(std::string& str, const std::string subString, const std::string to, const bool fromLast = false);

		/// <summary>
		/// Replace all occurrences of substring to another string
		/// </summary>
		/// <param name="str">String to replace in</param>
		/// <param name="subString">Substring to replace</param>
		/// <param name="to">Replacement string</param>
		/// <returns>Amount of substring occurrences</returns>
		static size_t ReplaceAll(std::string& str, const std::string subString, const std::string to);

		/// <summary>
		/// Turn string to lower case
		/// </summary>
		/// <param name="str">Input string</param>
		static void ToLower(std::string& str);
	};
}
