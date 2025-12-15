#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insrteAtBegin(struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data Values :");
    scanf("%d", &(*newnode).data); // Or newnode ->data;
    newnode->next = NULL;
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
        printf("Enter Choice \n 1-Insertion 2-Insertion At Beginning 3-Print\n");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3)
        {
            if (choice == 1)
            {
                insrte(&head,&ptr);
            }
            else if (choice == 2)
            {
                insrteAtBegin(&head);
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