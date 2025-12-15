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
    struct node *head=NULL,*ptr=NULL;
    int i=0;
    while (i < 5)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data Values :");
        scanf("%d", &(*newnode).data); // Or newnode ->data;
        newnode->next = NULL;
        if (head == 0)
        {
            head = newnode;
            ptr = newnode;
            ptr->prev=NULL;
        }else{
            ptr->next=newnode;
            newnode->prev=ptr;
            ptr=newnode;
        }
        i++;
    }
    struct node *ptr2=NULL;
    ptr=head;
    while (ptr != NULL) {
        printf("[%d]---", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}