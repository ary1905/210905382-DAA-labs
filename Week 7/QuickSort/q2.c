#include <stdio.h>
int opcount=0;

void quicksort(int number[], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
            {
                i++;
                opcount++;
            }
            while (number[j] > number[pivot])
            {
                j--;
                opcount++;
            }
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

int main()
{
    int i, n;
    printf("Enter Number of Elements:\n");
    scanf("%d", &n);
    int number[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &number[i]);
    quicksort(number, 0, n - 1);
    printf("The Sorted Order is: ");
    for (i = 0; i < n; i++)
        printf(" %d", number[i]);
    printf("\n");
    printf("The Number of Basic Operation: %d\n", opcount);
    return 0;
}