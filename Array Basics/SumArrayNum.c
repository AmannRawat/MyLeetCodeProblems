#include<stdio.h>
int main(){
    int a[5],sum=0;
    printf("Enter any 5 values for 1st Array :");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
       sum+=a[i];
    }
    printf("Sum :%d",sum);
}