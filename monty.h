#ifndef MONTY_H
#define MONTY_H
/* header files */
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define READSIZE 1024
#define EXIT exit(EXIT_FAILURE)
extern int stack_value;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct opcode - opcode name and value
 * @opcode_name: name of the opcode instruction
 * @opcode_value: value argumnent of the opcode
 *
 * Description: To be ble to store the opcode instruction and value
 * for the stack, queue, LIFO, FIFO
 */
typedef struct opcode
{
	char *opcode_name;
	int opcode_value;
} opcode_t;
/* function declaration */
void ErrorHandler(int, char *, int);
char **_strtokenize(char *);
int StrCountWord(char *, char *);
opcode_t *StrtokenizLineCommand(char *, unsigned int);
void push(stack_t **, unsigned int);

void pall(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
#endif
