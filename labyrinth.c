#include "shellux.h"

/**
 * fork_exec_comnd - This function forks the execution line to run command
 * forks a child process to execute a command using execve.
 * @informat: A pointer to `inform_t` struct that stores all information.
 *
 * Return: Void(empty)
 */
void fork_exec_comnd(inform_t *informat)
{
	pid_t child_pid;

	child_pid = fork();

	switch (child_pid)
	{
		case -1:
			perror("Error:");
			return;
		case 0:
			if (execve(informat->path, informat->argv, _getenviro(informat)) == -1)
			{
				_free_inform(informat, 1);
				switch (errno)
				{
					case EACCES:
						exit(126);
					default:
						exit(1);
				}
			}
			break;
		default:
			wait(&(informat->status));
			if (WIFEXITED(informat->status))
			{
				informat->status = WEXITSTATUS(informat->status);
				switch (informat->status)
				{
					case 126:
						_prnterr(informat, "Unauthorized: Access denied\n");
						break;
					default:
						break;
				}
			}
			break;
	}
}


/**
 * _exec_hsh - Our custom shellux loop for simple_shell
 * This function implements a loop for the shell.
 * It handles input processing, command execution, and error handling.
 * The function takes an `inform_t` struct
 * and an argument vector as parameters.
 * @informat: A pointer to `inform_t` struct that stores all information.
 * @av: The arguement vector for the function
 * Return: 0 on success, and 1 with an error code on failure.
 *
 * Authors: Cletus Samuel and Amanda Obi
 */
int _exec_hsh(inform_t *informat, char **av)
{
	int builtin_cmd = 0;
	ssize_t a = 0;

	for (; a != -1 && builtin_cmd != -2; _clr_inform(informat))
	{
	if (active(informat))
	_puts("$ ");
	_errputchar(BUFFER_FLUSH);
	a = get_the_input(informat);
	if (a != -1)
	{
	_get_inform(informat, av);
	builtin_cmd = _search_builtins(informat);
	switch (builtin_cmd)
	{
	case -1:
	locate_comnd(informat);
	break;
	default:
	break;
	}
	}
	else if (active(informat))
	_putchar('\n');
	_free_inform(informat, 0);
	}
	wrt_hstry(informat);
	_free_inform(informat, 1);
	switch (builtin_cmd)
	{case -2:
	if (informat->err_num == -1)
	exit(informat->status);
	exit(informat->err_num);
	break;
	default:
	if (!active(informat) && informat->status)
	exit(informat->status);
	break;
	}
	return (builtin_cmd);
}

/**
 * locate_comnd - This function finds the builtin command in PATH
 * searches for a built-in command in the PATH environment variable.
 * @informat: A pointer to `inform_t` struct that stores all information.
 *
 * Return: Void(empty)
 */
void locate_comnd(inform_t *informat)
{
	int a = 0;
	int b = 0;
	char *path = NULL;

	informat->path = informat->argv[0];
	if (informat->linecount_flag == 1)
	{
		informat->line_count++;
		informat->linecount_flag = 0;
	}
	while (informat->arg[a])
	{
	switch (!isDelimiter(informat->arg[a], " \t\n"))
	{case 0:
		break;
		default:
		b++;
		break;
	}
		a++;
	}
	if (!b)
		return;
	path = _search_path(informat, get_enviro(informat, "PATH="),
		informat->argv[0]);
	switch (path != NULL)
	{case 1:
	informat->path = path;
	fork_exec_comnd(informat);
	break;
	default:
	if ((active(informat) || get_enviro(informat, "PATH=")
	|| informat->argv[0][0] == '/') && _this_comnd(informat, informat->argv[0]))
	fork_exec_comnd(informat);
	else if (*(informat->arg) != '\n')
	{informat->status = 127;
	_prnterr(informat, "command not found\n");
	}
	break;
	}
}





/**
 * _search_builtins - This func finds the reserved commands,
 * searches for reserved commands within the given shell environment
 * @informat: A pointer to `inform_t` struct that stores all information.
 *
 * Return: 0 if customCmd is handled successfully,
 * 1 if customCmd is found but not successful,
 * -2 if customCmd exit()
 * -1 if customCmd is not found in the console.
 */

int _search_builtins(inform_t *informat)
{
	int a;
	int builtin_cmd2;

	/* Array of command names and their corresponding functions */
	comndinfo_table comnd_builttable[] = {
	{"setenv", _shsetenviro},
	{"exit", _shexit},
	{"alias", _shaliases},
	{"history", _shhstry},
	{"env", _shenviro},
	{"unsetenv", _shunsetenviro},
	{"cd", _shcdr},
	{"help", _shhelp},
	{NULL, NULL} /* Terminating entry for the array */
	};

	builtin_cmd2 = -1;
	a = 0; /* Initialize loop control variable */

	while (comnd_builttable[a].type != NULL)
	{
	/* Check if the input command matches a built-in command */
	if (_strn_compare(informat->argv[0], comnd_builttable[a].type) == 0)
	{
	informat->line_count++;
	builtin_cmd2 = comnd_builttable[a].func(informat);
	break;
	}
	/* Increment loop control variable to check the next entry */
	a++;
	}

	return (builtin_cmd2);
}

