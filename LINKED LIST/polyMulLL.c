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
    if (coefficient == 0) return head; 

    Node* newNode = createNode(coefficient, exponent);

    if (head == NULL || head->exponent > exponent) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL && temp->next->exponent < exponent) {
            temp = temp->next;
        }

        if (temp->next != NULL && temp->next->exponent == exponent) {
            temp->next->coefficient += coefficient;
            free(newNode);
            if (temp->next->coefficient == 0) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                free(toDelete);
            }
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1;
    Node* temp2;

    while (temp1 != NULL) {
        temp2 = poly2;
        while (temp2 != NULL) {
            int coeffProduct = temp1->coefficient * temp2->coefficient;
            int expSum = temp1->exponent + temp2->exponent;
            result = insertInOrder(result, coeffProduct, expSum);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return result;
}

void displayPolynomial(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

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

Node* createPolynomial() {
    Node* poly = NULL;
    int n, coefficient, exponent;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        poly = insertInOrder(poly, coefficient, exponent);
    }

    return poly;
}

int main() {
    printf("Enter the first polynomial:\n");
    Node* poly1 = createPolynomial();

    printf("Enter the second polynomial:\n");
    Node* poly2 = createPolynomial();

    Node* result = multiplyPolynomials(poly1, poly2);

    printf("The resulting polynomial after multiplication is: ");
    displayPolynomial(result);

    return 0;
}
