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


/**
 * strn_concat - Concatenates two strings up to a specified length.
 * @dest: The first string to which the second string will be appended.
 * @src: The second string to be appended.
 * @n: The maximum number of bytes to be used from the second string.
 *
 * This function appends up to 'n' bytes from the source string 'src' to the
 * end of the destination string 'dest'. It ensures that the destination
 * string remains null-terminated. The function returns the pointer to the
 * modified destination string.
 *
 * Return: Pointer to the modified destination string 'dest'.
 */
