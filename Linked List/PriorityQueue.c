#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void insrte(struct node **head, struct node **ptr)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Your data :");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    // newnode->prev=NULL;
    if (*head == NULL)
    {
        *head = newnode;
        *ptr = newnode;
    }
    else
    {
        (*ptr)->next = newnode;
        newnode->prev = *ptr;
        *ptr = newnode;
    }
}
void serve(struct node **head)
{
    struct node *temp = *head;
    int smallest = temp->data;
    while (temp != NULL)
    {
        if (temp->data < smallest)
        {
            smallest = temp->data;
        }
        temp = temp->next;
    }
    temp = *head;
    while (temp != NULL)
    {
        if (temp->data == smallest)
        {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                *head = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
            break;
        }
        temp = temp->next;
    }
    printf("%d is Served\n", smallest);
}
void prnt(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        printf("[%d]---", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node *head = NULL, *ptr = NULL;
    int i, choice;

    do
    {
        printf("Enter Choice \n 1-Insertion 2-Serve 3-Print\n");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3)
        {
            if (choice == 1)
            {
                insrte(&head, &ptr);
            }
            else if (choice == 2)
            {
                serve(&head);
            }
            else if (choice == 3)
            {
                prnt(&head);
            }
        }
        else
        {
            printf("Enter Valid Choice.....\n");
        }
        printf("Enter 1 if you wanna contniue :");
        scanf("%d", &i);
    } while (i == 1);
}