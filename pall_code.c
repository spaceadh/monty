#include "monty.h"
#include <stdio.h>
#include <unistd.h>

/**
* _pall - adds element to stack
* @stack: the stack
* @i: line number
* Return: void
*/

void _pall(stack_t **stack, unsigned int i)
{
	stack_t *temp;
	(void)i;
	temp = *stack;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
