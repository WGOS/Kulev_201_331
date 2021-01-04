#include <iostream>

template<typename T>
void quickSort(T* array, size_t low, size_t high);


int main()
{
    int a[] = { 1, 32, 4, 123, 2139, 143, 1, 344, 23, 23, 566656, 1024 };

    quickSort(a, 0, 11);

    for (int i = 0; i < 12; i++)
        std::cout << a[i] << std::endl;


}

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
