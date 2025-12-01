#include<stdio.h>
int main(){
    int a[5],b[5];
    printf("Enter any 5 values for 1st Array :");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter any 5 values for 2nd Array :");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&b[i]);
    }
    int sum[5];
    for (int i = 0; i < 5; i++)
    {
       sum[i]=a[i]+b[i];
    }
    printf("Sum Array :");
     for (int i = 0; i < 5; i++)
    {
        printf("%d",sum[i]);
        printf(" ");
    }
}