#include "monty.h"

/**
 * get_sub - Subtract the top element from the second top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void get_sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	get_pop(stack, line_number);
}
