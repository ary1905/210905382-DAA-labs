#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* code */
    int n, i, j;
    int count = 0;
    int temp, min;
    printf("Enter Number of elements in the array:\n");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    printf("Enter Elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            count++;
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\nCount: %d\n", count);
    return 0;
}
