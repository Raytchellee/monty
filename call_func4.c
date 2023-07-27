#include "monty.h"

/**
 * _pstr - prints strings in a list
 * @top: pointer to top of stack
 * @l_num: line number
 */

void _pstr(stack_t **top, unsigned int l_num)
{
	stack_t *current;

	(void)top;
	(void)l_num;

	current = *top;
	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	while (current && current->n > 0 && current->n < 128)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
 * _rotl - rotates stack top to bottom
 * @top: pointer to top of stack
 * @l_num: line number
 * Return: none
 */

void _rotl(stack_t **top, unsigned int l_num)
{
	stack_t *current, *nnode;
	unsigned int idx;
	int count = 0;

	(void)l_num;
	count = getlen(top);
	if (*top != NULL && count >= 2)
	{
		nnode = malloc(sizeof(stack_t));
		if (!nnode)
		{
			print_error(109);
		}
		current = *top;
		idx = current->n;
		*top = current->next;
		free(current);
		current = *top;
		while (current->next)
        {
			current = current->next;
        }
		current->next = nnode;
		nnode->n = idx;
		nnode->prev = current;
		nnode->next = NULL;
	}
}

/**
 * _rotr - rotates stack bottom to top
 * @top: pointer to top of stack
 * @l_num: line number
 * Return: none
 */

void _rotr(stack_t **top, unsigned int l_num)
{
	stack_t *current = NULL, *nnode = NULL;
	int count = 0;

	(void)l_num;
	count = getlen(top);
	if (*top != NULL && count >= 2)
	{
		nnode = malloc(sizeof(stack_t));
		if (!nnode)
			print_error(109);
		nnode->prev = NULL;
		current = *top;
		while (current->next->next)
        {
			current = current->next;
        }
		nnode->n = current->next->n;
		free(current->next);
		current->next = NULL;
		current = *top;
		nnode->next = current;
		*top = nnode;
	}
}

/**
 * _stack - chnages queue to stack
 * @top: pointer to top of stack
 * @l_num: line number
 * Return: none
 */

void _stack(stack_t **top, unsigned int l_num)
{
	(*top)->n = 0;
	(void)l_num;
}

/**
 * _queue - changes stack to queue
 * @top: pointer to top of stack
 * @l_num: line number
 * Return: none
 */

void _queue(stack_t **top, unsigned int l_num)
{
	(*top)->n = 1;
	(void)l_num;
}
