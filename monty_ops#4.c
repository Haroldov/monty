#include "monty.h"

/**
 * op_rotl - subtracts the top two elements of the stack
 * @dlinkedlist: pointer to list
 * @line_num: line number for error
 */
void op_rotl(stack_t **dlinkedlist, unsigned int line_num)
{
	(void) line_num;
	rev_dlistint(dlinkedlist);
}
