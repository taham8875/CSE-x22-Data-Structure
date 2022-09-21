#include <stdio.h>

void towerOfHanoi(int numberOfDisks, int start, int end, int temp)
{
    if (numberOfDisks > 0)
    {
        towerOfHanoi(numberOfDisks - 1, start, temp, end);
        printf("move disk %d from %d to %d\n", numberOfDisks, start, end);
        towerOfHanoi(numberOfDisks - 1, temp, end, start);
    }
    else
        return;
}

int main()
{
    int numberOfDisks, start, end, temp;
    printf("Enter the number of disks, start, end, temp: ");
    scanf("%d %d %d %d", &numberOfDisks, &start, &end, &temp);
    towerOfHanoi(numberOfDisks, start, end, temp);
}