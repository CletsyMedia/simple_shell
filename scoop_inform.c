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

