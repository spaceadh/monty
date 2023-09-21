#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @head: pointer to head node address
 * @line_number: specific line number
 *
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int temp;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		EXIT;
	}
	while (dir->next)
		dir = dir->next;
	prev =  dir->prev;
	temp  = prev->n;
	prev->n = dir->n;
	dir->n = temp;
}

/**
 * add - adds the top two elements of the stack.
 * @head: pointer to head node address
 * @line_number: specific line number
 *
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		EXIT;
	}
	while (dir->next)
		dir = dir->next;
	prev = dir->prev;
	result =  prev->n + dir->n;
	prev->n = result;
	free(dir);
	prev->next = NULL;
}

/**
 * nop - performs nothing
 * @head: unused
 * @line_number: unused
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
