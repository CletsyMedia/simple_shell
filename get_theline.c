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


/**
 * input_buf - Read input from the user and store it in a buffer.
 * @informat: Pointer to an inform_t struct.
 * @buffs: Pointer to a pointer to the input buffer.
 * @len: Pointer to the length of the input buffer.
 *
 * This function reads input from the user using the `getline` or
 * `get_the_line` function based on the `USE_GETLINE` macro. It dynamically
 * allocates memory for the input buffer, updates the length, and processes
 * the input.
 *
 * Return: The number of characters read or -1 on failure.
 */
ssize_t input_buf(inform_t *informat, char **buffs, size_t *len)
{
	size_t len_buffs = 0;
	ssize_t i = 0;

	/* Fill the buffer if nothing is left */
	if (!*len)
	{
	free(*buffs);
	*buffs = NULL;
	signal(SIGINT, sign_handlers);

	/* Read input using either getline or get_the_line */
	#if USE_GETLINE
	i = getline(buffs, &len_buffs, stdin);
	#else
	i = get_the_line(informat, buffs, &len_buffs);
	#endif

	if (i > 0)
	{
	/* Remove newline character if present */
	if ((*buffs)[i - 1] == '\n')
	{
	(*buffs)[i - 1] = '\0';
	i--;
	}

	informat->linecount_flag = 1;
	slice_comnts(*buffs);

	/* Build history and update length */
	build_hstry(informat, *buffs, informat->historycount++);
	*len = i;
	informat->cmd_buffs = buffs;
	}
	}

	return (i);
}

