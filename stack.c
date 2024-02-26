#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 256
int stack[STACK_SIZE];
int sp = 0; // Stack pointer.

// Stack status checks.
bool is_empty() { return sp == 0; }
bool is_full() { return sp == STACK_SIZE; }

// Stack manipulation functions.
void push(int value) {
    if (!is_full()) stack[sp++] = value;
    else printf("Stack Overflow\n");
}

int pop() {
    if (!is_empty()) return stack[--sp];
    printf("Stack Underflow\n");
    return -1;
}

void dup() {
    if (!is_empty()) {
        int top = pop();
        push(top);
        push(top);
    } else printf("Error: Stack is empty\n");
}

void drop() {
    if (!is_empty()) pop();
    else printf("Error: Stack is empty\n");
}

void swap() {
    if (sp >= 2) {
        int top = pop(), second = pop();
        push(top); push(second);
    } else printf("Error: Not enough elements to swap\n");
}

void over() {
    if (sp >= 2) {
        int top = pop(), second = pop();
        push(second); push(top); push(second);
    } else printf("Error: Not enough elements to perform over\n");
}

// Extended stack operations for working with two elements.
void two_dup() {
    if (sp >= 2) {
        int top1 = stack[sp - 1], top2 = stack[sp - 2];
        push(top2); push(top1);
    } else printf("Error: Not enough elements for 2DUP\n");
}

void two_drop() {
    if (sp >= 2) pop(), pop();
    else printf("Error: Not enough elements for 2DROP\n");
}

void two_swap() {
    if (sp >= 4) {
        int top1 = pop(), top2 = pop(), top3 = pop(), top4 = pop();
        push(top2); push(top1); push(top4); push(top3);
    } else printf("Error: Not enough elements for 2SWAP\n");
}

void two_over() {
    if (sp >= 4) {
        int top1 = stack[sp - 1], top2 = stack[sp - 2],
                top3 = stack[sp - 3], top4 = stack[sp - 4];
        push(top3); push(top4);
    } else printf("Error: Not enough elements for 2OVER\n");
}

void rot() {
    if (sp >= 3) {
        int third = stack[sp - 3];
        stack[sp - 3] = stack[sp - 2];
        stack[sp - 2] = stack[sp - 1];
        stack[sp - 1] = third;
    } else printf("Error: Not enough elements to perform rot\n");
}

// Arithmetic operations.
void add() {
    if (sp >= 2) {
        int b = pop(), a = pop();
        push(a + b);
    } else printf("Error: Not enough elements for addition\n");
}

void subtract() {
    if (sp >= 2) {
        int b = pop(), a = pop();
        push(a - b);
    } else printf("Error: Not enough elements for subtraction\n");
}

void multiply() {
    if (sp >= 2) {
        int b = pop(), a = pop();
        push(a * b);
    } else printf("Error: Not enough elements for multiplication\n");
}

void divide() {
    if (sp >= 2) {
        int b = pop();
        if (b != 0) {
            int a = pop();
            push(a / b);
        } else printf("Error: Division by zero\n");
    } else printf("Error: Not enough elements for division\n");
}

void div_mod() {
    if (sp >= 2) {
        int divisor = pop();
        if (divisor != 0) {
            int dividend = pop();
            int quotient = dividend / divisor;
            int remainder = dividend % divisor;
            push(remainder);
            push(quotient);
        } else printf("Error: Division by zero\n");
    } else printf("Error: Not enough elements for /MOD\n");
}

void mod() {
    if (sp >= 2) {
        int divisor = pop();
        if (divisor != 0) {
            int dividend = pop();
            int remainder = dividend % divisor;
            push(remainder);
        } else printf("Error: Division by zero\n");
    } else printf("Error: Not enough elements for MOD\n");
}

// Print functions for debugging.
void dot() {
    if (!is_empty()) printf("%d\n", stack[sp - 1]);
    else printf("Error: Stack is empty\n");
}

void print_stack() {
    printf("Stack:");
    for (int i = 0; i < sp; i++) printf(" %d", stack[i]);
    printf(" <- Top\n");
}
