#include "monty.h"

/**
 *rev_dlistint - reverse all the elements of a dlistint_t list.
 *@h: header of the doubly linked list
 *Return: the number of nodes
 */

stack_t *rev_dlistint(stack_t **h)
{
	int *tmp_buf = NULL, i = 1, sw = 0;
	size_t size = dlistint_len(*h);
	stack_t *tmp = *h;

	if (*h == NULL)
		return (NULL);
	tmp_buf = malloc(sizeof(int) * size);
	if (tmp_buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (tmp != NULL)
	{
		if (tmp->next == NULL || sw == 1)
		{
			if (sw == 0)
			{
				*(tmp_buf + i - 1) = tmp->n;
				i++;
			}
			tmp->n = *(tmp_buf + i - size - 1);
			tmp = tmp->prev;
			sw = 1;
		}
		else
		{
			*(tmp_buf + i - 1) = tmp->n;
			tmp = tmp->next;
		}
		i++;
	}
	return (*h);
}
