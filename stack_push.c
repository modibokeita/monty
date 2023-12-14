#include "monty.h"
/**
 * stack_push - add node to the stack
 * @head: stack head
 * @c: line_number
 * Return: no return
*/
void stack_push(stack_t **head, unsigned int c)
{
	int n, j = 0, flag = 0;

	if (montyState.arg)
	{
		if (montyState.arg[0] == '-')
			j++;
		for (; montyState.arg[j] != '\0'; j++)
		{
			if (montyState.arg[j] > 57 || montyState.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(montyState.file);
			free(montyState.package);
			_freeglo(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", c);
		fclose(montyState.file);
		free(montyState.package);
		_freeglo(*head);
		exit(EXIT_FAILURE); }
	n = atoi(montyState.arg);
	if (montyState.lifo == 0)
		_add_node(head, n);
	else
		_add_queue(head, n);
}
