#include <stdio.h>
int main()
{
    int a[2][2], sum1 = 0,sum2=0;
    printf("Enter any values for Array :\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if(i==j){
                sum1=sum1+a[i][j];
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i+j==2){
                sum2=sum2+a[i][j];
            }
        }
    }
    printf("Sum of 1st Diagonal:%d\n",sum1);
    printf("Sum of 2nd Diagonal:%d\n",sum2);
}