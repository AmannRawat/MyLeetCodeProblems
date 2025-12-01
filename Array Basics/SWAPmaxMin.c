#include <stdio.h>
int main()
{
    int arr[5], max,min,maxI,minI,temp;
    printf("Enter any 5 values for Array :");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    min = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            maxI=i;
        }
        if (min > arr[i])
        {
            min = arr[i];
            minI=i;
        }    
    }
    temp = arr[maxI];
    arr[maxI] = arr[minI];
    arr[minI] = temp;
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
        printf(" ");
    }
}