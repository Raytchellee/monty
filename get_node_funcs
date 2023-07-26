#include "monty.h"

/**
 * create_node - returns new node
 * @n: node value
 * Return: new node or null
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		print_error(109);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_list - frees node
 * Return: none
 */

void free_list(void)
{
	stack_t *current;

	if (main_node == NULL)
		return;

	while (main_node != NULL)
	{
		current = main_node;
		main_node = main_node->next;
		free(current);
	}
}
