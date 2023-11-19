#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * main - interprete monty byte code
 * @argc: the number of argument passed
 * @argv: the pointer to the arguments passed
 * Return: 0 success otherwise return 1
 */
int main(int argc, char **argv)
{
	free_t to_free;
	stack_t *stack = NULL;
	ssize_t byteread = 0, file_access = 0;
	size_t inst_size;
	void (*function)(stack_t **, unsigned int, free_t) = NULL;
	instruction_t opcodes[] = {{"pall", pall_f}, {"pint", pint_f}, {"pop", pop_f},
		{"swap", swap_f}, {"sub", sub_f}, {"div", div_f},
		{"add", add_f}, {"mul", mul_f}, {"mod", mod_f},
		{"nop", nop_f}, {"pchar", pchar_f}, {"pstr", pstr_f},
	};
	unsigned int line_number = 0, i;

	to_free.instruction = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_access = access(argv[1], F_OK);
	if (file_access == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	to_free.fd = fopen(argv[1], "r");
	if (!to_free.fd)
	{
		fprintf(stderr, "Could not open the file specified\n");
		exit(EXIT_FAILURE);
	}
	while ((byteread = getline(&to_free.instruction, &inst_size, to_free.fd)) > 0)
	{
		line_number++;
		to_free.instruction[byteread - 1] = '\0';
		to_free.command = split_words(to_free.instruction);
		if (to_free.command && to_free.command[0][0] != '#')
		{
			if (strcmp(to_free.command[0], "push") == 0)
			{
				push_f(&stack, line_number, to_free);
			}
			else
			{
				for (i = 0; i < (sizeof(opcodes) / sizeof(instruction_t)); i++)
				{
					if (strcmp(opcodes[i].opcode, to_free.command[0]) == 0)
					{
						function = opcodes[i].f;
						break;
					}
				}
				if (function)
					function(&stack, line_number, to_free);
				else
				{
					fprintf(stderr, "L%d: unknown instruction %s\n",
							line_number, to_free.command[0]);
					free_strings(to_free.command);
					free(to_free.instruction);
					free_stack(&stack);
					fclose(to_free.fd);
					exit(EXIT_FAILURE);
				}
			}
		}
		free_strings(to_free.command);
	}
	free(to_free.instruction);
	fclose(to_free.fd);
	free_stack(&stack);
	return (0);
}
