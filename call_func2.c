#include "monty.h"

/**
 * _add - adds top two nodes in stack
 * @top: input pointer to top of stack
 * @l_num: line number of opcode
 * Return: none
 */

void _add(stack_t **top, unsigned int l_num)
{
	int total;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		print_error2(113, l_num, "add");

	(*top) = (*top)->next;
	total = (*top)->n + (*top)->prev->n;
	(*top)->n = total;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * _sub - subtracts top two nodes in stack
 * @top: input pointer to top of stack
 * @l_num: line number of opcode
 * Return: none
 */

void _sub(stack_t **top, unsigned int l_num)
{
	int result;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		print_error2(113, l_num, "sub");

	(*top) = (*top)->next;
	result = (*top)->n - (*top)->prev->n;
	(*top)->n = result;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * _div - divides top two nodes in stack
 * @top: input pointer to top of stack
 * @l_num: line number of opcode
 * Return: none
 */

void _div(stack_t **top, unsigned int l_num)
{
	int result;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		print_error2(113, l_num, "div");
	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}
	(*top) = (*top)->next;
	result = (*top)->n / (*top)->prev->n;
	(*top)->n = result;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * _mod - modulus of top two nodes in stack
 * @top: input pointer to top of stack
 * @l_num: line number of opcode
 * Return: none
 */

void _mod(stack_t **top, unsigned int l_num)
{
	int result;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		print_error2(113, l_num, "mod");
	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}
	(*top) = (*top)->next;
	result = (*top)->n % (*top)->prev->n;
	(*top)->n = result;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * _mul - multiplies top two nodes
 * @top: pointer to a top node
 * @l_num: line number of opcode
 * Return: none
 */

void _mul(stack_t **top, unsigned int l_num)
{
	int product;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		print_error2(113, l_num, "mul");
	}

	(*top) = (*top)->next;
	product = (*top)->n * (*top)->prev->n;
	free((*top)->prev);
	(*top)->prev = NULL;
	(*top)->n = product;
}
