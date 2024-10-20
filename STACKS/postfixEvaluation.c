#include <stdio.h>
#include <ctype.h> // for isdigit
#include <stdlib.h> // for atoi

#define MAX 100

int stack[MAX];
int top = -1;

// Stack Operations
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* postfix) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
 
       char ch = postfix[i];
        // If the character is an operand, push it to the stack
        if (isdigit(ch)) {
            push(ch - '0'); // Convert char to int
        }
        // If the character is an operator, pop two elements, apply the operator, and push the result
        else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2);
                    break;
                default:
                    printf("Invalid operator encountered\n");
                    return -1;
            }
        }
    }
    // The final result will be the only element left in the stack
    return pop();
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result of evaluation: %d\n", result);

    return 0;
}
