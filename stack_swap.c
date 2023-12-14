#include "monty.h"
/**
 * stack_swap - adds the top two elements of the stack.
 * @head: stack head
 * @c: line_number
 * Return: no return
*/
void stack_swap(stack_t **head, unsigned int c)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", c);
		fclose(montyState.file);
		free(montyState.package);
		_freeglo(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
