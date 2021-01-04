#include <iostream>
#include <queue>
#include <string>
#include "StringExt.h"
#include "ConsoleExt.h"

using Misc::Console;
using Misc::StrExt;

void drawMenu();
void inpNumber();
bool checkNumber(unsigned long long num);

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
            inpNumber();
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

bool checkNumber(unsigned long long num)
{
    const int simpleNumbers[3] = { 2, 3, 5 };
    std::queue<unsigned long long> nq;

    nq.push(num);

    for (int i = 0; i < 3; i++)
    {
        while (nq.back() % simpleNumbers[i] == 0)
        {
            nq.push(nq.back() / simpleNumbers[i]);
        }
    }

    return nq.back() == 1;
}

void inpNumber()
{
    std::queue<unsigned long long> nq;
    unsigned long long number;

    try
    {
        printf_s("Enter number count: ");
        number = std::stoi(Console::ReadLine());
    }
    catch (const std::exception&)
    {
        printf_s("Print correct value!\n");
        return;
    }

    for (unsigned long long i = 2, n = 0; n < number; i++)
    {
        if (checkNumber(i))
        {
            nq.push(i);
            n++;
        }
    }

    while (!nq.empty())
    {
        printf_s("%llu\n", nq.front());
        nq.pop();
    }
}