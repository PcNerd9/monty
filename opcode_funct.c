#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push_f - push a value to the stack
 * @stack: a pointer to the stack
 * @line_number: the line number of the instruction
 * @to_free: a structure that contain all spaces to free
 *
 * Return: nothing
 */
void push_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	stack_t *new_node;
	int value;
	int number_args = number_of_args(to_free.command);

	if (number_args != 2)
	{
		free_strings(to_free.command);
		free_stack(stack);
		fclose(to_free.fd);
		free(to_free.instruction);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
		return;
	value = atoi(to_free.command[1]);
	if (value == 0 && ('0' - 48) == 0)
	{
		free_strings(to_free.command);
		free_stack(stack);
		free(to_free.instruction);
		fclose(to_free.fd);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = NULL;
	}
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		*stack = new_node;
	}
}

/**
 * pall_f - print all the value on the stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of the instruction
 * @to_free: a struct of space to free before exiting program
 *
 * Return: nothing
 */
void pall_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	stack_t *tmp;

	tmp = *stack;
	(void)line_number;
	(void)to_free;
	while (tmp)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint_f - print only the value on top of the stack
 * @stack: a pointer to the top of the stack
 * @line_number: the line number of the instruction
 * @to_free: a struct to the space to be freed before exit program
 *
 * Return: nothing
 */
void pint_f(stack_t **stack, unsigned int line_number, free_t to_free)
{

	if (*stack == NULL)
	{
		free_strings(to_free.command);
		free(to_free.instruction);
		fclose(to_free.fd);
		free_stack(stack);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop_f - remove the value on the top of th stack
 * @stack: a pointer to the top of the stack
 * @line_number: the line number of the instruction
 * @to_free: the struct to space to be free before program exit
 *
 * Return: nothing
 */
void pop_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		free_stack(stack);
		free_strings(to_free.command);
		free(to_free.instruction);
		fclose(to_free.fd);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * swap_f - swap the value on top of the stack and the second value
 * @stack: a pointer to the top of the stack
 * @line_number: the line number of the instruction
 * @to_free: the struct to space to be freed before program exit
 *
 * Return: nothing
 */
void swap_f(stack_t **stack, unsigned int line_number, free_t to_free)
{
	stack_t *tmp;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_strings(to_free.command);
		free(to_free.instruction);
		fclose(to_free.fd);
		free_stack(stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	n = tmp->n;
	tmp->n = (*stack)->n;
	(*stack)->n = n;

}
