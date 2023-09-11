#include "shellux.h"

/**
 * del_node_idx - Deletes a node at a specified index in a linked list
 * @head: Pointer to the pointer of the head node of the linked list
 * @idx: The index of the node to be deleted (0-based)
 *
 * Return: 1 if the node was successfully deleted, 0 otherwise
 */
int del_node_idx(listed_t **head, unsigned int idx)
{
	unsigned int a = 0;	/* Counter for the current index */
	listed_t *prevNode = NULL;	/* Pointer to the previous node */
	listed_t *node = NULL;	/* Pointer to the current node */

	/* Check if the head pointer or the list is NULL */
	if (!head || !*head)
	return (0);

	switch (idx)
	{
	case 0:
	/* Special case for deleting the head node */
	node = *head;
	*head = (*head)->next;
	free(node->str);
	free(node);
	return (1);
	default:
	/* Regular case for deleting a node at a specific index */
	node = *head;
	for (a = 0; node; a++)
	{
	if (a == idx)
	{
	prevNode->next = node->next;
	free(node->str);
	free(node);
	return (1);
	}
	prevNode = node;
	node = node->next;
	}
	return (0);
	}
}



/**
 * _free_list - Frees a linked list and its strings
 * @head_ptr: A pointer to a pointer to the head of the list
 *
 * This function frees all nodes of a linked list and their associated strings.
 * It also sets the head pointer to NULL to indicate an empty list.
 */