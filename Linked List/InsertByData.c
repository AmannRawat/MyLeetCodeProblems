#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int perform(struct node **head, int pos)
{
    int count = 0;
    struct node *tracer1 = NULL;
    struct node *tracer2 = NULL;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int newdata = 0;
    newnode->data = newdata;
    tracer1 = *head;
    if (pos == 0)
    {
        newnode->next = *head;  // Insert at the head
        *head = newnode;  // Update the head pointer
        return 0;
    }
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
    int data[] = {2, 4, 6, 8, 10, 16, 8, 8, 6, 10};
    struct node *head = NULL;
    struct node *temp = NULL;
    int i = 0;
    while (i < 10)
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

    printf("Insertion on First Data--->\n");
    int val = 6;
    int pos = 0;
    temp = head;
    while (!(temp == NULL))
    {
        pos++;
        if (temp->data == val)
        {
            break;
        }
        temp = temp->next;
    }
    perform(&head, pos);
    prnt(&head);
    //....
    printf("Insertion on last the Data--->\n");
    int POS = 0;
    val = 8;
    pos = 0;
    temp = head;
    while (!(temp == NULL))
    {
        pos++;
        if (temp->data == val)
        {
            POS = pos;
        }
        temp = temp->next;
    }
    if (POS == 0)
        printf("Value not found\n");
    perform(&head, POS);
    prnt(&head);
    // //.....
    printf("Insertion on Middle Data among odd numbers of data--->\n");
    int c = 0;
    POS = 0;
    val = 8;
    pos = 0;
    // For counting how many data
    temp = head;
    while (!(temp == NULL))
    {
        if (temp->data == val)
        {
            c++;
        }
        temp = temp->next;
    }
    int middlePos;
    if (c % 2 != 0)
    {
        middlePos = (c + 1) / 2; // Ceil of Half Formula (For odd occurrences)
    }
    else
    {
        middlePos = c / 2 + 1; // For even occurrences, take the second occurrence
    }
    temp = head;
    c = 0;
    while (!(temp == NULL))
    {
        pos++;
        if (temp->data == val)
        {
            c++;
            if (c == middlePos)
            {
                POS = pos;
                break;
            }
        }
        temp = temp->next;
    }
    printf("%d\n", POS);
    if (POS == 0)
        printf("Value not found\n");
    perform(&head, POS);
    prnt(&head);
}