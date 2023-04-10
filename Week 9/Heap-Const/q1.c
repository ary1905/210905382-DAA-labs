#include <stdio.h>
#include <stdlib.h>
int opcount = 0;

void heapify(int a[], int x)
{
    int root = x / 2;
    while (root > 0)
    {
        opcount++;
        if (a[root] < a[x])
        {
            int temp = a[x];
            a[x] = a[root];
            a[root] = temp;

            x = root;
            root = x / 2;
        }
        else
            return;
    }
}

int main()
{
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n + 1 * sizeof(int));
    printf("Enter Heap Elements: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        heapify(arr, i);
    }
    printf("Constructed Heap:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\nNumber of Operations: %d", opcount);
}
