#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
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
 * struct free_s - contains spaces to be freed before exiting program
 * @command: the instruction in form of 2d array
 * @instruction: the instruction in form of strings
 * @fd: a open file descriptor to close
 */
typedef struct free_s
{
	char **command;
	char *instruction;
	FILE *fd;
}free_t;
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
        void (*f)(stack_t **stack, unsigned int line_number, free_t to_free);
} instruction_t;

char **split_words(char *);
void push_f(stack_t **stack, unsigned int line_number, free_t to_free);
void pop_f(stack_t **stack, unsigned int line_number, free_t to_free);
void pint_f(stack_t **stack, unsigned int line_number, free_t to_free);
void pall_f(stack_t **stack, unsigned int line_number, free_t to_free);
void swap_f(stack_t **stack, unsigned int line_number, free_t to_free);
void add_f(stack_t **stack, unsigned int line_number, free_t to_free);
void nop_f(stack_t **stack, unsigned int line_number, free_t to_free);
void sub_f(stack_t **stack, unsigned int line_number, free_t to_free);
void div_f(stack_t **stack, unsigned int line_number, free_t to_free);
void mul_f(stack_t **stack, unsigned int line_number, free_t to_free);
void mod_f(stack_t **stack, unsigned int line_number, free_t to_free);
void pchar_f(stack_t **stack, unsigned int line_number, free_t to_free);
void pstr_f(stack_t **stack, unsigned int line_number, free_t to_free);

int number_of_args(char **);
void free_strings(char **);
void free_stack(stack_t **stack);
#endif
