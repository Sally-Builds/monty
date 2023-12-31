#include "monty.h"

stack_t *stack = NULL;
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	char line[MAX_LINE_LENGTH];
	FILE *file;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		char *opcode;

		line_number++;

		if (strlen(line) == 1 && (line[0] == ' ' || line[0] == '\n'))
		{
			continue;
		}

		opcode = strtok(line, " \t\r\n");
		if (opcode)
		{
			execute_instruction(opcode, line_number);
		}
	}

	fclose(file);

	while (stack)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}

	return (EXIT_SUCCESS);
}
