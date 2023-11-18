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
	FILE *fd = NULL;
	stack_t *stack = NULL;
	ssize_t byteread = 0, file_access = 0;
	size_t inst_size;
	void (*function)(stack_t **stack, unsigned int line_number) = NULL;
	instruction_t opcodes[] = {{"pall", pall_f}, {"pint", pint_f}, {"pop", pop_f},
		{"swap", swap_f},
		{"add", add_f},
		{NULL, NULL}
	};
	char *instruc = NULL, **commands = NULL;
	unsigned int line_number = 0, i;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	file_access = access(argv[1], F_OK);
	if (file_access == -1)
	{
		write(2, "The file does not exit\n", 23);
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		write(2, "Could not open the file specified\n", 34);
		exit(EXIT_FAILURE);
	}
	while ((byteread = getline(&instruc, &inst_size, fd)) > 0)
	{
		line_number++;
		instruc[byteread - 1] = '\0';
		commands = split_words(instruc);
		if (commands)
		{
			if (strcmp(commands[0], "push") == 0)

				push_f(&stack, line_number, commands);
			else
			{
				for (i = 0; i < (sizeof(opcodes) / sizeof(instruction_t)); i++)
				{
					if (strcmp(opcodes[i].opcode, commands[0]) == 0)
					{
						function = opcodes[i].f;
						break;
					}
				}
				if (function)
					function(&stack, line_number);
			}
		}
		free_strings(commands);
	}
	free(instruc);
	fclose(fd);
	free_stack(&stack);
	return (0);
}
