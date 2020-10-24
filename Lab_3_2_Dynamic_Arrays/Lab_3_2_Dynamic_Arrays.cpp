#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#pragma region Prots
void drawMenu();
void wr(const char*, bool = true);

bool tryDelArray(int* arr);
void enterArray(int*& arrPtr, int& size);
void outArray(const int* arr, const int& size);
void bubbleSortEven(int* arr, const int& size);
void bubbleSortLastDigit(int* arr, const int& size);
int evenDigitsSum(const int& num);
int countDigits(int num);
int lastDigit(const int& num);
bool areLastDigitsEqual(const int* arr, const int& size);
bool isArrayNullptr(const int* arr);
#pragma endregion

int main()
{
    drawMenu();
    return 0;
}

#pragma region Other
void drawMenu()
{
    int* arr = nullptr;
    int opt, size;

    while (true)
    {
        wr("=== Programm menu ===");
        wr("1. Input array");
        wr("2. Output array");
        wr("3. Sort by summ of even digits");
        wr("4. Sort by last digit asc");
        wr("5. Exit");
        wr("Choose one option: ", false);

        cin >> opt;

        switch (opt)
        {
        case 1:
            enterArray(arr, size);
            break;

        case 2:
            if(!isArrayNullptr(arr))
                outArray(arr, size);

            break;

        case 3:
            if (!isArrayNullptr(arr))
                bubbleSortEven(arr, size);

            break;

        case 4:
            if (!isArrayNullptr(arr))
                bubbleSortLastDigit(arr, size);

            break;

        case 5:
            tryDelArray(arr);
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

bool tryDelArray(int* arr)
{
    if (isArrayNullptr(arr))
    {
        wr("Removing array");
        delete[] arr;

        return true;
    }

    return false;
}

bool isArrayNullptr(const int* arr)
{
    bool r = arr == nullptr;

    if (r)
        wr("Array is not provided!");

    return r;
}
#pragma endregion

#pragma region Task 1
void enterArray(int*& arrPtr, int& size)
{
    tryDelArray(arrPtr);

    do
    {
        wr("Enter array size: ", false);
        cin >> size;
    } while (size <= 0);

    arrPtr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] = ";
        cin >> arrPtr[i];
    }
}
#pragma endregion

#pragma region Task 2
void outArray(const int* arrPtr, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arrPtr[i] << endl;
    }
}
#pragma endregion

#pragma region Task 3
void bubbleSortEven(int* arr, const int& size)
{
    bool swapped;

    do
    {
        swapped = false;

        for (int i = 0; i < size - 1; i++)
        {
            if (evenDigitsSum(arr[i]) > evenDigitsSum(arr[i + 1]))
            {
                swapped = true;
                int buf = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buf;
            }
        }

    } while (swapped);
}

int evenDigitsSum(const int& num)
{
    if (num < 10)
        return num;

    int dgtCount = countDigits(num);
    int currPos = 0;
    int currNum = num;
    int sum = 0;

    while (currNum > 0)
    {
        currPos++;

        if (currPos % 2 == (dgtCount % 2 == 0 ? 1 : 0))
            sum += currNum % 10;

        currNum /= 10;
    }

    return sum;
}

int countDigits(int num)
{
    int count = 0;

    while (num > 0)
    {
        num /= 10;
        count++;
    }

    return count;
}
#pragma endregion

#pragma region Task 4
void bubbleSortLastDigit(int* arr, const int& size)
{
    bool swapped;
    bool ldEqual = areLastDigitsEqual(arr, size);

    do
    {
        swapped = false;

        for (int i = 0; i < size - 1; i++)
        {
            if ((ldEqual && arr[i] < arr[i + 1]) || (!ldEqual && lastDigit(arr[i]) > lastDigit(arr[i + 1])))
            {
                swapped = true;
                int buf = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buf;
            }
        }

    } while (swapped);
}

int lastDigit(const int& num)
{
    return num % 10;
}

bool areLastDigitsEqual(const int* arr, const int& size)
{
    int currLastDigit = lastDigit(arr[0]);

    for (int i = 1; i < size; i++)
    {
        if (currLastDigit != lastDigit(arr[i]))
            return false;
    }

    return true;
}
#pragma endregion