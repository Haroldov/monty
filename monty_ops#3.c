#include "monty.h"

/**
 * op_sub - subtracts the top two elements of the stack
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */
void op_sub(stack_t **dlinkedlist, unsigned int line_num)
{
	int a, b;

	if (dlistint_len(*dlinkedlist) < 2)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_num);
		free_dlistint(*dlinkedlist), free(carrier.words), free(carrier.line);
		fclose(carrier.stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		a = (*dlinkedlist)->n;
		b = (*dlinkedlist)->next->n;
		(*dlinkedlist)->next->n = b - a;
		delete_head(dlinkedlist);
	}
}
