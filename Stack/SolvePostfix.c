#include <stdio.h>
void push(char stack[], int *top, char val)
{
    (*top)++;
    stack[*top] = val;
}
char pop(char stack[], int *top)
{
    char val = stack[*top];
    (*top)--;
    return val;
}
char solve(char stack[], int *top)
{
    char val = stack[*top];
    (*top)--;
    return val;
}
int prece(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0; // lowest precedence
    }
}

int associa(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1; // left to right
    case '*':
    case '/':
        return 1;
    case '^':
        return 2; // right to left
    default:
        return 0; // lowest
    }
}

int main()
{
    char string[] = "k+l-m*n";
    char output[50];
    int idx = -1;
    char stack[20];
    int top = -1;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= '0' && string[i] <= '9'))
        {
            idx++;
            output[idx] = string[i];
        }
        else if (string[i] == '(')
        {
            push(stack, &top, string[i]);
        }
        // Closing bracket
        else if (string[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                idx++;
                output[idx] = pop(stack, &top);
            }
            if (top != -1 && stack[top] == '(')
                pop(stack, &top); // remove '('
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                   ((prece(stack[top]) > prece(string[i])) ||
                    (prece(stack[top]) == prece(string[i]) && associa(string[i]) == 1)))
            {
                idx++;
                output[idx] = pop(stack, &top);
            }
            push(stack, &top, string[i]);
        }
    }
    while (top != -1)
    {
        idx++;
        output[idx] = pop(stack, &top);
    }
    output[idx + 1] = '\0'; // null-terminate the string
    printf("Postfix Expression: %s\n", output);
    int k=2,l=5,m=9,n=4;
    printf("Now solving Postfix expression");
    for (int i = 0; output[i] != '\0'; i++)
    {
        if ((output[i] >= 'a' && output[i] <= 'z') || (output[i] >= 'A' && output[i] <= 'Z') || (output[i] >= '0' && output[i] <= '9'))
        {
            push(stack, &top, output[i]);
        }
        else if (output[i] == '+' || output[i] == '-' || output[i] == '*' || output[i] == '/' || output[i] == '^')
        {

        }
    }
}