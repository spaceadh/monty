#include "monty.h"
#include <stdlib.h>

/**
* nop - does nothing
* @stack: stack to swap
* @i: line number
* Return: void
*/

void nop(stack_t **stack, unsigned int i)
{
	/* this doesn't do anything */
	(void)*stack;
	(void)i;
}
