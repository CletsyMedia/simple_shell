#include "shellux.h"


/**
 * _shhstry - Displays the command history with line numbers.
 * @informat: Pointer to the inform_t struct containing command information.
 *
 * This function prints the list of executed commands in the history,
 * each preceded by its line number. It uses the provided inform_t
 * structure to access the history list.
 *
 *	Return: Always 0
 */
int _shhstry(inform_t *informat)
{
	/* Print the shell command history using prnt_list() */
	prnt_list(informat->history);

	return (0);
}


/**
 * unset_alias - Removes an alias from the alias list.
 * @informat: Pointer to the inform_t struct containing command information.
 * @str: The string alias to be removed.
 *
 * This function searches for the provided alias string in the alias linked
 * list stored in the 'informat' structure. If found, it removes the
 * corresponding node from the list. The modified alias list is then stored
 * back in the 'informat' structure.
 *
 * Return: 0 on success (alias removed successfully),
 *	- 1 on error (alias not found or encountered an issue).
 */
int unset_alias(inform_t *informat, char *str)
{
	char *p;
	int rem;
	char c;

	p = strn_char(str, '=');/* Find the position of '=' in 'str'. */
	if (!p)
	/* If '=' is not found, return failure. */
	return (1);
	/* Store the character at the position of '='. */
	c = *p;
	/* Null-terminate 'str' at the position of '=' to get the variable name. */
	*p = 0;

	/* Remove the alias entry with the var name and store the result in 'ret'. */
	rem = del_node_idx(&(informat->alias), get_node_idx(informat->alias,
	node_triggers(informat->alias, str, -1)));
	/* Restore the original character at the position of '=' in 'str'. */
	*p = c;
	/* Return the result of the alias removal(0 for success, 1 for failure). */
	return (rem);
}


/**
 * set_alias - Sets an alias to a given string.
 * @informat: Pointer to the inform_t struct containing command information.
 * @str: The string alias to be set.
 *
 * This function handles the setting of aliases in the alias linked list stored
 * in the 'informat' structure. It first searches for the provided alias string
 * in the alias list and removes any existing alias with the same name.
 * Then, it adds a new node containing the alias to the end of the alias list.
 *
 * Return:
 *	- 0 on success (alias set successfully).
 *	- 1 on error (issue encountered while setting the alias).
 */
int set_alias(inform_t *informat, char *str)
{
	char *p;
	/* Locate '=' character in the input string */
	p = strn_char(str, '=');
	if (!p)

	return (1);/* Return failure if '=' character is not found */

	if (!*++p)
	/* Unset alias if no value is provided */
	return (unset_alias(informat, str));

	unset_alias(informat, str);/* Unset any existing alias with the same name */
	/* Set the alias using addNode_end() */
	return (addNode_end(&(informat->alias), str, 0) == NULL);
}


/**
 * print_alias - Prints an alias string.
 * @node: Pointer to the alias node containing the alias string.
 *
 * This function is responsible for printing an alias stored in an alias node.
 * It extracts the alias name and its corresponding value from the node and
 * prints them in a formatted way. The alias name is enclosed in single quotes,
 * followed by the alias value.
 *
 * Return:
 *	- 0 on success (alias printed successfully).
 *	- 1 on error (no alias node provided).
 */
int print_alias(listed_t *node)
{
	/* Pointers for '=' character and alias string */
	char *p = NULL;
	char *a = NULL;

	if (node)
	{
	/* Locate '=' character in the alias */
	p = strn_char(node->str, '=');
	for (a = node->str; a <= p; a++)
	/* Print alias name characters */
	_putchar(*a);
	/* Print opening single quote */
	_putchar('\'');
	/* Print alias value after '=' character */
	_puts(p + 1);
	/* Print closing single quote and newline */
	_puts("'\n");
	/* Return success */
	return (0);
	}
	return (1);/* Return failure if node is NULL */

}

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


