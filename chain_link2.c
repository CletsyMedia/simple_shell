#include "shellux.h"



/**
 * node_triggers - Returns a node whose string starts with the given prefix
 * and has the specified next character.
 * @node: Pointer to the list head.
 * @prefix: String to match as a prefix.
 * @c: The next character after the prefix to match.
 *
 * Return: Pointer to the matching node or NULL if no match is found.
 */
listed_t *node_triggers(listed_t *node, char *prefix, char c)
{
	char *p = NULL;

	for (; node; node = node->next)
	{
	/* Check if the node's string starts with the given prefix */
	p = triggers(node->str, prefix);
	/* If p is not NULL and the next char matches or no char is specified */
	if (p && ((c == -1) || (*p == c)))
	return (node); /* Return the matching node */
	}

	return (NULL); /* No match found, return NULL */
}

