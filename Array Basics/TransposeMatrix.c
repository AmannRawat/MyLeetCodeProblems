#include <stdio.h>
int main()
{
    int m;
    printf("how many rows and columns you want in your array :");
    scanf("%d", &m);
    int a[m][m];

    printf("Enter array elements :");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Your Array :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d", a[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = i+1; j < m; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    printf("Transpose Array :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d", a[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}