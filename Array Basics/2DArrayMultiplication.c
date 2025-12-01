#include <stdio.h>
int main()
{
    int new[2][2];
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{1, 2}, {3, 4}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            new[i][j] = a[i][j] * b[j][i] + a[i][j] * b[j][i];
        }
    }

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