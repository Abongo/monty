#include "monty.h"

/**
 * stack_mode - Set the format of the data to a stack (LIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing, as the default behavior is LIFO (stack) */
}

/**
 * queue_mode - Set the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp;

	(void)line_number;

	if (current != NULL && current->next != NULL)
	{
		while (current->next != NULL)
			current = current->next;

		temp = *stack;
		*stack = (*stack)->next;
		current->next = temp;
		temp->next = NULL;
	}
}
