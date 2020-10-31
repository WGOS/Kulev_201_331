#include <iostream>
#include <string>

using std::wstring;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

#pragma region Prots
wstring readLine();
void drawMenu();
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
        printf_s("%d. Check if string is palindromic\n", ++menuPos);
        printf_s("%d. Substring\n", ++menuPos);
        printf_s("%d. Encrypt string\n", ++menuPos);
        printf_s("%d. Select text in braces\n", ++menuPos);
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
            break;

        case 2:
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

wstring readLine()
{
    wstring str;
    getline(std::wcin, str);

    return str;
}