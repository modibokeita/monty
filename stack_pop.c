#include "monty.h"
/**
 * stack_pop - prints the top
 * @head: stack head
 * @c: line_number
 * Return: no return
*/
void stack_pop(stack_t **head, unsigned int c)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", c);
		fclose(montyState.file);
		free(montyState.package);
		_freeglo(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
