#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include "StringExt.h"
#include "ConsoleExt.h"

using Misc::Console;
using Misc::StrExt;
using std::string;

void drawMenu();
void solveTest();
void listStuds();

namespace lab6 
{
    std::unordered_set<std::string> students;
}

int main()
{
    drawMenu();

    return 0;
}

void drawMenu()
{
    int menuPos = 0, opt;

    while (true)
    {
        printf_s("=== Programm menu ===\n");
        printf_s("%d. Solve the test\n", ++menuPos);
        printf_s("%d. List students\n", ++menuPos);
        printf_s("%d. Exit\n", ++menuPos);
        printf_s("Choose one option: ");

        menuPos = 0;

        try
        {
            opt = std::stoi(Console::ReadLine());
        }
        catch (const std::exception&)
        {
            printf_s("Print correct value!\n");
            continue;
        }

        switch (opt)
        {
        case 1:
            solveTest();
            break;

        case 2:
            listStuds();
            break;

        case 3:
            printf_s("Exititng\n");
            return;

        default:
            printf_s("Unknown option\n");
            break;
        }
    }
}

void solveTest()
{
    printf_s("Enter your full name: ");
    string stName = Console::ReadLine();

    StrExt::ToLower(stName);

    if (lab6::students.find(stName) != lab6::students.end())
    {
        printf_s("You've already solved the test!\n");
        return;
    }

    std::unordered_set<string> answers;

    for (int i = 0; i < 3; i++)
    {
        printf_s("Question %d: bla-bla\nAnswer: ", i + 1);
        Console::ReadLine();
    }

    lab6::students.insert(stName);
}

void listStuds()
{
    for (string stud : lab6::students)
    {
        printf_s("%s\n", stud.c_str());
    }
}