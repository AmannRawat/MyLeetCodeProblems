#include <stdio.h>

int main() {
    int n, count;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int RepeatNhihua = 0;

    for (int i = 0; i < n; i++) {
        count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j] && i != j) {
                count++;
                break;
            }
        }
        if (count == 0) {
            RepeatNhihua++;
            if (RepeatNhihua == 2) {
                printf("Second non-repeating element: %d\n", arr[i]);
                return 0;
            }
        }
    }
    printf("Ni mila non-repeating element.\n");
    return 0;
}
