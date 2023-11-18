#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_f - add the value on top of the stack with the second
 * value on the stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of the instruction
 *
 * Return: nothing
 */
void add_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n + tmp->n;
	free(tmp);
}

