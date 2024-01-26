#include "monty.h"
#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* main - monty intepreter
* @argc: argument count
* @argv: the argument array
* Return: success
*/

int main(int argc, char *argv[])
{
	stack_t *stack;
	char *trigger;
	char data[1024];
	FILE *file;
	unsigned int found, i, k;

	k = 0;
	i = 1;
	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (fgets(data, sizeof(data), file) != NULL)
		{
			trigger = strtok(data, " \t\n");
			if (trigger != NULL && strcmp(trigger, "push") == 0)
			{
				trigger = strtok(NULL, " \t\n");
				if (trigger != NULL)
					_push(&stack, i, trigger);
			}
			else if (trigger != NULL)
			{
				found = 0;
				for (k = 0; Commands[k].opcode != NULL; k++)
				{
					if (strcmp(trigger, Commands[k].opcode) == 0)
					{
						Commands[k].f(&stack, i);
						found = 1;
						break;
					}
				}
				if (!found)
				{
					fprintf(stderr, "L%u: unknown instruction %s\n", i, trigger);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", i);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}
