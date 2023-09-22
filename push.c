#include "monty.h"

int is_valid_integer(const char *str);
/**
 * push - push an integer onto the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int value;
	/**size_t i = 0; */
	stack_t *new_node;

	token = strtok(NULL, " \t\r\n");
	if (!token || is_valid_integer(token) == 0)
	{
		fprintf(stderr, "L%u usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(token);


	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}




int is_valid_integer(const char *str) {
	char *endptr;
	long value;

	errno = 0;
	value = strtol(str, &endptr, 10);

	if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN)) ||
			(errno != 0 && value == 0)) {
		perror("strtol");
		return 0;
	}

	if (endptr == str || *endptr != '\0') {
		return 0;
	}

	return 1;
}
