#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insrte(struct node **head, struct node **ptr)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data Values :");
    scanf("%d", &(*newnode).data); // Or newnode ->data;
    newnode->next = NULL;
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
void deltAtBegin(struct node **head, struct node **ptr)
{
    struct node *temp = *head;
    printf("%d is Deleted\n", **head);
    *ptr = (*head)->next;
    *head = *ptr;
    free(temp);
}
void deltAtLast(struct node **head)
{
    struct node *temp = *head;
    if (*head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }
    struct node *p = NULL;
    while (temp->next != NULL) // Stop at the last node
    {
        p = temp;
        temp = temp->next;
    }
    free(temp);
    p->next = NULL;

    printf("Last node deleted successfully.\n");
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
        printf("Enter Choice \n 1-Insert Values 2-Deletion At Beginning 3-Deletion At End 4-Print\n");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4)
        {
            if (choice == 1)
            {
                insrte(&head, &ptr);
            }
            if (choice == 2)
            {
                deltAtBegin(&head, &ptr);
            }
            else if (choice == 3)
            {
                deltAtLast(&head);
            }
            else if (choice == 4)
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