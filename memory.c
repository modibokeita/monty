#include "monty.h"

/**
 * ca_lloc - Allocate and zero-initialize memory for an array
 * @member: Number of elements in the array
 * @size: Size of each element in bytes
 * Return: Pointer to the allocated memory, or NULL if malloc fails
 */
void *ca_lloc(unsigned int member, unsigned int size)
{
	void *p = NULL;

	if (member == 0 || size == 0)
		return (NULL);

	p = malloc(member * size);
	if (!p)
	{
		dprintf(2, "Error: malloc failed\n");
		_freeglo();
		exit(EXIT_FAILURE);
	}

	/* Using memset for zero-initialization */
	memset(p, 0, member * size);

	return (p);
}

/**
 * re_alloc - Reallocate memory with new size and copy the content
 * @ptr: Pointer to the previously allocated memory
 * @oldsize: Size of the old memory block
 * @newsize: Size of the new memory block
 * Return: Pointer to the reallocated memory, or NULL if malloc fails
 */
void *re_alloc(void *ptr, unsigned int oldsize, unsigned int newsize)
{
	char *p = NULL;
	unsigned int i;

	if (newsize == oldsize)
		return (ptr);

	if (!ptr)
	{
		p = malloc(newsize);
		if (!p)
		{
			dprintf(2, "Error: malloc failed\n");
			_freeglo();
			exit(EXIT_FAILURE);
		}
		return (p);
	}

	if (newsize == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(newsize);
	if (!p)
	{
		dprintf(2, "Error: malloc failed\n");
		_freeglo();
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < (oldsize < newsize ? oldsize : newsize); i++)
		p[i] = *((char *)ptr + i);

	free(ptr);

	return (p);
}
