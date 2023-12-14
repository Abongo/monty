#include "monty.h"

/**
 * parse_line - Parses a line from the Monty bytecode file.
 * @line: The line to parse.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void parse_line(char *line,stack_t **stack __attribute__((unused)),
		unsigned int line_number)
{
	char *opcode, *argument;

	opcode = strtok(line, " \t\n");
	argument = strtok(NULL, " \t\n");

	if (opcode != NULL)
	{
		printf("Line %u: Opcode: %s, Argument: %s\n", line_number, opcode, argument);
	}
}
