#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#pragma region Function prototypes
void drawMenu();
void wr(const char*, bool = true);
void drawTriangleOption();
void calcBinomialOption();
void findAvgOption();
int findBinomialCoefficient(int, int);
int fact(int);
#pragma endregion


int main()
{
    drawMenu();

    return 0;
}

#pragma region Other
void drawMenu()
{
    int opt;

    while (true)
    {
        wr("=== Programm menu ===");
        wr("1. Draw triangle");
        wr("2. Calc binomial coefficient");
        wr("3. Find avg");
        wr("4. Exit");
        wr("Choose one option: ", false);

        cin >> opt;

        switch (opt)
        {
        case 1:
            drawTriangleOption();
            break;

        case 2:
            calcBinomialOption();
            break;

        case 3:
            findAvgOption();
            break;

        case 4:
            wr("Exiting");
            return;

        default:
            wr("Unknown option!");
            break;
        }
    }
}

void wr(const char* text, bool nl)
{
    cout << text;
    if (nl)
        cout << endl;
}
#pragma endregion

#pragma region Task 1
void drawTriangleOption()
{
    unsigned int fNum;

    do 
    {
        wr("Enter a postitive number: ", false);
        cin >> fNum;
    } while (fNum <= 0);
    
    for (unsigned int i = 0; i <= fNum; i++) 
    {
        for (unsigned int j = 0; j <= i; j++)
            cout << j;
        
        cout << endl;
    }
}
#pragma endregion

#pragma region Task 2
void calcBinomialOption()
{
    int n;

    do
    {
        wr("Enter a number (0 < n < 100): ");
        cin >> n;
    } while (!(0 < n && n < 100));

    for (int k = 0; k <= n; k++)
        cout << "C(" << n << ", " << k << ") = " << findBinomialCoefficient(n, k) << endl;
}

int findBinomialCoefficient(int n, int k)
{
    return fact(n) / (fact(n - k) * fact(k));
}

int fact(int n)
{
    if (n == 0)
        return 1;

    if(n > 0)
        for (int i = n - 1; i > 0; i--)
            n *= i;
    else
        for (int i = n + 1; i < 0; i++)
            n *= i;

    return n;
}
#pragma endregion

#pragma region Task 3
void findAvgOption()
{
    wr("Enter values. Enter 0 to exit");

    int count = 0;
    double summ = 0, current;

    while (true)
    {
        cin >> current;

        if (current == 0)
        {
            bool exit;

            wr("Exit? (0 = keep; other = exit): ", false);
            cin >> exit;

            if (exit)
                break;
        }

        count++;
        summ += current;
    }

    if (count == 0)
        wr("No values passed.");
    else
        cout << "Avg: " << summ / count << endl;
}
#pragma endregion
