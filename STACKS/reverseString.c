#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
int capacity;
char* stack;

void initializeStack(int size) {
    capacity = size;
    stack = (char*)malloc(capacity*sizeof(char));
}

void push(char val) {
    stack[++top] = val;
}

char pop() {
    return stack[top--];
}

void reverse(char* str) {
    int n = strlen(str);

    for(int i=0; i<n; i++) {
        push(str[i]);
    }

    for(int i=0; i<n; i++) {
        str[i] = pop();
    }

}

int main() {
    char str[100];
    initializeStack(100);

    printf("Enter a string: ");
    // scanf("%s", str); 
    gets(str);

    reverse(str);
    printf("%s", str);


    return 0;
}