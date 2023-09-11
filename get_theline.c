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

/**
 * get_the_input - Reads a line of input, processes command chaining, and
 * returns the length.
 * @informat: Pointer to the inform_t struct containing command information
 *
 * This function retrieves a line of input from the user, manages command
 * chaining, and updates the inform_t struct accordingly. It utilizes the
 * input_buf() function to obtain the input line and maintains buffer pointers
 * for tracking. The function also handles command chaining by iterating
 * through the input buffer and invoking _chain() to identify command chain
 * characters. After processing, it updates the buffer pointers and resets them
 * if the end of the buffer is reached. The final length of the command is
 * calculated and returned. If EOF is encountered, -1 is returned.
 *
 * Return: The length of the command line or -1 in case of EOF
 */
ssize_t get_the_input(inform_t *informat)
{
	ssize_t i = 0;
	static size_t a, b, len;
	char **buf_p = &(informat->arg), *p;
	static char *buffs;

	_putchar(BUFFER_FLUSH);
	i = input_buf(informat, &buffs, &len);

	if (i == -1) /* EOF */
	return (-1);

	if (len)
	{
	/* initializing a new iterator to the current buffer position */
	b = a;
	p = buffs + a;
	_checkChain(informat, buffs, &b, a, len);

	for (; b < len; b++)
	{
	if (_chain(informat, buffs, &b))
	break;
	}

	/* Increment the past null */
	a = b + 1;

	if (a >= len)
	{
	/* Reset its position */
	a = len = 0;
	informat->cmd_buffs_type = NORM_COMND;
	}

	*buf_p = p;
	/* Return length of the current command */
	return (_strn_length(p));
	}
	*buf_p = buffs;
	return (i);
}


/**
 * read_buf - Reads data into a buffer from a file descriptor
 * @informat: Pointer to inform_t struct with command information
 * @buffs: Buffer to store the read data
 * @a: Pointer to size indicator
 *
 * This function reads data from the file descriptor in 'informat' into the
 * provided 'buffer'. The size of data read is determined by the value pointed
 * to by 'a'. If data has already been read into the buffer, the function
 * returns 0. Otherwise, it reads up to 'READ_BUFFER_SIZE' bytes from the file
 * descriptor, updates the 'a' value, and returns the number of bytes read.
 *
 * Return: Number of bytes read (positive), 0 if buffer already contains data,
 *	or -1 on error (and sets 'errno').
 */
ssize_t read_buf(inform_t *informat, char *buffs, size_t *a)
{
	ssize_t i = 0;

	if (*a)
	{
		return (0); /* Buffer already contains data */
	}

	i = read(informat->readfd, buffs, READ_BUFFER_SIZE); /* Read data */

	if (i >= 0)
	{
		*a = i; /* Update size indicator */
	}

	return (i); /* Return bytes read or error code */
}

/**
 * get_the_line - Retrieves the next line of input from STDIN
 * @informat: Pointer to the parameter struct containing shell information
 * @ptr: Address of a pointer to buffer, which can be preallocated or NULL
 * @length: Size of the preallocated buffer pointed by ptr, if not NULL
 *
 * This function reads the next line of input from the standard input (STDIN)
 * and processes it. It maintains a static buffer to read data from, and it
 * searches for a newline character in the buffer to identify the end of the
 * line. The function reallocates memory as needed to store the line. If ptr
 * and length are provided, the function uses the provided buffer and size for
 * reallocation. If successful, it returns the length of the read line. If
 * there is an error or if the end of the input is reached, it returns -1.
 *
 * Return: Length of the read line if successful, -1 on error or end of input.
 */
