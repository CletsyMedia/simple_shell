#include "shellux.h"

/**
 * triggers - Checks if a substring starts within a larger string.
 * @haystack: The larger string to search in.
 * @pin: The substring to find.
 *
 *	This function searches for the substring specified by @pin within the
 * larger string @haystack. It compares characters of @haystack and @pin
 * char by char until the end of @pin is reached or a mismatch is found.
 * If a mismatch is found, return NULL, indicating that the substring
 * @pin was not found within @haystack.
 * If the entire @pin is found in @haystack,
 * it returns the address of the next character after the found substring
 * in @haystack.
 * If the entire @pin is empty (i.e., a null terminator), the function
 * immediately returns the address of the first character of @haystack.
 *
 * Return: The address of the next character after
 * the found substring in `haystack`,
 * or NULL if the substring is not found.
 */
char *triggers(const char *haystack, const char *pin)
{
	/* Iterate through each character of the substring */
	for (; *pin; pin++, haystack++)
	{
		/* Compare characters of `pin` and `haystack` */
		if (*pin != *haystack)
			return (NULL);
	}

	/* Return pointer to the location of `haystack` where the substring starts */
	return ((char *)haystack);
}

/**
 * _strn_concat - This function concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * This function appends the char from the source buffer (@src) to the end
 * of the destination buffer (@dest), ensuring null termination at the end.
 * Return: A pointer to the destination buffer after concatenation.
 */
char *_strn_concat(char *dest, char *src)
{
	char *ret = dest;

	/* Move to the end of the destination string */
	for (; *dest; dest++)
		;

	/* Copy the content of the source string to the destination */
	for (; *src; src++)
		*dest++ = *src;

	/* Null-terminate the concatenated string */
	*dest = *src;

	return (ret);
}

/**
 * _strn_length - Calculates the length of a given string.
 * @s: A pointer to the input string whose length needs to be calculated.
 * Return: The length of the string as an integer.
 *
 * Authors: Cletus Samuel and Amanda Obi
 */
int _strn_length(char *s)
{
	int a = 0;
	/* Handle the case of a null pointer */
	if (!s)

	return (0);

	while (*s++)
	
	a++; /* increment the length counter */

	return (a);/* Return the calculated length */
}

/**
 * _strn_compare - Compares two strings alphabetically.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 * Return: An integer indicating the comparison result:
 *	- Negative if str1 < str2 alphabetically.
 *	- Positive if str1 > str2 alphabetically.
 *	- Zero if str1 = str2 alphabetically.
 */
int _strn_compare(char *str1, char *str2)
{
	/* Iterate through each character of both strings */
	for (; *str1 && *str2; str1++, str2++)
	{
		/* Compare characters of `str1` and `str2` */
		if (*str1 != *str2)
			/* Return the difference of ASCII values */
			return (*str1 - *str2);
	}

	/* One or both strings have reached the null terminator */
	if (*str1 == *str2)
		/* Both strings are equal */
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);/* Compare based on ASCII values */
}


