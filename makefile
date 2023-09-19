COMPILE = -Wall -Werror -Wextra -pedantic -std=c89 -g

MEMORY_LEAK = -s --leak-check=full --show-leak-kinds=all --track-origins=yes 

betty:
	betty monty.h *.c

run:
	gcc $(COMPILE) *.c -o monty

leak:
	valgrind $(MEMORY_LEAK) ./monty