#include "shellux.h"


/**
 * _setenviro - Initializes a new environment variable or modifies an existing
 * one.
 * @informat: Pointer to the inform_t struct containing command information.
 * @var: The string representing the environment variable property.
 * @value: The string representing the environment variable value.
 *
 * This function either initializes a new environment variable with the
 * specified property and value or modifies an existing environment variable.
 * It updates the environment_changed flag to indicate that the environment has
 * been modified.
 *
 * Return: Always 0.
 */
int _setenviro(inform_t *informat, char *var, char *value)
{
	char *buffs = NULL; /* Initialize a buffer to hold the variable and value. */
	listed_t *node;	/* Create a pointer to traverse the linked list. */
	char *p;	/* Create a pointer for searching within strings. */
	/* Check if either 'var' or 'value' is NULL, and return 0 on failure. */
	/* Check if either 'var' or 'value' is NULL, and return on failure. */
	if (!var || !value)
	return (0);
	/* Allocate memory for 'buffs' to store the variable and value. */
	buffs = malloc(_strn_length(var) + _strn_length(value) + 2);
	if (!buffs)
	return (1);
	/* Copy 'var' into 'buffs'. */
	_strn_copy(buffs, var);
	/* Concatenate '=' to 'buffs'. */
	_strn_concat(buffs, "=");
	/* Concatenate 'value' to 'buffs'. */
	_strn_concat(buffs, value);
	/* Traverse the linked list 'informat->env'. */
	for (node = informat->env; node; node = node->next)
	{/* Search for 'var' within the current node's string. */
	p = triggers(node->str, var);
	/* If 'var' is found and followed by '=', update the value. */
	if (p && *p == '=')
	{/* Free the old string and replace it with 'buffs'. */
	free(node->str);
	node->str = buffs;
	/* Set a flag to indicate that the environment was changed. */
	informat->env_changed = 1;
	/* Free 'buffs' as it's no longer needed. */
	free(buffs);
	return (0);/* Return success. */
	}
	}
	/* If 'var' was not found in the linked list, add a new node at the end. */
	addNode_end(&(informat->env), buffs, 0);
	/* Set a flag to indicate that the environment was changed. */
	informat->env_changed = 1;
	/* Free 'buffs' as it's no longer needed. */
	free(buffs);
	return (0);/* Return success. */
}




/**
 * _getenviro - Retrieves and returns a copy of the environment variables.
 * @informat: Pointer to the inform_t struct containing command information.
 *
 * This function fetches a copy of the environment variables from the inform_t
 * structure. If changes were made to the environment or if the copy hasn't
 * been retrieved yet, it updates the stored copy using the listTostrns
 * function.
 *
 * Return: A char pointer to the string array containing environment variables.
 */
char **_getenviro(inform_t *informat)
{

	if (!informat->environ || informat->env_changed)
	{
	/*Convert the 'env' linked list to an array of strings ('environ')*/
	informat->environ = listTostrns(informat->env);

	/* This reset the env_change flag*/
	informat->env_changed = 0;

	}
	/*Return the 'environ' array.*/
	return (informat->environ);
}

/**
 * _unsetenviro - Removes an environment variable from the list.
 * @informat: Pointer to the inform_t struct containing command information.
 * @var: The string representing the environment variable to remove.
 *
 * This function iterates through the list of environment variables stored in
 * the inform_t structure and removes the environment variable indicated by
 * the var parameter. The environment_changed flag is updated to reflect the
 * change.
 *
 * Return: 1 if the environment variable was successfully removed, 0 otherwise.
 */
