#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

Node* insertInOrder(Node* head, int coefficient, int exponent) {
    Node* newNode = createNode(coefficient, exponent);
    if (head == NULL || head->exponent > exponent) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL && temp->next->exponent < exponent) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

void displayPolynomial(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* polynomial = NULL;
    int n, coefficient, exponent;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        polynomial = insertInOrder(polynomial, coefficient, exponent);
    }

    printf("The polynomial is: ");
    displayPolynomial(polynomial);

    return 0;
}
