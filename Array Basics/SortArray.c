#include <stdio.h>
int main()
{
    int arr[5];
    int temp;
    printf("Enter any 5 values for Array :");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

      for (int x = 0; x < 5-1; x++)
    {
        for (int i = 0; i < 5-1; i++)
        {

            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
        printf(" ");
    }
}