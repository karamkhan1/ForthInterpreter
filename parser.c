#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Forward declarations for stack operations.
void push(int value);
int pop(void);
void dup(void);
void drop(void);
void swap(void);
void over(void);
void rot(void);
void add(void);
void subtract(void);
void multiply(void);
void divide(void);
void dot(void);
void two_swap(void);
void two_dup(void);
void two_over(void);
void two_drop(void);
void print_stack(void);
void div_mod(void);
void mod(void);

// Checks if a string represents a number.
int is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && str[i] != '-') return 0;
    }
    return 1;
}

// Processes a command or pushes a number onto the stack.
void execute_command(const char *command) {
    if (strcmp(command, "+") == 0) add();
    else if (strcmp(command, "-") == 0) subtract();
    else if (strcmp(command, "*") == 0) multiply();
    else if (strcmp(command, "/") == 0) divide();
    else if (strcmp(command, "DUP") == 0) dup();
    else if (strcmp(command, "DROP") == 0) drop();
    else if (strcmp(command, "SWAP") == 0) swap();
    else if (strcmp(command, "OVER") == 0) over();
    else if (strcmp(command, "ROT") == 0) rot();
    else if (strcmp(command, ".") == 0) dot();
    else if (strcmp(command, "2SWAP") == 0) two_swap();
    else if (strcmp(command, "2DUP") == 0) two_dup();
    else if (strcmp(command, "2OVER") == 0) two_over();
    else if (strcmp(command, "2DROP") == 0) two_drop();
    else if (strcmp(command, "/MOD") == 0) div_mod();
    else if (strcmp(command, "MOD") == 0) mod();
    else if (strcmp(command, ".S") == 0) print_stack();
    else if (is_number(command)) push(atoi(command));
    else printf("Unknown command: %s\n", command);
    if (strcmp(command, ".S") != 0 && !is_number(command)) dot();
}

// Main function to drive the interpreter loop.
int main() {
    char input[1024];
    printf("Simple Forth Interpreter\n");
    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) break; // Exit loop on EOF.
        char *command = strtok(input, " \n"); // Tokenize input.
        while (command != NULL) {
            execute_command(command);
            command = strtok(NULL, " \n");
        }
    }
    return 0;
}
