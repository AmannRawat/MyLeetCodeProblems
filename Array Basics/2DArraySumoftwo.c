#include <stdio.h>
int main()
{
    int a[2][2], b[2][2], new[2][2], sum = 0;
    printf("Enter any values for 1st Array :");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
    printf("Enter any values for 2nd Array :");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            new[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\n");
    printf("Your res Array :\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d", new[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}