#include "monty.h"
/**
 * main - Main function for monty program
 * @argc: Argument count passed in the program.
 * @argv: Argument vector for the program.
 *
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char opcode[100];
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}
	while (fscanf(file, "%s", opcode) != EOF)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "Usage: push integer\n");
				return (EXIT_FAILURE);
			}
			push(value);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop();
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall();
		}
		else
		{
			fprintf(stderr, "Unknown opcode: %s\n", opcode);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
