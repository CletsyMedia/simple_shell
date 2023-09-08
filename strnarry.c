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

