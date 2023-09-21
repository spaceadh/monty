#include "monty.h"


int stack[STACK_SIZE];
int top = -1; 

void push(int value) 
{
    if (top == STACK_SIZE - 1) 
    {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

int i;
void pall() 
{
    for (i = top; i >= 0; i--) 
    {
        printf("%d\n", stack[i]);
    }
}


int pop() {
    if (top == -1) 
    {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
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

    return EXIT_SUCCESS;
}
