#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

#define STACK_SIZE 1000

typedef struct
{
    int stack[STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, int value)
{
    if (stack->top == STACK_SIZE - 1)
    {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->stack[++stack->top] = value;
}

void pall(Stack *stack)
{
    int i;
    for (i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->stack[i]);
    }
}

int main() {
    FILE *file = fopen("bytecodes/00.m", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file\n");
        return EXIT_FAILURE;
    }

    Stack stack;
    stack.top = -1;

    char opcode[100];
    int value;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "Error: usage: push integer\n");
                fclose(file);
                return EXIT_FAILURE;
            }
            push(&stack, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else {
            // Handle other opcodes if needed
            fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
