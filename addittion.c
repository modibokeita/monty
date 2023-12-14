#include "monty.h"
/**
 * addTopTwoElements - adds the top two elements of the stack.
 * @head: stack head
 * @c: line_number
 * Return: no return
*/
void addTopTwoElements(stack_t **head, unsigned int c)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", c);
		fclose(montyState.file);
		free(montyState.package);
		_freeglo(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
