#include <stdio.h>
int main()
{
    int a[6] = {1, 2, 3, 4, 5,6};
    for (int i = 0; i < 6/2; i++)
    {
        int temp = a[5-i];
        a[5-i] = a[i];
        a[i] = temp;
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", a[i]);
    }
}