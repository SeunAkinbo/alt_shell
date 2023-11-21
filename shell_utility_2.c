#include "simple_shell.h"

/**
 * chk_path - Checks if a command is found in the PATH.
 * @cmd: The command to be searched for.
 *
 * Return: Pointer to the path of a command if found, or NULL if not found.
 *
 * Description:
 * Takes a command and checks if it can be found in the PATH env variable.
 * It searches through the directories listed in the PATH and returns
 * the full path to the command if found, or NULL if the command is not
 * found in any of the directories.
 */

char *chk_path(char *cmd)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		char **path_array = NULL;
		char *temp = NULL, *temp2 = NULL, *path_copy = NULL;
		char *path = _getenv("PATH");
		int i = 0, num_directories = 0;

		if (path == NULL || _stringlen(path) == 0)
			return (NULL);

		/* Allocate memory for path_copy*/
		path_copy = malloc(sizeof(*path_copy) * (_stringlen(path) + 1));
		_strcopy(path, path_copy);
		/* Tokenize path into directories*/
		path_array = str_tokenizer(path_copy, ":");
		/* Count the number of directories */
		for (num_directories = 0; path_array[num_directories] != NULL; )
			num_directories++;
		/* Iterate through directories to find the command*/
		for (i = 0; i < num_directories; i++)
		{
			temp2 = _str_concat(path_array[i], "/");
			temp = _str_concat(temp2, cmd);
			/* Check if concatenated path is accessible*/
			if (access(temp, F_OK) == 0)
			{
				free(temp2);
				free(path_array);
				free(path_copy);
				return (temp);
			}
			free(temp);
			free(temp2);
		}
		/* Clean up and return NULL if not found*/
		free(path_copy);
		free(path_array);
		return (NULL);
	}
	return (NULL);
}

/**
 * get_cmd_function - Retrieves a function based on a command and a mapping.
 * @cmd: The string to check against the mapping.
 *
 * Return: Pointer to the proper function, or NULL on fail.
 *
 * Description:
 * This function takes a command (cmd) and searches for it in
 * a mapping that associates commands with functions. If the command is found,
 * the corresponding function pointer is returned.
 * If the command is not found, NULL is returned to indicate failure.
 */
void (*get_cmd_function(char *cmd))(char **)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		size_t i = 0;

		mapping_to_function mapping[] = {
			{"env", current_env}, {"exit", exiting_program}
		};

		/*Iterate through the mapping and using a while loop*/
		while (i < sizeof(mapping) / sizeof(mapping[0]))
		{
			if (_str_comp(cmd, mapping[i].cmd_name) == 0)
				return (mapping[i].func);

			i++;
		}

		return (NULL);
	}

	return (NULL);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: The value of the variable as a string, or NULL if var is not found.
 *
 * Description:
 * Takes the name of an env variable (name) & retrieves its value from the env.
 * It iterates through env variables until it finds a match for a given name.
 * If a match is found, it returns a pointer to the value of the variable;
 * otherwise, it returns NULL.
 */
char *_getenv(char *name)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		char **my_environ = NULL;
		char *pair_ptr = NULL;
		char *name_cpy = NULL;
		int i = 0;

		/* Iterate through environment variables using a while loop*/
		while ((my_environ = &environ[i]) != NULL && *my_environ != NULL)
		{
			/*Iterate through characters of variable name using a do-while*/
			pair_ptr = *my_environ;
			name_cpy = name;
			do {
				if (*pair_ptr == '=')
					break;
				pair_ptr++;
				name_cpy++;
			} while (*pair_ptr == *name_cpy);

			/*Return value if variable name matches*/
			if ((*pair_ptr == '=') && (*name_cpy == '\0'))
				return (pair_ptr + 1);

			i++; /*Move to the next environment variable*/
		}
		return (NULL); /*Variable not found*/
	}
	return (NULL);
}
