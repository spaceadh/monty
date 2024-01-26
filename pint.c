#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* pint - prints the value at top
* @stack: the stack
* @i: the line number
* Return: the first num
*/

void pint(stack_t **stack, unsigned int i)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", i);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
