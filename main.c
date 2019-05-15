#include "monty.h"

/**
 *main - entry point
 *@argc: number of arguments
 *@argv: arguments
 *Return: 0 always
 */

int main(int argc, char *argv[])
{
	char *line = NULL, **words = NULL;
	FILE *stream = NULL;
	size_t line_size = 0;
	stack_t *dlinkedlist = NULL;
	unsigned int line_num = 0;
	void (*cmd)(stack_t **stack, unsigned int line_number) = NULL;

	(void) argc;
	stream = fopen(argv[1], "r");
	while (getline(&line, &line_size, stream) != -1)
	{
		words = split(line, " \n");
		/*cmd = get_op(words[0])*/
		line_num = (words[1] == NULL) ? 0 : (unsigned int) atoi(words[1]);
		cmd(&dlinkedlist, line_num);
	}
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
		return (NULL);

	for (i = 1; i < wNum; i++)
		*(argv + i) = strtok(NULL, delim);
	*(argv + i) = NULL;
	return (argv);
}
