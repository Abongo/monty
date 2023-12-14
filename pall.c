#include "monty.h"

/**
 * get_pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void get_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Unused parameter */

	print_stack(*stack);
}

/**
 * print_stack - Prints all the values in the stack.
 * @stack: Pointer to the top of the stack.
 */
void print_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
