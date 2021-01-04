#include <iostream>
#include <map>
#include <string>
#include "ConsoleExt.h"
#include "StringExt.h"

using Misc::Console;
using Misc::StrExt;
using std::string;

void drawMenu();
void countPercentage();

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
        printf_s("%d. Input a text\n", ++menuPos);
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
            countPercentage();
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

void countPercentage()
{
    std::map<string, size_t> words;

    printf_s("Input your text below:\n");

    string inp = Console::ReadLine();
    string* wordsArray;
    size_t wordsArraySize = StrExt::Split(inp, ' ', wordsArray);

    for (size_t i = 0; i < wordsArraySize; i++)
    {
        string word = wordsArray[i];
        StrExt::ToLower(word);

        if (words.find(word) == words.end())
            words.try_emplace(word, 1);
        else
            words[word]++;
    }

    for (const auto& kvp : words)
    {
        printf_s("\"%s\", %.2f%% (%u)\n", kvp.first.c_str(), ((double)kvp.second / wordsArraySize) * 100, kvp.second);
    }

    delete[] wordsArray;
}