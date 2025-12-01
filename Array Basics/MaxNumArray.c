#include <stdio.h>
int main()
{
    int arr[5], max,min;
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    printf("Enter any 5 values for Array :");
    for (int i = 0; i < arr_len; i++)
    {
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    min = arr[0];
    for (int i = 0; i < arr_len; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
        
    }
    printf("Maximum value is : %d\n",max);
    printf("Minimum value is : %d\n",min);
}