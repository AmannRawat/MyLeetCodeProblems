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
    int arr[10];
    i=0;
    while (ptr != NULL)
    {
        arr[i]=ptr->data;
        i++;
        ptr=ptr->next;
    }
    int count=i;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count-1; j++)
        {
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
            }
        }
    }
    ptr = head;
    i=0;
    printf("\nNON-Sorted LL----->");
    prnt(&head);
    while (ptr != NULL)
    {
        ptr->data=arr[i];
        i++;
        ptr=ptr->next;
    }
    printf("\nSorted LL----->");
    prnt(&head);
}