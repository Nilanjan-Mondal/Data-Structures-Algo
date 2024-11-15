#include <stdio.h>
#include <stdlib.h>

int *stack;
int idx = -1;
int capacity;

// Function to initialize the stack
void initializeStack(int size) {
    capacity = size;
    stack = (int*)malloc(capacity * sizeof(int));
}

// Function to push an element onto the stack
void push(int value) {
    if (idx == capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    idx++;
    stack[idx] = value;
}

// Function to pop an element from the stack
void pop() {
    if (idx == -1) {
        printf("Stack underflow\n");
        return;
    }
    idx--;
}

// Function to peek at the top element of the stack
int peek() {
    if (idx == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[idx];
}

// Function to display the elements of the stack
void display() {
    if (idx == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = idx; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    initializeStack(size);
    
    push(10);
    push(20);
    push(30);
    push(40);

    printf("Stack elements: ");
    display();

    printf("Top element is %d\n", peek());

    pop();
    printf("Stack elements after pop: ");
    display();


    free(stack);
    return 0;
}