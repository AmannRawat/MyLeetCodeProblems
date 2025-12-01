#include <stdio.h>
int main()
{
    int arr[5], count;
    int temp;
    printf("Enter any 5 values for Array :");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int x = 0; x < 5; x++)
    {
        count = 0;
        int Counted = 0;
        for (int j = 0; j < x; j++)
        {
            if (arr[x] == arr[j])
            {
                Counted = 1;
                break;
            }
        }

        if (Counted)
            continue;

        for (int i = 0; i < 5; i++)
        {

            if (arr[x] == arr[i])
            {
                count++;
            }
        }
        if (count > 1)
        {
            printf("%d is occuring %d times\n", arr[x], count);
        }
    }
}