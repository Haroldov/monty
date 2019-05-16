#include "monty.h"

/**
 *op_nop - doesn’t do anything.
 *@dlinkedlist: the header of the stack or queue
 *@line_num: this is unused in this function
 *Return: none
 */

void op_nop(stack_t **dlinkedlist, unsigned int line_num)
{
	(void) line_num;
	(void) dlinkedlist;
}

/**
 *op_div - divides the second top element of the stack by the top element of the stack.
 *@dlinkedlist: the header of the stack or queue
 *@line_num: this is unused in this function
 *Return: none
 */

void op_div(stack_t **dlinkedlist, unsigned int line_num)
{
	int a, b;

	if (dlistint_len(*dlinkedlist) < 2)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	a = (*dlinkedlist)->n;
	b = (*dlinkedlist)->next->n;
	b /= a;
	delete_head(dlinkedlist);
	(*dlinkedlist)->n = b;
}
