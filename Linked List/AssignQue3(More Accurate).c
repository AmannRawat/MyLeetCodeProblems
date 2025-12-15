#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void prnt(struct node *head) {
    while (head != NULL) {
        printf("[%d]---", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int linkedListToNumber(struct node *head) {
    int num = 0;
    while (head != NULL) {
        num = num * 10 + head->data;
        head = head->next;
    }
    return num;
}

void insert(struct node **head, struct node **ptr, int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
        *ptr = newnode;
    } else {
        (*ptr)->next = newnode;
        *ptr = newnode;
    }
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    struct node *ptr1 = NULL, *ptr2 = NULL;
    int i, value;

    printf("Enter data for LL 1 --->\n");
    for (i = 0; i < 3; i++) {
        printf("Enter data: ");
        scanf("%d", &value);
        insert(&head1, &ptr1, value);
    }

    printf("Enter data for LL 2 --->\n");
    for (i = 0; i < 3; i++) {
        printf("Enter data: ");
        scanf("%d", &value);
        insert(&head2, &ptr2, value);
    }

    int num1 = linkedListToNumber(head1);
    int num2 = linkedListToNumber(head2);
    int result = num1 - num2;

    printf("\nLL1: ");
    prnt(head1);
    printf("LL2: ");
    prnt(head2);
    printf("Result of subtraction: %d\n", result);

    return 0;
}
