
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int arr[100];

int sum_digit(int x)
{
    int sum = 0;
    while (x > 0)
    {
        int rem = x % 10;
        sum += rem;
        x = x / 10;
    }
    return sum;
}

int mul_digit(int x)
{
    int mul = 1;
    while (x > 0)
    {
        int rem = x % 10;
        mul *= rem;
        x = x / 10;
    }
    return mul;
}

int getDigit(int x)
{
    int rem = x % 10;
    return rem;
}

int getRev(int x)
{
    int rev = 0;
    while (x > 0)
    {
        int rem = x % 10;
        rev = rev * 10 + rem;
        x = x / 10;
    }
    return rev;
}

int final_sum(int n, int a[n][n], int b)
{
    int sum = 0;
    int i = 1;
    b = getRev(b);
    while (b > 0)
    {
        int x = getDigit(b);
        sum += a[i][x];
        i++;
        b = b / 10;
    }
    return sum;
}

int main()
{
    int n, a = 0, temp, rev = 0, sum = 0, j = 0, mul = 1, min, p;
    int count = 0;
    printf("Enter Number of Persons:\n");
    scanf("%d", &n);
    int job[n][n];
    int final[n];
    for (int i = 1; i <= n; i++)
    {
        a = a * 10 + i;
    }
    temp = a;
    while (temp > 0)
    {
        int rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }
    sum = sum_digit(a);
    mul = mul_digit(a);
    while (a != rev + 1)
    {
        if (sum_digit(a) == sum && mul_digit(a) == mul)
        {
            count++;
            arr[j++] = a;
        }
        a++;
    }
    printf("Enter Job Matrix Elements:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            scanf("%d", &job[i][k]);
        }
    }
    for (int i = 0; i < j; i++)
    {
        final[i] = final_sum(n, job, arr[i]);
    }
    min = final[0];
    p = 0;
    for (int i = 1; i < j; i++)
    {
        if (min > final[i])
        {
            min = final[i];
            p = i;
        }
    }
    printf("The Minimum Job Cost is %d and the Order is %d", min, arr[p]);
    printf("\nOperation Count is: %d\n", count);
    return 0;
}
