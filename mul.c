#include "monty.h"

/**
 * get_mul - Multiply the second top element with the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void get_mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	get_pop(stack, line_number);
}
