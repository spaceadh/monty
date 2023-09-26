#include "monty.h"
/**
 * free_stack_elements - Function frees all allocated nodes memory
 * in the stack.
 *
 * Return: NULL.
 */
void free_stack_elements(void)
{
	stack_t *top = NULL;

	while (top != NULL)
	{
		stack_t *temp = top;

		top = top->next;
		free(temp);
	}
}
