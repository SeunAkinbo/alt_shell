#include "simple_shell.h"
/**
 *_str_spn - gets the length of a prefix substring
 *@str1: the string to be searched
 *@str2: string to be used
 *
 *Return: No. of bytes in initial segment of 5 which are part of a string
 */
int _str_spn(char *str1, char *str2)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int match = 0;
		int i = 0;

		for (i = 0; str1[i] != '\0'; i++)
		{
			if (_strchr(str2, str1[i]) == NULL)
			{
				break;
			}
			match++;
		}
		return (match);
	}
	return (0);
}


/**
 *_strcspn - computes segment of str1 consisting of characters absent in str2
 *@str1: the string to be searched
 *@str2: the string to be used
 *
 *Return: the index position at which a char in str1 exists in str2
 */
int _strcspn(char *str1, char *str2)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int len = 0;

		while (str1[len] != '\0')
		{
			if (_strchr(str2, str1[len]) != NULL)
			{
				break;
			}
			len++;
		}

		return (len);
	}
	return (0);
}

/**
 *_strchr - locates a char in a string
 *@s: string to be searched
 *@c: char to be checked
 *
 *Return: returns a mpointer to the first occurence of c in s
 */
char *_strchr(char *s, char c)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;

		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}
		if (s[i] == c)
		{
			return (s + i);
		}
		else
		{
			return (NULL);
		}
	}
	return (NULL);
}
