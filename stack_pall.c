#include "monty.h"
/**
 * stack_pall - prints the stack
 * @head: stack head
 * @c: no used
 * Return: no return
*/
void stack_pall(stack_t **head, unsigned int c)
{
	stack_t *h;
	(void)c;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
