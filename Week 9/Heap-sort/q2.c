#include <stdio.h>
#include <stdlib.h>
int op = 0;

void heapify(int h[], int l, int n)
{
    int i, k, v, heap, j;
    for (i = (n / 2); i >= l; i--)
    {
        k = i;
        v = h[k];
        heap = 0;
        while (heap == 0 && 2 * k <= n)
        {
            j = 2 * k;
            op++;
            if (j < n)
                if (h[j] < h[j + 1])

                    j = j + 1;
            if (v >= h[j])
                heap = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}

void heapSort(int arr[], int n)
{
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        heapify(arr, 1, n - k);
        int temp = arr[1];
        arr[1] = arr[n - k];
        arr[n - k] = temp;
        k++;
    }
}

void main()
{
    int arr[20], n;
    printf("Enter the Number of Elements : \n");
    scanf("%d", &n);
    printf("Enter the Elements : \n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    heapSort(arr, n);
    printf("The Sorted List is : \n");
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Count = %d\n", op);
}
