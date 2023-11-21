#include "simple_shell.h"

/**
 * setup_init - starts executing everything
 * @current_cmd: try to check current token
 * @cmd_type: parse token
 *
 * Return: void function
 */

void setup_init(char **current_cmd, int cmd_type)
{
	if ((shell_isatty(STDIN_FILENO)) == 1)
	{
		pid_t _PID_;

		if (cmd_type == EXT_CMD || cmd_type == PTH_CMD)
		{
			_PID_ = fork();
			if (_PID_ == 0)
				execute_command(current_cmd, cmd_type);
			else
			{
				waitpid(_PID_, &status, 0);
				status >>= 8;
			}
		}
		else
		{
			execute_command(current_cmd, cmd_type);
		}
	}
}
