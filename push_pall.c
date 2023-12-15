#include "monty.h"

/**
 * get_push - Push an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 * @temp: The value to push onto the stack
 */
void get_push(stack_t **stack, unsigned int line_number, char *temp)
{
	stack_t *new_node;

	if (temp == NULL || !is_numeric(temp))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(temp);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * get_pall - Print all elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void get_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * is_numeric - Check if a string represents a numeric value
 * @str: The string to check
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && (i == 0 && str[i] != '-'))
			return (0);
	}

	return (1);
}
