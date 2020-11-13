// LIBRARIES AVAILABLE IN REPO
// https://github.com/WGOS/Kulev_201_331
#include <iostream>
#include <ConsoleExt.h>
#include <Matrix.h>

using Misc::Console;

#pragma region Prots
void drawMenu();
void inputMatrix(Matrix& matr);
void multiplyMbM(Matrix& matr);
void multiplyMbN(Matrix& matr);
void summ(Matrix& matr);
void getElm(Matrix& matr);
#pragma endregion


int main()
{
    drawMenu();
    return 0;
}

void drawMenu()
{
    int menuPos = 0, opt;
    Matrix matr;

    while (true)
    {
        printf_s("=== Programm menu ===\n");
        printf_s("%d. Input matrix\n", ++menuPos);
        printf_s("%d. Print matrix\n", ++menuPos);
        printf_s("%d. Multiply two matrcices\n", ++menuPos);
        printf_s("%d. Multuply by number\n", ++menuPos);
        printf_s("%d. Summ of matrcies\n", ++menuPos);
        printf_s("%d. Trace\n", ++menuPos);
        printf_s("%d. Get row count\n", ++menuPos);
        printf_s("%d. Get column count\n", ++menuPos);
        printf_s("%d. Get element\n", ++menuPos);
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
            inputMatrix(matr);
            break;

        case 2:
            matr.Print();
            break;

        case 3:
            multiplyMbM(matr);
            break;

        case 4:
            multiplyMbN(matr);
            break;

        case 5:
            summ(matr);
            break;

        case 6:
            printf_s("Matrix trace: %f\n", matr.Trace());
            break;

        case 7:
            printf_s("Row count: %u", matr.GetRows());
            break;

        case 8:
            printf_s("Column count: %u", matr.GetColumns());
            break;

        case 9:
            getElm(matr);
            break;

        case 10:
            printf_s("Exititng\n");
            return;

        default:
            printf_s("Unknown option\n");
            break;
        }
    }
}

void inputMatrix(Matrix& matr)
{
    printf_s("Enter row count: ");
    size_t rows = std::stoul(Console::ReadLine());

    printf_s("Enter column count: ");
    size_t columns = std::stoul(Console::ReadLine());

    matr = Matrix(rows, columns);
    matr.Input();
}

void multiplyMbM(Matrix& matr)
{
    printf_s("Enter values for new matrix\n");
    
    Matrix inpM;
    inputMatrix(inpM);

    try
    {
        Matrix res = matr * inpM;
        printf_s("Multiply result:\n");
        res.Print();
    }
    catch (const std::exception& e)
    {
        printf_s("Error!\n%s", e.what());
    }
}

void multiplyMbN(Matrix& matr)
{
    printf_s("Enter multiplier: ");
    double mult = std::stod(Console::ReadLine());

    Matrix mm = matr * mult;
    mm.Print();
}

void summ(Matrix& matr)
{
    printf_s("Enter values for new matrix\n");

    Matrix inpM;
    inputMatrix(inpM);

    try
    {
        Matrix res = matr + inpM;
        printf_s("Summ:\n");
        res.Print();
    }
    catch (const std::exception& e)
    {
        printf_s("Error!\n%s", e.what());
    }
}

void getElm(Matrix& matr)
{
    printf_s("Enter i: ");
    size_t i = std::stoul(Console::ReadLine());

    printf_s("Enter j: ");
    size_t j = std::stoul(Console::ReadLine());

    printf_s("[%u, %u] = %f\n", i, j, matr[i][j]);
}