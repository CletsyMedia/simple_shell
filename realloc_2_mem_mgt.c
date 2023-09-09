#include "shellux.h"


/**
 * free_mem - This frees a string of strings
 * @pp: This is the string of strings
 * The free_mem function deallocates memory for a string array, including
 * its individual strings and the array itself. It takes a char ** pointer as
 * input, iterates through the strings, and releases memory to prevent leaks.
 */
void free_mem(char **pp)
{
	char **a = pp; /* Create a copy of the original pointer */

	if (!pp) /* If `pp` is NULL, nothing to free */
		return;
	/* Loop until a pointer in the array is NULL (end of array) */
	for (; *pp; pp++)
	{
		free(*pp); /* Free the memory pointed to by the current pointer */
	}

	free(a); /* Free the memory of the array itself */
}

/**
 * reallocate_mem - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_mem: byte size of previous block
 * @new_mem: byte size of new block
 *
 * This function reallocates a block of memory pointed to by @ptr.
 * If @ptr is NULL, it behaves like malloc and allocates a new block of
 * size @new. If @new is 0, it deallocates the memory block pointed to by @ptr
 * and returns NULL. If the new size is the same as the old size, the function
 * returns the original @ptr without changes. Otherwise, the function allocates
 * a new block of size @new, copies the contents from the old block to the new
 * block, and frees the old block.
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure.
 */