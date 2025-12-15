#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
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
        }else{
            ptr->next=newnode;
            ptr=newnode;
        }
        i++;
    }
    ptr=head;
    while (ptr != NULL) {
        printf("[%d]---", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}