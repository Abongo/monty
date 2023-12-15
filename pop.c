#include "monty.h"

/**
 * get_pop - Remove the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void get_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
