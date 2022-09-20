#include <stdio.h>

void insertionSort(int array[], int size)
{
    int element;
    int j;
    for (int i = 1; i < size; i++)
    {
        element = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > element)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = element;
    }
}

int main()
{
    int array[] = {10, 54, 11, 3, 85, 71, 6, 21, 13};
    int size = sizeof(array) / sizeof(array[0]);
    insertionSort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
