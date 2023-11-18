#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

char **split_words(char *strings)
{
	int i, j, lenght = 0, number_of_words = 0, l = 0, k, m = 0;
	char **instructions, *word;

	if (strings == NULL || strings[0] == '\0')
		return (NULL);
	instructions = (char **)malloc(sizeof(char *) * 3);
	if (instructions == NULL)
		return (NULL);
	for (i = 0; strings[i] != '\0'; i++)
	{
		if (strings[i] != ' ')
		{
			lenght = 0;
			number_of_words++;
			for (j = i; strings[j] != ' ' && strings[j] != '\0'; j++)
			       lenght++;
			word = (char *)malloc(sizeof(char) * lenght + 1);
			if (word == NULL)
				return (NULL);
			l = 0;
			for (k = i; strings[k] != ' ' && strings[k] != '\0'; k++)
				word[l++] = strings[k];
			word[l] = '\0';
			instructions[m++] = word;
			i = j;
			if (number_of_words == 2)
				break;
		}
		if (strings[i] == '\0')
			break;
	}
	instructions[m] = NULL;
	return (instructions);
}
void free_strings(char **strings)
{
	int i = 0;

	if (strings != NULL)
	{
		while (strings[i] != NULL)
		{
			free(strings[i]);
			i++;
		}
		free(strings);
	}	
}
int number_of_args(char **command)
{
        int number_args = 0;

        while (*command)
        {
                number_args++;
                command++;
        }
        return (number_args);
}
