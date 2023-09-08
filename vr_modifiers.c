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
