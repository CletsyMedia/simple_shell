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
char *strn_concat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	 /* Find the end of the destination string */
	for (a = 0; dest[a] != '\0'; a++)
		;

	/* Copy up to n characters from src to dest */
	for (b = 0; src[b] != '\0' && b < n; b++)
	{
		/* Copy a character from src to dest */
		dest[a] = src[b];
		 /* Increment the destination index */
		a++;
	}
	/* Ensure that dest is null-terminated if fewer than n chars are copied */

	if (b < n)
		dest[a] = '\0';

	return (s);
}

/**
 * strn_copy - Copies a string up to a specified length.
 * @dest: The destination string to copy to.
 * @src: The source string to copy from.
 * @n: The maximum number of characters to copy.
 *
 * This function copies up to 'n' characters from the source string 'src'
 * to the destination string 'dest'. If the source string is shorter than 'n'
 * characters, the remaining characters in 'dest' are set to null bytes ('\0').
 * The function returns the pointer to the modified destination string.
 *
 * Return: Pointer to the modified destination string 'dest'.
 */
char *strn_copy(char *dest, char *src, int n)
{
	char *s = dest;
	int a = 0;
	int b;

	/* Iterate through src until null terminator or n-1 characters are copied */

	for (; src[a] != '\0' && a < n - 1; a++)
	{
	/* Copy characters from src to dest */
		dest[a] = src[a];
	}
	/* Check if less than n characters were copied */
	if (a < n)
	{
		 /* Copy the value of a into b */
		b = a;
		/* Pad dest with null terminators until n characters are reached */

		for (; b < n; b++)
		{
			dest[b] = '\0';
		}
	}
	return (s); /* Return a pointer to the start of the destination buffer */
}


