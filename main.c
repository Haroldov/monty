#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
carrier_t carrier = {0, NULL};

/**
 *main - entry point
 *@argc: number of arguments
 *@argv: arguments
 *Return: 0 always
 */

int main(int argc, char *argv[])
{
	char *line = NULL, **words = NULL;
	size_t line_size = 0;
	stack_t *dlinkedlist = NULL;
	unsigned int line_num = 0;
	void (*cmd)(stack_t **stack, unsigned int line_number) = NULL;

	if (argc != 2)
	{       fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);    }
	carrier.stream = fopen(argv[1], "r");
	if (carrier.stream == NULL)
	{       fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);    }
	while (getline(&line, &line_size, carrier.stream) != -1)
	{
		line_num++;
		words = split(line, " \n\t");
		if (words != NULL)
		{
			if (check_if_not_num(words[1]) == -1 && strcmp("push", words[0]) == 0)
			{       fprintf(stderr, "L%i: usage: push integer\n", line_num);
				goto free_all;       }
			carrier.data = (words[1] == NULL) ? 0 : (unsigned int) atoi(words[1]);
			cmd = get_op(words[0], line_num);
			free(words);
			if (cmd == NULL)
				goto free_all;
			cmd(&dlinkedlist, line_num);
		}
		free(line);
		line = NULL;
	}
	free(line), free_dlistint(dlinkedlist), fclose(carrier.stream);
	return (EXIT_SUCCESS);
free_all:
	free(line), free(words), free_dlistint(dlinkedlist), fclose(carrier.stream);
	exit(EXIT_FAILURE);
}

/**
 *split - splits a string according to the delimiter
 *@str: pointer to the string
 *@delim: pointer to the delimiter
 *Return: an array with each word
 */

char **split(char *str, const char *delim)
{
	char **argv, *buffer, *tmpCpy = strdup(str);
	unsigned int wNum = 0, i = 0;

	if (*str == '\0')
	{
		free(tmpCpy);
		return (NULL);
	}
	/*Count the number of words to allocate memory*/
	buffer = strtok(tmpCpy, delim);
	wNum += 1;
	while (buffer != NULL)
	{
		buffer = strtok(NULL, delim);
		if (buffer != NULL)
			wNum += 1;
	}
	free(tmpCpy);

	/*Allocate memory and check if it couldn't*/
	argv = malloc(sizeof(char *) * (wNum + 1));
	if (argv == NULL)
		return (NULL);

	/*Save pointer in the bidimensional array*/
	buffer = strtok(str, delim);
	if (buffer != NULL)
		*(argv) = buffer;
	else
	{
		free(argv);
		return (NULL);
	}

	for (i = 1; i < wNum; i++)
		*(argv + i) = strtok(NULL, delim);
	*(argv + i) = NULL;
	return (argv);
}
/**
 * get_op - gets function
 * @command: command to check for
 * @LN: line number for error output
 * Return: none
 */
void (*get_op(char *command, LN))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(command, ops[i].opcode) == 0)
		{
			free(command);
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, command);
	return (NULL);
}

/**
 *check_if_not_num - checks if a string is a number
v *@str: string to be checked
 *Return: -1 if not num 1 if it is a num
 */

int check_if_not_num(char *str)
{
	int i;

	if (str == NULL)
		return (-1);
	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (isdigit(*(str + i)) == 0 && *str != '-')
			return (-1);
	}
	return (1);
}
