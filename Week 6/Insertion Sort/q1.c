//Insertion Sort in C

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int n, x, j;
    int opcount = 0;
    printf("Enter Number of elements:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array Elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j>=0 && arr[j] > x)
        {
            opcount++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
    printf("Sorted Array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\nOperation Count: %d\n", opcount);
    return 0;
}
