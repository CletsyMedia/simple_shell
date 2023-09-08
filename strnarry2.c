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
