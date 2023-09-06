#include "shellux.h"

/**
 * _errputchar - Writes a character to the standard error stream.
 * @c: The character to be written.
 *
 * This function writes the input character 'c' to the standard error
 * stream (file descriptor 2). It uses a static buffer for efficient
 * writing and flushes the buffer when it's full or when 'BUFFER_FLUSH'
 * (a special flag) is encountered.
 * Return: 1 on success.
 */
int _errputchar(char c)
{
	 /* Static buffer to store characters */
	 static char buffs[WRITE_BUFFER_SIZE];
	 /* Static variable to keep track of buffer position */
	static int a;

	if (c == BUFFER_FLUSH || a >= WRITE_BUFFER_SIZE)
	{
	/* Write the buffered characters to stderr */
	write(2, buffs, a);
	a = 0; /* Reset buffer position */
	}
	else
	{
	buffs[a++] = c;/* Append the character to the buffer */
	}

	return (1);/* Return 1 to indicate success */
}


/**
 * _putfnd - Write a character to the given file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * This function writes the character 'c' to the specified file descriptor 'fd'
 * If the char is equal to 'BUFFER_FLUSH' or the buffer is full, it flushes
 * the buffer by writing its contents to 'fd'.
 * Return: 1 on successful write, or -1 on error (sets errno).
 */

int _putfnd(char c, int fd)
{
	/* Static buffer to store characters */
	static char buffs[WRITE_BUFFER_SIZE];
	/* Static variable to keep track of buffer position */
	static int a;

	if (c == BUFFER_FLUSH || a >= WRITE_BUFFER_SIZE)
	{
	/* Write the buffered characters to the specified file descriptor */
	write(fd, buffs, a);
	a = 0; /* Reset buffer position */
	}
	else
	{
	buffs[a++] = c; /* Append the character to the buffer */
	}

	return (1); /* Return 1 to indicate success */
}

/**
 * _errputs - Prints a null-terminated string to the standard error stream.
 * @str: The string to be printed.
 *
 * This function prints the characters of the input string 'str' to the
 * standard error stream. If the input string is NULL, no action is taken.
 *
 * Return: Nothing.
 */
void _errputs(char *str)
{
	int a = 0;

	if (!str)
		return;

	for (; str[a] != '\0'; a++)
	{
		_errputchar(str[a]);
	}
}


/**
 * _putsfnd - Write a string to the given file descriptor.
 * @str: The string to print.
 * @fd: The file descriptor to write to.
 *
 * This function writes the string 'str' to the specified file descriptor 'fd'.
 * It iterates through each character of the string using a 'for' loop and
 * accumulates the number of characters written. Returns the total number of
 * characters written to 'fd'. If 'str' is NULL, returns 0.
 * Return: The number of chars put
 */
int _putsfnd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	/* Loop through each character of the string */
	for (; *str; str++)
	{
		 /* Write the character to the file descriptor using _putfnd() */
		a += _putfnd(*str, fd);
	}
	return (a); /* Return the total number of characters written */
}










