#include <iostream>
#include <deque>
#include <string>
#include "StringExt.h"
#include "ConsoleExt.h"

using Misc::Console;
using Misc::StrExt;

void drawMenu();
void palindrome();
void convexPoints();

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
        printf_s("%d. Check if palindromic\n", ++menuPos);
        printf_s("%d. Convex hull of points\n", ++menuPos);
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
            palindrome();
            break;

        case 2:
            convexPoints();
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

void palindrome()
{
    std::deque<char> deq;

    printf_s("Enter your expression: ");
    std::string strInput = Console::ReadLine();

    for (char& c : strInput)
    {
        if(c != ' ')
            deq.push_back(tolower(c));
    }

    bool isPalindromic = true;

    do
    {
        if (deq.front() != deq.back()) 
        {
            isPalindromic = false;
            continue;
        }

        deq.pop_front();
        deq.pop_back();
    } while (deq.size() > 1 && !deq.empty() && isPalindromic);

    printf("Expression is %spalindromic\n", isPalindromic ? "" : "not ");

}

void convexPoints()
{
    size_t numPoints;
    try
    {
        printf_s("Enter number of points: ");
        numPoints = std::stoi(Console::ReadLine());
    }
    catch (const std::exception&)
    {
        printf_s("Print correct value!\n");
        return;
    }

    auto points = new double[numPoints][2];

    for (size_t i = 0; i < numPoints; i++)
    {
        double num;
        
        for (size_t j = 0; j < 1; j++)
        {
            try
            {
                printf_s("Enter point %u %c: ", i, j % 2 == 0 ? 'X' : 'Y');
                num = std::stoul(Console::ReadLine());
            }
            catch (const std::exception&)
            {
                printf_s("Print correct value!\n");
                return;
            }
        }
    }
}