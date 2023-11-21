#include "simple_shell.h"

/**
 * parse_command - Determines the type of the command.
 *
 * @cmd: The command to be parsed.
 *
 * Return: Constant representing the type of the command.
 *
 * Description:
 * - EXT_CMD (1) represents commands like /bin/ls.
 * - INT_CMD (2) represents commands like exit, env.
 * - PTH_CMD (3) represents commands found in the PATH like ls.
 * - INVD_CMD (-1) represents invalid commands.
 */

int parse_command(char *cmd)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		int i = 0;
		char *internal_command[] = {"env", "exit", NULL};
		char *path = NULL;

		/* Check if the command is an external command*/
		for (i = 0; cmd[i] != '\0'; i++)
		{
			if (cmd[i] == '/')
				return (EXT_CMD);
		}

		/* Check if the command is an internal command */
		for (i = 0; internal_command[i] != NULL; i++)
		{
			if (_str_comp(cmd, internal_command[i]) == 0)
				return (INT_CMD);
		}

		/* Check if the command is found in the PATH*/
		path = chk_path(cmd);
		if (path != NULL)
		{
			free(path);
			return (PTH_CMD);
		}

		return (INVD_CMD); /* Invalid command*/
	}
	return (0);
}

/**
 * execute_command - executes a command based on it's type
 * @cmd_tkn: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @cmd_type: type of the command
 *
 * Return: void
 */
void execute_command(char **cmd_tkn, int cmd_type)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		void (*func)(char **cmd);
		/* Execute external or path-based command*/
		if (cmd_type == EXT_CMD || cmd_type == PTH_CMD)
		{
			char *cmd_path = NULL;

			cmd_path = (cmd_type == EXT_CMD) ? cmd_tkn[0] : chk_path(cmd_tkn[0]);
			if (execve(cmd_path, cmd_tkn, NULL) == -1)
			{
				perror(_getenv("PWD"));
				exit(2);
			}
		}
		else if (cmd_type == INT_CMD)
		{
			func = get_cmd_function(cmd_tkn[0]);
			func(cmd_tkn);
		}
		else if (cmd_type == INVD_CMD)
		{
			shell_printer(program_name, STDERR_FILENO);
			shell_printer(": 1: ", STDERR_FILENO);
			shell_printer(cmd_tkn[0], STDERR_FILENO);
			shell_printer(": not found\n", STDERR_FILENO);
			status = 127;
		}
	}
}
