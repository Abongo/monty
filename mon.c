#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - Pushes a value onto the stack
 * @stack: Pointer to the stack structure
 * @value: Value to be pushed onto the stack
 */
void push(Stack *stack, int value)
{
	if (stack->top == STACK_SIZE - 1)
	{
		fprintf(stderr, "Error: Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	stack->stack[++stack->top] = value;
}

/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the stack structure
 */
void pall(Stack *stack)
{
	int i;

	for (i = stack->top; i >= 0; i--)
	{
		printf("%d\n", stack->stack[i]);
	}
}
