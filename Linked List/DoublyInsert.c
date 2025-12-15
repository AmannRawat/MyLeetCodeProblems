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
void insrteAtBegin(struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Your data :");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        newnode->next = *head;
        *head = newnode;
    }
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
void prntFromLast(struct node **ptr)
{
    struct node *temp = *ptr;
    while (temp != NULL)
    {
        printf("[%d]---", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
int main()
{
    struct node *head = NULL, *ptr = NULL;
    int i, choice;

    do
    {
        printf("Enter Choice \n 1-Insertion 2-Insertion At Beginning 3-Print 4-Print In Reverse\n");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4)
        {
            if (choice == 1)
            {
                insrte(&head, &ptr);
            }
            else if (choice == 2)
            {
                insrteAtBegin(&head);
            }
            else if (choice == 3)
            {
                prnt(&head);
            }
            else if (choice == 4)
            {
                prntFromLast(&ptr);
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