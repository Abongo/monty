#include "monty.h"

/**
 * get_rotl - Rotate the stack to the top
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void get_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last = *stack;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;

		while (last->next != NULL)
			last = last->next;

		last->next = temp;
		temp->next = NULL;
	}
}
