#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mask(int mk[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        mk[i] = 0;
    }
    while (x > 0)
    {
        mk[--n] = x % 2;
        x /= 2;
    }
}

int main()
{
    int n;
    int flag = 0;
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    printf("Enter Size of the Array:\n");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    int *mk = malloc(sizeof(int) * n);
    printf("Enter Array Elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < pow(2, n); i++)
    {
        mask(mk, n, i);
        sum1 = 0;
        sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (mk[j] == 0)
            {
                sum1 += arr[j];
            }
            if (mk[j] == 1)
            {
                sum2 += arr[j];
            }
        }
        if (sum1 == sum / 2 && sum2 == sum / 2)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("SET 1: ");
        for (int i = 0; i < n; i++)
        {
            if (mk[i] == 0)
                printf("%d\t", arr[i]);
        }
        printf("\nSET 2: ");
        for (int i = 0; i < n; i++)
        {
            if (mk[i] == 1)
                printf("%d\t", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Array Can't be Divided into Subsets having equal sum");
    }
    return 0;
}