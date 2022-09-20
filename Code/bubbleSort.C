#include <stdio.h>

void bubbleSort(int array[], int size)
{
    int temp;
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main()
{
    int array[] = {10, 54, 11, 3, 85, 71, 6, 21, 13};
    int size = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
