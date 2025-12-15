#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    char proc;
    struct node *next;
};
int main()
{
    struct node *head = NULL, *ptr = NULL, *temp = NULL;
    int i = 0, time = 0;
    while (i < 5)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        // Flush newline before reading char
        getchar(); //<-- This eats up the '\n'
        printf("Enter Process ID (e.g: A, B): ");
        scanf("%c", &newnode->proc);
        printf("Enter Process Burst Time: ");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = newnode;
            newnode->next = head;
            ptr = newnode;
        }
        else
        {
            newnode->next = head;
            ptr->next = newnode;
            ptr = newnode;
        }
        i++;
    }
    printf("Now Enter Process time in 1 Quantum period:");
    scanf("%d", &time);
    ptr = head;
    struct node *prev = NULL;
    while (i > 0)
    {
        if (ptr->data > 0)
        {
            if (ptr->data <= time)
            {
                printf("%c is processed completely!\n", ptr->proc);
                i--;
                if (ptr == ptr->next)
                {
                    free(ptr);
                    head = NULL;
                    break;
                }
                else
                {
                    if (ptr == head)
                        head = head->next;

                    temp = ptr;
                    prev->next = ptr->next;
                    ptr = ptr->next;
                    free(temp);
                    continue;
                }
            }
            else
            {
                printf("%c is partially processed, remaining: %d\n", ptr->proc, ptr->data - time);
                ptr->data -= time;
            }
        }

        prev = ptr;
        ptr = ptr->next;
    }

    printf("All processes completed!\n");
    return 0;
}