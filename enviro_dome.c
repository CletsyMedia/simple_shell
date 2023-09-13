#include "shellux.h"


/**
 * _shunsetenviro - Removes an environment variable.
 * @informat: Pointer to an `inform_t` structure containing potential arg.
 *	Used to maintain a constant function prototype.
 *
 * This function removes one or more environment variables.
 * It takes in the variable names as arguments and removes them from the
 * environment, effectively unsetting them.
 *
 * Return: Always 0
 */
int _shunsetenviro(inform_t *informat)
{
	int a = 1;

	if (informat->argc <= 1)
	{
		/* Print error message */
		_errputs("Argument count is less than required.\n");
		/* Return failure if arguments are insufficient */
		return (1);
	}

	/* Unset each specified variable. */
	while (a < informat->argc)
	{
		_unsetenviro(informat, informat->argv[a]);
		a++;
	}

	/* Return success after unsetting variables */
	return (0);
}


/**
 * _pop_enviro_list - Populates the environment linked list.
 * @informat: Pointer to an `inform_t` structure containing potential arg.
 *	Used to maintain a constant function prototype.
 *
 * This function populates the environment linked list using the existing
 * 'environ' array. It iterates through the 'environ' array and adds each
 * environment variable to the linked list.
 *
 * Return: Always 0
 */
