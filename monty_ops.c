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
