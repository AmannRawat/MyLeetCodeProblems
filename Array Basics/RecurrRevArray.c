#include <stdio.h>

void reverse(int arr[], int start, int end) {
    if (start >= end) 
         return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse(arr, start + 1, end - 1);
}

void findMaxMin(int arr[], int size, int index, int *max, int *min) {
    if (index == size)
        return;
    if (arr[index] > *max)
        *max = arr[index];
    if (arr[index] < *min)
        *min = arr[index];
    findMaxMin(arr, size, index + 1, max, min);
}
int main() {
    int arr[5], max, min;
    printf("5 elements Dede: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    max = min = arr[0];
    reverse(arr, 0, 4);
    printf("Array reverse hogya: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    findMaxMin(arr, 5, 0, &max, &min);
    printf("Maximum : %d\n", max);
    printf("Minimum : %d\n", min);

    return 0;
}
