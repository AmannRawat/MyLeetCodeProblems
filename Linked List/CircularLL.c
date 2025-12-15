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
        // newnode->next = NULL;
        // newnode->next = head;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
            ptr = newnode;
        }else{
            newnode->next = head;
            ptr->next=newnode;
            ptr=newnode;
        }
        i++;
    }
    printf("%d \n", ptr->next->data);//For checking if last node is pointing towards head
    ptr=head;
    while (ptr->next!=head ) {
        printf("[%d]---", ptr->data);
        ptr = ptr->next;
    }
    printf("[%d]---", ptr->data);
}