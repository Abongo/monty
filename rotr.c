#include "monty.h"

/**
 * get_rotr - Rotate the stack to the bottom
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void get_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last = *stack;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (last->next->next != NULL)
			last = last->next;

		temp = last->next;
		last->next = NULL;
		temp->next = *stack;
		*stack = temp;
	}
}
