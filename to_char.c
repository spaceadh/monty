#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* pchar - prints char elements
* @stack: stack to swap
* @i: line number
* Return: void
*/

void pchar(stack_t **stack, unsigned int i)
{
	int a;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", i);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;

	if (a > 0 && a <= 127)
		fprintf(stdout, "%c\n", a);
	else
	{
		fprintf(stdout, "L%u: can't pchar, value out of range\n", i);
		exit(EXIT_FAILURE);
	}
}
