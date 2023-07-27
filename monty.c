#include "monty.h"
stack_t *main_node = NULL;

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char **argv)
{
	if (argc != 2)
		print_error(106);
	open_f(argv[1]);
	free_list();
	return (0);
}
