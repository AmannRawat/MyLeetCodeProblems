#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *head = NULL, *temp = NULL;
    int i = 0, newdata;
    do
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter Data:");
        scanf("%d", &newdata);
        newnode->data = newdata;
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
    } while (i < 6);
    temp = head;
    printf("BEFORE LL ---->");
    while (temp != NULL)
    {
        printf("[%d]--->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    // rev start here
    temp = head->next;
    // printf("[%d]--->", temp->data);
    struct Node *curr = head;
    head = NULL; // HEAD is now prev = NULL
    temp = NULL; // temp = next

    while (curr != NULL)
    {
        temp = curr->next; // store next
        curr->next = head; // reverse link to prev          //Optimised Way
        head = curr;       // move prev forward
        curr = temp;       // move curr forward
    }
    // while (temp->next != NULL)           //PHELE Mene Ese Kiya
    // {
    //     if (head == curr)
    //     {
    //         curr->next = NULL;
    //         curr = temp;
    //         temp = temp->next;
    //         continue;
    //     }
    //     curr->next = head;
    //     head = curr;
    //     curr = temp;
    //     temp = temp->next;
    // }
    // curr->next = head;
    // head = curr;
    // curr = temp;
    // curr->next = head; // For Last Node
    // head = curr;
    temp = head;
    printf("After LL ---->");
    while (temp != NULL)
    {
        printf("[%d]--->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}