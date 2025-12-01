#include <stdio.h>
int main()
{
    int m, n;
    printf("how many rows you want in your array :");
    scanf("%d", &m);
    printf("how many columns you want in your array :");
    scanf("%d", &n);
    int a[m][n], new[n][m];

    printf("Enter array elements :");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            new[i][j] = a[j][i];
        }
    }
    printf("Your Array :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("Transpose Array :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d", new[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}