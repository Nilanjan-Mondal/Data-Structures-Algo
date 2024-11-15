#include <stdio.h>
#include <stdlib.h>

int frontIdx = 0;
int backIdx = 0;
int *queue;
int capacity;

// Function to initialize the queue
void initializeQueue(int size) {
    capacity = size;
    queue = (int*)malloc(capacity * sizeof(int));

}

// Function to check if the queue is empty
int isEmpty() {
    return frontIdx == backIdx;
}

// Function to check if the queue is full
int isFull() {
    return backIdx == capacity;
}

// Function to push an element into the queue
void push(int val) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        queue[backIdx] = val;
        backIdx++;
    }
}

// Function to pop an element from the queue
void pop() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    frontIdx++;
}

// Function to get the front element of the queue
int getFront() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[frontIdx];
}

// Function to get the back element of the queue
int getBack() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[backIdx - 1];
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        for (int i = frontIdx; i < backIdx; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function to test the queue operations
int main() {
    int size = 5;
    initializeQueue(size);
    
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    display();
    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());

    free(queue);
    return 0;
}