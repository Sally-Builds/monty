#include "monty.h"

/**
 * sub - print all values on the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; 


	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n -= current->n;

	*stack = current->next;

	free(current);
}
