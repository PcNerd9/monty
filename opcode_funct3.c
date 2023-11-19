#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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

