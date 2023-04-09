#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    int count = 0;
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
        for (j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\nCount: %d\n", count);
    return 0;
}
