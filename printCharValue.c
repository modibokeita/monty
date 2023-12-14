#include "monty.h"
/**
 * printCharValue - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @c: line_number
 * Return: no return
*/
void printCharValue(stack_t **head, unsigned int c)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", c);
		fclose(montyState.file);
		free(montyState.package);
		_freeglo(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", c);
		fclose(montyState.file);
		free(montyState.package);
		_freeglo(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
