#include "monty.h"

/**
 * op_rotl - subtracts the top two elements of the stack
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */
void op_rotl(stack_t **dlinkedlist, unsigned int line_num)
{
	(void) line_num;
	stack_t tmp = *dlinkedlist;

	while (tmp->next == NULL)
		tmp = tmp->next;
	tmp->next = *dlinkedlist;
	(*dlinkedlist)->prev = tmp;
	tmp = (*dlinkedlist)->next;
	(*dlinkedlist)->next = NULL;
	*dlinkedlist = tmp;
}
