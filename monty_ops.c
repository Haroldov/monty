#include "monty.h"

void op_push(stack_t **dlinkedlist, unsigned int line_num)
{
	stack_t push;
	
	/* Check if line_num is an integer */
	
	if (line_num == NULL)
	{
		fprintf(stderr, "L<line_number>: usage: push integer");
		exit(EXIT_FAILURE);
	}

	add_dnodeint(dlinkedlist, line_num);
}
