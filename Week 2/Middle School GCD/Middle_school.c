#include <stdio.h>
#include <stdlib.h>

void prime_factors(int m, int n)
{
    int a[20];
    int b[20];
    int p = 0;
    int q = 0;
    int x = m;
    int y = n;
    for (int i = 2; m > 1 && n > 1; i++)
    {
        while (m % i == 0)
        {
            a[p] = i;
            m = m / i;
            p++;
        }
        while (n % i == 0)
        {
            b[q] = i;
            n = n / i;
            q++;
        }
    }
    int c[20];
    int r = 0;

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if (a[i] == b[j])
            {
                c[r] = a[i];
                r++;
                a[i] = 0;
                b[j] = 0;
            }
        }
    }
    int gcd = 1;
    for (int i = 0; i < r; i++)
    {
        gcd *= c[i];
    }
    printf("GCD of %d and %d is: %d\n", x, y, gcd);
}

int main()
{
    int m, n;
    printf("Enter two numbers whose gcd is to be found\n");
    scanf("%d %d", &m, &n);
    prime_factors(m, n);
    return 0;
}