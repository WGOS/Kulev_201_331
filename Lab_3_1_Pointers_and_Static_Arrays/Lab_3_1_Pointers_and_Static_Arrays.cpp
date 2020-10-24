#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#pragma region Prots
void drawMenu();
void wr(const char*, bool = true);

template <typename T>
void bubbleSort(T*, const int);

void countSortCharSpecial(char*, const int);

template <typename T>
void mergeSort(T*, const int);

template <typename T>
void userInputArray(const int);
#pragma endregion

#define ASCII_START 'a'
#define ASCII_END 'z'

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
        wr("1. Numeric bubble sort");
        wr("2. Char count sort");
        wr("3. Numeric merge sort");
        wr("4. Exit");
        wr("Choose one option: ", false);

        cin >> opt;

        switch (opt)
        {
        case 1:
            userInputArray<double[1000]>(opt);
            break;

        case 2:
            userInputArray<char[1000]>(opt);
            break;

        case 3:
            wr("Sorry but this algorythm has no implementation yet :(");
            //userInputArray<double[1000]>(opt);
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

template <typename T>
void userInputArray(const int opt)
{
    T arr;
    int size;

    const int maxSize = sizeof(arr) / sizeof(*arr);

    do
    {
        cout << "Enter array size (max: " << maxSize << "): ";
        cin >> size;
    } while (size > maxSize);

    for (int i = 0; i < size; i++)
    {
        do
        {
            cout << "[" << i << "] = ";
            cin >> arr[i];
        } while (opt == 2 && !(ASCII_START <= arr[i] && arr[i] <= ASCII_END));
        // Check for a..z range for char array
    }

    if (maxSize > 1)
    {
        switch (opt)
        {
        case 1:
            bubbleSort(arr, size);
            break;

        case 2:
            countSortCharSpecial((char*)arr, size);
            break;
        case 3:
            mergeSort(arr, size);
            break;
        }
    }

    wr("Sorted array:");
    for (int i = 0; i < size; i++)
        cout << "[" << i << "] = " << arr[i] << endl;
}

template <typename T>
void bubbleSort(T* arr, const int size)
{
    bool swapped;

    do
    {
        swapped = false;

        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swapped = true;
                T buf = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buf;
            }
        }

    } while (swapped);
}

// This is function for a specific case of sorting chars from a to z!
void countSortCharSpecial(char* arr, const int size)
{
    const int offset = ASCII_START;
    const int helpSize = ASCII_END - ASCII_START + 1;
    int helpArr[helpSize] = { 0 };
    
    for (int i = 0; i < size; i++)
        helpArr[(int) arr[i] - offset]++;

    int arrIndex = 0;
    for (int i = 0; i < helpSize; i++)
    {
        for (int j = 0; j < helpArr[i]; j++)
        {
            arr[arrIndex] = i + offset;
            arrIndex++;
        }
    }
}

template <typename T>
void mergeSort(T* arr, int size)
{
    
}