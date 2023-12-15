#include "monty.h"

/**
 * get_nop - No operation, do nothing
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void get_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}

/**
 * get_free - Free the stack
 * @stack: Double pointer to the head of the stack
 */
void get_free(stack_t *stack)
{
	stack_t *current = stack, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
