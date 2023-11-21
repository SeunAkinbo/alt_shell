#include "simple_shell.h"

/**
 * str_tokenizer - tokenizes input and stores it into an array
 *@input_str: input to be parsed
 *@_delimita: delimiter to be used, needs to be one character string
 *
 *Return: array of tokens
 */

char **str_tokenizer(char *input_str, char *_delimita)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	for (token = _strtok_r(input_str, _delimita, &save_ptr);
	     token != NULL;
	     token = _strtok_r(NULL, _delimita, &save_ptr))
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
	}

	return (NULL);
}

/**
 *_str_comp - compares two strings
 *@first: the first string to be compared
 *@second: the second string to be compared
 *
 * Return: returns the difference of the two strings
 */
int _str_comp(char *first, char *second)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;

		for (i = 0; first[i] != '\0'; i++)
		{
			if (first[i] != second[i])
			{
				return (first[i] - second[i]);
			}
		}
		return (first[i] - second[i]);
	}
	return (0);
}
