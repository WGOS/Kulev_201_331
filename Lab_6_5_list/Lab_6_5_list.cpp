#include <iostream>
#include <list>
#include <string>
#include "ConsoleExt.h"

using Misc::Console;
using std::string;

void drawMenu();
void inputList();
void outputList();

namespace lab6
{
    std::list<string> group;
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
        printf_s("%d. Input list\n", ++menuPos);
        printf_s("%d. Output list\n", ++menuPos);
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
            inputList();
            break;

        case 2:
            outputList();
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

void inputList()
{
    printf_s("Enter list of students. Enter \"end\" to stop\n");
    
    string inp;

    while (true)
    {
        inp = Console::ReadLine();

        if (inp == "end")
            break;

        lab6::group.push_back(inp);
    }
}

void outputList()
{
    for (string stud : lab6::group)
    {
        printf_s("%s\n", stud.c_str());
    }
}