#include <stdio.h>

int main()
{
    int matrix[10][10], rows, cols;
    printf("Rows and columns btao: ");
    scanf("%d%d", &rows, &cols);
    printf("elements dalo matrix mai:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][cols - 1 - j];
            matrix[i][cols - 1 - j] = temp;
        }
    }

    printf("Naya matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
