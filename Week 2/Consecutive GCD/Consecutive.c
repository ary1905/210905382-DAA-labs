#include <stdio.h>
#include <stdlib.h>
int Consecutive(int num, int num1)
{
    int count = 0;
    int t = num < num1 ? num : num1;
    while (t != 0)
    {
        if (num % t == 0 && num1 % t == 0)
        {
            printf("Count: %d\n", count);
            return t;
        }
        t--;
        count++;
    }
}

int main()
{
    int m, n, t;
    printf("Enter the Numbers whose GCD is to be Calculated:\n ");
    scanf("%d %d", &m, &n);
    printf("m+n:%d\n", m + n);
    int gcd = Consecutive(m, n);
    printf("GCD: %d", gcd);
    return 0;
}