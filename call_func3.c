#include "monty.h"

/**
 * _nop - none
 * @top: pointer to top of stack
 * @l_num: line number
 * Return: none
*/

void _nop(stack_t **top, unsigned int l_num)
{
	(void)*top;
	(void)l_num;
}

/**
 * add_node - adds new node to queue
 * @nnode: node to add
 * @l_num: line number of opcode
 * Return: none
 */

void add_node(stack_t **nnode, unsigned int l_num)
{
	stack_t *current;
	(void) l_num;

	if (nnode == NULL || *nnode == NULL)
		exit(EXIT_FAILURE);
	if (main_node == NULL)
	{
		main_node = *nnode;
		return;
	}
	current = main_node;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = *nnode;
	(*nnode)->prev = current;
}
