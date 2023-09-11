#include "shellux.h"



/**
 * sign_handlers - Handles the Ctrl-C signal
 * @sign_num: The signal number (unused)
 *
 * This function is called when the Ctrl-C signal (SIGINT) is triggered.
 * It prints a newline character and the shell prompt to create a new line.
 * This behavior effectively blocks the default behavior of terminating the
 * program when Ctrl-C is pressed. The `__attribute__((unused))` attribute is
 * used to indicate that the parameter sign_num is not used in the function.
 *
 * Return: void
 */
void sign_handlers(__attribute__((unused)) int sign_num)
{
	/* Print a newline character */
	_puts("\n");
	/* Print a prompt */
	_puts("$ ");
	/* Flush the buffer */
	_putchar(BUFFER_FLUSH);
}
