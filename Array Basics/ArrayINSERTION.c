#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4,5};
    int value=10;
    int pos=3;
    pos--;
    for(int i=5;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=value;
     for(int i=0;i<6;i++){
        printf("%d",arr[i]);
        printf(" ");
    }
}