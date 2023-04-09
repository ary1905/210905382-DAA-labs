//Program to Implement Tower of Hanoi Problem Recursively

#include <stdio.h>
#include <stdlib.h>

void tower_of_hanoi(char* source, char* aux, char* dest, int n)
{
    if (n == 1)
    {
        printf("Move Disk 1 from %s to %s\n", source, dest);
        return;
    }
    tower_of_hanoi(source, dest, aux, n - 1);
    printf("Move disk %d from %s to %s\n", n, source, dest);
    tower_of_hanoi(aux, source, dest, n - 1);
}

int main()
{
    int n;
    printf("Enter Number of Disks:");
    scanf("%d", &n);
    tower_of_hanoi("Source", "Auxillary", "Destination", n);
    return 0;
}
