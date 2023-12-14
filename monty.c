#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

monty_t montyState = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *package;
	FILE *file;
	size_t size = 0;
	ssize_t lines = 1;
	stack_t *stack = NULL;
	unsigned int count_line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	montyState.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (lines > 0)
	{
		package = NULL;
		lines = getline(&package, &size, file);
		montyState.package = package;
		count_line++;
		if (lines > 0)
		{
			execute(package, &stack, count_line, file);
		}
		free(package);
	}
	_freeglo(stack);
	fclose(file);
	return (0);
}
