#ifndef __MONTY__
#define __MONTY__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LN unsigned int line_number

/**
 *struct carrier_s - auxiliar structure
 *@data: data to be inserted into stack or queue
 *@words: pointer to be freed
 *@line: pointer to be free
 *@stream: file to be closed if one fails
 */

typedef struct carrier_s
{
	int data;
	char **words;
	char *line;
	FILE *stream;
} carrier_t;

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

/*Global Variables*/
extern carrier_t carrier;

/*Prototypes*/

/*dlinkedlist#1*/
void free_dlistint(stack_t *head);
size_t dlistint_len(const stack_t *h);
size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, int n);
void delete_head(stack_t **dlistint_t);

/*monty_ops#1*/
void op_push(stack_t **stack, unsigned int line);
void op_pall(stack_t **dlinkedlist, unsigned int line);
void op_pint(stack_t **dlinkedlist, unsigned int line);
void op_swap(stack_t **dlinkedlist, unsigned int line);
void op_pop(stack_t **dlinkedlist, unsigned int line_num);

/*monty_ops#2*/
void op_nop(stack_t **dlinkedlist, unsigned int line);
void op_div(stack_t **dlinkedlist, unsigned int line);

/*main*/
char **split(char *str, const char *delim);
void (*get_op(char *command, LN))(stack_t **stack, unsigned int line_number);
int check_if_not_num(char *str);

#endif
