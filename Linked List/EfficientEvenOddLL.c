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
    printf("Your LL----->");
    prnt(&head);
     //CHAT GPT WAY
     struct node *current = NULL;
     struct node *index = NULL;
     int temp;
     for (current = head; current != NULL; current = current->next)
     {
         for (index = current->next; index != NULL; index = index->next)
         {
             if (EvenorOdd(index->data) && !EvenorOdd(current->data))
             {
                 // Swap if current is odd and index is even
                 temp = current->data;
                 current->data = index->data;
                 index->data = temp;
             }
         }
     }
     // OR MY WAY
    // ptr = head;
    struct node *ptr2 = head;
    // int temp;
    // for (int i = 0; i < 6; i++)
    // {
    //     while (ptr != NULL)
    //     {
    //         if (EvenorOdd(ptr->data))
    //         {
    //             temp = ptr->data;
    //             ptr->data = ptr2->data;
    //             ptr2->data = temp;
    //         }
    //         ptr2 = ptr;
    //         ptr = ptr->next;
    //     }
    //     ptr = head;
    //     ptr2 = head;
    // }
    ptr = head;
    ptr2 = head;
    struct node *Oddhead = NULL;
    while (ptr != NULL)
    {
        if (!(EvenorOdd(ptr->data)))
        {
            Oddhead=ptr;
            ptr2->next=NULL;
            break;
        }
        ptr2 = ptr;
        ptr = ptr->next;
    }
    printf("Even LL----->");
    prnt(&head);
    printf("Odd LL----->");
    prnt(&Oddhead);
}