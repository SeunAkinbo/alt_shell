#include "simple_shell.h"

/**
 *current_env - prints the current_environement
 *@cmd_tkn: command entered
 *
 *Return: void
 */
void current_env(char **cmd_tkn __attribute__((unused)))
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;

		/* Loop through environment variables and print them */
		for (i = 0; environ[i] != NULL; i++)
		{
			shell_printer(environ[i], STDOUT_FILENO);
			shell_printer("\n", STDOUT_FILENO);
		}
	}
}

/**
 * exiting_program - exits the shell
 * @cmd_tkn: command entered
 *
 * Return: void
 */
void exiting_program(char **cmd_tkn)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int num_token = 0;
		int arg = 0;

		for (; cmd_tkn[num_token] != NULL; num_token++)
			;
		if (num_token == 1)
		{
			free(cmd_tkn);
			free(user_input);
			free(my_cmds);
			exit(status);
		}
		else if (num_token == 2)
		{
			arg = __atoi(cmd_tkn[1]);

			if (arg == -1)
			{
				shell_printer(program_name, STDERR_FILENO);
				shell_printer(": 1: exit: bad number: ", STDERR_FILENO);
				shell_printer(cmd_tkn[1], STDERR_FILENO);
				shell_printer("\n", STDERR_FILENO);
				status = 2;
			}
			else
			{
				free(user_input);
				free(cmd_tkn);
				free(my_cmds);
				exit(arg);
			}
		}
		else
		{
		shell_printer("$: exit takes only 1 argument\n", STDERR_FILENO);
		}
	}
}
