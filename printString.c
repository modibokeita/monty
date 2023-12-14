#include "monty.h"
/**
 * printString - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @c: line_number
 * Return: no return
*/
void printString(stack_t **head, unsigned int c)
{
	stack_t *h;
	(void)c;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
