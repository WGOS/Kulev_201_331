#include <iostream>
#include <cstring>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

#pragma region Prots
void drawMenu();
void wr(const char*, const bool = true);
void palindromeOption();
bool isPalindrome(const char*);
int findSubstring(const char*, const char*, const int);
int* findSubstring(const char*, const char*);
void subStringOption();
#pragma endregion


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    drawMenu();

	return 0;
}

#pragma region Others
void drawMenu()
{
    char inBuf[256];
    int menuPos = 0;

    while (true)
    {
        printf_s("=== Programm menu ===\n");
        printf_s("%d. Check if string is palindromic\n", ++menuPos);
        printf_s("%d. Substring\n", ++menuPos);
        printf_s("%d. Sort by summ of even digits\n", ++menuPos);
        printf_s("%d. Sort by last digit asc\n", ++menuPos);
        printf_s("%d. Exit\n", ++menuPos);
        printf_s("Choose one option: ");

        menuPos = 0;

        cin.getline(inBuf, 255);

        switch (atoi(inBuf))
        {
        case 1:
            palindromeOption();
            break;

        case 2:
            subStringOption();
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            printf_s("Exititng\n");
            return;

        default:
            printf_s("Unknown option\n");
            break;
        }
    }
}
#pragma endregion

#pragma region Task 1
/// <summary>
/// Entry fucntion for 1st palindrome task
/// </summary>
void palindromeOption()
{
    char input[256]; // 1 additional index is for terminator

    printf_s("Enter string to check (up to 255 symbols): ");
    cin.getline(input, 255);

    printf_s("String is %s%s\n", isPalindrome(input) ? "" : "not ", "palindromic");
}

/// <summary>
/// Check if string is palindromic
/// </summary>
/// <param name="str">String pointer</param>
/// <returns>Palindromic</returns>
bool isPalindrome(const char* str)
{
    int symbolCount = 0, currCharNum = 0, originalLen = strlen(str);
    char currChar;
    char* bareString = new char[originalLen] {0};

    for (int i = 0; i < originalLen; i++)
    {
        if (str[i] != ' ')
            bareString[symbolCount++] = tolower(str[i]);
    }
    
    int bareStringLen = strlen(bareString);

    for (int i = 0; i < (bareStringLen - 1) / 2; i++)
    {
        if (bareString[i] != bareString[bareStringLen - 1 - i])
        {
            delete[] bareString;
            return false;
        }
            
    }

    delete[] bareString;
    return true;
}
#pragma endregion

#pragma region Task 2
/// <summary>
/// Entry function for 2nd task
/// </summary>
void subStringOption()
{
    char buf[256] = { 0 };

    printf_s("Print string (up to 255 symbols): ");
    cin.getline(buf, 255);
    char* str = new char[strlen(buf)];
    std::copy(buf, buf + strlen(buf) + 1, str);

    printf_s("Print substring (up to 255 symbols): ");
    cin.getline(buf, 255);
    char* subStr = new char[strlen(buf)];
    std::copy(buf, buf + strlen(buf) + 1, subStr);

    printf_s("Print start position: ");
    cin.getline(buf, 255);
    int sPos = atoi(buf);

    int occ = findSubstring(str, subStr, sPos);
    if (occ == -1)
        printf_s("No occurence found!\n");
    else
        printf_s("Found occurrence at: %d\n", occ);

    printf_s("!! Finding all occurrences\n");
    int* occs = findSubstring(str, subStr);

    if (occs[0] != -1)
        for (int i = 0; occs[i] != -1; i++)
            printf_s("Occurrence #%d at %d\n", i + 1, occs[i]);
    else
        printf_s("No occurrences found\n");

    //delete[] str;
    //delete[] subStr;
}

/// <summary>
/// Finds substring position
/// </summary>
/// <param name="str">String to search in</param>
/// <param name="subStr">String to search</param>
/// <param name="startPos">Start search from index</param>
/// <returns>First occurance of substring or -1 if no occurance</returns>
int findSubstring(const char* str, const char* subStr, const int startPos)
{
    const char* occur = strstr(str + startPos, subStr);

    if (occur == nullptr)
        return -1;

    return occur - str;
}

/// <summary>
/// Finds all occurrences of substring in the string
/// </summary>
/// <param name="str">String to search in</param>
/// <param name="subStr">String to search</param>
/// <returns>Array of index of occurrences with -1 at the end as terminator</returns>
int* findSubstring(const char* str, const char* subStr)
{
    const int strLen = strlen(str), subStrLen = strlen(subStr);
    int occurrencesCount = 0, occ;
    int* occurrences = new int[1]{ -1 };

    for (int pos = 0; pos < strLen; pos = occ + subStrLen)
    {
        occ = findSubstring(str, subStr, pos);

        if (occ == -1)
            break;

        int* tmp = new int[++occurrencesCount + 1];
        std::copy(occurrences, occurrences + occurrencesCount, tmp);
        delete[] occurrences;
        occurrences = tmp;

        tmp[occurrencesCount - 1] = occ;
        tmp[occurrencesCount] = -1;
    }

    return occurrences;
}
#pragma endregion
