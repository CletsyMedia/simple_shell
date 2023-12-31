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
void *reallocate_mem(void *ptr, unsigned int old_mem, unsigned int new_mem)
{
	/* Declare a new pointer to the memory */
	char *p;

	switch (1)
	{
	case 0:
	/* Allocate new memory if old pointer is NULL */
	return (malloc(new_mem));

	case 1:
	if (new_mem == 0)
	{
	/* Free old memory if new size is 0 */
	free(ptr);
	return (NULL);
	}
	else if (new_mem == old_mem)
	{
	/* Return old pointer if sizes match */
	return (ptr);
	}
	else
	{
	/* Allocate new memory block */
	p = malloc(new_mem);
	if (!p)
	{
	return (NULL);
	}
	old_mem = old_mem < new_mem ? old_mem : new_mem;
	for (; old_mem > 0; old_mem--)
	{
	p[old_mem - 1] = ((char *)ptr)[old_mem - 1];
	}
	/* Free old memory and return new pointer */
	free(ptr);
	return (p);
	}
	}
}




/**
 * memory_set - Fills a block of memory with a specified value.
 * @s: A pointer to the memory area to be filled.
 * @b: The byte value to be set in the memory.
 * @n: The number of bytes to be filled.
 *
 * This function fills the first @n bytes of the memory area pointed to by @s
 * with the byte value @b.
 *
 * Return: A pointer to the memory area @s.
 */
char *memory_set(char *s, char b, unsigned int n)
{
	unsigned int a = 0;

	/* Loop through each byte of memory */
	while (a < n)
	{
		/* Set the byte at address `s + a` to the value of `b` */
		s[a] = b;
		/* Move to the next byte */
		a++;
	}
	/* Return the pointer to the starting memory address `s` */
	return (s);
}

/**
 * buffs_free - Safely frees a pointer and sets the address to NULL
 * @ptr: Address of the pointer to be freed
 *
 * This function safely frees memory by checking if the input pointer is not
 * NULL. If both the input pointer and the memory it points to are valid
 * (not NULL), the memory is deallocated using the `free()` function,
 * and the input pointer is set to NULL to prevent any further accidental
 * access to the freed memory. The function returns 1 upon successful memory
 * deallocation and pointer reset, or 0 if no action was taken due to an
 * invalid pointer or NULL memory.
 *
 * Return: 1 if memory was successfully freed and pointer reset, otherwise 0.
 */

int buffs_free(void **ptr)
{
	/* Check if ptr and *ptr are not NULL */
	if (ptr && *ptr)
	{
		/* Free the buffer and set the pointer to NULL */
		free(*ptr);

		*ptr = NULL;

		return (1); /* Return success */
	}
	return (0); /* Return failure */
}



