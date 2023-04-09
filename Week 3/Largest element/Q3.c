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
    int max = arr[0];
    for (i = 0; i < n - 1; i++)
    {
        count++;
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Largest Element: %d", max);
    printf("\nCount: %d\n", count);
    return 0;
}
