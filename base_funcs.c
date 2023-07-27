#include "monty.h"

/**
 * open_f - opens the file
 * @file_name: file name
 * Return: none
 */

void open_f(char *file_name)
{
	int check;
	FILE *des;

	if (file_name == NULL)
	{
		print_error(107, file_name);
	}
	check = access(file_name, R_OK);
	if (check == -1)
	{
		print_error(107, file_name);
	}
	des = fopen(file_name, "r");
	if (des == NULL)
	{
		print_error(107, file_name);
	}

	read_f(des);
	fclose(des);
}

/**
 * read_f - reads file content
 * @des: file description pointer
 * Return: none
 */

void read_f(FILE *des)
{
	size_t t = 0;
	char *buff = NULL;
	int l_num = 1, fmt = 0;

	if (des == NULL)
	{
		print_error(107, "file_name");
	}
	while (getline(&buff, &t, des) != EOF)
	{
		fmt = sep_line(buff, l_num, fmt);
		l_num++;
	}

	free(buff);
}

/**
 * sep_line - separates and interpretes line
 * @s: input string
 * @l_num: opcode line number
 * @fmt: stack and queue format specifier
 * Return: 1 if queue, 0 otherwise
 */

int sep_line(char *s, int l_num, int fmt)
{
	char *operation, *exc;
	const char *rmv;

	rmv = "\n ";

	if (s == NULL)
	{
		print_error(109);
	}

	operation = strtok(s, rmv);

	if (operation == NULL)
	{
		return (fmt);
	}

	exc = strtok(NULL, rmv);
	if (strcmp(operation, "stack") == 0)
	{
		return (0);
	}
	else if (strcmp(operation, "queue") == 0)
	{
		return (1);
	}

	call_func(operation, exc, l_num, fmt);
	return (fmt);
}

/**
 * call_func - call the function to execute
 * @opcode: input operation code
 * @exc: input command to execute
 * @l_num: opcode line number
 * @fmt: stack and queue format specifier
 * Return: none
 */

void call_func(char *opcode, char *exc, int l_num, int fmt)
{
	int idx, err_val;

	instruction_t functions[] = {
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mod", _mod},
		{"mul", _mul},
		{"swap", _swap},
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
	{
		return;
	}

	for (err_val = 1, idx = 0; functions[idx].opcode != NULL; idx++)
	{
		if (strcmp(opcode, functions[idx].opcode) == 0)
		{
			gets_func(functions[idx].f, opcode, exc, l_num, fmt);
			err_val = 0;
		}
	}

	if (err_val == 1)
		print_error(108, l_num, opcode);
}

/**
 * gets_func - gets the correct function
 * @f: function pointer
 * @operation: opcode
 * @exc: input command
 * @l_num: opcode line number
 * @fmt: stack and queue format specifier
 * Return: none
 */

void gets_func(f_call f, char *operation, char *exc, int l_num, int fmt)
{
	int err_val = 1, idx;
	stack_t *new_node;

	if (strcmp(operation, "push") == 0)
	{
		if (exc != NULL && exc[0] == '-')
		{
			exc = exc + 1;
			err_val = -1;
		}

		if (exc == NULL)
			print_error(110, l_num);

		for (idx = 0; exc[idx] != '\0'; idx++)
		{
			if (isdigit(exc[idx]) == 0)
				print_error(110, l_num);

		}

		new_node = create_node(atoi(exc) * err_val);
		if (fmt == 0)
			f(&new_node, l_num);
		if (fmt == 1)
			add_node(&new_node, l_num);
	}
	else
		f(&main_node, l_num);
}

