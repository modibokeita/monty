#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct monty_t - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct monty_t
{
	char *arg;
	FILE *file;
	char *package;
	int lifo;
}  monty_t;
extern monty_t montyState;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void stack_push(stack_t **head, unsigned int number);
void stack_pall(stack_t **head, unsigned int number);
void stack_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int count_line, FILE *file);
void _freeglo(stack_t *head);
void stack_pop(stack_t **head, unsigned int c);
void stack_swap(stack_t **head, unsigned int c);
void addTopTwoElements(stack_t **head, unsigned int c);
void doNothing(stack_t **head, unsigned int c);
void subtractTopTwoElements(stack_t **head, unsigned int c);
void divideTopTwoElements(stack_t **head, unsigned int c);
void multiplyTopTwoElements(stack_t **head, unsigned int c);
void moduloTopTwoElements(stack_t **head, unsigned int c);
void printCharValue(stack_t **head, unsigned int c);
void printString(stack_t **head, unsigned int c);
void rotateLeft(stack_t **head, unsigned int c);
void rotateRight(stack_t **head, __attribute__((unused)) unsigned int c);
void _add_node(stack_t **head, int n);
void _add_queue(stack_t **head, int n);
void setQueueFormat(stack_t **head, unsigned int c);
void setStackFormat(stack_t **head, unsigned int c);

#endif
