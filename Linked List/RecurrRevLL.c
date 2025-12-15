#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *recurrRev(struct node **head, struct node *temp) {
    if (temp == NULL || temp->next == NULL) {
        *head = temp; 
        return temp;
    }
    recurrRev(head, temp->next);
    struct node *ptr=temp->next;
    ptr->next = temp;
    temp->next = NULL;     
}
int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    int i = 0, stack[10], top = -1;
    while (i < 6)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        i++;
    }
    printf("Before--->");
    temp = head;
    while (!(temp == NULL))
    {
        printf("[%d]---", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    temp=head;
    recurrRev(&head,head);
    printf("After--->");
    temp = head;
    while (!(temp == NULL))
    {
        printf("[%d]---", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}