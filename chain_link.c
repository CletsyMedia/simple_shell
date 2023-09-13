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
listed_t *addNode(listed_t **head, const char *str, int number)
{
	listed_t *new_list;

	/* Check if the head pointer is NULL */
	if (!head)
	return (NULL);

	/* Allocate memory for the new node */
	new_list = malloc(sizeof(listed_t));
	if (!new_list)
	return (NULL);

	/* Initialize the new node */
	memory_set((void *)new_list, 0, sizeof(listed_t));

	/* Assign the node index */
	new_list->number = number;

	/* Duplicate the string if provided */
	if (str)
	{
	new_list->str = strn_duplicate(str);
	if (!new_list->str)
	{
	/* Free allocated memory if string duplication fails */
	free(new_list);
	return (NULL);
	}
	}

	/* Update the next pointer to the current head */
	new_list->next = *head;

	/* Update the head pointer to point to the new node */
	*head = new_list;

	/* Return the address of the newly added node */
	return (new_list);
}


/**
 * addNode_end - Adds a node to the end of the list.
 * @head: Address of pointer to the head node.
 * @str: String field of the new node.
 * @number: Node index used by history.
 * Return: Address of the new node if successful, NULL on failure.
 */
listed_t *addNode_end(listed_t **head, const char *str, int number)
{
	listed_t *node;
	listed_t *newNode;

	if (!head)
		return (NULL);
	/* Store the current head node */
	node = *head;
	/* Allocate memory for the new node */
	newNode = malloc(sizeof(listed_t));
	if (!newNode)
		return (NULL);
	/* Initialize the new node's memory to zero */
	memory_set((void *)newNode, 0, sizeof(listed_t));
	/* Set the node index used by history */
	newNode->number = number;
	/* Check if str is provided */
	if (str)
	{/* Duplicate the input string for the new node */
		newNode->str = strn_duplicate(str);
		if (!newNode->str)
		{
			free(newNode);
			return (NULL);
		}
	}
	/* If there's an existing list */
	if (node)
	{
		while (node->next)/* Traverse to the end of the list */
			node = node->next;
		/* Attach the new node to the end of the list */
		node->next = newNode;
	}
	else
	{
		/* If the list is empty, set the new node as the head */
		*head = newNode;
	}
	/* Return the address of the new node */
	return (newNode);
}


/**
 * prntList_strn - Prints only the `str` element of a `listed_t` linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t prntList_strn(const listed_t *h)
{
	size_t a = 0;

	/* Iterate through the linked list */
	for (; h; h = h->next)
	{
		/* Print the `str` element or "(nil)" if NULL */
		_puts(h->str ? h->str : "(nil)");

		_puts("\n");
		a++; /* Increment the counter */
	}
	return (a);
}

