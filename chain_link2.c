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


/**
 * get_node_idx - Gets the index of a node within a linked list.
 * @head: Pointer to the list head.
 * @node: Pointer to the target node.
 *
 * Return: Index of the node or -1 if not found.
 */
ssize_t get_node_idx(listed_t *head, listed_t *node)
{
	size_t a = 0; /* Initialize a counter to keep track of the index */

	for (; head; head = head->next, a++)
	{
	/* Compare the current node's address with the target node's address */
	if (head == node)
	{
	return (a); /* Return the index if a match is found */
	}
	}
	return (-1); /* Return -1 if the target node is not found in the list */
}

/**
 * list_len - Determines the length of a linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t list_len(const listed_t *h)
{
	size_t a = 0; /* Initialize the counter to zero */

	for (; h; h = h->next)
	{
	/* Iterate through the linked list using a for loop */
	a++; /* Increment the counter for each node */
	}

	return (a); /* Return the total count of nodes */
}

/**
 * listTostrns - Returns an array of strings from the list->str field.
 * @head: Pointer to the first node.
 * The function aims to transform the str field of each node in a
 * linked list into an array of strings.
 * It's important to manage memory carefully to avoid memory leaks or
 * unexpected behavior due to improper memory management.
 * Return: Array of strings.
 */
