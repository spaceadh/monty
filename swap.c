#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* swap - swaps elements
* @stack: stack to swap
* @i: line number
* Return: void
*/

void swap(stack_t **stack, unsigned int i)
{
	stack_t *temp;
	int a, b;

	if (*stack == NULL || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	a = (*stack)->n;
	b = temp->n;

	temp->n = a;
	(*stack)->n = b;
}
