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
void _free_list(listed_t **head_ptr)
{
	listed_t *node;	/* Pointer to the current node */
	listed_t *nextNode;	/* Pointer to the next node */
	listed_t *head;	/* Copy of the head pointer */

	/* Check if the head pointer is NULL or points to an empty list */
	if (!head_ptr || !*head_ptr)
	return;

	/* Store a copy of the head pointer */
	head = *head_ptr;

	/* Traverse the list and free each node and its associated string */
	for (node = head; node;)
	{
	/* Store a reference to the next node */
	nextNode = node->next;

	/* Free the string inside the current node */
	free(node->str);

	/* Free the current node itself */
	free(node);

	/* Move to the next node */
	node = nextNode;
	}

	/* Set the head pointer to NULL to indicate an empty list */
	*head_ptr = NULL;
}


/**
 * addNode - Adds a node to the start of the list.
 * @head: Address of pointer to head node.
 * @str: String field of the node.
 * @number: Node index used by history.
 *
 * Return: Address of the new node if successful, NULL on failure.
 */