#include "monty.h"

/**
 * swap - print all values on the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number; 

	if (*stack == NULL)
	{
		printf("L%u: can't swap an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		printf("L%u: can't swap an empty stack\n", line_number);
                exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->prev = NULL;

	*stack = temp;
}
