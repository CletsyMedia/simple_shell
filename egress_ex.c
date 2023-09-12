#include "shellux.h"


/**
 * strn_char - Locates a character in a string up to a maximum length.
 * @s: The string to be parsed.
 * @c: The character to look for.
 * Return: A pointer to the first occurrence of 'c' in 's', or NULL.
 */

char *strn_char(char *s, char c)
{
	while (*s != '\0')
	{
	if (*s == c)
	/* Return a pointer to the first occurrence of 'c' in 's' */
	return (s);
	s++; /* Increment s after the check*/
	}
	/* Return NULL if 'c' is not found in 's' */
	return (NULL);
}

