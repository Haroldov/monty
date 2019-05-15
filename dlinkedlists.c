#include "monty.h"

/**
 *print_dlistint - prints all the elements of a dlistint_t list.
 *@h: header of the doubly linked list
 *Return: the number of nodes
 */

size_t print_dlistint(const stack_t *h)
{
	unsigned int numNodes = 0;

	if (h == NULL)
		return (numNodes);
	while (h != NULL)
	{
		printf("%i\n", (*h).n);
		h = (*h).next;
		numNodes++;
	}
	return (numNodes);
}
/**
 * add_dnodeint - add node at head of list
 * @head: pointer to list
 * @n: data to add
 * Return: pointer to new node
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);
	(*new_node).n = n;
	(*new_node).prev = NULL;
	(*new_node).next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}
