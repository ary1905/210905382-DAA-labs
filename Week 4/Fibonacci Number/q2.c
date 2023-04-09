//Program to Find nth fibonacci number using Recursion

#include<stdio.h>

int fibo(int n){
    if (n==1 || n==0)
    {
        return n;
    }
    return (fibo(n - 1) + fibo(n - 2));
}

int main()
{
    int n;
    printf("Enter Number for Generation of fibonacci number:");
    scanf("%d", &n);
    printf("%dth Fibonacci Number is: %d",n, fibo(n));
    return 0;
}
