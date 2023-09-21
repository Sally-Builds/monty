#include "monty.h"

/**
 * pall - print all values on the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; 


	if (current == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current)
		printf("%d\n", current->n);
}
