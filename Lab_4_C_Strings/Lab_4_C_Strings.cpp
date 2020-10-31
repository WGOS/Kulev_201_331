#include <iostream>
#include <cstring>
#include <Windows.h>

using std::cin;

#pragma region Prots
void drawMenu();
void wr(const char*, const bool = true);
void palindromeOption();
bool isPalindrome(const char*);
int findSubstring(const char*, const char*, const int);
int* findSubstring(const char*, const char*);
void subStringOption();
void encryptOption();
void encrypt(char*, const int);
char* readStr(const int);
bool isCyrillic(const char);
bool isUpperC(const char);
#pragma endregion

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << isUpperC('Ù') << std::endl;

    drawMenu();

	return 0;
}

#pragma region Others
void drawMenu()
{
    int menuPos = 0;

    while (true)
    {
        printf_s("=== Programm menu ===\n");
        printf_s("%d. Check if string is palindromic\n", ++menuPos);
        printf_s("%d. Substring\n", ++menuPos);
        printf_s("%d. Encrypt string\n", ++menuPos);
        printf_s("%d. Sort by last digit asc\n", ++menuPos);
        printf_s("%d. Exit\n", ++menuPos);
        printf_s("Choose one option: ");

        menuPos = 0;

        switch (atoi(readStr(255)))
        {
        case 1:
            palindromeOption();
            break;

        case 2:
            subStringOption();
            break;

        case 3:
            encryptOption();
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

/// <summary>
/// Reads string from stdin
/// </summary>
/// <param name="maxLen">Maximum lenght of string (w/o terminator)</param>
/// <returns>Pointer to a string</returns>
char* readStr(const int maxLen)
{
    char* str = nullptr;
    char* buf = new char[maxLen + 1]{ 0 };

    cin.getline(buf, maxLen);

    const int strLen = strlen(buf);
    str = new char[strLen + 1] {0};

    std::copy(buf, buf + strLen + 1, str);
    delete[] buf;

    return str;
}
#pragma endregion

#pragma region Task 1
/// <summary>
/// Entry fucntion for 1st palindrome task
/// </summary>
void palindromeOption()
{
    printf_s("Enter string to check (up to 255 symbols): ");
    const char* str = readStr(255);

    printf_s("String is %s%s\n", isPalindrome(str) ? "" : "not ", "palindromic");
    delete[] str;
}

/// <summary>
/// Check if string is palindromic
/// </summary>
/// <param name="str">String pointer</param>
/// <returns>Palindromic</returns>
bool isPalindrome(const char* str)
{
    bool palindromic = true;
    int bareStringLen = 0, currCharNum = 0, originalLen = strlen(str);
    char currChar;
    char* bareString = new char[originalLen] {0};

    for (int i = 0; i < originalLen; i++)
    {
        if (str[i] != ' ') 
            bareString[bareStringLen++] = tolower(str[i]);
    }


    for (int i = 0; i < (bareStringLen) / 2; i++)
    {
        if (bareString[i] != bareString[bareStringLen - 1 - i])
        {
            palindromic = false;
            break;
        }
    }

    delete[] bareString;
    return palindromic;
}
#pragma endregion

#pragma region Task 2
/// <summary>
/// Entry function for 2nd task
/// </summary>
void subStringOption()
{
    printf_s("Print string (up to 255 symbols): ");
    const char* str = readStr(255);

    printf_s("Print substring (up to 255 symbols): ");
    const char* subStr = readStr(255);

    printf_s("Print start position: ");
    const int sPos = atoi(readStr(255)); // does atoi releases RAM?

    const int occ = findSubstring(str, subStr, sPos);
    if (occ == -1)
        printf_s("No occurence found!\n");
    else
        printf_s("Found first occurrence at: %d\n", occ);

    printf_s("Finding all occurrences\n");
    const int* occs = findSubstring(str, subStr);

    if (occs[0] != -1)
        for (int i = 0; occs[i] != -1; i++)
            printf_s("\tOccurrence #%d at %d\n", i + 1, occs[i]);
    else
        printf_s("\tNo occurrences found\n");

    delete[] str, subStr, occs;
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

#pragma region Task 3
/// <summary>
/// Entry function for 3rd task
/// </summary>
void encryptOption()
{
    printf_s("Enter string to encrypt (up to 255 symbols): ");
    char* str = readStr(255);

    printf_s("Enter key: ");
    const int key = atoi(readStr(255));

    encrypt(str, key);

    printf_s("Encrypted string:\t\n%s\n", str);

    delete[] str;
}

/// <summary>
/// Encrypts string by offset
/// </summary>
/// <param name="str">String to encrypt, will be changed in process</param>
/// <param name="key">Encryptyion offset</param>
void encrypt(char* str, const int key)
{
    int offset, alphabetStrengh;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            continue;

        if (isCyrillic(str[i]))
        {
            switch (str[i])
            {
            case '¨':
                str[i] = 'Å';
                break;

            case '¸':
                str[i] = 'å';
                break;
            }

            alphabetStrengh = 32;
            offset = isUpperC(str[i]) ? 'À' : 'à';
        }
        else
        {
            alphabetStrengh = 26;
            offset = isUpperC(str[i]) ? 'A' : 'a';
        }

        str[i] = char(int(str[i] + key - offset) % alphabetStrengh + offset);
    }
}

/// <summary>
/// Checks if char is in cyrillic range
/// </summary>
/// <param name="c">Char to check</param>
/// <returns>Is char cyrillic</returns>
bool isCyrillic(const char c)
{
    int tablePos = 256 + c;

    return c < 0 && ((192 <= tablePos && tablePos <= 255) || tablePos == 168 || tablePos == 184);
}

/// <summary>
/// Checks if char is in uppercase
/// </summary>
/// <param name="c">Char to check</param>
/// <returns>Is char is in uppercase</returns>
bool isUpperC(const char c)
{
    if (!isCyrillic(c))
        return isupper(c);

    int tablePos = 256 + c;

    return (192 <= tablePos && tablePos <= 223) || tablePos == 168;
}
#pragma endregion
