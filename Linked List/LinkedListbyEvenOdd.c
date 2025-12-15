#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int EvenorOdd(int val)
{
    if (val % 2 == 0)
        return 1;
    else
        return 0;
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
    int i = 0;
    while (i < 6)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data Values :");
        scanf("%d", &(*newnode).data); // Or newnode ->data;
        newnode->next = NULL;
        if (head == 0)
        {
            head = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->next = newnode;
            ptr = newnode;
        }
        i++;
    }
    ptr = head;
    struct node *ptreven = NULL;
    struct node *ptrodd = NULL;
    struct node *evenhead = NULL;
    struct node *oddhead = NULL;
    while (ptr != NULL)
    {
        struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
        newnode2->data = ptr->data;
        newnode2->next = NULL;
        if (EvenorOdd(ptr->data))
        { // For Even
            if (evenhead == NULL)
            {
                evenhead = newnode2;
                ptreven = newnode2;
            }
            else
            {
                ptreven->next = newnode2;
                ptreven = newnode2;
            }
        }
        else
        {
            if (oddhead == NULL)
            {
                oddhead = newnode2;
                ptrodd = newnode2;
            }
            else
            {
                ptrodd->next = newnode2;
                ptrodd = newnode2;
            }
        }
        ptr = ptr->next;
        // ptr2 = ptr2->next;
    }
    printf("Your LL----->");
    prnt(&head);
    printf("Even LL----->");
    prnt(&evenhead);
    printf("Odd LL----->");
    prnt(&oddhead);
}