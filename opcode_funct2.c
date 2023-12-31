#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_f - add the value on top of the stack with the second
 * value on the stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of the instruction
 * @to_free: a struct of  all the space to free before exiting program
 *
 * Return: nothing
 */
void add_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_strings(to_free.command);
		free(to_free.instruction);
		fclose(to_free.fd);
		free_stack(stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n + tmp->n;
	free(tmp);
}
/**
 * nop_f - do nothing
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of instruction
 * @to_free: spaces to free before program exit
 *
 * Return: nothing
 */

void nop_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	(void)stack;
	(void)line_number;
	(void)to_free;
}

/**
 * sub_f - subtract the top element of the stack from the
 * second top element of the stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of instruction
 * @to_free: spaces to free before program exit
 *
 * Return: nothing
 */

void sub_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_strings(to_free.command);
		free(to_free.instruction);
		fclose(to_free.fd);
		free_stack(stack);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n - tmp->n;
	free(tmp);
}

/**
 * div_f - divid the second top element of the stack
 * by the top element of the stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of instruction
 * @to_free: spaces to free before program exit
 *
 * Return: nothing
 */

void div_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	(*stack)->n = (*stack)->n / tmp->n;
	free(tmp);
}

/**
 * mul_f - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of instruction
 * @to_free: spaces to free before program exit
 *
 * Return: nothing
 */

void mul_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_strings(to_free.command);
		free(to_free.instruction);
		fclose(to_free.fd);
		free_stack(stack);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n * tmp->n;
	free(tmp);
}
