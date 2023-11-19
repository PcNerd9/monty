#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mod_f - compute the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of instruction
 * @to_free: spaces to free before program exit
 *
 * Return: nothing
 */
void mod_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		else
			fprintf(stderr, "L%d: division by zero\n", line_number);
		free_strings(to_free.command);
		free(to_free.instruction);
		fclose(to_free.fd);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n % tmp->n;
	free(tmp);
}

void pchar_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	if (*stack == NULL || (*stack)->n <32 || (*stack)->n >126)
	{
		if (*stack == NULL)
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		else
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_strings(to_free.command);
		free(to_free.instruction);
		fclose(to_free.fd);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
void pstr_f(stack_t **stack, unsigned int  line_number, free_t to_free)
{
	stack_t *tmp;
	(void)to_free;
	(void)line_number;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->n < 32 || tmp->n > 126)
			break;
		fprintf(stdout, "%c", tmp->n);
		tmp = tmp->next;
	}
	fprintf(stdout, "\n");

}
