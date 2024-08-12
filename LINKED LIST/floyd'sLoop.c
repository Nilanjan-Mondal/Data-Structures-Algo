#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int detectLoop(Node* head) {
    Node *slow = head, *fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;    

        if (slow == fast) return 1;

    }
    return 0;
}

void createLoop(Node* head, int position) {
    if (position == 0) return;

    Node* temp = head;
    Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    if (loopNode != NULL) {
        temp->next = loopNode; 
    }
}

int main() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);
    Node* fifth = createNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    createLoop(head, 2);

    if (detectLoop(head)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}
