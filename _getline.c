#include "simple_shell.h"

#define MAX_LINE_LENGTH 1024

/**
 * _getline - Read from file stream & store in dynamically allocated buffer.
 * @line: A pointer to a pointer that will store the read line.
 * @len: A pointer to the size of the allocated buffer, updated as needed.
 * @stream: A pointer to the file stream to read from.
 *
 * Reads characters from the specified file stream (@stream) and stores
 * them in the buffer pointed to by @line.
 * The buffer is dynamically allocated or resized as needed to accommodate
 * the input line. The size of the buffer is tracked by
 * @len, which is updated accordingly.
 *
 * Return:
 *   - On success, returns the number of chars read, excl the null terminator.
 *   - If an error occurs or the end of the file is reached, it returns -1.
 *   - If @line or @len is NULL or if memory allocation fails, it returns -1.
 *
 * Note: The caller is responsible for freeing the memory allocated for
 * the line when it's no longer needed.
 */
ssize_t _getline(char **line, size_t *len, FILE *stream)
{
	char *getline;
	ssize_t read;

	if (*line == NULL || *len == 0)
	{
		*len = 1024;
		*line = malloc(*len);
		if (*line == NULL)
		{
			return (-1);
		}
	}

	getline = _fgets(*line, *len, stream);
	if (getline != NULL)
	{
		read = _strlen(*line);

		if (read > 0 && (*line)[read - 1] == '\n')
		{
			(*line)[read - 1] = '\0';
			read--;
		}
		return (read);
	}
	else
	{
		return (-1);
	}
}

/**
 * _fgets - Read a line of text from a file stream into a fixed-size buffer.
 * @buffer: A pointer to the character array where the line will be stored.
 * @max_length: The maximum number of characters to read, including the null
 * terminator.
 * @stream: A pointer to the file stream to read from.
 *
 * This function reads characters from the specified file stream (@stream)
 * and stores them in the buffer (@buffer) up to a maximum * length of
 * (@max_length) characters, including the null terminator. It is designed
 * to read lines of text from a file.
 *
 * Return:
 *   - On success, it returns a pointer to the input buffer.
 *   - If an error occurs or the end of the file is reached, it returns NULL.
 *   - If @buffer is NULL, @max_length is non-positive, or @stream is NULL,
 * it returns NULL.
 */
char *_fgets(char *buffer, int max_length, FILE *stream)
{
	int i;
	int c;

	if (buffer == NULL || max_length <= 0 || stream == NULL)
	{
		return (NULL);  /* Invalid arguments */
	}

	i = 0;

	while (i < max_length - 1)
	{
		c = fgetc(stream);

		if (c == EOF)
		{
			if (i == 0)
			{
				/* No characters read, and we've reached the end of the file */
				return (NULL);
			}
			break;  /* End of line reached */
		}

		buffer[i++] = (char)c;

		if (c == '\n')
		{
			break;  /* End of line reached */
		}
	}

	buffer[i] = '\0';  /* Null-terminate the string */

	return (buffer);
}

/**
 * _strlen - Calculate the length of a null-terminated string.
 * @str: A pointer to the input string.
 *
 * Calculates & returns length of the null-terminated str pointed to by @str.
 *
 * Return:
 *   - The length of an input string (num of chars) excldg the null terminator.
 */
size_t _strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
