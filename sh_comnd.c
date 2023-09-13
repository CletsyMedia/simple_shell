#include "shellux.h"

/**
 * _shhelp - Displays help information for the shell
 * @informat: Pointer to the inform_t struct containing command information
 *
 * Return:	Always returns 0 to indicate successful execution.
 */
int _shhelp(inform_t *informat)
{
	char **arg_arr;

	arg_arr = informat->argv;
	/* A message indicating that help functionality is not yet implemented */
	_puts("The 'help' command is functional, but has not been implemented.\n");
	if (0)
		_puts(*arg_arr);
	return (0);
}


/**
 * _shcdr - Change the current directory of the shell process.
 * @informat: Pointer to the inform_t struct with command information.
 *
 * This function handles changing the working directory of the shell process.
 * It interprets different command arguments to navigate the directory
 * structure. It supports changing to the home directory, switching to the
 * previous directory ("-"), and providing a specific directory path. The
 * function also updates relevant environment variables to reflect the changes
 * in the current and previous directories.
 *
 * Return: Always returns 0 to indicate success.
 */
int _shcdr(inform_t *informat)
{
	char buffs[1024];
	char *dir;
	char *s;
	int chngdir_ret;
	/* Get the current working directory. */
	s = getcwd(buffs, sizeof(buffs));
	if (!s)
		_puts("To be implemented:>>Handle 'getcwd' failure message<<\n");
	if (!informat->argv[1])/* Check if no directory argument is provided. */
	{dir = get_enviro(informat, "HOME=");/* The home directory from env vars.*/
		if (!dir)
			chngdir_ret = chdir((dir = get_enviro(informat, "PWD=")) ? dir : "/");
		else
			chngdir_ret = chdir(dir);/* Change to the home directory. */
	}
	else if (_strn_compare(informat->argv[1], "-") == 0)/*Find the argument "-"*/
	{
		if (!get_enviro(informat, "OLDPWD="))/* Check if "OLDPWD" is not set. */
		{_puts(s);/* Print the current working directory. */
			_putchar('\n');
			return (1);/* Return with success. */
		}
		_putchar('\n');/* Print the "OLDPWD" environment variable. */
		_puts(get_enviro(informat,	"OLDPWD=")), _putchar('\n');
		/* Change to "OLDPWD" or root if not set. */
		chngdir_ret = chdir((dir = get_enviro(informat, "OLDPWD")) ? dir : "/");
	}
	else/* Change to the specified directory argument. */
		chngdir_ret = chdir(informat->argv[1]);
	if (chngdir_ret == -1)/* Check if 'chdir' returned an error. */
	{/* Print an error message. */
		_prnterr(informat, "Error: Could not change to directory");
		_errputs(informat->argv[1]), _errputchar('\n');/*Print the dir*/
	}
	else
	{/* Set "OLDPWD" to the previous current directory. */
		_setenviro(informat, "OLDPWD", get_enviro(informat, "PWD="));
		_setenviro(informat, "PWD", getcwd(buffs, 1024));/* Set the new "PWD"*/
	}
	return (0);
}


/**
 * _shexit - Exits the shell with a given exit status.
	* @informat: Pointer to the inform_t struct containing command information
 *
 * This function is responsible for exiting the shell with a specific exit
 * status. If a numeric argument is provided after the "exit" command, it's
 * used as the exit status. If no argument is given, the exit status is set
 * to -1. In case of an invalid numeric argument, the function sets the status
 * to 2 and displays an error message. The function returns the exit status
 * code.
 *
 * Return: The exit status code: -2 if no argument provided, 1 if invalid
 * numeric argument, or -1 if no exit argument and -1 if error in converting
 * numeric argument.
 */
int _shexit(inform_t *informat)
{
	int exit_status;

	/* Check if an exit status is provided. */
	if (informat->argv[1])
	{
	/* Convert exit status to an integer. */
	exit_status = err_atoi(informat->argv[1]);

	if (exit_status == -1)
	{
	/* Set status to indicate an error. */
	informat->status = 2;
	/* Print an error message. */
	_prnterr(informat, "Invalid	number: ");
	/* Print the invalid number. */
	_errputs(informat->argv[1]);
	/* Print a newline character. */
	_errputchar('\n');
	/* Return failure. */
	return (1);
	}
	/* Store the exit status. */
	informat->err_num = err_atoi(informat->argv[1]);

	return (-2);/* Return success. */
	}
	/* No exit status provided, set error number to -1. */
	informat->err_num = -1;

	return (-2);
}

