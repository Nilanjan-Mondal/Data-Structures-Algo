#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';  // return null if stack is empty
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';  // return null if stack is empty
}

bool isValid(char *s) {
    int length = strlen(s);
    
    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i]);
        } else if (s[i] == ')') {
            if (i == 0 || top == -1 || peek() != '(') {
                return false;
            }
            pop();
        } else if (s[i] == ']') {
            if (i == 0 || top == -1 || peek() != '[') {
                return false;
            }
            pop();
        } else if (s[i] == '}') {
            if (i == 0 || top == -1 || peek() != '{') {
                return false;
            }
            pop();
        }
    }
    
    return top == -1;  // stack should be empty if valid
}

int main() {
    char s[MAX];

    printf("Enter the string of parentheses: ");
    scanf("%s", s);

    if (isValid(s)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}
