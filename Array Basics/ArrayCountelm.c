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
    for (int i = 0; i < 5; i++)
    {
        int count = 0, Counted = 0;
        for (int k = 0; k < i; k++)
        {
            if (arr[i] == arr[k])
            {
                Counted = 1;
                break;
            }
        }
        if (Counted)
            continue;

        for (int j = 0; j < 5; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        printf("The %d is coming %d times\n", arr[i], count);
    }
}