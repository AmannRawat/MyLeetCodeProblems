#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    int i = 0;
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
    temp = head;
    struct node *mid = head;
    while (temp != NULL && temp->next != NULL)  //For Even and For Odd condition respectively
    {
        mid = mid->next;
        temp = temp->next->next;
    }
    temp = mid;
    mid = NULL;
    struct node *store = NULL;
    while (temp != NULL)
    {
        store = temp->next;
        temp->next = mid;
        mid = temp;
        temp = store;
    }
    // printf("[%d]---", mid->data);
    struct node *store2 = NULL;
    temp = head;
    while (mid->next != NULL)
    {
        store = temp->next;
        temp->next = mid;
        store2 = mid->next;
        temp=store;
        mid->next = store;
        mid = store2;
    }
    printf("After--->");
    temp = head;
    while (!(temp == NULL))
    {
        printf("[%d]---", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}