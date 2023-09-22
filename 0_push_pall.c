#include "monty.h"

stack_t *top = NULL;

void push(int value) 
{
    stack_t *new_stack_t = (stack_t*)malloc(sizeof(stack_t));
    if (new_stack_t == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_stack_t->n = value;
    new_stack_t->next = top;
    new_stack_t->prev = NULL;

    if (top != NULL) 
    {
        top->prev = new_stack_t;
    }

    top = new_stack_t;
}

void pall() 
{
    stack_t *current = top;
    while (current != NULL) 
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int pop()
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

    if (top != NULL) 
    {
        top->prev = NULL;
    }

    free(temp);
    return value;
}

FILE *file;
char opcode[100];
    int value;

int main(int argc, char *argv[])
 {
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    

    while (fscanf(file, "%s", opcode) != EOF) 
    {
        if (strcmp(opcode, "push") == 0) 
        {
            if (fscanf(file, "%d", &value) != 1) 
            {
                fprintf(stderr, "Usage: push integer\n");
                return EXIT_FAILURE;
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
            return EXIT_FAILURE;
        }
    }

    fclose(file);

    while (top != NULL) 
    {
        stack_t *temp = top;
        top = top->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}
