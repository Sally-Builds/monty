#include "monty.h"

/**
 * execute_instruction - execute a Monty bytecode instruction
 * @opcode: the opcode to execute
 * @line_number: line number
 */
void execute_instruction(char *opcode, unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"sub", sub},
		{"nop", nop},
		{NULL, NULL}
	};

	if (*opcode == '#')
		return;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(&stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
