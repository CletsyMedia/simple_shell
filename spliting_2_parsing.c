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

/**
 * _duplicate_chars - Duplicates characters from a string within a range.
 * @pathstr: The input string.
 * @begin: The beginning index of the range.
 * @end: The ending index of the range (exclusive).
 * Return: A pointer to a new buffer containing the duplicated characters.
 */
char *_duplicate_chars(char *pathstr, int begin, int end)
{
	/* Initialize index variables for input string and buffer */
	int a = begin;
	int b = 0;
	/* Declare a static buffer to store the duplicated characters */
	static char buffs[1024];

	/* Loop through the characters in the specified range [begin, end) */
	while (a < end)
	{
	/* Copy characters that are not ':' to the buffer */
	if (pathstr[a] != ':')
	{
	buffs[b++] = pathstr[a];
	}
	a++;
	}
	buffs[b] = 0;	/* Null-terminate the buffer to create a valid C string */
	/* Return a pointer to the new buffer containing duplicated characters */
	return (buffs);
}

/**
 * _search_path - Finds the given command in the PATH string.
 * @informat: Pointer to the `inform_t` struct.
 * @pathstr: The PATH string.
 * @comnd: The command to find.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *_search_path(inform_t *informat, char *pathstr, char *comnd)
{
	char *path;
	int current_pos = 0;
	int a;

	if (!pathstr)
	return (NULL);

	if ((_strn_length(comnd) > 2) && triggers(comnd, "./"))
	{
	if (_this_comnd(informat, comnd))
	return (comnd);
	}

	for (a = 0; ; a++)
	{
	switch (pathstr[a])
	{
	case '\0':
	case ':':
	path = _duplicate_chars(pathstr, current_pos, a);
	if (!*path)
	_strn_concat(path, comnd);
	else
	{
	_strn_concat(path, "/");
	_strn_concat(path, comnd);
	}
	if (_this_comnd(informat, path))
	return (path);
	if (!pathstr[a])
	return (NULL);
	current_pos = a;
	break;
	}
	}
}


/**
 * strntok1 - Splits an input string into words using a specified delimiter.
 * @str: The input string to be split.
 * @d: The delimiter used to separate words.
 *
 * This function takes an input string and a delimiter and splits the input
 * string into separate words based on the specified delimiter. It returns
 * a dynamically allocated array of strings, each element representing a word.
 * If no words are found or if memory allocation fails, it returns NULL.
 *
 * Return: A pointer to an array of strings containing separated words,
 * or NULL on failure.
 */
char **strntok1(char *str, char d)
{
	char **s;
	int a, b, c, e, num_to_words = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
			(str[a] != d && !str[a + 1]) || str[a + 1] == d)
			num_to_words++;
	if (num_to_words == 0)
		return (NULL);
	s = malloc((1 + num_to_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < num_to_words; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		c = 0;
		while (str[a + c] != d && str[a + c] && str[a + c] != d)
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


/**
 * _this_comnd - Determines if a file is an executable command.
 * @informat: A pointer to `inform_t` struct that stores all information.
 * @path: Path to the file.
 *
 * This function checks whether the file at the given path is
 * an executable command.
 * It uses the `stat` function to gather information about the file's type.
 * If the file is a regular file, the function
 * considers it an executable command.
 *
 * Return: 1 if the file is an executable command, 0 otherwise.
 * Authors: Cletus Samuel and Amanda Obi
 */

int _this_comnd(inform_t *informat, char *path)
{
	/* Declare a structure to store file information. */
	struct stat store;
	/* Suppress unused parameter warning */
	(void)informat;
	/* Check if the path is NULL or if calling `stat` fails */
	if (!path || stat(path, &store))
		return (0);
	/* Check if the file is a regular file */
	if (S_ISREG(store.st_mode))
	{
		/* File is considered an executable command */
		return (1);
	}
	/* File is not an executable command */
	return (0);
}


