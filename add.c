#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* add - adds elements
* @stack: stack to swap
* @i: line number
* Return: void
*/

void add(stack_t **stack, unsigned int i)
{
	stack_t *temp, *current;
	int a, b;

	if (*stack == NULL || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	temp = (*stack)->next;
	a = (*stack)->n;
	b = temp->n;

	temp->n = (a + b);
	*stack = temp;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);

}
