#include "monty.h"

/**
 * _addnodeint_end - Add a node at the end of the doubly linked list
 * @head: Pointer to the first node of the linked list
 * @n: Data to store in the new node
 * Return: Pointer to the newly added node
 */
stack_t *_addnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *last_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;

	new_node->prev = last_node;
	last_node->next = new_node;

	return (new_node);
}

/**
 * _addnodeint - Add a node at the beginning of the doubly linked list
 * @head: Pointer to the first node of the linked list
 * @n: Data to store in the new node
 * Return: Pointer to the newly added node
 */
stack_t *_addnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (!*head)
	{
		new_node->next = NULL;
		*head = new_node;
		return (*head);
	}

	(*head)->prev = new_node;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}

/**
 * _freelistint - Frees the doubly linked list
 * @head: Pointer to the head of the list
 * Return: No return value
 */
void _freelistint(stack_t *head)
{
	stack_t *current, *next_node;

	current = head;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
