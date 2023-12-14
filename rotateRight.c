#include "monty.h"
/**
  *rotateRight- rotates the stack to the bottom
  *@head: stack head
  *@c: line_number
  *Return: no return
 */
void rotateRight(stack_t **head, __attribute__((unused)) unsigned int c)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
