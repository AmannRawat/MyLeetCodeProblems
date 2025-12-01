#include <stdio.h>
int main()
{
    int a[3][3], sum = 0;
    printf("Enter any values for Array :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i+j==2){
                sum=sum+a[i][j];
            }
        }
    }
    printf("Your res :%d",sum);
}