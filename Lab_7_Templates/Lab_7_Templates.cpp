#include <iostream>
#include <string>
#include "ConsoleExt.h"

using Misc::Console;

struct student
{
    std::string surname;
    std::string name;
    unsigned short age;

    enum class CompareBy
    {
        Name, Surname, Age
    };

    /// <summary>
    /// Compare structure by its member
    /// </summary>
    /// <param name="by">Member to compare by</param>
    /// <param name="to">Structure to compare to</param>
    /// <returns>0 if structures equal by member; 1 if input structure is greater, -1 if less</returns>
    int compare(CompareBy by, student& to)
    {
        switch (by)
        {
        case student::CompareBy::Name:
            return name.compare(to.name);
        case student::CompareBy::Surname:
            return surname.compare(to.surname);
        case student::CompareBy::Age:
            if (age == to.age)
                return 0;
            else if (age > to.age)
                return -1;
            else
                return 1;
        default:
            return 0;
        }
    }
};

void drawMenu();
template<typename T>
void quickSort(T* array, size_t low, size_t high);
void quickSort(student* array, student::CompareBy member, size_t low, size_t high);

void sortArrayOpt();
void sortStudOpt();

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
        printf_s("%d. Sort an array\n", ++menuPos);
        printf_s("%d. Sort a student list\n", ++menuPos);
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
            sortArrayOpt();
            break;

        case 2:
            sortStudOpt();
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

void sortStudOpt()
{
    size_t len;
    try
    {
        printf_s("Enter array size: ");
        len = std::stoul(Console::ReadLine());
    }
    catch (const std::exception&)
    {
        printf_s("Print correct value!\n");
        return;
    }

    student* arr = new student[len];

    for (size_t i = 0; i < len; i++)
    {
        printf_s("Student #%d:\n", i);

        printf_s("\tEnter surname: ");
        arr[i].surname = Console::ReadLine();

        printf_s("\tEnter name: ");
        arr[i].name = Console::ReadLine();

        printf_s("\tEnter age: ");
        try
        {
            arr[i].age = std::stod(Console::ReadLine());
        }
        catch (const std::exception&)
        {
            printf_s("Print correct value!\n");
            delete[] arr;
            return;
        }
    }

    printf_s("Sort by surname:\n");
    quickSort(arr, student::CompareBy::Surname, 0, len - 1);
    for (size_t i = 0; i < len; i++)
    {
        printf_s("\t%s, %s, %d\n", arr[i].surname.c_str(), arr[i].name.c_str(), arr[i].age);
    }

    printf_s("Sort by name:\n");
    quickSort(arr, student::CompareBy::Name, 0, len - 1);
    for (size_t i = 0; i < len; i++)
    {
        printf_s("\t%s, %s, %d\n", arr[i].surname.c_str(), arr[i].name.c_str(), arr[i].age);
    }

    printf_s("Sort by age:\n");
    quickSort(arr, student::CompareBy::Age, 0, len - 1);
    for (size_t i = 0; i < len; i++)
    {
        printf_s("\t%s, %s, %d\n", arr[i].surname.c_str(), arr[i].name.c_str(), arr[i].age);
    }
}

void sortArrayOpt()
{
    size_t len;
    try
    {
        printf_s("Enter array size: ");
        len = std::stoul(Console::ReadLine());
    }
    catch (const std::exception&)
    {
        printf_s("Print correct value!\n");
        return;
    }

    double* arr = new double[len];

    for (size_t i = 0; i < len; i++)
    {
        printf_s("arr[%u] = ", i);
        try
        {
            arr[i] = std::stod(Console::ReadLine());
        }
        catch (const std::exception&)
        {
            printf_s("Print correct value!\n");
            delete[] arr;
            return;
        }
    }

    quickSort(arr, 0, len - 1);

    printf_s("Sorted array:\n");

    for (size_t i = 0; i < len; i++)
    {
        printf_s("arr[%u] = %f\n", i, arr[i]);
    }

    delete[] arr;
}

// 1 9 2 8 3 7 4 6

template<typename T>
void quickSort(T* array, size_t low, size_t high)
{
    size_t i = low;
    size_t j = high;
    T pivot = array[(i + j) / 2];
    T temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

void quickSort(student* array, student::CompareBy member, size_t low, size_t high)
{
    size_t i = low;
    size_t j = high;
    student pivot = array[(i + j) / 2];
    student temp;

    while (i <= j)
    {
        while (array[i].compare(member, pivot) == -1)
            i++;
        while (array[j].compare(member, pivot) == 1)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, member, low, j);
    if (i < high)
        quickSort(array, member, i, high);
}