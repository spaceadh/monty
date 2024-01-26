#include "monty.h"

instruction_t Commands[] = {
	{"pall", _pall},
	{"pint", pint},
	{"nop", nop},
	{"pop", pop},
	{"add", add},
	{"swap", swap},
	{"sub", _sub},
	{"div", _div},
	{"mul", _mul},
	{"mod", _mod},
	{"pstr", pstr},
	{"pchar", pchar},
	{"#", nop},
	{NULL, NULL}
};
