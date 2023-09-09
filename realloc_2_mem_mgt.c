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
