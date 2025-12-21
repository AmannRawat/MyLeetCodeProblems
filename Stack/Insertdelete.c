#include <stdio.h>
int main()
{
    int stack[10], top = -1, choice, value;

    while (1)
    {
        printf("\n1. Push  2. Pop  3. Display  4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        if (choice == 1)
        {
            if (top == 10 - 1)
                printf("Stack Overflow!\n");
            else
            {
                scanf("%d", &stack[++top]);
                printf("%d pushed.\n", stack[top]);
            }
        }
        else if (choice == 2)
        {
            if (top == -1)
                printf("Stack Underflow!\n");
            else
                printf("%d popped.\n", stack[top--]);
        }
        else if (choice == 3)
        {
            if (top == -1)
                printf("Stack is empty!\n");
            else
                for (int i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
            printf("\n");
        }
        else
            printf("Invalid choice!\n");
    }
    return 0;
}
