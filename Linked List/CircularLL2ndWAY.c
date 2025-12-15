#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        newNode->next = newNode; // Point to itself
        last = newNode;
    } else {
        newNode->next = last->next; // Point to first node
        last->next = newNode;
        last = newNode; // Update last to new node
    }
}

void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;

    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    insertEnd(5);
    insertEnd(10);
    insertEnd(15);
    insertEnd(20);

    display();

    return 0;
}
