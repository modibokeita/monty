#include "monty.h"
/**
 * stack_pint - prints the top
 * @head: stack head
 * @c: line_number
 * Return: no return
*/
void stack_pint(stack_t **head, unsigned int c)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", c);
		fclose(montyState.file);
		free(montyState.package);
		_freeglo(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
