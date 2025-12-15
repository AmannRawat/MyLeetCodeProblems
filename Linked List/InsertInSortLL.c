#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert_sorted(struct node **head) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data value: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    // If list is empty or new node should be placed at the beginning
    if (*head == NULL || (*head)->data >= newnode->data) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    // Find correct insertion point
    struct node *current = *head;
    while (current->next != NULL && current->next->data < newnode->data) {
        current = current->next;
    }

    // Insert new node
    newnode->next = current->next;
    current->next = newnode;
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
    struct node *head = NULL;
    int i, choice;

    do
    {
        printf("Enter Choice \n 1-Insertion 2-Print\n");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 2)
        {
            if (choice == 1)
            {
                insert_sorted(&head);
            }
            else if (choice == 2)
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