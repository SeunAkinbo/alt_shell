#include "simple_shell.h"

/**
 *shell_printer - prints a string to stdout
 *@sstring: the string to be printed
 *@output_stream: the stream to print out to
 *
 *Return: void, return nothing
 */

void shell_printer(char *sstring, int output_stream)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;

		while (sstring[i] != '\0')
		{
			write(output_stream, &sstring[i], 1);
			i++;
		}
	}
}


/**
 *_str_concat - concatenates two strings
 *@destination: the first string to be concatenated
 *@source:  the second string to be concatenated
 *
 * Return: returns the address of the new string
 */
char *_str_concat(char *destination, char *source)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		char *new_string = NULL;
		int len_dest = _stringlen(destination);
		int len_source = _stringlen(source);
		int i = 0;

		new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));

		while (destination[i] != '\0')
		{
			new_string[i] = destination[i];
			i++;
		}

		i = 0;
		while (source[i] != '\0')
		{
			new_string[len_dest + i] = source[i];
			i++;
		}

		new_string[len_dest + len_source] = '\0';
		return (new_string);
	}
	return (NULL);
}
