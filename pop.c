#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* pop - pops elements
* @stack: stack to pop
* @i: line number
* Return: void
*/

void pop(stack_t **stack, unsigned int i)
{
	stack_t *del;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", i);
		exit(EXIT_FAILURE);
	}

	/**
	* save the current top of the stack
	* move the stack pointer to the next element
	* update the pointer of the new top element
	* free the top element
	*/
	del = *stack;
	*stack = del->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(del);
}
