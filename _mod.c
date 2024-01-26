#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* _mod - mod elements
* @stack: stack to swap
* @i: line number
* Return: void
*/

void _mod(stack_t **stack, unsigned int i)
{
	stack_t *temp, *current;
	int a, b;

	if (*stack == NULL || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	temp = (*stack)->next;

	a = (*stack)->n;
	b = temp->n;

	if (a == 0)
	{
		fprintf(stderr, "L%u: division by zero", i);
		exit(EXIT_FAILURE);
	}
	temp->n = (b % a);
	*stack = temp;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
