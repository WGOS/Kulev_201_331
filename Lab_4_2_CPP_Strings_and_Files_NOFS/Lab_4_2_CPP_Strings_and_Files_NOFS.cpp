// C++ 17
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

using std::string;
using std::cout;
using fs::path;

#pragma region Prots
string readLine();
void drawMenu();
void getFileExtOption();
string getFileExt(const string filePath);
void getFileNameOption();
string getFileName(const string filePath);
void getDirPathOption();
string getDirPath(const string filePath);
void getRootOption();
string getRoot(const string pathStr);
void renameFileOption();
bool renameFile(string* pathStr, const string newName);
void copyFileOption();
bool copyFile(const string fromPathStr, const string toPathStr);
bool copyFile2(const string fromPathStr, const string toPathStr);
bool copyFile3(const string fromPathStr, const string toPathStr);
size_t strSplit(string*& subStrings, const string str, const char delimiter);
string strJoin(const string* subStrings, const size_t size, const char delimiter = NULL);
#pragma endregion

int main()
{
    drawMenu();
}

#pragma region Others
void drawMenu()
{
    int menuPos = 0, opt;

    while (true)
    {
        printf_s("=== Programm menu ===\n");
        printf_s("%d. Get file extension\n", ++menuPos);
        printf_s("%d. Get file name\n", ++menuPos);
        printf_s("%d. Get parent directory path\n", ++menuPos);
        printf_s("%d. Get root name\n", ++menuPos);
        printf_s("%d. Rename file\n", ++menuPos);
        printf_s("%d. Copy file\n", ++menuPos);
        printf_s("%d. Exit\n", ++menuPos);
        printf_s("Choose one option: ");

        menuPos = 0;

        try
        {
            opt = stoi(readLine());
        }
        catch (const std::exception&)
        {
            printf_s("Print correct value!\n");
            continue;
        }

        switch (opt)
        {
        case 1:
            getFileExtOption();
            break;

        case 2:
            getFileNameOption();
            break;

        case 3:
            getDirPathOption();
            break;

        case 4:
            getRootOption();
            break;

        case 5:
            renameFileOption();
            break;

        case 6:
            copyFileOption();
            break;

        case 7:
            printf_s("Exititng\n");
            return;

        default:
            printf_s("Unknown option\n");
            break;
        }
    }
}

string readLine()
{
    string str;
    std::getline(std::cin, str);

    return str;
}

/// <summary>
/// Split strings to substrings by delimiter
/// </summary>
/// <param name="subStrings">Pointer address of sub-strings array</param>
/// <param name="str">String to split</param>
/// <param name="delimiter">Delimiter to split string by</param>
/// <returns>Size of sub-strings array</returns>
size_t strSplit(string*& subStrings, const string str, const char delimiter)
{
    size_t delimOcc = std::count(str.begin(), str.end(), delimiter);
    if (delimOcc <= 0)
        return 0;

    subStrings = new string[delimOcc + 1];

    for (size_t pos = 0, nPos, i = 0; i <= delimOcc; i++, pos = nPos + 1)
    {
        nPos = str.find(delimiter, pos);
        subStrings[i] = str.substr(pos, nPos - pos);
    }

    return delimOcc + 1;
}

/// <summary>
/// Join substrings into one string
/// </summary>
/// <param name="subStrings">Array of substrings to join</param>
/// <param name="size">Size of array of substrings</param>
/// <param name="delimiter">Delimiter between substrings</param>
/// <returns>Joined string</returns>
string strJoin(const string* subStrings, const size_t size, const char delimiter)
{
    if (size <= 0)
        return "";

    string jStr = subStrings[0];

    for (size_t i = 1; i < size; i++)
    {
        if (delimiter != NULL)
            jStr += delimiter;

        jStr += subStrings[i];
    }

    return jStr;
}
#pragma endregion

#pragma region Task 1
/// <summary>
/// Entry function for 1st task
/// </summary>
void getFileExtOption()
{
    printf_s("Enter path: ");
    printf_s("Exteinsion is: %s\n", getFileExt(readLine()).c_str());
}

/// <summary>
/// Get file extension
/// </summary>
/// <param name="str">Path to file</param>
/// <returns>File extension with dot before</returns>
string getFileExt(const string str)
{
    string* nameParts = nullptr;
    const size_t pCnt = strSplit(nameParts, getFileName(str), '.');
    
    if (pCnt <= 0)
        return "";

    const string ext = nameParts[pCnt - 1];
    delete[] nameParts;

    return "." + ext;
}
#pragma endregion

#pragma region Task 2
/// <summary>
/// Entry func for 2nd task
/// </summary>
void getFileNameOption()
{
    printf_s("Enter path: ");
    const string path = readLine();
    printf_s("File name is: %s\n",
        getFileName(path).c_str());
}

/// <summary>
/// Get name of file from path
/// </summary>
/// <param name="filePath">Path to file</param>
/// <returns>File name w/ extension by default</returns>
string getFileName(const string filePath)
{
    string* subs;
    const size_t partsCount = strSplit(subs, filePath, '\\');

    if (partsCount <= 1)
        return filePath;

    const string name = subs[partsCount - 1];
    const string prevName = subs[partsCount - 2];
    delete[] subs;

    if (name == prevName && partsCount == 2)
        return filePath;

    if (name.empty())
        return prevName;

    return name;
}
#pragma endregion

#pragma region Task 3
/// <summary>
/// Entry func for 3rd task
/// </summary>
void getDirPathOption()
{
    printf_s("Enter path: ");
    const string path = readLine();

    printf_s("Parent directory path: %s\n", getDirPath(path).c_str());
}

/// <summary>
/// Get relative path from two paths
/// </summary>
/// <param name="basePathStr">Base path</param>
/// <param name="relPathStr">Path that base relative to</param>
/// <returns>Path relative to base</returns>
string getDirPath(const string filePath)
{
    string* pathParts = nullptr;
    const size_t partCount = strSplit(pathParts, filePath, '\\');

    const string parentPath = strJoin(pathParts, partCount - 1, '\\');
    delete[] pathParts;

    return parentPath;
}
#pragma endregion

#pragma region Task 4
/// <summary>
/// Entry func for 4th task
/// </summary>
void getRootOption()
{
    printf_s("Enter path: ");
    printf_s("Root is: %s\n", getRoot(readLine()).c_str());
}

/// <summary>
/// Get root name of path
/// </summary>
/// <param name="pathStr">Path</param>
/// <returns>Root name</returns>
string getRoot(const string pathStr)
{
    string* pathParts = nullptr;
    strSplit(pathParts, pathStr, '\\');

    const string rootName = pathParts[0];
    delete[] pathParts;

    return !rootName.empty() ? rootName : "\\";
}
#pragma endregion

#pragma region Task 5
/// <summary>
/// Entry func for 5th task
/// </summary>
void renameFileOption()
{
    printf_s("Enter path to file: ");
    string fPath = readLine();

    printf_s("Enter new file name: ");
    const string newName = readLine();

    if (!renameFile(&fPath, newName))
        printf_s("Unable to rename file!\n");

    printf_s("New file path: %s\n", fPath.c_str());
}

/// <summary>
/// Rename file (does not affect actual file system)
/// </summary>
/// <param name="pathStr">Pointer to file path that will be renamed</param>
/// <param name="newName">New name of file w/o path delimiters</param>
/// <returns>Has pathStr changed</returns>
bool renameFile(string* pathStr, const string newName)
{
    if (newName.find('\\') != string::npos || newName.find('/') != string::npos)
        return false;

    const string oldName = getFileName(*pathStr);

    *pathStr = (*pathStr).replace((*pathStr).length() - oldName.length(), oldName.length(), newName);
    return true;
}
#pragma endregion

#pragma region Task 6
/// <summary>
/// Entry function for 6th task
/// </summary>
void copyFileOption()
{
    printf_s("Enter path to file: ");
    const string ogPath = readLine();

    printf_s("%s\n", copyFile(ogPath, ogPath + "_copy") ? "File has been copied" : "Can't copy file");
}

/// <summary>
/// Copy file
/// </summary>
/// <param name="fromPathStr">Path to file</param>
/// <param name="toPathStr">Path of new file dest</param>
/// <returns>Has file been copied</returns>
bool copyFile(const string fromPathStr, const string toPathStr)
{
    std::ifstream in;
    std::ofstream out;
    string buf;

    try
    {
        in.open(fromPathStr);
        out.open(toPathStr);

        while (std::getline(in, buf))
        {
            out << buf << std::endl;
        }
    }
    catch (const std::exception&)
    {
        return false;
    }

    if(in.is_open())
        in.close();

    if(out.is_open())
        out.close();
    
    return true;
}

bool copyFile2(const string fromPathStr, const string toPathStr)
{
    std::ifstream in;
    std::ofstream out;

    try
    {
        in.open(fromPathStr);
        out.open(toPathStr);

        out << in.rdbuf();
    }
    catch (const std::exception&)
    {
        return false;
    }

    if (in.is_open())
        in.close();

    if (out.is_open())
        out.close();

    return true;
}

bool copyFile3(const string fromPathStr, const string toPathStr)
{
    return fs::copy_file(fromPathStr, toPathStr);
}
#pragma endregion