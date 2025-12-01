#include<stdio.h>
int main(){
    int arr[5],n,flag=0;
     int arr_len = sizeof(arr) / sizeof(arr[0]);
    printf("Enter any 5 values for Array :");
    for (int i = 0; i < arr_len; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Now enter the value you want to find:");
    scanf("%d",&n);
    for (int i = 0; i < arr_len; i++)
    {
        if(arr[i]==n){
            printf("Your value is at index : %d",i);
            flag++;
        }
    }
    if(flag<1){
        printf("Your value not found");
    }
}