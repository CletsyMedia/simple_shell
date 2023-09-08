#include "shellux.h"

/**
 * _putchar - Write a character to the standard output.
 * @ch: The character to be written.
 *
 * This function writes a single character to the standard output.
 * If the internal buffer is full or if a special flush character
 * is encountered, the content of the buffer is flushed to the output.
 *
 * Return: On success, 1. On error, -1 is returned, and errno is set
 *	appropriately.
 */
int _putchar(char ch)
{
	static char buffs[WRITE_BUFFER_SIZE];
	static int a;

	if (ch == BUFFER_FLUSH || a >= WRITE_BUFFER_SIZE)
	{
	write(1, buffs, a);
	a = 0;
	}

	if (ch != BUFFER_FLUSH)
	buffs[a++] = ch;

	return (1);
}

/**
 * _puts - Print a string to the standard output.
 * @str: The input string to be printed.
 *
 * This function takes an input string and prints its contents
 * to the standard output, character by character, until a null
 * terminator is encountered.
 */
void _puts(char *str)
{
	int a = 0;

	if (!str)
		return;

	for (; str[a] != '\0'; a++)
	{
		_putchar(str[a]);
	}
}


/**
 * _strn_copy - Copies a string from source to destination.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * This function copies the string pointed to by `src` (including the
 * null-terminator) to the buffer pointed to by `dest`. It returns `dest`.
 * If `src` and `dest` are the same, or if `src` is NULL, the function returns
 * `dest`.
 *
 * Return: A pointer to the destination buffer.
 * Authors: Cletus Samuel and Amanda Obi
 */
char *_strn_copy(char *dest, char *src)
{
	int a = 0;

	/* If src and dest are the same or src is NULL, return dest */
  if (dest == src || src == 0)
		return (dest);

	/* Loop through source and copy characters to destination */
  for (; src[a]; a++)
		dest[a] = src[a];
  
}