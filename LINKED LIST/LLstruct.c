#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} node;

node* createLinkedList() {
    int n, value;
    node *head = NULL, *temp, *newNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (node*) malloc(sizeof(node));
        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; 
            temp = head;
        } else {
            temp->next = newNode; 
            temp = newNode;
        }
    }
    return head; 
}

node* insertAtFirst(node* head, int value) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = value;
    newNode->next = head;
    head = newNode;
    return head;
}

node* insertAtLast(node* head, int value) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL) return newNode; 
    node* temp = head;
    while (temp->next != NULL) temp = temp->next; 

    temp->next = newNode; 
    return head;
}

node* insertAtAny(node* head, int value, int position) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = value;

    if (position == 1) {
        newNode->next = head;
        return newNode; 
    }

    node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

node* deleteFromFirst(node* head) {
    head = head->next;
    return head;
}

node* deleteFromLast(node* head) {
    node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

node* deleteFromAny(node* head, int value) {
    if (head == NULL) return NULL;
    node* current = head;
    while (current->next != NULL) {
        if (current->next->val == value) {
            current->next = current->next->next; 
            return head;
        }
        current = current->next;
    }
    return head;
}

void display(node* temp) {
    if (temp == NULL) {
        printf("\nLL is empty");
    }
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

int main() {
    node* head = createLinkedList(); 

    int value, position;

    printf("\nEnter value to insert at the beginning: ");
    scanf("%d", &value);
    head = insertAtFirst(head, value); 

    printf("\nEnter value to insert at the end: ");
    scanf("%d", &value);
    head = insertAtLast(head, value); 

    printf("\nEnter value to insert at any position: ");
    scanf("%d", &value);
    printf("Enter the position: ");
    scanf("%d", &position);
    head = insertAtAny(head, value, position); 

    display(head); 

    head = deleteFromFirst(head);
    printf("\nAfter Deleting head LL = ");
    display(head);

    head = deleteFromLast(head);
    printf("\nAfter Deleting last LL = ");
    display(head);

    head = deleteFromAny(head, 3);
    printf("\nAfter deleting nth node: ");
    display(head);
}
