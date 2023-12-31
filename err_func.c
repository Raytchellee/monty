#include "monty.h"

/**
 * print_error - handles the error messages
 * @err_code: input error code
 * Return: none
 */
void print_error(unsigned int err_code, ...)
{
	va_list args;
	char *err_m;
	unsigned int num;

	va_start(args, err_code);

	switch (err_code)
	{
		case 110:
			fprintf(stderr, "L%u: usage: push integer\n", va_arg(args, unsigned int));
			break;
		case 109:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 108:
			num = va_arg(args, unsigned int);
			err_m = va_arg(args, char *);
			fprintf(stderr, "L%u: unknown instruction %s\n", num, err_m);
			break;
		case 107:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(args, char *));
			break;
		case 106:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		default:
			break;
	}

	free_list();
	exit(EXIT_FAILURE);
}

/**
 * print_error2 - prints correct error message
 * @err_code: input error message
 * Return: none
 */

void print_error2(unsigned int err_code, ...)
{
	va_list args;
	char *err_m;
	unsigned int l_num;

	va_start(args, err_code);
	switch (err_code)
	{
		case 114:
			l_num = va_arg(args, unsigned int);
			err_m = va_arg(args, char *);
			fprintf(stderr, "L%u: can't div %s, stack too short \n",
					l_num, err_m);
			break;
		case 113:
			l_num = va_arg(args, unsigned int);
			err_m = va_arg(args, char *);
			fprintf(stderr, "L%u: can't %s, stack too short\n", l_num, err_m);
			break;
		case 112:
			fprintf(stderr, "L%u: can't pop an empty stack\n",
					va_arg(args, unsigned int));
			break;
		case 111:
			fprintf(stderr, "L%u: can't pint, stack empty\n",
					va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_list();
	exit(EXIT_FAILURE);
}
