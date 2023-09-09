#include "shellux.h"


/**
 * strntok - Splits a given input string into separate words
 * using specified delimiters.
 * @str: The input string to be split.
 * @d: The delimiters used to separate words.
 * This function takes an input string and a delimiter string and splits the
 * input string into separate words using the specified delimiters.
 * It returns a dynamically allocated array of strings, where each element in
 * the array represents a word. If no words are found or if memory allocation
 * fails, it returns NULL.
 *
 * Return: A pointer to an array of strings containing separated words,
 * or NULL on failure.
 */
char **strntok(char *str, char *d)
{
	char **s;
	int a, b, c, e, num_to_words = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!isDelimiter(str[a], d) && (isDelimiter(str[a + 1], d) || !str[a + 1]))
			num_to_words++;

	if (num_to_words == 0)
		return (NULL);
	s = malloc((1 + num_to_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < num_to_words; b++)
	{
		while (isDelimiter(str[a], d))
			a++;
		c = 0;
		while (!isDelimiter(str[a + c], d) && str[a + c])
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (e = 0; e < c; e++)
			s[b][e] = str[a++];
		s[b][e] = 0;
	}
	s[b] = NULL;
	return (s);
}

