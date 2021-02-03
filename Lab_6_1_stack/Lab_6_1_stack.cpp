#include <iostream>
#include <stack>
#include <string>
#include "StringExt.h"
#include "ConsoleExt.h"

using Misc::Console;
using Misc::StrExt;

void drawMenu();
void inputStack();

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
        printf_s("%d. Input stack\n", ++menuPos);
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
            inputStack();
            break;

        case 2:
            printf_s("Exititng\n");
            return;

        default:
            printf_s("Unknown option\n");
            break;
        }
    }
}

void inputStack() 
{
    const std::string brackets[2] = { "([{", ")]}" };
    std::stack<char> strStack;

    printf_s("Enter your expression: ");
    std::string strInput = Console::ReadLine();

    for (char& c : strInput)
    {
        if (brackets[0].find(c) != std::string::npos) 
        {
            strStack.push(c);
        }
        else if (brackets[1].find(c) != std::string::npos) 
        {
            size_t enclosureIndex = brackets[1].find(c);

            if (!strStack.empty() && strStack.top() == brackets[0][enclosureIndex])
                strStack.pop();
            else if (strStack.empty())
                strStack.push(c);
        }
    }

    printf("Expression is %s\n", strStack.empty() ? "correct" : "incorrect!");

}