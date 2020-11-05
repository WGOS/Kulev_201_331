// C++ 17
#include <iostream>
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
string getFileName(const string filePath, const bool attachExt = true);
void getRelativePathOption();
string getRelativePath(const string basePathStr, const string relPathStr);
void getRootOption();
string getRoot(const string pathStr);
void renameFileOption();
bool renameFile(string* pathStr, const string newName);
void copyFileOption();
bool copyFile(const string fromPathStr, const string toPathStr, const bool rewrite = false);
#pragma endregion

int main()
{
    drawMenu();
}

void drawMenu()
{
    int menuPos = 0, opt;

    while (true)
    {
        printf_s("=== Programm menu ===\n");
        printf_s("%d. Get file extension\n", ++menuPos);
        printf_s("%d. Get file name\n", ++menuPos);
        printf_s("%d. Get relative path\n", ++menuPos);
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
            getRelativePathOption();
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
/// <param name="str">is path to file</param>
/// <returns>File extension with dot before</returns>
string getFileExt(const string str)
{
    return path(str).extension().string();
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
    printf_s(
        "File name w/ extension is: %s\n\tw/o extension: %s\n", 
        getFileName(path).c_str(), 
        getFileName(path, false).c_str());
}

/// <summary>
/// Get name of file from path
/// </summary>
/// <param name="filePath">Path to file</param>
/// <param name="attachExt">Attach extension to return value</param>
/// <returns>File name w/ extension by default</returns>
string getFileName(const string filePath, const bool attachExt)
{
    const path p(filePath);
    string name = p.filename().string();

    if (attachExt || !p.has_extension())
        return name;

    const string ext = getFileExt(filePath);

    return name.replace(name.length() - ext.length(), ext.length(), "");
}
#pragma endregion

#pragma region Task 3
/// <summary>
/// Entry func for 3rd task
/// </summary>
void getRelativePathOption()
{
    printf_s("Enter base path: ");
    const string basePathStr = readLine();

    printf_s("Enter relative to path: ");
    const string relPathStr = readLine();

    printf_s("Relative path: %s\n", getRelativePath(basePathStr, relPathStr).c_str());
}

/// <summary>
/// Get relative path from two paths
/// </summary>
/// <param name="basePathStr">Base path</param>
/// <param name="relPathStr">Path that base relative to</param>
/// <returns>Path relative to base</returns>
string getRelativePath(const string basePathStr, const string relPathStr)
{
    const path base(basePathStr);
    const path rel(relPathStr);
    
    return fs::relative(base, rel).string();
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
    return path(pathStr).root_name().string();
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

    const string oldName = path(*pathStr).filename().string();

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

    printf_s("Enter destination of file: ");
    const string dstPath = readLine();

    printf_s("%s\n", copyFile(ogPath, dstPath) ? "File has been copied" : "Can't copy file");
}

/// <summary>
/// Copy file
/// </summary>
/// <param name="fromPathStr">Path to file</param>
/// <param name="toPathStr">Path of new file dest</param>
/// <param name="rewrite">Rewrite file if it exists</param>
/// <returns>Has file been copied</returns>
bool copyFile(const string fromPathStr, const string toPathStr, const bool rewrite)
{
    const path from(fromPathStr);
    const path to(toPathStr);

    if (
        fs::is_directory(from)
        || (fs::exists(to) && !rewrite))
        return false;

    try
    {
        return fs::copy_file(from, to);
    }
    catch (const std::exception&)
    {
        return false;
    }
}
#pragma endregion