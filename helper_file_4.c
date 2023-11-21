#include "simple_shell.h"

/**
 *newline_remover - removes new line from a string
 *@str: string to be used
 *
 *
 *Return: void
 */

void newline_remover(char *str)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;

		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				break;
			i++;
		}
		str[i] = '\0';
	}
}

/**
 *_strcopy - copies a string to another buffer
 *@source: source to copy from
 *@dest: destination to copy to
 *
 * Return: void
 */


void _strcopy(char *source, char *dest)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{	int i = 0;


		while (source[i] != '\0')
		{
			dest[i] = source[i];
			i++;
		}
		dest[i] = '\0';
	}
}


/**
 *_stringlen - counts string length
 *@sstring: string to be counted
 *
 * Return: length of the string
 */

int _stringlen(char *sstring)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int len = 0;

		if (sstring == NULL)
			return (len);

		while (sstring[len] != '\0')
		{
			len++;
		}

		return (len);
	}
	return (0);
}
