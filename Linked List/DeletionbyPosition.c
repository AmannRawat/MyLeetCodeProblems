#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
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
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        i++;
    }

    // DELETION BEGINS

    printf("Deletion on the Position--->\n");
    int pos = 4;
    int count = 0;
    struct node *tracer1 = NULL;
    struct node *tracer2 = NULL;
    tracer1 = head;
    while (!(tracer1 == NULL))
    {
        if (count == pos - 1)
        {
            tracer2->next = tracer1->next;
            free(tracer1);
            break;
        }
        count++;
        tracer2 = tracer1;
        tracer1 = tracer1->next;
    }
    temp = head;
    while (!(temp == NULL))
    {
        printf("[%d]---", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    //....
    printf("Deletion Before the Position--->\n");
    count = 0;
    tracer1 = head;
    while (!(tracer1 == NULL))
    {
        if (count == pos - 2) // Differece here
        {
            tracer2->next = tracer1->next;
            free(tracer1);
            break;
        }
        count++;
        tracer2 = tracer1;
        tracer1 = tracer1->next;
    }
    temp = head;
    while (!(temp == NULL))
    {
        printf("[%d]---", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    //.....
    printf("Deletion After the Position--->\n");
    pos=2;
    count = 0;
    tracer1 = head;
    while (!(tracer1 == NULL))
    {
        if (count == pos) // Differece here
        {
            tracer2->next = tracer1->next;
            free(tracer1);
            break;
        }
        count++;
        tracer2 = tracer1;
        tracer1 = tracer1->next;
    }
    temp = head;
    while (!(temp == NULL))
    {
        printf("[%d]---", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}