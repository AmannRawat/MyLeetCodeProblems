#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head1 = NULL,*head2 = NULL, *ptr = NULL,*ptr2 = NULL;
    int i = 0;
    printf("Enter data for LL 1 --->\n");
    while (i < 3)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data Values :");
        scanf("%d", &(*newnode).data); // Or newnode ->data;
        newnode->next = NULL;
        if (head1 == 0)
        {
            head1 = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->next = newnode;
            ptr = newnode;
        }
        i++;
    }
    printf("Enter data for LL 2 --->\n");
    i=0;
    while (i < 3)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data Values :");
        scanf("%d", &(*newnode).data); // Or newnode ->data;
        newnode->next = NULL;
        if (head2 == 0)
        {
            head2 = newnode;
            ptr2 = newnode;
        }
        else
        {
            ptr2->next = newnode;
            ptr2 = newnode;
        }
        i++;
    }
    int output=0,base=100;
    ptr = head1;
    ptr2 = head2;
    while (ptr!=NULL && ptr2!=NULL)
    {
       output+=(ptr->data-ptr2->data)*base;
       base/=10;
       ptr=ptr->next;
       ptr2=ptr2->next;
    }
    
    printf("\nOutput----->");
    printf("%d",output);
}