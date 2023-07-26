#include "monty.h"

/**
 * _push - adds new node to stack
 * @nnode: node to add
 * @l_num: opcode line number
 * Return: none
 */

void _push(stack_t **nnode, unsigned int l_num)
{
	stack_t *current;
	(void) l_num;

	if (nnode == NULL || *nnode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (main_node == NULL)
	{
		main_node = *nnode;
		return;
	}

	current = main_node;
	current->prev = NULL;
	main_node = *nnode;
	main_node->next = current;
	current->prev = main_node;

}

/**
 * _pall - prints all node values
 * @top: input pointer to top of stack
 * @l_num: opcode line number
 * Return: none
 */

void _pall(stack_t **top, unsigned int l_num)
{
	stack_t *current;

	(void) l_num;
	if (top == NULL)
	{
		exit(EXIT_FAILURE);
	}
	current = *top;
	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pop - removes the last node from stack
 * @top: input pointer to top of stack
 * @l_num: opcode line number
 * Return: none
 */

void _pop(stack_t **top, unsigned int l_num)
{
	stack_t *current;

	if (top == NULL || *top == NULL)
	{
		print_error2(112, l_num);
	}

	current = *top;
	*top = current->next;
	if (*top != NULL)
	{
		(*top)->prev = NULL;
	}
	free(current);
}

/**
 * _swap - swaps top two nodes
 * @top: input pointer to top of stack
 * @l_num: Opcode line number.
 * Return: none
 */

void _swap(stack_t **top, unsigned int l_num)
{
	stack_t *current;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		print_error2(113, l_num, "swap");
	}

	current = (*top)->next;
	(*top)->next = current->next;

	if (current->next != NULL)
	{
		current->next->prev = *top;
	}

	current->next = *top;
	(*top)->prev = current;
	current->prev = NULL;
	*top = current;
}

/**
 * _pint - prints value at top of stack
 * @top: input pointer to top of stack
 * @l_num: opcode line number
 * Return: none
 */

void _pint(stack_t **top, unsigned int l_num)
{
	if (top == NULL || *top == NULL)
	{
		print_error2(111, l_num);
	}

	printf("%d\n", (*top)->n);
}
