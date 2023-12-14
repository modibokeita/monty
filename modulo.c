#include "monty.h"
/**
 * moduloTopTwoElements - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @c: line_number
 * Return: no return
*/
void moduloTopTwoElements(stack_t **head, unsigned int c)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", c);
		fclose(montyState.file);
		free(montyState.package);
		_freeglo(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", c);
		fclose(montyState.file);
		free(montyState.package);
		_freeglo(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
