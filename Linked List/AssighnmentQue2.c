#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    // struct node *prev;
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
        *ptr = newnode;
    }
}
void insrteByArranging(struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Your data :");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    struct node *ptr = *head;
    struct node *smallData = NULL;
    struct node *ptrSmall = NULL;
    struct node *largData = NULL;
    struct node *ptrLarg = NULL;
    while (ptr != NULL)
    {
        if (ptr->data <= newnode->data)
        {
            if (smallData == NULL)
            {
                smallData = ptr;
                ptrSmall = ptr;
            }
            else
            {
                ptrSmall->next = ptr;
                ptrSmall = ptr;
            }
        }
        else
        {
            if (largData == NULL)
            {
                largData = ptr;
                ptrLarg = ptr;
            }
            else
            {
                ptrLarg->next = ptr;
                ptrLarg = ptr;
            }
        }
        ptr = ptr->next;
    }
    // tail to NULL
    if (ptrLarg != NULL)
        ptrLarg->next = NULL;
    if (ptrSmall != NULL)
        ptrSmall->next = NULL;

    if (smallData != NULL)
    {
        ptr = smallData;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = largData;
        *head = smallData;
    }
    else
    {
        newnode->next = largData;
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
int main()
{
    struct node *head = NULL, *ptr = NULL;
    int i, choice;

    do
    {
        printf("Enter Choice \n 1-Insertion 2-Rearrange 3-Print\n");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3)
        {
            if (choice == 1)
            {
                insrte(&head, &ptr);
            }
            else if (choice == 2)
            {
                insrteByArranging(&head);
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