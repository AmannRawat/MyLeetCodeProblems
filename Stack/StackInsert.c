#include <stdio.h>
int main()
{
    int stack[10], top = -1, choice, value;

    while (1)
    {
        printf("Enter Value :");
        scanf("%d", &value);
        if (top == 10 - 1)
            printf("Stack Overflow!\n");
        else
        {
            ++top;
            stack[top]=value;
            // scanf("%d", &stack[++top]);
            // scanf("%d", &stack[top++]);//GARBAGE VALUE
            printf("%d pushed.\n", stack[top]);
        }
        for (int i = 0; i <= top; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}
