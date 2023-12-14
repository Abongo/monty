#include "monty.h"

/**
 * get_push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 * @temp: The argument to be pushed onto the stack.
 */
void get_push(stack_t **stack, unsigned int line_number, char *temp)
{
	if (temp == NULL || !is_numeric(temp))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		get_free(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	push(stack, atoi(temp));
}

/**
 * is_numeric - Checks if a string is a numeric value.
 * @str: The string to be checked.
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

/**
 * push - Pushes a new node onto the stack.
 * @stack: Pointer to the top of the stack.
 * @n: Value to be pushed onto the stack.
 */
void push(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		get_free(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
