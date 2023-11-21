#include "simple_shell.h"
/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size of ptr
 * @new_size: size of the new memory to be allocated
 *
 * Return: pointer to the address of the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int i;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block != NULL)
		{
			i = 0;
			while (i < old_size && i < new_size)
			{
				*((char *)temp_block + i) = *((char *)ptr + i);
				i++;
			}
			free(ptr);
			return (temp_block);
		}
		else
		{
			return (NULL);
		}
	}
}

/**
 * ctrl_c_handler - handles the signal raised by CTRL-C
 * @signum: signal number
 *
 * Return: void
 */

void ctrl_c_handler(int signum)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		if (signum == SIGINT)
		{
			shell_printer("\n$:) ", STDIN_FILENO);
		}
	}
}

/**
 * remove_comment - removes/ignores everything after a '#' char
 * @input: input to be used
 *
 * Return: void
 */

void remove_comment(char *input)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;

		if (input[i] == '#')
		{
			input[i] = '\0';
			return;
		}

		for (; input[i] != '\0'; i++)
		{
			if (input[i] == '#' && input[i - 1] == ' ')
			{
				break;
			}
		}

		input[i] = '\0';
	}
}
