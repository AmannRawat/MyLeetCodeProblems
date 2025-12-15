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

    // INSERTION BEGINS

    printf("Insertion on the Position--->\n");
    int pos = 4;
    int count = 0;
    struct node *tracer1 = NULL;
    struct node *tracer2 = NULL;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int newdata = 20;
    newnode->data = newdata;
    tracer1 = head;
    while (!(tracer1 == NULL))
    {
        if (count == pos - 1)
        {
            tracer2->next = newnode;
            newnode->next = tracer1->next;
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
    printf("Insertion Before the Position--->\n");
    count = 0;
    struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
    int newdata2 = 50;
    newnode2->data = newdata2;
    tracer1 = head;
    while (!(tracer1 == NULL))
    {
        if (count == pos - 2) // Differece here
        {
            newnode2->next = tracer1->next;
            tracer1->next = newnode2;
            break;
        }
        count++;
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
    printf("Insertion After the Position--->\n");
    count = 0;
    struct node *newnode3 = (struct node *)malloc(sizeof(struct node));
    int newdata3 = 50;
    newnode3->data = newdata3;
    tracer1 = head;
    while (!(tracer1 == NULL))
    {
        if (count == pos) // Differece here
        {
            newnode3->next = tracer1->next;
            tracer1->next = newnode3;
            break;
        }
        count++;
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