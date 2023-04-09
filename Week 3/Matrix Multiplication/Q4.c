#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row1, col1, row2, col2, i, j, k;
    int count = 0;
    printf("Enter Rows and Columns of the First array:\n");
    scanf("%d %d", &row1, &col1);
    printf("Enter Rows and Columns of the Second array:\n");
    scanf("%d %d", &row2, &col2);
    if (col1 != row2)
    {
        printf("Cannot Multiply");
        return 0;
    }
    int arr1[row1][col1];
    int arr2[row2][col2];
    int mul[row1][col2];
    printf("Enter Elements of the First Matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter Elements of the Second Matrix:\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < col1; k++)
            {
                count++;
                mul[i][j] = mul[i][j] + arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("Multiplied Array:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }
    printf("\nCount: %d\n", count);
    return 0;
}