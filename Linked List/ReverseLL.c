#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head=NULL;
    struct node *temp=NULL;
    int i=0,stack[10],top=-1;
    while(i<6){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else
        {
            temp->next=newnode;
            temp=temp->next;
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
    temp=head;
    while(temp!=NULL){
        top++;
        stack[top]=temp->data;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=stack[top];
        top--;
        temp=temp->next;
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