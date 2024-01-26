#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* pstr - prints elements
* @stack: stack to swap
* @i: line number
* Return: void
*/

void pstr(stack_t **stack, unsigned int i)
{
	stack_t *temp;
	(void)i;

	if (*stack == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}
	temp = *stack;

	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		fprintf(stdout, "%c", temp->n);
		if (temp->n == 0)
			break;
		temp = temp->next;
	}
		fprintf(stdout, "\n");
}
