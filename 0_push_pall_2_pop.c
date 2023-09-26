#include "monty.h"
stack_t *top = NULL;
/**
 * push - Function adds a new element at the top of the stack
 * @value: Element to push on the stack
 *
 * Return: NILL
 */
void push(int value)
{
	stack_t *new_stack_t = (stack_t *)malloc(sizeof(stack_t));

	if (new_stack_t == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_stack_t->n = value;
	new_stack_t->next = top;
	new_stack_t->prev = NULL;

	if (top)
	{
		top->prev = new_stack_t;
	}
	top = new_stack_t;
}
/**
 * pall - Function prints all elements in the stack
 *
 * Return: Elements in the stack
 */
void pall(void)
{
	stack_t *current = top;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pop - Function removes a last element at the top of the stack
 *
 * Return: Removed element
 */
int pop(void)
{
	int value;
	stack_t *temp;

	if (top == NULL)
	{
		fprintf(stderr, "Stack underflow\n");
		exit(EXIT_FAILURE);
	}
	value = top->n;
	temp = top;
	top = top->next;

	if (top)
	{
		top->prev = NULL;
	}

	free(temp);
	return (value);
}
