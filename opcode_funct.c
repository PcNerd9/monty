#include "monty.h"
#include <stdlib.h>
#include <stdio.h> 

void push_f(stack_t **stack, unsigned int line_number, char **commands)
{
	stack_t *new_node;
	int value;
	int number_args = number_of_args(commands);
	if (number_args != 2)
	{
		fprintf(stderr, "%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
		return;
	value = atoi(commands[1]);
	if (value < 0)
	{
		fprintf(stderr, "%d: usage: push integer\n", line_number);
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

void pall_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
void pint_f(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "%d: can't pint, stack empty", line_number);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

void pop_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "%d: can't pop an empty stack", line_number);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

void swap_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	n = tmp->n;
	tmp->n = (*stack)->n;
	(*stack)->n = n;

}

void add_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

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
