#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *main_node;
typedef void (*f_call)(stack_t **, unsigned int);
ssize_t getline(char **ptr, size_t *t, FILE *stream);

/** base_funcs.c */
void open_f(char *file_name);
void read_f(FILE *des);
int sep_line(char *s, int l_num, int fmt);
void call_func(char *operation, char *exc, int l_num, int fmt);
void gets_func(f_call, char *operation, char *exc, int l_num, int fmt);

/** call_funcs.c */
void _push(stack_t **top, unsigned int);
void _pall(stack_t **top, unsigned int);
void _pop(stack_t **top, unsigned int);
void _swap(stack_t **top, unsigned int);
void _pint(stack_t **top, unsigned int);

/** call_funcs2.c */
void _add(stack_t **top, unsigned int l_num);
void _sub(stack_t **top, unsigned int l_num);
void _div(stack_t **top, unsigned int l_num);
void _mod(stack_t **top, unsigned int l_num);
void _mul(stack_t **top, unsigned int l_num);

/** call_funcs3.c */
void _nop(stack_t **top, unsigned int l_num);
void add_node(stack_t **, unsigned int l_num);

/** err_funcs.c */
void print_error(unsigned int err_code, ...);
void print_error2(unsigned int err_code, ...);

/** get_node_funcs.c */
stack_t *create_node(int n);
void free_list(void);

#endif

