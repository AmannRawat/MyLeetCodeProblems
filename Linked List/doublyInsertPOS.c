#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
int main()
{
    int data[] = {2, 4, 6, 8, 10, 16};
    struct node *head = NULL;
    struct node *temp = NULL;
    int i = 0;
    while (i < 6)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        newnode->data = data[i];
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
            temp->prev = NULL;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        i++;
    }

    // INSERTION BEGINS

    printf("Insertion on the Position--->\n");
    int pos = 4;
    int count = 0;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int newdata = 20;
    newnode->data = newdata;
    temp = head;
    while (temp != NULL)
    {
        if (count == pos - 2)
        {
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            break;
        }
        count++;
        temp = temp->next;
    }
    temp = head;
    while (!(temp == NULL))
    {
        printf("[%d]---", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    temp = head;
}