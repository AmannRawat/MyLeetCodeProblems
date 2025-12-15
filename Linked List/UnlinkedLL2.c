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
    struct node *temp2 = NULL;
    struct node *store = NULL;

    // ONE WAY----->

    // struct node *store2 = NULL;
    // temp = head;
    // temp2 = head->next;
    // head=head->next;
    // while (temp != NULL && temp2 != NULL) 
    // {
    //     if (temp2->next != NULL)
    //     {
    //         store = temp->next->next;
    //         store2 = temp2->next->next;
    //         temp->next = temp->next->next->next;
    //     }
    //     else
    //     {
    //         store = NULL;
    //         temp->next = NULL;
    //     }
    //     temp2->next = temp;
    //     temp = store;
    //     temp2 = store2;
    // }

    // SECOND WAY --->   //Not Right loosing 4 and 6 debug later for practice
    temp = head;
    temp2 = head->next;
    head=head->next;
    store=NULL;
    while (temp != NULL && temp2 != NULL) {
        store=temp->next->next;
        temp->next=store;
        temp2->next=temp;
        temp=store;
        if(temp != NULL)
            temp2=temp->next;
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