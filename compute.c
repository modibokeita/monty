#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @count_line: line_counter
* @file: poiner to monty file
* @package: line content
* Return: no return
*/
int execute(char *package, stack_t **stack, unsigned int count_line, FILE *file)
{
	instruction_t opst[] = {
				{"push", stack_push}, {"pall", stack_pall}, {"pint", stack_pint},
				{"pop", stack_pop},
				{"swap", stack_swap},
				{"add", addTopTwoElements},
				{"nop", doNothing},
				{"sub", subtractTopTwoElements},
				{"div", divideTopTwoElements},
				{"mul", multiplyTopTwoElements},
				{"mod",  moduloTopTwoElements},
				{"pchar", printCharValue},
				{"pstr", printString},
				{"rotl", rotateLeft},
				{"rotr", rotateRight},
				{"queue", setQueueFormat},
				{"stack", setStackFormat},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(package, " \n\t");
	if (op && op[0] == '#')
		return (0);
	montyState.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count_line);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count_line, op);
		fclose(file);
		free(package);
		_freeglo(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
