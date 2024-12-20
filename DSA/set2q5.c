#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure for operators
struct Stack {
    int top;
    char arr[MAX];
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char c) {
    if (!isFull(stack)) {
        stack->arr[++(stack->top)] = c;
    } else {
        printf("Stack overflow!\n");
    }
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[(stack->top)--];
    } else {
        return '\0';
    }
}

// Function to return the top element of the stack
char peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    } else {
        return '\0';
    }
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to define precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initializeStack(&stack);
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If the character is '(', push it onto the stack
        else if (c == '(') {
            push(&stack, c);
        }
        // If the character is ')', pop from the stack until '(' is found
        else if (c == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(c)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }

        i++;
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function to test the infix to postfix conversion
int main() {
    char infix[MAX], postfix[MAX];

    // Input the infix expression
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Convert the infix expression to postfix
    infixToPostfix(infix, postfix);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
