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

