#include "shellux.h"

/**
 * _shaliases - Copies the alias that is in the builtin (man alias).
 * @informat: Pointer to the inform_t struct containing command information.
 *
 * Description:
 * This function simulates the behavior of the 'alias' built-in command in a
 * shell. When invoked without arguments, it prints the list of aliases
 * previously set, where each alias is displayed as 'alias_name'='alias_value'.
 * When provided with arguments, it either sets or prints aliases based on the
 * provided arguments. If the argument contains an equal sign ('='), it's
 * considered an alias to be set. If not, the argument is assumed to be an
 * alias name and its corresponding value is printed.
 *
 * Return:
 *	- Always 0, indicating successful execution of the function.
 */
int _shaliases(inform_t *informat)
{
	char *p = NULL; /* Pointer to '=' character in an argument */
	listed_t *node = NULL; /* Pointer to alias linked list */
	int a = 0; /* Counter for arguments */

	if (informat->argc == 1)
	{
		/* If no arguments, display existing aliases */
		node = informat->alias;
		while (node)
		{
			 /* Display the alias */
			print_alias(node);
			 /* Move to the next alias in the list */
			node = node->next;
		}
		return (0); /* Return success */
	}

	for (a = 1; informat->argv[a]; a++)
	{
		 /* Check if argument contains '=' */
		p = strn_char(informat->argv[a], '=');
		if (p)/* Set new alias */
			set_alias(informat, informat->argv[a]);
		else /* Display existing alias */
			print_alias(node_triggers(informat->alias, informat->argv[a], '='));
	}

	return (0); /* Return success */
}
