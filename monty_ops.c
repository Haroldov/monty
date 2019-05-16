#include "monty.h"


/**
 *op_pall -  prints all the values on the stack,
 *starting from the top of the stack or queue.
 *@dlinkedlist: the header of the stack or queue
 *@line_num: this is unused in this function
 *Return: none
 */

void op_pall(stack_t **dlinkedlist, unsigned int line_num)
{
	(void) line_num;
	print_dlistint(*dlinkedlist);
}

/**
 * op_push - pushes data to stack
 * @dlinkedlist: pointer to list
 * @line_num: line number of command
 */

void op_push(stack_t **dlinkedlist, unsigned int line_num)
{
	/* Check if line_num is an integer */
	(void) line_num;
	add_dnodeint(dlinkedlist, data);
}

/**
 *op_pint - prints the value at the top of the stack, followed by a new line
 * @dlinkedlist: pointer to list
 * @line_num: line number of command
 */

void op_pint(stack_t **dlinkedlist, unsigned int line_num)
{
	if (*dlinkedlist == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*dlinkedlist)->n);
}
