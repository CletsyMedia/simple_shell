#include "shellux.h"

/**
 * _checkChain - Determines whether to continue chaining based on last status.
 * @informat: Pointer to the `inform_t` structure.
 * @buffs: Character buffer to be checked.
 * @p: Address of the current position in the buffer.
 * @a: Starting position in the buffer.
 * @len: Length of the buffer.
 *
 * This function examines the last status of the executed command and the
 * 'cmd_buffs_type' field in the 'inform_t' structure to determine whether
 * the chaining logic should continue. If the 'cmd_buffs_type' is AND_COMND and
 * the last command's status is non-zero, it truncates the buffer and stops.
 * If the 'cmd_buffs_type' is OR_COMND and the last command's status is zero,
 * it truncates the buffer and stops.
 *
 * Return: Void.
 */
void _checkChain(inform_t *informat, char *buffs, size_t *p,
size_t a, size_t len)
{
	size_t b = *p;

	switch (informat->cmd_buffs_type)
	{
	case AND_COMND:
	if (informat->status)
	{
	buffs[a] = 0;
	b = len;
	}
	break;

	case OR_COMND:
	if (!informat->status)
	{
	buffs[a] = 0;
	b = len;
	}
	break;

	default:
	/* Handle any underlying cases if needed */
	break;
	}

	*p = b;
}


/**
 * _chain - Tests if the current character in the buffer is a chain delimiter.
 * @informat: Pointer to the `inform_t` structure.
 * @buffs: Character buffer to be checked.
 * @p: Address of the current position in the buffer.
 *
 * This function examines the current character in the buffer to determine if
 * it is a chain delimiter ('||', '&&', or ';'). Depending on the delimiter
 * found, it updates the 'cmd_buffs_type' field in the 'inform_t' structure.
 *
 * Return: 1 if a chain delimiter is found, 0 otherwise.
 */
int _chain(inform_t *informat, char *buffs, size_t *p)
{
	size_t b = *p;

	switch (buffs[b])
	{
	case '|':
	if (buffs[b + 1] == '|')
	{
	buffs[b] = 0;
	b++;
	informat->cmd_buffs_type = OR_COMND;
	}
	else
	{
	return (0);
	}
	break;

	case '&':
	if (buffs[b + 1] == '&')
	{
	buffs[b] = 0;
	b++;
	informat->cmd_buffs_type = AND_COMND;
	}
	else
	{
	return (0);
	}
	break;

	case ';':
	buffs[b] = (0);
	informat->cmd_buffs_type = CHAIN_COMND;
	break;

	default:
	return (0);
	}
	*p = b;
	return (1);
}


/**
 * change_strn - Replaces an old string with a new string.
 * @older: Address of a pointer to the old string.
 * @newer: Pointer to the new string.
 *
 * This function replaces an existing strn, pointed to by the `older` pointer,
 * with a new string provided by the `newer` pointer. It first deallocates the
 * memory used by the old string using `free`, and then assigns the `newer`
 * string to the `older` pointer, effectively replacing the old string with the
 * new string.
 *
 * Return: 1 indicating successful replacement, 0 otherwise.
 */
int change_strn(char **older, char *newer)
{
	/* Free the memory occupied by the older string */
	free(*older);
	/* Update 'older' to point to the new string */
	*older = newer;
	/* Return 1 to indicate success */
	return (1);
}




/**
 * change_aliases - Replaces a cmd with its corresponding alias if available.
 * @informat: Pointer to the `inform_t` struct.
 *
 * This function searches for an alias that matches the current command in the
 * alias list stored in the `inform_t` structure. If an alias is found, the
 * cmd is replaced with the corresponding alias value in the tokenized string.
 *
 * Return: 1 if an alias is replaced, 0 if no alias found.
 */
int change_aliases(inform_t *informat)
{
	listed_t *node;/* Pointer to a listed_t structure */
	char *p;/* Pointer to a character */
	int a = 0;/* Counter initialized to 0 */

	while (a < 10)/* Loop up to 10 times */
	{
	/* Find any alias stored */
	node = node_triggers(informat->alias, informat->argv[0], '=');
	if (node == NULL)/* If no alias is found */
	/* Return 0 to indicate failure */
	return (0);
	else
	{
	free(informat->argv[0]); /* Free the memory of the old alias */
	/* Find the character '=' in the alias */
	p = strn_char(node->str, '=');
	if (!p)/* If '=' is not found */
	return (0);
	p = strn_duplicate(p + 1);/* Duplicate the content after '=' */
	if (!p)/* If duplication fails */
	return (0);
	/* Update argv[0] with the new alias content */
	informat->argv[0] = p;
	a++;/* Increment the counter */
	}
	}

	return (1);
}

/**
 * change_vars - Replaces variables in the tokenized string with their values.
 * @informat: Pointer to the `inform_t` struct.
 *
 * This function iterates through the tokenized command arguments in the
 * `informat` structure and identifies variables starting with '$'. It then
 * replaces the variables with their corresponding values. Special vars like
 * "$?" (exit status), "$$" (process ID), and environment variables are handled
 * appropriately.
 *
 * Return: 1 if variables are replaced, 0 otherwise.
 */
int change_vars(inform_t *informat)
{
	int a = 0;
	listed_t *node;

	for (a = 0; informat->argv[a]; a++)
	{
		if (informat->argv[a][0] != '$' || !informat->argv[a][1])
			continue;

		if (!_strn_compare(informat->argv[a], "$?"))
		{
			change_strn(&(informat->argv[a]),
				strn_duplicate(change_num(informat->status, 10, 0)));
			continue;
		}
		if (!_strn_compare(informat->argv[a], "$$"))
		{
			change_strn(&(informat->argv[a]),
				strn_duplicate(change_num(getpid(), 10, 0)));
			continue;
		}
		node = node_triggers(informat->env, &informat->argv[a][1], '=');
		if (node)
		{
			change_strn(&(informat->argv[a]),
				strn_duplicate(strn_char(node->str, '=') + 1));
			continue;
		}
		change_strn(&informat->argv[a], strn_duplicate(""));

	}
	return (0);
}


