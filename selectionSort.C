#include <stdio.h>

void selectionSort(int array[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        int indexOfSmallest = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[indexOfSmallest])
            {
                indexOfSmallest = j;
            }
        }
        temp = array[i];
        array[i] = array[indexOfSmallest];
        array[indexOfSmallest] = temp;
    }
}

int main()
{
    int array[] = {10, 54, 11, 3, 85, 71, 6, 21, 13};
    int size = sizeof(array) / sizeof(array[0]);
    selectionSort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
