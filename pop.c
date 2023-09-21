#include "monty.h"

/**
 * pop - print all values on the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; 


	if (current == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = current->next;
	free(current);
}
