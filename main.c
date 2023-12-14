#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	execute_monty();

	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * execute_monty - Execute Monty bytecode commands
 */
void execute_monty(void)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		parse_line(line, &stack, line_number);

		if(EXIT_FAILURE)
		{
			fprintf(stderr, "Error parsing line %d\n", line_number);
			free(line);
			get_free(stack);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	get_free(stack);
}

/**
 * get_free - Frees the memory allocated for the stack.
 * @stack: Pointer to the top of the stack.
 */
void get_free(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
