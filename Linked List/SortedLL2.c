#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
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
    printf("\nNON-Sorted LL----->");
    prnt(&head);
    //CHAT GPT WAY
    struct node *current = NULL;
    struct node *index = NULL;
    int temp;
    for (current = head; current != NULL; current = current->next)
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if (current->data > index->data)
            {
                // Swap the data
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
    // OR MY WAY
    // ptr = head;
    // struct node *ptr2 = head;
    // while (ptr != NULL)
    // {
    //     while (ptr != NULL)
    //     {
    //         if (ptr->data < ptr2->data)
    //         {
    //             int temp = ptr->data;
    //             ptr->data = ptr2->data;
    //             ptr2->data = temp;
    //         }
    //         ptr2 = ptr;
    //         ptr = ptr->next;
    //     }
    //     ptr = head;
    //     ptr2 = head;
    //     ptr = ptr->next;
    // }
    ptr = head;
    printf("\nSorted LL----->");
    prnt(&head);
}